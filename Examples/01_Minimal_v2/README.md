## Works without -gpu=managed and NVIDIA's nvc
Ingredients
* Run with McStas from the updated 'EPICURE' branch
* Use the local comps here that have fixed-length static arrays
* Build for NVIDIA gpu using e.g.
```bash
mcrun -c Minimal.instr -y --openacc --verbose --override-config=NO_managed/
```
(See file log.txt for the ouput)
* Generated c-code compiles with gcc / offloading using below cmd but does not return output yet...
```bash
gcc-13 -o ./Minimal.out ./Minimal.c -lm -fopenacc -foffload=default -foffload"=-fcf-protection=none" -fno-stack-protector -DOPENACC -foffload=-lm -DGCCOFFLOAD -lm
```