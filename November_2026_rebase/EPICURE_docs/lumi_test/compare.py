#!/usr/bin/env python3
"""Compare two McCode output dirs monitor by monitor (statistically, not bitwise).

  compare.py REF_DIR TEST_DIR       e.g. stock CPU run vs OpenMP GPU run

Per output file: z-score of the totals from '# values: I I_err N', and chi2/dof over bins
(array_1d: columns I, I_err; array_2d: the I and I_err blocks). Event lists
(array_2d without an '# Errors' block) get totals only. |z| > 3 or chi2/dof >> 1 flags.
Numpy only; same seed is NOT expected to give identical numbers (RNG use differs).
"""
import glob
import os
import sys

import numpy as np


def load(path):
    head, rows = {}, []
    blocks, cur = [], None
    for ln in open(path, errors='replace'):
        if ln.startswith('#'):
            k, _, v = ln[1:].partition(':')
            head.setdefault(k.strip(), v.strip())
            if ln.startswith(('# Data', '# Errors', '# Events')):
                cur = []
                blocks.append(cur)
        elif ln.strip():
            (cur if cur is not None else rows).append([float(x) for x in ln.split()])
    I = Ie = None
    if head.get('xvar') == 'Li' and blocks and blocks[0]:   # Monitor_nD event list: totals from p column
        p = np.array(blocks[0])[:, 0]
        return [p.sum(), np.sqrt((p**2).sum()), len(p)], None, None
    if head.get('type', '').startswith('array_1d') and rows:
        a = np.array(rows)
        I, Ie = a[:, 1], a[:, 2]
    elif len(blocks) >= 2 and 'Errors' in open(path, errors='replace').read():
        I, Ie = np.array(blocks[0]), np.array(blocks[1])
    tot = [float(x) for x in head.get('values', 'nan nan nan').split()[:3]]
    return tot, I, Ie


def chi2dof(I1, e1, I2, e2):
    v = e1**2 + e2**2
    m = v > 0
    return float(np.sum((I1[m] - I2[m])**2 / v[m]) / max(m.sum(), 1)), int(m.sum())


def compare(ref, test):
    bad = 0
    for f in sorted(glob.glob(os.path.join(ref, '*'))):
        if f.endswith(('.sim', '.log')) or os.path.isdir(f):
            continue
        g = os.path.join(test, os.path.basename(f))
        if not os.path.exists(g):
            print(f'{os.path.basename(f):40s} MISSING in {test}'); bad += 1; continue
        (a, ae, an), I1, e1 = load(f)
        (b, be, bn), I2, e2 = load(g)
        z = (a - b) / np.hypot(ae, be) if np.hypot(ae, be) > 0 else 0.0
        msg = f'{os.path.basename(f):40s} I={a:.4g}/{b:.4g}  z={z:+.2f}  N={an:.0f}/{bn:.0f}'
        flag = abs(z) > 3
        if I1 is not None and I2 is not None and I1.shape == I2.shape:
            c, n = chi2dof(I1, e1, I2, e2)
            msg += f'  chi2/dof={c:.2f} ({n} bins)'
            flag |= c > 2
            if I1.ndim == 2 and I1.shape[0] == I1.shape[1]:   # catches transposed 2D output
                ct, _ = chi2dof(I1, e1, I2.T, e2.T)
                if ct < c / 2:
                    msg += f'  TRANSPOSED? (chi2/dof vs transpose={ct:.2f})'; flag = True
        print(('!! ' if flag else '   ') + msg)
        bad += flag
    print(f'{bad} flagged')
    return bad


def selftest():
    I = np.arange(1.0, 10.0).reshape(3, 3); e = np.sqrt(I)
    assert chi2dof(I, e, I, e)[0] == 0
    assert chi2dof(I, e, I.T, e.T)[0] > 0.5


if __name__ == '__main__':
    selftest()
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    sys.exit(1 if compare(sys.argv[1], sys.argv[2]) else 0)
