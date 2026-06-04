/* Automatically generated file. Do not edit. 
 * Format:     ANSI C source code
 * Creator:    McStas <http://www.mcstas.org>
 * Instrument: templateNMX.instr (templateNMX)
 * Date:       Thu Jun  4 15:36:00 2026
 * File:       templateNMX.c
 * CFLAGS=
 */

#ifndef WIN32
#  ifndef OPENACC
#    define _GNU_SOURCE
#  endif
#  define _POSIX_C_SOURCE 200809L
#endif
/* In case of cl.exe on Windows, supppress warnings about #pragma acc */
#ifdef _MSC_EXTENSIONS
#pragma warning(disable: 4068)
#endif

#define MCCODE_STRING " 3.99.99, git"
#define FLAVOR        "mcstas"
#define FLAVOR_UPPER  "MCSTAS"

#define MC_USE_DEFAULT_MAIN
#define MC_TRACE_ENABLED

#include <string.h>
#include <inttypes.h>

typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#define MCCODE_BASE_TYPES

/* available random number generators */
#define _RNG_ALG_MT         1
#define _RNG_ALG_KISS       2
/* selection of random number generator */
#ifndef RNG_ALG
#  define RNG_ALG  _RNG_ALG_KISS
#endif
#if RNG_ALG == _RNG_ALG_MT // MT 
#define randstate_t uint32_t
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#define randstate_t uint64_t
#endif

#ifndef MC_NUSERVAR
#define MC_NUSERVAR 10
#endif

/* Particle JUMP control logic */
struct particle_logic_struct {
int dummy;
};

struct _struct_particle {
  double x,y,z; /* position [m] */
  double vx,vy,vz; /* velocity [m/s] */
  double sx,sy,sz; /* spin [0-1] */
  int mcgravitation; /* gravity-state */
  void *mcMagnet;    /* precession-state */
  int allow_backprop; /* allow backprop */
  /* Generic Temporaries: */
  /* May be used internally by components e.g. for special */
  /* return-values from functions used in trace, thusreturned via */
  /* particle struct. (Example: Wolter Conics from McStas, silicon slabs.) */
  double _mctmp_a; /* temp a */
  double _mctmp_b; /* temp b */
  double _mctmp_c; /* temp c */
  randstate_t randstate[7];
  double t, p;     /* time, event weight */
  long long _uid;  /* Unique event ID */
  long _index;     /* component index where to send this event */
  long _absorbed;  /* flag set to TRUE when this event is to be removed/ignored */
  long _scattered; /* flag set to TRUE when this event has interacted with the last component instance */
  long _restore;   /* set to true if neutron event must be restored */
  long flag_nocoordschange;   /* set to true if particle is jumping */
  struct particle_logic_struct _logic;
};
typedef struct _struct_particle _class_particle;

_class_particle _particle_global_randnbuse_var;
_class_particle* _particle = &_particle_global_randnbuse_var;

_class_particle mcgenstate(void);
_class_particle mcsetstate(double x, double y, double z, double vx, double vy, double vz,
			   double t, double sx, double sy, double sz, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop);
_class_particle mcgetstate(_class_particle mcneutron, double *x, double *y, double *z,
                           double *vx, double *vy, double *vz, double *t,
                           double *sx, double *sy, double *sz, double *p);

#pragma omp declare target
extern int mcgravitation;      /* flag to enable gravitation */
#pragma omp end declare target

_class_particle mcgenstate(void) {
  _class_particle particle = mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, mcgravitation, NULL, 0);
  return(particle);
}
/*Generated user variable handlers:*/

double particle_getvar(_class_particle *p, char *name, int *suc);

#if defined(OPENACC) || defined(_OPENMP)
int str_comp(char *str1, char *str2);
#endif

double particle_getvar(_class_particle *p, char *name, int *suc){
#if !defined(OPENACC) && !defined(_OPENMP)
#define str_comp strcmp
#endif
  int s=1;
  double rval=0;
  if(!str_comp("x",name)){rval=p->x;s=0;}
  if(!str_comp("y",name)){rval=p->y;s=0;}
  if(!str_comp("z",name)){rval=p->z;s=0;}
  if(!str_comp("vx",name)){rval=p->vx;s=0;}
  if(!str_comp("vy",name)){rval=p->vy;s=0;}
  if(!str_comp("vz",name)){rval=p->vz;s=0;}
  if(!str_comp("sx",name)){rval=p->sx;s=0;}
  if(!str_comp("sy",name)){rval=p->sy;s=0;}
  if(!str_comp("sz",name)){rval=p->sz;s=0;}
  if(!str_comp("t",name)){rval=p->t;s=0;}
  if(!str_comp("p",name)){rval=p->p;s=0;}
  if(!str_comp("_mctmp_a",name)){rval=p->_mctmp_a;s=0;}
  if(!str_comp("_mctmp_b",name)){rval=p->_mctmp_b;s=0;}
  if(!str_comp("_mctmp_c",name)){rval=p->_mctmp_c;s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

void* particle_getvar_void(_class_particle *p, char *name, int *suc);

#if defined(OPENACC) || defined(_OPENMP)
int str_comp(char *str1, char *str2);
#endif

void* particle_getvar_void(_class_particle *p, char *name, int *suc){
#if !defined(OPENACC) && !defined(_OPENMP)
#define str_comp strcmp
#endif
  int s=1;
  void* rval=0;
  if(!str_comp("x",name)) {rval=(void*)&(p->x); s=0;}
  if(!str_comp("y",name)) {rval=(void*)&(p->y); s=0;}
  if(!str_comp("z",name)) {rval=(void*)&(p->z); s=0;}
  if(!str_comp("vx",name)){rval=(void*)&(p->vx);s=0;}
  if(!str_comp("vy",name)){rval=(void*)&(p->vy);s=0;}
  if(!str_comp("vz",name)){rval=(void*)&(p->vz);s=0;}
  if(!str_comp("sx",name)){rval=(void*)&(p->sx);s=0;}
  if(!str_comp("sy",name)){rval=(void*)&(p->sy);s=0;}
  if(!str_comp("sz",name)){rval=(void*)&(p->sz);s=0;}
  if(!str_comp("t",name)) {rval=(void*)&(p->t); s=0;}
  if(!str_comp("p",name)) {rval=(void*)&(p->p); s=0;}
  if (suc!=0x0) {*suc=s;}
  return rval;
}

int particle_setvar_void(_class_particle *, char *, void*);

int particle_setvar_void(_class_particle *p, char *name, void* value){
#if !defined(OPENACC) && !defined(_OPENMP)
#define str_comp strcmp
#endif
  int rval=1;
  if(!str_comp("x",name)) {memcpy(&(p->x),  value, sizeof(double)); rval=0;}
  if(!str_comp("y",name)) {memcpy(&(p->y),  value, sizeof(double)); rval=0;}
  if(!str_comp("z",name)) {memcpy(&(p->z),  value, sizeof(double)); rval=0;}
  if(!str_comp("vx",name)){memcpy(&(p->vx), value, sizeof(double)); rval=0;}
  if(!str_comp("vy",name)){memcpy(&(p->vy), value, sizeof(double)); rval=0;}
  if(!str_comp("vz",name)){memcpy(&(p->vz), value, sizeof(double)); rval=0;}
  if(!str_comp("sx",name)){memcpy(&(p->sx), value, sizeof(double)); rval=0;}
  if(!str_comp("sy",name)){memcpy(&(p->sy), value, sizeof(double)); rval=0;}
  if(!str_comp("sz",name)){memcpy(&(p->sz), value, sizeof(double)); rval=0;}
  if(!str_comp("p",name)) {memcpy(&(p->p),  value, sizeof(double)); rval=0;}
  if(!str_comp("t",name)) {memcpy(&(p->t),  value, sizeof(double)); rval=0;}
  return rval;
}

int particle_setvar_void_array(_class_particle *, char *, void*, int);

int particle_setvar_void_array(_class_particle *p, char *name, void* value, int elements){
#if !defined(OPENACC) && !defined(_OPENMP)
#define str_comp strcmp
#endif
  int rval=1;
  return rval;
}

void particle_restore(_class_particle *p, _class_particle *p0);

void particle_restore(_class_particle *p, _class_particle *p0) {
  p->x  = p0->x;  p->y  = p0->y;  p->z  = p0->z;
  p->vx = p0->vx; p->vy = p0->vy; p->vz = p0->vz;
  p->sx = p0->sx; p->sy = p0->sy; p->sz = p0->sz;
  p->t = p0->t;  p->p  = p0->p;
  p->_absorbed=0; p->_restore=0;
}

double particle_getuservar_byid(_class_particle *p, int id, int *suc){
  int s=1;
  double rval=0;
  switch(id){
  }
  if (suc!=0x0) {*suc=s;}
  return rval;
}

void particle_uservar_init(_class_particle *p){
}

#define MC_EMBEDDED_RUNTIME
/* embedding file "mccode-r.h" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: mcstas 3.99.99
* Version: $Revision$
*
* Runtime system header for McStas/McXtrace.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int numipar;
*   metadata_table_t metadata_table[];
*   int num_metadata;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  mcAbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas/McXtrace version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCCODE_R_H
#define MCCODE_R_H "$Revision$"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#ifndef _MSC_EXTENSIONS
#include <sys/time.h>
#endif
#include <float.h>
#include <inttypes.h>
#include <stdint.h>
#if defined(OPENACC)
#include <openacc.h>
#ifndef GCCOFFLOAD
#include <accelmath.h>
#elif defined(_OPENMP)
#include <omp.h>
#else
#include <math.h>
#endif
#pragma acc routine
int noprintf();
#pragma acc routine
size_t str_len(const char *s);
#else
#include <math.h>
#endif

/* In case of gcc / clang, ensure to use
   the built-in isnan/isinf functions */
#if defined(__GNUC__) || defined(__clang__)
#  ifdef isnan
#    undef isnan
#  endif
#  ifdef isinf
#    undef isinf
#  endif
#  define isnan(x) __builtin_isnan(x)
#  define isinf(x) __builtin_isinf(x)
#endif

#ifdef _MSC_EXTENSIONS
#ifndef _TIMES_H
#define _TIMES_H

#if defined(WIN32) || defined(_WIN32)
#include <sys/timeb.h>
#include <sys/types.h>
#include <winsock2.h>

int gettimeofday(struct timeval* t,void* timezone);

#define __need_clock_t
#include <time.h>


/* Structure describing CPU time used by a process and its children.  */
struct tms
  {
    clock_t tms_utime;          /* User CPU time.  */
    clock_t tms_stime;          /* System CPU time.  */

    clock_t tms_cutime;         /* User CPU time of dead children.  */
    clock_t tms_cstime;         /* System CPU time of dead children.  */
  };

/* Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.  */
clock_t times (struct tms *__buffer);

typedef long long suseconds_t ;



int gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
		return 0;
}

clock_t times (struct tms *__buffer) {

	__buffer->tms_utime = clock();
	__buffer->tms_stime = 0;
	__buffer->tms_cstime = 0;
	__buffer->tms_cutime = 0;
	return __buffer->tms_utime;
}


#endif
#endif
#endif

/* If the runtime is embedded in the simulation program, some definitions can
   be made static. */

#ifdef MC_EMBEDDED_RUNTIME
#  define mcstatic
#else
#  define mcstatic
#endif

#ifdef __dest_os
#  if (__dest_os == __mac_os)
#    define MAC
#  endif
#endif

#ifdef __FreeBSD__
#  define NEED_STAT_H
#endif

#if defined(__APPLE__) && defined(__GNUC__)
#  define NEED_STAT_H
#endif

#if defined(WIN32) || defined(_WIN32)
#  define NEED_STAT_H
#  define NEED_TYPES_H
#endif

#ifdef NEED_STAT_H
#  include <sys/stat.h>
#endif

#ifdef NEED_TYPES_H
#  include <sys/types.h>
#endif

#ifndef MC_PATHSEP_C
#if defined(WIN32) || defined(_WIN32)
#    define MC_PATHSEP_C '\\'
#    define MC_PATHSEP_S "\\"
#  else  /* !WIN32 */
#    define MC_PATHSEP_C '/'
#    define MC_PATHSEP_S "/"
#  endif /* !WIN32 */
#endif /* MC_PATHSEP_C */

#if defined(WIN32) || defined(_WIN32)
#if defined _MSC_VER
#include <direct.h>
#elif defined __GNUC__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#define mkdir(a,b) mkdir(a)
#define getpid() _getpid()
#endif

/* the version string is replaced when building distribution with mkdist */
#ifndef MCCODE_STRING
#  define MCCODE_STRING " 3.99.99, git"
#endif

#ifndef MCCODE_DATE
#  define MCCODE_DATE "git"
#endif

#ifndef MCCODE_VERSION
#  define MCCODE_VERSION "3.99.99"
#endif

#ifndef __MCCODE_VERSION__
#define __MCCODE_VERSION__ 399099L
#endif

#ifndef MCCODE_NAME
#  define MCCODE_NAME "mcstas"
#endif

#ifndef MCCODE_PARTICLE
#  define MCCODE_PARTICLE "neutron"
#endif

#ifndef MCCODE_PARTICLE_CODE
#  define MCCODE_PARTICLE_CODE 2112
#endif

#ifndef MCCODE_LIBENV
#  define MCCODE_LIBENV "MCSTAS"
#endif

#ifndef FLAVOR_UPPER
#  define FLAVOR_UPPER MCCODE_NAME
#endif

#ifdef MC_PORTABLE
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#ifdef MAC
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#if (USE_MPI == 0)
#  undef USE_MPI
#endif

#ifdef USE_MPI  /* default is to disable signals with MPI, as MPICH uses them to communicate */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#if defined(OPENACC) || defined(_OPENMP)  /* default is to disable signals with PGI/OpenACC */
#  ifndef NOSIGNALS
#    define NOSIGNALS 1
#  endif
#endif

#if !defined(OPENACC) && !defined(_OPENMP)
#  ifndef USE_OFF  /* default is to enable OFF when not using PGI/OpenACC */
#    define USE_OFF
#  endif
#  //ifndef CPUFUNNEL  /* allow to enable FUNNEL-mode on CPU */
#  //ifdef FUNNEL      /* by default disable FUNNEL-mode when not using PGI/OpenACC */
#  //  undef FUNNEL
#  //endif
#  //endif
#endif

#if (NOSIGNALS == 0)
#  undef NOSIGNALS
#endif

/** Header information for metadata-r.c ----------------------------------------------------------------------------- */
struct metadata_table_struct { /* stores metadata strings from components */
  char * source;  // component name which provided the metadata
  char * name;    // the name of the metadata
  char * type;    // the MIME type of the metadata (free form, valid identifier)
  char * value;   // the metadata string contents
};
typedef struct metadata_table_struct metadata_table_t;
char * metadata_table_key_component(char* key);
char * metadata_table_key_literal(char * key);
int metadata_table_defined(int, metadata_table_t *, char *);
char * metadata_table_name(int, metadata_table_t *, char *);
char * metadata_table_type(int, metadata_table_t *, char *);
char * metadata_table_literal(int, metadata_table_t *, char *);
void metadata_table_print_all_keys(int no, metadata_table_t * tab);
int metadata_table_print_all_components(int no, metadata_table_t * tab);
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key);
/* -------------------------------------------------------------------------- Header information for metadata-r.c --- */

/* Note: the enum instr_formal_types definition MUST be kept
   synchronized with the one in mccode.h and with the
   instr_formal_type_names array in cogen.c. */
enum instr_formal_types
  {
    instr_type_int,
    instr_type_string, instr_type_char,
    instr_type_vector, instr_type_double
  };
struct mcinputtable_struct { /* defines instrument parameters */
  char *name; /* name of parameter */
  void *par;  /* pointer to instrument parameter (variable) */
  enum instr_formal_types type;
  char *val;  /* default value */
  char *unit; /* expected unit for parameter; informational only */
};


#ifndef MCCODE_BASE_TYPES
typedef double MCNUM;
typedef struct {MCNUM x, y, z;} Coords;
typedef MCNUM Rotation[3][3];
#endif

/* the following variables are defined in the McStas generated C code
   but should be defined externally in case of independent library usage */
#ifndef DANSE
extern struct mcinputtable_struct mcinputtable[];         /* list of instrument parameters */
extern int    numipar;                                    /* number of instrument parameters */
extern metadata_table_t metadata_table[];                 /* list of component-defined string metadata */
extern int    num_metadata;                               /* number of component-defined string metadata */
extern char   instrument_name[], instrument_source[]; /* instrument name and filename */
extern char  *instrument_exe;                           /* executable path = argv[0] or NULL */
extern char   instrument_code[];                        /* contains the initial 'instr' file */

#ifndef MC_ANCIENT_COMPATIBILITY
extern int traceenabled, defaultmain;
#endif
#endif


/* Useful macros ============================================================ */


/* SECTION: Dynamic Arrays */
typedef int* IArray1d;
IArray1d create_iarr1d(int n);
void destroy_iarr1d(IArray1d a);

typedef int** IArray2d;
IArray2d create_iarr2d(int nx, int ny);
void destroy_iarr2d(IArray2d a);

typedef int*** IArray3d;
IArray3d create_iarr3d(int nx, int ny, int nz);
void destroy_iarr3d(IArray3d a);

typedef double* DArray1d;
DArray1d create_darr1d(int n);
void destroy_darr1d(DArray1d a);

typedef double** DArray2d;
DArray2d create_darr2d(int nx, int ny);
void destroy_darr2d(DArray2d a);

typedef double*** DArray3d;
DArray3d create_darr3d(int nx, int ny, int nz);
void destroy_darr3d(DArray3d a);


/* MPI stuff */
#ifdef USE_MPI
#include "mpi.h"

#ifdef OMPI_MPI_H  /* openmpi does not use signals: we may install our sighandler */
#if !defined(OPENACC) && !defined(_OPENMP)    /* ... but only if we are not also running on GPU */
#undef NOSIGNALS
#endif
#endif

/*
 * MPI_MASTER(i):
 * execution of i only on master node
 */
#define MPI_MASTER(statement) { \
  if(mpi_node_rank == mpi_node_root)\
  { statement; } \
}

#ifndef MPI_REDUCE_BLOCKSIZE
#define MPI_REDUCE_BLOCKSIZE 100000
#endif

int mc_MPI_Sum(double* buf, long count);
int mc_MPI_Send(void *sbuf, long count, MPI_Datatype dtype, int dest);
int mc_MPI_Recv(void *rbuf, long count, MPI_Datatype dtype, int source);

/* MPI_Finalize exits gracefully and should be preferred to MPI_Abort */
#define exit(code) do {                                   \
    MPI_Finalize();                                       \
    exit(code);                                           \
  } while(0)

#else /* !USE_MPI */
#define MPI_MASTER(instr) instr
#endif /* USE_MPI */


#ifdef USE_MPI
static int mpi_node_count;
#endif

#ifdef USE_THREADS  /* user want threads */
#error Threading (USE_THREADS) support has been removed for very poor efficiency. Use MPI/SSH grid instead.
#endif


void   mcset_ncount(unsigned long long count);    /* wrapper to get mcncount */
#pragma acc routine
unsigned long long int mcget_ncount(void);            /* wrapper to set mcncount */
unsigned long long mcget_run_num(void);           /* wrapper to get mcrun_num=0:mcncount-1 */

/* Following part is only embedded when not redundant with mccode.h ========= */

#ifndef MCCODE_H

#ifndef NOSIGNALS
#include <signal.h>
char  *mcsig_message;
#define SIG_MESSAGE(msg) mcsig_message=(char *)(msg);
#else
#define SIG_MESSAGE(...)
#endif /* !NOSIGNALS */


/* Useful macros and constants ============================================== */


#ifndef FLT_MAX
#define FLT_MAX         3.40282347E+38F /* max decimal value of a "float" */
#endif

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif
#ifndef SQR
#define SQR(x) ( (x) * (x) )
#endif
#ifndef SIGN
#define SIGN(x) (((x)>0.0)?(1):(-1))
#endif


#  ifndef M_E
#    define M_E        2.71828182845904523536  // e
#  endif
#  ifndef M_LOG2E
#    define M_LOG2E    1.44269504088896340736  //  log2(e)
#  endif
#  ifndef M_LOG10E
#    define M_LOG10E   0.434294481903251827651 //  log10(e)
#  endif
#  ifndef M_LN2
#    define M_LN2      0.693147180559945309417 //  ln(2)
#  endif
#  ifndef M_LN10
#    define M_LN10     2.30258509299404568402  //  ln(10)
#  endif
#  ifndef M_PI
#    define M_PI       3.14159265358979323846  //  pi
#  endif
#  ifndef PI
#    define PI       M_PI                      //  pi - also used in some places
#  endif
#  ifndef M_PI_2
#    define M_PI_2     1.57079632679489661923  //  pi/2
#  endif
#  ifndef M_PI_4
#    define M_PI_4     0.785398163397448309616 //  pi/4
#  endif
#  ifndef M_1_PI
#    define M_1_PI     0.318309886183790671538 //  1/pi
#  endif
#  ifndef M_2_PI
#    define M_2_PI     0.636619772367581343076 //  2/pi
#  endif
#  ifndef M_2_SQRTPI
#    define M_2_SQRTPI 1.12837916709551257390  //  2/sqrt(pi)
#  endif
#  ifndef M_SQRT2
#    define M_SQRT2    1.41421356237309504880  //  sqrt(2)
#  endif
#  ifndef M_SQRT1_2
#    define M_SQRT1_2  0.707106781186547524401 //  1/sqrt(2)
#  endif

#define RAD2MIN  ((180*60)/PI)
#define MIN2RAD  (PI/(180*60))
#define DEG2RAD  (PI/180)
#define RAD2DEG  (180/PI)
#define FWHM2RMS 0.424660900144    /* Convert between full-width-half-max and */
#define RMS2FWHM 2.35482004503     /* root-mean-square (standard deviation) */
#define HBAR     1.05457168e-34    /* [Js] h bar Planck constant CODATA 2002 */
#define MNEUTRON 1.67492728e-27    /* [kg] mass of neutron CODATA 2002 */
#define GRAVITY  9.81              /* [m/s^2] gravitational acceleration */
#define NA       6.02214179e23     /* [#atoms/g .mole] Avogadro's number*/


#define UNSET nan("0x6E6F74736574")
int nans_match(double, double);
int is_unset(double);
int is_valid(double);
int is_set(double);
int all_unset(int n, ...);
int all_set(int n, ...);
int any_unset(int n, ...);
int any_set(int n, ...);


/* wrapper to get absolute and relative position of comp */
/* mccomp_posa and mccomp_posr are defined in McStas generated C code */
#define POS_A_COMP_INDEX(index) (instrument->_position_absolute[index])
#define POS_R_COMP_INDEX(index) (instrument->_position_relative[index])

/* setting parameters based COMP_GETPAR (returned as pointer)         */
/* compname must be given as a string, type and par are symbols.      */
#define COMP_GETPAR3(type, compname, par) \
    &( ((_class_ ## type *) _getvar_parameters(compname))->par )
/* the body of this function depends on component instances, and is cogen'd */
void* _getvar_parameters(char* compname);

int _getcomp_index(char* compname);

/* Note: The two-stage approach to COMP_GETPAR is NOT redundant; without it,
* after #define C sample, COMP_GETPAR(C,x) would refer to component C, not to
* component sample. Such are the joys of ANSI C.

* Anyway the usage of COMP_GETPAR requires that we use sometimes bare names...
* NOTE: This can ONLY be used in instrument descriptions, not components.
*/
#define COMP_GETPAR2(comp, par) (_ ## comp ## _var.par)
#define COMP_GETPAR(comp, par) COMP_GETPAR2(comp,par)

#define INSTRUMENT_GETPAR(par) (_instrument_var.par)

/* Current component name, index, position and orientation */
/* These macros work because, using class-based functions, "comp" is usually
*  the local variable of the active/current component. */
#define INDEX_CURRENT_COMP (_comp->_index)
#define NAME_CURRENT_COMP (_comp->_name)
#define TYPE_CURRENT_COMP (_comp->_type)
#define POS_A_CURRENT_COMP (_comp->_position_absolute)
#define POS_R_CURRENT_COMP (_comp->_position_relative)
#define ROT_A_CURRENT_COMP (_comp->_rotation_absolute)
#define ROT_R_CURRENT_COMP (_comp->_rotation_relative)

#define NAME_INSTRUMENT (instrument->_name)


/* MCDISPLAY/trace and debugging message sent to stdout */
#ifdef MC_TRACE_ENABLED
#define DEBUG
#endif

#ifdef DEBUG
#define DEBUG_INSTR() if(!mcdotrace); else { printf("INSTRUMENT:\n"); printf("Instrument '%s' (%s)\n", instrument_name, instrument_source); }
#define DEBUG_COMPONENT(name,c,t) if(!mcdotrace); else {\
     printf("COMPONENT: \"%s\"\n"					  \
     "POS: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
     name, c.x, c.y, c.z, t[0][0], t[0][1], t[0][2], \
     t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]); \
     printf("Component %30s AT (%g,%g,%g)\n", name, c.x, c.y, c.z); }
#define DEBUG_INSTR_END() if(!mcdotrace); else printf("INSTRUMENT END:\n");
#define DEBUG_ENTER() if(!mcdotrace); else printf("ENTER:\n");
#define DEBUG_COMP(c) if(!mcdotrace); else printf("COMP: \"%s\"\n", c);
#define DEBUG_LEAVE() if(!mcdotrace); else printf("LEAVE:\n");
#define DEBUG_ABSORB() if(!mcdotrace); else printf("ABSORB:\n");
#else
#define DEBUG_INSTR()
#define DEBUG_COMPONENT(name,c,t)
#define DEBUG_INSTR_END()
#define DEBUG_ENTER()
#define DEBUG_COMP(c)
#define DEBUG_LEAVE()
#define DEBUG_ABSORB()
#endif

// mcDEBUG_STATE and mcDEBUG_SCATTER are defined by mcstas-r.h and mcxtrace-r.h



#ifdef TEST
#define test_printf printf
#else
#define test_printf while(0) printf
#endif

/* send MCDISPLAY message to stdout to show gemoetry */
void mcdis_magnify(char *what);
void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2);
void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n);
void mcdis_multiline(int count, ...);
void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height);
void mcdis_box(double x, double y, double z,
	       double width, double height, double length, double thickness, double nx, double ny, double nz);
void mcdis_circle(char *plane, double x, double y, double z, double r);
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz);
void mcdis_cylinder( double x, double y, double z,
		     double r, double height, double thickness, double nx, double ny, double nz);
void mcdis_cone( double x, double y, double z,
        double r, double height, double nx, double ny, double nz);
void mcdis_sphere(double x, double y, double z, double r);


/* random number generation. ================================================ */

#if RNG_ALG == _RNG_ALG_MT  // MT (currently not functional for GPU)
#  define MC_RAND_MAX ((uint32_t)0xffffffffUL)
#  define RANDSTATE_LEN 1
#  define srandom(seed) mt_srandom_empty()
#  define random() mt_random()
#  define _random() mt_random()
#elif RNG_ALG == _RNG_ALG_KISS  // KISS
#  ifndef UINT64_MAX
#    define UINT64_MAX ((uint64_t)0xffffffffffffffffULL)
#  endif
#  define MC_RAND_MAX UINT64_MAX
#  define RANDSTATE_LEN 7
#  define srandom(seed) kiss_srandom(_particle->randstate, seed)
#  define random() kiss_random(_particle->randstate)
#  define _random() kiss_random(state)
#endif

#pragma acc routine
double _randnorm2(randstate_t* state);

// Component writer interface
#define randnorm() _randnorm2(_particle->randstate)        // NOTE: can't use _randnorm on GPU
#define rand01() _rand01(_particle->randstate)
#define randpm1() _randpm1(_particle->randstate)
#define rand0max(p1) _rand0max(p1, _particle->randstate)
#define randminmax(p1, p2) _randminmax(p1, p2, _particle->randstate)
#define randtriangle() _randtriangle(_particle->randstate)

// Mersenne Twister rng
uint32_t mt_random(void);
void mt_srandom (uint32_t x);
void mt_srandom_empty();

// KISS rng
#pragma acc routine
uint64_t *kiss_srandom(uint64_t state[7], uint64_t seed);
#pragma acc routine
uint64_t kiss_random(uint64_t state[7]);

// Scrambler / hash function
#pragma acc routine seq
randstate_t _hash(randstate_t x);

// internal RNG (transforms) interface
#pragma acc routine
double _rand01(randstate_t* state);
#pragma acc routine
double _randpm1(randstate_t* state);
#pragma acc routine
double _rand0max(double max, randstate_t* state);
#pragma acc routine
double _randminmax(double min, double max, randstate_t* state);
#pragma acc routine
double _randtriangle(randstate_t* state);
// version which pass randstate_t* as opague void*
#pragma acc routine
double _rand01_opague(void* state);


#ifdef USE_OPENCL
#include "opencl-lib.h"
#include "opencl-lib.c"
#endif

#ifndef DANSE
int init(void);
int raytrace(_class_particle*);
int save(FILE *);
int finally(void);
int display(void);
#endif


/* GPU related algorithms =================================================== */

/*
*  Divide-and-conquer strategy for parallel sort absorbed last.
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier);
#endif
long sort_absorb_last_serial(_class_particle* particles, long len);


/* simple vector algebra ==================================================== */


#define vec_prod(x, y, z, x1, y1, z1, x2, y2, z2) \
	vec_prod_func(&x, &y, &z, x1, y1, z1, x2, y2, z2)
#pragma acc routine seq
mcstatic void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic double scalar_prod(
		double x1, double y1, double z1, double x2, double y2, double z2);

#pragma acc routine seq
mcstatic void norm_func(double *x, double *y, double *z);
#define NORM(x,y,z)	norm_func(&x, &y, &z)

#pragma acc routine seq
void normal_vec(double *nx, double *ny, double *nz,
    double x, double y, double z);

/**
 * Rotate the vector vx,vy,vz psi radians around the vector ax,ay,az
 * and put the result in x,y,z.
 */
#define rotate(x, y, z, vx, vy, vz, phi, ax, ay, az) \
  do { \
    double mcrt_tmpx = (ax), mcrt_tmpy = (ay), mcrt_tmpz = (az); \
    double mcrt_vp, mcrt_vpx, mcrt_vpy, mcrt_vpz; \
    double mcrt_vnx, mcrt_vny, mcrt_vnz, mcrt_vn1x, mcrt_vn1y, mcrt_vn1z; \
    double mcrt_bx, mcrt_by, mcrt_bz; \
    double mcrt_cos, mcrt_sin; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vp = scalar_prod((vx), (vy), (vz), mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_vpx = mcrt_vp*mcrt_tmpx; \
    mcrt_vpy = mcrt_vp*mcrt_tmpy; \
    mcrt_vpz = mcrt_vp*mcrt_tmpz; \
    mcrt_vnx = (vx) - mcrt_vpx; \
    mcrt_vny = (vy) - mcrt_vpy; \
    mcrt_vnz = (vz) - mcrt_vpz; \
    vec_prod(mcrt_bx, mcrt_by, mcrt_bz, \
             mcrt_tmpx, mcrt_tmpy, mcrt_tmpz, mcrt_vnx, mcrt_vny, mcrt_vnz); \
    mcrt_cos = cos((phi)); mcrt_sin = sin((phi)); \
    mcrt_vn1x = mcrt_vnx*mcrt_cos + mcrt_bx*mcrt_sin; \
    mcrt_vn1y = mcrt_vny*mcrt_cos + mcrt_by*mcrt_sin; \
    mcrt_vn1z = mcrt_vnz*mcrt_cos + mcrt_bz*mcrt_sin; \
    (x) = mcrt_vpx + mcrt_vn1x; \
    (y) = mcrt_vpy + mcrt_vn1y; \
    (z) = mcrt_vpz + mcrt_vn1z; \
  } while(0)

/**
 * Mirror (xyz) in the plane given by the point (rx,ry,rz) and normal (nx,ny,nz)
 *
 * TODO: This define is seemingly never used...
 */
#define mirror(x,y,z,rx,ry,rz,nx,ny,nz) \
  do { \
    double mcrt_tmpx= (nx), mcrt_tmpy = (ny), mcrt_tmpz = (nz); \
    double mcrt_tmpt; \
    NORM(mcrt_tmpx, mcrt_tmpy, mcrt_tmpz); \
    mcrt_tmpt=scalar_prod((rx),(ry),(rz),mcrt_tmpx,mcrt_tmpy,mcrt_tmpz); \
    (x) = rx -2 * mcrt_tmpt*mcrt_rmpx; \
    (y) = ry -2 * mcrt_tmpt*mcrt_rmpy; \
    (z) = rz -2 * mcrt_tmpt*mcrt_rmpz; \
  } while (0)

#pragma acc routine
Coords coords_set(MCNUM x, MCNUM y, MCNUM z);
#pragma acc routine
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z);
#pragma acc routine
Coords coords_add(Coords a, Coords b);
#pragma acc routine
Coords coords_sub(Coords a, Coords b);
#pragma acc routine
Coords coords_neg(Coords a);
#pragma acc routine
Coords coords_scale(Coords b, double scale);
#pragma acc routine
double coords_sp(Coords a, Coords b);
#pragma acc routine
Coords coords_xp(Coords b, Coords c);
#pragma acc routine
double coords_len(Coords a);
#pragma acc routine seq
void   coords_print(Coords a);
#pragma acc routine seq
mcstatic void coords_norm(Coords* c);

#pragma acc routine seq
void rot_set_rotation(Rotation t, double phx, double phy, double phz);
#pragma acc routine seq
int  rot_test_identity(Rotation t);
#pragma acc routine seq
void rot_mul(Rotation t1, Rotation t2, Rotation t3);
#pragma acc routine seq
void rot_copy(Rotation dest, Rotation src);
#pragma acc routine seq
void rot_transpose(Rotation src, Rotation dst);
#pragma acc routine seq
Coords rot_apply(Rotation t, Coords a);

#pragma acc routine seq
void mccoordschange(Coords a, Rotation t, _class_particle *particle);
#pragma acc routine seq
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz);

double mcestimate_error(double N, double p1, double p2);
void mcreadparams(void);

/* this is now in mcstas-r.h and mcxtrace-r.h as the number of state parameters
is no longer equal */

_class_particle mcgenstate(void);

// trajectory/shape intersection routines
#pragma acc routine seq
int inside_rectangle(double, double, double, double);
#pragma acc routine seq
int box_intersect(double *dt_in, double *dt_out, double x, double y, double z,
      double vx, double vy, double vz, double dx, double dy, double dz);
#pragma acc routine seq
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r, double h);
#pragma acc routine seq
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
      double vx, double vy, double vz, double r);
// second order equation roots
#pragma acc routine seq
int solve_2nd_order(double *t1, double *t2,
      double A,  double B,  double C);

// random vector generation to shape
// defines silently introducing _particle as the last argument
#define randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius) \
  _randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, radius, _particle)
#define randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A) \
  _randvec_target_rect_angular(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, _particle)
#define randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order) \
  _randvec_target_rect_real(xo, yo, zo, solid_angle, xi, yi, zi, height, width, A, lx, ly, lz, order, _particle)
// defines forwarding to "inner" functions
#define randvec_target_sphere randvec_target_circle
#define randvec_target_rect(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9) \
  randvec_target_rect_real(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,0,0,0,1)
// headers for randvec
#pragma acc routine seq
void _randvec_target_circle(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double radius,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_angular(double *xo, double *yo, double *zo,
  double *solid_angle, double xi, double yi, double zi, double height,
  double width, Rotation A,
  _class_particle* _particle);
#pragma acc routine seq
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
  double xi, double yi, double zi, double height, double width, Rotation A,
  double lx, double ly, double lz, int order,
  _class_particle* _particle);


// this is the main()
int mccode_main(int argc, char *argv[]);


#endif /* !MCCODE_H */

#ifndef MCCODE_R_IO_H
#define MCCODE_R_IO_H "$Revision$"

#if (USE_NEXUS == 0)
#undef USE_NEXUS
#endif

#ifndef CHAR_BUF_LENGTH
#define CHAR_BUF_LENGTH 1024
#endif


/* I/O section part ========================================================= */

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */


/* main DETECTOR structure which stores most information to write to data files */
struct mcdetector_struct {
  char   filename[CHAR_BUF_LENGTH];   /* file name of monitor */
  double Position[3];                 /* position of detector component*/
  char   position[CHAR_BUF_LENGTH];   /* position of detector component (string)*/
  Rotation Rotation;                  /* position of detector component*/
  char   options[CHAR_BUF_LENGTH];    /* Monitor_nD style list-mode'options' (string)*/
  char   component[CHAR_BUF_LENGTH];  /* component instance name */
  char   nexuscomp[CHAR_BUF_LENGTH];  /* component naming in NeXus/HDF case */
  char   instrument[CHAR_BUF_LENGTH]; /* instrument name */
  char   type[CHAR_BUF_LENGTH];       /* data type, e.g. 0d, 1d, 2d, 3d */
  char   user[CHAR_BUF_LENGTH];       /* user name, e.g. HOME */
  char   date[CHAR_BUF_LENGTH];       /* date of simulation end/write time */
  char   title[CHAR_BUF_LENGTH];      /* title of detector */
  char   xlabel[CHAR_BUF_LENGTH];     /* X axis label */
  char   ylabel[CHAR_BUF_LENGTH];     /* Y axis label */
  char   zlabel[CHAR_BUF_LENGTH];     /* Z axis label */
  char   xvar[CHAR_BUF_LENGTH];       /* X variable name */
  char   yvar[CHAR_BUF_LENGTH];       /* Y variable name */
  char   zvar[CHAR_BUF_LENGTH];       /* Z variable name */
  char   ncount[CHAR_BUF_LENGTH];     /* number of events initially generated */
  char   limits[CHAR_BUF_LENGTH];     /* X Y Z limits, e.g. [xmin xmax ymin ymax zmin zmax] */
  char   variables[CHAR_BUF_LENGTH];  /* variables written into data block */
  char   statistics[CHAR_BUF_LENGTH]; /* center, mean and half width along axis */
  char   signal[CHAR_BUF_LENGTH];     /* min max and mean of signal (data block) */
  char   values[CHAR_BUF_LENGTH];     /* integrated values e.g. [I I_err N] */
  double xmin,xmax;                   /* min max of axes */
  double ymin,ymax;
  double zmin,zmax;
  double intensity;                   /* integrated values for data block */
  double error;
  double events;
  double min;                         /* statistics for data block */
  double max;
  double mean;
  double centerX;                     /* statistics for axes */
  double halfwidthX;
  double centerY;
  double halfwidthY;
  int    rank;                        /* dimensionaly of monitor, e.g. 0 1 2 3 */
  char   istransposed;                /* flag to transpose matrix for some formats */

  long   m,n,p;                       /* dimensions of data block and along axes */
  long   date_l;                      /* same as date, but in sec since 1970 */

  double *p0, *p1, *p2;               /* pointers to saved data, NULL when freed */
  char   format[CHAR_BUF_LENGTH];    /* format for file generation */
};

typedef struct mcdetector_struct MCDETECTOR;

static   char *dirname             = NULL;      /* name of output directory */
static   char *siminfo_name        = "mccode";  /* default output sim file name */
char    *mcformat                    = NULL;      /* NULL (default) or a specific format */

/* file I/O definitions and function prototypes */

#ifndef MC_EMBEDDED_RUNTIME /* the mcstatic variables (from mccode-r.c) */
extern FILE * siminfo_file;     /* handle to the output siminfo file */
extern int    mcgravitation;      /* flag to enable gravitation */
extern int    mcdotrace;          /* flag to print MCDISPLAY messages */
#else
mcstatic FILE *siminfo_file        = NULL;
#endif

/* I/O function prototypes ================================================== */

// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle);

/* output functions */
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2, char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
                  char *xvar, double x1, double x2, long n,
                  double *p0, double *p1, double *p2, char *f, char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2, long m,
                  long n, double *p0, double *p1, double *p2, char *f,
                  char *c, Coords pos, Rotation rot, int index);
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
	          char *c, Coords posa, Rotation rot,char* options, int index);

/* wrappers to output functions, that automatically set NAME and POSITION */
#define DETECTOR_OUT(p0,p1,p2) mcdetector_out_0D(NAME_CURRENT_COMP,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_0D(t,p0,p1,p2) mcdetector_out_0D(t,p0,p1,p2,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f) \
     mcdetector_out_1D(t,xl,yl,xvar,x1,x2,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)
#define DETECTOR_OUT_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f) \
     mcdetector_out_2D(t,xl,yl,x1,x2,y1,y2,m,n,p0,p1,p2,f,NAME_CURRENT_COMP,POS_A_CURRENT_COMP,ROT_A_CURRENT_COMP,INDEX_CURRENT_COMP)

#ifdef USE_NEXUS
#include "napi.h"
NXhandle nxhandle;
#endif

#endif /* ndef MCCODE_R_IO_H */

#endif /* MCCODE_R_H */
/* End of file "mccode-r.h". */

/* embedding file "mcstas-r.h" */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.h
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y
* Version: $Revision$
*
* Runtime system header for McStas.
*
* In order to use this library as an external library, the following variables
* and macros must be declared (see details in the code)
*
*   struct mcinputtable_struct mcinputtable[];
*   int mcnumipar;
*   char instrument_name[], instrument_source[];
*   int traceenabled, defaultmain;
*   extern MCNUM  mccomp_storein[];
*   extern MCNUM  instrument.counter_AbsorbProp[];
*   extern MCNUM  mcScattered;
*   #define MCCODE_STRING "the McStas version"
*
* Usage: Automatically embbeded in the c code.
*
* $Id$
*
*******************************************************************************/

#ifndef MCSTAS_R_H
#define MCSTAS_R_H "$Revision$"

/* Following part is only embedded when not redundent with mcstas.h */

#ifndef MCCODE_H

#define AA2MS    629.622368        /* Convert k[1/AA] to v[m/s] */
#define MS2AA    1.58825361e-3     /* Convert v[m/s] to k[1/AA] */
#define K2V      AA2MS
#define V2K      MS2AA
#define Q2V      AA2MS
#define V2Q      MS2AA
#define SE2V     437.393377        /* Convert sqrt(E)[meV] to v[m/s] */
#define VS2E     5.22703725e-6     /* Convert (v[m/s])**2 to E[meV] */

#define SCATTER0 do {DEBUG_SCATTER(); SCATTERED++;} while(0)
#define SCATTER SCATTER0

#define JUMPTOCOMP(comp) mcneutron->_index = INDEX_COMP(comp);

#define MAGNET_ON \
  do { \
    mcMagnet = 1; \
  } while(0)

#define MAGNET_OFF \
  do { \
    mcMagnet = 0; \
  } while(0)

#define ALLOW_BACKPROP \
  do { \
    allow_backprop = 1; \
  } while(0)

#define DISALLOW_BACKPROP \
  do { \
    allow_backprop = 0; \
  } while(0)

#define PROP_MAGNET(dt) \
  do { \
  } while (0)
    /* change coordinates from local system to magnet system */
/*    Rotation rotLM, rotTemp; \
      Coords   posLM = coords_sub(POS_A_CURRENT_COMP, mcMagnetPos); \
      rot_transpose(ROT_A_CURRENT_COMP, rotTemp); \
      rot_mul(rotTemp, mcMagnetRot, rotLM); \
      mcMagnetPrecession(x, y, z, t, vx, vy, vz, \
               &sx, &sy, &sz, dt, posLM, rotLM); \
      } while(0)
*/

#define mcPROP_DT(dt) \
  do { \
    if (mcMagnet && dt > 0) PROP_MAGNET(dt);\
    x += vx*(dt); \
    y += vy*(dt); \
    z += vz*(dt); \
    t += (dt); \
    if (isnan(p) || isinf(p)) { ABSORB; }\
  } while(0)

/* ADD: E. Farhi, Aug 6th, 2001 PROP_GRAV_DT propagation with acceleration */
#define PROP_GRAV_DT(dt, Ax, Ay, Az) \
  do { \
    if(dt < 0 && allow_backprop == 0) { ABSORB; }\
    if (mcMagnet) /*printf("Spin precession gravity\n")*/; \
    x  += vx*(dt) + (Ax)*(dt)*(dt)/2; \
    y  += vy*(dt) + (Ay)*(dt)*(dt)/2; \
    z  += vz*(dt) + (Az)*(dt)*(dt)/2; \
    vx += (Ax)*(dt); \
    vy += (Ay)*(dt); \
    vz += (Az)*(dt); \
    t  += (dt); \
    DISALLOW_BACKPROP;\
  } while(0)


#define PROP_DT(dt) \
  do { \
    if(dt < 0 && allow_backprop == 0) { RESTORE=1; ABSORB; }; \
    if (mcgravitation) { Coords mcLocG; double mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    PROP_GRAV_DT(dt, mc_gx, mc_gy, mc_gz); } \
    else mcPROP_DT(dt); \
    DISALLOW_BACKPROP;\
  } while(0)


#define PROP_Z0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gz/2, -vz, -z); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); z=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_Z0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define mcPROP_Z0 \
  do { \
    double mc_dt; \
    if(vz == 0) { ABSORB; }; \
    mc_dt = -z/vz; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    z = 0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_X0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gx/2, -vx, -x); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); x=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_X0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define mcPROP_X0 \
  do { \
    double mc_dt; \
    if(vx == 0) { ABSORB; }; \
    mc_dt = -x/vx; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    x = 0; \
    DISALLOW_BACKPROP;\
  } while(0)

#define PROP_Y0 \
  do { \
    if (mcgravitation) { Coords mcLocG; int mc_ret; \
    double mc_dt, mc_gx, mc_gy, mc_gz; \
    mcLocG = rot_apply(ROT_A_CURRENT_COMP, coords_set(0,-GRAVITY,0)); \
    coords_get(mcLocG, &mc_gx, &mc_gy, &mc_gz); \
    mc_ret = solve_2nd_order(&mc_dt, NULL, -mc_gy/2, -vy, -y); \
    if (mc_ret) {PROP_GRAV_DT(mc_dt, mc_gx, mc_gy, mc_gz); y=0;}\
    else if (allow_backprop == 0 && mc_dt < 0) { ABSORB; }; } \
    else mcPROP_Y0; \
    DISALLOW_BACKPROP;\
  } while(0)


#define mcPROP_Y0 \
  do { \
    double mc_dt; \
    if(vy == 0) { ABSORB; }; \
    mc_dt = -y/vy; \
    if(mc_dt < 0 && allow_backprop == 0) { ABSORB; }; \
    mcPROP_DT(mc_dt); \
    y = 0; \
    DISALLOW_BACKPROP; \
  } while(0)


#ifdef DEBUG

#define DEBUG_STATE() if(!mcdotrace); else \
  printf("STATE: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         x,y,z,vx,vy,vz,t,sx,sy,sz,p);
#define DEBUG_SCATTER() if(!mcdotrace); else \
  printf("SCATTER: %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g\n", \
         x,y,z,vx,vy,vz,t,sx,sy,sz,p);

#else

#define DEBUG_STATE()
#define DEBUG_SCATTER()

#endif

#endif /* !MCCODE_H */

#endif /* MCSTAS_R_H */
/* End of file "mcstas-r.h". */

/* embedding file "mccode-r.c" */

/*******************************************************************************
*
* McCode, neutron/xray ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mccode-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y/McXtrace X.Y
* Version: $Revision$
*
* Runtime system for McStas and McXtrace.
* Embedded within instrument in runtime mode.
* Contains SECTIONS:
*   MPI handling (sum, send, recv)
*   format definitions
*   I/O
*   mcdisplay support
*   random numbers
*   coordinates handling
*   vectors math (solve 2nd order, normals, randvec...)
*   parameter handling
*   signal and main handlers
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/


/** Include header files to avoid implicit declarations (not allowed on LLVM) */
#include <ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

// UNIX specific headers (non-Windows)
#if defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#include <sys/stat.h>
#endif


#ifndef DANSE
#ifdef MC_ANCIENT_COMPATIBILITY
int traceenabled = 0;
int defaultmain  = 0;
#endif
/* else defined directly in the McCode generated C code */

#pragma omp declare target
static   long mcseed                 = 0; /* seed for random generator */
#pragma omp end declare target

static   long mcstartdate            = 0; /* start simulation time */
static   int  mcdisable_output_files = 0; /* --no-output-files */

#pragma omp declare target
mcstatic int  mcgravitation          = 0; /* use gravitation flag, for PROP macros */
#pragma omp end declare target
mcstatic int  mcusedefaults          = 0; /* assume default value for all parameters */
mcstatic int  mcappend               = 0; /* flag to allow append mode on datasets/directories */
#pragma omp declare target
mcstatic int  mcdotrace              = 0; /* flag for --trace and messages for DISPLAY */
#pragma omp end declare target
mcstatic int  mcnexus_embed_idf      = 0; /* flag to embed xml-formatted IDF file for Mantid */
int      mcallowbackprop             = 0;         /* flag to enable negative/backprop */

/* OpenACC-related segmentation parameters: */
int vecsize = 128;
int numgangs = 7813;
long gpu_innerloop = 2147483647;

/* Monitor_nD list/buffer-size default */
/* Starting value may be defined using -DND_BUFFER=N */
/* Can further be controlled dynamically using --bufsiz input */
long MONND_BUFSIZ = 10000000;
#ifdef ND_BUFFER
MONND_BUFSIZ = ND_BUFFER;
#endif
 

/* Number of particle histories to simulate. */

#ifdef NEUTRONICS
mcstatic unsigned long long int mcncount             = 1;
mcstatic unsigned long long int mcrun_num            = 0;
#else
#pragma omp declare target
#ifdef MCDEFAULT_NCOUNT
mcstatic unsigned long long int mcncount             = MCDEFAULT_NCOUNT;
#else
mcstatic unsigned long long int mcncount             = 1000000;
#endif
mcstatic unsigned long long int mcrun_num            = 0;
#pragma omp end declare target
#endif /* NEUTRONICS */

#else
#include "mcstas-globals.h"
#endif /* !DANSE */

#ifndef NX_COMPRESSION
#define NX_COMPRESSION NX_COMP_NONE
#endif

/* String nullification on GPU and other replacements */
#if defined(OPENACC) || defined(_OPENMP)
int noprintf() {
  return 0;
}

int str_comp(char *str1, char *str2) {
  while (*str1 && *str1 == *str2) {
    str1++;
    str2++;
  }
  return (*str1 - *str2);
}

size_t str_len(const char *s)
{
  size_t len = 0;
  if(s != NULL)
  {
    while(*s != '\0')
    {
      ++len;
      ++s;
    }
  }
  return len;
}

#endif

/* SECTION: Predefine (component) parameters ================================= */

int nans_match(double a, double b){
  return (*(uint64_t*)&a == *(uint64_t*)&b);
}
int is_unset(double x){
  return nans_match(x, UNSET);
}
int is_set(double x){
  return !nans_match(x, UNSET);
}
int is_valid(double x){
  return !isnan(x)||is_unset(x);
}
int all_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int all_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=1;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=0;
  va_end(ptr);
  return ret;
}
int any_unset(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_unset(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}
int any_set(int n, ...){
  va_list ptr;
  va_start(ptr, n);
  int ret=0;
  for (int i=0; i<n; ++i) if(is_set(va_arg(ptr, double))) ret=1;
  va_end(ptr);
  return ret;
}


/* SECTION: Dynamic Arrays ================================================== */
IArray1d create_iarr1d(int n){
  IArray1d arr1d;
  arr1d = calloc(n, sizeof(int));
  if (!arr1d) {
    fprintf(stderr, "Error allocating IArray1d of dimension %i\n",n);
    exit(-1);
  }
  return arr1d;
}

void destroy_iarr1d(IArray1d a){
  free(a);
}

IArray2d create_iarr2d(int nx, int ny){
  IArray2d arr2d;
  arr2d = calloc(nx, sizeof(int *));
  if (!arr2d) {
    fprintf(stderr, "Error allocating IArray2d of dimension %i x %i\n",nx,ny);
    exit(-1);
  }

  int *p1;
  p1 = calloc(nx*ny, sizeof(int));

  if (!p1) {
    fprintf(stderr, "Error allocating int* array of dimension %i\n",nx*ny);
    exit(-1);
  }
  
  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_iarr2d(IArray2d a){
  free(a[0]);
  free(a);
}

IArray3d create_iarr3d(int nx, int ny, int nz){
  IArray3d arr3d;
  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(int **));
  if (!arr3d) {
    fprintf(stderr, "Error allocating IArray3d of dimension %i x %i x %i\n",nx,ny,nz);
    exit(-1);
  }

  // d2
  int **p1;
  p1 = calloc(nx*ny, sizeof(int *));

  if (!p1) {
    fprintf(stderr, "Error allocating int** array of dimension %i\n",nx*ny);
    exit(-1);
  }
  
  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  int *p2;
  p2 = calloc(nx*ny*nz, sizeof(int));
  if (!p2) {
    fprintf(stderr, "Error allocating int* array of dimension %i\n",nx*ny*nz);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_iarr3d(IArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}

DArray1d create_darr1d(int n){
  DArray1d arr1d;
  arr1d = calloc(n, sizeof(double));
  if (!arr1d) {
    fprintf(stderr, "Error allocating DArray1d of dimension %i\n",n);
    exit(-1);
  }
  return arr1d;
}

void destroy_darr1d(DArray1d a){
  free(a);
}

DArray2d create_darr2d(int nx, int ny){
  DArray2d arr2d;
  arr2d = calloc(nx, sizeof(double *));
  if (!arr2d) {
    fprintf(stderr, "Error allocating DArray2d of dimension %i x %i\n",nx,ny);
    exit(-1);
  }
  double *p1;
  p1 = calloc(nx*ny, sizeof(double));
  if (!p1) {
    fprintf(stderr, "Error allocating double* array of dimension %i\n",nx*ny);
    exit(-1);
  }
  int i;
  for (i=0; i<nx; i++){
    arr2d[i] = &(p1[i*ny]);
  }
  return arr2d;
}

void destroy_darr2d(DArray2d a){
  free(a[0]);
  free(a);
}

DArray3d create_darr3d(int nx, int ny, int nz){
  DArray3d arr3d;

  int i, j;

  // 1d
  arr3d = calloc(nx, sizeof(double **));
  if (!arr3d) {
    fprintf(stderr, "Error allocating DArray3d of dimension %i x %i x %i\n",nx,ny,nz);
    exit(-1);
  }
  // d2
  double **p1;
  p1 = calloc(nx*ny, sizeof(double *));
  if (!p1) {
    fprintf(stderr, "Error allocating double** array of dimension %i\n",nx*ny);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    arr3d[i] = &(p1[i*ny]);
  }

  // 3d
  double *p2;
  p2 = calloc(nx*ny*nz, sizeof(double));
  if (!p2) {
    fprintf(stderr, "Error allocating double* array of dimension %i\n",nx*ny*nz);
    exit(-1);
  }
  for (i=0; i<nx; i++){
    for (j=0; j<ny; j++){
      arr3d[i][j] = &(p2[(i*ny+j)*nz]);
    }
  }
  return arr3d;
}

void destroy_darr3d(DArray3d a){
  free(a[0][0]);
  free(a[0]);
  free(a);
}


/* SECTION: MPI handling ==================================================== */

#ifdef USE_MPI
/* MPI rank */
static int mpi_node_rank;
static int mpi_node_root = 0;


/*******************************************************************************
* mc_MPI_Reduce: Gathers arrays from MPI nodes using Reduce function.
*******************************************************************************/
int mc_MPI_Sum(double *sbuf, long count)
{
  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to reduce */
  else {
    /* we must cut the buffer into blocks not exceeding the MPI max buffer size of 32000 */
    long   offset=0;
    double *rbuf=NULL;
    int    length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */
    int    i=0;
    rbuf = calloc(count, sizeof(double));
    if (!rbuf)
      exit(-fprintf(stderr, "Error: Out of memory %zi (mc_MPI_Sum)\n", count*sizeof(double)));
    while (offset < count) {
      if (!length || offset+length > count-1) length=count-offset;
      else length=MPI_REDUCE_BLOCKSIZE;
      if (MPI_Allreduce((double*)(sbuf+offset), (double*)(rbuf+offset),
              length, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD) != MPI_SUCCESS)
        return MPI_ERR_COUNT;
      offset += length;
    }

    for (i=0; i<count; i++) sbuf[i] = rbuf[i];
    free(rbuf);
  }
  return MPI_SUCCESS;
} /* mc_MPI_Sum */

/*******************************************************************************
* mc_MPI_Send: Send array to MPI node by blocks to avoid buffer limit
*******************************************************************************/
int mc_MPI_Send(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int dest)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to send */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Send((void*)((char*)sbuf+offset*dsize), length, dtype, dest, tag++, MPI_COMM_WORLD) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Send */

/*******************************************************************************
* mc_MPI_Recv: Receives arrays from MPI nodes by blocks to avoid buffer limit
*             the buffer must have been allocated previously.
*******************************************************************************/
int mc_MPI_Recv(void *sbuf,
                  long count, MPI_Datatype dtype,
                  int source)
{
  int dsize;
  long offset=0;
  int  tag=1;
  int  length=MPI_REDUCE_BLOCKSIZE; /* defined in mccode-r.h */

  if (!sbuf || count <= 0) return(MPI_SUCCESS); /* nothing to recv */
  MPI_Type_size(dtype, &dsize);

  while (offset < count) {
    if (offset+length > count-1) length=count-offset;
    else length=MPI_REDUCE_BLOCKSIZE;
    if (MPI_Recv((void*)((char*)sbuf+offset*dsize), length, dtype, source, tag++,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE) != MPI_SUCCESS)
      return MPI_ERR_COUNT;
    offset += length;
  }

  return MPI_SUCCESS;
} /* mc_MPI_Recv */

#endif /* USE_MPI */

/* SECTION: parameters handling ============================================= */

/* Instrument input parameter type handling. */
/*******************************************************************************
* mcparm_double: extract double value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_double(char *s, void *vptr)
{
  char *p;
  double *v = (double *)vptr;

  if (!s) { *v = 0; return(1); }
  *v = strtod(s, &p);
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_double: display parameter type double
*******************************************************************************/
static char *
mcparminfo_double(char *parmname)
{
  return "double";
}

/*******************************************************************************
* mcparmerror_double: display error message when failed extract double
*******************************************************************************/
static void
mcparmerror_double(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for floating point parameter %s (mcparmerror_double)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_double: convert double to string
*******************************************************************************/
static void
mcparmprinter_double(char *f, void *vptr)
{
  double *v = (double *)vptr;
  sprintf(f, "%g", *v);
}

/*******************************************************************************
* mcparm_int: extract int value from 's' into 'vptr'
*******************************************************************************/
static int
mcparm_int(char *s, void *vptr)
{
  char *p;
  int *v = (int *)vptr;
  long x;

  if (!s) { *v = 0; return(1); }
  *v = 0;
  x = strtol(s, &p, 10);
  if(x < INT_MIN || x > INT_MAX)
    return 0;                        /* Under/overflow */
  *v = x;
  if(*s == '\0' || (p != NULL && *p != '\0') || errno == ERANGE)
    return 0;                        /* Failed */
  else
    return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_int: display parameter type int
*******************************************************************************/
static char *
mcparminfo_int(char *parmname)
{
  return "int";
}

/*******************************************************************************
* mcparmerror_int: display error message when failed extract int
*******************************************************************************/
static void
mcparmerror_int(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for integer parameter %s (mcparmerror_int)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_int: convert int to string
*******************************************************************************/
static void
mcparmprinter_int(char *f, void *vptr)
{
  int *v = (int *)vptr;
  sprintf(f, "%d", *v);
}

/*******************************************************************************
* mcparm_string: extract char* value from 's' into 'vptr' (copy)
*******************************************************************************/
static int
mcparm_string(char *s, void *vptr)
{
  char **v = (char **)vptr;
  if (!s) { *v = NULL; return(1); }
  *v = (char *)malloc(strlen(s) + 1);
  if(*v == NULL)
  {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcparm_string).\n", (long)strlen(s) + 1));
  }
  strcpy(*v, s);
  return 1;                        /* Success */
}

/*******************************************************************************
* mcparminfo_string: display parameter type string
*******************************************************************************/
static char *
mcparminfo_string(char *parmname)
{
  return "string";
}

/*******************************************************************************
* mcparmerror_string: display error message when failed extract string
*******************************************************************************/
static void
mcparmerror_string(char *parm, char *val)
{
  fprintf(stderr, "Error: Invalid value '%s' for string parameter %s (mcparmerror_string)\n",
          val, parm);
}

/*******************************************************************************
* mcparmprinter_string: convert string to string (including esc chars)
*******************************************************************************/
static void
mcparmprinter_string(char *f, void *vptr)
{
  char **v = (char **)vptr;
  char *p;

  if (!*v) { *f='\0'; return; }
  strcpy(f, "");
  for(p = *v; *p != '\0'; p++)
  {
    switch(*p)
    {
      case '\n':
        strcat(f, "\\n");
        break;
      case '\r':
        strcat(f, "\\r");
        break;
      case '"':
        strcat(f, "\\\"");
        break;
      case '\\':
        strcat(f, "\\\\");
        break;
      default:
        strncat(f, p, 1);
    }
  }
  /* strcat(f, "\""); */
} /* mcparmprinter_string */

/* now we may define the parameter structure, using previous functions */
static struct
  {
    int (*getparm)(char *, void *);
    char * (*parminfo)(char *);
    void (*error)(char *, char *);
    void (*printer)(char *, void *);
} mcinputtypes[] = {
  {
    mcparm_int, mcparminfo_int, mcparmerror_int,
    mcparmprinter_int
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_string, mcparminfo_string, mcparmerror_string,
    mcparmprinter_string
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }, {
    mcparm_double, mcparminfo_double, mcparmerror_double,
    mcparmprinter_double
  }
};

/*******************************************************************************
* mcestimate_error: compute sigma from N,p,p2 in Gaussian large numbers approx
*******************************************************************************/
double mcestimate_error(double N, double p1, double p2)
{
  double pmean, n1;
  if(N <= 1)
    return p1;
  pmean = p1 / N;
  n1 = N - 1;
  /* Note: underflow may cause p2 to become zero; the fabs() below guards
     against this. */
  return sqrt((N/n1)*fabs(p2 - pmean*pmean));
}

double (*mcestimate_error_p)
  (double V2, double psum, double p2sum)=mcestimate_error;

/* ========================================================================== */

/*                               MCCODE_R_IO_C                                */

/* ========================================================================== */

#ifndef MCCODE_R_IO_C
#define MCCODE_R_IO_C "$Revision$"

/* SECTION: file i/o handling ================================================ */

#ifndef HAVE_STRCASESTR
// from msysgit: https://code.google.com/p/msysgit/source/browse/compat/strcasestr.c
char *strcasestr(const char *haystack, const char *needle)
{
  int nlen = strlen(needle);
  int hlen = strlen(haystack) - nlen + 1;
  int i;

  for (i = 0; i < hlen; i++) {
    int j;
    for (j = 0; j < nlen; j++) {
            unsigned char c1 = haystack[i+j];
            unsigned char c2 = needle[j];
            if (toupper(c1) != toupper(c2))
                    goto next;
    }
    return (char *) haystack + i;
  next:
    ;
  }
  return NULL;
}


#endif
#ifndef HAVE_STRCASECMP
int strcasecmp( const char *s1, const char *s2 )
{
  int c1, c2;
  do {
    c1 = tolower( (unsigned char) *s1++ );
    c2 = tolower( (unsigned char) *s2++ );
  } while (c1 == c2 && c1 != 0);
  return c2 > c1 ? -1 : c1 > c2;
}
#endif

#ifndef STRACPY
/* this is a replacement to strncpy, but ensures that the copy ends with NULL */
/* http://stracpy.blogspot.fr/2011/04/stracpy-strncpy-replacement.html */
#define STRACPY
char *stracpy(char *destination, const char *source, size_t amount)
{
        if (!destination || !source || !amount) return(NULL);
        while(amount--)
          if((*destination++ = *source++) == '\0') break;
        *destination = '\0';
        return destination;
}
#endif

/*******************************************************************************
* mcfull_file: allocates a full file name=dirname+file. Catenate extension if missing.
*******************************************************************************/
char *mcfull_file(char *name, char *ext)
{
  int   dirlen=0;
  char *mem   =NULL;

  dirlen = dirname ? strlen(dirname) : 0;
  mem = (char*)malloc(dirlen + strlen(name) + CHAR_BUF_LENGTH);
  if(!mem) {
    exit(-fprintf(stderr, "Error: Out of memory %li (mcfull_file)\n", (long)(dirlen + strlen(name) + 256)));
  }
  strcpy(mem, "");

  /* prepend directory name to path if name does not contain a path */
  if (dirlen > 0 && !strchr(name, MC_PATHSEP_C)) {
    strcat(mem, dirname);
    strcat(mem, MC_PATHSEP_S);
  } /* dirlen */

  strcat(mem, name);
  if (!strchr(name, '.') && ext && strlen(ext))
  { /* add extension if not in file name already */
    strcat(mem, ".");
    strcat(mem, ext);
  }
  return(mem);
} /* mcfull_file */

/*******************************************************************************
* mcnew_file: opens a new file within dirname if non NULL
*             the file is opened in "a" (append, create if does not exist)
*             the extension 'ext' is added if the file name does not include one.
*             the last argument is set to 0 if file did not exist, else to 1.
*******************************************************************************/
FILE *mcnew_file(char *name, char *ext, int *exists)
{
  char *mem;
  FILE *file=NULL;

  if (!name || strlen(name) == 0 || mcdisable_output_files) return(NULL);

  mem  = mcfull_file(name, ext); /* create dirname/name.ext */

  /* check for existence */
  file = fopen(mem, "r"); /* for reading -> fails if does not exist */
  if (file) {
    fclose(file);
    *exists=1;
  } else
    *exists=0;

  /* open the file for writing/appending */
#ifdef USE_NEXUS
  if (mcformat && strcasestr(mcformat, "NeXus")) {
    /* NXhandle nxhandle is defined in the .h with USE_NEXUS */
    NXaccess mode = (*exists ? NXACC_CREATE5 | NXACC_RDWR : NXACC_CREATE5);

    if (NXopen(mem, mode, &nxhandle) != NX_OK)
      file = NULL;
    else
      file = (FILE*)&nxhandle; /* to make it non NULL */
  } else
#endif
    file = fopen(mem, "a+");

  if(!file)
    fprintf(stderr, "Warning: could not open output file '%s' for %s (mcnew_file)\n",
      mem, *exists ? "append" : "create");
  free(mem);

  return file;
} /* mcnew_file */

/*******************************************************************************
* mcdetector_statistics: compute detector statistics, error bars, [x I I_err N] 1D
* RETURN:            updated detector structure
* Used by: detector_import
*******************************************************************************/
MCDETECTOR mcdetector_statistics(
  MCDETECTOR detector)
{

  if (!detector.p1 || !detector.m)
    return(detector);

  /* compute statistics and update MCDETECTOR structure ===================== */
  double sum_z  = 0, min_z  = 0, max_z  = 0;
  double fmon_x =0,  smon_x = 0, fmon_y =0, smon_y=0, mean_z=0;
  double Nsum=0, P2sum=0;

  double sum_xz = 0, sum_yz = 0, sum_x = 0, sum_y = 0, sum_x2z = 0, sum_y2z = 0;
  int    i,j;
  char   hasnan=0, hasinf=0;
  char   israw = ((char*)strcasestr(detector.format,"raw") != NULL);
  double *this_p1=NULL; /* new 1D McCode array [x I E N]. Freed after writing data */

  /* if McCode/PGPLOT and rank==1 we create a new m*4 data block=[x I E N] */
  if (detector.rank == 1 && strcasestr(detector.format,"McCode")) {
    this_p1 = (double *)calloc(detector.m*detector.n*detector.p*4, sizeof(double));
    if (!this_p1)
      exit(-fprintf(stderr, "Error: Out of memory creating %zi 1D " MCCODE_STRING " data set for file '%s' (detector_import)\n",
        detector.m*detector.n*detector.p*4*sizeof(double*), detector.filename));
  }

  max_z = min_z = detector.p1[0];

  /* compute sum and moments (not for lists) */
  if (!strcasestr(detector.format,"list") && detector.m)
  for(j = 0; j < detector.n*detector.p; j++)
  {
    for(i = 0; i < detector.m; i++)
    {
      double x,y,z;
      double N, E;
      long   index= !detector.istransposed ? i*detector.n*detector.p + j : i+j*detector.m;
      char   hasnaninf=0;

      if (detector.m)
        x = detector.xmin + (i + 0.5)/detector.m*(detector.xmax - detector.xmin);
      else x = 0;
      if (detector.n && detector.p)
        y = detector.ymin + (j + 0.5)/detector.n/detector.p*(detector.ymax - detector.ymin);
      else y = 0;
      z = detector.p1[index];
      N = detector.p0 ? detector.p0[index] : 1;
      E = detector.p2 ? detector.p2[index] : 0;
      if (detector.p2 && !israw)
        detector.p2[index] = (*mcestimate_error_p)(detector.p0[index],detector.p1[index],detector.p2[index]); /* set sigma */

      if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {
        /* fill-in 1D McCode array [x I E N] */
        this_p1[index*4]   = x;
        this_p1[index*4+1] = z;
        this_p1[index*4+2] = detector.p2 ? detector.p2[index] : 0;
        this_p1[index*4+3] = N;
      }

      if (isnan(z) || isnan(E) || isnan(N)) hasnaninf=hasnan=1;
      if (isinf(z) || isinf(E) || isinf(N)) hasnaninf=hasinf=1;

      /* compute stats integrals */
      if (!hasnaninf) {
        sum_xz += x*z;
        sum_yz += y*z;
        sum_x  += x;
        sum_y  += y;
        sum_z  += z;
        sum_x2z += x*x*z;
        sum_y2z += y*y*z;
        if (z > max_z) max_z = z;
        if (z < min_z) min_z = z;

        Nsum += N;
        P2sum += E;
      }

    }
  } /* for j */

  /* compute 1st and 2nd moments. For lists, sum_z=0 so this is skipped. */
  if (sum_z && detector.n*detector.m*detector.p)
  {
    fmon_x = sum_xz/sum_z;
    fmon_y = sum_yz/sum_z;
    smon_x = sum_x2z/sum_z-fmon_x*fmon_x; smon_x = smon_x > 0 ? sqrt(smon_x) : 0;
    smon_y = sum_y2z/sum_z-fmon_y*fmon_y; smon_y = smon_y > 0 ? sqrt(smon_y) : 0;
    mean_z = sum_z/detector.n/detector.m/detector.p;
  }
  /* store statistics into detector */
  detector.intensity = sum_z;
  detector.error     = Nsum ? (*mcestimate_error_p)(Nsum, sum_z, P2sum) : 0;
  detector.events    = Nsum;
  detector.min       = min_z;
  detector.max       = max_z;
  detector.mean      = mean_z;
  detector.centerX   = fmon_x;
  detector.halfwidthX= smon_x;
  detector.centerY   = fmon_y;
  detector.halfwidthY= smon_y;

  /* if McCode/PGPLOT and rank==1 replace p1 with new m*4 1D McCode and clear others */
  if (detector.rank == 1 && this_p1 && strcasestr(detector.format,"McCode")) {

    detector.p1 = this_p1;
    detector.n  = detector.m; detector.m  = 4;
    detector.p0 = detector.p2 = NULL;
    detector.istransposed = 1;
  }

  if (detector.n*detector.m*detector.p > 1)
    snprintf(detector.signal, CHAR_BUF_LENGTH,
      "Min=%g; Max=%g; Mean=%g;", detector.min, detector.max, detector.mean);
  else
    strcpy(detector.signal, "None");
  snprintf(detector.values, CHAR_BUF_LENGTH,
    "%g %g %g", detector.intensity, detector.error, detector.events);

  switch (detector.rank) {
    case 1:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g;",
      detector.centerX, detector.halfwidthX); break;
    case 2:
    case 3:  snprintf(detector.statistics, CHAR_BUF_LENGTH, "X0=%g; dX=%g; Y0=%g; dY=%g;",
      detector.centerX, detector.halfwidthX, detector.centerY, detector.halfwidthY);
      break;
    default: strcpy(detector.statistics, "None");
  }

  if (hasnan)
    printf("WARNING: Nan detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");
  if (hasinf)
    printf("WARNING: Inf detected in component/file %s %s\n",
      detector.component, strlen(detector.filename) ? detector.filename : "");

  return(detector);

} /* mcdetector_statistics */

/*******************************************************************************
* detector_import: build detector structure, merge non-lists from MPI
*                    compute basic stat, write "Detector:" line
* RETURN:            detector structure. Invalid data if detector.p1 == NULL
*                    Invalid detector sets m=0 and filename=""
*                    Simulation data  sets m=0 and filename=siminfo_name
* This function is equivalent to the old 'mcdetector_out', returning a structure
*******************************************************************************/
MCDETECTOR detector_import(
  char *format,
  char *component, char *title,
  long m, long n,  long p,
  char *xlabel, char *ylabel, char *zlabel,
  char *xvar, char *yvar, char *zvar,
  double x1, double x2, double y1, double y2, double z1, double z2,
  char *filename,
  double *p0, double *p1, double *p2,
  Coords position, Rotation rotation, int index)
{
  time_t t;       /* for detector.date */
  long   date_l;  /* date as a long number */
  char   istransposed=0;
  char   c[CHAR_BUF_LENGTH]; /* temp var for signal label */

  MCDETECTOR detector;

  /* build MCDETECTOR structure ============================================= */
  /* make sure we do not have NULL for char fields */

  /* these also apply to simfile */
  strncpy (detector.filename,  filename ? filename : "",        CHAR_BUF_LENGTH);
  strncpy (detector.format,    format   ? format   : "McCode" , CHAR_BUF_LENGTH);
  /* add extension if missing */
  if (strlen(detector.filename) && !strchr(detector.filename, '.'))
  { /* add extension if not in file name already */
    strcat(detector.filename, ".dat");
  }
  strncpy (detector.component, component ? component : MCCODE_STRING " component", CHAR_BUF_LENGTH);
  #ifdef USE_NEXUS
  char pref[5];
  if (index-1 < 10) {
    sprintf(pref,"000");
  } else if (index-1 < 100) {
    sprintf(pref,"00");
  } else if (index-1 < 1000) {
    sprintf(pref,"0");
  } else if (index-1 < 10000) {
    sprintf(pref,"");
  } else {
    fprintf(stderr,"Error, no support for > 10000 comps at the moment!\n");
    exit(-1);
  }
  sprintf(detector.nexuscomp,"%s%d_%s",pref,index-1,detector.component);
  #endif

  snprintf(detector.instrument, CHAR_BUF_LENGTH, "%s (%s)", instrument_name, instrument_source);
  snprintf(detector.user, CHAR_BUF_LENGTH,      "%s on %s",
        getenv("USER") ? getenv("USER") : MCCODE_NAME,
        getenv("HOST") ? getenv("HOST") : "localhost");
  time(&t);         /* get current write time */
  date_l = (long)t; /* same but as a long */
  snprintf(detector.date, CHAR_BUF_LENGTH, "%s", ctime(&t));
  if (strlen(detector.date))   detector.date[strlen(detector.date)-1] = '\0'; /* remove last \n in date */
  detector.date_l = date_l;

  if (!mcget_run_num() || mcget_run_num() >= mcget_ncount())
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%llu", mcget_ncount()
#ifdef USE_MPI
*mpi_node_count
#endif
  );
  else
    snprintf(detector.ncount, CHAR_BUF_LENGTH, "%g/%g", (double)mcget_run_num(), (double)mcget_ncount());

  detector.p0         = p0;
  detector.p1         = p1;
  detector.p2         = p2;

  /* handle transposition (not for NeXus) */
  if (!strcasestr(detector.format, "NeXus")) {
    if (m<0 || n<0 || p<0)             istransposed = !istransposed;
    if (strcasestr(detector.format, "transpose")) istransposed = !istransposed;
    if (istransposed) { /* do the swap once for all */
      long i=m; m=n; n=i;
    }
  }

  m=labs(m); n=labs(n); p=labs(p); /* make sure dimensions are positive */
  detector.istransposed = istransposed;

  /* determine detector rank (dimensionality) */
  if (!m || !n || !p || !p1) detector.rank = 4; /* invalid: exit with m=0 filename="" */
  else if (m*n*p == 1)       detector.rank = 0; /* 0D */
  else if (n == 1 || m == 1) detector.rank = 1; /* 1D */
  else if (p == 1)           detector.rank = 2; /* 2D */
  else                       detector.rank = 3; /* 3D */

  /* from rank, set type */
  switch (detector.rank) {
    case 0:  strcpy(detector.type,  "array_0d"); m=n=p=1; break;
    case 1:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_1d(%ld)", m*n*p); m *= n*p; n=p=1; break;
    case 2:  if(!strcasestr(detector.format,"list")) {
               snprintf(detector.type, CHAR_BUF_LENGTH, "array_2d(%ld, %ld)", m, n*p); n *= p; p=1;
             } else {
               snprintf(detector.type, CHAR_BUF_LENGTH, "list(%ld, %ld)", m, n*p); n *= p; p=1;
             } break;
    case 3:  snprintf(detector.type, CHAR_BUF_LENGTH, "array_3d(%ld, %ld, %ld)", m, n, p); break;
    default: m=0; strcpy(detector.type, ""); strcpy(detector.filename, "");/* invalid */
  }

  detector.m    = m;
  detector.n    = n;
  detector.p    = p;

  /* these only apply to detector files ===================================== */

  detector.Position[0]=position.x;
  detector.Position[1]=position.y;
  detector.Position[2]=position.z;
  rot_copy(detector.Rotation,rotation);
  snprintf(detector.position, CHAR_BUF_LENGTH, "%g %g %g", position.x, position.y, position.z);
  /* may also store actual detector orientation in the future */

  strncpy(detector.title,      title && strlen(title) ? title : component,       CHAR_BUF_LENGTH);
  strncpy(detector.xlabel,     xlabel && strlen(xlabel) ? xlabel : "X", CHAR_BUF_LENGTH); /* axis labels */
  strncpy(detector.ylabel,     ylabel && strlen(ylabel) ? ylabel : "Y", CHAR_BUF_LENGTH);
  strncpy(detector.zlabel,     zlabel && strlen(zlabel) ? zlabel : "Z", CHAR_BUF_LENGTH);
  strncpy(detector.xvar,       xvar && strlen(xvar) ? xvar :       "x", CHAR_BUF_LENGTH); /* axis variables */
  strncpy(detector.yvar,       yvar && strlen(yvar) ? yvar :       detector.xvar, CHAR_BUF_LENGTH);
  strncpy(detector.zvar,       zvar && strlen(zvar) ? zvar :       detector.yvar, CHAR_BUF_LENGTH);

  /* set "variables" as e.g. "I I_err N" */
  strcpy(c, "I ");
  if (strlen(detector.zvar))      strncpy(c, detector.zvar,32);
  else if (strlen(detector.yvar)) strncpy(c, detector.yvar,32);
  else if (strlen(detector.xvar)) strncpy(c, detector.xvar,32);

  if (detector.rank == 1)
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s %s_err N", detector.xvar, c, c);
  else
    snprintf(detector.variables, CHAR_BUF_LENGTH, "%s %s_err N", c, c);

  /* limits */
  detector.xmin = x1;
  detector.xmax = x2;
  detector.ymin = y1;
  detector.ymax = y2;
  detector.zmin = z1;
  detector.zmax = z2;
  if (abs(detector.rank) == 1)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g", x1, x2);
  else if (detector.rank == 2)
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g", x1, x2, y1, y2);
  else
    snprintf(detector.limits, CHAR_BUF_LENGTH, "%g %g %g %g %g %g", x1, x2, y1, y2, z1, z2);

  /* if MPI and nodes_nb > 1: reduce data sets when using MPI =============== */
#ifdef USE_MPI
  if (!strcasestr(detector.format,"list") && mpi_node_count > 1 && m) {
    /* we save additive data: reduce everything into mpi_node_root */
    if (p0) mc_MPI_Sum(p0, m*n*p);
    if (p1) mc_MPI_Sum(p1, m*n*p);
    if (p2) mc_MPI_Sum(p2, m*n*p);
    if (!p0) {  /* additive signal must be then divided by the number of nodes */
      int i;
      for (i=0; i<m*n*p; i++) {
        p1[i] /= mpi_node_count;
        if (p2) p2[i] /= mpi_node_count;
      }
    }
  }
#endif /* USE_MPI */

  /* compute statistics, Nsum, intensity, Error bars */
  detector = mcdetector_statistics(detector);

#ifdef USE_MPI
  /* slaves are done */
  if(mpi_node_rank != mpi_node_root) {
    return detector;
  }
#endif

  /* output "Detector:" line ================================================ */
  /* when this is a detector written by a component (not the SAVE from instrument),
     not an event lists */
  if (!m) return(detector);
  if (!strcasestr(detector.format,"list")) {
    if (!strcmp(detector.component, instrument_name)) {
      if (strlen(detector.filename))  /* we name it from its filename, or from its title */
        strncpy(c, detector.filename, CHAR_BUF_LENGTH);
      else
        snprintf(c, CHAR_BUF_LENGTH, "%s", instrument_name);
    } else
      strncpy(c, detector.component, CHAR_BUF_LENGTH);  /* usual detectors written by components */

    printf("Detector: %s_I=%g %s_ERR=%g %s_N=%g",
           c, detector.intensity,
           c, detector.error,
           c, detector.events);
    printf(" \"%s\"\n", strlen(detector.filename) ? detector.filename : detector.component);
  }


  return(detector);
} /* detector_import */

/* end MCDETECTOR import section ============================================ */

















/* ========================================================================== */

/*                               ASCII output                                 */
/*     The SIM file is YAML based, the data files have '#' headers            */

/* ========================================================================== */


/*******************************************************************************
* mcinfo_out: output instrument tags/info (only in SIM)
* Used in: siminfo_init (ascii), mcinfo(stdout)
*******************************************************************************/
static void mcinfo_out(char *pre, FILE *f)
{
  char Parameters[CHAR_BUF_LENGTH] = "";
  int  i;

  if (!f || mcdisable_output_files) return;

  /* create parameter string ================================================ */
  for(i = 0; i < numipar; i++)
  {
    char ThisParam[CHAR_BUF_LENGTH];
    if (strlen(mcinputtable[i].name) > CHAR_BUF_LENGTH) break;
    snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
            (*mcinputtypes[mcinputtable[i].type].parminfo)
                (mcinputtable[i].name));
    if (strlen(Parameters) + strlen(ThisParam) + 1 >= CHAR_BUF_LENGTH) break;
    strcat(Parameters, ThisParam);
  }

  /* output data ============================================================ */
  if (f != stdout)
    fprintf(f, "%sFile: %s%c%s\n",    pre, dirname, MC_PATHSEP_C, siminfo_name);
  else
    fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);

  fprintf(f, "%sSource: %s\n",   pre, instrument_source);
  fprintf(f, "%sParameters: %s\n",    pre, Parameters);

  fprintf(f, "%sTrace_enabled: %s\n", pre, traceenabled ? "yes" : "no");
  fprintf(f, "%sDefault_main: %s\n",  pre, defaultmain ?  "yes" : "no");
#ifdef MC_EMBEDDED_RUNTIME
  fprintf(f, "%sEmbedded_runtime: %s\n", pre, "yes");
#else
  fprintf(f, "%sEmbedded_runtime: %s\n", pre, "no");
#endif

  fflush(f);
} /* mcinfo_out */

/*******************************************************************************
* mcruninfo_out: output simulation tags/info (both in SIM and data files)
* Used in: siminfo_init (ascii case), mcdetector_out_xD_ascii
*******************************************************************************/
static void mcruninfo_out(char *pre, FILE *f)
{
  int i;
  char Parameters[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  fprintf(f, "%sFormat: %s%s\n",      pre,
    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME,
    mcformat && strcasestr(mcformat,"McCode") ? " with text headers" : "");
  fprintf(f, "%sURL: %s\n",         pre, "http://www.mccode.org");
  fprintf(f, "%sCreator: %s\n",     pre, MCCODE_STRING);
  fprintf(f, "%sInstrument: %s\n", pre, instrument_source);
  fprintf(f, "%sNcount: %llu\n",        pre, mcget_ncount());
  fprintf(f, "%sTrace: %s\n",       pre, mcdotrace ? "yes" : "no");
  fprintf(f, "%sGravitation: %s\n", pre, mcgravitation ? "yes" : "no");
  snprintf(Parameters, CHAR_BUF_LENGTH, "%ld", mcseed);
  fprintf(f, "%sSeed: %s\n",        pre, Parameters);
  fprintf(f, "%sDirectory: %s\n",        pre, dirname ? dirname : ".");
#ifdef USE_MPI
  if (mpi_node_count > 1)
    fprintf(f, "%sNodes: %i\n",        pre, mpi_node_count);
#endif

  // TODO Consider replacing this by a a call to `mcparameterinfo_out(pre+"Param: ", f)`
  /* output parameter string ================================================ */
  for(i = 0; i < numipar; i++) {
      if (mcinputtable[i].par){
	/* Parameters with a default value */
	if(mcinputtable[i].val && strlen(mcinputtable[i].val)){
	  (*mcinputtypes[mcinputtable[i].type].printer)(Parameters, mcinputtable[i].par);
	  fprintf(f, "%sParam: %s=%s\n", pre, mcinputtable[i].name, Parameters);
        /* ... and those without */
	}else{
	  fprintf(f, "%sParam: %s=NULL\n", pre, mcinputtable[i].name);
	}
      }
  }
  fflush(f);
} /* mcruninfo_out */

/*******************************************************************************
 * @brief Print parameter information to the specified file
 * @param pre any beginning-of-line padding
 * @param f the output file
 */
static void mcparameterinfo_out(char * pre, FILE *f){
  if (!f || mcdisable_output_files) return;

  unsigned int nchar = 4;
  for (int i=0; i < numipar; ++i){
    if (mcinputtable[i].par && mcinputtable[i].val && strlen(mcinputtable[i].val) > nchar)
      nchar = strlen(mcinputtable[i].val);
  }
  char * buffer = calloc(nchar+1, sizeof(char));

  if (!buffer) {
    exit(1);
  }

  for (int i=0; i < numipar; ++i) {
    if (mcinputtable[i].par) {
      char * name = mcinputtable[i].name;
      if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
        mcinputtypes[mcinputtable[i].type].printer(buffer, mcinputtable[i].par);
      } else {
        strcpy(buffer, "NULL");
      }
      if (strlen(mcinputtable[i].unit)){
        //fprintf(f, "%s%s %s (\"%s\") = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
        fprintf(f, "%s%s %s/\"%s\" = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, mcinputtable[i].unit, buffer);
      } else {
        fprintf(f, "%s%s %s = %s\n", pre, mcinputtypes[mcinputtable[i].type].parminfo(name), name, buffer);
      }
    }
  }

  free(buffer);
}

/*******************************************************************************
* siminfo_out:    wrapper to fprintf(siminfo_file)
*******************************************************************************/
void siminfo_out(char *format, ...)
{
  va_list ap;

  if(siminfo_file && !mcdisable_output_files)
  {
    va_start(ap, format);
    vfprintf(siminfo_file, format, ap);
    va_end(ap);
  }
} /* siminfo_out */


/*******************************************************************************
* mcdatainfo_out: output detector header
*   mcdatainfo_out(prefix, file_handle, detector) writes info to data file
*******************************************************************************/
static void
mcdatainfo_out(char *pre, FILE *f, MCDETECTOR detector)
{
  if (!f || !detector.m || mcdisable_output_files) return;

  /* output data ============================================================ */
  fprintf(f, "%sDate: %s (%li)\n",       pre, detector.date, detector.date_l);
  fprintf(f, "%stype: %s\n",       pre, detector.type);
  fprintf(f, "%sSource: %s\n",     pre, detector.instrument);
  fprintf(f, "%scomponent: %s\n",  pre, detector.component);
  fprintf(f, "%sposition: %s\n",   pre, detector.position);

  fprintf(f, "%stitle: %s\n",      pre, detector.title);
  fprintf(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
             "%sNcount: %s\n" :
             "%sratio: %s\n",  pre, detector.ncount);

  if (strlen(detector.filename)) {
    fprintf(f, "%sfilename: %s\n", pre, detector.filename);
  }

  fprintf(f, "%sstatistics: %s\n", pre, detector.statistics);
  fprintf(f, "%ssignal: %s\n",     pre, detector.signal);
  fprintf(f, "%svalues: %s\n",     pre, detector.values);

  if (detector.rank >= 1)
  {
    fprintf(f, "%sxvar: %s\n",     pre, detector.xvar);
    fprintf(f, "%syvar: %s\n",     pre, detector.yvar);
    fprintf(f, "%sxlabel: %s\n",   pre, detector.xlabel);
    fprintf(f, "%sylabel: %s\n",   pre, detector.ylabel);
    if (detector.rank > 1) {
      fprintf(f, "%szvar: %s\n",   pre, detector.zvar);
      fprintf(f, "%szlabel: %s\n", pre, detector.zlabel);
    }
  }

  fprintf(f,
    abs(detector.rank)==1 ?
             "%sxlimits: %s\n" :
             "%sxylimits: %s\n", pre, detector.limits);
  fprintf(f, "%svariables: %s\n", pre,
    strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

  fflush(f);

} /* mcdatainfo_out */

/* mcdetector_out_array_ascii: output a single array to a file
 *   m: columns
 *   n: rows
 *   p: array
 *   f: file handle (already opened)
 */
static void mcdetector_out_array_ascii(long m, long n, double *p, FILE *f, char istransposed)
{
  if(f)
  {
    int i,j;
    for(j = 0; j < n; j++)
    {
      for(i = 0; i < m; i++)
      {
          fprintf(f, "%.10g ", p[!istransposed ? i*n + j : j*m+i]);
      }
      fprintf(f,"\n");
    }
  }
} /* mcdetector_out_array_ascii */

/*******************************************************************************
* mcdetector_out_0D_ascii: called by mcdetector_out_0D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_0D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  /* Write data set information to simulation description file. */
  MPI_MASTER(
    siminfo_out("\nbegin data\n"); // detector.component
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.component, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* write I I_err N */
      fprintf(outfile, "%g %g %g\n",
        detector.intensity, detector.error, detector.events);
      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);
} /* mcdetector_out_0D_ascii */

/*******************************************************************************
* mcdetector_out_1D_ascii: called by mcdetector_out_1D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_1D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Write data set information to simulation description file. */
    siminfo_out("\nbegin data\n"); // detector.filename
    mcdatainfo_out("  ", siminfo_file, detector);
    siminfo_out("end data\n");
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write data file header and entry in simulation description file */
      mcruninfo_out( "# ", outfile);
      mcdatainfo_out("# ", outfile, detector);
      /* output the 1D array columns */
      mcdetector_out_array_ascii(detector.m, detector.n, detector.p1, outfile, detector.istransposed);

      fclose(outfile);
    }
  ); /* MPI_MASTER */
  return(detector);

}  /* mcdetector_out_1D_ascii */

/*******************************************************************************
* mcdetector_out_2D_ascii: called by mcdetector_out_2D for ascii output
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_ascii(MCDETECTOR detector)
{
  int exists=0;
  FILE *outfile = NULL;

  MPI_MASTER(
    /* Loop over array elements, writing to file. */
    /* Don't write if filename is NULL: mcnew_file handles this (return NULL) */
    outfile = mcnew_file(detector.filename, "dat", &exists);
    if(outfile)
    {
      /* write header only if file has just been created (not appending) */
      if (!exists) {
        /* Write data set information to simulation description file. */
        siminfo_out("\nbegin data\n"); // detector.filename
        mcdatainfo_out("  ", siminfo_file, detector);
        siminfo_out("end data\n");

        mcruninfo_out( "# ", outfile);
        mcdatainfo_out("# ", outfile,   detector);
      }
      /* Add # Data entry for any write to the file (e.g. via -USR2, see GitHub issue #2174 ) */
      fprintf(outfile, "# Data [%s/%s] %s:\n", detector.component, detector.filename, detector.zvar);
      mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
        outfile, detector.istransposed);
      if (detector.p2) {
        fprintf(outfile, "# Errors [%s/%s] %s_err:\n", detector.component, detector.filename, detector.zvar);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p2,
          outfile, detector.istransposed);
      }
      if (detector.p0) {
        fprintf(outfile, "# Events [%s/%s] N:\n", detector.component, detector.filename);
        mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p0,
          outfile, detector.istransposed);
      }
      fclose(outfile);

      if (!exists) {
        if (strcasestr(detector.format, "list"))
          printf("Events:   \"%s\"\n",
            strlen(detector.filename) ? detector.filename : detector.component);
      }
    } /* if outfile */
  ); /* MPI_MASTER */
#ifdef USE_MPI
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    int node_i=0;
    /* loop along MPI nodes to write sequentially */
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      /* MPI: slaves wait for the master to write its block, then append theirs */
      MPI_Barrier(MPI_COMM_WORLD);
      if (node_i != mpi_node_root && node_i == mpi_node_rank) {
        if(strlen(detector.filename) && !mcdisable_output_files)	/* Don't write if filename is NULL */
          outfile = mcnew_file(detector.filename, "dat", &exists);
        if (!exists)
          fprintf(stderr, "Warning: [MPI node %i] file '%s' does not exist yet, "
                          "MASTER should have opened it before.\n",
            mpi_node_rank, detector.filename);
        if(outfile) {
          mcdetector_out_array_ascii(detector.m, detector.n*detector.p, detector.p1,
            outfile, detector.istransposed);
          fclose(outfile);
        }
      }
    }
  } /* if strcasestr list */
#endif
  return(detector);
} /* mcdetector_out_2D_ascii */

/*******************************************************************************
* strcpy_valid: makes a valid string for variable names.
*   copy 'original' into 'valid', replacing invalid characters by '_'
*   char arrays must be pre-allocated
*******************************************************************************/
static char *strcpy_valid(char *valid, char *original)
{
  long i;
  int  n=CHAR_BUF_LENGTH; /* max length of valid names */

  if (original == NULL || !strlen(original)) return(NULL);

  if (n > strlen(original)) n = strlen(original);
  else original += strlen(original)-n;
  strncpy(valid, original, n);

  for (i=0; i < n; i++)
  {
    if ( (valid[i] > 122)
      || (valid[i] < 32)
      || (strchr("!\"#$%&'()*+,-.:;<=>?@[\\]^`/ \n\r\t", valid[i]) != NULL) )
    {
      if (i) valid[i] = '_'; else valid[i] = 'm';
    }
  }
  valid[i] = '\0';

  return(valid);
} /* strcpy_valid */

/* end ascii output section ================================================= */







#ifdef USE_NEXUS

/* ========================================================================== */

/*                               NeXus output                                 */

/* ========================================================================== */

#define nxprintf(...)    nxstr('d', __VA_ARGS__)
#define nxprintattr(...) nxstr('a', __VA_ARGS__)

/*******************************************************************************
* nxstr: output a tag=value data set (char) in NeXus/current group
*   when 'format' is larger that 1024 chars it is used as value for the 'tag'
*   else the value is assembled with format and following arguments.
*   type='d' -> data set
*        'a' -> attribute for current data set
*******************************************************************************/
static int nxstr(char type, NXhandle *f, char *tag, char *format, ...)
{
  va_list ap;
  char value[CHAR_BUF_LENGTH];
  int  i;
  int  ret=NX_OK;

  if (!tag || !format || !strlen(tag) || !strlen(format)) return(NX_OK);

  /* assemble the value string */
  if (strlen(format) < CHAR_BUF_LENGTH) {
    va_start(ap, format);
    ret = vsnprintf(value, CHAR_BUF_LENGTH, format, ap);
    va_end(ap);

    i = strlen(value);
  } else {
    i = strlen(format);
  }

  if (type == 'd') {
    /* open/put/close data set */
    if (NXmakedata (f, tag, NX_CHAR, 1, &i) != NX_OK) return(NX_ERROR);
    NXopendata (f, tag);
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputdata  (f, value);
    else
      ret = NXputdata  (f, format);
    NXclosedata(f);
  } else {
    if (strlen(format) < CHAR_BUF_LENGTH)
      ret = NXputattr  (f, tag, value, strlen(value), NX_CHAR);
    else
      ret = NXputattr  (f, tag, format, strlen(format), NX_CHAR);
  }

  return(ret);

} /* nxstr */

/*******************************************************************************
* mcinfo_readfile: read a full file into a string buffer which is allocated
*   Think to free the buffer after use.
* Used in: mcinfo_out_nexus (nexus)
*******************************************************************************/
char *mcinfo_readfile(char *filename)
{
  FILE *f = fopen(filename, "rb");
  if (!f) return(NULL);
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  rewind(f);
  char *string = malloc(fsize + 1);
  if (string) {
    int n = fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;
  }
  return(string);
}

/*******************************************************************************
* mcinfo_out: output instrument/simulation groups in NeXus file
* Used in: siminfo_init (nexus)
*******************************************************************************/
static void mcinfo_out_nexus(NXhandle f)
{
  FILE  *fid;     /* for intrument source code/C/IDF */
  char  *buffer=NULL;
  time_t t     =time(NULL); /* for date */
  char   entry0[CHAR_BUF_LENGTH];
  int    count=0;
  char   name[CHAR_BUF_LENGTH];
  char   class[CHAR_BUF_LENGTH];

  if (!f || mcdisable_output_files) return;

  /* write NeXus NXroot attributes */
  /* automatically added: file_name, HDF5_Version, file_time, NeXus_version */
  nxprintattr(f, "creator",   "%s generated with " MCCODE_STRING, instrument_name);

  /* count the number of existing NXentry and create the next one */
  NXgetgroupinfo(f, &count, name, class);
  sprintf(entry0, "entry%i", count+1);

  /* create the main NXentry (mandatory in NeXus) */
  if (NXmakegroup(f, entry0, "NXentry") == NX_OK)
  if (NXopengroup(f, entry0, "NXentry") == NX_OK) {
    nxprintf(nxhandle, "program_name", MCCODE_STRING);
    nxprintf(f, "start_time", ctime(&t));
    nxprintf(f, "title", "%s%s%s simulation generated by instrument %s",
      dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name,
      instrument_name);
    nxprintattr(f, "program_name", MCCODE_STRING);
    nxprintattr(f, "instrument",   instrument_name);
    nxprintattr(f, "simulation",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

    /* write NeXus instrument group */
    if (NXmakegroup(f, "instrument", "NXinstrument") == NX_OK)
    if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
      int   i;
      char *string=NULL;

      /* write NeXus parameters(types) data =================================== */
      string = (char*)malloc(CHAR_BUF_LENGTH);
      if (string) {
        strcpy(string, "");
        for(i = 0; i < numipar; i++)
        {
          char ThisParam[CHAR_BUF_LENGTH];
          snprintf(ThisParam, CHAR_BUF_LENGTH, " %s(%s)", mcinputtable[i].name,
                  (*mcinputtypes[mcinputtable[i].type].parminfo)
                      (mcinputtable[i].name));
          if (strlen(string) + strlen(ThisParam) < CHAR_BUF_LENGTH)
            strcat(string, ThisParam);
        }
        nxprintattr(f, "Parameters",    string);
        free(string);
      }

      nxprintattr(f, "name",          instrument_name);
      nxprintf   (f, "name",          instrument_name);
      nxprintattr(f, "Source",        instrument_source);

      nxprintattr(f, "Trace_enabled", traceenabled ? "yes" : "no");
      nxprintattr(f, "Default_main",  defaultmain ?  "yes" : "no");
#ifdef MC_EMBEDDED_RUNTIME
      nxprintattr(f, "Embedded_runtime", "yes");
#else
      nxprintattr(f, "Embedded_runtime", "no");
#endif

      /* add instrument source code when available */
      buffer = mcinfo_readfile(instrument_source);
      if (buffer && strlen(buffer)) {
        long length=strlen(buffer);
        nxprintf (f, "description", buffer);
        NXopendata(f,"description");
        nxprintattr(f, "file_name", instrument_source);
        nxprintattr(f, "file_size", "%li", length);
        nxprintattr(f, "MCCODE_STRING", MCCODE_STRING);
        NXclosedata(f);
        nxprintf (f,"instrument_source", "%s " MCCODE_NAME " " MCCODE_PARTICLE " Monte Carlo simulation", instrument_name);
        free(buffer);
      } else
        nxprintf (f, "description", "File %s not found (instrument description %s is missing)",
          instrument_source, instrument_name);

      if (mcnexus_embed_idf) {
        /* add Mantid/IDF.xml when available */
        char *IDFfile=NULL;
        IDFfile = (char*)malloc(CHAR_BUF_LENGTH);
        sprintf(IDFfile,"%s%s",instrument_source,".xml");
        buffer = mcinfo_readfile(IDFfile);
        if (buffer && strlen(buffer)) {
          NXmakegroup (nxhandle, "instrument_xml", "NXnote");
          NXopengroup (nxhandle, "instrument_xml", "NXnote");
          nxprintf(f, "data", buffer);
          nxprintf(f, "description", "IDF.xml file found with instrument %s", instrument_source);
          nxprintf(f, "type", "text/xml");
          NXclosegroup(f); /* instrument_xml */
          free(buffer);
        }
        free(IDFfile);
      }

      /* Add "components" entry */
      if (NXmakegroup(f, "components", "NXdata") == NX_OK) {
        NXopengroup(f, "components", "NXdata");
        nxprintattr(f, "description", "Component list for instrument %s",  instrument_name);
	NXclosegroup(f); /* components */
      } else {
	printf("Failed to create NeXus component hierarchy\n");
      }
      NXclosegroup(f); /* instrument */
    } /* NXinstrument */

    /* write NeXus simulation group */
    if (NXmakegroup(f, "simulation", "NXnote") == NX_OK)
    if (NXopengroup(f, "simulation", "NXnote") == NX_OK) {

      nxprintattr(f, "name",   "%s%s%s",
        dirname && strlen(dirname) ? dirname : ".", MC_PATHSEP_S, siminfo_name);

      nxprintf   (f, "name",      "%s",     siminfo_name);
      nxprintattr(f, "Format",    mcformat && strlen(mcformat) ? mcformat : MCCODE_NAME);
      nxprintattr(f, "URL",       "http://www.mccode.org");
      nxprintattr(f, "program",   MCCODE_STRING);
      nxprintattr(f, "Instrument",instrument_source);
      nxprintattr(f, "Trace",     mcdotrace ?     "yes" : "no");
      nxprintattr(f, "Gravitation",mcgravitation ? "yes" : "no");
      nxprintattr(f, "Seed",      "%li", mcseed);
      nxprintattr(f, "Directory", dirname);
    #ifdef USE_MPI
      if (mpi_node_count > 1)
        nxprintf(f, "Nodes", "%i",        mpi_node_count);
    #endif

      /* output parameter string ================================================ */
      if (NXmakegroup(f, "Param", "NXparameters") == NX_OK) {
	NXopengroup(f,"Param", "NXparameters");
        int i;
        char string[CHAR_BUF_LENGTH];
        for(i = 0; i < numipar; i++) {
          if (mcget_run_num() || (mcinputtable[i].val && strlen(mcinputtable[i].val))) {
            if (mcinputtable[i].par == NULL)
              strncpy(string, (mcinputtable[i].val ? mcinputtable[i].val : ""), CHAR_BUF_LENGTH);
            else
              (*mcinputtypes[mcinputtable[i].type].printer)(string, mcinputtable[i].par);

            nxprintf(f,  mcinputtable[i].name, "%s", string);
            nxprintattr(f, mcinputtable[i].name, string);
          }
        }
        NXclosegroup(f); /* Param */
      } /* NXparameters */
      NXclosegroup(f); /* simulation */
    } /* NXsimulation */

    /* create a group to hold all links for all monitors */
    NXmakegroup(f, "data", "NXdetector");

    /* leave the NXentry opened (closed at exit) */
  } /* NXentry */
} /* mcinfo_out_nexus */

/*******************************************************************************
* mccomp_placement_type_nexus:
*   Places
*    - absolute (3x1) position
*    - absolute (3x3) rotation
*    - type / class of component instance into attributes under
*     entry<N>/instrument/compname
*   requires: NXentry to be opened
*******************************************************************************/
static void mccomp_placement_type_nexus(NXhandle nxhandle, char* component, Coords position, Rotation rotation, char* comptype)
{
  /* open NeXus instrument group */

  #ifdef USE_NEXUS
  if(nxhandle) {
    if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
      if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	if (NXmakegroup(nxhandle, component, "NXdata") == NX_OK) {
	  if (NXopengroup(nxhandle, component, "NXdata") == NX_OK) {
	    int64_t pdims[3]; pdims[0]=3; pdims[1]=0; pdims[2]=0;
	    if (NXcompmakedata64(nxhandle, "Position", NX_FLOAT64, 1, pdims, NX_COMPRESSION, pdims) == NX_OK) {
	      if (NXopendata(nxhandle, "Position") == NX_OK) {
		double pos[3]; coords_get(position, &pos[0], &pos[1], &pos[2]);
		if (NXputdata (nxhandle, pos) == NX_OK) {
		  NXclosedata(nxhandle);
		} else {
		  fprintf(stderr, "COULD NOT PUT Position field for component %s\n",component);
		}
	      } else {
		fprintf(stderr, "Warning: could not open Position field for component %s\n",component);
	      }
	    }
	    int64_t rdims[3]; rdims[0]=3; rdims[1]=3; rdims[2]=0;
	    if (NXcompmakedata64(nxhandle, "Rotation", NX_FLOAT64, 2, rdims, NX_COMPRESSION, rdims) == NX_OK) {
	      if (NXopendata(nxhandle, "Rotation") == NX_OK) {
		if (NXputdata (nxhandle, rotation) == NX_OK) {
		  NXclosedata(nxhandle);
		} else {
		  fprintf(stderr, "COULD NOT PUT Rotation field for component %s\n",component);
		}
	      } else {
		fprintf(stderr, "Warning: could not open Rotation field for component %s\n",component);
	      }
	    }
	    nxprintf(nxhandle, "Component_type", comptype);
	    NXclosegroup(nxhandle); // component
	  } else {
	    printf("FAILED to open comp data group %s\n",component);
	  }
	} else {
	  printf("FAILED to create comp data group %s\n",component);
	}
	NXclosegroup(nxhandle); // components
      } else {
	printf("Failed to open NeXus component hierarchy\n");
      }
      NXclosegroup(nxhandle); // instrument
    } else {
      printf("Failed to open NeXus instrument hierarchy\n");
    }
  } else {
    fprintf(stderr,"NO NEXUS FILE\n");
  }
  #endif
} /* mccomp_placement_nexus */

/*******************************************************************************
* mccomp_param_nexus:
*   Output parameter/value pair for component instance into
*   the attribute
*     entry<N>/instrument/compname/parameter
*   requires: NXentry to be opened
*******************************************************************************/
static void mccomp_param_nexus(NXhandle nxhandle, char* component, char* parameter, char* defval, char* value, char* type)
{
  /* open NeXus instrument group */

  #ifdef USE_NEXUS
  if(nxhandle) {
    if (NXopengroup(nxhandle, "instrument", "NXinstrument") == NX_OK) {
      if (NXopengroup(nxhandle, "components", "NXdata") == NX_OK) {
	if (NXopengroup(nxhandle, component, "NXdata") == NX_OK) {
	  NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
	  NXmakegroup(nxhandle, "parameters", "NXdata");
	  NXMEnableErrorReporting();  /* re-enable NeXus error messages */
	  if (NXopengroup(nxhandle, "parameters", "NXdata") == NX_OK) {
	    NXmakegroup(nxhandle, parameter, "NXnote");
	    if (NXopengroup(nxhandle, parameter, "NXnote") == NX_OK) {
	      nxprintattr(nxhandle, "type", type);
	      nxprintattr(nxhandle, "default",  defval);
	      nxprintattr(nxhandle, "value",  value);
	      NXclosegroup(nxhandle); // parameter
	    } else {
	      printf("FAILED to open parameters %s data group \n",parameter);
	    }
	    NXclosegroup(nxhandle); // "parameters"
	  } else {
	    printf("FAILED to open comp/parameters data group \n");
	  }
	  NXclosegroup(nxhandle); // component
	  } else {
	  printf("FAILED to open comp data group %s\n",component);
	}
	NXclosegroup(nxhandle); // components
      } else {
	printf("Failed to open NeXus component hierarchy\n");
      }
      NXclosegroup(nxhandle); // instrument
    } else {
      printf("Failed to open NeXus instrument hierarchy\n");
    }
  } else {
    fprintf(stderr,"NO NEXUS FILE\n");
  }
#endif
} /* mccomp_param_nexus */

/*******************************************************************************
* mcdatainfo_out_nexus: output detector header
*   mcdatainfo_out_nexus(detector) create group and write info to NeXus data file
*   open data:NXdetector then filename:NXdata and write headers/attributes
*   requires: NXentry to be opened
*******************************************************************************/
static void
mcdatainfo_out_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];
  if (!f || !detector.m || mcdisable_output_files) return;

  strcpy_valid(data_name,
    strlen(detector.filename) ?
      detector.filename : detector.component);

  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
    if (NXopengroup(f, "components", "NXdata") == NX_OK) {
      NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
      NXmakegroup(f, detector.nexuscomp, "NXdata");
      if (NXopengroup(f, detector.nexuscomp, "NXdata") == NX_OK) {
	NXmakegroup(f, "output", "NXdetector");
	if (NXopengroup(f, "output", "NXdetector") == NX_OK) {
	  if (NXmakegroup(f, data_name, "NXdata") == NX_OK) {
	    if (NXopengroup(f, data_name, "NXdata") == NX_OK) {
	      /* output metadata (as attributes) ======================================== */
	      nxprintattr(f, "Date",       detector.date);
	      nxprintattr(f, "type",       detector.type);
	      nxprintattr(f, "Source",     detector.instrument);
	      nxprintattr(f, "component",  detector.component);
	      nxprintattr(f, "position",   detector.position);

	      nxprintattr(f, "title",      detector.title);
	      nxprintattr(f, !mcget_run_num() || mcget_run_num() >= mcget_ncount() ?
			  "Ncount" :
			  "ratio",  detector.ncount);

	      if (strlen(detector.filename)) {
		nxprintattr(f, "filename", detector.filename);
	      }

	      nxprintattr(f, "statistics", detector.statistics);
	      nxprintattr(f, "signal",     detector.signal);
	      nxprintattr(f, "values",     detector.values);

	      if (detector.rank >= 1)
		{
		  nxprintattr(f, "xvar",     detector.xvar);
		  nxprintattr(f, "yvar",     detector.yvar);
		  nxprintattr(f, "xlabel",   detector.xlabel);
		  nxprintattr(f, "ylabel",   detector.ylabel);
		  if (detector.rank > 1) {
		    nxprintattr(f, "zvar",   detector.zvar);
		    nxprintattr(f, "zlabel", detector.zlabel);
		  }
		}

	      nxprintattr(f, abs(detector.rank)==1 ?
			  "xlimits" :
			  "xylimits", detector.limits);
	      nxprintattr(f, "variables",
			  strcasestr(detector.format, "list") ? detector.ylabel : detector.variables);

	      NXclosegroup(f); // data_name
	    }
	  }
	}
	NXclosegroup(f); // output
	NXclosegroup(f); // detector.nexuscomp
      }
      NXclosegroup(f); // components
    }
    NXMEnableErrorReporting();  /* re-enable NeXus error messages */
    NXclosegroup(f); // instrument
  } /* NXdetector (instrument) */ 
} /* mcdatainfo_out_nexus */

/*******************************************************************************
* mcdetector_out_axis_nexus: write detector axis into current NXdata
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_axis_nexus(NXhandle f, char *label, char *var, int rank, long length, double min, double max)
{
  if (!f || length <= 1 || mcdisable_output_files || max == min) return(NX_OK);
  else {
    double *axis;
    axis=malloc(sizeof(double)*length);
    if (!axis ) {
      printf("Fatal memory error allocating NeXus axis of length %li, exiting!\n", length);
      return(NX_ERROR);
    }
    char *valid;
    valid=malloc(sizeof(char)*CHAR_BUF_LENGTH);
    if (!valid ) {
      printf("Fatal memory error allocating label axis of length %i, exiting!\n", CHAR_BUF_LENGTH);
      free(axis);
      return(NX_ERROR);
    }
    int dim=(int)length;
    int i;
    int nprimary=1;
    /* create an axis from [min:max] */
    for(i = 0; i < length; i++)
      axis[i] = min+(max-min)*(i+0.5)/length;
    /* create the data set */
    strcpy_valid(valid, label);
    NXcompmakedata(f, valid, NX_FLOAT64, 1, &dim, NX_COMPRESSION, &dim);
    /* open it */
    if (NXopendata(f, valid) != NX_OK) {
      fprintf(stderr, "Warning: could not open axis rank %i '%s' (NeXus)\n",
        rank, valid);
      free(axis);
      free(valid);
      return(NX_ERROR);
    }
    /* put the axis and its attributes */
    NXputdata  (f, axis);
    nxprintattr(f, "long_name",  label);
    nxprintattr(f, "short_name", var);
    NXputattr  (f, "axis",       &rank,     1, NX_INT32);
    nxprintattr(f, "units",      var);
    NXputattr  (f, "primary",    &nprimary, 1, NX_INT32);
    NXclosedata(f);
    free(axis);
    free(valid);
    return(NX_OK);
  }
} /* mcdetector_out_axis_nexus */

/*******************************************************************************
* mcdetector_out_array_nexus: write detector array into current NXdata (1D,2D)
*   requires: NXdata to be opened
*******************************************************************************/
int mcdetector_out_array_nexus(NXhandle f, char *part, double *data, MCDETECTOR detector)
{

  int64_t dims[3]={detector.m,detector.n,detector.p};  /* number of elements to write */
  int64_t fulldims[3]={detector.m,detector.n,detector.p};
  int signal=1;
  int exists=0;
  int64_t current_dims[3]={0,0,0};
  int ret=NX_OK;

  if (!f || !data || !detector.m || mcdisable_output_files) return(NX_OK);

  /* when this is a list, we set 1st dimension to NX_UNLIMITED for creation */
  if (strcasestr(detector.format, "list")) fulldims[0] = NX_UNLIMITED;

  /* create the data set in NXdata group */
  NXMDisableErrorReporting(); /* inactivate NeXus error messages, as creation may fail */
  ret = NXcompmakedata64(f, part, NX_FLOAT64, detector.rank, fulldims, NX_COMPRESSION, dims);
  if (ret != NX_OK) {
    /* failed: data set already exists */
    int datatype=0;
    int rank=0;
    exists=1;
    /* inquire current size of data set (nb of events stored) */
    NXopendata(f, part);
    NXgetinfo64(f, &rank, current_dims, &datatype);
    NXclosedata(f);
  }
  NXMEnableErrorReporting();  /* re-enable NeXus error messages */

  /* open the data set */
  if (NXopendata(f, part) == NX_ERROR) {
    fprintf(stderr, "Warning: could not open DataSet %s '%s' (NeXus)\n",
      part, detector.title);
    return(NX_ERROR);
  }
  if (strcasestr(detector.format, "list")) {
    current_dims[1] = current_dims[2] = 0; /* set starting location for writing slab */
    NXputslab64(f, data, current_dims, dims);
    if (!exists)
      printf("Events:   \"%s\"\n",
        strlen(detector.filename) ? detector.filename : detector.component);
    else
      printf("Append:   \"%s\"\n",
	     strlen(detector.filename) ? detector.filename : detector.component);
  } else {
    NXputdata (f, data);
  }

  if (strstr(part,"data") || strstr(part, "events")) {
    NXputattr(f, "signal", &signal, 1, NX_INT32);
    nxprintattr(f, "short_name", strlen(detector.filename) ?
      detector.filename : detector.component);
  }
  nxprintattr(f, "long_name", "%s '%s'", part, detector.title);
  NXclosedata(f);

  return(NX_OK);
} /* mcdetector_out_array_nexus */

/*******************************************************************************
* mcdetector_out_data_nexus: write detector axes+data into current NXdata
*   The data:NXdetector is opened, then filename:NXdata
*   requires: NXentry to be opened
*******************************************************************************/
int mcdetector_out_data_nexus(NXhandle f, MCDETECTOR detector)
{
  char data_name[CHAR_BUF_LENGTH];

  if (!f || !detector.m || mcdisable_output_files) return(NX_OK);

  strcpy_valid(data_name,
    strlen(detector.filename) ?
      detector.filename : detector.component);
  NXlink pLink;
  /* the NXdetector group has been created in mcinfo_out_nexus (siminfo_init) */
  if (NXopengroup(f, "instrument", "NXinstrument") == NX_OK) {
    if (NXopengroup(f, "components", "NXdata") == NX_OK) {
      if (NXopengroup(f, detector.nexuscomp, "NXdata") == NX_OK) {
	if (NXopengroup(f, "output", "NXdetector") == NX_OK) {

	  /* the NXdata group has been created in mcdatainfo_out_nexus */
	  if (NXopengroup(f, data_name, "NXdata") == NX_OK) {
	    
	    MPI_MASTER(
		       nxprintattr(f, "options",
				   strlen(detector.options) ? detector.options : "None");
		       );
	    /* write axes, for histogram data sets, not for lists */
	    if (!strcasestr(detector.format, "list")) {
	      mcdetector_out_axis_nexus(f, detector.xlabel, detector.xvar,
					1, detector.m, detector.xmin, detector.xmax);
	      mcdetector_out_axis_nexus(f, detector.ylabel, detector.yvar,
					2, detector.n, detector.ymin, detector.ymax);
	      mcdetector_out_axis_nexus(f, detector.zlabel, detector.zvar,
					3, detector.p, detector.zmin, detector.zmax); 
	    } else {
	      	    MPI_MASTER(
			       nxprintattr(f, "dataset columns",
					   strlen(detector.ylabel) ? detector.ylabel : "None");
		    );
	    }

	    /* write the actual data (appended if already exists) */
	    if (!strcasestr(detector.format, "list") && !strcasestr(detector.format, "pixels")) {
	      mcdetector_out_array_nexus(f, "data", detector.p1, detector);
	      mcdetector_out_array_nexus(f, "errors", detector.p2, detector);
	      mcdetector_out_array_nexus(f, "ncount", detector.p0, detector);
	    } else if (strcasestr(detector.format, "pixels")) {
	      mcdetector_out_array_nexus(  f, "pixels", detector.p1, detector);
	    } else {
	      mcdetector_out_array_nexus(  f, "events", detector.p1, detector);
	    }
	    NXclosegroup(f);
	    NXopengroup(f, data_name, "NXdata");
	    NXgetgroupID(nxhandle, &pLink);
	    NXclosegroup(f);
	  } /* NXdata data_name*/
	  NXclosegroup(f);
	} /* NXdetector output */
	NXclosegroup(f);
      } /* NXdata detector.nexuscomp */
      NXclosegroup(f);
    } /* NXdata components */
    NXclosegroup(f);
  } /* NXdata instrument */
  
  if (!strcasestr(detector.format, "pixels")) {
    if (NXopengroup(f, "data", "NXdetector") == NX_OK) {
      NXmakelink(nxhandle, &pLink);
      NXclosegroup(f);
    }
  }
  return(NX_OK);
} /* mcdetector_out_array_nexus */

#ifdef USE_MPI
/*******************************************************************************
* mcdetector_out_list_slaves: slaves send their list data to master which writes
*   requires: NXentry to be opened
* WARNING: this method has a flaw: it requires all nodes to flush the lists
*   the same number of times. In case one node is just below the buffer size
*   when finishing (e.g. monitor_nd), it may not trigger save but others may.
*   Then the number of recv/send is not constant along nodes, and simulation stalls.
*******************************************************************************/
MCDETECTOR mcdetector_out_list_slaves(MCDETECTOR detector)
{
  int     node_i=0;
  MPI_MASTER(
	     printf("\n** MPI master gathering slave node list data ** \n");
  );

  if (mpi_node_rank != mpi_node_root) {
    /* MPI slave: slaves send their data to master: 2 MPI_Send calls */
    /* m, n, p must be sent first, since all slaves do not have the same number of events */
    int mnp[3]={detector.m,detector.n,detector.p};

    if (mc_MPI_Send(mnp, 3, MPI_INT, mpi_node_root)!= MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send mnp list error (mcdetector_out_list_slaves)\n", mpi_node_rank);
    if (!detector.p1
     || mc_MPI_Send(detector.p1, mnp[0]*mnp[1]*mnp[2], MPI_DOUBLE, mpi_node_root) != MPI_SUCCESS)
      fprintf(stderr, "Warning: proc %i to master: MPI_Send p1 list error: mnp=%i (mcdetector_out_list_slaves)\n", mpi_node_rank, abs(mnp[0]*mnp[1]*mnp[2]));
    /* slaves are done: sent mnp and p1 */
  } /* end slaves */

  /* MPI master: receive data from slaves sequentially: 2 MPI_Recv calls */

  if (mpi_node_rank == mpi_node_root) {
    for(node_i=0; node_i<mpi_node_count; node_i++) {
      double *this_p1=NULL;                               /* buffer to hold the list from slaves */
      int     mnp[3]={0,0,0};  /* size of this buffer */
      if (node_i != mpi_node_root) { /* get data from slaves */
	if (mc_MPI_Recv(mnp, 3, MPI_INT, node_i) != MPI_SUCCESS)
	  fprintf(stderr, "Warning: master from proc %i: "
		  "MPI_Recv mnp list error (mcdetector_write_data)\n", node_i);
	if (mnp[0]*mnp[1]*mnp[2]) {
	  this_p1 = (double *)calloc(mnp[0]*mnp[1]*mnp[2], sizeof(double));
	  if (!this_p1 || mc_MPI_Recv(this_p1, abs(mnp[0]*mnp[1]*mnp[2]), MPI_DOUBLE, node_i)!= MPI_SUCCESS)
	    fprintf(stderr, "Warning: master from proc %i: "
		    "MPI_Recv p1 list error: mnp=%i (mcdetector_write_data)\n", node_i, mnp[0]*mnp[1]*mnp[2]);
	  else {
	    printf(". MPI master writing data for slave node %i\n",node_i);
	    detector.p1 = this_p1;
	    detector.m  = mnp[0]; detector.n  = mnp[1]; detector.p  = mnp[2];

	    mcdetector_out_data_nexus(nxhandle, detector);
	  }
	}
      } /* if not master */
      free(this_p1);
    } /* for */
  MPI_MASTER(
	     printf("\n** Done ** \n");
  );
  }
  // Common return statement for slaves / master alike
  return(detector);
}
#endif

MCDETECTOR mcdetector_out_0D_nexus(MCDETECTOR detector)
{
  /* Write data set information to NeXus file. */
  MPI_MASTER(
    mcdatainfo_out_nexus(nxhandle, detector);
  );

  return(detector);
} /* mcdetector_out_0D_ascii */

MCDETECTOR mcdetector_out_1D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_1D_ascii */

MCDETECTOR mcdetector_out_2D_nexus(MCDETECTOR detector)
{
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );

#ifdef USE_MPI // and USE_NEXUS
  /* NeXus: slave nodes have master write their lists */
  if (strcasestr(detector.format, "list") && mpi_node_count > 1) {
    mcdetector_out_list_slaves(detector);
  }
#endif /* USE_MPI */

  return(detector);
} /* mcdetector_out_2D_nexus */

MCDETECTOR mcdetector_out_3D_nexus(MCDETECTOR detector)
{
  printf("Received detector from %s\n",detector.component);
  MPI_MASTER(
  mcdatainfo_out_nexus(nxhandle, detector);
  mcdetector_out_data_nexus(nxhandle, detector);
  );
  return(detector);
} /* mcdetector_out_3D_nexus */


#endif /* USE_NEXUS*/








/* ========================================================================== */

/*                            Main input functions                            */
/*            DETECTOR_OUT_xD function calls -> ascii or NeXus                */

/* ========================================================================== */

/*******************************************************************************
* siminfo_init:   open SIM and write header
*******************************************************************************/
FILE *siminfo_init(FILE *f)
{
  int exists=0;

  /* check format */
  if (!mcformat || !strlen(mcformat)
   || !strcasecmp(mcformat, "MCSTAS") || !strcasecmp(mcformat, "MCXTRACE")
   || !strcasecmp(mcformat, "PGPLOT") || !strcasecmp(mcformat, "GNUPLOT") || !strcasecmp(mcformat, "MCCODE")
   || !strcasecmp(mcformat, "MATLAB")) {
    mcformat="McCode";
#ifdef USE_NEXUS
  } else if (strcasestr(mcformat, "NeXus")) {
    /* Do nothing */
#endif
  } else {
    fprintf(stderr,
	    "Warning: You have requested the output format %s which is unsupported by this binary. Resetting to standard %s format.\n",mcformat ,"McCode");
    mcformat="McCode";
  }

  /* open the SIM file if not defined yet */
  if (siminfo_file || mcdisable_output_files)
    return (siminfo_file);

#ifdef USE_NEXUS
  /* only master writes NeXus header: calls NXopen(nxhandle) */
  if (mcformat && strcasestr(mcformat, "NeXus")) {
	  MPI_MASTER(
	  siminfo_file = mcnew_file(siminfo_name, "h5", &exists);
    if(!siminfo_file)
      fprintf(stderr,
	      "Warning: could not open simulation description file '%s'\n",
	      siminfo_name);
	  else
	    mcinfo_out_nexus(nxhandle);
	  );
    return(siminfo_file); /* points to nxhandle */
  }
#endif

  /* write main description file (only MASTER) */
  MPI_MASTER(

  siminfo_file = mcnew_file(siminfo_name, "sim", &exists);
  if(!siminfo_file)
    fprintf(stderr,
	    "Warning: could not open simulation description file '%s'\n",
	    siminfo_name);
  else
  {
    /* write SIM header */
    time_t t=time(NULL);
    siminfo_out("%s simulation description file for %s.\n",
      MCCODE_NAME, instrument_name);
    siminfo_out("Date:    %s", ctime(&t)); /* includes \n */
    siminfo_out("Program: %s\n\n", MCCODE_STRING);

    siminfo_out("begin instrument: %s\n", instrument_name);
    mcinfo_out(   "  ", siminfo_file);
    siminfo_out("end instrument\n");

    siminfo_out("\nbegin simulation: %s\n", dirname);
    mcruninfo_out("  ", siminfo_file);
    siminfo_out("end simulation\n");

  }
  ); /* MPI_MASTER */
  return (siminfo_file);

} /* siminfo_init */

/*******************************************************************************
*   siminfo_close:  close SIM
*******************************************************************************/
void siminfo_close()
{
#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
  if(siminfo_file && !mcdisable_output_files) {
#ifdef USE_NEXUS
    if (mcformat && strcasestr(mcformat, "NeXus")) {
      time_t t=time(NULL);
      nxprintf(nxhandle, "end_time", ctime(&t));
      nxprintf(nxhandle, "duration", "%li", (long)t-mcstartdate);
      NXclosegroup(nxhandle); /* NXentry */
      NXclose(&nxhandle);
    } else {
#endif
      fclose(siminfo_file);
#ifdef USE_NEXUS
    }
#endif
#ifdef USE_MPI
  }
#endif
    siminfo_file = NULL;
  }
} /* siminfo_close */

/*******************************************************************************
* mcdetector_out_0D: wrapper for 0D (single value).
*   Output single detector/monitor data (p0, p1, p2).
*   Title is t, component name is c.
*******************************************************************************/
MCDETECTOR mcdetector_out_0D(char *t, double p0, double p1, double p2,
			     char *c, Coords posa, Rotation rota, int index)
{
  /* import and perform basic detector analysis (and handle MPI reduce) */
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " data"),
    1, 1, 1,
    "I", "", "",
    "I", "", "",
    0, 0, 0, 0, 0, 0, c,
    &p0, &p1, &p2, posa, rota, index); /* write Detector: line */

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_0D_nexus(detector));
  else
#endif
    return(mcdetector_out_0D_ascii(detector));

} /* mcdetector_out_0D */



/*******************************************************************************
* mcdetector_out_1D: wrapper for 1D.
*   Output 1d detector data (p0, p1, p2) for n bins linearly
*   distributed across the range x1..x2 (x1 is lower limit of first
*   bin, x2 is upper limit of last bin). Title is t, axis labels are xl
*   and yl. File name is f, component name is c.
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   xvar: measured variable length
*   x1:   x axus min
*   x2:   x axis max
*   n:    1d data vector lenght
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_1D(char *t, char *xl, char *yl,
        char *xvar, double x1, double x2,
        long n,
        double *p0, double *p1, double *p2, char *f,
        char *c, Coords posa, Rotation rota, int index)
{
  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  // detector_import calls mcdetector_statistics, which will return different
  // MCDETECTOR versions for 1-D data based on the value of mcformat.
  //
  MCDETECTOR detector = detector_import(mcformat,
    c, (t ? t : MCCODE_STRING " 1D data"),
    n, 1, 1,
    xl, yl, (n > 1 ? "Signal per bin" : " Signal"),
    xvar, "(I,I_err)", "I",
    x1, x2, 0, 0, 0, 0, f,
    p0, p1, p2, posa, rota, index); /* write Detector: line */
  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    detector = mcdetector_out_1D_nexus(detector);
  else
#endif
    detector = mcdetector_out_1D_ascii(detector);
  if (detector.p1 != p1 && detector.p1) {
    // mcdetector_statistics allocated memory but it hasn't been freed.
    free(detector.p1);
    // plus undo the other damage done there:
    detector.p0 = p0; // was set to NULL
    detector.p1 = p1; // was set to this_p1
    detector.p2 = p2; // was set to NULL
    detector.m = detector.n; // (e.g., labs(n))
    detector.n = 1;  // not (n x n)
    detector.istransposed = n < 0 ? 1 : 0;
  }
  return detector;

} /* mcdetector_out_1D */

/*******************************************************************************
* mcdetector_out_2D: wrapper for 2D.
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*   rota: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
		  char *c, Coords posa, Rotation rota, int index)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D */

/*******************************************************************************
* mcdetector_out_2D_list: List mode 2D including forwarding "options" from
* Monitor_nD
*
*   Special case for list: master creates file first, then slaves append their
*   blocks without header-
*
*   t:    title
*   xl:   x-label
*   yl:   y-label
*   x1:   x axus min
*   x2:   x axis max
*   y1:   y axis min
*   y2:   y axis max
*   m:    dim 1 (x) size
*   n:    dim 2 (y) size
*   p0:   pntr to start of data block#0
*   p1:   pntr to start of data block#1
*   p2:   pntr to start of data block#2
*   f:    filename
*
*   Not included in the macro, and here forwarded to detector_import:
*   c:    ?
*   posa: ?
*   rota: ?
*******************************************************************************/
MCDETECTOR mcdetector_out_2D_list(char *t, char *xl, char *yl,
                  double x1, double x2, double y1, double y2,
                  long m, long n,
                  double *p0, double *p1, double *p2, char *f,
		  char *c, Coords posa, Rotation rota, char* options, int index)
{
  char xvar[CHAR_BUF_LENGTH];
  char yvar[CHAR_BUF_LENGTH];

  /* create short axes labels */
  if (xl && strlen(xl)) { strncpy(xvar, xl, CHAR_BUF_LENGTH); xvar[2]='\0'; }
  else strcpy(xvar, "x");
  if (yl && strlen(yl)) { strncpy(yvar, yl, CHAR_BUF_LENGTH); yvar[2]='\0'; }
  else strcpy(yvar, "y");

  MCDETECTOR detector;

  /* import and perform basic detector analysis (and handle MPI_Reduce) */
  if (labs(m) == 1) {/* n>1 on Y, m==1 on X: 1D, no X axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      n, 1, 1,
      yl, "", "Signal per bin",
      yvar, "(I,Ierr)", "I",
      y1, y2, x1, x2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  } else if (labs(n)==1) {/* m>1 on X, n==1 on Y: 1D, no Y axis*/
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 1D data"),
      m, 1, 1,
      xl, "", "Signal per bin",
      xvar, "(I,Ierr)", "I",
      x1, x2, y1, y2, 0, 0, f,
      p0, p1, p2, posa, rota, index); /* write Detector: line */
  }else {
    detector = detector_import(mcformat,
      c, (t ? t : MCCODE_STRING " 2D data"),
      m, n, 1,
      xl, yl, "Signal per bin",
      xvar, yvar, "I",
      x1, x2, y1, y2, 0, 0, f,
     p0, p1, p2, posa, rota, index); /* write Detector: line */
  }

  MPI_MASTER(
  if (strlen(options)) {
    strcpy(detector.options,options);
  } else {
    strcpy(detector.options,"None");
  }
  );

  if (!detector.p1 || !detector.m) return(detector);

#ifdef USE_NEXUS
  if (strcasestr(detector.format, "NeXus"))
    return(mcdetector_out_2D_nexus(detector));
  else
#endif
    return(mcdetector_out_2D_ascii(detector));

} /* mcdetector_out_2D_list */

/*******************************************************************************
* mcdetector_out_list: wrapper for list output (calls out_2D with mcformat+"list").
*   m=number of events, n=size of each event
*******************************************************************************/
MCDETECTOR mcdetector_out_list(char *t, char *xl, char *yl,
                  long m, long n,
                  double *p1, char *f,
			       char *c, Coords posa, Rotation rota, char* options, int index)
{
  char       format_new[CHAR_BUF_LENGTH];
  char      *format_org;
  MCDETECTOR detector;

  format_org = mcformat;
  strcpy(format_new, mcformat);
  strcat(format_new, " list");
  mcformat = format_new;
  detector = mcdetector_out_2D_list(t, xl, yl,
                  1,labs(m),1,labs(n),
                  m,n,
                  NULL, p1, NULL, f,
		  c, posa,rota,options, index);

  mcformat = format_org;
  return(detector);
}

/*******************************************************************************
 * mcuse_dir: set data/sim storage directory and create it,
 * or exit with error if exists
 ******************************************************************************/
static void
mcuse_dir(char *dir)
{
  if (!dir || !strlen(dir)) return;
#ifdef MC_PORTABLE
  fprintf(stderr, "Error: "
          "Directory output cannot be used with portable simulation (mcuse_dir)\n");
  exit(1);
#else  /* !MC_PORTABLE */
  /* handle file://directory URL type */
  if (strncmp(dir, "file://", strlen("file://")))
    dirname = dir;
  else
    dirname = dir+strlen("file://");


#ifdef USE_MPI
  if(mpi_node_rank == mpi_node_root) {
#endif
    int exists=0;
    DIR* handle = opendir(dirname);
    if (handle) {
      /* Directory exists. */
      closedir(handle);
      exists=1;
    }
    if(mkdir(dirname, 0777)) {
#ifndef DANSE
      if(!mcappend) {
	fprintf(stderr, "Error: unable to create directory '%s' (mcuse_dir)\n", dir);
	fprintf(stderr, "(Maybe the directory already exists?)\n");
#endif
#ifdef USE_MPI
	MPI_Abort(MPI_COMM_WORLD, -1);
#endif
	exit(-1);
      }
    }
#ifdef USE_MPI
    }
#endif

  /* remove trailing PATHSEP (if any) */
  while (strlen(dirname) && dirname[strlen(dirname) - 1] == MC_PATHSEP_C)
    dirname[strlen(dirname) - 1]='\0';
#endif /* !MC_PORTABLE */
} /* mcuse_dir */

/*******************************************************************************
* mcinfo: display instrument simulation info to stdout and exit
*******************************************************************************/
static void
mcinfo(void)
{
  fprintf(stdout, "begin instrument: %s\n", instrument_name);
  mcinfo_out("  ", stdout);
  fprintf(stdout, "end instrument\n");
  fprintf(stdout, "begin simulation: %s\n", dirname ? dirname : ".");
  mcruninfo_out("  ", stdout);
  fprintf(stdout, "end simulation\n");
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcinfo */

/*******************************************************************************
* mcparameterinfo: display instrument parameter info to stdout and exit
*******************************************************************************/
static void
mcparameterinfo(void)
{
  mcparameterinfo_out("  ", stdout);
  exit(0); /* includes MPI_Finalize in MPI mode */
} /* mcparameterinfo */



#endif /* ndef MCCODE_R_IO_C */

/* end of the I/O section =================================================== */







/*******************************************************************************
* mcset_ncount: set total number of rays to generate
*******************************************************************************/
void mcset_ncount(unsigned long long int count)
{
  mcncount = count;
}

/* mcget_ncount: get total number of rays to generate */
unsigned long long int mcget_ncount(void)
{
  return mcncount;
}

/* mcget_run_num: get curent number of rays */
/* Within the TRACE scope we are now using _particle->uid directly */
unsigned long long int mcget_run_num() // shuld be (_class_particle* _particle) somehow
{
  /* This function only remains for the few cases outside TRACE where we need to know
     the number of simulated particles */
  return mcrun_num;
}

/* mcsetn_arg: get ncount from a string argument */
static void
mcsetn_arg(char *arg)
{
  mcset_ncount((long long int) strtod(arg, NULL));
}

/* mcsetseed: set the random generator seed from a string argument */
static void
mcsetseed(char *arg)
{
  mcseed = atol(arg);
  if(!mcseed) {
  //  srandom(mcseed);
  //} else {
    fprintf(stderr, "Error: seed must not be zero (mcsetseed)\n");
    exit(1);
  }
}

/* Following part is only embedded when not redundent with mccode-r.h ========= */

#ifndef MCCODE_H

/* SECTION: MCDISPLAY support. =============================================== */

/*******************************************************************************
* Just output MCDISPLAY keywords to be caught by an external plotter client.
*******************************************************************************/

void mcdis_magnify(char *what){
  // Do nothing here, better use interactive zoom from the tools
}

void mcdis_line(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: multiline(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}

void mcdis_dashed_line(double x1, double y1, double z1,
		       double x2, double y2, double z2, int n){
  int i;
  const double dx = (x2-x1)/(2*n+1);
  const double dy = (y2-y1)/(2*n+1);
  const double dz = (z2-z1)/(2*n+1);

  for(i = 0; i < n+1; i++)
    mcdis_line(x1 + 2*i*dx,     y1 + 2*i*dy,     z1 + 2*i*dz,
	       x1 + (2*i+1)*dx, y1 + (2*i+1)*dy, z1 + (2*i+1)*dz);
}

void mcdis_multiline(int count, ...){
  va_list ap;
  double x,y,z;

  printf("MCDISPLAY: multiline(%d", count);
  va_start(ap, count);
  while(count--)
    {
    x = va_arg(ap, double);
    y = va_arg(ap, double);
    z = va_arg(ap, double);
    printf(",%g,%g,%g", x, y, z);
    }
  va_end(ap);
  printf(")\n");
}

void mcdis_rectangle(char* plane, double x, double y, double z,
		     double width, double height){
  /* draws a rectangle in the plane           */
  /* x is ALWAYS width and y is ALWAYS height */
  if (strcmp("xy", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y - height/2, z,
		    x + width/2, y - height/2, z,
		    x + width/2, y + height/2, z,
		    x - width/2, y + height/2, z,
		    x - width/2, y - height/2, z);
  } else if (strcmp("xz", plane)==0) {
    mcdis_multiline(5,
		    x - width/2, y, z - height/2,
		    x + width/2, y, z - height/2,
		    x + width/2, y, z + height/2,
		    x - width/2, y, z + height/2,
		    x - width/2, y, z - height/2);
  } else if (strcmp("yz", plane)==0) {
    mcdis_multiline(5,
		    x, y - height/2, z - width/2,
		    x, y - height/2, z + width/2,
		    x, y + height/2, z + width/2,
		    x, y + height/2, z - width/2,
		    x, y - height/2, z - width/2);
  } else {

    fprintf(stderr, "Error: Definition of plane %s unknown\n", plane);
    exit(1);
  }
}

void mcdis_circle(char *plane, double x, double y, double z, double r){
  printf("MCDISPLAY: mcdiscircle('%s',%g,%g,%g,%g)\n", plane, x, y, z, r);
}

void mcdis_new_circle(double x, double y, double z, double r, double nx, double ny, double nz){
  printf("MCDISPLAY: mcdisnew_circle(%g,%g,%g,%g,%g,%g,%g)\n", x, y, z, r, nx, ny, nz);
}


/* Draws a circle with center (x,y,z), radius (r), and in the plane
 * with normal (nx,ny,nz)*/
void mcdis_Circle(double x, double y, double z, double r, double nx, double ny, double nz){
    int i;
    if(nx==0 && ny && nz==0){
        for (i=0;i<24; i++){
            mcdis_line(x+r*sin(i*2*PI/24),y,z+r*cos(i*2*PI/24),
                    x+r*sin((i+1)*2*PI/24),y,z+r*cos((i+1)*2*PI/24));
        }
    }else{
        double mx,my,mz;
        /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
        /*draw circle*/
        for (i=0;i<24; i++){
            double ux,uy,uz;
            double wx,wy,wz;
            rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
            rotate(wx,wy,wz, mx,my,mz, (i+1)*2*PI/24, nx,ny,nz);
            mcdis_line(x+ux*r,y+uy*r,z+uz*r,
                    x+wx*r,y+wy*r,z+wz*r);
        }
    }
}


/*  OLD IMPLEMENTATION
    draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_legacy_box(double x, double y, double z,
	       double width, double height, double length){

  mcdis_rectangle("xy", x, y, z-length/2, width, height);
  mcdis_rectangle("xy", x, y, z+length/2, width, height);
  mcdis_line(x-width/2, y-height/2, z-length/2,
	     x-width/2, y-height/2, z+length/2);
  mcdis_line(x-width/2, y+height/2, z-length/2,
	     x-width/2, y+height/2, z+length/2);
  mcdis_line(x+width/2, y-height/2, z-length/2,
	     x+width/2, y-height/2, z+length/2);
  mcdis_line(x+width/2, y+height/2, z-length/2,
	     x+width/2, y+height/2, z+length/2);
}

/*  NEW 3D IMPLEMENTATION OF BOX SUPPORTS HOLLOW ALSO
    draws a box with center at (x, y, z) and
    width (deltax), height (deltay), length (deltaz) */
void mcdis_box(double x, double y, double z,
	       double width, double height, double length, double thickness, double nx, double ny, double nz){
  if (mcdotrace==2) {
    printf("MCDISPLAY: mcdisbox(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g)\n", x, y, z, width, height, length, thickness, nx, ny, nz);
  } else {
    mcdis_legacy_box(x, y, z, width, height, length);
    if (thickness)
      mcdis_legacy_box(x, y, z, width-thickness, height-thickness, length);
  }
}


/* OLD IMPLEMENTATION
Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz. */
void mcdis_legacy_cylinder( double x, double y, double z,
        double r, double height, int N, double nx, double ny, double nz){
    int i;
    /*no lines make little sense - so trigger the default*/
    if(N<=0) N=5;

    NORM(nx,ny,nz);
    double h_2=height/2.0;
    mcdis_Circle(x+nx*h_2,y+ny*h_2,z+nz*h_2,r,nx,ny,nz);
    mcdis_Circle(x-nx*h_2,y-ny*h_2,z-nz*h_2,r,nx,ny,nz);

    double mx,my,mz;
    /*generate perpendicular vector using (nx,ny,nz) and (0,1,0)*/
    if(nx==0 && ny && nz==0){
        mx=my=0;mz=1;
    }else{
        vec_prod(mx,my,mz, 0,1,0, nx,ny,nz);
        NORM(mx,my,mz);
    }
    /*draw circle*/
    for (i=0; i<24; i++){
        double ux,uy,uz;
        rotate(ux,uy,uz, mx,my,mz, i*2*PI/24, nx,ny,nz);
        mcdis_line(x+nx*h_2+ux*r, y+ny*h_2+uy*r, z+nz*h_2+uz*r,
                 x-nx*h_2+ux*r, y-ny*h_2+uy*r, z-nz*h_2+uz*r);
    }
}

/* NEW 3D IMPLEMENTATION ALSO SUPPORTING HOLLOW
Draws a cylinder with center at (x,y,z) with extent (r,height).
 * The cylinder axis is along the vector nx,ny,nz.*/
void mcdis_cylinder( double x, double y, double z,
        double r, double height, double thickness, double nx, double ny, double nz){
  if (mcdotrace==2) {
      printf("MCDISPLAY: mcdiscylinder(%g, %g, %g, %g, %g, %g, %g, %g, %g)\n",
         x, y, z, r, height, thickness, nx, ny, nz);
  } else {
    mcdis_legacy_cylinder(x, y, z,
			  r, height, 12, nx, ny, nz);
  }
}

/* Draws a cone with center at (x,y,z) with extent (r,height).
 * The cone axis is along the vector nx,ny,nz.*/
void mcdis_cone( double x, double y, double z,
        double r, double height, double nx, double ny, double nz){
  if (mcdotrace==2) {
    printf("MCDISPLAY: mcdiscone(%g, %g, %g, %g, %g, %g, %g, %g)\n",
       x, y, z, r, height, nx, ny, nz);
  } else {
    mcdis_Circle(x, y, z, r, nx, ny, nz);
    mcdis_Circle(x+0.25*height*nx, y+0.25*height*ny, z+0.25*height*nz, 0.75*r, nx, ny, nz);
    mcdis_Circle(x+0.5*height*nx, y+0.5*height*ny, z+0.5*height*nz, 0.5*r, nx, ny, nz);
    mcdis_Circle(x+0.75*height*nx, y+0.75*height*ny, z+0.75*height*nz, 0.25*r, nx, ny, nz);
    mcdis_line(x, y, z, x+height*nx, y+height*ny, z+height*nz);
  }
}

/* Draws a disc with center at (x,y,z) with extent (r).
 * The disc axis is along the vector nx,ny,nz.*/
void mcdis_disc( double x, double y, double z,
        double r, double nx, double ny, double nz){
  printf("MCDISPLAY: mcdisdisc(%g, %g, %g, %g, %g, %g, %g)\n",
     x, y, z, r, nx, ny, nz);
}

/* Draws a annulus with center at (x,y,z) with extent (outer_radius) and remove inner_radius.
 * The annulus axis is along the vector nx,ny,nz.*/
void mcdis_annulus( double x, double y, double z,
        double outer_radius, double inner_radius, double nx, double ny, double nz){
  printf("MCDISPLAY: mcdisannulus(%g, %g, %g, %g, %g, %g, %g, %g)\n",
     x, y, z, outer_radius, inner_radius, nx, ny, nz);
}

/* draws a sphere with center at (x,y,z) with extent (r)*/
void mcdis_sphere(double x, double y, double z, double r){
  if (mcdotrace==2) {
    printf("MCDISPLAY: mcdissphere(%g,%g,%g,%g)\n", x, y, z, r);
  } else {
    double nx,ny,nz;
    int i;
    int N=12;

    nx=0;ny=0;nz=1;
    mcdis_Circle(x,y,z,r,nx,ny,nz);
    for (i=1;i<N;i++){
        rotate(nx,ny,nz, nx,ny,nz, PI/N, 0,1,0);
        mcdis_Circle(x,y,z,r,nx,ny,nz);
    }
    /*lastly draw a great circle perpendicular to all N circles*/
    //mcdis_Circle(x,y,z,radius,1,0,0);

    for (i=1;i<=N;i++){
        double yy=-r+ 2*r*((double)i/(N+1));
        mcdis_Circle(x,y+yy ,z,  sqrt(r*r-yy*yy) ,0,1,0);
    }
  }
}
/* POLYHEDRON IMPLEMENTATION*/

void mcdis_polyhedron(char *vertices_faces){
  printf("MCDISPLAY: polyhedron %s\n", vertices_faces);
}

/* POLYGON IMPLEMENTATION */
void mcdis_polygon(int count, ...){
  va_list ap;
  double *x,*y,*z;

  double x0=0,y0=0,z0=0; /* Used for centre-of-mass in trace==2 */

  x=malloc(count*sizeof(double));
  y=malloc(count*sizeof(double));
  z=malloc(count*sizeof(double));
  if (!x || !y || !z) {
    fprintf(stderr,"Error initializing polygon set size %i\n",count);
    exit(-1);
  }
  va_start(ap, count);
  // Fallback for trace==1 is multiline, one rank higher
  if (mcdotrace==1) {
    printf("MCDISPLAY: multiline(%i,",count+1);
  }
  
  int j;
  for (j=0; j<count; j++) {
    x[j] = va_arg(ap, double);
    y[j] = va_arg(ap, double);
    z[j] = va_arg(ap, double);
    if (mcdotrace==1) {
      printf("%g,%g,%g,",x[j],y[j],z[j]);
    } else {
      // Calculation of polygon centre of mass
      x0 += x[j]; y0 += y[j]; z0 += z[j];
    }
  }
  va_end(ap);

  /* Patch data for multiline(count+1, ... use 0th point*/
  if (mcdotrace==1) {
    printf("%g,%g,%g)\n",x[0],y[0],z[0]);
  } else {
    x0 /= count; y0 /= count; z0 /= count;
    /* Build up a json string for a "polyhedron" */
    // Estimate size of the JSON string
    const int VERTEX_OVERHEAD = 30;
    const int FACE_OVERHEAD_BASE = 20;
    const int FACE_INDEX_OVERHEAD = 15;
    int estimated_size = 256; // Base size
    estimated_size += count * VERTEX_OVERHEAD;

    int faceSize;
    int vtxSize;
    if (count > 3) {
      /* Split in triangles - as many as polygon rank */
      faceSize=count;
      vtxSize=count+1;
    } else {
      faceSize=1;
      vtxSize=count;
    }
    
    for (int i = 0; i < faceSize;) {
        int num_indices = 3;
        estimated_size += FACE_OVERHEAD_BASE + num_indices * FACE_INDEX_OVERHEAD;
        i += num_indices + 1;
    }

    char *json_string = malloc(estimated_size);
    if (json_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    char *ptr = json_string;
    ptr += sprintf(ptr, "{ \"vertices\": [");

    if (count==3) { // Single, basic triangle
      ptr += sprintf(ptr, "[%g, %g, %g], [%g, %g, %g], [%g, %g, %g]", x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2]);
    } else {
      for (int i = 0; i < vtxSize-1; i++) {
        ptr += sprintf(ptr, "[%g, %g, %g]", x[i], y[i], z[i]);
        if (i < vtxSize - 2) {
	  ptr += sprintf(ptr, ", ");
        } else {
	  ptr += sprintf(ptr, ", [%g, %g, %g]", x0, y0, z0);
	}
      }
    }
    ptr += sprintf(ptr, "], \"faces\": [");
    if (count==3) { // Single, basic triangle, 1 face...
      ptr += sprintf(ptr, "{ \"face\": [");
      ptr += sprintf(ptr, "0, 1, 2");
      ptr += sprintf(ptr, "]}");
    } else {
      for (int i = 0; i < faceSize; i++) {
        int num = 3;
        ptr += sprintf(ptr, "{ \"face\": [");
	if (i < faceSize - 1) {
	  ptr += sprintf(ptr, "%d, %d, %d",i,i+1,count);
	} else {
	  ptr += sprintf(ptr, "%d, %d, %d",i,count,0);
	}
	ptr += sprintf(ptr, "]}");
	if (i < faceSize-1) {
	  ptr += sprintf(ptr, ", ");
	}
      }
    }
    ptr += sprintf(ptr, "]}");
    mcdis_polyhedron(json_string);

    free(json_string);
  }
  free(x);free(y);free(z);
}
/* END NEW POLYGON IMPLEMENTATION*/

/*
void polygon(double x1, double y1, double z1,
                double x2, double y2, double z2){
  printf("MCDISPLAY: polygon(2,%g,%g,%g,%g,%g,%g)\n",
         x1,y1,z1,x2,y2,z2);
}
*/

/* SECTION: coordinates handling ============================================ */

/*******************************************************************************
* Since we use a lot of geometric calculations using Cartesian coordinates,
* we collect some useful routines here. However, it is also permissible to
* work directly on the underlying struct coords whenever that is most
* convenient (that is, the type Coords is not abstract).
*
* Coordinates are also used to store rotation angles around x/y/z axis.
*
* Since coordinates are used much like a basic type (such as double), the
* structure itself is passed and returned, rather than a pointer.
*
* At compile-time, the values of the coordinates may be unknown (for example
* a motor position). Hence coordinates are general expressions and not simple
* numbers. For this we used the type Coords_exp which has three CExp
* fields. For runtime (or calculations possible at compile time), we use
* Coords which contains three double fields.
*******************************************************************************/

/* coords_set: Assign coordinates. */
Coords coords_set(MCNUM x, MCNUM y, MCNUM z)
{
  Coords a;

  a.x = x;
  a.y = y;
  a.z = z;
  return a;
}

/* coords_get: get coordinates. Required when 'x','y','z' are #defined as ray pars */
Coords coords_get(Coords a, MCNUM *x, MCNUM *y, MCNUM *z)
{
  *x = a.x;
  *y = a.y;
  *z = a.z;
  return a;
}

/* coords_add: Add two coordinates. */
Coords coords_add(Coords a, Coords b)
{
  Coords c;

  c.x = a.x + b.x;
  c.y = a.y + b.y;
  c.z = a.z + b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_sub: Subtract two coordinates. */
Coords coords_sub(Coords a, Coords b)
{
  Coords c;

  c.x = a.x - b.x;
  c.y = a.y - b.y;
  c.z = a.z - b.z;
  if (fabs(c.z) < 1e-14) c.z=0.0;
  return c;
}

/* coords_neg: Negate coordinates. */
Coords coords_neg(Coords a)
{
  Coords b;

  b.x = -a.x;
  b.y = -a.y;
  b.z = -a.z;
  return b;
}

/* coords_scale: Scale a vector. */
Coords coords_scale(Coords b, double scale) {
  Coords a;

  a.x = b.x*scale;
  a.y = b.y*scale;
  a.z = b.z*scale;
  return a;
}

/* coords_sp: Scalar product: a . b */
double coords_sp(Coords a, Coords b) {
  double value;

  value = a.x*b.x + a.y*b.y + a.z*b.z;
  return value;
}

/* coords_xp: Cross product: a = b x c. */
Coords coords_xp(Coords b, Coords c) {
  Coords a;

  a.x = b.y*c.z - c.y*b.z;
  a.y = b.z*c.x - c.z*b.x;
  a.z = b.x*c.y - c.x*b.y;
  return a;
}

/* coords_len: Gives length of coords set. */
double coords_len(Coords a) {
  return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

/* coords_mirror: Mirror a in plane (through the origin) defined by normal n*/
Coords coords_mirror(Coords a, Coords n) {
  double t = scalar_prod(n.x, n.y, n.z, n.x, n.y, n.z);
  Coords b;
  if (t!=1) {
    t = sqrt(t);
    n.x /= t;
    n.y /= t;
    n.z /= t;
  }
  t=scalar_prod(a.x, a.y, a.z, n.x, n.y, n.z);
  b.x = a.x-2*t*n.x;
  b.y = a.y-2*t*n.y;
  b.z = a.z-2*t*n.z;
  return b;
}

/* coords_print: Print out vector values. */
void coords_print(Coords a) {
  #if !defined(OPENACC) && !defined(_OPENMP)
  fprintf(stdout, "(%f, %f, %f)\n", a.x, a.y, a.z);
  #endif
  return;
}

mcstatic void coords_norm(Coords* c) {
	double temp = coords_sp(*c,*c);

	// Skip if we will end dividing by zero
	if (temp == 0) return;

	temp = sqrt(temp);

	c->x /= temp;
	c->y /= temp;
	c->z /= temp;
}

/* coords_test_zero: check if zero vector*/
int coords_test_zero(Coords a){
  return ( a.x==0 && a.y==0 && a.z==0 );
}

/*******************************************************************************
* The Rotation type implements a rotation transformation of a coordinate
* system in the form of a double[3][3] matrix.
*
* Contrary to the Coords type in coords.c, rotations are passed by
* reference. Functions that yield new rotations do so by writing to an
* explicit result parameter; rotations are not returned from functions. The
* reason for this is that arrays cannot by returned from functions (though
* structures can; thus an alternative would have been to wrap the
* double[3][3] array up in a struct). Such are the ways of C programming.
*
* A rotation represents the tranformation of the coordinates of a vector when
* changing between coordinate systems that are rotated with respect to each
* other. For example, suppose that coordinate system Q is rotated 45 degrees
* around the Z axis with respect to coordinate system P. Let T be the
* rotation transformation representing a 45 degree rotation around Z. Then to
* get the coordinates of a vector r in system Q, apply T to the coordinates
* of r in P. If r=(1,0,0) in P, it will be (sqrt(1/2),-sqrt(1/2),0) in
* Q. Thus we should be careful when interpreting the sign of rotation angles:
* they represent the rotation of the coordinate systems, not of the
* coordinates (which has opposite sign).
*******************************************************************************/

/*******************************************************************************
* rot_set_rotation: Get transformation for rotation first phx around x axis,
* then phy around y, then phz around z.
*******************************************************************************/
void rot_set_rotation(Rotation t, double phx, double phy, double phz)
{
  if ((phx == 0) && (phy == 0) && (phz == 0)) {
    t[0][0] = 1.0;
    t[0][1] = 0.0;
    t[0][2] = 0.0;
    t[1][0] = 0.0;
    t[1][1] = 1.0;
    t[1][2] = 0.0;
    t[2][0] = 0.0;
    t[2][1] = 0.0;
    t[2][2] = 1.0;
  } else {
    double cx = cos(phx);
    double sx = sin(phx);
    double cy = cos(phy);
    double sy = sin(phy);
    double cz = cos(phz);
    double sz = sin(phz);

    t[0][0] = cy*cz;
    t[0][1] = sx*sy*cz + cx*sz;
    t[0][2] = sx*sz - cx*sy*cz;
    t[1][0] = -cy*sz;
    t[1][1] = cx*cz - sx*sy*sz;
    t[1][2] = sx*cz + cx*sy*sz;
    t[2][0] = sy;
    t[2][1] = -sx*cy;
    t[2][2] = cx*cy;
  }
}

/*******************************************************************************
* rot_test_identity: Test if rotation is identity
*******************************************************************************/
int rot_test_identity(Rotation t)
{
  return (t[0][0] + t[1][1] + t[2][2] == 3);
}

/*******************************************************************************
* rot_mul: Matrix multiplication of transformations (this corresponds to
* combining transformations). After rot_mul(T1, T2, T3), doing T3 is
* equal to doing first T2, then T1.
* Note that T3 must not alias (use the same array as) T1 or T2.
*******************************************************************************/
void rot_mul(Rotation t1, Rotation t2, Rotation t3)
{
  if (rot_test_identity(t1)) {
    rot_copy(t3, t2);
  } else if (rot_test_identity(t2)) {
    rot_copy(t3, t1);
  } else {
    int i,j;
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3; j++)
	t3[i][j] = t1[i][0]*t2[0][j] + t1[i][1]*t2[1][j] + t1[i][2]*t2[2][j];
  }
}

/*******************************************************************************
* rot_copy: Copy a rotation transformation (arrays cannot be assigned in C).
*******************************************************************************/
void rot_copy(Rotation dest, Rotation src)
{
  int i,j;
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      dest[i][j] = src[i][j];
}

/*******************************************************************************
* rot_transpose: Matrix transposition, which is inversion for Rotation matrices
*******************************************************************************/
void rot_transpose(Rotation src, Rotation dst)
{
  dst[0][0] = src[0][0];
  dst[0][1] = src[1][0];
  dst[0][2] = src[2][0];
  dst[1][0] = src[0][1];
  dst[1][1] = src[1][1];
  dst[1][2] = src[2][1];
  dst[2][0] = src[0][2];
  dst[2][1] = src[1][2];
  dst[2][2] = src[2][2];
}

/*******************************************************************************
* rot_apply: returns t*a
*******************************************************************************/
Coords rot_apply(Rotation t, Coords a)
{
  Coords b;
  if (rot_test_identity(t)) {
    return a;
  } else {
    b.x = t[0][0]*a.x + t[0][1]*a.y + t[0][2]*a.z;
    b.y = t[1][0]*a.x + t[1][1]*a.y + t[1][2]*a.z;
    b.z = t[2][0]*a.x + t[2][1]*a.y + t[2][2]*a.z;
    return b;
  }
}

/**
 * Pretty-printing of rotation matrices.
 */
void rot_print(Rotation rot) {
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[0][0], rot[0][1], rot[0][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n",
			rot[1][0], rot[1][1], rot[1][2]);
	printf("[ %4.2f %4.2f %4.2f ]\n\n",
			rot[2][0], rot[2][1], rot[2][2]);
}

/**
 * Vector product: used by vec_prod (mccode-r.h). Use coords_xp for Coords.
 */
void vec_prod_func(double *x, double *y, double *z,
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
    *x = (y1)*(z2) - (y2)*(z1);
    *y = (z1)*(x2) - (z2)*(x1);
    *z = (x1)*(y2) - (x2)*(y1);
}

/**
 * Scalar product: use coords_sp for Coords.
 */
double scalar_prod(
		double x1, double y1, double z1,
		double x2, double y2, double z2) {
	return ((x1 * x2) + (y1 * y2) + (z1 * z2));
}

mcstatic void norm_func(double *x, double *y, double *z) {
	double temp = (*x * *x) + (*y * *y) + (*z * *z);
	if (temp != 0) {
		temp = sqrt(temp);
		*x /= temp;
		*y /= temp;
		*z /= temp;
	}
}


/* SECTION: GPU algorithms ================================================== */


/*
*  Divide-and-conquer strategy for parallelizing this task: Sort absorbed
*  particles last.
*
*   particles:  the particle array, required to checking _absorbed
*   pbuffer:    same-size particle buffer array required for parallel sort
*   len:        sorting area-of-interest size (e.g. from previous calls)
*   buffer_len: total array size
*   flag_split: if set, multiply live particles into absorbed slots, up to buffer_len
*   multiplier: output arg, becomes the  SPLIT multiplier if flag_split is set
*/
#ifdef FUNNEL
long sort_absorb_last(_class_particle* particles, _class_particle* pbuffer, long len, long buffer_len, long flag_split, long* multiplier) {
  #define SAL_THREADS 1024 // num parallel sections
  if (len<SAL_THREADS) return sort_absorb_last_serial(particles, len);

  if (multiplier != NULL) *multiplier = -1; // set default out value for multiplier
  long newlen = 0;
  long los[SAL_THREADS]; // target array startidxs
  long lens[SAL_THREADS]; // target array sublens
  long l = floor(len/(SAL_THREADS-1)); // subproblem_len
  long ll = len - l*(SAL_THREADS-1); // last_subproblem_len

  // TODO: The l vs ll is too simplistic, since ll can become much larger
  // than l, resulting in idling. We should distribute lengths more evenly.

  // step 1: sort sub-arrays
  #pragma acc parallel loop present(particles[0:buffer_len], pbuffer[0:buffer_len])
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long lo = l*tidx;
    long loclen = l;
    if (tidx==(SAL_THREADS-1)) loclen = ll; // last sub-problem special case
    long i = lo;
    long j = lo + loclen - 1;

    // write into pbuffer at i and j
    #pragma acc loop seq
    while (i < j) {
      #pragma acc loop seq
      while (!particles[i]._absorbed && i<j) {
        pbuffer[i] = particles[i];
        i++;
      }
      #pragma acc loop seq
      while (particles[j]._absorbed && i<j) {
        pbuffer[j] = particles[j];
        j--;
      }
      if (i < j) {
        pbuffer[j] = particles[i];
        pbuffer[i] = particles[j];
        i++;
        j--;
      }
    }
    // transfer edge case
    if (i==j)
      pbuffer[i] = particles[i];

    lens[tidx] = i - lo;
    if (i==j && !particles[i]._absorbed) lens[tidx]++;
  }

  // determine lo's
  long accumlen = 0;
  #pragma acc loop seq
  for (long idx=0; idx<SAL_THREADS; idx++) {
    los[idx] = accumlen;
    accumlen = accumlen + lens[idx];
  }

  // step 2: write non-absorbed sub-arrays to psorted/output from the left
  #pragma acc parallel loop present(pbuffer[0:buffer_len])
  for (unsigned long tidx=0; tidx<SAL_THREADS; tidx++) {
    long j, k;
    #pragma acc loop seq
    for (long i=0; i<lens[tidx]; i++) {
      j = i + l*tidx;
      k = i + los[tidx];
      particles[k] = pbuffer[j];
    }
  }
  //for (int ii=0;ii<accumlen;ii++) printf("%ld ", (psorted[ii]->_absorbed));

  // return (no SPLIT)
  if (flag_split != 1)
    return accumlen;

  // SPLIT - repeat the non-absorbed block N-1 times, where len % accumlen = N + R
  int mult = buffer_len / accumlen; // TODO: possibly use a new arg, bufferlen, rather than len

  // not enough space for full-block split, return
  if (mult <= 1)
    return accumlen;

  // copy non-absorbed block
  #pragma acc parallel loop present(particles[0:buffer_len])
  for (long tidx = 0; tidx < accumlen; tidx++) { // tidx: thread index
    randstate_t randstate[7];
    _class_particle sourcebuffer;
    _class_particle targetbuffer;
    // assign reduced weight to all particles
    particles[tidx].p=particles[tidx].p/mult;
    #pragma acc loop seq
    for (long bidx = 1; bidx < mult; bidx++) { // bidx: block index
      // preserve absorbed particle (for randstate)
      sourcebuffer = particles[bidx*accumlen + tidx];
      // buffer full particle struct
      targetbuffer = particles[tidx];
      // reassign previous randstate
      targetbuffer.randstate[0] = sourcebuffer.randstate[0];
      targetbuffer.randstate[1] = sourcebuffer.randstate[1];
      targetbuffer.randstate[2] = sourcebuffer.randstate[2];
      targetbuffer.randstate[3] = sourcebuffer.randstate[3];
      targetbuffer.randstate[4] = sourcebuffer.randstate[4];
      targetbuffer.randstate[5] = sourcebuffer.randstate[5];
      targetbuffer.randstate[6] = sourcebuffer.randstate[6];
      // apply
      particles[bidx*accumlen + tidx] = targetbuffer;
    }
  }

  // set out split multiplier value
  *multiplier = mult;

  // return expanded array size
  return accumlen * mult;
}

#endif

/*
*  Fallback serial version of the one above.
*/
long sort_absorb_last_serial(_class_particle* particles, long len) {
  long i = 0;
  long j = len - 1;
  _class_particle pbuffer;

  // bubble
  while (i < j) {
    while (!particles[i]._absorbed && i<j) i++;
    while (particles[j]._absorbed && i<j) j--;
    if (i < j) {
      pbuffer = particles[j];
      particles[j] = particles[i];
      particles[i] = pbuffer;
      i++;
      j--;
    }
  }

  // return new length
  if (i==j && !particles[i]._absorbed)
    return i + 1;
  else
    return i;
}

/*******************************************************************************
* mccoordschange: applies rotation to (x y z) and (vx vy vz) and Spin (sx,sy,sz)
*******************************************************************************/
void mccoordschange(Coords a, Rotation t, _class_particle *particle)
{
  Coords b, c;

  b.x = particle->x;
  b.y = particle->y;
  b.z = particle->z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  particle->x = b.x;
  particle->y = b.y;
  particle->z = b.z;

#if MCCODE_PARTICLE_CODE == 2112
    if (particle->vz != 0.0 || particle->vx != 0.0 || particle->vy != 0.0)
      mccoordschange_polarisation(t, &(particle->vx), &(particle->vy), &(particle->vz));

    if (particle->sz != 0.0 || particle->sx != 0.0 || particle->sy != 0.0)
      mccoordschange_polarisation(t, &(particle->sx), &(particle->sy), &(particle->sz));
#elif MCCODE_PARTICLE_CODE == 22
    if (particle->kz != 0.0 || particle->kx != 0.0 || particle->ky != 0.0)
      mccoordschange_polarisation(t, &(particle->kx), &(particle->ky), &(particle->kz));

    if (particle->Ez != 0.0 || particle->Ex != 0.0 || particle->Ey != 0.0)
      mccoordschange_polarisation(t, &(particle->Ex), &(particle->Ey), &(particle->Ez));
#endif
}

/*******************************************************************************
* mccoordschange_polarisation: applies rotation to vector (sx sy sz)
*******************************************************************************/
void mccoordschange_polarisation(Rotation t, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *sx;
  b.y = *sy;
  b.z = *sz;
  c = rot_apply(t, b);
  *sx = c.x;
  *sy = c.y;
  *sz = c.z;
}

/* SECTION: vector math  ==================================================== */

/* normal_vec_func: Compute normal vector to (x,y,z). */
void normal_vec(double *nx, double *ny, double *nz,
                double x, double y, double z)
{
  double ax = fabs(x);
  double ay = fabs(y);
  double az = fabs(z);
  double l;
  if(x == 0 && y == 0 && z == 0)
  {
    *nx = 0;
    *ny = 0;
    *nz = 0;
    return;
  }
  if(ax < ay)
  {
    if(ax < az)
    {                           /* Use X axis */
      l = sqrt(z*z + y*y);
      *nx = 0;
      *ny = z/l;
      *nz = -y/l;
      return;
    }
  }
  else
  {
    if(ay < az)
    {                           /* Use Y axis */
      l = sqrt(z*z + x*x);
      *nx = z/l;
      *ny = 0;
      *nz = -x/l;
      return;
    }
  }
  /* Use Z axis */
  l = sqrt(y*y + x*x);
  *nx = y/l;
  *ny = -x/l;
  *nz = 0;
} /* normal_vec */

/*******************************************************************************
 * solve_2nd_order: second order equation solve: A*t^2 + B*t + C = 0
 * solve_2nd_order(&t1, NULL, A,B,C)
 *   returns 0 if no solution was found, or set 't1' to the smallest positive
 *   solution.
 * solve_2nd_order(&t1, &t2, A,B,C)
 *   same as with &t2=NULL, but also returns the second solution.
 * EXAMPLE usage for intersection of a trajectory with a plane in gravitation
 * field (gx,gy,gz):
 * The neutron starts at point r=(x,y,z) with velocityv=(vx vy vz). The plane
 * has a normal vector n=(nx,ny,nz) and contains the point W=(wx,wy,wz).
 * The problem consists in solving the 2nd order equation:
 *      1/2.n.g.t^2 + n.v.t + n.(r-W) = 0
 * so that A = 0.5 n.g; B = n.v; C = n.(r-W);
 * Without acceleration, t=-n.(r-W)/n.v
 ******************************************************************************/
int solve_2nd_order_old(double *t1, double *t2,
                  double A,  double B,  double C)
{
  int ret=0;

  if (!t1) return 0;
  *t1 = 0;
  if (t2) *t2=0;

  if (fabs(A) < 1E-10) /* approximate to linear equation: A ~ 0 */
  {
    if (B) {  *t1 = -C/B; ret=1; if (t2) *t2=*t1; }
    /* else no intersection: A=B=0 ret=0 */
  }
  else
  {
    double D;
    D = B*B - 4*A*C;
    if (D >= 0) /* Delta > 0: two solutions */
    {
      double sD, dt1, dt2;
      sD = sqrt(D);
      dt1 = (-B + sD)/2/A;
      dt2 = (-B - sD)/2/A;
      /* we identify very small values with zero */
      if (fabs(dt1) < 1e-10) dt1=0.0;
      if (fabs(dt2) < 1e-10) dt2=0.0;

      /* now we choose the smallest positive solution */
      if      (dt1<=0.0 && dt2>0.0) ret=2; /* dt2 positive */
      else if (dt2<=0.0 && dt1>0.0) ret=1; /* dt1 positive */
      else if (dt1> 0.0 && dt2>0.0)
      {  if (dt1 < dt2) ret=1; else ret=2; } /* all positive: min(dt1,dt2) */
      /* else two solutions are negative. ret=-1 */
      if (ret==1) { *t1 = dt1;  if (t2) *t2=dt2; }
      else        { *t1 = dt2;  if (t2) *t2=dt1; }
      ret=2;  /* found 2 solutions and t1 is the positive one */
    } /* else Delta <0: no intersection. ret=0 */
  }
  return(ret);
} /* solve_2nd_order */

int solve_2nd_order(double *t0, double *t1, double A, double B, double C){
  int retval=0;
  double sign=copysign(1.0,B);
  double dt0,dt1;

  dt0=0;
  dt1=0;
  if(t1){ *t1=0;}

  /*protect against rounding errors by locally equating DBL_EPSILON with 0*/
  if (fabs(A)<DBL_EPSILON){
    A=0;
  }
  if (fabs(B)<DBL_EPSILON){
    B=0;
  }
  if (fabs(C)<DBL_EPSILON){
    C=0;
  }

  /*check if coefficient are sane*/
  if( A==0  && B==0){
    retval=0;
  }else{
    if(A==0){
      /*equation is linear*/
      dt0=-C/B;
      retval=1;
    }else if (C==0){
      /*one root is 0*/
      if(sign<0){
        dt0=0;dt1=-B/A;
      }else{
        dt0=-B/A;dt1=0;
      }
      retval=2;
    }else{
      /*a regular 2nd order eq. Also works out fine for B==0.*/
      double D;
      D=B*B-4*A*C;
      if (D>=0){
        dt0=(-B - sign*sqrt(B*B-4*A*C))/(2*A);
        dt1=C/(A*dt0);
        retval=2;
      }else{
        /*no real roots*/
        retval=0;
      }
    }
    /*sort the solutions*/
    if (retval==1){
      /*put both solutions in t0 and t1*/
      *t0=dt0;
      if(t1) *t1=dt1;
    }else{
      /*we have two solutions*/
      /*swap if both are positive and t1 smaller than t0 or t1 the only positive*/
      int swap=0;
      if(dt1>0 && ( dt1<dt0 || dt0<=0) ){
        swap=1;
      }
      if (swap){
        *t0=dt1;
        if(t1) *t1=dt0;
      }else{
        *t0=dt0;
        if(t1) *t1=dt0;
      }
    }

  }
  return retval;

} /*solve_2nd_order_improved*/


/*******************************************************************************
 * randvec_target_circle: Choose random direction towards target at (x,y,z)
 * with given radius.
 * If radius is zero, choose random direction in full 4PI, no target.
 ******************************************************************************/
void _randvec_target_circle(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double radius,
        _class_particle* _particle)
{
  double l2, phi, theta, nx, ny, nz, xt, yt, zt, xu, yu, zu;

  if(radius == 0.0)
  {
    /* No target, choose uniformly a direction in full 4PI solid angle. */
    theta = acos(1 - rand0max(2));
    phi = rand0max(2 * PI);
    if(solid_angle)
      *solid_angle = 4*PI;
    nx = 1;
    ny = 0;
    nz = 0;
    yi = sqrt(xi*xi+yi*yi+zi*zi);
    zi = 0;
    xi = 0;
  }
  else
  {
    double costheta0;
    l2 = xi*xi + yi*yi + zi*zi; /* sqr Distance to target. */
    costheta0 = sqrt(l2/(radius*radius+l2));
    if (radius < 0) costheta0 *= -1;
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
        *solid_angle = 2*PI*(1 - costheta0);
    }

    /* Now choose point uniformly on circle surface within angle theta0 */
    theta = acos (1 - rand0max(1 - costheta0)); /* radius on circle */
    phi = rand0max(2 * PI); /* rotation on circle at given radius */
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around a
       perpendicular axis u=i x n and then angle phi around i. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, xu, yu, zu);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xi, yi, zi);
}
/* randvec_target_circle */

/*******************************************************************************
 * randvec_target_rect_angular: Choose random direction towards target at
 * (xi,yi,zi) with given ANGULAR dimension height x width. height=phi_x=[0,PI],
 * width=phi_y=[0,2*PI] (radians)
 * If height or width is zero, choose random direction in full 4PI, no target.
 *******************************************************************************/
void _randvec_target_rect_angular(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi, double width, double height, Rotation A,
        _class_particle* _particle)
{
  double theta, phi, nx, ny, nz, xt, yt, zt, xu, yu, zu;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle, xi, yi, zi, 0);
    return;
  }
  else
  {
    if(solid_angle)
    {
      /* Compute solid angle of target as seen from origin. */
      *solid_angle = 2*fabs(width*sin(height/2));
    }

    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Now choose point uniformly on the unit sphere segment with angle theta/phi */
    phi   = width*randpm1()/2.0;
    theta = asin(randpm1()*sin(height/2.0));
    /* Now, to obtain the desired vector rotate (xi,yi,zi) angle theta around
       n, and then phi around u. */
    if(xi == 0 && zi == 0)
    {
      nx = 1;
      ny = 0;
      nz = 0;
    }
    else
    {
      nx = -zi;
      nz = xi;
      ny = 0;
    }
  }

  /* [xyz]u = [xyz]i x n[xyz] (usually vertical) */
  vec_prod(xu,  yu,  zu, xi, yi, zi,        nx, ny, nz);
  /* [xyz]t = [xyz]i rotated theta around [xyz]u */
  rotate  (xt,  yt,  zt, xi, yi, zi, theta, nx, ny, nz);
  /* [xyz]o = [xyz]t rotated phi around n[xyz] */
  rotate (*xo, *yo, *zo, xt, yt, zt, phi, xu,  yu,  zu);

  /* Go back to local coordinate system */
  tmp = coords_set(*xo, *yo, *zo);
  tmp = rot_apply(A, tmp);
  coords_get(tmp, &*xo, &*yo, &*zo);
}
/* randvec_target_rect_angular */

/*******************************************************************************
 * randvec_target_rect_real: Choose random direction towards target at (xi,yi,zi)
 * with given dimension height x width (in meters !).
 *
 * Local emission coordinate is taken into account and corrected for 'order' times.
 * (See remarks posted to mcstas-users by George Apostolopoulus <gapost@ipta.demokritos.gr>)
 *
 * If height or width is zero, choose random direction in full 4PI, no target.
 *
 * Traditionally, this routine had the name randvec_target_rect - this is now a
 * a define (see mcstas-r.h) pointing here. If you use the old rouine, you are NOT
 * taking the local emmission coordinate into account.
*******************************************************************************/
void _randvec_target_rect_real(double *xo, double *yo, double *zo, double *solid_angle,
        double xi, double yi, double zi,
        double width, double height, Rotation A,
        double lx, double ly, double lz, int order,
        _class_particle* _particle)
{
  double dx, dy, dist, dist_p, nx, ny, nz, mx, my, mz, n_norm, m_norm;
  double cos_theta;
  Coords tmp;
  Rotation Ainverse;

  rot_transpose(A, Ainverse);

  if(height == 0.0 || width == 0.0)
  {
    randvec_target_circle(xo, yo, zo, solid_angle,
               xi, yi, zi, 0);
    return;
  }
  else
  {
    /* Now choose point uniformly on rectangle within width x height */
    dx = width*randpm1()/2.0;
    dy = height*randpm1()/2.0;

    /* Determine distance to target plane*/
    dist = sqrt(xi*xi + yi*yi + zi*zi);
    /* Go to global coordinate system */

    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(Ainverse, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    /* Determine vector normal to trajectory axis (z) and gravity [0 1 0] */
    vec_prod(nx, ny, nz, xi, yi, zi, 0, 1, 0);

    /* This now defines the x-axis, normalize: */
    n_norm=sqrt(nx*nx + ny*ny + nz*nz);
    nx = nx/n_norm;
    ny = ny/n_norm;
    nz = nz/n_norm;

    /* Now, determine our y-axis (vertical in many cases...) */
    vec_prod(mx, my, mz, xi, yi, zi, nx, ny, nz);
    m_norm=sqrt(mx*mx + my*my + mz*mz);
    mx = mx/m_norm;
    my = my/m_norm;
    mz = mz/m_norm;

    /* Our output, random vector can now be defined by linear combination: */

    *xo = xi + dx * nx + dy * mx;
    *yo = yi + dx * ny + dy * my;
    *zo = zi + dx * nz + dy * mz;

    /* Go back to local coordinate system */
    tmp = coords_set(*xo, *yo, *zo);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &*xo, &*yo, &*zo);

    /* Go back to local coordinate system */
    tmp = coords_set(xi, yi, zi);
    tmp = rot_apply(A, tmp);
    coords_get(tmp, &xi, &yi, &zi);

    if (solid_angle) {
      /* Calculate vector from local point to remote random point */
      lx = *xo - lx;
      ly = *yo - ly;
      lz = *zo - lz;
      dist_p = sqrt(lx*lx + ly*ly + lz*lz);

      /* Adjust the 'solid angle' */
      /* 1/r^2 to the chosen point times cos(\theta) between the normal */
      /* vector of the target rectangle and direction vector of the chosen point. */
      cos_theta = (xi * lx + yi * ly + zi * lz) / (dist * dist_p);
      *solid_angle = width * height / (dist_p * dist_p);
      int counter;
      for (counter = 0; counter < order; counter++) {
        *solid_angle = *solid_angle * cos_theta;
      }
    }
  }
}
/* randvec_target_rect_real */


/* SECTION: random numbers ==================================================

  How to add a new RNG:

  - Use an rng with a manegable state vector, e.g. of lengt 4 or 7. The state
  will sit on the particle struct as a "randstate_t state[RANDSTATE_LEN]"
  - If the rng has a long state (as MT), set an empty "srandom" and initialize
  it explicitly using the appropriate define (RNG_ALG)
  - Add a seed and a random function (the transforms will be reused)
  - Write the proper defines in mccode-r.h, e.g. randstate_t and RANDSTATE_LEN,
  srandom and random.
  - Compile using -DRNG_ALG=<selector int value>

============================================================================= */


/* "Mersenne Twister", by Makoto Matsumoto and Takuji Nishimura. */
/* See http://www.math.keio.ac.jp/~matumoto/emt.html for original source. */
/*
   A C-program for MT19937, with initialization improved 2002/1/26.
   Coded by Takuji Nishimura and Makoto Matsumoto.

   Before using, initialize the state by using mt_srandom(seed)
   or init_by_array(init_key, key_length).

   Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

     1. Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

     2. Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.

     3. The names of its contributors may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


   Any feedback is very welcome.
   http://www.math.keio.ac.jp/matumoto/emt.html
   email: matumoto@math.keio.ac.jp
*/
#include <stdio.h>
#include <stdint.h>   // for uint32_t
#include <stddef.h>   // for size_t

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfU   /* constant vector a */
#define UPPER_MASK 0x80000000U /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffU /* least significant r bits */

static uint32_t mt[N]; /* the array for the state vector  */
static int mti = N + 1; /* mti==N+1 means mt[N] is not initialized */

// Required for compatibility with common RNG interface (e.g., kiss/mt polymorphism)
void mt_srandom_empty(void) {}

// Initializes mt[N] with a seed
void mt_srandom(uint32_t seed) {
    mt[0] = seed;
    for (mti = 1; mti < N; mti++) {
        mt[mti] = 1812433253U * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti;
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffU;
        /* for >32 bit machines */
    }
}
/* Initialize by an array with array-length.
   Init_key is the array for initializing keys.
   key_length is its length. */
void init_by_array(uint32_t init_key[], size_t key_length) {
    size_t i = 1, j = 0, k;
    mt_srandom(19650218U);
    k = (N > key_length ? N : key_length);
    for (; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525U))
              + init_key[j] + (uint32_t)j;
        mt[i] &= 0xffffffffU;
        i++; j++;
        if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
        if (j >= key_length) j = 0;
    }
    for (k = N - 1; k; k--) {
        mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941U))
              - (uint32_t)i;
        mt[i] &= 0xffffffffU;
        i++;
        if (i >= N) { mt[0] = mt[N - 1]; i = 1; }
    }
    mt[0] = 0x80000000U; /* MSB is 1; ensuring non-zero initial array */
}

// Generates a random number on [0, 0xffffffff]-interval
uint32_t mt_random(void) {
    uint32_t y;
    static const uint32_t mag01[2] = { 0x0U, MATRIX_A };
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= N) { /* generate N words at one time */
        int kk;

        if (mti == N + 1)   /* if mt_srandom() has not been called, */ 
            mt_srandom(5489U);  /* a default initial seed is used */

        for (kk = 0; kk < N - M; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1U];
        }
        for (; kk < N - 1; kk++) {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1U];
        }
        y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
        mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1U];

        mti = 0;
    }

    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680U;
    y ^= (y << 15) & 0xefc60000U;
    y ^= (y >> 18);

    return y;
}
#undef N
#undef M
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK
/* End of "Mersenne Twister". */


/*
KISS

 From: http://www.helsbreth.org/random/rng_kiss.html
 Scott Nelson 1999

 Based on Marsaglia's KISS or (KISS+SWB) <http://www.cs.yorku.ca/~oz/marsaglia-
rng.html>

 KISS - Keep it Simple Stupid PRNG

 the idea is to use simple, fast, individually promising
 generators to get a composite that will be fast, easy to code
 have a very long period and pass all the tests put to it.
 The three components of KISS are
        x(n)=a*x(n-1)+1 mod 2^32
        y(n)=y(n-1)(I+L^13)(I+R^17)(I+L^5),
        z(n)=2*z(n-1)+z(n-2) +carry mod 2^32
 The y's are a shift register sequence on 32bit binary vectors
 period 2^32-1;
 The z's are a simple multiply-with-carry sequence with period
 2^63+2^32-1.  The period of KISS is thus
      2^32*(2^32-1)*(2^63+2^32-1) > 2^127

 In 2025 adapted for consistent 64-bit behavior across platforms.
*/

/* the KISS state is stored as a vector of 7 uint64_t        */
/*   0  1  2  3  4      5  6   */
/* [ x, y, z, w, carry, k, m ] */

uint64_t *kiss_srandom(uint64_t state[7], uint64_t seed) {
    if (seed == 0) seed = 1ull;
    state[0] = seed | 1ull; // x
    state[1] = seed | 2ull; // y
    state[2] = seed | 4ull; // z
    state[3] = seed | 8ull; // w
    state[4] = 0ull;        // carry
    state[5] = 0ull;        // k
    state[6] = 0ull;        // m
    return state;
}

uint64_t kiss_random(uint64_t state[7]) {
    // Linear congruential generator
    state[0] = state[0] * 69069ull + 1ull;

    // Xorshift
    state[1] ^= state[1] << 13ull;
    state[1] ^= state[1] >> 17ull;
    state[1] ^= state[1] << 5ull;

    // Multiply-with-carry
    state[5] = (state[2] >> 2ull) + (state[3] >> 3ull) + (state[4] >> 2ull);
    state[6] = state[3] + state[3] + state[2] + state[4];
    state[2] = state[3];
    state[3] = state[6];
    state[4] = state[5] >> 62ull;  // Top bit of carry (adjusted for 64-bit)

    return state[0] + state[1] + state[3];
}
/* end of "KISS" rng */


/* FAST KISS in another implementation (Hundt) */

//////////////////////////////////////////////////////////////////////////////
// fast keep it simple stupid generator
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Thomas Mueller hash for initialization of rngs
// http://stackoverflow.com/questions/664014/
//        what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
//////////////////////////////////////////////////////////////////////////////
randstate_t _hash(randstate_t x) {
  x = ((x >> 16) ^ x) * (randstate_t)0x45d9f3b;
  x = ((x >> 16) ^ x) * (randstate_t)0x45d9f3b;
  x = ((x >> 16) ^ x);
  return x;
}


// SECTION: random number transforms ==========================================



// generate a random number from normal law
double _randnorm(randstate_t* state)
{
  static double v1, v2, s; /* removing static breaks comparison with McStas <= 2.5 */
  static int phase = 0;
  double X, u1, u2;

  if(phase == 0)
  {
    do
    {
      u1 = _rand01(state);
      u2 = _rand01(state);
      v1 = 2*u1 - 1;
      v2 = 2*u2 - 1;
      s = v1*v1 + v2*v2;
    } while(s >= 1 || s == 0);

    X = v1*sqrt(-2*log(s)/s);
  }
  else
  {
    X = v2*sqrt(-2*log(s)/s);
  }

  phase = 1 - phase;
  return X;
}
// another one
double _randnorm2(randstate_t* state) {
  double x, y, r;
  do {
      x = 2.0 * _rand01(state) - 1.0;
      y = 2.0 * _rand01(state) - 1.0;
      r = x*x + y*y;
  } while (r == 0.0 || r >= 1.0);
  return x * sqrt((-2.0 * log(r)) / r);
}

// Generate a random number from -1 to 1 with triangle distribution
double _randtriangle(randstate_t* state) {
	double randnum = _rand01(state);
	if (randnum>0.5) return(1-sqrt(2*(randnum-0.5)));
	else return(sqrt(2*randnum)-1);
}
double _rand01(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
  // TODO: can we mult instead of div?
	randnum /= (double) MC_RAND_MAX + 1;
	return randnum;
}
double _rand01_opague(void* opague_state) {
	randstate_t* state = (randstate_t*)opague_state;
	// Following lines exactly like in _rand01 just above (repeated to
	// avoid another layer of indirection):
	double randnum;
	randnum = (double) _random();
	// TODO: can we mult instead of div?
	randnum /= (double) MC_RAND_MAX + 1;
	return randnum;
}
// Return a random number between 1 and -1
double _randpm1(randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / 2;
	randnum -= 1;
	return randnum;
}
// Return a random number between 0 and max.
double _rand0max(double max, randstate_t* state) {
	double randnum;
	randnum = (double) _random();
	randnum /= ((double) MC_RAND_MAX + 1) / max;
	return randnum;
}
// Return a random number between min and max.
double _randminmax(double min, double max, randstate_t* state) {
	return _rand0max(max - min, state) + max;
}


/* SECTION: main and signal handlers ======================================== */

/*******************************************************************************
* mchelp: displays instrument executable help with possible options
*******************************************************************************/
static void
mchelp(char *pgmname)
{
  int i;

  fprintf(stderr, "%s (%s) instrument simulation, generated with " MCCODE_STRING " (" MCCODE_DATE ")\n", instrument_name, instrument_source);
  fprintf(stderr, "Usage: %s [options] [parm=value ...]\n", pgmname);
  fprintf(stderr,
"Options are:\n"
"  -s SEED   --seed=SEED      Set random seed (must be != 0)\n"
"  -n COUNT  --ncount=COUNT   Set number of particles to simulate.\n"
"  -d DIR    --dir=DIR        Put all data files in directory DIR.\n"
"  -a        --append         Append data files to those in directory DIR.\n"	  
"  -t        --trace          Enable trace of " MCCODE_PARTICLE "s through instrument.\n"
"                             (Use -t=2 or --trace=2 for modernised mcdisplay rendering)\n"
"  -g        --gravitation    Enable gravitation for all trajectories.\n"
"  --no-output-files          Do not write any data files.\n"
"  -h        --help           Show this help message.\n"
"  -i        --info           Detailed instrument information.\n"
"  --list-parameters          Print the instrument parameters to standard out\n"
"  -y        --yes            Assume default values for all parameters with a default\n"
"  --meta-list                Print names of components which defined metadata\n"
"  --meta-defined COMP[:NAME] Print component defined metadata names, or (0,1) if NAME provided\n"
"  --meta-type COMP:NAME      Print metadata format type specified in definition\n"
"  --meta-data COMP:NAME      Print the metadata text\n"
"  --source                   Show the instrument code which was compiled.\n"
#if defined(OPENACC) || defined(_OPENMP)
"\n"
"  --vecsize                  OpenACC vector-size (default: 128)\n"
"  --numgangs                 Number of OpenACC gangs (default: 7813)\n"
"  --gpu_innerloop            Maximum rays to process pr. OpenACC \n"
"                             kernel run (default: 2147483647)\n"
"\n"
#endif
"\n"
"  --bufsiz                   Monitor_nD list/buffer-size (default: 1000000)\n"
"  --format=FORMAT            Output data files using FORMAT="
   FLAVOR_UPPER
#ifdef USE_NEXUS
   " NEXUS\n"
"  --IDF                      Embed an xml-formatted IDF instrument definition\n"
"                             in the NeXus file (if existent in .)\n\n"
#else
"\n\n"
#endif
);
#ifdef USE_MPI
  fprintf(stderr,
  "This instrument has been compiled with MPI support.\n  Use 'mpirun %s [options] [parm=value ...]'.\n", pgmname);
#endif
#if defined(OPENACC) || defined(_OPENMP)
  fprintf(stderr,
  "This instrument has been compiled with NVIDIA GPU support through OpenACC.\n  Running on systems without such devices will lead to segfaults.\nFurter, fprintf, sprintf and printf have been removed from any component TRACE.\n");
#endif

  if(numipar > 0)
  {
    fprintf(stderr, "Instrument parameters are:\n");
    for(i = 0; i < numipar; i++)
      if (mcinputtable[i].val && strlen(mcinputtable[i].val))
        fprintf(stderr, "  %-16s(%s) [default='%s']\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name),
        mcinputtable[i].val);
      else
        fprintf(stderr, "  %-16s(%s)\n", mcinputtable[i].name,
        (*mcinputtypes[mcinputtable[i].type].parminfo)(mcinputtable[i].name));
  }

#ifndef NOSIGNALS
  fprintf(stderr, "Known signals are: "
#ifdef SIGUSR1
  "USR1 (status) "
#endif
#ifdef SIGUSR2
  "USR2 (save) "
#endif
#ifdef SIGBREAK
  "BREAK (save) "
#endif
#ifdef SIGTERM
  "TERM (save and exit)"
#endif
  "\n");
#endif /* !NOSIGNALS */
} /* mchelp */


/* mcshowhelp: show help and exit with 0 */
static void
mcshowhelp(char *pgmname)
{
  mchelp(pgmname);
  exit(0);
}

/* mcusage: display usage when error in input arguments and exit with 1 */
static void
mcusage(char *pgmname)
{
  fprintf(stderr, "Error: incorrect command line arguments\n");
  mchelp(pgmname);
  exit(1);
}

/* mcenabletrace: enable trace/mcdisplay or error if requires recompile */
static void
mcenabletrace(int mode)
{
 if(traceenabled) {
  mcdotrace = mode;
  #pragma acc update device ( mcdotrace )
 } else {
   if (mode>0) {
     fprintf(stderr,
	     "Error: trace not enabled (mcenabletrace)\n"
	     "Please re-run the " MCCODE_NAME " compiler "
	     "with the --trace option, or rerun the\n"
	     "C compiler with the MC_TRACE_ENABLED macro defined.\n");
     exit(1);
   }
 }
}

/*******************************************************************************
* mcreadparams: request parameters from the prompt (or use default)
*******************************************************************************/
void
mcreadparams(void)
{
  int i,j,status;
  static char buf[CHAR_BUF_LENGTH];
  char *p;
  int len;

  MPI_MASTER(printf("Instrument parameters for %s (%s)\n",
                    instrument_name, instrument_source));

  for(i = 0; mcinputtable[i].name != 0; i++)
  {
    do
    {
      MPI_MASTER(
                 if (mcinputtable[i].val && strlen(mcinputtable[i].val))
                   printf("Set value of instrument parameter %s (%s) [default='%s']:\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name), mcinputtable[i].val);
                 else
                   printf("Set value of instrument parameter %s (%s):\n",
                          mcinputtable[i].name,
                          (*mcinputtypes[mcinputtable[i].type].parminfo)
                          (mcinputtable[i].name));
                 fflush(stdout);
                 );
#ifdef USE_MPI
      if(mpi_node_rank == mpi_node_root)
        {
          p = fgets(buf, CHAR_BUF_LENGTH, stdin);
          if(p == NULL)
            {
              fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
              exit(1);
            }
        }
      else
        p = buf;
      MPI_Bcast(buf, CHAR_BUF_LENGTH, MPI_CHAR, mpi_node_root, MPI_COMM_WORLD);
#else /* !USE_MPI */
      p = fgets(buf, CHAR_BUF_LENGTH, stdin);
      if(p == NULL)
        {
          fprintf(stderr, "Error: empty input for paramater %s (mcreadparams)\n", mcinputtable[i].name);
          exit(1);
        }
#endif /* USE_MPI */
      len = strlen(buf);
      if (!len || (len == 1 && (buf[0] == '\n' || buf[0] == '\r')))
      {
        if (mcinputtable[i].val && strlen(mcinputtable[i].val)) {
          strncpy(buf, mcinputtable[i].val, CHAR_BUF_LENGTH);  /* use default value */
          len = strlen(buf);
        }
      }
      for(j = 0; j < 2; j++)
      {
        if(len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r'))
        {
          len--;
          buf[len] = '\0';
        }
      }

      status = (*mcinputtypes[mcinputtable[i].type].getparm)
                   (buf, mcinputtable[i].par);
      if(!status)
      {
        (*mcinputtypes[mcinputtable[i].type].error)(mcinputtable[i].name, buf);
        if (!mcinputtable[i].val || strlen(mcinputtable[i].val)) {
          fprintf(stderr, "       Change %s default value in instrument definition.\n", mcinputtable[i].name);
          exit(1);
        }
      }
    } while(!status);
  }
} /* mcreadparams */

/*******************************************************************************
* mcparseoptions: parse command line arguments (options, parameters)
*******************************************************************************/
void
mcparseoptions(int argc, char *argv[])
{
  int i, j;
  char *p;
  int paramset = 0, *paramsetarray;
  char *usedir=NULL;

  /* Add one to numipar to avoid allocating zero size memory block. */
  paramsetarray = (int*)malloc((numipar + 1)*sizeof(*paramsetarray));
  if(paramsetarray == NULL)
  {
    fprintf(stderr, "Error: insufficient memory (mcparseoptions)\n");
    exit(1);
  }
  for(j = 0; j < numipar; j++)
    {
      paramsetarray[j] = 0;
      if (mcinputtable[j].val != NULL && strlen(mcinputtable[j].val))
      {
        int  status;
        char buf[CHAR_BUF_LENGTH];
        strncpy(buf, mcinputtable[j].val, CHAR_BUF_LENGTH);
        status = (*mcinputtypes[mcinputtable[j].type].getparm)
                   (buf, mcinputtable[j].par);
        if(!status) fprintf(stderr, "Invalid '%s' default value %s in instrument definition (mcparseoptions)\n", mcinputtable[j].name, buf);
        else paramsetarray[j] = 1;
      } else {
        (*mcinputtypes[mcinputtable[j].type].getparm)
          (NULL, mcinputtable[j].par);
        paramsetarray[j] = 0;
      }
    }
  for(i = 1; i < argc; i++)
  {
    if(!strcmp("-s", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("-s", argv[i], 2))
      mcsetseed(&argv[i][2]);
    else if(!strcmp("--seed", argv[i]) && (i + 1) < argc)
      mcsetseed(argv[++i]);
    else if(!strncmp("--seed=", argv[i], 7))
      mcsetseed(&argv[i][7]);
    else if(!strcmp("-n", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("-n", argv[i], 2))
      mcsetn_arg(&argv[i][2]);
    else if(!strcmp("--ncount", argv[i]) && (i + 1) < argc)
      mcsetn_arg(argv[++i]);
    else if(!strncmp("--ncount=", argv[i], 9))
      mcsetn_arg(&argv[i][9]);
    else if(!strcmp("-d", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];  /* will create directory after parsing all arguments (end of this function) */
    else if(!strncmp("-d", argv[i], 2))
      usedir=&argv[i][2];
    else if(!strcmp("--dir", argv[i]) && (i + 1) < argc)
      usedir=argv[++i];
    else if(!strncmp("-a", argv[i], 2))
      mcappend = 1;
    else if(!strcmp("--append", argv[i]))
      mcappend = 1;
    else if(!strncmp("--dir=", argv[i], 6))
      usedir=&argv[i][6];
    else if(!strcmp("-h", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("--help", argv[i]) || !strcmp("--version", argv[i]))
      mcshowhelp(argv[0]);
    else if(!strcmp("-i", argv[i])) {
      mcformat=FLAVOR_UPPER;
      mcinfo();
    }
    else if(!strcmp("--info", argv[i]))
      mcinfo();
    else if (!strcmp("--list-parameters", argv[i]))
      mcparameterinfo();
    else if (!strcmp("--meta-list", argv[i]) && ((i+1) >= argc || argv[i+1][0] == '-')){
      //printf("Components with metadata defined:\n");
      exit(metadata_table_print_all_components(num_metadata, metadata_table) == 0);
    }
    else if (!strcmp("--meta-defined", argv[i]) && (i+1) < argc){
      exit(metadata_table_print_component_keys(num_metadata, metadata_table, argv[i+1]) == 0);
    }
    else if (!strcmp("--meta-type", argv[i]) && (i+1) < argc){
      char * literal_type = metadata_table_type(num_metadata, metadata_table, argv[i+1]);
      if (literal_type == NULL) exit(1);
      printf("%s\n", literal_type);
      exit(0);
    }
    else if (!strcmp("--meta-data", argv[i]) && (i+1) < argc){
      char * literal = metadata_table_literal(num_metadata, metadata_table, argv[i+1]);
      if (literal == NULL) exit(1);
      printf("%s\n", literal);
      exit(0);
    }
    else if(!strncmp("--trace=", argv[i], 8)) {
      mcenabletrace(atoi(&argv[i][8]));
    } else if(!strncmp("-t=", argv[i], 3) || !strcmp("--verbose", argv[i])) {
      mcenabletrace(atoi(&argv[i][3]));
    } else if(!strcmp("-t", argv[i]))
      mcenabletrace(1);
    else if(!strcmp("--trace", argv[i]) || !strcmp("--verbose", argv[i]))
      mcenabletrace(1);
    else if(!strcmp("--gravitation", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("-g", argv[i]))
      mcgravitation = 1;
    else if(!strcmp("--yes", argv[i]))
      mcusedefaults = 1;
    else if(!strcmp("-y", argv[i]))
      mcusedefaults = 1;
    else if(!strncmp("--format=", argv[i], 9)) {
      mcformat=&argv[i][9];
    }
    else if(!strcmp("--format", argv[i]) && (i + 1) < argc) {
      mcformat=argv[++i];
    }
#ifdef USE_NEXUS
    else if(!strcmp("--IDF", argv[i])) {
      mcnexus_embed_idf = 1;
    }
#endif
    else if(!strncmp("--vecsize=", argv[i], 10)) {
      vecsize=atoi(&argv[i][10]);
    }    
    else if(!strcmp("--vecsize", argv[i]) && (i + 1) < argc) {
      vecsize=atoi(argv[++i]);
    }
    else if(!strncmp("--bufsiz=", argv[i], 9)) {
      MONND_BUFSIZ=atoi(&argv[i][9]);
    }
    else if(!strcmp("--bufsiz", argv[i]) && (i + 1) < argc) {
      MONND_BUFSIZ=atoi(argv[++i]);
    }
    else if(!strncmp("--numgangs=", argv[i], 11)) {
      numgangs=atoi(&argv[i][11]);
    }
    else if(!strcmp("--numgangs", argv[i]) && (i + 1) < argc) {
      numgangs=atoi(argv[++i]);
    }
    else if(!strncmp("--gpu_innerloop=", argv[i], 16)) {
      gpu_innerloop=(long)strtod(&argv[i][16], NULL);
    }
    else if(!strcmp("--gpu_innerloop", argv[i]) && (i + 1) < argc) {
      gpu_innerloop=(long)strtod(argv[++i], NULL);
    }

    else if(!strcmp("--no-output-files", argv[i]))
      mcdisable_output_files = 1;
    else if(!strcmp("--source", argv[i])) {
      printf("/* Source code %s from %s: */\n"
        "/******************************************************************************/\n"
        "%s\n"
        "/******************************************************************************/\n"
        "/* End of source code %s from %s */\n",
        instrument_name, instrument_source, instrument_code,
        instrument_name, instrument_source);
      exit(1);
    }
    else if(argv[i][0] != '-' && (p = strchr(argv[i], '=')) != NULL)
    {
      *p++ = '\0';

      for(j = 0; j < numipar; j++)
        if(!strcmp(mcinputtable[j].name, argv[i]))
        {
          int status;
          status = (*mcinputtypes[mcinputtable[j].type].getparm)(p,
                        mcinputtable[j].par);
          if(!status || !strlen(p))
          {
            (*mcinputtypes[mcinputtable[j].type].error)
              (mcinputtable[j].name, p);
            exit(1);
          }
          paramsetarray[j] = 1;
          paramset = 1;
          break;
        }
      if(j == numipar)
      {                                /* Unrecognized parameter name */
        fprintf(stderr, "Error: unrecognized parameter %s (mcparseoptions)\n", argv[i]);
        exit(1);
      }
    }
    else if(argv[i][0] == '-') {
      fprintf(stderr, "Error: unrecognized option argument %s (mcparseoptions). Ignored.\n", argv[i++]);
    }
    else {
      fprintf(stderr, "Error: unrecognized argument %s (mcparseoptions). Aborting.\n", argv[i]);
      mcusage(argv[0]);
    }
  }
  if (mcusedefaults) {
    MPI_MASTER(
     printf("Using all default parameter values\n");
    );
    for(j = 0; j < numipar; j++) {
      int status;
      if(mcinputtable[j].val && strlen(mcinputtable[j].val)){
	status = (*mcinputtypes[mcinputtable[j].type].getparm)(mcinputtable[j].val,
                        mcinputtable[j].par);
	paramsetarray[j] = 1;
	paramset = 1;
      }
    }
  }
  if(!paramset)
    mcreadparams();                /* Prompt for parameters if not specified. */
  else
  {
    for(j = 0; j < numipar; j++)
      if(!paramsetarray[j])
      {
        fprintf(stderr, "Error: Instrument parameter %s left unset (mcparseoptions)\n",
                mcinputtable[j].name);
        exit(1);
      }
  }
  free(paramsetarray);
#ifdef USE_MPI
  if (mcdotrace) mpi_node_count=1; /* disable threading when in trace mode */
#endif
  if (usedir && strlen(usedir) && !mcdisable_output_files) mcuse_dir(usedir);
} /* mcparseoptions */

#ifndef NOSIGNALS
/*******************************************************************************
* sighandler: signal handler that makes simulation stop, and save results
*******************************************************************************/
void sighandler(int sig)
{
  /* MOD: E. Farhi, Sep 20th 2001: give more info */
  time_t t1, t0;
#define SIG_SAVE 0
#define SIG_TERM 1
#define SIG_STAT 2
#define SIG_ABRT 3

  printf("\n# " MCCODE_STRING ": [pid %i] Signal %i detected", getpid(), sig);
#ifdef USE_MPI
  printf(" [proc %i]", mpi_node_rank);
#endif
#if defined(SIGUSR1) && defined(SIGUSR2) && defined(SIGKILL)
  if (!strcmp(mcsig_message, "sighandler") && (sig != SIGUSR1) && (sig != SIGUSR2))
  {
    printf("\n# Fatal : unrecoverable loop ! Suicide (naughty boy).\n");
    kill(0, SIGKILL); /* kill myself if error occurs within sighandler: loops */
  }
#endif
  switch (sig) {
#ifdef SIGINT
    case SIGINT : printf(" SIGINT (interrupt from terminal, Ctrl-C)"); sig = SIG_TERM; break;
#endif
#ifdef SIGILL
    case SIGILL  : printf(" SIGILL (Illegal instruction)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGFPE
    case SIGFPE  : printf(" SIGFPE (Math Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGSEGV
    case SIGSEGV : printf(" SIGSEGV (Mem Error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGTERM
    case SIGTERM : printf(" SIGTERM (Termination)"); sig = SIG_TERM; break;
#endif
#ifdef SIGABRT
    case SIGABRT : printf(" SIGABRT (Abort)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGQUIT
    case SIGQUIT : printf(" SIGQUIT (Quit from terminal)"); sig = SIG_TERM; break;
#endif
#ifdef SIGTRAP
    case SIGTRAP : printf(" SIGTRAP (Trace trap)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGPIPE
    case SIGPIPE : printf(" SIGPIPE (Broken pipe)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGUSR1
    case SIGUSR1 : printf(" SIGUSR1 (Display info)"); sig = SIG_STAT; break;
#endif
#ifdef SIGUSR2
    case SIGUSR2 : printf(" SIGUSR2 (Save simulation)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGHUP
    case SIGHUP  : printf(" SIGHUP (Hangup/update)"); sig = SIG_SAVE; break;
#endif
#ifdef SIGBUS
    case SIGBUS  : printf(" SIGBUS (Bus error)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGURG
    case SIGURG  : printf(" SIGURG (Urgent socket condition)"); sig = SIG_ABRT; break;
#endif
#ifdef SIGBREAK
    case SIGBREAK: printf(" SIGBREAK (Break signal, Ctrl-Break)"); sig = SIG_SAVE; break;
#endif
    default : printf(" (look at signal list for signification)"); sig = SIG_ABRT; break;
  }
  printf("\n");
  printf("# Simulation: %s (%s) \n", instrument_name, instrument_source);
  printf("# Breakpoint: %s ", mcsig_message);
  if (strstr(mcsig_message, "Save") && (sig == SIG_SAVE))
    sig = SIG_STAT;
  SIG_MESSAGE("sighandler");
  if (mcget_ncount() == 0)
    printf("(0 %%)\n" );
  else
  {
    printf("%.2f %% (%10.1f/%10.1f)\n", 100.0*mcget_run_num()/mcget_ncount(), 1.0*mcget_run_num(), 1.0*mcget_ncount());
  }
  t0 = (time_t)mcstartdate;
  t1 = time(NULL);
  printf("# Date:      %s", ctime(&t1));
  printf("# Started:   %s", ctime(&t0));

  if (sig == SIG_STAT)
  {
    printf("# " MCCODE_STRING ": Resuming simulation (continue)\n");
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_SAVE)
  {
    printf("# " MCCODE_STRING ": Saving data and resume simulation (continue)\n");
    save(NULL);
    fflush(stdout);
    return;
  }
  else
  if (sig == SIG_TERM)
  {
    printf("# " MCCODE_STRING ": Finishing simulation (save results and exit)\n");
    finally();
    exit(0);
  }
  else
  {
    fflush(stdout);
    perror("# Last I/O Error");
    printf("# " MCCODE_STRING ": Simulation stop (abort).\n");
// This portion of the signal handling only works on UNIX
#if defined(__unix__) || defined(__APPLE__)
    signal(sig, SIG_DFL); /* force to use default sighandler now */
    kill(getpid(), sig);  /* and trigger it with the current signal */
#endif
    exit(-1);
  }
#undef SIG_SAVE
#undef SIG_TERM
#undef SIG_STAT
#undef SIG_ABRT

} /* sighandler */
#endif /* !NOSIGNALS */

#ifdef NEUTRONICS
/*Main neutronics function steers the McStas calls, initializes parameters etc */
/* Only called in case NEUTRONICS = TRUE */
void neutronics_main_(float *inx, float *iny, float *inz, float *invx, float *invy, float *invz, float *intime, float *insx, float *insy, float *insz, float *inw, float *outx, float *outy, float *outz, float *outvx, float *outvy, float *outvz, float *outtime, float *outsx, float *outsy, float *outsz, float *outwgt)
{

  extern double mcnx, mcny, mcnz, mcnvx, mcnvy, mcnvz;
  extern double mcnt, mcnsx, mcnsy, mcnsz, mcnp;

  /* External code governs iteration - McStas is iterated once per call to neutronics_main. I.e. below counter must be initiancated for each call to neutronics_main*/
  mcrun_num=0;

  time_t t;
  t = (time_t)mcstartdate;
  mcstartdate = t;  /* set start date before parsing options and creating sim file */
  init();

  /* *** parse options *** */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat=getenv(FLAVOR_UPPER "_FORMAT") ?
           getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;

  /* Set neutron state based on input from neutronics code */
  mcsetstate(*inx,*iny,*inz,*invx,*invy,*invz,*intime,*insx,*insy,*insz,*inw);

  /* main neutron event loop - runs only one iteration */

  //mcstas_raytrace(&mcncount); /* prior to McStas 1.12 */

  mcallowbackprop = 1; //avoid absorbtion from negative dt
  int argc=1;
  char *argv[0];
  int dummy = mccode_main(argc, argv);

  *outx =  mcnx;
  *outy =  mcny;
  *outz =  mcnz;
  *outvx =  mcnvx;
  *outvy =  mcnvy;
  *outvz =  mcnvz;
  *outtime =  mcnt;
  *outsx =  mcnsx;
  *outsy =  mcnsy;
  *outsz =  mcnsz;
  *outwgt =  mcnp;

  return;
} /* neutronics_main */

#endif /*NEUTRONICS*/

#endif /* !MCCODE_H */
/* End of file "mccode-r.c". */
/* End of file "mccode-r.c". */

/* embedding file "mcstas-r.c" */

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/mcstas-r.c
*
* %Identification
* Written by: KN
* Date:    Aug 29, 1997
* Release: McStas X.Y
* Version: $Revision$
*
* Runtime system for McStas.
* Embedded within instrument in runtime mode.
*
* Usage: Automatically embbeded in the c code whenever required.
*
* $Id$
*
*******************************************************************************/

#ifndef MCSTAS_R_H
#include "mcstas-r.h"
#endif
#ifdef DANSE
#include "mcstas-globals.h"
#endif

/*******************************************************************************
* The I/O format definitions and functions
*******************************************************************************/

/*the magnet stack*/
#ifdef MC_POL_COMPAT
void (*mcMagnetPrecession) (double, double, double, double, double, double,
    double, double*, double*, double*, double, Coords, Rotation)=NULL;
Coords   mcMagnetPos;
Rotation mcMagnetRot;
double*  mcMagnetData                = NULL;
/* mcMagneticField(x, y, z, t, Bx, By, Bz) */
int (*mcMagneticField) (double, double, double, double,
    double*, double*, double*, void *) = NULL;
#endif

#ifndef MCSTAS_H

/*******************************************************************************
* mcsetstate: transfer parameters into global McStas variables
*******************************************************************************/
_class_particle mcsetstate(double x, double y, double z, double vx, double vy, double vz,
			   double t, double sx, double sy, double sz, double p, int mcgravitation, void *mcMagnet, int mcallowbackprop)
{
  _class_particle mcneutron;

  mcneutron.x  = x;
  mcneutron.y  = y;
  mcneutron.z  = z;
  mcneutron.vx = vx;
  mcneutron.vy = vy;
  mcneutron.vz = vz;
  mcneutron.t  = t;
  mcneutron.sx = sx;
  mcneutron.sy = sy;
  mcneutron.sz = sz;
  mcneutron.p  = p;
  mcneutron.mcgravitation = mcgravitation;
  mcneutron.mcMagnet = mcMagnet;
  mcneutron.allow_backprop = mcallowbackprop;
  mcneutron._uid       = 0;
  mcneutron._index     = 1;
  mcneutron._absorbed  = 0;
  mcneutron._restore   = 0;
  mcneutron._scattered = 0;
  mcneutron.flag_nocoordschange = 0;
  
  /* init tmp-vars - FIXME are they used? */
  mcneutron._mctmp_a = mcneutron._mctmp_b =  mcneutron._mctmp_c = 0;
  // what about mcneutron._logic ?
  mcneutron._logic.dummy=1;
  // init uservars via cogen'd-function
  particle_uservar_init(&mcneutron);

  return(mcneutron);
} /* mcsetstate */

/*******************************************************************************
* mcgetstate: get neutron parameters from particle structure
*******************************************************************************/
_class_particle mcgetstate(_class_particle mcneutron, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *t,
               double *sx, double *sy, double *sz, double *p)
{
  *x  =  mcneutron.x;
  *y  =  mcneutron.y;
  *z  =  mcneutron.z;
  *vx =  mcneutron.vx;
  *vy =  mcneutron.vy;
  *vz =  mcneutron.vz;
  *t  =  mcneutron.t;
  *sx =  mcneutron.sx;
  *sy =  mcneutron.sy;
  *sz =  mcneutron.sz;
  *p  =  mcneutron.p;

  return(mcneutron);
} /* mcgetstate */


/*******************************************************************************
* mcgenstate: set default neutron parameters
*******************************************************************************/
// Moved to generated code
/* #pragma acc routine seq */
/* _class_particle mcgenstate(void) */
/* { */
/*   return(mcsetstate(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, mcgravitation, mcMagnet, mcallowbackprop)); */
/* } */

/*******************************************************************************
* mccoordschanges: old style rotation routine rot -> (x y z) ,(vx vy vz),(sx,sy,sz)
*******************************************************************************/
void
mccoordschanges(Coords a, Rotation t, double *x, double *y, double *z,
               double *vx, double *vy, double *vz, double *sx, double *sy, double *sz)
{
  Coords b, c;

  b.x = *x;
  b.y = *y;
  b.z = *z;
  c = rot_apply(t, b);
  b = coords_add(c, a);
  *x = b.x;
  *y = b.y;
  *z = b.z;

  if ( (vz && vy  && vx) && (*vz != 0.0 || *vx != 0.0 || *vy != 0.0) )
    mccoordschange_polarisation(t, vx, vy, vz);

  if ( (sz && sy  && sx) && (*sz != 0.0 || *sx != 0.0 || *sy != 0.0) )
    mccoordschange_polarisation(t, sx, sy, sz);

}

/* intersection routines ==================================================== */

/*******************************************************************************
* inside_rectangle: Check if (x,y) is inside rectangle (xwidth, yheight)
* return 0 if outside and 1 if inside
*******************************************************************************/
int inside_rectangle(double x, double y, double xwidth, double yheight)
{
  if (x>-xwidth/2 && x<xwidth/2 && y>-yheight/2 && y<yheight/2)
    return 1;
  else
    return 0;
}

/*******************************************************************************
 * box_intersect: compute time intersection with a box
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting times dt_in and dt_out
 * This function written by Stine Nyborg, 1999.
 *******************************************************************************/
int box_intersect(double *dt_in, double *dt_out,
                  double x, double y, double z,
                  double vx, double vy, double vz,
                  double dx, double dy, double dz)
{
  double x_in, y_in, z_in, tt, t[6], a, b;
  int i, count, s;

      /* Calculate intersection time for each of the six box surface planes
       *  If the box surface plane is not hit, the result is zero.*/

  if(vx != 0)
   {
    tt = -(dx/2 + x)/vx;
    y_in = y + tt*vy;
    z_in = z + tt*vz;
    if( y_in > -dy/2 && y_in < dy/2 && z_in > -dz/2 && z_in < dz/2)
      t[0] = tt;
    else
      t[0] = 0;

    tt = (dx/2 - x)/vx;
    y_in = y + tt*vy;
    z_in = z + tt*vz;
    if( y_in > -dy/2 && y_in < dy/2 && z_in > -dz/2 && z_in < dz/2)
      t[1] = tt;
    else
      t[1] = 0;
   }
  else
    t[0] = t[1] = 0;

  if(vy != 0)
   {
    tt = -(dy/2 + y)/vy;
    x_in = x + tt*vx;
    z_in = z + tt*vz;
    if( x_in > -dx/2 && x_in < dx/2 && z_in > -dz/2 && z_in < dz/2)
      t[2] = tt;
    else
      t[2] = 0;

    tt = (dy/2 - y)/vy;
    x_in = x + tt*vx;
    z_in = z + tt*vz;
    if( x_in > -dx/2 && x_in < dx/2 && z_in > -dz/2 && z_in < dz/2)
      t[3] = tt;
    else
      t[3] = 0;
   }
  else
    t[2] = t[3] = 0;

  if(vz != 0)
   {
    tt = -(dz/2 + z)/vz;
    x_in = x + tt*vx;
    y_in = y + tt*vy;
    if( x_in > -dx/2 && x_in < dx/2 && y_in > -dy/2 && y_in < dy/2)
      t[4] = tt;
    else
      t[4] = 0;

    tt = (dz/2 - z)/vz;
    x_in = x + tt*vx;
    y_in = y + tt*vy;
    if( x_in > -dx/2 && x_in < dx/2 && y_in > -dy/2 && y_in < dy/2)
      t[5] = tt;
    else
      t[5] = 0;
   }
  else
    t[4] = t[5] = 0;

  /* The intersection is evaluated and *dt_in and *dt_out are assigned */

  a = b = s = 0;
  count = 0;

  for( i = 0; i < 6; i = i + 1 )
    if( t[i] == 0 )
      s = s+1;
    else if( count == 0 )
    {
      a = t[i];
      count = 1;
    }
    else
    {
      b = t[i];
      count = 2;
    }

  if ( a == 0 && b == 0 )
    return 0;
  else if( a < b )
  {
    *dt_in = a;
    *dt_out = b;
    return 1;
  }
  else
  {
    *dt_in = b;
    *dt_out = a;
    return 1;
  }

} /* box_intersect */

/*******************************************************************************
 * cylinder_intersect: compute intersection with a cylinder
 * returns 0 when no intersection is found
 *      or 2/4/8/16 bits depending on intersection,
 *     and resulting times t0 and t1
 * Written by: EM,NB,ABA 4.2.98
  *******************************************************************************/
int cylinder_intersect(double *t0, double *t1, double x, double y, double z,
                   double vx, double vy, double vz, double r, double h)
{
  double D, t_in, t_out, y_in, y_out;
  int ret=1;

  D = (2*vx*x + 2*vz*z)*(2*vx*x + 2*vz*z)
    - 4*(vx*vx + vz*vz)*(x*x + z*z - r*r);

  if (D>=0)
  {
    if (vz*vz + vx*vx) {
      t_in  = (-(2*vz*z + 2*vx*x) - sqrt(D))/(2*(vz*vz + vx*vx));
      t_out = (-(2*vz*z + 2*vx*x) + sqrt(D))/(2*(vz*vz + vx*vx));
    } else if (vy) { /* trajectory parallel to cylinder axis */
      t_in = (-h/2-y)/vy;
      t_out = (h/2-y)/vy;
      if (t_in>t_out){
        double tmp=t_in;
        t_in=t_out;t_out=tmp;
      }
    } else return 0;
    y_in = vy*t_in + y;
    y_out =vy*t_out + y;

    if ( (y_in > h/2 && y_out > h/2) || (y_in < -h/2 && y_out < -h/2) )
      return 0;
    else
    {
      if (y_in > h/2)
        { t_in = ((h/2)-y)/vy; ret += 2; }
      else if (y_in < -h/2)
        { t_in = ((-h/2)-y)/vy; ret += 4; }
      if (y_out > h/2)
        { t_out = ((h/2)-y)/vy; ret += 8; }
      else if (y_out < -h/2)
        { t_out = ((-h/2)-y)/vy; ret += 16; }
    }
    *t0 = t_in;
    *t1 = t_out;
    return ret;
  }
  else
  {
    *t0 = *t1 = 0;
    return 0;
  }
} /* cylinder_intersect */


/*******************************************************************************
 * sphere_intersect: Calculate intersection between a line and a sphere.
 * returns 0 when no intersection is found
 *      or 1 in case of intersection with resulting times t0 and t1
 *******************************************************************************/
int sphere_intersect(double *t0, double *t1, double x, double y, double z,
                 double vx, double vy, double vz, double r)
{
  double A, B, C, D, v;

  v = sqrt(vx*vx + vy*vy + vz*vz);
  A = v*v;
  B = 2*(x*vx + y*vy + z*vz);
  C = x*x + y*y + z*z - r*r;
  D = B*B - 4*A*C;
  if(D < 0)
    return 0;
  D = sqrt(D);
  *t0 = (-B - D) / (2*A);
  *t1 = (-B + D) / (2*A);
  return 1;
} /* sphere_intersect */

/*******************************************************************************
 * plane_intersect: Calculate intersection between a plane and a line.
 * returns 0 when no intersection is found (i.e. line is parallel to the plane)
 * returns 1 or -1 when intersection time is positive and negative respectively
 *******************************************************************************/
int plane_intersect(double *t, double x, double y, double z,
                 double vx, double vy, double vz, double nx, double ny, double nz, double wx, double wy, double wz)
{
  double s;
  if (fabs(s=scalar_prod(nx,ny,nz,vx,vy,vz))<FLT_EPSILON) return 0;
  *t = - scalar_prod(nx,ny,nz,x-wx,y-wy,z-wz)/s;
  if (*t<0) return -1;
  else return 1;
} /* plane_intersect */

#endif /* !MCSTAS_H */
/* End of file "mcstas-r.c". */


/* *****************************************************************************
* Start of instrument 'templateNMX' generated code
***************************************************************************** */

#ifdef MC_TRACE_ENABLED
int traceenabled = 1;
#else
int traceenabled = 0;
#endif
#define MCSTAS "/home/willend/micromamba/envs/mcstas-dev/share/mcstas/resources/"
int   defaultmain         = 1;
char  instrument_name[]   = "templateNMX";
char  instrument_source[] = "templateNMX.instr";
char *instrument_exe      = NULL; /* will be set to argv[0] in main */
char  instrument_code[]   = "Instrument templateNMX source code templateNMX.instr is not embedded in this executable.\n  Use --source option when running mcstas.\n";

int main(int argc, char *argv[]){return mccode_main(argc, argv);}

/* *****************************************************************************
* instrument 'templateNMX' and components DECLARE
***************************************************************************** */

/* Instrument parameters: structure and a table for the initialisation
   (Used in e.g. inputparse and I/O function (e.g. detector_out) */

/* instrument SPLIT and GROUP control logic */
struct instrument_logic_struct {
  long Split_sample; /* this is the SPLIT counter decremented down to 0 */
  _class_particle Split_sample_particle; /* this is the particle to duplicate */
};

struct _instrument_struct {
  char   _name[256]; /* the name of this instrument e.g. 'templateNMX' */
/* Counters per component instance */
  double counter_AbsorbProp[7]; /* absorbed events in PROP routines */
  double counter_N[7], counter_P[7], counter_P2[7]; /* event counters after each component instance */
  _class_particle _trajectory[7]; /* current trajectory for STORE/RESTORE */
/* Components position table (absolute and relative coords) */
  Coords _position_relative[7]; /* positions of all components */
  Coords _position_absolute[7];
  int _counter;
  MCNUM REPS;
  char* reflections;
  struct instrument_logic_struct logic; /* instrument logic */
} _instrument_var;
struct _instrument_struct *instrument = & _instrument_var;

int numipar = 2;
struct mcinputtable_struct mcinputtable[] = {
  "REPS", &(_instrument_var.REPS), instr_type_double, "1", "",
  "reflections", &(_instrument_var.reflections), instr_type_string, "Rubredoxin.lau", "",
  NULL, NULL, instr_type_double, ""
};

struct metadata_table_struct metadata_table[] = {
  "", "", "", ""
};
int num_metadata = 0;

/* ************************************************************************** */
/*             SHARE user declarations for all components                     */
/* ************************************************************************** */

/* Shared user declarations for all components types 'Slit'. */
  void
  slit_print_if (int condition, char* level, char* message, char* component) {
    if (condition)
      fprintf (stderr, "Slit: %s: %s: %s\n", component, level, message);
  }
  void
  slit_error_if (int condition, char* message, char* component) {
    slit_print_if (condition, "Error", message, component);
    if (condition)
      exit (-1);
  }
  void
  slit_warning_if (int condition, char* message, char* component) {
    slit_print_if (condition, "Warning", message, component);
  }

/* Shared user declarations for all components types 'Single_crystal'. */
  /* used for reading data table from file */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright 1997-2002, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.h
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas 1.6
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions.
*
* This library may be used directly as an external library. It has no dependency
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#define READ_TABLE_LIB_H "$Revision$"

#define READ_TABLE_STEPTOL  0.04 /* tolerancy for constant step approx */

#ifndef MC_PATHSEP_C
#ifdef WIN32
#define MC_PATHSEP_C '\\'
#define MC_PATHSEP_S "\\"
#else  /* !WIN32 */
#ifdef MAC
#define MC_PATHSEP_C ':'
#define MC_PATHSEP_S ":"
#else  /* !MAC */
#define MC_PATHSEP_C '/'
#define MC_PATHSEP_S "/"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MC_PATHSEP_C */

#ifndef MCSTAS
#ifdef WIN32
#define MCSTAS "C:\\mcstas\\lib"
#else  /* !WIN32 */
#ifdef MAC
#define MCSTAS ":mcstas:lib" /* ToDo: What to put here? */
#else  /* !MAC */
#define MCSTAS "/usr/local/lib/mcstas"
#endif /* !MAC */
#endif /* !WIN32 */
#endif /* !MCSTAS */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _MSC_EXTENSIONS
#include <strings.h>
#else
#  include <string.h>
#  define strcasecmp _stricmp
#  define strncasecmp _strnicmp
#endif

  typedef struct struct_table
  {
    char    filename[1024];
    long    filesize;
    char   *header;  /* text header, e.g. comments */
    double *data;    /* vector { x[0], y[0], ... x[n-1], y[n-1]... } */
    double  min_x;   /* min value of first column */
    double  max_x;   /* max value of first column */
    double  step_x;  /* minimal step value of first column */
    long    rows;    /* number of rows in matrix block */
    long    columns; /* number of columns in matrix block */

    long    begin;   /* start fseek index of block */
    long    end;     /* stop  fseek index of block */
    long    block_number;  /* block index. 0 is catenation of all */
    long    array_length;  /* number of elements in the t_Table array */
    char    monotonic;     /* true when 1st column/vector data is monotonic */
    char    constantstep;  /* true when 1st column/vector data has constant step */
    char    method[32];    /* interpolation method: nearest, linear */
    char    quiet;   /*output level for messages to the console 0: print all messages, 1:only print some/including errors, 2: never print anything.*/
  } t_Table;

/*maximum number of rows to rebin a table = 1M*/
enum { mcread_table_rebin_maxsize = 1000000 };

typedef struct t_Read_table_file_item {
    int ref_count;
    t_Table *table_ref;
} t_Read_table_file_item;

typedef enum enum_Read_table_file_actions {STORE,FIND,GC}  t_Read_table_file_actions;

/* read_table-lib function prototypes */
/* ========================================================================= */

/* 'public' functions */
long     Table_Read              (t_Table *Table, char *File, long block_number);
long     Table_Read_Offset       (t_Table *Table, char *File, long block_number,
                                  long *offset, long max_lines);
long     Table_Read_Offset_Binary(t_Table *Table, char *File, char *Type,
                                  long *Offset, long Rows, long Columns);
long     Table_Rebin(t_Table *Table); /* rebin table with regular 1st column and interpolate all columns 2:end */
long     Table_Info (t_Table Table);
#pragma acc routine
double   Table_Index(t_Table Table,   long i, long j); /* get indexed value */
#pragma acc routine
double   Table_Value(t_Table Table, double X, long j); /* search X in 1st column and return interpolated value in j-column */
t_Table *Table_Read_Array(char *File, long *blocks);
void     Table_Free_Array(t_Table *Table);
long     Table_Info_Array(t_Table *Table);
int      Table_SetElement(t_Table *Table, long i, long j, double value);
long     Table_Init(t_Table *Table, long rows, long columns); /* create a Table */
#pragma acc routine
double   Table_Value2d(t_Table Table, double X, double Y);    /* same as Table_Index with non-integer indices and 2d interpolation */
MCDETECTOR Table_Write(t_Table Table, char*file, char*xl, char*yl, 
           double x1, double x2, double y1, double y2); /* write Table to disk */
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier);
t_Table *Table_File_List_find(char *name, int block, int offset);
int Table_File_List_gc(t_Table *tab);
void *Table_File_List_store(t_Table *tab);

#define Table_ParseHeader(header, ...) \
  Table_ParseHeader_backend(header,__VA_ARGS__,NULL);

char **Table_ParseHeader_backend(char *header, ...);
FILE *Open_File(char *name, const char *Mode, char *path);


/* private functions */
void Table_Free(t_Table *Table);
long Table_Read_Handle(t_Table *Table, FILE *fid, long block_number, long max_lines, char *name);
static void Table_Stat(t_Table *Table);
#pragma acc routine
double Table_Interp1d(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp1d_nearest(double x, double x1, double y1, double x2, double y2);
#pragma acc routine
double Table_Interp2d(double x, double y, double x1, double y1, double x2, double y2,
double z11, double z12, double z21, double z22);


#endif

/* end of read_table-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2009, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Library: share/read_table-lib.c
*
* %Identification
* Written by: EF
* Date: Aug 28, 2002
* Origin: ILL
* Release: McStas CVS_090504
* Version: $Revision$
*
* This file is to be imported by components that may read data from table files
* It handles some shared functions. Embedded within instrument in runtime mode.
*
* Usage: within SHARE
* %include "read_table-lib"
*
*******************************************************************************/

#ifndef READ_TABLE_LIB_H
#include "read_table-lib.h"
#endif

#ifndef READ_TABLE_LIB_C
#define READ_TABLE_LIB_C "$Revision$"


/*******************************************************************************
 * void *Table_File_List_Handler(action, item, item_modifier)
 *   ACTION: handle file entries in the read_table-lib file list. If a file is read - it is supposed to be
 *   stored in a list such that we can avoid reading the same file many times.
 *   input  action: FIND, STORE, GC. check if file exists in the list, store an item in the list, or check if it can be garbage collected.
 *   input item: depends on the action.
 *    FIND)  item is a filename, and item_modifier is the block number
 *    STORE) item is the Table to store - item_modifier is ignored
 *    GC)    item is the Table to check. If it has a ref_count >1 then this is simply decremented.
 *   return  depends on the action
 *    FIND)  return a reference to a table+ref_count item if found - NULL otherwise. I.e. NULL means the file has not been read before and must be read again.
 *    STORE) return NULL always
 *    GC)    return NULL if no garbage collection is needed, return an adress to the t_Table which should be garbage collected. 0x1 is returned if
 *           the item is not found in the list
*******************************************************************************/
void * Table_File_List_Handler(t_Read_table_file_actions action, void *item, void *item_modifier){

    /* logic here is Read_Table should include a call to FIND. If found the return value should just be used as
     * if the table had been read from disk. If not found then read the table and STORE.
     * Table_Free should include a call to GC. If this returns non-NULL then we should proceed with freeing the memory
     * associated with the table item - otherwise only decrement the reference counter since there are more references
     * that may need it.*/

    static t_Read_table_file_item read_table_file_list[1024];  
    static int read_table_file_count=0;

    t_Read_table_file_item *tr;
    switch(action){
        case FIND:
            /*interpret data item as a filename, if it is found return a pointer to the table and increment refcount.
             * if not found return the item itself*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                int i=*((int*) item_modifier);
                int j=*( ((int*) item_modifier)+1);
                if ( !strcmp(tr->table_ref->filename,(char *) item) &&
                        tr->table_ref->block_number==i && tr->table_ref->begin==j ){
                    tr->ref_count++;
                    return (void *) tr;
                }
                tr++;
            }
            return NULL;
        case STORE:
            /*find an available slot and store references to table there*/
            tr=&(read_table_file_list[read_table_file_count++]);
            tr->table_ref = ((t_Table *) item);
            tr->ref_count++;
            return NULL;
        case GC:
            /* Should this item be garbage collected (freed) - if so scratch the entry and return the address of the item - 
             * else decrement ref_count and return NULL.
             * A non-NULL return expects the item to actually be freed afterwards.*/
            tr=read_table_file_list;
            while ( tr->table_ref!=NULL ){
                if ( tr->table_ref->data ==((t_Table *)item)->data && 
                        tr->table_ref->block_number == ((t_Table *)item)->block_number){
                    /*matching item found*/
                    if (tr->ref_count>1){
                        /*the item is found and no garbage collection needed*/
                        tr->ref_count--;
                        return NULL;
                    }else{
                        /* The item is found and the reference counter is 1.
                         * This means we should garbage collect. Move remaining list items up one slot,
                         * and return the table for garbage collection by caller*/
                        while (tr->table_ref!=NULL){
                            *tr=*(tr+1);
                            tr++;
                        }
                        read_table_file_count--;
                        return (t_Table *) item;
                    }
                }
                tr++;
            }
            /* item not found, and so should be garbage collected. This could be the case if freeing a
             * Table that has been constructed from code - not read from file. Return 0x1 to flag it for
             * collection.*/
            return (void *) 0x1 ;
    }
    /* If we arrive here, nothing worked, return NULL */
    return NULL;
}

/* Access functions to the handler*/

/********************************************
 * t_Table *Table_File_List_find(char *name, int block, int offset)
 * input name: filename to search for in the file list
 * input block: data block in the file as each file may contain more than 1 data block.
 * return a ref. to a table if it is found (you may use this pointer and skip reading the file), NULL otherwise (i.e. go ahead and read the file)
*********************************************/
t_Table *Table_File_List_find(char *name, int block, int offset){
    int vars[2]={block,offset};
    t_Read_table_file_item *item = Table_File_List_Handler(FIND,name, vars);
    if (item == NULL){
        return NULL;
    }else{
        return item->table_ref;
    }
}
/********************************************
 * int Table_File_List_gc(t_Table *tab)
 * input tab: the table to check for references.
 * return 0: no garbage collection needed
 *        1: Table's data and header (at least) should be freed.
*********************************************/
int Table_File_List_gc(t_Table *tab){
    void *rval=Table_File_List_Handler(GC,tab,0);
    if (rval==NULL) return 0;
    else return 1;
}


/*****************************************************************************
 * void *Table_File_List_store(t_Table *tab)
 * input tab: pointer to table to store.
 * return None. 
*******************************************************************************/
void *Table_File_List_store(t_Table *tab){
    return Table_File_List_Handler(STORE,tab,0);
}


/*******************************************************************************
* FILE *Open_File(char *name, char *Mode, char *path)
*   ACTION: search for a file and open it. Optionally return the opened path.
*   input   name:  file name from which table should be extracted
*           mode: "r", "w", "a" or any valid fopen mode
*           path:  NULL or a pointer to at least 1024 allocated chars
*   return  initialized file handle or NULL in case of error
*******************************************************************************/

  FILE *Open_File(char *File, const char *Mode, char *Path)
  {
    char path[1024];
    FILE *hfile = NULL;
    
    if (!File || File[0]=='\0')                     return(NULL);
    if (!strcmp(File,"NULL") || !strcmp(File,"0"))  return(NULL);
    
    /* search in current or full path */
    strncpy(path, File, 1024);
    hfile = fopen(path, Mode);
    if(!hfile)
    {
      char dir[1024];

      if (!hfile && instrument_source[0] != '\0' && strlen(instrument_source)) /* search in instrument source location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_source, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_source;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_source, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile && instrument_exe[0] != '\0' && strlen(instrument_exe)) /* search in PWD instrument executable location */
      {
        char *path_pos   = NULL;
        /* extract path: searches for last file separator */
        path_pos    = strrchr(instrument_exe, MC_PATHSEP_C);  /* last PATHSEP */
        if (path_pos) {
          long path_length = path_pos +1 - instrument_exe;  /* from start to path+sep */
          if (path_length) {
            strncpy(dir, instrument_exe, path_length);
            dir[path_length] = '\0';
            snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
            hfile = fopen(path, Mode);
          }
        }
      }
      if (!hfile) /* search in HOME or . */
      {
        strcpy(dir, getenv("HOME") ? getenv("HOME") : ".");
        snprintf(path, 1024, "%s%c%s", dir, MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MCSTAS/data */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "data", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if (!hfile) /* search in MVCSTAS/contrib */
      {
        strcpy(dir, getenv(FLAVOR_UPPER) ? getenv(FLAVOR_UPPER) : MCSTAS);
        snprintf(path, 1024, "%s%c%s%c%s", dir, MC_PATHSEP_C, "contrib", MC_PATHSEP_C, File);
        hfile = fopen(path, Mode);
      }
      if(!hfile)
      {
        // fprintf(stderr, "Warning: Could not open input file '%s' (Open_File)\n", File);
        return (NULL);
      }
    }
    if (Path) strncpy(Path, path, 1024);
    return(hfile);
  } /* end Open_File */

/*******************************************************************************
* long Read_Table(t_Table *Table, char *name, int block_number)
*   ACTION: read a single Table from a text file
*   input   Table: pointer to a t_Table structure
*           name:  file name from which table should be extracted
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* File is opened, read and closed
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebinned with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read(t_Table *Table, char *File, long block_number)
  { /* reads all or a single data block from 'file' and returns a Table structure  */
    return(Table_Read_Offset(Table, File, block_number, NULL, 0));
  } /* end Table_Read */

/*******************************************************************************
* long Table_Read_Offset(t_Table *Table, char *name, int block_number, long *offset
*                        long max_rows)
*   ACTION: read a single Table from a text file, starting at offset
*     Same as Table_Read(..) except:
*   input   offset:    pointer to an offset (*offset should be 0 at start)
*           max_rows: max number of data rows to read from file (0 means all)
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset(t_Table *Table, char *File,
                         long block_number, long *offset,
                         long max_rows)
  { /* reads all/a data block in 'file' and returns a Table structure  */
    FILE *hfile;
    long  nelements=0;
    long  begin=0;
    long  filesize=0;
    char  name[1024];
    char  path[1024];
    struct stat stfile;

    /*Need to be able to store the pointer*/
    if (!Table) return(-1);

    /*TK: Valgrind flags it as usage of uninitialised variable: */
    Table->quiet = 0;

    //if (offset && *offset) snprintf(name, 1024, "%s@%li", File, *offset);
    //else                   
    strncpy(name, File, 1024);
    if(offset && *offset){
        begin=*offset;
    }
    /* Check if the table has already been read from file.
     * If so just reuse the table, if not (this is flagged by returning NULL
     * set up a new table and read the data into it */
    t_Table *tab_p= Table_File_List_find(name,block_number,begin);
    if ( tab_p!=NULL ){
        /*table was found in the Table_File_List*/
        *Table=*tab_p;
        MPI_MASTER(
            if(Table->quiet<1)
              printf("Reusing input file '%s' (Table_Read_Offset)\n", name);
            );
        return Table->rows*Table->columns;
    }

    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read_Offset)\n", path);
          );
    }
    
    /* read file state */
    stat(path,&stfile); filesize = stfile.st_size;
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    
    Table_Init(Table, 0, 0);

    /* read file content and set the Table */
    nelements = Table_Read_Handle(Table, hfile, block_number, max_rows, name);
    Table->begin = begin;
    Table->end   = ftell(hfile);
    Table->filesize = (filesize>0 ? filesize : 0);
    Table_Stat(Table);
    
    Table_File_List_store(Table);

    if (offset) *offset=Table->end;
    fclose(hfile);
    return(nelements);

  } /* end Table_Read_Offset */

/*******************************************************************************
* long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
*                               long *offset, long rows, long columns)
*   ACTION: read a single Table from a binary file, starting at offset
*     Same as Table_Read_Offset(..) except that it handles binary files.
*   input   type: may be "float"/NULL or "double"
*           offset: pointer to an offset (*offset should be 0 at start)
*           rows   : number of rows (0 means read all)
*           columns: number of columns
*   return  initialized single Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
*           updated *offset position (where end of reading occured)
*******************************************************************************/
  long Table_Read_Offset_Binary(t_Table *Table, char *File, char *type,
                                long *offset, long rows, long columns)
  { /* reads all/a data block in binary 'file' and returns a Table structure  */
    long    nelements, sizeofelement;
    long    filesize;
    FILE   *hfile;
    char    path[1024];
    struct stat stfile;
    double *data    = NULL;
    double *datatmp = NULL;
    long    i;
    long    begin;

    if (!Table) return(-1);

    Table_Init(Table, 0, 0);
    
    /* open the file */
    hfile = Open_File(File, "r", path);
    if (!hfile) return(-1);
    else {
      MPI_MASTER(
          if(Table->quiet<1)
            printf("Opening input file '%s' (Table_Read, Binary)\n", path);
      );
    }
    
    /* read file state */
    stat(File,&stfile);
    filesize = stfile.st_size;
    Table->filesize=filesize;
    
    /* read file content */
    if (type && !strcmp(type,"double")) sizeofelement = sizeof(double);
    else  sizeofelement = sizeof(float);
    if (offset && *offset) fseek(hfile, *offset, SEEK_SET);
    begin     = ftell(hfile);
    if (rows && filesize > sizeofelement*columns*rows)
      nelements = columns*rows;
    else nelements = (long)(filesize/sizeofelement);
    if (!nelements || filesize <= *offset) return(0);
    data    = (double*)malloc(nelements*sizeofelement);
    if (!data) {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: allocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    }
    nelements = fread(data, sizeofelement, nelements, hfile);

    if (!data || !nelements)
    {
      if(!(Table->quiet>1))
        fprintf(stderr,"Error: reading %ld elements from %s file '%s' (Table_Read_Offset_Binary)\n", nelements, type, File);
      exit(-1);
    }
    Table->begin   = begin;
    Table->end     = ftell(hfile);
    if (offset) *offset=Table->end;
    fclose(hfile);

    datatmp = (double*)realloc(data, (double)nelements*sizeofelement);
    if (!datatmp) {
      free(data);
      fprintf(stderr,"Error: reallocating %ld elements for %s file '%s'. Too big (Table_Read_Offset_Binary).\n", nelements, type, File);
      exit(-1);
    } else {
      data = datatmp;
    }
    /* copy file data into Table */
    if (type && !strcmp(type,"double")) Table->data = data;
    else {
      float  *s;
      double *dataf;
      s     = (float*)data;
      dataf = (double*)malloc(sizeof(double)*nelements);
      if (!dataf) {
	fprintf(stderr, "Could not allocate data block of size %ld\n", nelements);
	exit(-1);
      }
      for (i=0; i<nelements; i++)
        dataf[i]=s[i];
      free(data);
      Table->data = dataf;
    }
    strncpy(Table->filename, File, 1024);
    Table->rows    = nelements/columns;
    Table->columns = columns;
    Table->array_length = 1;
    Table->block_number = 1;

    Table_Stat(Table);

    return(nelements);
  } /* end Table_Read_Offset_Binary */

/*******************************************************************************
* long Table_Read_Handle(t_Table *Table, FILE *fid, int block_number, long max_rows, char *name)
*   ACTION: read a single Table from a text file handle (private)
*   input   Table:pointer to a t_Table structure
*           fid:  pointer to FILE handle
*           block_number: if the file does contain more than one
*                 data block, then indicates which one to get (from index 1)
*                 a 0 value means append/catenate all
*           max_rows: if non 0, only reads that number of lines
*   return  initialized single Table t_Table structure containing data, header, ...
*           modified Table t_Table structure containing data, header, ...
*           number of read elements (-1: error, 0:header only)
* The routine stores any line starting with '#', '%' and ';' into the header
* Other lines are interpreted as numerical data, and stored.
* Data block should be a rectangular matrix or vector.
* Data block may be rebined with Table_Rebin (also sort in ascending order)
*******************************************************************************/
  long Table_Read_Handle(t_Table *Table, FILE *hfile,
                         long block_number, long max_rows, char *name)
  { /* reads all/a data block from 'file' handle and returns a Table structure  */
    double *Data              = NULL;
    double *Datatmp           = NULL;
    char *Header              = NULL;
    char *Headertmp           = NULL;
    long  malloc_size         = CHAR_BUF_LENGTH;
    long  malloc_size_h       = 4096;
    long  Rows = 0,   Columns = 0;
    long  count_in_array      = 0;
    long  count_in_header     = 0;
    long  count_invalid       = 0;
    long  block_Current_index = 0;
    char  flag_End_row_loop   = 0;

    if (!Table) return(-1);
    Table_Init(Table, 0, 0);
    if (name && name[0]!='\0') strncpy(Table->filename, name, 1024);

    if(!hfile) {
       fprintf(stderr, "Error: File handle is NULL (Table_Read_Handle).\n");
       return (-1);
    }
    Header = (char*)  calloc(malloc_size_h, sizeof(char));
    Data   = (double*)calloc(malloc_size,   sizeof(double));
    if ((Header == NULL) || (Data == NULL)) {
       fprintf(stderr, "Error: Could not allocate Table and Header (Table_Read_Handle).\n");
       return (-1);
    }

    int flag_In_array = 0;
    do { /* while (!flag_End_row_loop) */
      char  *line=malloc(1024*CHAR_BUF_LENGTH*sizeof(char));
      long  back_pos=0;   /* ftell start of line */

      if (!line) {
	fprintf(stderr,"Could not allocate line buffer\n");
	exit(-1);
      }
      back_pos = ftell(hfile);
      if (fgets(line, 1024*CHAR_BUF_LENGTH, hfile) != NULL) { /* analyse line */
        /* first skip blank and tabulation characters */
        int i = strspn(line, " \t");

        /* handle comments: stored in header */
        if (NULL != strchr("#%;/", line[i]))
        { /* line is a comment */
          count_in_header += strlen(line);
          if (count_in_header >= malloc_size_h) {
            /* if succeed and in array : add (and realloc if necessary) */
            malloc_size_h = count_in_header+4096;
            char *Headertmp = (char*)realloc(Header, malloc_size_h*sizeof(char));
	    if(!Headertmp) {
	      free(Header);
	             fprintf(stderr, "Error: Could not reallocate Header (Table_Read_Handle).\n");
		     free(Header);
		     return (-1);
	    } else {
	      Header = Headertmp;
	    }
          }
          strncat(Header, line, 4096);
          flag_In_array=0;
          /* exit line and file if passed desired block */
          if (block_number > 0 && block_number == block_Current_index) {
            flag_End_row_loop = 1;
          }

          /* Continue with next line */
          continue;
        }
        if (strstr(line, "***"))
        {
          count_invalid++;
          /* Continue with next line */
          continue;
        }

        /* get the number of columns splitting line with strtok */
        char  *lexeme;
        char  flag_End_Line = 0;
        long  block_Num_Columns = 0;
        const char seps[] = " ,;\t\n\r";

        lexeme = strtok(line, seps);
        while (!flag_End_Line) {
          if ((lexeme != NULL) && (lexeme[0] != '\0')) {
            /* reading line: the token is not empty */
            double X;
            int    count=1;
            /* test if we have 'NaN','Inf' */
            if (!strncasecmp(lexeme,"NaN",3))
              X = 0;
            else if (!strncasecmp(lexeme,"Inf",3) || !strncasecmp(lexeme,"+Inf",4))
              X = FLT_MAX;
            else if (!strncasecmp(lexeme,"-Inf",4))
              X = -FLT_MAX;
            else
              count = sscanf(lexeme,"%lg",&X);
            if (count == 1) {
              /* reading line: the token is a number in the line */
              if (!flag_In_array) {
                /* reading num: not already in a block: starts a new data block */
                block_Current_index++;
                flag_In_array    = 1;
                block_Num_Columns= 0;
                if (block_number > 0) {
                  /* initialise a new data block */
                  Rows = 0;
                  count_in_array = 0;
                } /* else append */
              }
              /* reading num: all blocks or selected block */
              if (flag_In_array && (block_number == 0 ||
                  block_number == block_Current_index)) {
                /* starting block: already the desired number of rows ? */
                if (block_Num_Columns == 0 &&
                    max_rows > 0 && Rows >= max_rows) {
                  flag_End_Line      = 1;
                  flag_End_row_loop  = 1;
                  flag_In_array      = 0;
                  /* reposition to begining of line (ignore line) */
                  fseek(hfile, back_pos, SEEK_SET);
                } else { /* store into data array */
                  if (count_in_array >= malloc_size) {
                    /* realloc data buffer if necessary */
                    malloc_size = count_in_array*1.5;
                    Datatmp = (double*) realloc(Data, malloc_size*sizeof(double));
                    if (Datatmp == NULL) {
                      fprintf(stderr, "Error: Can not re-allocate memory %zi (Table_Read_Handle).\n",
                              malloc_size*sizeof(double));
		      free(Data);
                      return (-1);
                    } else {
                      Data=Datatmp;
                    }
                  }
                  if (0 == block_Num_Columns) Rows++;
                  Data[count_in_array] = X;
                  count_in_array++;
                  block_Num_Columns++;
                }
              } /* reading num: end if flag_In_array */
            } /* end reading num: end if sscanf lexeme -> numerical */
            else {
              /* reading line: the token is not numerical in that line. end block */
              if (block_Current_index == block_number) {
                flag_End_Line = 1;
                flag_End_row_loop = 1;
              } else {
                flag_In_array = 0;
                flag_End_Line = 1;
              }
            }
          }
          else {
            /* no more tokens in line */
            flag_End_Line = 1;
            if (block_Num_Columns > 0) Columns = block_Num_Columns;
          }

          // parse next token
          lexeme = strtok(NULL, seps);

        } /* while (!flag_End_Line) */
      } /* end: if fgets */
      else flag_End_row_loop = 1; /* else fgets : end of file */
      free(line);
    } while (!flag_End_row_loop); /* end while flag_End_row_loop */

    Table->block_number = block_number;
    Table->array_length = 1;

    // shrink header to actual size (plus terminating 0-byte)
    if (count_in_header) {
      Headertmp = (char*)realloc(Header, count_in_header*sizeof(char) + 1);
      if(!Headertmp) {
	fprintf(stderr, "Error: Could not shrink Header (Table_Read_Handle).\n");
	free(Header);
	return (-1);
      } else {
        Header = Headertmp;
      }
    }
    Table->header = Header;

    if (count_in_array*Rows*Columns == 0)
    {
      Table->rows         = 0;
      Table->columns      = 0;
      free(Data);
      return (0);
    }
    if (Rows * Columns != count_in_array)
    {
      fprintf(stderr, "Warning: Read_Table :%s %s Data has %li values that should be %li x %li\n",
        (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_in_array, Rows, Columns);
      Columns = count_in_array; Rows = 1;
    }
    if (count_invalid)
    {
      fprintf(stderr,"Warning: Read_Table :%s %s Data has %li invalid lines (*****). Ignored.\n",
      (Table->filename[0] != '\0' ? Table->filename : ""),
        (!block_number ? " catenated" : ""),
        count_invalid);
    }
    Datatmp     = (double*)realloc(Data, count_in_array*sizeof(double));
    if(!Datatmp) {
      fprintf(stderr, "Error: Could reallocate Data block to %li doubles (Table_Read_Handle).\n", count_in_array);
      free(Data);
      return (-1);
    } else {
      Data = Datatmp;
    }
    Table->data         = Data;
    Table->rows         = Rows;
    Table->columns      = Columns;

    return (count_in_array);

  } /* end Table_Read_Handle */

/*******************************************************************************
* long Table_Rebin(t_Table *Table)
*   ACTION: rebin a single Table, sorting 1st column in ascending order
*   input   Table: single table containing data.
*                  The data block is reallocated in this process
*   return  updated Table with increasing, evenly spaced first column (index 0)
*           number of data elements (-1: error, 0:empty data)
*******************************************************************************/
  long Table_Rebin(t_Table *Table)
  {
    double new_step=0;
    long   i;
    /* performs linear interpolation on X axis (0-th column) */

    if (!Table) return(-1);
    if (!Table->data 
    || Table->rows*Table->columns == 0 || !Table->step_x)
      return(0);
    Table_Stat(Table); /* recompute statitstics and minimal step */
    new_step = Table->step_x; /* minimal step in 1st column */

    if (!(Table->constantstep)) /* not already evenly spaced */
    {
      long Length_Table;
      double *New_Table;

      Length_Table = ceil(fabs(Table->max_x - Table->min_x)/new_step)+1;
      /*return early if the rebinned table will become too large*/
      if (Length_Table > mcread_table_rebin_maxsize){
        fprintf(stderr,"WARNING: (Table_Rebin): Rebinning table from %s would exceed 1M rows. Skipping.\n", Table->filename); 
        return(Table->rows*Table->columns);
      }
      New_Table    = (double*)malloc(Length_Table*Table->columns*sizeof(double));
      if (!New_Table) {
	fprintf(stderr,"Could not allocate New_Table of size %ld x %ld\n", Length_Table, Table->columns);
	exit(-1);
      }
      for (i=0; i < Length_Table; i++)
      {
        long   j;
        double X;
        X = Table->min_x + i*new_step;
        New_Table[i*Table->columns] = X;
        for (j=1; j < Table->columns; j++)
          New_Table[i*Table->columns+j]
                = Table_Value(*Table, X, j);
      } /* end for i */

      Table->rows = Length_Table;
      Table->step_x = new_step;
      Table->max_x = Table->min_x + (Length_Table-1)*new_step; 
      /*max might not be the same anymore
       * Use Length_Table -1 since the first and laset rows are the limits of the defined interval.*/
      free(Table->data);
      Table->data = New_Table;
      Table->constantstep=1;
    } /* end else (!constantstep) */
    return (Table->rows*Table->columns);
  } /* end Table_Rebin */

/*******************************************************************************
* double Table_Index(t_Table Table, long i, long j)
*   ACTION: read an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*   return  Value = data[i][j]
* Returns Value from the i-th row, j-th column of Table
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/

#ifndef MIN
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif

double Table_Index(t_Table Table, long i, long j)
{
  long AbsIndex;

  if (Table.rows == 1 || Table.columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table.columns*Table.rows - 1);
    i = 0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table.rows - 1);
    j = MIN(MAX(0, j), Table.columns - 1);
  }

  /* handle vectors specifically */
  AbsIndex = i*(Table.columns)+j;

  if (Table.data != NULL)
    return (Table.data[AbsIndex]);
  else
    return 0;
} /* end Table_Index */

/*******************************************************************************
* void Table_SetElement(t_Table *Table, long i, long j, double value)
*   ACTION: set an element [i,j] of a single Table
*   input   Table: table containing data
*           i : index of row      (0:Rows-1)
*           j : index of column   (0:Columns-1)
*           value = data[i][j]
* Returns 0 in case of error
* Tests are performed on indexes i,j to avoid errors
*******************************************************************************/
int Table_SetElement(t_Table *Table, long i, long j,
                     double value)
{
  long AbsIndex;

  if (Table->rows == 1 || Table->columns == 1) {
    /* vector */
    j = MIN(MAX(0, i+j), Table->columns*Table->rows - 1); i=0;
  } else {
    /* matrix */
    i = MIN(MAX(0, i), Table->rows - 1);
    j = MIN(MAX(0, j), Table->columns - 1);
  }

  AbsIndex = i*(Table->columns)+j;
  if (Table->data != NULL) {
    Table->data[AbsIndex] = value;
    return 1;
  }

  return 0;
} /* end Table_SetElement */

/*******************************************************************************
* double Table_Value(t_Table Table, double X, long j)
*   ACTION: read column [j] of a single Table at row which 1st column is X
*   input   Table: table containing data.
*           X : data value in the first column (index 0)
*           j : index of column from which is extracted the Value (0:Columns-1)
*   return  Value = data[index for X][j] with linear interpolation
* Returns Value from the j-th column of Table corresponding to the
* X value for the 1st column (index 0)
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value(t_Table Table, double X, long j)
{
  long   Index = -1;
  double X1=0, Y1=0, X2=0, Y2=0;
  double ret=0;

  if (X > Table.max_x) return Table_Index(Table,Table.rows-1  ,j);
  if (X < Table.min_x) return Table_Index(Table,0  ,j);

  // Use constant-time lookup when possible
  if(Table.constantstep) {
    Index = (long)floor(
              (X - Table.min_x) / (Table.max_x - Table.min_x) * (Table.rows-1));
    X1 = Table_Index(Table,Index-1,0);
    X2 = Table_Index(Table,Index  ,0);
  }
  // Use binary search on large, monotonic tables
  else if(Table.monotonic && Table.rows > 100) {
    long left = Table.min_x;
    long right = Table.max_x;

    while (!((X1 <= X) && (X < X2)) && (right - left > 1)) {
      Index = (left + right) / 2;

      X1 = Table_Index(Table, Index-1, 0);
      X2 = Table_Index(Table, Index,   0);

      if (X < X1) {
        right = Index;
      } else {
        left  = Index;
      }
    }
  }

  // Fall back to linear search, if no-one else has set X1, X2 correctly
  if (!((X1 <= X) && (X < X2))) {
    /* look for index surrounding X in the table -> Index */
    for (Index=1; Index <= Table.rows-1; Index++) {
        X1 = Table_Index(Table, Index-1,0);
        X2 = Table_Index(Table, Index  ,0);
        if ((X1 <= X) && (X < X2)) break;
      } /* end for Index */
  }

  Y1 = Table_Index(Table,Index-1, j);
  Y2 = Table_Index(Table,Index  , j);

#if defined(OPENACC) || defined(_OPENMP)
#define strcmp(a,b) str_comp(a,b)
#endif

  if (!strcmp(Table.method,"linear")) {
    ret = Table_Interp1d(X, X1,Y1, X2,Y2);
  }
  else if (!strcmp(Table.method,"nearest")) {
    ret = Table_Interp1d_nearest(X, X1,Y1, X2,Y2);
  }

#if defined(OPENACC) || defined(_OPENMP)
#ifdef strcmp
#undef strcmp
#endif
#endif

  return ret;
} /* end Table_Value */

/*******************************************************************************
* double Table_Value2d(t_Table Table, double X, double Y)
*   ACTION: read element [X,Y] of a matrix Table
*   input   Table: table containing data.
*           X : row index, may be non integer
*           Y : column index, may be non integer
*   return  Value = data[index X][index Y] with bi-linear interpolation
* Returns Value for the indices [X,Y]
* Tests are performed (within Table_Index) on indexes i,j to avoid errors
* NOTE: data should rather be monotonic, and evenly sampled.
*******************************************************************************/
double Table_Value2d(t_Table Table, double X, double Y)
  {
    long   x1,x2,y1,y2;
    double z11,z12,z21,z22;
    double ret=0;

    x1 = (long)floor(X);
    y1 = (long)floor(Y);

    if (x1 > Table.rows-1 || x1 < 0) {
      x2 = x1;
    } else {
      x2 = x1 + 1;
    }

    if (y1 > Table.columns-1 || y1 < 0) {
      y2 = y1;
    } else {
      y2 = y1 + 1;
    }

    z11 = Table_Index(Table, x1, y1);

    if (y2 != y1) z12=Table_Index(Table, x1, y2); else z12 = z11;
    if (x2 != x1) z21=Table_Index(Table, x2, y1); else z21 = z11;
    if (y2 != y1) z22=Table_Index(Table, x2, y2); else z22 = z21;

#if defined(OPENACC) || defined(_OPENMP)
#define strcmp(a,b) str_comp(a,b)
#endif

    if (!strcmp(Table.method,"linear"))
      ret = Table_Interp2d(X,Y, x1,y1,x2,y2, z11,z12,z21,z22);
#if defined(OPENACC) || defined(_OPENMP)
#ifdef strcmp
#undef strcmp
#endif
#endif
    else {
      if (fabs(X-x1) < fabs(X-x2)) {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z11; else ret = z12;
      } else {
        if (fabs(Y-y1) < fabs(Y-y2)) ret = z21; else ret = z22;
      }
    }
    return ret;
  } /* end Table_Value2d */


/*******************************************************************************
* void Table_Free(t_Table *Table)
*   ACTION: free a single Table. First Call Table_File_list_gc. If this returns
*   non-zero it means there are more refernces to the table, and so the table
*   should not bee freed.
*   return: empty Table
*******************************************************************************/
  void Table_Free(t_Table *Table)
  {
    if( !Table_File_List_gc(Table) ){
       return;
    } 
    if (!Table) return;
    if (Table->data   != NULL) free(Table->data);
    if (Table->header != NULL) free(Table->header);
    Table->data   = NULL;
    Table->header = NULL;
  } /* end Table_Free */

/******************************************************************************
* void Table_Info(t_Table Table)
*    ACTION: print informations about a single Table
*******************************************************************************/
  long Table_Info(t_Table Table)
  {
    char buffer[256];
    long ret=0;

    if (!Table.block_number) strcpy(buffer, "catenated");
    else sprintf(buffer, "block %li", Table.block_number);
    printf("Table from file '%s' (%s)",
        Table.filename[0] != '\0' ? Table.filename : "", buffer);
    if ((Table.data != NULL) && (Table.rows*Table.columns))
    {
      printf(" is %li x %li ", Table.rows, Table.columns);
      if (Table.rows*Table.columns > 1)
        printf("(x=%g:%g)", Table.min_x, Table.max_x);
      else printf("(x=%g) ", Table.min_x);
      ret = Table.rows*Table.columns;
      if (Table.monotonic)    printf(", monotonic");
      if (Table.constantstep) printf(", constant step");
      printf(". interpolation: %s\n", Table.method);
    }
    else printf(" is empty.\n");

    if (Table.header && strlen(Table.header)) {
      char *header;
      int  i;
      header = malloc(80);
      if (!header) return(ret);
      for (i=0; i<80; header[i++]=0);
      strncpy(header, Table.header, 75);
      if (strlen(Table.header) > 75) {
        strcat( header, " ...");
      }
      for (i=0; i<strlen(header); i++)
        if (header[i] == '\n' || header[i] == '\r') header[i] = ';';
      printf("  '%s'\n", header);
      free(header);
    }

    return(ret);
  } /* end Table_Info */

/******************************************************************************
* long Table_Init(t_Table *Table, m, n)
*   ACTION: initialise a Table to empty m by n table
*   return: empty Table
******************************************************************************/
long Table_Init(t_Table *Table, long rows, long columns)
{
  double *data=NULL;
  long   i;

  if (!Table) return(0);

  Table->header  = NULL;
  Table->filename[0]= '\0';
  Table->filesize= 0;
  Table->min_x   = 0;
  Table->max_x   = 0;
  Table->step_x  = 0;
  Table->block_number = 0;
  Table->array_length = 0;
  Table->monotonic    = 0;
  Table->constantstep = 0;
  Table->begin   = 0;
  Table->end     = 0;
  strcpy(Table->method,"linear");

  if (rows*columns >= 1) {
    data    = (double*)malloc(rows*columns*sizeof(double));
    if (data) for (i=0; i < rows*columns; data[i++]=0);
    else {
      if(Table->quiet<2)
        fprintf(stderr,"Error: allocating %ld double elements."
            "Too big (Table_Init).\n", rows*columns);
      rows = columns = 0;
    }
  }
  Table->rows    = (rows >= 1 ? rows : 0);
  Table->columns = (columns >= 1 ? columns : 0);
  Table->data    = data;
  return(Table->rows*Table->columns);
} /* end Table_Init */

/******************************************************************************
* long Table_Write(t_Table Table, char *file, x1,x2, y1,y2)
*   ACTION: write a Table to disk (ascii).
*     when x1=x2=0 or y1=y2=0, the table default limits are used.
*   return: 0=all is fine, non-0: error
*******************************************************************************/
MCDETECTOR Table_Write(t_Table Table, char *file, char *xl, char *yl, 
  double x1, double x2, double y1, double y2)
{
  MCDETECTOR detector;

  if ((Table.data == NULL) && (Table.rows*Table.columns)) {
    detector.m = 0;
    detector.xmin = 0;
    detector.xmax = 0;
    detector.ymin = 0;
    detector.ymax = 0;
    detector.zmin = 0;
    detector.zmax = 0; 
    detector.intensity = 0;
    detector.error = 0;
    detector.events = 0;
    detector.min = 0;
    detector.max = 0;
    detector.mean = 0;
    detector.centerX = 0;
    detector.halfwidthX = 0;
    detector.centerY = 0;
    detector.halfwidthY = 0;
    detector.rank = 0;
    detector.istransposed = 0;
    detector.n = 0;
    detector.p = 0;
    detector.date_l = 0;
    detector.p0 = NULL;
    detector.p1 = NULL;
    detector.p2 = NULL;
    return(detector); /* Table is empty - nothing to do */
  }
  if (!x1 && !x2) {
    x1 = Table.min_x;
    x2 = Table.max_x;
  }
  if (!y1 && !y2) {
    y1 = 1;
    y2 = Table.columns;
  }

  /* transfer content of the Table into a 2D detector */
  Coords coords = { 0, 0, 0};
  Rotation rot;
  rot_set_rotation(rot, 0, 0, 0);
  
  if (Table.rows == 1 || Table.columns == 1) {
    detector = mcdetector_out_1D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      "x", x1, x2,
                      Table.rows * Table.columns,
                      NULL, Table.data, NULL,
		      file, file, coords, rot,9999);
  } else {
    detector = mcdetector_out_2D(Table.filename,
                      xl ? xl : "", yl ? yl : "",
                      x1, x2, y1, y2,
                      Table.rows, Table.columns,
                      NULL, Table.data, NULL,
		      file, file, coords, rot,9999);
  }
  return(detector);
}

/******************************************************************************
* void Table_Stat(t_Table *Table)
*   ACTION: computes min/max/mean step of 1st column for a single table (private)
*   return: updated Table
*******************************************************************************/
  static void Table_Stat(t_Table *Table)
  {
    long   i;
    double max_x, min_x;
    double row=1;
    char   monotonic=1;
    char   constantstep=1;
    double step=0;
    long n;

    if (!Table) return;
    if (!Table->rows || !Table->columns) return;
    if (Table->rows == 1) row=0; // single row
    max_x = -FLT_MAX;
    min_x =  FLT_MAX;
    n     = (row ? Table->rows : Table->columns);
    /* get min and max of first column/vector */
    for (i=0; i < n; i++)
    {
      double X;
      X = (row ? Table_Index(*Table,i  ,0)
                               : Table_Index(*Table,0, i));
      if (X < min_x) min_x = X;
      if (X > max_x) max_x = X;
    } /* for */
    
    /* test for monotonicity and constant step if the table is an XY or single vector */
    if (n > 1) {
      /* mean step */
      step = (max_x - min_x)/(n-1);
      /* now test if table is monotonic on first column, and get minimal step size */
      for (i=0; i < n-1; i++) {
        double X, diff;;
        X    = (row ? Table_Index(*Table,i  ,0)
                    : Table_Index(*Table,0,  i));
        diff = (row ? Table_Index(*Table,i+1,0)
                    : Table_Index(*Table,0,  i+1)) - X;
        if (diff && fabs(diff) < fabs(step)) step = diff;
        /* change sign ? */
        if ((max_x - min_x)*diff < 0 && monotonic)
          monotonic = 0;
      } /* end for */
      
      /* now test if steps are constant within READ_TABLE_STEPTOL */
      if(!step){
        /*means there's a disconitnuity -> not constantstep*/
        constantstep=0;
      }else if (monotonic) {
        for (i=0; i < n-1; i++) {
          double X, diff;
          X    = (row ? Table_Index(*Table,i  ,0)
              : Table_Index(*Table,0,  i));
          diff = (row ? Table_Index(*Table,i+1,0)
              : Table_Index(*Table,0,  i+1)) - X;
          if ( fabs(step)*(1+READ_TABLE_STEPTOL) < fabs(diff) ||
                fabs(diff) < fabs(step)*(1-READ_TABLE_STEPTOL) )
          { constantstep = 0; break; }
        }
      }

    }
    Table->step_x= step;
    Table->max_x = max_x;
    Table->min_x = min_x;
    Table->monotonic = monotonic;
    Table->constantstep = constantstep;
  } /* end Table_Stat */

/******************************************************************************
* t_Table *Table_Read_Array(char *File, long *blocks)
*   ACTION: read as many data blocks as available, iteratively from file
*   return: initialized t_Table array, last element is an empty Table.
*           the number of extracted blocks in non NULL pointer *blocks
*******************************************************************************/
  t_Table *Table_Read_Array(char *File, long *blocks)
  {
    t_Table *Table_Array    = NULL;
    t_Table *Table_Arraytmp = NULL;
    long offset=0;
    long block_number=0;
    long allocated=256;
    long nelements=1;

    /* first allocate an initial empty t_Table array */
    Table_Array = (t_Table *)malloc(allocated*sizeof(t_Table));
    if (!Table_Array) {
      fprintf(stderr, "Error: Can not allocate memory %zi (Table_Read_Array).\n",
         allocated*sizeof(t_Table));
      *blocks = 0;
      return (NULL);
    }

    while (nelements > 0)
    {
      t_Table Table;

      /* if ok, set t_Table block number else exit loop */
      block_number++;
      Table.block_number = block_number;
      
      /* access file at offset and get following block. Block number is from the set offset
       * hence the hardcoded 1 - i.e. the next block counted from offset.*/
      nelements = Table_Read_Offset(&Table, File, 1, &offset,0);
      /*if the block is empty - don't store it*/
      if (nelements>0){
          /* if t_Table array is not long enough, expand and realocate */
          if (block_number >= allocated-1) {
              allocated += 256;
              Table_Arraytmp = (t_Table *)realloc(Table_Array,
                      allocated*sizeof(t_Table));
              if (!Table_Arraytmp) {
                  fprintf(stderr, "Error: Can not re-allocate memory %zi (Table_Read_Array).\n",
                          allocated*sizeof(t_Table));
                  free(Table_Array);
                  *blocks = 0;
                  return (NULL);
              } else {
                Table_Array = Table_Arraytmp;
              }
          }
          /* store it into t_Table array */
          //snprintf(Table.filename, 1024, "%s#%li", File, block_number-1);
          Table_Array[block_number-1] = Table;
      }
      /* continues until we find an empty block */
    }
    /* send back number of extracted blocks */
    if (blocks) *blocks = block_number-1;

    /* now store total number of elements in Table array */
    for (offset=0; offset < block_number;
      Table_Array[offset++].array_length = block_number-1);

    return(Table_Array);
  } /* end Table_Read_Array */
/*******************************************************************************
* void Table_Free_Array(t_Table *Table)
*   ACTION: free a Table array
*******************************************************************************/
  void Table_Free_Array(t_Table *Table)
  {
    long index;
    if (!Table) return;
    for (index=0;index < Table[0].array_length; index++){
            Table_Free(&Table[index]);
    }
    free(Table);
  } /* end Table_Free_Array */

/******************************************************************************
* long Table_Info_Array(t_Table *Table)
*    ACTION: print informations about a Table array
*    return: number of elements in the Table array
*******************************************************************************/
  long Table_Info_Array(t_Table *Table)
  {
    long index=0;

    if (!Table) return(-1);
    while (index < Table[index].array_length
       && (Table[index].data || Table[index].header)
       && (Table[index].rows*Table[index].columns) ) {
      Table_Info(Table[index]);
      index++;
    }
    printf("This Table array contains %li elements\n", index);
    return(index);
  } /* end Table_Info_Array */

/******************************************************************************
* char **Table_ParseHeader(char *header, symbol1, symbol2, ..., NULL)
*    ACTION: search for char* symbols in header and return their value or NULL
*            the search is not case sensitive.
*            Last argument MUST be NULL
*    return: array of char* with line following each symbol, or NULL if not found
*******************************************************************************/
#ifndef MyNL_ARGMAX
#define MyNL_ARGMAX 50
#endif

char **Table_ParseHeader_backend(char *header, ...){
  va_list ap;
  char exit_flag=0;
  int counter   =0;
  char **ret    =NULL;
  if (!header || header[0]=='\0') return(NULL);

  ret = (char**)calloc(MyNL_ARGMAX, sizeof(char*));
  if (!ret) {
    printf("Table_ParseHeader: Cannot allocate %i values array for Parser (Table_ParseHeader).\n",
      MyNL_ARGMAX);
    return(NULL);
  }
  for (counter=0; counter < MyNL_ARGMAX; ret[counter++] = NULL);
  counter=0;

  va_start(ap, header);
  while(!exit_flag && counter < MyNL_ARGMAX-1)
  {
    char *arg_char=NULL;
    char *pos     =NULL;
    /* get variable argument value as a char */
    arg_char = va_arg(ap, char *);
    if (!arg_char || arg_char[0]=='\0'){
      exit_flag = 1; break;
    }
    /* search for the symbol in the header */
    pos = (char*)strcasestr(header, arg_char);
    if (pos) {
      char *eol_pos;
      eol_pos = strchr(pos+strlen(arg_char), '\n');
      if (!eol_pos)
        eol_pos = strchr(pos+strlen(arg_char), '\r');
      if (!eol_pos)
        eol_pos = pos+strlen(pos)-1;
      ret[counter] = (char*)malloc(eol_pos - pos);
      if (!ret[counter]) {
        printf("Table_ParseHeader: Cannot allocate value[%i] array for Parser searching for %s (Table_ParseHeader).\n",
          counter, arg_char);
        exit_flag = 1; break;
      }
      strncpy(ret[counter], pos+strlen(arg_char), eol_pos - pos - strlen(arg_char));
      ret[counter][eol_pos - pos - strlen(arg_char)]='\0';
    }
    counter++;
  }
  va_end(ap);
  return(ret);
} /* Table_ParseHeader */

/******************************************************************************
* double Table_Interp1d(x, x1, y1, x2, y2)
*    ACTION: interpolates linearly at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d(double x,
  double x1, double y1,
  double x2, double y2)
{
  double slope;
  if (x2 == x1) return (y1+y2)/2;
  if (y1 == y2) return  y1;
  slope = (y2 - y1)/(x2 - x1);
  return y1+slope*(x - x1);
} /* Table_Interp1d */

/******************************************************************************
* double Table_Interp1d_nearest(x, x1, y1, x2, y2)
*    ACTION: table lookup with nearest method at x between y1=f(x1) and y2=f(x2)
*    return: y=f(x) value
*******************************************************************************/
double Table_Interp1d_nearest(double x,
  double x1, double y1,
  double x2, double y2)
{
  if (fabs(x-x1) < fabs(x-x2)) return (y1);
  else return(y2);
} /* Table_Interp1d_nearest */

/******************************************************************************
* double Table_Interp2d(x,y, x1,y1, x2,y2, z11,z12,z21,z22)
*    ACTION: interpolates bi-linearly at (x,y) between z1=f(x1,y1) and z2=f(x2,y2)
*    return: z=f(x,y) value
*    x,y |   x1   x2
*    ----------------
*     y1 |   z11  z21
*     y2 |   z12  z22
*******************************************************************************/
double Table_Interp2d(double x, double y,
  double x1, double y1,
  double x2, double y2,
  double z11, double z12, double z21, double z22)
{
  double ratio_x, ratio_y;
  if (x2 == x1) return Table_Interp1d(y, y1,z11, y2,z12);
  if (y1 == y2) return Table_Interp1d(x, x1,z11, x2,z21);

  ratio_y = (y - y1)/(y2 - y1);
  ratio_x = (x - x1)/(x2 - x1);
  return (1-ratio_x)*(1-ratio_y)*z11 + ratio_x*(1-ratio_y)*z21
    + ratio_x*ratio_y*z22         + (1-ratio_x)*ratio_y*z12;
} /* Table_Interp2d */

/* end of read_table-lib.c */
#endif // READ_TABLE_LIB_C

/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff.h
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Release:
* Version:
*
* Object File Format intersection header for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format:
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#define INTEROFF_LIB_H "$Revision$"

#ifndef OFF_EPSILON
#define OFF_EPSILON 1e-13
#endif

#ifndef OFF_INTERSECT_MAX
#if defined(OPENACC) || defined(_OPENMP)
#define OFF_INTERSECT_MAX 100
#else
#define OFF_INTERSECT_MAX 1024
#endif
#endif

//#include <float.h>

#define N_VERTEX_DISPLAYED    200000

typedef struct intersection {
	MCNUM time;  	  //time of the intersection
	Coords v;	      //intersection point
	Coords normal;  //normal vector of the surface intersected
	short in_out;	  //1 if the ray enters the volume, -1 otherwise
	short edge;	    //1 if the intersection is on the boundary of the polygon, and error is possible
	unsigned long index; // index of the face
} intersection;

typedef struct polygon {
  MCNUM* p;       //vertices of the polygon in adjacent order, this way : x1 | y1 | z1 | x2 | y2 | z2 ...
  int npol;       //number of vertices
  #pragma acc shape(p[0:npol]) init_needed(npol)
  Coords normal;
  double D;
} polygon;

typedef struct off_struct {
    long vtxSize;
    long polySize;
    long faceSize;
    Coords* vtxArray;
    #pragma acc shape(vtxArray[0:vtxSize]) init_needed(vtxSize)
    Coords* normalArray;
    #pragma acc shape(vtxArray[0:faceSize]) init_needed(faceSize)
    unsigned long* faceArray;
    #pragma acc shape(vtxArray[0:faceSize][0:polySize]) init_needed(faceSize,polySize)
    double* DArray;
    #pragma acc shape(vtxArray[0:polySize]) init_needed(polySize)
    char *filename;
    int mantidflag;
    long mantidoffset;
    intersection intersects[OFF_INTERSECT_MAX]; // After a call to off_intersect_all contains the list of intersections.
    int nextintersect;                 // 'Next' intersection (first t>0) solution after call to off_intersect_all
    int numintersect;               // Number of intersections after call to off_intersect_all
} off_struct;

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data);

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
#pragma acc routine
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data );

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data );

/*****************************************************************************
* int off_intersectx(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedral the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
#pragma acc routine
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data );

/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED points from the object
*******************************************************************************/
void off_display(off_struct);

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq);

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2);

#endif

/* end of interoff-lib.h */
/*******************************************************************************
*
* McStas, neutron ray-tracing package
*         Copyright (C) 1997-2008, All rights reserved
*         Risoe National Laboratory, Roskilde, Denmark
*         Institut Laue Langevin, Grenoble, France
*
* Runtime: share/interoff-lib.c
*
* %Identification
* Written by: Reynald Arnerin
* Date:    Jun 12, 2008
* Origin: ILL
* Release: $Revision$
* Version: McStas X.Y
*
* Object File Format intersection library for McStas. Requires the qsort function.
*
* Such files may be obtained with e.g.
*   qhull < points.xyz Qx Qv Tv o > points.off
* where points.xyz has format (it supports comments):
*   3
*   <nb_points>
*   <x> <y> <z>
*   ...
* The resulting file should have its first line being changed from '3' into 'OFF'.
* It can then be displayed with geomview.
* A similar, but somewhat older solution is to use 'powercrust' with e.g.
*   powercrust -i points.xyz
* which will generate a 'pc.off' file to be renamed as suited.
*
*******************************************************************************/

#ifndef INTEROFF_LIB_H
#include "interoff-lib.h"
#endif

#ifndef INTEROFF_LIB_C
#define INTEROFF_LIB_C "$Revision$"

#if defined(OPENACC) || defined(_OPENMP) // If on GPU map fprintf to printf
#define fprintf(stderr,...) printf(__VA_ARGS__)
#endif

#pragma acc routine
double off_F(double x, double y,double z,double A,double B,double C,double D) {
  return ( A*x + B*y + C*z + D );
}

#pragma acc routine
char off_sign(double a) {
  if (a<0)       return(-1);
  else if (a==0) return(0);
  else           return(1);
}

// off_normal ******************************************************************
//gives the normal vector of p
#pragma acc routine
void off_normal(Coords* n, polygon p)
{
  //using Newell method
  int i=0,j=0;
  n->x=0;n->y=0;n->z=0;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++)
  {
    MCNUM x1=p.p[3*i],
          y1=p.p[3*i+1],
          z1=p.p[3*i+2];
    MCNUM x2=p.p[3*j],
          y2=p.p[3*j+1],
          z2=p.p[3*j+2];
    // n is the cross product of v1*v2
    n->x += (y1 - y2) * (z1 + z2);
    n->y += (z1 - z2) * (x1 + x2);
    n->z += (x1 - x2) * (y1 + y2);
  }
} /* off_normal */

// off_pnpoly ******************************************************************
//based on http://www.ecse.rpi.edu/Homepages/wrf/Research/Short_Notes/pnpoly.html
//return 0 if the vertex is out
//    1 if it is in
//   -1 if on the boundary
#pragma acc routine
int off_pnpoly(polygon p, Coords v)
{
  int i=0, c = 0;
  MCNUM minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;
  MCNUM areax=0,areay=0,areaz=0;

  int pol2dx=0,pol2dy=1;          //2d restriction of the poly
  MCNUM x=v.x,y=v.y;

  /*areax: projected area with x-scratched = |v1_yz x v2_yz|, where v1=(x1-x0,0,z1-z0) & v2=(x2-x0,0,z2-z0).*/
  /* In principle, if polygon is triangle area should be scaled by 1/2, but this is irrelevant for finding the maximum area.*/
  /* Similarly for y and z scratched.*/
  areax=coords_len(coords_xp(
        coords_set(0,p.p[3*1+1]-p.p[0+1],p.p[3*1+2]-p.p[0+2]),
        coords_set(0,p.p[3*2+1]-p.p[0+1],p.p[3*2+2]-p.p[0+2])));
  areay=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],0,p.p[3*1+2]-p.p[0+2]),
        coords_set(p.p[3*2+0]-p.p[0+0],0,p.p[3*2+2]-p.p[0+2])));
  areaz=coords_len(coords_xp(
        coords_set(p.p[3*1+0]-p.p[0+0],p.p[3*1+1]-p.p[0+1],0),
        coords_set(p.p[3*2+0]-p.p[0+0],p.p[3*2+1]-p.p[0+1],0)));

  if(areaz<areax){
    if(areax<areay){
      /*pick areay - i.e. scratch y*/
      pol2dy=2;
      y=v.z;
    }else{
      /*scratch x*/
      pol2dx=2;
      x=v.z;
    }
  }else if (areaz<areay){
    pol2dy=2;
    y=v.z;
  }

  //trace rays and test number of intersection
  int j;
  for (i = 0, j = p.npol-1; i < p.npol; j = i++) {
    if (((((p.p[3*i+pol2dy])<=y) && (y<(p.p[3*j+pol2dy]))) ||
         (((p.p[3*j+pol2dy])<=y) && (y<(p.p[3*i+pol2dy])))) &&
        (x < ( (p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
             / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx]) ))
      c = !c;

    if (((fabs(p.p[3*i+pol2dy]-y)<=OFF_EPSILON) || ((fabs(p.p[3*j+pol2dy]-y)<=OFF_EPSILON))) &&
        fabs(x -((p.p[3*j+pol2dx] - p.p[3*i+pol2dx]) * (y - p.p[3*i+pol2dy])
          / (p.p[3*j+pol2dy] - p.p[3*i+pol2dy]) + p.p[3*i+pol2dx])) < OFF_EPSILON)
    {
      //the point lies on the edge
      c=-1;
      break;
    }
  }

  return c;
} /* off_pnpoly */

// off_intersectPoly ***********************************************************
//gives the intersection vertex between ray [a,b) and polygon p and its parametric value on (a b)
//based on http://geometryalgorithms.com/Archive/algorithm_0105/algorithm_0105.htm
#pragma acc routine
int off_intersectPoly(intersection *inter, Coords a, Coords b, polygon p)
{
  //direction vector of [a,b]
  Coords dir = {b.x-a.x, b.y-a.y, b.z-a.z};

  //the normal vector to the polygon
  Coords normale=p.normal;
  //off_normal(&normale, p); done at the init stage

  //direction vector from a to a vertex of the polygon
  Coords w0 = {a.x-p.p[0], a.y-p.p[1], a.z-p.p[2]};

  //scalar product
  MCNUM nw0  =-scalar_prod(normale.x,normale.y,normale.z,w0.x,w0.y,w0.z);
  MCNUM ndir = scalar_prod(normale.x,normale.y,normale.z,dir.x,dir.y,dir.z);
  inter->time = inter->edge = inter->in_out=0;
  inter->v = inter->normal = coords_set(0,0,1);

  if (fabs(ndir) < OFF_EPSILON)    // ray is parallel to polygon plane
  {
    if (nw0 == 0)              // ray lies in polygon plane (infinite number of solution)
      return 0;
    else return 0;             // ray disjoint from plane (no solution)
  }

  // get intersect point of ray with polygon plane
  inter->time = nw0 / ndir;            //parametric value the point on line (a,b)

  inter->v = coords_set(a.x + inter->time * dir.x,// intersect point of ray and plane
    a.y + inter->time * dir.y,
    a.z + inter->time * dir.z);

  int res=off_pnpoly(p,inter->v);

  inter->edge=(res==-1);
  if (ndir<0)
    inter->in_out=1;  //the negative dot product means we enter the surface
  else
    inter->in_out=-1;

  inter->normal=p.normal;

  return res;         //true if the intersection point lies inside the poly
} /* off_intersectPoly */


// off_getBlocksIndex **********************************************************
/*reads the indexes at the beginning of the off file as this :
line 1  OFF
line 2  nbVertex nbFaces nbEdges
*/
FILE *off_getBlocksIndex(char* filename, long* vtxSize, long* polySize )
{
  FILE* f = Open_File(filename,"r", NULL); /* from read_table-lib: FILE *Open_File(char *name, char *Mode, char *path) */
  if (!f) return (f);

  char line[CHAR_BUF_LENGTH];
  char *ret=0;
  *vtxSize = *polySize = 0;

  /* **************** start to read the file header */
  /* OFF file:
     'OFF' or '3'
   */

  ret=fgets(line,CHAR_BUF_LENGTH , f);// line 1 = "OFF"
  if (ret == NULL)
  {
    fprintf(stderr, "Error: Can not read 1st line in file %s (interoff/off_getBlocksIndex)\n", filename);
    exit(1);
  }
  if (strlen(line)>5)
  {
      fprintf(stderr,"Error: First line in %s is too long (=%lu). Possibly the line is not terminated by '\\n'.\n"
              "       The first line is required to be exactly 'OFF', '3' or 'ply'.\n",
              filename,(long unsigned)strlen(line));
      fclose(f);
      return(NULL);
  }

  if (strncmp(line,"OFF",3) && strncmp(line,"3",1) && strncmp(line,"ply",1))
  {
    fprintf(stderr, "Error: %s is probably not an OFF, NOFF or PLY file (interoff/off_getBlocksIndex).\n"
                    "       Requires first line to be 'OFF', '3' or 'ply'.\n",filename);
    fclose(f);
    return(NULL);
  }

  if (!strncmp(line,"OFF",3) || !strncmp(line,"3",1)) {
    do  /* OFF file: skip # comments which may be there */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
    } while (line[0]=='#');
    //line = nblines of vertex,faces and edges arrays
    sscanf(line,"%lu %lu",vtxSize,polySize);
  } else {
    do  /* PLY file: read all lines until find 'end_header'
           and locate 'element faces' and 'element vertex' */
    {
      ret=fgets(line,CHAR_BUF_LENGTH , f);
      if (ret == NULL)
      {
        fprintf(stderr, "Error: Can not read line in file %s (interoff/off_getBlocksIndex)\n", filename);
        exit(1);
      }
      if (!strncmp(line,"element face",12))
        sscanf(line,"element face %lu",polySize);
      else if (!strncmp(line,"element vertex",14))
        sscanf(line,"element vertex %lu",vtxSize);
      else if (!strncmp(line,"format binary",13))
        exit(fprintf(stderr,
          "Error: Can not read binary PLY file %s, only 'format ascii' (interoff/off_getBlocksIndex)\n%s\n",
          filename, line));
    } while (strncmp(line,"end_header",10));
  }

  /* The FILE is left opened ready to read 'vtxSize' vertices (vtxSize *3 numbers)
     and then polySize polygons (rows) */

  return(f);
} /* off_getBlocksIndex */

// off_init_planes *************************************************************
//gives the equations of 2 perpandicular planes of [ab]
#pragma acc routine
void off_init_planes(Coords a, Coords b,
  MCNUM* A1, MCNUM* C1, MCNUM* D1, MCNUM *A2, MCNUM* B2, MCNUM* C2, MCNUM* D2)
{
  //direction vector of [a b]
  Coords dir={b.x-a.x, b.y-a.y, b.z-a.z};

  //the plane parallel to the 'y' is computed with the normal vector of the projection of [ab] on plane 'xz'
  *A1= dir.z;
  *C1=-dir.x;
  if(*A1!=0 || *C1!=0)
    *D1=-(a.x)*(*A1)-(a.z)*(*C1);
  else
  {
    //the plane does not support the vector, take the one parallel to 'z''
    *A1=1;
    //B1=dir.x=0
    *D1=-(a.x);
  }
  //the plane parallel to the 'x' is computed with the normal vector of the projection of [ab] on plane 'yz'
  *B2= dir.z;
  *C2=-dir.y;
  *A2= 0;
  if (*B2==0 && *C2==0)
  {
    //the plane does not support the vector, take the one parallel to 'z'
    *B2=1;
    //B1=dir.x=0
    *D2=-(a.y);
  }
  else {
    if (dir.z==0)
    {
      //the planes are the same, take the one parallel to 'z'
      *A2= dir.y;
      *B2=-dir.x;
      *D2=-(a.x)*(*A2)-(a.y)*(*B2);
    }
    else
      *D2=-(a.y)**B2-(a.z)**C2;
  }
} /* off_init_planes */

// off_clip_3D_mod *************************************************************
#pragma acc routine
int off_clip_3D_mod(intersection* t, Coords a, Coords b,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray)
{
  MCNUM A1=0, C1=0, D1=0, A2=0, B2=0, C2=0, D2=0;      //perpendicular plane equations to [a,b]
  off_init_planes(a, b, &A1, &C1, &D1, &A2, &B2, &C2, &D2);

  int t_size=0;
  MCNUM popol[3*4]; /*3 dimensions and max 4 vertices to form a polygon*/
  unsigned long i=0,indPoly=0;

  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    pol.D     = 1;
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    int j=1;
    /*check whether vertex is left or right of plane*/
    char sg0=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A1,0,C1,D1));
    while (j<pol.npol)
    {
      //polygon's j-th vertex index in vtxTable
      unsigned long indVertP2=faceArray[i+j];
      /*check whether vertex is left or right of plane*/
      char sg1=off_sign(off_F(vtxArray[indVertP2].x,vtxArray[indVertP2].y,vtxArray[indVertP2].z,A1,0,C1,D1));
      if (sg0!=sg1) //if the plane intersect the polygon
        break;

      ++j;
    }

    if (j<pol.npol)          //ok, let's test with the second plane
    {
      char sg1=off_sign(off_F(vtxArray[indVertP1].x,vtxArray[indVertP1].y,vtxArray[indVertP1].z,A2,B2,C2,D2));//tells if vertex is left or right of the plane

      j=1;
      while (j<pol.npol)
      {
        //unsigned long indVertPi=faceArray[i+j];  //polyg's j-th vertex index in vtxTable
        Coords vertPi=vtxArray[faceArray[i+j]];
        if (sg1!=off_sign(off_F(vertPi.x,vertPi.y,vertPi.z,A2,B2,C2,D2)))//if the plane intersect the polygon
          break;
        ++j;
      }
      if (j<pol.npol)
      {
#ifdef OFF_LEGACY
        if (t_size>OFF_INTERSECT_MAX)
        {
          fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", OFF_INTERSECT_MAX);
            return (t_size);
        }
#endif
        //both planes intersect the polygon, let's find the intersection point
        //our polygon :
        int k;
        for (k=0; k<pol.npol; ++k)
        {
          Coords vertPk=vtxArray[faceArray[i+k]];
          pol.p[3*k]  =vertPk.x;
          pol.p[3*k+1]=vertPk.y;
          pol.p[3*k+2]=vertPk.z;
        }
        pol.normal=normalArray[indPoly];
        intersection x;
        if (off_intersectPoly(&x, a, b, pol))
        {
          x.index = indPoly;
#ifdef OFF_LEGACY
          t[t_size++]=x;
#else
	  /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
	  /* Case 1, negative time? */
	  if (t_size < 4) t_size++;	  
	  if (x.time < 0) {
	    if (x.time > t[0].time) {
	      t[0]=x;
	    }
	  } else {
	    /* Case 2, positive time */
	    intersection xtmp;
	    if (x.time < t[3].time) {
	      t[3]=x;
	      if (t[3].time < t[2].time) {
		xtmp = t[2];
		t[2] = t[3];
		t[3] = xtmp;
	      }
	      if (t[2].time < t[1].time) {
		xtmp = t[1];
		t[1] = t[2];
		t[2] = xtmp;
	      }
	    } 
	  }
#endif
	}
      } /* if (j<pol.npol) */
    } /* if (j<pol.npol) */
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod */

// off_clip_3D_mod_grav *************************************************************
/*******************************************************************************
version of off_clip_3D_mod_grav
*******************************************************************************/
#pragma acc routine seq
int off_clip_3D_mod_grav(intersection* t, Coords pos, Coords vel, Coords acc,
  Coords* vtxArray, unsigned long vtxSize, unsigned long* faceArray,
  unsigned long faceSize, Coords* normalArray, double* DArray)
{
  int t_size=0;
  MCNUM popol[3*CHAR_BUF_LENGTH];
  double plane_Eq [4];
  double quadratic [3];
  unsigned long i=0,indPoly=0;
  //exploring the polygons :
  i=indPoly=0;
  while (i<faceSize)
  {
    polygon pol;
    pol.npol  = faceArray[i];                //nb vertex of polygon
    pol.p     = popol;
    pol.normal= coords_set(0,0,1);
    unsigned long indVertP1=faceArray[++i];  //polygon's first vertex index in vtxTable
    
    if (t_size>CHAR_BUF_LENGTH)
      {
	fprintf(stderr, "Warning: number of intersection exceeded (%d) (interoff-lib/off_clip_3D_mod)\n", CHAR_BUF_LENGTH);
	return (t_size);
      }
    //both planes intersect the polygon, let's find the intersection point
    //our polygon :
    int k;
    for (k=0; k<pol.npol; ++k)
      {
	Coords vertPk=vtxArray[faceArray[i+k]];
	pol.p[3*k]  =vertPk.x;
	pol.p[3*k+1]=vertPk.y;
	pol.p[3*k+2]=vertPk.z;
      }
    pol.normal=normalArray[indPoly];
    pol.D=DArray[indPoly];
    p_to_quadratic(pol.normal, pol.D, acc, pos, vel, quadratic);
    double x1, x2;
    int nsol = quadraticSolve(quadratic, &x1, &x2);

    if (nsol >= 1) {
      double time = 1.0e36;
      if (x1 < time && x1 > 0.0) {
	time = x1;
      }
      if (nsol == 2 && x2 < time && x2 > 0.0) {
	time = x2;
      }
      if (time != 1.0e36) {
	intersection inters;
	double t2 = time * time * 0.5;
	double tx = pos.x + time * vel.x;
	if (acc.x != 0.0) {
	  tx = tx + t2 * acc.x;
	}
	double ty = pos.y + time * vel.y;
	if (acc.y != 0.0) {
	  ty = ty + t2 * acc.y;
	}
	double tz = pos.z + time * vel.z;
	if (acc.z != 0.0) {
	  tz = tz + t2 * acc.z;
	}
	inters.v = coords_set(tx, ty, tz);
	Coords tvel = coords_set(vel.x + time * acc.x,
				 vel.y + time * acc.y,
				 vel.z + time * acc.z);
	inters.time = time;
	inters.normal = pol.normal;
	inters.index = indPoly;
	int res=off_pnpoly(pol,inters.v);
	if (res != 0) {
	  inters.edge=(res==-1);
	  MCNUM ndir = scalar_prod(pol.normal.x,pol.normal.y,pol.normal.z,tvel.x,tvel.y,tvel.z);
	  if (ndir<0) {
	    inters.in_out=1;  //the negative dot product means we enter the surface
	  } else {
	    inters.in_out=-1;
	  }
#ifdef OFF_LEGACY
          t[t_size++]=inters;
#else
    /* Check against our 4 existing times, starting from [-FLT_MAX, FLT_MAX, FLT_MAX, FLT_MAX] */
    /* Case 1, negative time? */
    if (t_size < 4) t_size++;
    if (inters.time < 0) {
      if (inters.time > t[0].time) {
        t[0]=inters;
      }
    } else {
      /* Case 2, positive time */
      intersection xtmp;
      if (inters.time < t[3].time) {
      t[3]=inters;
        if (t[3].time < t[2].time) {
    xtmp = t[2];
    t[2] = t[3];
    t[3] = xtmp;
        }
        if (t[2].time < t[1].time) {
    xtmp = t[1];
    t[1] = t[2];
    t[2] = xtmp;
        }
      }
    }
#endif
	}
      }
    }
    i += pol.npol;
    indPoly++;
  } /* while i<faceSize */
  return t_size;
} /* off_clip_3D_mod_grav */

// off_compare *****************************************************************
#pragma acc routine
int off_compare (void const *a, void const *b)
{
   intersection const *pa = a;
   intersection const *pb = b;

   return off_sign(pa->time - pb->time);
} /* off_compare */

// off_cleanDouble *************************************************************
//given an array of intersections throw those which appear several times
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanDouble(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    int j=i;
    //for each intersection with the same time
    while (j<*t_size && fabs(prev.time-t[j].time)<OFF_EPSILON)
    {
      //if the intersection is the exact same erase it
      if (prev.in_out==t[j].in_out)
      {
        int k;
        for (k=j+1; k<*t_size; ++k)
        {
          t[k-1]=t[k];
        }
        *t_size-=1;
      }
      else
        ++j;
    }
    prev=t[i];
    ++i;

  }
  return 1;
} /* off_cleanDouble */

// off_cleanInOut **************************************************************
//given an array of intesections throw those which enter and exit in the same time
//Meaning the ray passes very close to the volume
//returns 1 if there is a possibility of error
#pragma acc routine
int off_cleanInOut(intersection* t, int* t_size)
{
  int i=1;
  intersection prev=t[0];
  while (i<*t_size)
  {
    //if two intersection have the same time but one enters and the other exits erase both
    //(such intersections must be adjacent in the array : run off_cleanDouble before)
    if (fabs(prev.time-t[i].time)<OFF_EPSILON && prev.in_out!=t[i].in_out)
    {
      int j=0;
      for (j=i+1; j<*t_size; ++j)
      {
        t[j-2]=t[j];
      }
      *t_size-=2;
      prev=t[i-1];
    }
    else
    {
      prev=t[i];
      ++i;
    }
  }
  return (*t_size);
} /* off_cleanInOut */

/* PUBLIC functions ******************************************************** */

/*******************************************************************************
* long off_init(  char *offfile, double xwidth, double yheight, double zdepth, off_struct* data)
* ACTION: read an OFF file, optionally center object and rescale, initialize OFF data structure
* INPUT: 'offfile' OFF file to read
*        'xwidth,yheight,zdepth' if given as non-zero, apply bounding box.
*           Specifying only one of these will also use the same ratio on all axes
*        'notcenter' center the object to the (0,0,0) position in local frame when set to zero
* RETURN: number of polyhedra and 'data' OFF structure
*******************************************************************************/
long off_init(  char *offfile, double xwidth, double yheight, double zdepth,
                int notcenter, off_struct* data)
{
  // data to be initialized
  long    vtxSize =0, polySize=0, i=0, ret=0, faceSize=0;
  Coords* vtxArray        =NULL;
  Coords* normalArray     =NULL;
  double* DArray          =NULL;
  unsigned long* faceArray=NULL;
  FILE*   f               =NULL; /* the FILE with vertices and polygons */
  double minx=FLT_MAX,maxx=-FLT_MAX,miny=FLT_MAX,maxy=-FLT_MAX,minz=FLT_MAX,maxz=-FLT_MAX;

  // get the indexes
  if (!data) return(0);

  MPI_MASTER(
  printf("Loading geometry file (OFF/PLY): %s\n", offfile);
  );

  f=off_getBlocksIndex(offfile,&vtxSize,&polySize);
  if (!f) return(0);

  // read vertex table = [x y z | x y z | ...] =================================
  // now we read the vertices as 'vtxSize*3' numbers and store it in vtxArray
  MPI_MASTER(
  printf("  Number of vertices: %ld\n", vtxSize);
  );
  vtxArray   = malloc(vtxSize*sizeof(Coords));
  if (!vtxArray) return(0);
  i=0;
  while (i<vtxSize && ~feof(f))
  {
    double x,y,z;
    ret=fscanf(f, "%lg%lg%lg", &x,&y,&z);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 3) {
      fprintf(stderr, "Error: can not read [xyz] coordinates for vertex %li in file %s (interoff/off_init). Read %li values.\n",
        i, offfile, ret);
      exit(2);
    }
    vtxArray[i].x=x;
    vtxArray[i].y=y;
    vtxArray[i].z=z;

    //bounding box
    if (vtxArray[i].x<minx) minx=vtxArray[i].x;
    if (vtxArray[i].x>maxx) maxx=vtxArray[i].x;
    if (vtxArray[i].y<miny) miny=vtxArray[i].y;
    if (vtxArray[i].y>maxy) maxy=vtxArray[i].y;
    if (vtxArray[i].z<minz) minz=vtxArray[i].z;
    if (vtxArray[i].z>maxz) maxz=vtxArray[i].z;
    i++; // inquire next vertex
  }

  // resizing and repositioning params
  double centerx=0, centery=0, centerz=0;
  if (!notcenter) {
    centerx=(minx+maxx)*0.5;
    centery=(miny+maxy)*0.5;
    centerz=(minz+maxz)*0.5;
  }

  double rangex=-minx+maxx,
         rangey=-miny+maxy,
         rangez=-minz+maxz;

  double ratiox=1,ratioy=1,ratioz=1;

  if (xwidth && rangex)
  {
    ratiox=xwidth/rangex;
    ratioy=ratiox;
    ratioz=ratiox;
  }

  if (yheight && rangey)
  {
    ratioy=yheight/rangey;
    if(!xwidth)  ratiox=ratioy;
    ratioz=ratioy;
  }

  if (zdepth && rangez)
  {
    ratioz=zdepth/rangez;
    if(!xwidth)  ratiox=ratioz;
    if(!yheight) ratioy=ratioz;
  }

  rangex *= ratiox;
  rangey *= ratioy;
  rangez *= ratioz;

  //center and resize the object
  for (i=0; i<vtxSize; ++i)
  {
    vtxArray[i].x=(vtxArray[i].x-centerx)*ratiox+(!notcenter ? 0 : centerx);
    vtxArray[i].y=(vtxArray[i].y-centery)*ratioy+(!notcenter ? 0 : centery);
    vtxArray[i].z=(vtxArray[i].z-centerz)*ratioz+(!notcenter ? 0 : centerz);
  }

  // read face table = [nbvertex v1 v2 vn | nbvertex v1 v2 vn ...] =============
  MPI_MASTER(
  printf("  Number of polygons: %ld\n", polySize);
  );
  normalArray= malloc(polySize*sizeof(Coords));
  faceArray  = malloc(polySize*10*sizeof(unsigned long)); // we assume polygons have less than 9 vertices
  DArray     = malloc(polySize*sizeof(double));
  if (!normalArray || !faceArray || !DArray) return(0);

  // fill faces
  faceSize=0;
  i=0;
  while (i<polySize && ~feof(f)) {
    int  nbVertex=0, j=0;
    // read the length of this polygon
    ret=fscanf(f, "%d", &nbVertex);
    if (!ret) {
      // invalid line: we skip it (probably a comment)
      char line[CHAR_BUF_LENGTH];
      char *s=fgets(line, CHAR_BUF_LENGTH, f);
      continue;
    }
    if (ret != 1) {
      fprintf(stderr, "Error: can not read polygon %li length in file %s (interoff/off_init)\n",
        i, offfile);
      exit(3);
    }
    if (faceSize > polySize*10) {
      fprintf(stderr, "Error: %li exceeded allocated polygon array[%li] in file %s (interoff/off_init)\n",
        faceSize, polySize*10, offfile);
    }
    faceArray[faceSize++] = nbVertex; // length of the polygon/face
    // then read the vertex ID's
    for (j=0; j<nbVertex; j++) {
      double vtx=0;
      ret=fscanf(f, "%lg", &vtx);
      faceArray[faceSize++] = vtx;   // add vertices index after length of polygon
    }
    i++;
  }

  // precomputes normals
  long indNormal=0;//index in polyArray
  i=0;    //index in faceArray
  while (i<faceSize)
  {
    int    nbVertex=faceArray[i];//nb of vertices of this polygon
    double *vertices=malloc(3*nbVertex*sizeof(double));
    if (!vertices) {
      fprintf(stderr,"Error allocating vertex array sized %i\n",nbVertex);
      exit(-1);
    }
    int j;

    for (j=0; j<nbVertex; ++j)
    {
      unsigned long indVertPj=faceArray[i+j+1];
      vertices[3*j]  =vtxArray[indVertPj].x;
      vertices[3*j+1]=vtxArray[indVertPj].y;
      vertices[3*j+2]=vtxArray[indVertPj].z;
    }

    polygon p;
    p.p   =vertices;
    p.npol=nbVertex;
    p.D=1;
    off_normal(&(p.normal),p);

    normalArray[indNormal]=p.normal;
    p.D = scalar_prod(p.normal.x,p.normal.y,p.normal.z,
		      vertices[0],vertices[1],vertices[2]);
    DArray[indNormal]=p.D;

    i += nbVertex+1;
    indNormal++;
    free(vertices);
  }

  MPI_MASTER(
  if (ratiox!=ratioy || ratiox!=ratioz || ratioy!=ratioz)
    printf("Warning: Aspect ratio of the geometry %s was modified.\n"
           "         If you want to keep the original proportions, specifiy only one of the dimensions.\n",
           offfile);
  if ( xwidth==0 && yheight==0 && zdepth==0 ) {
    printf("Warning: Neither xwidth, yheight or zdepth are defined.\n"
	   "           The file-defined (non-scaled) geometry the OFF geometry %s will be applied!\n",
           offfile);
  }
  printf("  Bounding box dimensions for geometry %s:\n", offfile);
  printf("    Length=%f (%.3f%%)\n", rangex, ratiox*100);
  printf("    Width= %f (%.3f%%)\n", rangey, ratioy*100);
  printf("    Depth= %f (%.3f%%)\n", rangez, ratioz*100);
  );

  data->vtxArray   = vtxArray;
  data->normalArray= normalArray;
  data->DArray     = DArray;
  data->faceArray  = faceArray;
  data->vtxSize    = vtxSize;
  data->polySize   = polySize;
  data->faceSize   = faceSize;
  data->filename   = offfile;
  #if defined(OPENACC) || defined(_OPENMP)
  acc_attach((void *)&vtxArray);
  acc_attach((void *)&normalArray);
  acc_attach((void *)&faceArray);
  #endif

  return(polySize);
} /* off_init */

#pragma acc routine
int Min_int(int x, int y) {
  return (x<y)? x :y;
}

 
#pragma acc routine
void merge(intersection *arr, int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 =  r - m;

/* create temp arrays */
intersection *L, *R;
 L = (intersection *)malloc(sizeof(intersection) * n1);
 R = (intersection *)malloc(sizeof(intersection) * n2);
 if (!L||!R) {
   fprintf(stderr,"Error allocating intersection arrays\n");
   exit(-1);
 }
/* Copy data to temp arrays L[] and R[] */
 #pragma acc loop independent
for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
 #pragma acc loop independent
for (j = 0; j < n2; j++)
    R[j] = arr[m + 1+ j];

/* Merge the temp arrays back into arr[l..r]*/
i = 0;
j = 0;
k = l;

while (i < n1 && j < n2)
{
    if (L[i].time <= R[j].time)
    {
        arr[k] = L[i];
        i++;
    }
    else
    {
        arr[k] = R[j];
        j++;
    }
    k++;
}

/* Copy the remaining elements of L[], if there are any */

while (i < n1)
{
    arr[k] = L[i];
    i++;
    k++;
}

/* Copy the remaining elements of R[], if there are any */
while (j < n2)
{
    arr[k] = R[j];
    j++;
    k++;
}
free(L);
free(R);
}


#ifdef USE_OFF
#pragma acc routine
void gpusort(intersection *arr, int size)
{
  int curr_size;  // For current size of subarrays to be merged
  // curr_size varies from 1 to n/2
  int left_start; // For picking starting index of left subarray
  // to be merged
  // pcopying (R[0:n2])
  {
    for (curr_size=1; curr_size<=size-1; curr_size = 2*curr_size)
      {
	// Pick starting point of different subarrays of current size
	for (left_start=0; left_start<size-1; left_start += 2*curr_size)
	  {
	    // Find ending point of left subarray. mid+1 is starting
	    // point of right
	    int mid = left_start + curr_size - 1;

	    int right_end = Min_int(left_start + 2*curr_size - 1, size-1);

	    // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
	    if (mid < right_end) merge(arr, left_start, mid, right_end);
	  }
      }
  }
}
#endif

/*******************************************************************************
void p_to_quadratic(double eq[], Coords acc,
                    Coords pos, Coords vel,
                    double* teq)
* ACTION: define the quadratic for the intersection of a parabola with a plane
* INPUT: 'eq' plane equation
*        'acc' acceleration vector
*        'vel' velocity of the particle
*        'pos' position of the particle
*         equation of plane A * x + B * y + C * z - D = 0
*         eq[0] = (C*az)/2+(B*ay)/2+(A*ax)/2
*         eq[1] = C*vz+B*vy+A*vx
*         eq[2] = C*z0+B*y0+A*x0-D
* RETURN: equation of parabola: teq(0) * t^2 + teq(1) * t + teq(2)
*******************************************************************************/
void p_to_quadratic(Coords norm, MCNUM d, Coords acc, Coords pos, Coords vel,
		    double* teq)
{
  teq[0] = scalar_prod(norm.x, norm.y, norm.z, acc.x, acc.y, acc.z) * 0.5;
  teq[1] = scalar_prod(norm.x, norm.y, norm.z, vel.x, vel.y, vel.z);
  teq[2] = scalar_prod(norm.x, norm.y, norm.z, pos.x, pos.y, pos.z) - d;
  return;
}

/*******************************************************************************
int quadraticSolve(double eq[], double* x1, double* x2);
* ACTION: solves the quadratic for the roots x1 and x2 
*         eq[0] * t^2 + eq[1] * t + eq[2] = 0
* INPUT: 'eq' the coefficients of the parabola
* RETURN: roots x1 and x2 and the number of solutions
*******************************************************************************/
int quadraticSolve(double* eq, double* x1, double* x2)
{
  if (eq[0] == 0.0) { // This is a linear equation
    if (eq[1] != 0.0) { // one solution
      *x1 = -eq[2]/eq[1];
      *x2 = 1.0e36;
      return 1;
    }else { // no solutions, 1.0e36 will be ignored.
      *x1 = 1.0e36;
      *x2 = 1.0e36;
      return 0;
    }
  }
  double delta = eq[1]*eq[1]-4.0*eq[0]*eq[2];
  if (delta < 0.0) { // no solutions, both are imaginary
    *x1 = 1.0e36;
    *x2 = 1.0e36;
    return 0;
  }
  double s = 1.0;
  if (eq[1] < 0) {
    s = -1.0;
  }
  *x1 = (-eq[1] - s * sqrt(delta))/(2.0*eq[0]);
  if (eq[0] != 0.0) { //two solutions
    *x2 = eq[2]/(eq[0]*(*x1));
    return 2;
  } else { //one solution
    *x2 = 1.0e36;
    return 1;
  }
}

/*******************************************************************************
* int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         ax, ay, az are the local acceleration vector
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*         data is the full OFF structure, including a list intersection type
*******************************************************************************/
int off_intersect_all(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct *data )
{

    int t_size = 0;
#ifdef OFF_LEGACY

    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(data->intersects, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray );
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(data->intersects, A, B,
			     data->vtxArray, data->vtxSize, data->faceArray,
			     data->faceSize, data->normalArray );
    }
    #if !defined(OPENACC) && !defined(_OPENMP)
    qsort(data->intersects, t_size, sizeof(intersection),  off_compare);
    #else
    #ifdef USE_OFF
    gpusort(data->intersects, t_size);
    #endif
    #endif
    off_cleanDouble(data->intersects, &t_size);
    off_cleanInOut(data->intersects,  &t_size);

    /*find intersections "closest" to 0 (favouring positive ones)*/
    if(t_size>0){
      int i=0;
      if(t_size>1) {
        for (i=1; i < t_size-1; i++){
          if (data->intersects[i-1].time > 0 && data->intersects[i].time > 0)
            break;
        }

	data->nextintersect=i-1;
	data->numintersect=t_size;

        if (t0) *t0 = data->intersects[i-1].time;
        if (n0) *n0 = data->intersects[i-1].normal;
        if (t3) *t3 = data->intersects[i].time;
        if (n3) *n3 = data->intersects[i].normal;
      } else {
        if (t0) *t0 = data->intersects[0].time;
	      if (n0) *n0 = data->intersects[0].normal;
      }
      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(data->intersects[data->nextintersect]).index;
      return t_size;
    }
#else
    intersection intersect4[4];
    intersect4[0].time=-FLT_MAX;
    intersect4[1].time=FLT_MAX;
    intersect4[2].time=FLT_MAX;
    intersect4[3].time=FLT_MAX;
    if(mcgravitation) {
      Coords pos={ x,  y,  z};
      Coords vel={vx, vy, vz};
      Coords acc={ax, ay, az};
      t_size=off_clip_3D_mod_grav(intersect4, pos, vel, acc,
				  data->vtxArray, data->vtxSize, data->faceArray,
				  data->faceSize, data->normalArray, data->DArray);
    } else {
    ///////////////////////////////////
    // non-grav
      Coords A={x, y, z};
      Coords B={x+vx, y+vy, z+vz};
      t_size=off_clip_3D_mod(intersect4, A, B,
	  data->vtxArray, data->vtxSize, data->faceArray, data->faceSize, data->normalArray );
    }
    if(t_size>0){
      int i=0;
      if (intersect4[0].time == -FLT_MAX) i=1;
      data->numintersect=t_size;
      if (t0) *t0 = intersect4[i].time;
      if (n0) *n0 = intersect4[i].normal;
      if (t3) *t3 = intersect4[i+1].time;
      if (n3) *n3 = intersect4[i+1].normal;

      if (intersect4[1].time == FLT_MAX)
      {
        if (t3) *t3 = 0.0;
      }

      /* should also return t[0].index and t[i].index as polygon ID */
      data->nextintersect=(int)intersect4[i].index;
      return t_size;
    }
#endif
    return 0;
} /* off_intersect */

/*******************************************************************************
* int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double vx, double vy, double vz,
     off_struct data )
* ACTION: computes intersection of neutron trajectory with an object.
* INPUT:  x,y,z and vx,vy,vz are the position and velocity of the neutron
*         data points to the OFF data structure
* RETURN: the number of polyhedral which trajectory intersects
*         t0 and t3 are the smallest incoming and outgoing intersection times
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_intersect(double* t0, double* t3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double vx, double vy, double vz,
     double ax, double ay, double az,
     off_struct data )
{
  return off_intersect_all(t0, t3, n0, n3, x, y, z, vx, vy, vz, ax, ay, az, &data );
} /* off_intersect */

/*****************************************************************************
* int off_x_intersect(double* l0, double* l3,
     Coords *n0, Coords *n3,
     double x, double y, double z,
     double kx, double ky, double kz,
     off_struct data )
* ACTION: computes intersection of an xray trajectory with an object.
* INPUT:  x,y,z and kx,ky,kz, are spatial coordinates and wavevector of the x-ray
*         respectively. data points to the OFF data structure.
* RETURN: the number of polyhedral the trajectory intersects
*         l0 and l3 are the smallest incoming and outgoing intersection lengths
*         n0 and n3 are the corresponding normal vectors to the surface
*******************************************************************************/
int off_x_intersect(double *l0,double *l3,
     Coords *n0, Coords *n3,
     double x,  double y,  double z,
     double kx, double ky, double kz,
     off_struct data )
{
  /*This function simply reformats and calls off_intersect (as for neutrons)
   *by normalizing the wavevector - this will yield the intersection lengths
   *in m*/
  double jx,jy,jz,invk;
  int n;
  invk=1/sqrt(scalar_prod(kx,ky,kz,kx,ky,kz));
  jx=kx*invk;jy=ky*invk;jz=kz*invk;
  n=off_intersect(l0,l3,n0,n3,x,y,z,jx,jy,jz,0.0,0.0,0.0,data);
  return n;
}


/*******************************************************************************
* void off_display(off_struct data)
* ACTION: display up to N_VERTEX_DISPLAYED polygons from the object
*******************************************************************************/
void off_display(off_struct data)
{
    if(mcdotrace==2){
    // Estimate size of the JSON string
    const int VERTEX_OVERHEAD = 30;
    const int FACE_OVERHEAD_BASE = 20;
    const int FACE_INDEX_OVERHEAD = 15;
    int estimated_size = 256; // Base size
    estimated_size += data.vtxSize * VERTEX_OVERHEAD;

    for (int i = 0; i < data.faceSize;) {
        int num_indices = data.faceArray[i];
        estimated_size += FACE_OVERHEAD_BASE + num_indices * FACE_INDEX_OVERHEAD;
        i += num_indices + 1;
    }

    char *json_string = malloc(estimated_size);
    if (json_string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    char *ptr = json_string;
    ptr += sprintf(ptr, "{ \"vertices\": [");

    for (int i = 0; i < data.vtxSize; i++) {
        ptr += sprintf(ptr, "[%g, %g, %g]", data.vtxArray[i].x, data.vtxArray[i].y, data.vtxArray[i].z);
        if (i < data.vtxSize - 1) {
            ptr += sprintf(ptr, ", ");
        }
    }

    ptr += sprintf(ptr, "], \"faces\": [");

    for (int i = 0; i < data.faceSize;) {
        int num = data.faceArray[i];
        ptr += sprintf(ptr, "{ \"face\": [");
        for (int j = 1; j <= num; j++) {
            ptr += sprintf(ptr, "%lu", data.faceArray[i + j]);
            if (j < num) {
                ptr += sprintf(ptr, ", ");
            }
        }
        ptr += sprintf(ptr, "]}");
        i += num + 1;
        if(i<data.faceSize){
          ptr += sprintf(ptr, ", ");
        }
    }

    ptr += sprintf(ptr, "]}");
    mcdis_polyhedron(json_string);

    free(json_string);
    }
    else {
      unsigned int i;
      double ratio=(double)(N_VERTEX_DISPLAYED)/(double)data.faceSize;
      unsigned int pixel=0;
      for (i=0; i<data.faceSize-1; i++) {
        int j;
        int nbVertex = data.faceArray[i];
        double x0,y0,z0;
        x0 = data.vtxArray[data.faceArray[i+1]].x;
        y0 = data.vtxArray[data.faceArray[i+1]].y;
        z0 = data.vtxArray[data.faceArray[i+1]].z;
        double x1=x0,y1=y0,z1=z0;
        double cmx=0,cmy=0,cmz=0;

        int drawthis = rand01() < ratio;
        // First pass, calculate center of mass location...
        for (j=1; j<=nbVertex; j++) {
          cmx = cmx+data.vtxArray[data.faceArray[i+j]].x;
          cmy = cmy+data.vtxArray[data.faceArray[i+j]].y;
          cmz = cmz+data.vtxArray[data.faceArray[i+j]].z;
        }
        cmx /= nbVertex;
        cmy /= nbVertex;
        cmz /= nbVertex;

        char pixelinfo[1024];
	char pixelinfotmp[1024];
        sprintf(pixelinfo, "%li,%li,%li,%i,%g,%g,%g,%g,%g,%g", data.mantidoffset+pixel, data.mantidoffset, data.mantidoffset+data.polySize-1, nbVertex, cmx, cmy, cmz, x1-cmx, y1-cmy, z1-cmz);
        for (j=2; j<=nbVertex; j++) {
          double x2,y2,z2;
          x2 = data.vtxArray[data.faceArray[i+j]].x;
          y2 = data.vtxArray[data.faceArray[i+j]].y;
          z2 = data.vtxArray[data.faceArray[i+j]].z;
          sprintf(pixelinfotmp, "%s,%g,%g,%g", pixelinfo, x2-cmx, y2-cmy, z2-cmz);
	  sprintf(pixelinfo,"%s",pixelinfotmp);
          if (ratio > 1 || drawthis) {
	    mcdis_line(x1,y1,z1,x2,y2,z2);
          }
          x1 = x2; y1 = y2; z1 = z2;
        }
        if (ratio > 1 || drawthis) {
	    mcdis_line(x1,y1,z1,x0,y0,z0);
          }
        if (data.mantidflag) {
          printf("MANTID_PIXEL: %s\n", pixelinfo);
          pixel++;
        }
        i += nbVertex;
      }
    }
} /* off_display */

/* end of interoff-lib.c */
#endif // INTEROFF_LIB_C

  #if !defined(OPENACC) && !defined(_OPENMP)

//////////////////////////////////////////////////////////////////////////////
//OpenCL lilbrary file for McStas
//
// global variables assigned to the OpenCL mechanism
// only initialised once
//Created by Jinyan LIU
//Date july 2014
//////////////////////////////////////////////////////////////////////////////



#ifdef USE_OPENCL
#ifndef OPENCL_LIB_H
#define OPENCL_LIB_H

#include <>

// this structure holds the full GPU context initialised from a Kernel source file
// to get if use: s = oclInitKernel(filename, 1);
#define MAX_GPU_COUNT 8

struct opencl_context {
  cl_context       GPUContext;                     // OpenCL context
  cl_command_queue CommandQueue[MAX_GPU_COUNT];      // OpenCL command queue
  cl_kernel        Kernel;
};

struct opencl_context oclInitKernel(char *filename, cl_uint nDevice);

// Mersenne OCL implementation
#define   MT_RNG_COUNT 4096
#define          MT_MM 397            
#define          MT_NN 624               
#define       MT_WMASK 0xFFFFFFFFU
#define       MT_UMASK 0x80000000U      
#define       MT_LMASK 0x7fffffffU       
#define      MT_SHIFT0 12
#define      MT_SHIFTB 7
#define      MT_SHIFTC 15
#define      MT_SHIFT1 18
#define      DCMT_SEED 4172

////////////////////////////////////////////////////////////////////////////////
//OpenCL Global Variable 
//////////////////////////////////////////////////////////////////////////////// 
struct opencl_context oclContext_mt;
unsigned int        **oclContext_mt_buffer=NULL;      // buffer holding a list of random numbers, on the CPU
cl_mem               *oclContext_mt_buffer_GPU=NULL;  // buffer holding a list of random numbers, on the GPU/OpenCL
int                   oclContext_mt_counter = -2;     // index of random number read from buffer

void         mt_srandom_opencl(unsigned long s);
unsigned int mt_random_opencl(void);

#endif
#endif

//////////////////////////////////////////////////////////////////////////////
//OpenCL lilbrary file for McStas
//
// global variables assigned to the OpenCL mechanism
// only initialised once
//Created by Jinyan LIU
//Date july 2014
//////////////////////////////////////////////////////////////////////////////

#ifdef USE_OPENCL
#ifndef OPENCL_LIB_C
#define OPENCL_LIB_C

//////////////////////////////////////////////////////////////////////////////
//! fileparts: return the name of the file between '/' and '.'
//!
//! @return the name of the file if succeeded, 0 otherwise
//! @param name      filename maybe with '/' , '\' or '.'
//! 
//////////////////////////////////////////////////////////////////////////////

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
#define PATHSEP_C '\\'
#define PATHSEP_S "\\"
#else  /* !WIN32 */
#define PATHSEP_C '/'
#define PATHSEP_S "/"
#endif /* !WIN32 */

char* fileparts(char *name)
{
  char *Name=NULL;

  if (name && strlen(name)) {
    char *dot_pos    = NULL;
    char *path_pos   = NULL;
    char *end_pos    = NULL;
    char *name_pos   = NULL;
    size_t  name_length= 0;

    end_pos = name+strlen(name);  /* end of file name */

    /* extract path: searches for last file separator */
    path_pos= strrchr(name, PATHSEP_C);  /* last PATHSEP */

    if (!path_pos) {
      path_pos   =name;
      name_pos   =name;
    } else {
      name_pos    = path_pos+1; /* from start to path+sep */
    }

    /* extract ext: now looks for the 'dot' */
    dot_pos = strrchr(name_pos, '.');           /* last dot */
    if (dot_pos <= name_pos)
      dot_pos = end_pos;

    /* extract Name (without extension) */
    name_length = dot_pos - name_pos; /* from path to dot */
    if (name_length) {
      Name = (char*)malloc(name_length);
      if (Name) strncpy(Name, name_pos, name_length);
      Name[name_length]='\0';
    }
  } /* if (name) */
  return (Name);

} /* fileparts */


//////////////////////////////////////////////////////////////////////////////
//! oclLoadProgSource: Loads a Program file and prepends the cPreamble to the code.
//!
//! @return the source string if succeeded, 0 otherwise
//! @param cFilename        program filename
//! @param cPreamble        code that is prepended to the loaded file, typically a set of #defines or a header
//! @param szFinalLength    returned length of the code string
//////////////////////////////////////////////////////////////////////////////

char* oclLoadProgSource(const char* cFilename, const char* cPreamble, size_t* szFinalLength)
{
    // locals 
    FILE* pFileStream = NULL;
    size_t szSourceLength;

    // open the OpenCL source code file
    #ifdef _WIN32   // Windows version
        if(fopen_s(&pFileStream, cFilename, "rb") != 0) 
        {       
            return NULL;
        }
    #else           // Linux version
        pFileStream = fopen(cFilename, "rb");
        if(pFileStream == 0) 
        {       
            return NULL;
        }
    #endif

    size_t szPreambleLength = strlen(cPreamble);

    // get the length of the source code
    fseek(pFileStream, 0, SEEK_END); 
    szSourceLength = ftell(pFileStream);
    fseek(pFileStream, 0, SEEK_SET); 

    // allocate a buffer for the source code string and read it in
    char* cSourceString = (char *)malloc(szSourceLength + szPreambleLength + 1); 
    memcpy(cSourceString, cPreamble, szPreambleLength);
    if (fread((cSourceString) + szPreambleLength, szSourceLength, 1, pFileStream) != 1)
    {
        fclose(pFileStream);
        free(cSourceString);
        return NULL;
    }

    // close the file and return the total length of the combined (preamble + source) string
    fclose(pFileStream);
    if(szFinalLength != 0)
    {
        *szFinalLength = szSourceLength + szPreambleLength;
    }
    cSourceString[szSourceLength + szPreambleLength] = '\0';

    return cSourceString;
} /* end oclLoadProgSource */

//////////////////////////////////////////////////////////////////////////////
//! oclGetPlatformID: Gets the platform ID for NVIDIA if available, otherwise default
//!
//! @return the id 
//! @param clSelectedPlatformID         OpenCL plateform ID
//////////////////////////////////////////////////////////////////////////////

cl_int oclGetPlatformID(cl_platform_id* clSelectedPlatformID)
{
    char chBuffer[1024];
    cl_uint num_platforms,i; 
    cl_platform_id* clPlatformIDs;
    cl_int ciErrNum;
    *clSelectedPlatformID = NULL;

    // Get OpenCL platform count
    ciErrNum = clGetPlatformIDs (0, NULL, &num_platforms);
    if (ciErrNum != CL_SUCCESS)
    {
        printf(" Error %i in clGetPlatformIDs Call !!!\n\n", ciErrNum);
        return -1000;
    }
    else 
    {
        if(num_platforms == 0)
        {
            printf("No OpenCL platform found!\n\n");
            return -2000;
        }
        else 
        {
            // if there's a platform or more, make space for ID's
            if ((clPlatformIDs = (cl_platform_id*)malloc(num_platforms * sizeof(cl_platform_id))) == NULL)
            {
                printf("Failed to allocate memory for cl_platform ID's!\n\n");
                return -3000;
            }

            // get platform info for each platform and trap the NVIDIA platform if found
            ciErrNum = clGetPlatformIDs (num_platforms, clPlatformIDs, NULL);
	    printf("We found %i CL platforms, selecting the first of them:\n",num_platforms);
	    
            ciErrNum = clGetPlatformInfo (clPlatformIDs[0], CL_PLATFORM_NAME, 1024, &chBuffer, NULL);
            if(ciErrNum == CL_SUCCESS)
            {
		printf("Platform: %s\n",chBuffer);
                *clSelectedPlatformID = clPlatformIDs[0];
            }

            free(clPlatformIDs);
        }
    }

    return CL_SUCCESS;
} /* end oclGetPlatformID */

//////////////////////////////////////////////////////////////////////////////
//! oclInit: initialize 'nDevice' GPU's
//!
//! @return error code or CL_SUCCESS
//! @param nDevice         nb of devices requested OpenCL
//
// This function should initialize cxGPUContext and cqCommandQueue
//////////////////////////////////////////////////////////////////////////////


struct opencl_context oclInitKernel(char *filename, cl_uint nDevice) {

  cl_program cpProgram;                           // OpenCL program
  
  cl_platform_id cpPlatform; 

  cl_device_id* cdDevices;                        // OpenCL device list   
  
  cl_int ciErr1, ciErr2;                          // Error code var
  
  char *basename = NULL;
  const int nPerRng = 5860;                       // # of recurrence steps, must be even if do Box-Muller transformation
  const int nRand = MT_RNG_COUNT * nPerRng;       // Output size  

  cl_uint i;
  
  struct opencl_context oclContext;
  oclContext.GPUContext = NULL;
  oclContext.Kernel     = NULL;
  
  ciErr1 = oclGetPlatformID(&cpPlatform);
  if(ciErr1 != CL_SUCCESS) 
    return(oclContext);
  ciErr1 = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 0, NULL, &nDevice);

  cdDevices = (cl_device_id *)malloc(nDevice * sizeof(cl_device_id) );
  ciErr1 =clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU,  nDevice, cdDevices, NULL);
  
  
  oclContext.GPUContext = clCreateContext(0, nDevice, cdDevices, NULL, NULL, &ciErr1);
  if(ciErr1 != CL_SUCCESS) 
    return(oclContext);
        
  for (i = 0; i < nDevice; i++) 
  {
      oclContext.CommandQueue[i] = clCreateCommandQueue(oclContext.GPUContext, cdDevices[i], 0, &ciErr1);
  }
  
  if (!oclContext.GPUContext) return (oclContext);

  /* load mersenne twister kernel source from disk */
  size_t szKernelLength; // Byte size of kernel code
  char   *cKernel = oclLoadProgSource(filename, "// My comment\n", &szKernelLength);
  
  if(cKernel == NULL) {
    printf("%s:%u: OpenCL error: Failed to open the OpenCL program source file %s\n", __FILE__, __LINE__, filename);
    return(oclContext);
  }
  
  cpProgram = clCreateProgramWithSource(oclContext.GPUContext, 1, (const char **)&cKernel, &szKernelLength, &ciErr1);
  if(ciErr1 != CL_SUCCESS) 
    return(oclContext);  
       
  if (cpProgram== NULL) {
    printf("%s:%u: OpenCL error: Failed to create %s OpenCL program\n", __FILE__, __LINE__, filename);
    return(oclContext);
  }  
       
  ciErr1 |= clBuildProgram(cpProgram, 0, NULL, "-cl-fast-relaxed-math", NULL, NULL);
  if (ciErr1 !=CL_SUCCESS){
    printf("%s:%u: OpenCL error: Failed to build %s kernel\n", __FILE__, __LINE__, filename);
    for (i=0; i < nDevice; i++) {
      // Determine the size of the log
      size_t len;
      clGetProgramBuildInfo(cpProgram, cdDevices[i], CL_PROGRAM_BUILD_LOG, 0, NULL, &len); 
      // Allocate memory for the log
      char *build_log = (char*)malloc(len);
      // Get the log
      ciErr1 |= clGetProgramBuildInfo(cpProgram, cdDevices[i], CL_PROGRAM_BUILD_LOG, len, build_log, NULL);
      // Print the log
      printf("-------Build log-----------\n");
      printf("\nBuildInfo:%s\n", build_log);
      free(build_log);
      clFinish(oclContext.CommandQueue[i]);
    }
    return(oclContext);
  }
  
  basename = fileparts(filename);
  
  oclContext.Kernel = clCreateKernel(cpProgram, basename, &ciErr1);
  
  free(basename);

  if (oclContext.Kernel == NULL || ciErr1 !=CL_SUCCESS) {
    printf("%s:%u: OpenCL error: Failed to create %s kernel\n", __FILE__, __LINE__, filename);
    return(oclContext);
  }

  for (i = 0; i < nDevice; i++)
    {
      clFinish(oclContext.CommandQueue[i]);
    }
    
  clReleaseProgram(cpProgram); 
  free(cKernel);
  free(cdDevices);
  
  return oclContext;
}

/* ========================================================================== */
/*        OpenCL implementation of random MersenneTwister generator           */
/* ========================================================================== */



unsigned int **mt_random_opencl_fill_buffer(cl_uint nDevice, struct opencl_context oclContext)
{

  cl_int ciErr1=0, ciErr2=0;                      // Error code var
  size_t globalWorkSize[1] = {MT_RNG_COUNT};      // 1D var for Total # of work items
  size_t localWorkSize[1] = {128};                // 1D var for # of work items in the work group

  const int nPerRng =5860;                        // # of recurrence steps, must be even if do Box-Muller transformation
  const int nRand = MT_RNG_COUNT * nPerRng;       // Output size   
  char      allocate_memory=0;
  cl_uint   iDevice,i;

  printf("Filling buffer\n");

  /* this section launches the kernel to fill the buffer (when counter = -1) */
  
  //  Using GPU(s)...
  if (oclContext.Kernel == NULL || oclContext.GPUContext==NULL)
    return(NULL);

  //  Initialization: load MT parameters and init host buffers
  if (!oclContext_mt_buffer) {
    // first call to this function: allocate memory
    allocate_memory = 1;
    oclContext_mt_buffer = (unsigned int**)malloc(nDevice*sizeof(unsigned int*));
    if (!oclContext_mt_buffer) return NULL;
    for (iDevice = 0; iDevice < nDevice; oclContext_mt_buffer[iDevice++]=NULL);
  }

  //  Allocate memory
  if (allocate_memory)
    for (iDevice = 0; iDevice < nDevice; iDevice++)
    {
       if (!oclContext_mt_buffer[iDevice])
           oclContext_mt_buffer[iDevice]  = (unsigned int*)malloc(sizeof(unsigned int)*nRand); // Host buffers for GPU output
       if (!oclContext_mt_buffer[iDevice]) return(NULL);
    }

  if (allocate_memory && !oclContext_mt_buffer_GPU) {
    oclContext_mt_buffer_GPU = (cl_mem*)malloc(nDevice*sizeof(cl_mem));
    if (!oclContext_mt_buffer_GPU) return NULL;
    for (iDevice = 0; iDevice < nDevice; oclContext_mt_buffer_GPU[iDevice++]=NULL);
  }
  
  if (allocate_memory)
    for (iDevice = 0; iDevice < nDevice; iDevice++)
    {
        if (!oclContext_mt_buffer_GPU[iDevice]) {
          oclContext_mt_buffer_GPU[iDevice] = clCreateBuffer(oclContext.GPUContext, CL_MEM_READ_WRITE, sizeof(cl_uint)*nRand, NULL, &ciErr2);
        
          if (ciErr2 !=CL_SUCCESS) return(NULL);
        }
        
    } /* for */
  
  for (iDevice = 0; iDevice < nDevice; iDevice++)
  {
      clFinish(oclContext.CommandQueue[iDevice]);
  }
  
  for (iDevice = 0; iDevice < nDevice; iDevice++)
  {
    time_t t;
    int seed=(int)time(&t);
    if (allocate_memory) {
      ciErr1 |= clSetKernelArg(oclContext.Kernel, 0, sizeof(cl_mem), (void*)&oclContext_mt_buffer_GPU[iDevice]);
      if (ciErr1 !=CL_SUCCESS) return(NULL);
        
      ciErr1 |= clSetKernelArg(oclContext.Kernel, 1, sizeof(int),    (void*)&nPerRng);
      if (ciErr1 !=CL_SUCCESS) return(NULL);
    }

    // Each call to fill buffer must use a different seed
    ciErr1 |= clSetKernelArg(oclContext.Kernel, 2, sizeof(int),    (void*)&seed);
      if (ciErr1 !=CL_SUCCESS) return(NULL);
      
    // call the Kernel with the queue
    ciErr1 |= clEnqueueNDRangeKernel(oclContext.CommandQueue[iDevice], oclContext.Kernel, 1, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL);

    if (ciErr1 !=CL_SUCCESS) return (NULL);
  }
    
  for (iDevice = 0; iDevice < nDevice; iDevice++)
  {
      clFinish(oclContext.CommandQueue[iDevice]);
  }

  //  Read back results
  
  for (iDevice = 0; iDevice < nDevice; iDevice++)
  {
      ciErr1 = clEnqueueReadBuffer(oclContext.CommandQueue[iDevice], oclContext_mt_buffer_GPU[iDevice], CL_TRUE, 0, 
          sizeof(cl_uint) * nRand, oclContext_mt_buffer[iDevice], 0, NULL, NULL);
  
      if (ciErr1 !=CL_SUCCESS) return(NULL);
  }  

  return (unsigned int**) oclContext_mt_buffer;
} /* end mt_random_opencl_fill_buffer */



// main Mersenne random call ---------------------------------------------------
void mt_srandom_opencl(unsigned long s) {
  fprintf(stderr, "%s: The GPU implementation does not support manual seed setting. Using seed=clock().\n", __FILE__);
}

unsigned int mt_random_opencl(void) // Should be called by others 
{
  unsigned int nDevice = 1;                              // Use 1st opencl Device, > 0
  const int    nPerRng = 5860;                           // # of recurrence steps, must be even if do Box-Muller transformation
  const int    nRand = MT_RNG_COUNT * nPerRng;           // Output size
 
  if (oclContext_mt_counter >= nRand) {    
    printf("%s:%i: INFO: reached max (oclContext_mt_counter=%i)\n", __FILE__, __LINE__, oclContext_mt_counter); fflush(NULL);
    oclContext_mt_counter = -1;
  }  
  
  if (oclContext_mt_counter <= -2) {
    /* the first time we create the OCL kernel and the buffer */
    oclContext_mt = oclInitKernel("MersenneTwister.cl", nDevice);
    oclContext_mt_counter = -1;
  }
  
  // in case the OpenCL context has noot been initialized, default to serial MT
  if (oclContext_mt.Kernel == NULL) {
    return(mt_random());
  }
    
  if (oclContext_mt_counter <= -1 /*|| oclContext_mt_counter >= nRand*/ ) {
    /* when the buffer is just created or fully read, we re-fill the buffer */
    if (mt_random_opencl_fill_buffer(nDevice, oclContext_mt) == NULL) {
      fprintf(stderr, "%s: Could not find the OpenCL MT buffer. Using serial MT.\n", __FILE__);
      return(mt_random());
    }

    oclContext_mt_counter = 0;
  } 
  
  /* return the value of the random number read from the buffer */
  printf("Rng returned %u as %u\n",oclContext_mt_counter++,oclContext_mt_buffer[nDevice-1][oclContext_mt_counter++]);
  return (oclContext_mt_buffer[nDevice-1][oclContext_mt_counter++]);
} /* mt_random_opencl */

#endif
#endif


  #endif
  /* Declare structures and functions only once in each instrument. */
  #ifndef SINGLE_CRYSTAL_DECL
  #define SINGLE_CRYSTAL_DECL

  #ifndef Mosaic_AB_Undefined
  #define Mosaic_AB_Undefined {0,0, 0,0,0, 0,0,0}
  #endif

  #ifndef MCSX_REFL_SLIST_SIZE
  #define MCSX_REFL_SLIST_SIZE 128
  #endif

  struct hkl_data {
    int h, k, l;                /* Indices for this reflection */
    double F2;                  /* Value of structure factor */
    double tau_x, tau_y, tau_z; /* Coordinates in reciprocal space */
    double tau;                 /* Length of (tau_x, tau_y, tau_z) */
    double u1x, u1y, u1z;       /* First axis of local coordinate system */
    double u2x, u2y, u2z;       /* Second axis of local coordinate system */
    double u3x, u3y, u3z;       /* Third axis of local coordinate system */
    double sig123;              /* The product sig1*sig2*sig3 = volume of spot */
    double m1, m2, m3;          /* Diagonal matrix representation of Gauss */
    double cutoff;              /* Cutoff value for Gaussian tails */
  };

  struct tau_data {
    int index; /* Index into reflection table */
    double refl;
    double xsect;
    /* The following vectors are in local koordinates. */
    double rho_x, rho_y, rho_z; /* The vector ki - tau */
    double rho;                 /* Length of rho vector */
    double ox, oy, oz;          /* Origin of Ewald sphere tangent plane */
    double b1x, b1y, b1z;       /* Spanning vectors of Ewald sphere tangent */
    double b2x, b2y, b2z;
    double l11, l12, l22; /* Cholesky decomposition L of 2D Gauss */
    double y0x, y0y;      /* 2D Gauss center in tangent plane */
  };

  struct hkl_info_struct {
    int count;                  /* Number of reflections */
    double m_delta_d_d;         /* Delta-d/d FWHM */
    double m_ax, m_ay, m_az;    /* First unit cell axis (direct space, AA) */
    double m_bx, m_by, m_bz;    /* Second unit cell axis */
    double m_cx, m_cy, m_cz;    /* Third unit cell axis */
    double asx, asy, asz;       /* First reciprocal lattice axis (1/AA) */
    double bsx, bsy, bsz;       /* Second reciprocal lattice axis */
    double csx, csy, csz;       /* Third reciprocal lattice axis */
    double m_a, m_b, m_c;       /* length of lattice parameter lengths */
    double m_aa, m_bb, m_cc;    /* lattice angles */
    double sigma_a, sigma_i;    /* abs and inc X sect */
    double rho;                 /* density */
    double at_weight;           /* atomic weight */
    double at_nb;               /* nb of atoms in a cell */
    double V0;                  /* Unit cell volume (AA**3) */
    int column_order[5];        /* column signification [h,k,l,F,F2] */
    int recip;                  /* Flag to indicate if recip or direct cell axes given */
    int shape;                  /* 0:cylinder, 1:box, 2:sphere 3:any shape*/
    int flag_warning;           /* number of warnings */
    int flag_barns;             /* 1: F2 in barns, 0: in fm^2 */
    char type;                  /* type of last event: t=transmit,c=coherent or i=incoherent */
    int h, k, l;                /* last coherent scattering momentum transfer indices */
    int tau_count;              /* Number of reflections within cutoff */
    double coh_refl, coh_xsect; /* cross section computed with last tau_list */
    double kix, kiy, kiz;       /* last incoming neutron ki */
    int nb_reuses, nb_refl, nb_refl_count;
    int max_tau_count;
  };
  #pragma acc routine
  int
  SX_list_compare (void const* a, void const* b) {
    struct hkl_data const* pa = a;
    struct hkl_data const* pb = b;

    /* Sort by tau */
    if (pa->tau < pb->tau)
      return -1;
    if (pa->tau > pb->tau)
      return 1;

    /* Sort by tau_x */
    if (pa->tau_x < pb->tau_x)
      return -1;
    if (pa->tau_x > pb->tau_x)
      return 1;

    /* Sort by tau_y */
    if (pa->tau_y < pb->tau_y)
      return -1;
    if (pa->tau_y > pb->tau_y)
      return 1;

    /* Sort by tau_z */
    if (pa->tau_z < pb->tau_z)
      return -1;
    if (pa->tau_z > pb->tau_z)
      return 1;

    /* In case of tie, sort by F2 also */
    if (pa->F2 < pb->F2)
      return -1;
    if (pa->F2 > pb->F2)
      return 1;

    return 0;
  } /* SX_list_compare */

  #ifndef CIF2HKL
  #define CIF2HKL
  // hkl_filename = cif2hkl(file, options)
  //   used to convert CIF/CFL/INS file into F2(hkl)
  //   the CIF2HKL env var can point to a cif2hkl executable
  //   else the McCode binary is attempted, then the system.
  char*
  cif2hkl (char* infile, char* options) {
    char cmd[1024];
    int ret = 0;
    int found = 0;
    char* OUTFILE;
    char* inpath;

    // get filename extension
    const char* ext = strrchr (infile, '.');
    if (!ext || ext == infile)
      return infile;
    else
      ext++;

    // return input when no extension or not a CIF/FullProf/ShelX file
    if (strcasecmp (ext, "cif") && strcasecmp (ext, "pcr") && strcasecmp (ext, "cfl") && strcasecmp (ext, "shx") && strcasecmp (ext, "ins")
        && strcasecmp (ext, "res"))
      return infile;

    OUTFILE = malloc (1024);
    if (!OUTFILE) {
      free (OUTFILE);
      return infile;
    }
    inpath = malloc (1024);
    if (!inpath) {
      free (OUTFILE);
      free (inpath);
      return infile;
    }

    // get input file path from read-table:Open_File
    FILE* f_infile = Open_File (infile, "r", inpath);
    if (!f_infile) {
      free (OUTFILE);
      free (inpath);
      free (f_infile);
      return infile;
    }
    fclose (f_infile);

    strncpy (OUTFILE, tmpnam (NULL), 1024); // create an output temporary file name

    // try in order the CIF2HKL env var, then the system cif2hkl, then the McCode one
    if (!found && getenv ("CIF2HKL")) {
      snprintf (cmd, 1024, "%s -o %s %s %s", getenv ("CIF2HKL"), OUTFILE, options, inpath);
      ret = system (cmd);
      if (ret != -1 && ret != 127)
        found = 1;
    }
    if (!found) {
      // try with cif2hkl command from the system PATH
      snprintf (cmd, 1024, "%s -o %s %s %s", "cif2hkl", OUTFILE, options, inpath);
      ret = system (cmd);
      if (ret != -1 && ret != 127)
        found = 1;
    }
    if (!found) {
      // As a last resort, attempt with cif2hkl from $MCSTAS/bin
      snprintf (cmd, 1024, "%s%c%s%c%s -o %s %s %s", getenv (FLAVOR_UPPER) ? getenv (FLAVOR_UPPER) : MCSTAS, MC_PATHSEP_C, "bin", MC_PATHSEP_C, "cif2hkl",
                OUTFILE, options, inpath);
      ret = system (cmd);
    }
    // ret = -1:  child process could not be created
    // ret = 127: shell could not be executed in the child process
    if (ret == -1 || ret == 127) {
      free (OUTFILE);
      return (NULL);
    }

    // test if the result file has been created
    FILE* file = fopen (OUTFILE, "r");
    if (!file) {
      free (OUTFILE);
      return (NULL);
    }
    MPI_MASTER (printf ("%s: INFO: Converting %s into F2(HKL) list %s\n", __FILE__, infile, OUTFILE); printf ("%s\n", cmd););
    fflush (NULL);
    fclose (file);
    return (OUTFILE);
  } // cif2hkl
  #endif

  /* ------------------------------------------------------------------------ */
  int
  read_hkl_data (char* SC_file, struct hkl_info_struct* info, struct hkl_data** hkl_list, double SC_mosaic, double SC_mosaic_a, double SC_mosaic_b,
                 double SC_mosaic_c, double* SC_mosaic_AB) {
    struct hkl_data* list = NULL;
    int size = 0;
    t_Table sTable; /* sample data table structure from SC_file */
    int i = 0;
    double tmp_x, tmp_y, tmp_z;
    char** parsing;
    char flag = 0;
    double nb_atoms = 1;
    char* filename = NULL;

    if (!SC_file || !strlen (SC_file) || !strcmp (SC_file, "NULL") || !strcmp (SC_file, "0")) {
      info->count = 0;
      flag = 1;
    }
    if (!flag) {
      filename = cif2hkl (SC_file, "--xtal --mode NUC");
      if (filename != SC_file)
        info->flag_barns = 1;            // cif2hkl returns barns
      Table_Read (&sTable, filename, 1); /* read 1st block data from SC_file into sTable*/
      if (sTable.columns < 4) {
        fprintf (stderr, "Single_crystal: Error: The number of columns in %s should be at least %d for [h,k,l,F2]\n", SC_file, 4);
        return (0);
      }
      if (!sTable.rows) {
        fprintf (stderr, "Single_crystal: Error: The number of rows in %s should be at least %d\n", SC_file, 1);
        return (0);
      } else
        size = sTable.rows;

      /* parsing of header */
      parsing
          = Table_ParseHeader (sTable.header, "sigma_abs", "sigma_a ", "sigma_inc", "sigma_i ", "column_h", "column_k", "column_l", "column_F ", "column_F2",
                               "Delta_d/d", "lattice_a ", "lattice_b ", "lattice_c ", "lattice_aa", "lattice_bb", "lattice_cc", "nb_atoms", "multiplicity", NULL);

      if (parsing) {
        if (parsing[0] && !info->sigma_a)
          info->sigma_a = atof (parsing[0]);
        if (parsing[1] && !info->sigma_a)
          info->sigma_a = atof (parsing[1]);
        if (parsing[2] && !info->sigma_i)
          info->sigma_i = atof (parsing[2]);
        if (parsing[3] && !info->sigma_i)
          info->sigma_i = atof (parsing[3]);
        if (parsing[4])
          info->column_order[0] = atoi (parsing[4]);
        if (parsing[5])
          info->column_order[1] = atoi (parsing[5]);
        if (parsing[6])
          info->column_order[2] = atoi (parsing[6]);
        if (parsing[7])
          info->column_order[3] = atoi (parsing[7]);
        if (parsing[8])
          info->column_order[4] = atoi (parsing[8]);
        if (parsing[9] && info->m_delta_d_d < 0)
          info->m_delta_d_d = atof (parsing[9]);
        if (parsing[10] && !info->m_a)
          info->m_a = atof (parsing[10]);
        if (parsing[11] && !info->m_b)
          info->m_b = atof (parsing[11]);
        if (parsing[12] && !info->m_c)
          info->m_c = atof (parsing[12]);
        if (parsing[13] && !info->m_aa)
          info->m_aa = atof (parsing[13]);
        if (parsing[14] && !info->m_bb)
          info->m_bb = atof (parsing[14]);
        if (parsing[15] && !info->m_cc)
          info->m_cc = atof (parsing[15]);
        if (parsing[16])
          nb_atoms = atof (parsing[16]);
        if (parsing[17])
          nb_atoms = atof (parsing[17]);
        for (i = 0; i <= 17; i++)
          if (parsing[i])
            free (parsing[i]);
        free (parsing);
      }
    }

    if (nb_atoms > 1) {
      info->sigma_a *= nb_atoms;
      info->sigma_i *= nb_atoms;
    }

    /* special cases for the structure definition */
    if (info->m_ax || info->m_ay || info->m_az) {
      info->m_a = 0;
      info->m_aa = 0;
    } /* means we specify by hand the vectors */
    if (info->m_bx || info->m_by || info->m_bz) {
      info->m_b = 0;
      info->m_bb = 0;
    }
    if (info->m_cx || info->m_cy || info->m_cz) {
      info->m_c = 0;
      info->m_cc = 0;
    };

    /* compute the norm from vector a if missing */
    if (info->m_ax || info->m_ay || info->m_az) {
      double as = sqrt (info->m_ax * info->m_ax + info->m_ay * info->m_ay + info->m_az * info->m_az);
      if (!info->m_bx && !info->m_by && !info->m_bz)
        info->m_a = info->m_b = as;
      if (!info->m_cx && !info->m_cy && !info->m_cz)
        info->m_a = info->m_c = as;
    }
    if (info->m_a && !info->m_b)
      info->m_b = info->m_a;
    if (info->m_b && !info->m_c)
      info->m_c = info->m_b;

    /* compute the lattive angles if not set from data file. Not used when in vector mode. */
    if (info->m_a && !info->m_aa)
      info->m_aa = 90;
    if (info->m_aa && !info->m_bb)
      info->m_bb = info->m_aa;
    if (info->m_bb && !info->m_cc)
      info->m_cc = info->m_bb;

    /* parameters consistency checks */
    if (!info->m_ax && !info->m_ay && !info->m_az && !info->m_a) {
      fprintf (stderr, "Single_crystal: Error: Wrong a lattice vector definition\n");
      return (0);
    }
    if (!info->m_bx && !info->m_by && !info->m_bz && !info->m_b) {
      fprintf (stderr, "Single_crystal: Error: Wrong b lattice vector definition\n");
      return (0);
    }
    if (!info->m_cx && !info->m_cy && !info->m_cz && !info->m_c) {
      fprintf (stderr, "Single_crystal: Error: Wrong c lattice vector definition\n");
      return (0);
    }
    if (info->m_aa && info->m_bb && info->m_cc && info->recip) {
      fprintf (stderr, "Single_crystal: Error: Selecting reciprocal cell and angles is unmeaningful\n");
      return (0);
    }

    /* when lengths a,b,c + angles are given (instead of vectors a,b,c) */
    if (info->m_aa && info->m_bb && info->m_cc) {
      MPI_MASTER (printf ("Mode: lengths and angles\n"););
      double as, bs, cs;
      if (info->m_a)
        as = info->m_a;
      else
        as = sqrt (info->m_ax * info->m_ax + info->m_ay * info->m_ay + info->m_az * info->m_az);
      if (info->m_b)
        bs = info->m_b;
      else
        bs = sqrt (info->m_bx * info->m_bx + info->m_by * info->m_by + info->m_bz * info->m_bz);
      if (info->m_c)
        cs = info->m_c;
      else
        cs = sqrt (info->m_cx * info->m_cx + info->m_cy * info->m_cy + info->m_cz * info->m_cz);

      info->m_bz = as;
      info->m_by = 0;
      info->m_bx = 0;
      info->m_az = bs * cos (info->m_cc * DEG2RAD);
      info->m_ay = bs * sin (info->m_cc * DEG2RAD);
      info->m_ax = 0;
      info->m_cz = cs * cos (info->m_bb * DEG2RAD);
      info->m_cy = cs * (cos (info->m_aa * DEG2RAD) - cos (info->m_cc * DEG2RAD) * cos (info->m_bb * DEG2RAD)) / sin (info->m_cc * DEG2RAD);
      info->m_cx = sqrt (cs * cs - info->m_cz * info->m_cz - info->m_cy * info->m_cy);

      MPI_MASTER (
          printf ("Single_crystal: %s structure a=%g b=%g c=%g aa=%g bb=%g cc=%g ", (flag ? "INC" : SC_file), as, bs, cs, info->m_aa, info->m_bb, info->m_cc););
    } else {
      if (!info->recip) {
        MPI_MASTER (printf ("Mode: Direct mode lattice\n");
                    printf ("Single_crystal: %s structure a=[%g,%g,%g] b=[%g,%g,%g] c=[%g,%g,%g] ", (flag ? "INC" : SC_file), info->m_ax, info->m_ay, info->m_az,
                            info->m_bx, info->m_by, info->m_bz, info->m_cx, info->m_cy, info->m_cz););
      } else {
        MPI_MASTER (printf ("Mode: Reciprocal mode lattice\n");
                    printf ("Single_crystal: %s structure a*=[%g,%g,%g] b*=[%g,%g,%g] c*=[%g,%g,%g] ", (flag ? "INC" : SC_file), info->m_ax, info->m_ay,
                            info->m_az, info->m_bx, info->m_by, info->m_bz, info->m_cx, info->m_cy, info->m_cz););
      }
    }
    /* Compute reciprocal or direct lattice vectors. */
    if (!info->recip) {
      vec_prod (tmp_x, tmp_y, tmp_z, info->m_bx, info->m_by, info->m_bz, info->m_cx, info->m_cy, info->m_cz);
      info->V0 = fabs (scalar_prod (info->m_ax, info->m_ay, info->m_az, tmp_x, tmp_y, tmp_z));
      MPI_MASTER (printf ("V0=%g\n", info->V0););

      info->asx = 2 * PI / info->V0 * tmp_x;
      info->asy = 2 * PI / info->V0 * tmp_y;
      info->asz = 2 * PI / info->V0 * tmp_z;
      vec_prod (tmp_x, tmp_y, tmp_z, info->m_cx, info->m_cy, info->m_cz, info->m_ax, info->m_ay, info->m_az);
      info->bsx = 2 * PI / info->V0 * tmp_x;
      info->bsy = 2 * PI / info->V0 * tmp_y;
      info->bsz = 2 * PI / info->V0 * tmp_z;
      vec_prod (tmp_x, tmp_y, tmp_z, info->m_ax, info->m_ay, info->m_az, info->m_bx, info->m_by, info->m_bz);
      info->csx = 2 * PI / info->V0 * tmp_x;
      info->csy = 2 * PI / info->V0 * tmp_y;
      info->csz = 2 * PI / info->V0 * tmp_z;
    } else {
      info->asx = info->m_ax;
      info->asy = info->m_ay;
      info->asz = info->m_az;
      info->bsx = info->m_bx;
      info->bsy = info->m_by;
      info->bsz = info->m_bz;
      info->csx = info->m_cx;
      info->csy = info->m_cy;
      info->csz = info->m_cz;

      vec_prod (tmp_x, tmp_y, tmp_z, info->bsx / (2 * PI), info->bsy / (2 * PI), info->bsz / (2 * PI), info->csx / (2 * PI), info->csy / (2 * PI),
                info->csz / (2 * PI));
      info->V0 = 1 / fabs (scalar_prod (info->asx / (2 * PI), info->asy / (2 * PI), info->asz / (2 * PI), tmp_x, tmp_y, tmp_z));
      MPI_MASTER (printf ("V0=%g\n", info->V0););

      /*compute the direct cell parameters, ofr completeness*/
      info->m_ax = tmp_x * info->V0;
      info->m_ay = tmp_y * info->V0;
      info->m_az = tmp_z * info->V0;
      vec_prod (tmp_x, tmp_y, tmp_z, info->csx / (2 * PI), info->csy / (2 * PI), info->csz / (2 * PI), info->asx / (2 * PI), info->asy / (2 * PI),
                info->asz / (2 * PI));
      info->m_bx = tmp_x * info->V0;
      info->m_by = tmp_y * info->V0;
      info->m_bz = tmp_z * info->V0;
      vec_prod (tmp_x, tmp_y, tmp_z, info->asx / (2 * PI), info->asy / (2 * PI), info->asz / (2 * PI), info->bsx / (2 * PI), info->bsy / (2 * PI),
                info->bsz / (2 * PI));
      info->m_cx = tmp_x * info->V0;
      info->m_cy = tmp_y * info->V0;
      info->m_cz = tmp_z * info->V0;
    }

    if (flag)
      return (-1);

    if (!info->column_order[0] || !info->column_order[1] || !info->column_order[2]) {
      fprintf (stderr, "Single_crystal: Error: Wrong h,k,l column definition\n");
      return (0);
    }
    if (!info->column_order[3] && !info->column_order[4]) {
      fprintf (stderr, "Single_crystal: Error: Wrong F,F2 column definition\n");
      return (0);
    }

    /* allocate hkl_data array */
    list = (struct hkl_data*)malloc (size * sizeof (struct hkl_data));
    if (!list) {
      fprintf (stderr, "Single_crystal: Error allocating reflection list\n");
      return (0);
    }

    for (i = 0; i < size; i++) {
      double h = 0, k = 0, l = 0, F2 = 0;
      double b1[3], b2[3];
      double sig1, sig2, sig3;

      /* get data from table */
      h = Table_Index (sTable, i, info->column_order[0] - 1);
      k = Table_Index (sTable, i, info->column_order[1] - 1);
      l = Table_Index (sTable, i, info->column_order[2] - 1);
      if (info->column_order[3]) {
        F2 = Table_Index (sTable, i, info->column_order[3] - 1);
        F2 *= F2;
      } else if (info->column_order[4])
        F2 = Table_Index (sTable, i, info->column_order[4] - 1);

      list[i].h = h;
      list[i].k = k;
      list[i].l = l;
      list[i].F2 = F2;

      /* Precompute some values */
      list[i].tau_x = h * info->asx + k * info->bsx + l * info->csx;
      list[i].tau_y = h * info->asy + k * info->bsy + l * info->csy;
      list[i].tau_z = h * info->asz + k * info->bsz + l * info->csz;
      list[i].tau = sqrt (list[i].tau_x * list[i].tau_x + list[i].tau_y * list[i].tau_y + list[i].tau_z * list[i].tau_z);
      list[i].u1x = list[i].tau_x / list[i].tau;
      list[i].u1y = list[i].tau_y / list[i].tau;
      list[i].u1z = list[i].tau_z / list[i].tau;
      sig1 = FWHM2RMS * info->m_delta_d_d * list[i].tau;

      /* Find two arbitrary axes perpendicular to tau and each other. */
      normal_vec (&b1[0], &b1[1], &b1[2], list[i].u1x, list[i].u1y, list[i].u1z);
      vec_prod (b2[0], b2[1], b2[2], list[i].u1x, list[i].u1y, list[i].u1z, b1[0], b1[1], b1[2]);

      /* Find the two mosaic axes perpendicular to tau. */
      if (SC_mosaic > 0) {
        /* Use isotropic mosaic. */
        list[i].u2x = b1[0];
        list[i].u2y = b1[1];
        list[i].u2z = b1[2];
        sig2 = FWHM2RMS * list[i].tau * MIN2RAD * SC_mosaic;
        list[i].u3x = b2[0];
        list[i].u3y = b2[1];
        list[i].u3z = b2[2];
        sig3 = FWHM2RMS * list[i].tau * MIN2RAD * SC_mosaic;
      } else if (SC_mosaic_a > 0 && SC_mosaic_b > 0 && SC_mosaic_c > 0) {
        /* Use anisotropic mosaic. */
        fprintf (stderr, "Single_crystal: Warning: you are using an experimental feature:\n"
                         "  anistropic mosaicity. Please examine your data carefully.\n");
        /* compute the jacobian of (tau_v,tau_n) from rotations around the unit cell vectors. */
        struct hkl_data* l = &(list[i]);
        double xia_x, xia_y, xia_z, xib_x, xib_y, xib_z, xic_x, xic_y, xic_z;
        /*input parameters are in arc minutes*/
        double sig_fi_a = SC_mosaic_a * MIN2RAD;
        double sig_fi_b = SC_mosaic_b * MIN2RAD;
        double sig_fi_c = SC_mosaic_c * MIN2RAD;
        if (info->m_a == 0)
          info->m_a = sqrt (scalar_prod (info->m_ax, info->m_ay, info->m_az, info->m_ax, info->m_ay, info->m_az));
        if (info->m_b == 0)
          info->m_b = sqrt (scalar_prod (info->m_bx, info->m_by, info->m_bz, info->m_bx, info->m_by, info->m_bz));
        if (info->m_c == 0)
          info->m_c = sqrt (scalar_prod (info->m_cx, info->m_cy, info->m_cz, info->m_cx, info->m_cy, info->m_cz));

        l->u2x = b1[0];
        l->u2y = b1[1];
        l->u2z = b1[2];
        l->u3x = b2[0];
        l->u3y = b2[1];
        l->u3z = b2[2];

        xia_x = l->tau_x - (M_2_PI * h / info->m_a) * info->asx;
        xia_y = l->tau_y - (M_2_PI * h / info->m_a) * info->asy;
        xia_z = l->tau_z - (M_2_PI * h / info->m_a) * info->asz;
        xib_x = l->tau_x - (M_2_PI * h / info->m_b) * info->bsx;
        xib_y = l->tau_y - (M_2_PI * h / info->m_b) * info->bsy;
        xib_z = l->tau_z - (M_2_PI * h / info->m_b) * info->bsz;
        xic_x = l->tau_x - (M_2_PI * h / info->m_c) * info->csx;
        xic_y = l->tau_y - (M_2_PI * h / info->m_c) * info->csy;
        xic_z = l->tau_z - (M_2_PI * h / info->m_c) * info->csz;

        double xia = sqrt (xia_x * xia_x + xia_y * xia_y + xia_z * xia_z);
        double xib = sqrt (xib_x * xib_x + xib_y * xib_y + xib_z * xib_z);
        double xic = sqrt (xic_x * xic_x + xic_y * xic_y + xic_z * xic_z);

        vec_prod (tmp_x, tmp_y, tmp_z, l->tau_x, l->tau_y, l->tau_z, l->u2x, l->u2y, l->u2z);
        double J_n_fia = xia / info->m_a / l->tau * scalar_prod (info->asx, info->asy, info->asz, tmp_x, tmp_y, tmp_z);
        vec_prod (tmp_x, tmp_y, tmp_z, l->tau_x, l->tau_y, l->tau_z, l->u2x, l->u2y, l->u2z);
        double J_n_fib = xib / info->m_b / l->tau * scalar_prod (info->bsx, info->bsy, info->bsz, tmp_x, tmp_y, tmp_z);
        vec_prod (tmp_x, tmp_y, tmp_z, l->tau_x, l->tau_y, l->tau_z, l->u2x, l->u2y, l->u2z);
        double J_n_fic = xic / info->m_c / l->tau * scalar_prod (info->csx, info->csy, info->csz, tmp_x, tmp_y, tmp_z);

        vec_prod (tmp_x, tmp_y, tmp_z, l->tau_x, l->tau_y, l->tau_z, l->u3x, l->u3y, l->u3z);
        double J_v_fia = xia / info->m_a / l->tau * scalar_prod (info->asx, info->asy, info->asz, tmp_x, tmp_y, tmp_z);
        vec_prod (tmp_x, tmp_y, tmp_z, l->tau_x, l->tau_y, l->tau_z, l->u3x, l->u3y, l->u3z);
        double J_v_fib = xib / info->m_b / l->tau * scalar_prod (info->bsx, info->bsy, info->bsz, tmp_x, tmp_y, tmp_z);
        vec_prod (tmp_x, tmp_y, tmp_z, l->tau_x, l->tau_y, l->tau_z, l->u3x, l->u3y, l->u3z);
        double J_v_fic = xic / info->m_c / l->tau * scalar_prod (info->csx, info->csy, info->csz, tmp_x, tmp_y, tmp_z);

        /*with the jacobian we can compute the sigmas in terms of the orthogonal vectors u2 and u3*/
        sig2 = sig_fi_a * fabs (J_v_fia) + sig_fi_b * fabs (J_v_fib) + sig_fi_c * fabs (J_v_fic);
        sig3 = sig_fi_a * fabs (J_n_fia) + sig_fi_b * fabs (J_n_fib) + sig_fi_c * fabs (J_n_fic);
      } else if (SC_mosaic_AB[0] != 0 && SC_mosaic_AB[1] != 0) {
        if ((SC_mosaic_AB[2] == 0 && SC_mosaic_AB[3] == 0 && SC_mosaic_AB[4] == 0) || (SC_mosaic_AB[5] == 0 && SC_mosaic_AB[6] == 0 && SC_mosaic_AB[7] == 0)) {
          fprintf (stderr, "Single_crystal: Error: in-plane mosaics are specified but one (or both)\n"
                           "  in-plane reciprocal vector is the zero vector\n");
          return (0);
        }
        fprintf (stderr, "Single_crystal: Warning: you are using an experimental feature: \n"
                         "  \"in-plane\" anistropic mosaicity. Please examine your data carefully.\n");

        /*for given reflection in list - compute linear comb of tau_a and tau_b*/
        /*check for not in plane - f.i. check if (tau_a X tau_b).tau_i)==0*/
        struct hkl_data* l = &(list[i]);
        double det, c1, c2, sig_tau_c;
        double em_x, em_y, em_z, tmp_x, tmp_y, tmp_z;
        double tau_a[3], tau_b[3];
        /*convert Miller indices to taus*/
        if (info->m_a == 0)
          info->m_a = sqrt (scalar_prod (info->m_ax, info->m_ay, info->m_az, info->m_ax, info->m_ay, info->m_az));
        if (info->m_b == 0)
          info->m_b = sqrt (scalar_prod (info->m_bx, info->m_by, info->m_bz, info->m_bx, info->m_by, info->m_bz));
        if (info->m_c == 0)
          info->m_c = sqrt (scalar_prod (info->m_cx, info->m_cy, info->m_cz, info->m_cx, info->m_cy, info->m_cz));
        tau_a[0] = M_2_PI * ((SC_mosaic_AB[2] / info->m_a) * info->asx + (SC_mosaic_AB[3] / info->m_b) * info->bsx + (SC_mosaic_AB[4] / info->m_c) * info->csx);
        tau_a[1] = M_2_PI * ((SC_mosaic_AB[2] / info->m_a) * info->asy + (SC_mosaic_AB[3] / info->m_b) * info->bsy + (SC_mosaic_AB[4] / info->m_c) * info->csy);
        tau_a[2] = M_2_PI * ((SC_mosaic_AB[2] / info->m_a) * info->asz + (SC_mosaic_AB[3] / info->m_b) * info->bsz + (SC_mosaic_AB[4] / info->m_c) * info->csz);
        tau_b[0] = M_2_PI * ((SC_mosaic_AB[5] / info->m_a) * info->asx + (SC_mosaic_AB[6] / info->m_b) * info->bsx + (SC_mosaic_AB[7] / info->m_c) * info->csx);
        tau_b[1] = M_2_PI * ((SC_mosaic_AB[5] / info->m_a) * info->asy + (SC_mosaic_AB[6] / info->m_b) * info->bsy + (SC_mosaic_AB[7] / info->m_c) * info->csy);
        tau_b[2] = M_2_PI * ((SC_mosaic_AB[5] / info->m_a) * info->asz + (SC_mosaic_AB[6] / info->m_b) * info->bsz + (SC_mosaic_AB[7] / info->m_c) * info->csz);

        /*check determinants to see how we should compute the linear combination of a and b (to match c)*/
        c1 = c2 = 0;
        if ((det = tau_a[0] * tau_b[1] - tau_a[1] * tau_b[0]) != 0) {
          c1 = (l->tau_x * tau_b[1] - l->tau_y * tau_b[0]) / det;
          c2 = (tau_a[0] * l->tau_y - tau_a[1] * l->tau_x) / det;
        } else if ((det = tau_a[1] * tau_b[2] - tau_a[2] * tau_b[1]) != 0) {
          c1 = (l->tau_y * tau_b[2] - l->tau_z * tau_b[1]) / det;
          c2 = (tau_a[1] * l->tau_z - tau_a[2] * l->tau_y) / det;
        } else if ((det = tau_a[0] * tau_b[2] - tau_a[2] * tau_b[0]) != 0) {
          c1 = (l->tau_x * tau_b[2] - l->tau_z * tau_b[0]) / det;
          c2 = (tau_a[0] * l->tau_z - tau_a[2] * l->tau_x) / det;
        }
        if ((c1 == 0) && (c2 == 0)) {
          fprintf (stderr,
                   "Single_crystal: Warning: reflection tau[%i]=(%g %g %g) "
                   "has no component in defined mosaic plane\n",
                   i, l->tau_x, l->tau_y, l->tau_z);
        }
        /*compute linear combination => sig_tau_i = | c1*sig_tau_a + c2*sig_tau_b |  - also add in the minute to radian scaling factor*/;
        sig_tau_c = MIN2RAD * sqrt (c1 * SC_mosaic_AB[0] * c1 * SC_mosaic_AB[0] + c2 * SC_mosaic_AB[1] * c2 * SC_mosaic_AB[1]);
        l->u2x = b1[0];
        l->u2y = b1[1];
        l->u2z = b1[2];
        l->u3x = b2[0];
        l->u3y = b2[1];
        l->u3z = b2[2];

        /*so now let's compute the rotation around planenormal tau_a X tau_b*/
        /*g_bar (unit normal of rotation plane) = tau_a X tau_b / norm(tau_a X tau_b)*/
        vec_prod (tmp_x, tmp_y, tmp_z, tau_a[0], tau_a[1], tau_a[2], tau_b[0], tau_b[1], tau_b[2]);
        vec_prod (em_x, em_y, em_z, l->tau_x, l->tau_y, l->tau_z, tmp_x, tmp_y, tmp_z);
        NORM (em_x, em_y, em_z);
        sig2 = l->tau * sig_tau_c * fabs (scalar_prod (em_x, em_y, em_z, l->u2x, l->u2y, l->u2z));
        sig3 = l->tau * sig_tau_c * fabs (scalar_prod (em_x, em_y, em_z, l->u3x, l->u3y, l->u3z));
        /*protect against collapsing gaussians. These seem to be sensible values.*/
        if (sig2 < 1e-5)
          sig2 = 1e-5;
        if (sig3 < 1e-5)
          sig3 = 1e-5;
      } else {
        fprintf (stderr, "Single_crystal: Error: EITHER mosaic OR (mosaic_a, mosaic_b, mosaic_c)\n"
                         "  must be given and be >0.\n");
        return (0);
      }
      list[i].sig123 = sig1 * sig2 * sig3;
      list[i].m1 = 1 / (2 * sig1 * sig1);
      list[i].m2 = 1 / (2 * sig2 * sig2);
      list[i].m3 = 1 / (2 * sig3 * sig3);
      /* Set Gauss cutoff to 5 times the maximal sigma. */
      if (sig1 > sig2)
        if (sig1 > sig3)
          list[i].cutoff = 5 * sig1;
        else
          list[i].cutoff = 5 * sig3;
      else if (sig2 > sig3)
        list[i].cutoff = 5 * sig2;
      else
        list[i].cutoff = 5 * sig3;
    }
    Table_Free (&sTable);

    /* sort the list with increasing tau */
    qsort (list, i, sizeof (struct hkl_data), SX_list_compare);

    *hkl_list = list;
    info->count = i;

    // remove temporary F2(hkl) file when giving CFL/CIF/ShelX file
    if (filename != SC_file)
      unlink (filename);

    return (info->count);
  } /* read_hkl_data */

  /* ------------------------------------------------------------------------ */
  /* hkl_search
    search the HKL reflections which are on the Ewald sphere
    input:
      L,T,count,V0: constants for all calls
      kix,kiy,kiz: may be different for each call
    this function returns:
      tau_count (return), coh_refl, coh_xsect, T (updated elements in the array up to [j])
   */
  #pragma acc routine
  int
  hkl_search (struct hkl_data* L, void* TT, int count, double V0, double kix, double kiy, double kiz, double tau_max, double* coh_refl, double* coh_xsect) {
    double rho, rho_x, rho_y, rho_z;
    double diff;
    int i, j;
    double ox, oy, oz;
    double b1x, b1y, b1z, b2x, b2y, b2z, kx, ky, kz, nx, ny, nz;
    double n11, n22, n12, det_N, inv_n11, inv_n22, inv_n12, l11, l22, l12, det_L;
    double Bt_D_O_x, Bt_D_O_y, y0x, y0y, alpha;

    double ki = sqrt (kix * kix + kiy * kiy + kiz * kiz);
    int jglobal = -1;
    double coherent_refl, coherent_xsect;

    struct tau_data* T = (struct tau_data*)TT;

    // coherent_refl = *coh_refl;
    // coherent_xsect = *coh_xsect;
    coherent_refl = 0;
    coherent_xsect = 0;

    /* Common factor in coherent cross-section */
    double xsect_factor = pow (2 * PI, 5.0 / 2.0) / (V0 * ki * ki);
    j = 0;
    for (i = 0; i < count; i++) {
      /* Assuming reflections are sorted, stop search when max tau exceeded. */
      if (L[i].tau > tau_max)
        break;
      /* Check if this reciprocal lattice point is close enough to the
         Ewald sphere to make scattering possible. */
      rho_x = kix - L[i].tau_x;
      rho_y = kiy - L[i].tau_y;
      rho_z = kiz - L[i].tau_z;
      rho = sqrt (rho_x * rho_x + rho_y * rho_y + rho_z * rho_z);
      diff = fabs (rho - ki);

      /* Check if scattering is possible (cutoff of Gaussian tails). */
      if (diff <= L[i].cutoff) {
        /* Store reflection. */
        T[j].index = i;
        /* Get ki vector in local coordinates. */
        kx = kix * L[i].u1x + kiy * L[i].u1y + kiz * L[i].u1z;
        ky = kix * L[i].u2x + kiy * L[i].u2y + kiz * L[i].u2z;
        kz = kix * L[i].u3x + kiy * L[i].u3y + kiz * L[i].u3z;
        T[j].rho_x = kx - L[i].tau;
        T[j].rho_y = ky;
        T[j].rho_z = kz;
        T[j].rho = rho;
        /* Compute the tangent plane of the Ewald sphere. */
        nx = T[j].rho_x / T[j].rho;
        ny = T[j].rho_y / T[j].rho;
        nz = T[j].rho_z / T[j].rho;
        ox = (ki - T[j].rho) * nx;
        oy = (ki - T[j].rho) * ny;
        oz = (ki - T[j].rho) * nz;
        T[j].ox = ox;
        T[j].oy = oy;
        T[j].oz = oz;
        /* Compute unit vectors b1 and b2 that span the tangent plane. */
        normal_vec (&b1x, &b1y, &b1z, nx, ny, nz);
        vec_prod (b2x, b2y, b2z, nx, ny, nz, b1x, b1y, b1z);
        T[j].b1x = b1x;
        T[j].b1y = b1y;
        T[j].b1z = b1z;
        T[j].b2x = b2x;
        T[j].b2y = b2y;
        T[j].b2z = b2z;
        /* Compute the 2D projection of the 3D Gauss of the reflection. */
        /* The symmetric 2x2 matrix N describing the 2D gauss. */
        n11 = L[i].m1 * b1x * b1x + L[i].m2 * b1y * b1y + L[i].m3 * b1z * b1z;
        n12 = L[i].m1 * b1x * b2x + L[i].m2 * b1y * b2y + L[i].m3 * b1z * b2z;
        n22 = L[i].m1 * b2x * b2x + L[i].m2 * b2y * b2y + L[i].m3 * b2z * b2z;
        /* The (symmetric) inverse matrix of N. */
        det_N = n11 * n22 - n12 * n12;
        inv_n11 = n22 / det_N;
        inv_n12 = -n12 / det_N;
        inv_n22 = n11 / det_N;
        /* The Cholesky decomposition of 1/2*inv_n (lower triangular L). */
        l11 = sqrt (inv_n11 / 2);
        l12 = inv_n12 / (2 * l11);
        l22 = sqrt (inv_n22 / 2 - l12 * l12);
        T[j].l11 = l11;
        T[j].l12 = l12;
        T[j].l22 = l22;
        det_L = l11 * l22;
        /* The product B^T D o. */
        Bt_D_O_x = b1x * L[i].m1 * ox + b1y * L[i].m2 * oy + b1z * L[i].m3 * oz;
        Bt_D_O_y = b2x * L[i].m1 * ox + b2y * L[i].m2 * oy + b2z * L[i].m3 * oz;
        /* Center of 2D Gauss in plane coordinates. */
        y0x = -(Bt_D_O_x * inv_n11 + Bt_D_O_y * inv_n12);
        y0y = -(Bt_D_O_x * inv_n12 + Bt_D_O_y * inv_n22);
        T[j].y0x = y0x;
        T[j].y0y = y0y;
        /* Factor alpha for the distance of the 2D Gauss from the origin. */
        alpha = L[i].m1 * ox * ox + L[i].m2 * oy * oy + L[i].m3 * oz * oz - (y0x * y0x * n11 + y0y * y0y * n22 + 2 * y0x * y0y * n12);
        T[j].refl = xsect_factor * det_L * exp (-alpha) / L[i].sig123; /* intensity of that Bragg */
        *coh_refl += T[j].refl;                                        /* total scatterable intensity*/
        T[j].xsect = T[j].refl * L[i].F2;
        *coh_xsect += T[j].xsect;
        j++;
      }
      /*protect against tau shortlist buffer overrrun*/
      if (j == MCSX_REFL_SLIST_SIZE) {
        break;
      }
    } /* end for */
    return (j); // this is 'tau_count', i.e. number of reachable reflections
  } /* end hkl_search */

  #pragma acc routine
  int
  hkl_select (struct tau_data* T, int tau_count, double coh_refl, double* sum, _class_particle* _particle) {
    int j;
    double r = rand0max (coh_refl);
    *sum = 0;
    for (j = 0; j < tau_count; j++) {
      *sum += T[j].refl;
      if (*sum > r)
        break;
    }
    return j;
  }

  /* Functions for "reorientation", powder and PG modes */
  /* Powder, forward */
  #pragma acc routine
  void
  randrotate (double* nx, double* ny, double* nz, double a, double b, double c) {
    double x1, y1, z1, x2, y2, z2;
    rotate (x1, y1, z1, *nx, *ny, *nz, a, 1, 0, 0); /* <1> = rot(<n>,a) */
    rotate (x2, y2, z2, x1, y1, z1, b, 0, 1, 0);    /* <2> = rot(<1>,b) */
    rotate (*nx, *ny, *nz, x2, y2, z2, c, 0, 0, 1); /* <n> = rot(<2>,c) */
  }
  /* Powder, back */
  #pragma acc routine
  void
  randderotate (double* nx, double* ny, double* nz, double a, double b, double c) {
    double x1, y1, z1, x2, y2, z2;
    rotate (x1, y1, z1, *nx, *ny, *nz, -c, 0, 0, 1);
    rotate (x2, y2, z2, x1, y1, z1, -b, 0, 1, 0);
    rotate (*nx, *ny, *nz, x2, y2, z2, -a, 1, 0, 0);
  }
  /* PG, forward */
  #pragma acc routine
  void
  PGrotate (double* nx, double* ny, double* nz, double a, double csx, double csy, double csz) {
    /* Currently assumes c-axis along 'x', ought to be generalized... */
    double nvx, nvy, nvz;
    rotate (nvx, nvy, nvz, *nx, *ny, *nz, a, csx, csy, csz);
    *nx = nvx;
    *ny = nvy;
    *nz = nvz;
  }
  /* PG, back */
  #pragma acc routine
  void
  PGderotate (double* nx, double* ny, double* nz, double a, double csx, double csy, double csz) {
    /* Currently assumes c-axis along 'x', ought to be generalized... */
    double nvx, nvy, nvz;
    rotate (nvx, nvy, nvz, *nx, *ny, *nz, -a, csx, csy, csz);
    *nx = nvx;
    *ny = nvy;
    *nz = nvz;
  }

  #pragma acc routine
  /* rotate vector counterclockwise */
  void
  vec_rotate_2d (double* x, double* y, double angle) {
    double c, s;
    double newx, newy;

    c = cos (angle);
    s = sin (angle);

    newx = *x * c - *y * s;
    newy = *x * s + *y * c;

    *x = newx;
    *y = newy;
  }

  #ifdef USE_OPENCL
  struct opencl_context oclContext_SX;
  cl_mem d_T = NULL, d_tau_count = NULL, d_coh_refl = NULL, d_coh_xsect = NULL; // OpenCL device buffers
  cl_mem d_L = NULL;
  #endif

  #endif /* !SINGLE_CRYSTAL_DECL */



/* ************************************************************************** */
/*             End of SHARE user declarations for all components              */
/* ************************************************************************** */


/* ********************** component definition declarations. **************** */


/* Parameters for component type 'Progress_bar' */
struct _struct_Progress_bar {
  char     _name[256]; /* e.g. Origin */
  char     _type[256]; /* Progress_bar */
  long     _index; /* e.g. 1 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  /* Component type 'Progress_bar' setting parameters */
  char profile[16384];
  MCNUM percent;
  MCNUM flag_save;
  MCNUM minutes;
  /* Component type 'Progress_bar' private parameters */
  double  IntermediateCnts;
  time_t  StartTime;
  time_t  EndTime;
  time_t  CurrentTime;
  char  infostring[64];
};
typedef struct _struct_Progress_bar _class_Progress_bar;
_class_Progress_bar _Origin_var;


/* Parameters for component type 'Source_simple' */
struct _struct_Source_simple {
  char     _name[256]; /* e.g. source */
  char     _type[256]; /* Source_simple */
  long     _index; /* e.g. 2 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  /* Component type 'Source_simple' setting parameters */
  MCNUM radius;
  MCNUM yheight;
  MCNUM xwidth;
  MCNUM dist;
  MCNUM focus_xw;
  MCNUM focus_yh;
  MCNUM E0;
  MCNUM dE;
  MCNUM lambda0;
  MCNUM dlambda;
  MCNUM flux;
  MCNUM gauss;
  int target_index;
  /* Component type 'Source_simple' private parameters */
  double  pmul;
  double  srcArea;
  int  square;
  double  tx;
  double  ty;
  double  tz;
};
typedef struct _struct_Source_simple _class_Source_simple;
_class_Source_simple _source_var;


/* Parameters for component type 'Slit' */
struct _struct_Slit {
  char     _name[256]; /* e.g. slit */
  char     _type[256]; /* Slit */
  long     _index; /* e.g. 3 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  /* Component type 'Slit' setting parameters */
  MCNUM xmin;
  MCNUM xmax;
  MCNUM ymin;
  MCNUM ymax;
  MCNUM radius;
  MCNUM xwidth;
  MCNUM yheight;
  /* Component type 'Slit' private parameters */
  char  isradial;
};
typedef struct _struct_Slit _class_Slit;
_class_Slit _slit_var;


/* Parameters for component type 'Single_crystal' */
struct _struct_Single_crystal {
  char     _name[256]; /* e.g. sample */
  char     _type[256]; /* Single_crystal */
  long     _index; /* e.g. 4 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  /* Component type 'Single_crystal' setting parameters */
  char reflections[16384];
  char geometry[16384];
  MCNUM mosaic_AB[8];
  MCNUM xwidth;
  MCNUM yheight;
  MCNUM zdepth;
  MCNUM radius;
  MCNUM delta_d_d;
  MCNUM mosaic;
  MCNUM mosaic_a;
  MCNUM mosaic_b;
  MCNUM mosaic_c;
  MCNUM recip_cell;
  MCNUM barns;
  MCNUM ax;
  MCNUM ay;
  MCNUM az;
  MCNUM bx;
  MCNUM by;
  MCNUM bz;
  MCNUM cx;
  MCNUM cy;
  MCNUM cz;
  MCNUM p_transmit;
  MCNUM sigma_abs;
  MCNUM sigma_inc;
  MCNUM aa;
  MCNUM bb;
  MCNUM cc;
  MCNUM order;
  MCNUM extra_order;
  MCNUM RX;
  MCNUM RY;
  MCNUM powder;
  MCNUM PG;
  MCNUM deltak;
  /* Component type 'Single_crystal' private parameters */
  struct hkl_info_struct  hkl_info;
  off_struct  offdata;
  struct hkl_data*  hkl_list;
  struct tau_data  tau_list[MCSX_REFL_SLIST_SIZE];
};
typedef struct _struct_Single_crystal _class_Single_crystal;
_class_Single_crystal _sample_var;


/* Parameters for component type 'PSD_monitor_4PI' */
struct _struct_PSD_monitor_4PI {
  char     _name[256]; /* e.g. det */
  char     _type[256]; /* PSD_monitor_4PI */
  long     _index; /* e.g. 5 index in TRACE list */
  Coords   _position_absolute;
  Coords   _position_relative; /* wrt PREVIOUS */
  Rotation _rotation_absolute;
  Rotation _rotation_relative; /* wrt PREVIOUS */
  int      _rotation_is_identity;
  int      _position_relative_is_zero;
  /* Component type 'PSD_monitor_4PI' setting parameters */
  int nx;
  int ny;
  char filename[16384];
  int nowritefile;
  MCNUM radius;
  int restore_neutron;
  /* Component type 'PSD_monitor_4PI' private parameters */
  DArray2d  PSD_N;
  DArray2d  PSD_p;
  DArray2d  PSD_p2;
};
typedef struct _struct_PSD_monitor_4PI _class_PSD_monitor_4PI;
_class_PSD_monitor_4PI _det_var;

int mcNUMCOMP = 5;

/* User declarations from instrument definition. Can define functions. */

#undef compcurname
#undef compcurtype
#undef compcurindex
/* end of instrument 'templateNMX' and components DECLARE */

/* *****************************************************************************
* instrument 'templateNMX' and components INITIALISE
***************************************************************************** */

double index_getdistance(int first_index, int second_index)
/* Calculate the distance two components from their indexes*/
{
  return coords_len(coords_sub(POS_A_COMP_INDEX(first_index), POS_A_COMP_INDEX(second_index)));
}

double getdistance(char* first_component, char* second_component)
/* Calculate the distance between two named components */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  return index_getdistance(first_index, second_index);
}

double checked_setpos_getdistance(int current_index, char* first_component, char* second_component)
/* Calculate the distance between two named components at *_setpos() time, with component index checking */
{
  int first_index = _getcomp_index(first_component);
  int second_index = _getcomp_index(second_component);
  if (first_index >= current_index || second_index >= current_index) {
    printf("setpos_getdistance can only be used with the names of components before the current one!\n");
    return 0;
  }
  return index_getdistance(first_index, second_index);
}
#define setpos_getdistance(first, second) checked_setpos_getdistance(current_setpos_index, first, second)

/* component Origin=Progress_bar() SETTING, POSITION/ROTATION */
int _Origin_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_Origin_setpos] component Origin=Progress_bar() SETTING [Progress_bar:0]");
  stracpy(_Origin_var._name, "Origin", 16384);
  stracpy(_Origin_var._type, "Progress_bar", 16384);
  _Origin_var._index=1;
  int current_setpos_index = 1;
  if("NULL" && strlen("NULL"))
    stracpy(_Origin_var.profile, "NULL" ? "NULL" : "", 16384);
  else 
  _Origin_var.profile[0]='\0';
  _Origin_var.percent = 10;
  _Origin_var.flag_save = 0;
  _Origin_var.minutes = 0;


  /* component Origin=Progress_bar() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(_Origin_var._rotation_absolute,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_copy(_Origin_var._rotation_relative, _Origin_var._rotation_absolute);
    _Origin_var._rotation_is_identity =  rot_test_identity(_Origin_var._rotation_relative);
    _Origin_var._position_absolute = coords_set(
      0, 0, 0);
    tc1 = coords_neg(_Origin_var._position_absolute);
    _Origin_var._position_relative = rot_apply(_Origin_var._rotation_absolute, tc1);
  } /* Origin=Progress_bar() AT ROTATED */
  DEBUG_COMPONENT("Origin", _Origin_var._position_absolute, _Origin_var._rotation_absolute);
  instrument->_position_absolute[1] = _Origin_var._position_absolute;
  instrument->_position_relative[1] = _Origin_var._position_relative;
    _Origin_var._position_relative_is_zero =  coords_test_zero(_Origin_var._position_relative);
  instrument->counter_N[1]  = instrument->counter_P[1] = instrument->counter_P2[1] = 0;
  instrument->counter_AbsorbProp[1]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0000_Origin", _Origin_var._position_absolute, _Origin_var._rotation_absolute, "Progress_bar");
        mccomp_param_nexus(nxhandle,"0000_Origin", "profile", "NULL", "NULL", "char*");
        mccomp_param_nexus(nxhandle,"0000_Origin", "percent", "10", "10","MCNUM");
        mccomp_param_nexus(nxhandle,"0000_Origin", "flag_save", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0000_Origin", "minutes", "0", "0","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _Origin_setpos */

/* component source=Source_simple() SETTING, POSITION/ROTATION */
int _source_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_source_setpos] component source=Source_simple() SETTING [Source_simple:0]");
  stracpy(_source_var._name, "source", 16384);
  stracpy(_source_var._type, "Source_simple", 16384);
  _source_var._index=2;
  int current_setpos_index = 2;
  _source_var.radius = 0.02;
  _source_var.yheight = 0;
  _source_var.xwidth = 0;
  _source_var.dist = 0;
  _source_var.focus_xw = 0.001;
  _source_var.focus_yh = 0.001;
  _source_var.E0 = 0;
  _source_var.dE = 0;
  _source_var.lambda0 = 7;
  _source_var.dlambda = 5;
  _source_var.flux = 1e12;
  _source_var.gauss = 0;
  _source_var.target_index = 1;


  /* component source=Source_simple() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(_source_var._rotation_absolute,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_transpose(_Origin_var._rotation_absolute, tr1);
    rot_mul(_source_var._rotation_absolute, tr1, _source_var._rotation_relative);
    _source_var._rotation_is_identity =  rot_test_identity(_source_var._rotation_relative);
    _source_var._position_absolute = coords_set(
      0, 0, 0);
    tc1 = coords_sub(_Origin_var._position_absolute, _source_var._position_absolute);
    _source_var._position_relative = rot_apply(_source_var._rotation_absolute, tc1);
  } /* source=Source_simple() AT ROTATED */
  DEBUG_COMPONENT("source", _source_var._position_absolute, _source_var._rotation_absolute);
  instrument->_position_absolute[2] = _source_var._position_absolute;
  instrument->_position_relative[2] = _source_var._position_relative;
    _source_var._position_relative_is_zero =  coords_test_zero(_source_var._position_relative);
  instrument->counter_N[2]  = instrument->counter_P[2] = instrument->counter_P2[2] = 0;
  instrument->counter_AbsorbProp[2]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0001_source", _source_var._position_absolute, _source_var._rotation_absolute, "Source_simple");
        mccomp_param_nexus(nxhandle,"0001_source", "radius", "0.1", "0.02","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "yheight", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "xwidth", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "dist", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "focus_xw", ".045", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "focus_yh", ".12", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "E0", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "dE", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "lambda0", "0", "7","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "dlambda", "0", "5","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "flux", "1", "1e12","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "gauss", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0001_source", "target_index", "1", "1","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _source_setpos */

/* component slit=Slit() SETTING, POSITION/ROTATION */
int _slit_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_slit_setpos] component slit=Slit() SETTING [Slit:0]");
  stracpy(_slit_var._name, "slit", 16384);
  stracpy(_slit_var._type, "Slit", 16384);
  _slit_var._index=3;
  int current_setpos_index = 3;
  _slit_var.xmin = UNSET;
  _slit_var.xmax = UNSET;
  _slit_var.ymin = UNSET;
  _slit_var.ymax = UNSET;
  _slit_var.radius = UNSET;
  _slit_var.xwidth = 0.001;
  _slit_var.yheight = 0.001;


  /* component slit=Slit() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _source_var._rotation_absolute, _slit_var._rotation_absolute);
    rot_transpose(_source_var._rotation_absolute, tr1);
    rot_mul(_slit_var._rotation_absolute, tr1, _slit_var._rotation_relative);
    _slit_var._rotation_is_identity =  rot_test_identity(_slit_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 5);
    rot_transpose(_source_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _slit_var._position_absolute = coords_add(_source_var._position_absolute, tc2);
    tc1 = coords_sub(_source_var._position_absolute, _slit_var._position_absolute);
    _slit_var._position_relative = rot_apply(_slit_var._rotation_absolute, tc1);
  } /* slit=Slit() AT ROTATED */
  DEBUG_COMPONENT("slit", _slit_var._position_absolute, _slit_var._rotation_absolute);
  instrument->_position_absolute[3] = _slit_var._position_absolute;
  instrument->_position_relative[3] = _slit_var._position_relative;
    _slit_var._position_relative_is_zero =  coords_test_zero(_slit_var._position_relative);
  instrument->counter_N[3]  = instrument->counter_P[3] = instrument->counter_P2[3] = 0;
  instrument->counter_AbsorbProp[3]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0002_slit", _slit_var._position_absolute, _slit_var._rotation_absolute, "Slit");
        mccomp_param_nexus(nxhandle,"0002_slit", "xmin", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_slit", "xmax", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_slit", "ymin", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_slit", "ymax", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_slit", "radius", "UNSET", "UNSET","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_slit", "xwidth", "UNSET", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0002_slit", "yheight", "UNSET", "0.001","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _slit_setpos */

/* component sample=Single_crystal() SETTING, POSITION/ROTATION */
int _sample_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_sample_setpos] component sample=Single_crystal() SETTING [Single_crystal:0]");
  stracpy(_sample_var._name, "sample", 16384);
  stracpy(_sample_var._type, "Single_crystal", 16384);
  _sample_var._index=4;
  int current_setpos_index = 4;
  if(_instrument_var.reflections && strlen(_instrument_var.reflections))
    stracpy(_sample_var.reflections, _instrument_var.reflections ? _instrument_var.reflections : "", 16384);
  else 
  _sample_var.reflections[0]='\0';
  _sample_var.geometry[0]='\0';
  _sample_var.mosaic_AB[0] = 0;
  _sample_var.mosaic_AB[1] = 0;
  _sample_var.mosaic_AB[2] = 0;
  _sample_var.mosaic_AB[3] = 0;
  _sample_var.mosaic_AB[4] = 0;
  _sample_var.mosaic_AB[5] = 0;
  _sample_var.mosaic_AB[6] = 0;
  _sample_var.mosaic_AB[7] = 0;
  _sample_var.xwidth = 0.001;
  _sample_var.yheight = 0.001;
  _sample_var.zdepth = 0.001;
  _sample_var.radius = 0;
  _sample_var.delta_d_d = 1e-4;
  _sample_var.mosaic = 1e-4;
  _sample_var.mosaic_a = -1;
  _sample_var.mosaic_b = -1;
  _sample_var.mosaic_c = -1;
  _sample_var.recip_cell = 0;
  _sample_var.barns = 0;
  _sample_var.ax = 0;
  _sample_var.ay = 0;
  _sample_var.az = 0;
  _sample_var.bx = 0;
  _sample_var.by = 0;
  _sample_var.bz = 0;
  _sample_var.cx = 0;
  _sample_var.cy = 0;
  _sample_var.cz = 0;
  _sample_var.p_transmit = 0.001;
  _sample_var.sigma_abs = 0;
  _sample_var.sigma_inc = 0;
  _sample_var.aa = 0;
  _sample_var.bb = 0;
  _sample_var.cc = 0;
  _sample_var.order = 1;
  _sample_var.extra_order = 0;
  _sample_var.RX = 0;
  _sample_var.RY = 0;
  _sample_var.powder = 0;
  _sample_var.PG = 0;
  _sample_var.deltak = 1e-6;


  /* component sample=Single_crystal() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _slit_var._rotation_absolute, _sample_var._rotation_absolute);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    rot_mul(_sample_var._rotation_absolute, tr1, _sample_var._rotation_relative);
    _sample_var._rotation_is_identity =  rot_test_identity(_sample_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0.10);
    rot_transpose(_slit_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _sample_var._position_absolute = coords_add(_slit_var._position_absolute, tc2);
    tc1 = coords_sub(_slit_var._position_absolute, _sample_var._position_absolute);
    _sample_var._position_relative = rot_apply(_sample_var._rotation_absolute, tc1);
  } /* sample=Single_crystal() AT ROTATED */
  DEBUG_COMPONENT("sample", _sample_var._position_absolute, _sample_var._rotation_absolute);
  instrument->_position_absolute[4] = _sample_var._position_absolute;
  instrument->_position_relative[4] = _sample_var._position_relative;
    _sample_var._position_relative_is_zero =  coords_test_zero(_sample_var._position_relative);
  instrument->counter_N[4]  = instrument->counter_P[4] = instrument->counter_P2[4] = 0;
  instrument->counter_AbsorbProp[4]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0003_sample", _sample_var._position_absolute, _sample_var._rotation_absolute, "Single_crystal");
        mccomp_param_nexus(nxhandle,"0003_sample", "reflections", 0, _instrument_var.reflections, "char*");
        mccomp_param_nexus(nxhandle,"0003_sample", "geometry", 0, 0, "char*");
        mccomp_param_nexus(nxhandle,"0003_sample", "mosaic_AB", "{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }", "{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "xwidth", "0", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "yheight", "0", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "zdepth", "0", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "radius", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "delta_d_d", "1e-4", "1e-4","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "mosaic", "-1", "1e-4","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "mosaic_a", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "mosaic_b", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "mosaic_c", "-1", "-1","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "recip_cell", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "barns", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "ax", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "ay", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "az", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "bx", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "by", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "bz", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "cx", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "cy", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "cz", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "p_transmit", "0.001", "0.001","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "sigma_abs", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "sigma_inc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "aa", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "bb", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "cc", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "order", "0", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "extra_order", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "RX", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "RY", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "powder", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "PG", "0", "0","MCNUM");
        mccomp_param_nexus(nxhandle,"0003_sample", "deltak", "1e-6", "1e-6","MCNUM");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _sample_setpos */

/* component det=PSD_monitor_4PI() SETTING, POSITION/ROTATION */
int _det_setpos(void)
{ /* sets initial component parameters, position and rotation */
  SIG_MESSAGE("[_det_setpos] component det=PSD_monitor_4PI() SETTING [PSD_monitor_4PI:0]");
  stracpy(_det_var._name, "det", 16384);
  stracpy(_det_var._type, "PSD_monitor_4PI", 16384);
  _det_var._index=5;
  int current_setpos_index = 5;
  _det_var.nx = 360;
  _det_var.ny = 180;
  if("psd" && strlen("psd"))
    stracpy(_det_var.filename, "psd" ? "psd" : "", 16384);
  else 
  _det_var.filename[0]='\0';
  _det_var.nowritefile = 0;
  _det_var.radius = 1;
  _det_var.restore_neutron = 0;


  /* component det=PSD_monitor_4PI() AT ROTATED */
  {
    Coords tc1, tc2;
    tc1 = coords_set(0,0,0);
    tc2 = coords_set(0,0,0);
    Rotation tr1;
    rot_set_rotation(tr1,0,0,0);
    rot_set_rotation(tr1,
      (0.0)*DEG2RAD, (0.0)*DEG2RAD, (0.0)*DEG2RAD);
    rot_mul(tr1, _sample_var._rotation_absolute, _det_var._rotation_absolute);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    rot_mul(_det_var._rotation_absolute, tr1, _det_var._rotation_relative);
    _det_var._rotation_is_identity =  rot_test_identity(_det_var._rotation_relative);
    tc1 = coords_set(
      0, 0, 0);
    rot_transpose(_sample_var._rotation_absolute, tr1);
    tc2 = rot_apply(tr1, tc1);
    _det_var._position_absolute = coords_add(_sample_var._position_absolute, tc2);
    tc1 = coords_sub(_sample_var._position_absolute, _det_var._position_absolute);
    _det_var._position_relative = rot_apply(_det_var._rotation_absolute, tc1);
  } /* det=PSD_monitor_4PI() AT ROTATED */
  DEBUG_COMPONENT("det", _det_var._position_absolute, _det_var._rotation_absolute);
  instrument->_position_absolute[5] = _det_var._position_absolute;
  instrument->_position_relative[5] = _det_var._position_relative;
    _det_var._position_relative_is_zero =  coords_test_zero(_det_var._position_relative);
  instrument->counter_N[5]  = instrument->counter_P[5] = instrument->counter_P2[5] = 0;
  instrument->counter_AbsorbProp[5]= 0;
  #ifdef USE_NEXUS
  if(nxhandle) {
    if ((!mcdotrace) && mcformat && strcasestr(mcformat, "NeXus")) {
    MPI_MASTER(
        mccomp_placement_type_nexus(nxhandle,"0004_det", _det_var._position_absolute, _det_var._rotation_absolute, "PSD_monitor_4PI");
        mccomp_param_nexus(nxhandle,"0004_det", "nx", "90", "360","int");
        mccomp_param_nexus(nxhandle,"0004_det", "ny", "90", "180","int");
        mccomp_param_nexus(nxhandle,"0004_det", "filename", 0, "psd", "char*");
        mccomp_param_nexus(nxhandle,"0004_det", "nowritefile", "0", "0","int");
        mccomp_param_nexus(nxhandle,"0004_det", "radius", "1", "1","MCNUM");
        mccomp_param_nexus(nxhandle,"0004_det", "restore_neutron", "0", "0","int");
      );
    }
  } else {
    // fprintf(stderr,"NO NEXUS FILE");
  }
  #endif
  return(0);
} /* _det_setpos */

_class_Progress_bar *class_Progress_bar_init(_class_Progress_bar *_comp
) {
  #define profile (_comp->profile)
  #define percent (_comp->percent)
  #define flag_save (_comp->flag_save)
  #define minutes (_comp->minutes)
  #define IntermediateCnts (_comp->IntermediateCnts)
  #define StartTime (_comp->StartTime)
  #define EndTime (_comp->EndTime)
  #define CurrentTime (_comp->CurrentTime)
  #define infostring (_comp->infostring)
  SIG_MESSAGE("[_Origin_init] component Origin=Progress_bar() INITIALISE [Progress_bar:0]");

  IntermediateCnts = 0;
  StartTime = 0;
  EndTime = 0;
  CurrentTime = 0;

  fprintf (stdout, "[%s] Initialize\n", instrument_name);
  if (percent * mcget_ncount () / 100 < 1e5) {
    percent = 1e5 * 100.0 / mcget_ncount ();
  }
  #if defined(OPENACC) || defined(_OPENMP)
  time (&StartTime);
  #endif

  #ifdef USE_MPI
  sprintf (infostring, "(%i MPI processes) ", mpi_node_count);
  #else
  sprintf (infostring, "(single process) ");
  #endif
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_init */

_class_Source_simple *class_Source_simple_init(_class_Source_simple *_comp
) {
  #define radius (_comp->radius)
  #define yheight (_comp->yheight)
  #define xwidth (_comp->xwidth)
  #define dist (_comp->dist)
  #define focus_xw (_comp->focus_xw)
  #define focus_yh (_comp->focus_yh)
  #define E0 (_comp->E0)
  #define dE (_comp->dE)
  #define lambda0 (_comp->lambda0)
  #define dlambda (_comp->dlambda)
  #define flux (_comp->flux)
  #define gauss (_comp->gauss)
  #define target_index (_comp->target_index)
  #define pmul (_comp->pmul)
  #define srcArea (_comp->srcArea)
  #define square (_comp->square)
  #define tx (_comp->tx)
  #define ty (_comp->ty)
  #define tz (_comp->tz)
  SIG_MESSAGE("[_source_init] component source=Source_simple() INITIALISE [Source_simple:0]");

square = 0;
/* Determine source area */
if (radius && !yheight && !xwidth ) {
    square = 0;
    srcArea = PI*radius*radius;
  } else if(yheight && xwidth) {
    square = 1;
    srcArea = xwidth * yheight;
  }

  if (flux) {
    pmul=flux*1e4*srcArea/mcget_ncount();
    if (dlambda)
      pmul *= 2*dlambda;
    else if (dE)
      pmul *= 2*dE;
  } else {
    gauss = 0;
    pmul=1.0/(mcget_ncount()*4*PI);
  }

  if (target_index && !dist)
  {
    Coords ToTarget;
    ToTarget = coords_sub(POS_A_COMP_INDEX(INDEX_CURRENT_COMP+target_index),POS_A_CURRENT_COMP);
    ToTarget = rot_apply(ROT_A_CURRENT_COMP, ToTarget);
    coords_get(ToTarget, &tx, &ty, &tz);
    dist=sqrt(tx*tx+ty*ty+tz*tz);
  } else if (dist) {
    tx = 0;
    ty = 0;
    tz = dist;
  }

  if (srcArea <= 0) {
    printf("Source_simple: %s: Source area is <= 0 !\n ERROR - Exiting\n",
           NAME_CURRENT_COMP);
    exit(0);
  }
  if (dist <= 0 || focus_xw <= 0 || focus_yh <= 0) {
    printf("Source_simple: %s: Target area unmeaningful! (negative dist / focus_xw / focus_yh)\n ERROR - Exiting\n",
           NAME_CURRENT_COMP);
    exit(0);
  }

  if ((!lambda0 && !E0 && !dE && !dlambda)) {
    printf("Source_simple: %s: You must specify either a wavelength or energy range!\n ERROR - Exiting\n",
           NAME_CURRENT_COMP);
    exit(0);
  }
  if ((!lambda0 && !dlambda && (E0 <= 0 || dE < 0 || E0-dE <= 0))
    || (!E0 && !dE && (lambda0 <= 0 || dlambda < 0 || lambda0-dlambda <= 0))) {
    printf("Source_simple: %s: Unmeaningful definition of wavelength or energy range!\n ERROR - Exiting\n",
           NAME_CURRENT_COMP);
      exit(0);
  }
  #undef radius
  #undef yheight
  #undef xwidth
  #undef dist
  #undef focus_xw
  #undef focus_yh
  #undef E0
  #undef dE
  #undef lambda0
  #undef dlambda
  #undef flux
  #undef gauss
  #undef target_index
  #undef pmul
  #undef srcArea
  #undef square
  #undef tx
  #undef ty
  #undef tz
  return(_comp);
} /* class_Source_simple_init */

_class_Slit *class_Slit_init(_class_Slit *_comp
) {
  #define xmin (_comp->xmin)
  #define xmax (_comp->xmax)
  #define ymin (_comp->ymin)
  #define ymax (_comp->ymax)
  #define radius (_comp->radius)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define isradial (_comp->isradial)
  SIG_MESSAGE("[_slit_init] component slit=Slit() INITIALISE [Slit:0]");

  if (is_unset (radius)) {
    isradial = 0;
    if (all_set (3, xwidth, xmin, xmax)) {
      slit_error_if (xwidth != xmax - xmin, "specifying xwidth, xmin and xmax requires consistent parameters", NAME_CURRENT_COMP);
    } else {
      slit_error_if (is_unset (xwidth) && any_unset (2, xmin, xmax), "specify either xwidth or xmin & xmax", NAME_CURRENT_COMP);
    }
    if (all_set (3, yheight, ymin, ymax)) {
      slit_error_if (yheight != ymax - ymin, "specifying yheight, ymin and ymax requires consistent parameters", NAME_CURRENT_COMP);
    } else {
      slit_error_if (is_unset (yheight) && any_unset (2, ymin, ymax), "specify either yheight or ymin & ymax", NAME_CURRENT_COMP);
    }
    if (is_unset (xmin)) { // xmax also unset but xwidth *is* set
      xmax = xwidth / 2;
      xmin = -xmax;
    }
    if (is_unset (ymin)) { // ymax also unset but yheight *is* set
      ymax = yheight / 2;
      ymin = -ymax;
    }
    slit_warning_if (xmin == xmax || ymin == ymax, "Running with CLOSED rectangular slit - is this intentional?", NAME_CURRENT_COMP);
  } else {
    isradial = 1;
    slit_error_if (any_set (6, xwidth, xmin, xmax, yheight, ymin, ymax), "specify radius OR width and height parameters", NAME_CURRENT_COMP);
    slit_warning_if (radius == 0., "Running with CLOSED radial slit - is this intentional?", NAME_CURRENT_COMP);
  }
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef isradial
  return(_comp);
} /* class_Slit_init */

_class_Single_crystal *class_Single_crystal_init(_class_Single_crystal *_comp
) {
  #define reflections (_comp->reflections)
  #define geometry (_comp->geometry)
  #define mosaic_AB (_comp->mosaic_AB)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define zdepth (_comp->zdepth)
  #define radius (_comp->radius)
  #define delta_d_d (_comp->delta_d_d)
  #define mosaic (_comp->mosaic)
  #define mosaic_a (_comp->mosaic_a)
  #define mosaic_b (_comp->mosaic_b)
  #define mosaic_c (_comp->mosaic_c)
  #define recip_cell (_comp->recip_cell)
  #define barns (_comp->barns)
  #define ax (_comp->ax)
  #define ay (_comp->ay)
  #define az (_comp->az)
  #define bx (_comp->bx)
  #define by (_comp->by)
  #define bz (_comp->bz)
  #define cx (_comp->cx)
  #define cy (_comp->cy)
  #define cz (_comp->cz)
  #define p_transmit (_comp->p_transmit)
  #define sigma_abs (_comp->sigma_abs)
  #define sigma_inc (_comp->sigma_inc)
  #define aa (_comp->aa)
  #define bb (_comp->bb)
  #define cc (_comp->cc)
  #define order (_comp->order)
  #define extra_order (_comp->extra_order)
  #define RX (_comp->RX)
  #define RY (_comp->RY)
  #define powder (_comp->powder)
  #define PG (_comp->PG)
  #define deltak (_comp->deltak)
  #define hkl_info (_comp->hkl_info)
  #define offdata (_comp->offdata)
  #define hkl_list (_comp->hkl_list)
  #define tau_list (_comp->tau_list)
  SIG_MESSAGE("[_sample_init] component sample=Single_crystal() INITIALISE [Single_crystal:0]");


  double as, bs, cs;
  int i = 0;

  /* transfer input parameters */
  hkl_info.m_delta_d_d = delta_d_d;
  hkl_info.m_a = 0;
  hkl_info.m_b = 0;
  hkl_info.m_c = 0;
  hkl_info.m_aa = aa;
  hkl_info.m_bb = bb;
  hkl_info.m_cc = cc;
  hkl_info.m_ax = ax;
  hkl_info.m_ay = ay;
  hkl_info.m_az = az;
  hkl_info.m_bx = bx;
  hkl_info.m_by = by;
  hkl_info.m_bz = bz;
  hkl_info.m_cx = cx;
  hkl_info.m_cy = cy;
  hkl_info.m_cz = cz;
  hkl_info.sigma_a = sigma_abs;
  hkl_info.sigma_i = sigma_inc;
  hkl_info.recip = recip_cell;

  /* default format h,k,l,F,F2  */
  hkl_info.column_order[0] = 1;
  hkl_info.column_order[1] = 2;
  hkl_info.column_order[2] = 3;
  hkl_info.column_order[3] = 0;
  hkl_info.column_order[4] = 7;
  hkl_info.kix = hkl_info.kiy = hkl_info.kiz = 0;
  hkl_info.nb_reuses = hkl_info.nb_refl = hkl_info.nb_refl_count = 0;
  hkl_info.tau_count = 0;
  hkl_info.flag_barns = barns;

  /* ought to be cleaned up as mosaic_AB now is a proper vector/array and not a define */
  double* mosaic_ABin = mosaic_AB;
  /* Read in structure factors, and do some pre-calculations. */
  if (!read_hkl_data (reflections, &hkl_info, &hkl_list, mosaic, mosaic_a, mosaic_b, mosaic_c, mosaic_ABin)) {
    printf ("Single_crystal: %s: Error: Aborting.\n", NAME_CURRENT_COMP);
    exit (-1);
  }

  if (hkl_info.sigma_a < 0)
    hkl_info.sigma_a = 0;
  if (hkl_info.sigma_i < 0)
    hkl_info.sigma_i = 0;

  if (hkl_info.count) {
    MPI_MASTER (printf ("Single_crystal: %s: Read %d reflections from file '%s'\n", NAME_CURRENT_COMP, hkl_info.count, reflections););
  } else {
    MPI_MASTER (printf ("Single_crystal: %s: Using incoherent elastic scattering only sigma=%g.\n", NAME_CURRENT_COMP, hkl_info.sigma_i););
  }
  /*this should not be in hkl_info*/
  hkl_info.shape = -1; /* -1:no shape, 0:cyl, 1:box, 2:sphere, 3:any-shape  */
  if (geometry && strlen (geometry) && strcmp (geometry, "NULL") && strcmp (geometry, "0")) {
    #ifndef USE_OFF
    fprintf (stderr, "Error: You are attempting to use an OFF geometry without -DUSE_OFF. You will need to recompile with that define set!\n");
    exit (-1);
    #else
    if (off_init (geometry, xwidth, yheight, zdepth, 0, &offdata)) {
      hkl_info.shape = 3;
    }
    #endif
  } else if (xwidth && yheight && zdepth)
    hkl_info.shape = 1; /* box */
  else if (radius > 0 && yheight)
    hkl_info.shape = 0; /* cylinder */
  else if (radius > 0 && !yheight)
    hkl_info.shape = 2; /* sphere */

  if (hkl_info.shape < 0)
    exit (fprintf (stderr,
                   "Single_crystal: %s: sample has invalid dimensions.\n"
                   "ERROR           Please check parameter values (xwidth, yheight, zdepth, radius).\n",
                   NAME_CURRENT_COMP));

  MPI_MASTER (printf ("Single_crystal: %s: Vc=%g [Angs] sigma_abs=%g [barn] sigma_inc=%g [barn] reflections=%s\n", NAME_CURRENT_COMP, hkl_info.V0,
                      hkl_info.sigma_a, hkl_info.sigma_i, reflections&& strlen (reflections) ? reflections : "NULL"););
  if (powder && PG)
    exit (fprintf (stderr,
                   "Single_crystal: %s: powder and PG modes can not be used together!\n"
                   "ERROR           Please use EITHER powder or PG mode.\n",
                   NAME_CURRENT_COMP));

  if (powder && !(order == 1)) {
    fprintf (stderr,
             "Single_crystal: %s: powder mode means implicit choice of no multiple scattering!\n"
             "WARNING setting order=1\n",
             NAME_CURRENT_COMP);
    order = 1;
  }

  if (PG && !(order == 1)) {
    fprintf (stderr,
             "Single_crystal: %s: PG mode means implicit choice of no multiple scattering!\n"
             "WARNING setting order=1\n",
             NAME_CURRENT_COMP);
    order = 1;
  }

  if (order == 0 && extra_order) {
    fprintf (stderr, "Single_crystal: %s: extra_order used while order=0, then this option has no effect\n", NAME_CURRENT_COMP);
  }
  MPI_MASTER (printf ("Direct space lattice orientation:\n"); printf ("  a = [%g %g %g]\n", hkl_info.m_ax, hkl_info.m_ay, hkl_info.m_az);
              printf ("  b = [%g %g %g]\n", hkl_info.m_bx, hkl_info.m_by, hkl_info.m_bz);
              printf ("  c = [%g %g %g]\n", hkl_info.m_cx, hkl_info.m_cy, hkl_info.m_cz); printf ("Reciprocal space lattice orientation:\n");
              printf ("  a* = [%g %g %g]\n", hkl_info.asx, hkl_info.asy, hkl_info.asz); printf ("  b* = [%g %g %g]\n", hkl_info.bsx, hkl_info.bsy, hkl_info.bsz);
              printf ("  c* = [%g %g %g]\n", hkl_info.csx, hkl_info.csy, hkl_info.csz););
  #undef reflections
  #undef geometry
  #undef mosaic_AB
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef radius
  #undef delta_d_d
  #undef mosaic
  #undef mosaic_a
  #undef mosaic_b
  #undef mosaic_c
  #undef recip_cell
  #undef barns
  #undef ax
  #undef ay
  #undef az
  #undef bx
  #undef by
  #undef bz
  #undef cx
  #undef cy
  #undef cz
  #undef p_transmit
  #undef sigma_abs
  #undef sigma_inc
  #undef aa
  #undef bb
  #undef cc
  #undef order
  #undef extra_order
  #undef RX
  #undef RY
  #undef powder
  #undef PG
  #undef deltak
  #undef hkl_info
  #undef offdata
  #undef hkl_list
  #undef tau_list
  return(_comp);
} /* class_Single_crystal_init */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_init(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->nx)
  #define ny (_comp->ny)
  #define filename (_comp->filename)
  #define nowritefile (_comp->nowritefile)
  #define radius (_comp->radius)
  #define restore_neutron (_comp->restore_neutron)
  #define PSD_N (_comp->PSD_N)
  #define PSD_p (_comp->PSD_p)
  #define PSD_p2 (_comp->PSD_p2)
  SIG_MESSAGE("[_det_init] component det=PSD_monitor_4PI() INITIALISE [PSD_monitor_4PI:0]");

  PSD_N = create_darr2d (nx, ny);
  PSD_p = create_darr2d (nx, ny);
  PSD_p2 = create_darr2d (nx, ny);

  // Use instance name for monitor output if no input was given
  if (!strcmp (filename, "\0"))
    sprintf (filename, "%s", NAME_CURRENT_COMP);
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_init */



int init(void) { /* called by mccode_main for templateNMX:INITIALISE */
  DEBUG_INSTR();
  // Initialise rng
  srandom(_hash(mcseed-1));

  /* code_main/parseoptions/readparams sets instrument parameters value */
  stracpy(instrument->_name, "templateNMX", 256);
  _instrument_var._counter=0;

  _Origin_setpos(); /* type Progress_bar */
  _source_setpos(); /* type Source_simple */
  _slit_setpos(); /* type Slit */
  _sample_setpos(); /* type Single_crystal */
  _det_setpos(); /* type PSD_monitor_4PI */

  /* call iteratively all components INITIALISE */
  class_Progress_bar_init(&_Origin_var);

  class_Source_simple_init(&_source_var);

  class_Slit_init(&_slit_var);

  class_Single_crystal_init(&_sample_var);

  class_PSD_monitor_4PI_init(&_det_var);

  if (mcdotrace) display();
  DEBUG_INSTR_END();

  return(0);
} /* init */

/*******************************************************************************
* components TRACE
*******************************************************************************/

#define x (_particle->x)
#define y (_particle->y)
#define z (_particle->z)
#define vx (_particle->vx)
#define vy (_particle->vy)
#define vz (_particle->vz)
#define t (_particle->t)
#define sx (_particle->sx)
#define sy (_particle->sy)
#define sz (_particle->sz)
#define p (_particle->p)
#define mcgravitation (_particle->mcgravitation)
#define mcMagnet (_particle->mcMagnet)
#define allow_backprop (_particle->allow_backprop)
#define _mctmp_a (_particle->_mctmp_a)
#define _mctmp_b (_particle->_mctmp_b)
#define _mctmp_c (_particle->_mctmp_c)
/* if on GPU, globally nullify sprintf,fprintf,printfs   */
/* (Similar defines are available in each comp trace but */
/*  those are not enough to handle external libs etc. )  */
#if defined(OPENACC) || defined(_OPENMP)
#define fprintf(stderr,...) printf(__VA_ARGS__)
#define sprintf(string,...) printf(__VA_ARGS__)
#define exit(...) noprintf()
#define strcmp(a,b) str_comp(a,b)
#define strlen(a) str_len(a)
#endif
#define SCATTERED (_particle->_scattered)
#define RESTORE (_particle->_restore)
#define RESTORE_NEUTRON(_index, ...) _particle->_restore = _index;
#define ABSORB0 do { DEBUG_STATE(); DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; return; } while(0)
#define ABSORBED (_particle->_absorbed)
#define mcget_run_num() _particle->_uid
#define ABSORB ABSORB0
void class_Progress_bar_trace(_class_Progress_bar *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define profile (_comp->profile)
  #define percent (_comp->percent)
  #define flag_save (_comp->flag_save)
  #define minutes (_comp->minutes)
  #define IntermediateCnts (_comp->IntermediateCnts)
  #define StartTime (_comp->StartTime)
  #define EndTime (_comp->EndTime)
  #define CurrentTime (_comp->CurrentTime)
  #define infostring (_comp->infostring)
  SIG_MESSAGE("[_Origin_trace] component Origin=Progress_bar() TRACE [Progress_bar:0]");

  #if !defined(OPENACC) && !defined(_OPENMP)
  double ncount;
  ncount = mcget_run_num ();
  if (!StartTime) {
    time (&StartTime); /* compute starting time */
    IntermediateCnts = 1e3;
  }
  time_t NowTime;
  time (&NowTime);
  /* compute initial estimate of computation duration */
  if (!EndTime && ncount >= IntermediateCnts) {
    CurrentTime = NowTime;
    if (difftime (NowTime, StartTime) > 10 && ncount) { /* wait 10 sec before writing ETA */
      EndTime = StartTime + (time_t)(difftime (NowTime, StartTime) * (double)mcget_ncount () / ncount);
      IntermediateCnts = 0;
      MPI_MASTER (fprintf (stdout, "\nTrace ETA "); fprintf (stdout, "%s", infostring);
                  if (difftime (EndTime, StartTime) < 60.0) fprintf (stdout, "%g [s] ", difftime (EndTime, StartTime));
                  else if (difftime (EndTime, StartTime) > 3600.0) fprintf (stdout, "%g [h] ", difftime (EndTime, StartTime) / 3600.0);
                  else fprintf (stdout, "%g [min] ", difftime (EndTime, StartTime) / 60.0); fprintf (stdout, "\n"););
    } else
      IntermediateCnts += 1e3;
    fflush (stdout);
  }

  /* display percentage when percent or minutes have reached step */
  if (EndTime && mcget_ncount () && ((minutes && difftime (NowTime, CurrentTime) > minutes * 60) || (percent && !minutes && ncount >= IntermediateCnts))) {
    MPI_MASTER (fprintf (stdout, "%llu %%\n", (unsigned long long)(ncount * 100.0 / mcget_ncount ())); fflush (stdout););
    CurrentTime = NowTime;

    IntermediateCnts = ncount + percent * mcget_ncount () / 100;
    /* check that next intermediate ncount check is a multiple of the desired percentage */
    IntermediateCnts = floor (IntermediateCnts * 100 / percent / mcget_ncount ()) * percent * mcget_ncount () / 100;
    /* raise flag to indicate that we did something */
    SCATTER;
    if (flag_save)
      save (NULL);
  }
  #endif
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return;
} /* class_Progress_bar_trace */

void class_Source_simple_trace(_class_Source_simple *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define radius (_comp->radius)
  #define yheight (_comp->yheight)
  #define xwidth (_comp->xwidth)
  #define dist (_comp->dist)
  #define focus_xw (_comp->focus_xw)
  #define focus_yh (_comp->focus_yh)
  #define E0 (_comp->E0)
  #define dE (_comp->dE)
  #define lambda0 (_comp->lambda0)
  #define dlambda (_comp->dlambda)
  #define flux (_comp->flux)
  #define gauss (_comp->gauss)
  #define target_index (_comp->target_index)
  #define pmul (_comp->pmul)
  #define srcArea (_comp->srcArea)
  #define square (_comp->square)
  #define tx (_comp->tx)
  #define ty (_comp->ty)
  #define tz (_comp->tz)
  SIG_MESSAGE("[_source_trace] component source=Source_simple() TRACE [Source_simple:0]");

 double chi,E,lambda,v,r, xf, yf, rf, dx, dy, pdir;

 t=0;
 z=0;

 if (square == 1) {
   x = xwidth * (rand01() - 0.5);
   y = yheight * (rand01() - 0.5);
 } else {
   chi=2*PI*rand01();                          /* Choose point on source */
   r=sqrt(rand01())*radius;                    /* with uniform distribution. */
   x=r*cos(chi);
   y=r*sin(chi);
 }
 randvec_target_rect_real(&xf, &yf, &rf, &pdir,
			  tx, ty, tz, focus_xw, focus_yh, ROT_A_CURRENT_COMP, x, y, z, 2);

 dx = xf-x;
 dy = yf-y;
 rf = sqrt(dx*dx+dy*dy+rf*rf);

 p = pdir*pmul;

 if(lambda0==0) {
   if (!gauss) {
     E=E0+dE*randpm1();              /*  Choose from uniform distribution */
   } else {
     E=E0+randnorm()*dE;
   }
   v=sqrt(E)*SE2V;
 } else {
   if (!gauss) {
     lambda=lambda0+dlambda*randpm1();
   } else {
     lambda=lambda0+randnorm()*dlambda;
   }
   v = K2V*(2*PI/lambda);
 }

 vz=v*dist/rf;
 vy=v*dy/rf;
 vx=v*dx/rf;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef radius
  #undef yheight
  #undef xwidth
  #undef dist
  #undef focus_xw
  #undef focus_yh
  #undef E0
  #undef dE
  #undef lambda0
  #undef dlambda
  #undef flux
  #undef gauss
  #undef target_index
  #undef pmul
  #undef srcArea
  #undef square
  #undef tx
  #undef ty
  #undef tz
  return;
} /* class_Source_simple_trace */

void class_Slit_trace(_class_Slit *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define xmin (_comp->xmin)
  #define xmax (_comp->xmax)
  #define ymin (_comp->ymin)
  #define ymax (_comp->ymax)
  #define radius (_comp->radius)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define isradial (_comp->isradial)
  SIG_MESSAGE("[_slit_trace] component slit=Slit() TRACE [Slit:0]");

  PROP_Z0;
  if (!isradial ? (x < xmin || x > xmax || y < ymin || y > ymax) : (x * x + y * y > radius * radius))
    ABSORB;
  else
    SCATTER;
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef isradial
  return;
} /* class_Slit_trace */

void class_Single_crystal_trace(_class_Single_crystal *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define reflections (_comp->reflections)
  #define geometry (_comp->geometry)
  #define mosaic_AB (_comp->mosaic_AB)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define zdepth (_comp->zdepth)
  #define radius (_comp->radius)
  #define delta_d_d (_comp->delta_d_d)
  #define mosaic (_comp->mosaic)
  #define mosaic_a (_comp->mosaic_a)
  #define mosaic_b (_comp->mosaic_b)
  #define mosaic_c (_comp->mosaic_c)
  #define recip_cell (_comp->recip_cell)
  #define barns (_comp->barns)
  #define ax (_comp->ax)
  #define ay (_comp->ay)
  #define az (_comp->az)
  #define bx (_comp->bx)
  #define by (_comp->by)
  #define bz (_comp->bz)
  #define cx (_comp->cx)
  #define cy (_comp->cy)
  #define cz (_comp->cz)
  #define p_transmit (_comp->p_transmit)
  #define sigma_abs (_comp->sigma_abs)
  #define sigma_inc (_comp->sigma_inc)
  #define aa (_comp->aa)
  #define bb (_comp->bb)
  #define cc (_comp->cc)
  #define order (_comp->order)
  #define extra_order (_comp->extra_order)
  #define RX (_comp->RX)
  #define RY (_comp->RY)
  #define powder (_comp->powder)
  #define PG (_comp->PG)
  #define deltak (_comp->deltak)
  #define hkl_info (_comp->hkl_info)
  #define offdata (_comp->offdata)
  #define hkl_list (_comp->hkl_list)
  #define tau_list (_comp->tau_list)
  SIG_MESSAGE("[_sample_trace] component sample=Single_crystal() TRACE [Single_crystal:0]");

  double t1, t2 = 0;  /* Entry and exit times in sample */
  struct hkl_data* L; /* Structure factor list */
  int i;              /* Index into structure factor list */
                      #if !defined(OPENACC) && !defined(_OPENMP)
  struct tau_data* T; /* List of reflections close to Ewald sphere */
                      #else
  struct tau_data T[MCSX_REFL_SLIST_SIZE];
  #endif
  int tau_count;              /* Number of reflections close to Ewald sphere*/
  int j;                      /* Index into reflection list */
  int event_counter;          /* scattering event counter */
  double kix, kiy, kiz, ki;   /* Initial wave vector [1/AA] */
  double kfx, kfy, kfz;       /* Final wave vector */
  double v;                   /* Neutron velocity */
  double rho_x, rho_y, rho_z; /* the vector ki - tau */
  double rho;
  double diff;                      /* Deviation from Bragg condition */
  double ox, oy, oz;                /* Origin of Ewald sphere tangent plane */
  double b1x, b1y, b1z;             /* First vector spanning tangent plane */
  double b2x, b2y, b2z;             /* Second vector spanning tangent plane */
  double n11, n12, n22;             /* 2D Gauss description matrix N */
  double det_N;                     /* Determinant of N */
  double inv_n11, inv_n12, inv_n22; /* Inverse of N */
  double l11, l12, l22;             /* Cholesky decomposition L of 1/2*inv(N) */
  double det_L;                     /* Determinant of L */
  double Bt_D_O_x, Bt_D_O_y;        /* Temporaries */
  double y0x, y0y;                  /* Center of 2D Gauss in plane coordinates */
  double alpha;                     /* Offset of 2D Gauss center from 3D center */
  double V0;                        /* Volume of unit cell */
  double l_full;                    /* Neutron path length for transmission */
  double l;                         /* Path length to scattering event */
  double abs_xsect, abs_xlen;       /* Absorption cross section and length */
  double inc_xsect, inc_xlen;       /* Incoherent scattering cross section and length */
  double coh_xlen;                  /* Coherent cross section and length */
  double tot_xsect, tot_xlen;       /* Total cross section and length */
  double z1, z2, y1, y2;            /* Temporaries to choose kf from 2D Gauss */
  double adjust, sum;               /* Temporaries */

  double p_trans;               /* Transmission probability */
  double mc_trans, mc_interact; /* Transmission, interaction MC choices */
  int intersect = 0;
  double theta, phi; /* rotation angles for curved lattice option */

  double curv_xangle;
  double curv_yangle;

  double _vx;
  double _vy;
  double _vz;

  char type; /* type of last event: t=transmit,c=coherent or i=incoherent */
  int itype; /* type of last event: t=1,c=2 or i=3 */

  #if defined(OPENACC) || defined(_OPENMP)
  #ifdef USE_OFF
  off_struct thread_offdata = offdata;
  #endif
  #else
  #define thread_offdata offdata
  #endif

  /* Intersection neutron trajectory / sample (sample surface) */
  if (hkl_info.shape == 0)
    intersect = cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius, yheight);
  else if (hkl_info.shape == 1)
    intersect = box_intersect (&t1, &t2, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
  else if (hkl_info.shape == 2)
    intersect = sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius);
  #ifdef USE_OFF
  else if (hkl_info.shape == 3)
    intersect = off_intersect (&t1, &t2, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
  #endif
  if (t2 < 0)
    intersect = 0; /* we passed sample volume already */

  if (intersect) { /* Neutron intersects crystal */
    if (t1 > 0)
      PROP_DT (t1); /* Move to crystal surface if not inside */
    v = sqrt (vx * vx + vy * vy + vz * vz);
    ki = V2K * v;
    event_counter = 0;
    abs_xsect = hkl_info.sigma_a * 2200 / v;
    inc_xsect = hkl_info.sigma_i;
    V0 = hkl_info.V0;
    abs_xlen = abs_xsect / V0;
    inc_xlen = inc_xsect / V0;

    /* Scalar cross sections for inc/abs are given in barns, so we need a scaling factor of 100
       to get scattering lengths in m, since V0 is assumed to be in AA*/
    abs_xlen *= 100;
    inc_xlen *= 100;

    L = hkl_list;

    type = '\0';
    itype = 0;

    #if !defined(OPENACC) && !defined(_OPENMP)
    T = tau_list;
    hkl_info.type = type;
    #endif
    do { /* Loop over multiple scattering events */
      /* Angles for powder randomization */
      double Alpha, Beta, Gamma;
      double lab_vx, lab_vy, lab_vz;

      lab_vx = vx;
      lab_vy = vy;
      lab_vz = vz;

      if (hkl_info.shape == 0)
        intersect = cylinder_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius, yheight);
      else if (hkl_info.shape == 1)
        intersect = box_intersect (&t1, &t2, x, y, z, vx, vy, vz, xwidth, yheight, zdepth);
      else if (hkl_info.shape == 2)
        intersect = sphere_intersect (&t1, &t2, x, y, z, vx, vy, vz, radius);
      #ifdef USE_OFF
      else if (hkl_info.shape == 3)
        intersect = off_intersect (&t1, &t2, NULL, NULL, x, y, z, vx, vy, vz, 0, 0, 0, thread_offdata);
      #endif
      if (!intersect || t2 * v < -1e-9 || t1 * v > 1e-9) {
        /* neutron is leaving the sample */
        if (hkl_info.flag_warning < 10)
          #if !defined(OPENACC) && !defined(_OPENMP)
          fprintf (stderr,
                   "Single_crystal: %s: Warning: neutron has unexpectedly left the crystal!\n"
                   "                t1=%g t2=%g x=%g y=%g z=%g vx=%g vy=%g vz=%g\n",
                   NAME_CURRENT_COMP, t1, t2, x, y, z, vx, vy, vz);
        hkl_info.flag_warning++;
        #endif
        break;
      }

      l_full = t2 * v;

      if ((order && !(extra_order) && event_counter >= order) || (order && extra_order && event_counter >= order + extra_order)) {
        // Exit due to truncated order, weight with relevant cross-sections to distance l_full
        p *= exp (-abs_xlen * l_full);
        intersect = 0;
        break;
      }

      /* (1). Compute incoming wave vector ki */
      if (powder) { /* orientation of crystallite is random */
        Alpha = randpm1 () * PI * powder;
        Beta = randpm1 () * PI / 2;
        Gamma = randpm1 () * PI;
        randrotate (&vx, &vy, &vz, Alpha, Beta, Gamma);
      }
      if (PG) { /* orientation of crystallite is random along <c> axis */
        Alpha = randpm1 () * PI * PG;
        PGrotate (&vx, &vy, &vz, Alpha, hkl_info.csx, hkl_info.csy, hkl_info.csz);
      }

      /* ------------------------------------------------------------------------- */
      /* lattice curvature option: rotate neutron velocity */
      /* WARNING: cannot be used together with the PG c-rotation! */
      curv_xangle = 0;
      curv_yangle = 0;

      _vx = vx;
      _vy = vy;
      _vz = vz;

      if (RY) { /* rotate v around x axis based on y pos, for vertical focus */
        curv_yangle = atan2 (y, RY);
        vec_rotate_2d (&vy, &vz, curv_yangle);
        vec_rotate_2d (&sy, &sz, curv_yangle);

        /*changing y,z actually curves the crystal, not only the planes*/
        /*comment out if only curvature of the lattice planes is needed*/
        vec_rotate_2d (&y, &z, curv_yangle);
      }
      if (RX) { /* rotate v around y axis based on x pos, for horizontal focus */
        curv_xangle = atan2 (x, RX);
        vec_rotate_2d (&vx, &vz, curv_xangle);
        vec_rotate_2d (&sx, &sz, curv_xangle);

        /*changing x,z actually curves the crystal, not only the planes*/
        /*comment out if only curvature of the lattice planes is needed*/
        vec_rotate_2d (&x, &z, curv_xangle);
      }

      kix = V2K * vx;
      kiy = V2K * vy;
      kiz = V2K * vz;
      vx = _vx;
      vy = _vy;
      vz = _vz;
      /* ------------------------------------------------------------------------- */

      /* (2). Intersection of Ewald sphere with reciprocal lattice points */

      double coh_xsect = 0, coh_refl = 0;

      // Condition to skip calculation of coherent cross section when, needed for extra_order feature
      if (order == 0 || extra_order == 0 || event_counter < order) {
        #if !defined(OPENACC) && !defined(_OPENMP)
        /* in case we use 'SPLIT' then consecutive neutrons can be identical when entering here
           and we may skip the hkl_search call. One tau_list is reserved for data for the initial
               ray results so that it potentially can be reused later. */
        T = tau_list;
        if (order == 1 && fabs (kix - hkl_info.kix) < deltak && fabs (kiy - hkl_info.kiy) < deltak && fabs (kiz - hkl_info.kiz) < deltak) {
          hkl_info.nb_reuses++;

          /* Restore in case of matching event (e.g. SPLIT) */
          coh_refl = hkl_info.coh_refl;
          coh_xsect = hkl_info.coh_xsect;
          tau_count = hkl_info.tau_count;
        } else {
          #endif
          /* Max possible tau for this ki with 5*sigma delta-d/d cutoff. */
          double tau_max = 2 * ki / (1 - 5 * hkl_info.m_delta_d_d);

          /* call hkl_search */
          #ifdef USE_OPENCL
          if (oclContext_SX.Kernel != NULL) { // the Kernel could be initialised
            tau_count = hkl_search_opencl (L, T, hkl_info.count, hkl_info.V0, kix, kiy, kiz, tau_max, &coh_refl, &coh_xsect, oclContext_SX, d_L, d_T, d_tau_count,
                                           d_coh_refl, d_coh_xsect);
            if (tau_count != 0)
              MPI_MASTER (printf ("\nGPU tau_count:%i\n", tau_count););
          } else
            #endif

            tau_count = hkl_search (L, T, hkl_info.count, hkl_info.V0, kix, kiy, kiz, tau_max, &coh_refl, &coh_xsect);

          /* store ki so that we can check for further SPLIT iterations */
          #if !defined(OPENACC) && !defined(_OPENMP)
          if (tau_count > hkl_info.max_tau_count) {
            hkl_info.max_tau_count = tau_count;
          }
          if (event_counter == 0) { /* only for incoming neutron */
            hkl_info.kix = kix;
            hkl_info.kiy = kiy;
            hkl_info.kiz = kiz;

            /* Store for potential re-use (e.g. SPLIT) */
            hkl_info.coh_refl = coh_refl;
            hkl_info.coh_xsect = coh_xsect;
            hkl_info.tau_count = tau_count;
            hkl_info.nb_refl += tau_count;
            hkl_info.nb_refl_count++;
          }
        }
        #endif
      } else {
        // When extra_order used, disable coherent scattering after order reached, but continue
        // Set coherent cross section to zero to ignore coherent part
        coh_refl = 0;
        coh_xsect = 0;
        tau_count = 0;
      }

      /* (3). Probabilities of the different possible interactions. */
      /* Cross-sections are in barns = 10**-28 m**2, and unit cell volumes are
         in AA**3 = 10**-30 m**2. Hence a factor of 100 is used to convert
         scattering lengths to m**-1 */
      coh_xlen = coh_xsect / V0;
      if (hkl_info.flag_barns) {
        coh_xlen *= 100;
      } /* else assume fm^2 */
      tot_xlen = abs_xlen + inc_xlen + coh_xlen;

      if (tot_xlen <= 0) {
        ABSORB; // Should we really absorb here? If "nothing" can happen we perhaps ought to "pass" instead?
      }

      /* (5). Transmission */
      p_trans = exp (-tot_xlen * l_full);
      if (!event_counter && p_transmit >= 0 && p_transmit <= 1) {
        mc_trans = p_transmit; /* first event */
      } else {
        mc_trans = p_trans;
      }
      mc_interact = 1 - mc_trans;
      if (mc_trans > 0 && (mc_trans >= 1 || rand01 () < mc_trans)) /* Transmit */
      {
        p *= p_trans / mc_trans;
        intersect = 0;
        if (powder) { /* orientation of crystallite is longer random */
          randderotate (&vx, &vy, &vz, Alpha, Beta, Gamma);
        }
        if (PG) { /* orientation of crystallite is longer random */
          PGderotate (&vx, &vy, &vz, Alpha, hkl_info.csx, hkl_info.csy, hkl_info.csz);
        }

        type = 't';
        if (!itype)
          itype = 1;
        #if !defined(OPENACC) && !defined(_OPENMP)
        hkl_info.type = type;
        #endif

        break;
        /* This break means that we are leaving the while-loop, exiting the
           crystal by "tunneling". */
      }

      /* Scattering "proper", i.e. coh or incoh */
      if (mc_interact <= 0) /* Protect against rounding errors */
      {
        intersect = 0;
        if (powder) { /* orientation of crystallite is no longer random */
          randderotate (&vx, &vy, &vz, Alpha, Beta, Gamma);
        }
        if (PG) { /* orientation of crystallite is no longer random, rotation around <c> */
          PGderotate (&vx, &vy, &vz, Alpha, hkl_info.csx, hkl_info.csy, hkl_info.csz);
        }
        break;
      }

      /* First-pass considerations: */
      if (!event_counter)
        p *= fabs (1 - p_trans) / mc_interact;
      /* Select a point at which to scatter the neutron, taking
         secondary extinction into account. */
      /* dP(l) = exp(-tot_xlen*l)dl
         P(l<l_0) = [-1/tot_xlen*exp(-tot_xlen*l)]_0^l_0
                  = (1 - exp(-tot_xlen*l0))/tot_xlen
         l = -log(1 - tot_xlen*rand0max(P(l<l_full)))/tot_xlen
       */
      if (tot_xlen * l_full < 1e-6)
        /* For very weak scattering, use simple uniform sampling of scattering
           point to avoid rounding errors. */
        l = rand0max (l_full);
      else
        l = -log (1 - rand0max ((1 - exp (-tot_xlen * l_full)))) / tot_xlen;

      /* Propagate to scattering point in lab space */
      vx = lab_vx;
      vy = lab_vy;
      vz = lab_vz;

      PROP_DT (l / v);
      event_counter++;

      if (PG || powder) {
        /* In case of PG or powder return to crystalite frame after propagation */
        vx = _vx;
        vy = _vy;
        vz = _vz;
      }

      /* (4). Account for the probability of sigma_abs */
      p *= (coh_xlen + inc_xlen) / tot_xlen;
      /* Choose between coherent and incoherent scattering */
      if (coh_xlen == 0 || rand0max (coh_xlen + inc_xlen) <= inc_xlen) {
        /* (6). Incoherent scattering */
        randvec_target_circle (&kix, &kiy, &kiz, NULL, vx, vy, vz, 0);
        vx = kix; /* ki vector is used as tmp var with norm v */
        vy = kiy;
        vz = kiz; /* Go for next scattering event */

        type = 'i';
        if (!itype)
          itype = 2;
        #if !defined(OPENACC) && !defined(_OPENMP)
        hkl_info.type = type;
        #endif
      } else {
        /* 7. Coherent scattering. Select reciprocal lattice point. */
        if (coh_refl <= 0) {
          ABSORB;
        }
        sum = 0;
        j = hkl_select (T, tau_count, coh_refl, &sum, _particle);
        if (j >= tau_count) {
          #if !defined(OPENACC) && !defined(_OPENMP)
          if (hkl_info.flag_warning < 10)
            fprintf (stderr,
                     "Single_crystal: Error: Illegal tau search "
                     "(sum=%g, j=%i, tau_count=%i).\n",
                     sum, j, tau_count);
          hkl_info.flag_warning++;
          #endif
          j = tau_count - 1;
        }
        i = T[j].index;
        /* (8). Pick scattered wavevector kf from 2D Gauss distribution. */
        z1 = randnorm ();
        z2 = randnorm ();
        y1 = T[j].l11 * z1 + T[j].y0x;
        y2 = T[j].l12 * z1 + T[j].l22 * z2 + T[j].y0y;
        kfx = T[j].rho_x + T[j].ox + T[j].b1x * y1 + T[j].b2x * y2;
        kfy = T[j].rho_y + T[j].oy + T[j].b1y * y1 + T[j].b2y * y2;
        kfz = T[j].rho_z + T[j].oz + T[j].b1z * y1 + T[j].b2z * y2;

        /* Normalize kf to length of ki, to account for planer
          approximation of the Ewald sphere. */
        adjust = ki / sqrt (kfx * kfx + kfy * kfy + kfz * kfz);
        kfx *= adjust;
        kfy *= adjust;
        kfz *= adjust;
        /* Adjust neutron weight (see manual for explanation). */
        double pmul = T[j].xsect * coh_refl / (coh_xsect * T[j].refl);
        if (!isnan (pmul))
          p *= pmul;
        vx = K2V * (L[i].u1x * kfx + L[i].u2x * kfy + L[i].u3x * kfz);
        vy = K2V * (L[i].u1y * kfx + L[i].u2y * kfy + L[i].u3y * kfz);
        vz = K2V * (L[i].u1z * kfx + L[i].u2z * kfy + L[i].u3z * kfz);

        type = 'c';
        if (!itype)
          itype = 3;
        #if !defined(OPENACC) && !defined(_OPENMP)
        hkl_info.type = type;
        hkl_info.h = L[i].h;
        hkl_info.k = L[i].k;
        hkl_info.l = L[i].l;
        #endif
      }
      /* ------------------------------------------------------------------------- */
      /* lattice curvature option: rotate back neutron velocity */
      if (RX) {
        vec_rotate_2d (&vx, &vz, -curv_xangle);
        vec_rotate_2d (&sx, &sz, -curv_xangle);

        /*changing x,z actually curves the crystal, not only the planes*/
        /*comment out if only curvature of the lattice planes is needed*/
        vec_rotate_2d (&x, &z, -curv_xangle);
      }
      if (RY) {
        vec_rotate_2d (&vy, &vz, -curv_yangle);
        vec_rotate_2d (&sy, &sz, -curv_yangle);

        /*changing y,z actually curves the crystal, not only the planes*/
        /*comment out if only curvature of the lattice planes is needed*/
        vec_rotate_2d (&y, &z, -curv_yangle);
      }
      /* ------------------------------------------------------------------------- */
      SCATTER;
      if (powder) { /* orientation of crystallite is no longer random */
        randderotate (&vx, &vy, &vz, Alpha, Beta, Gamma);
      }
      if (PG) { /* orientation of crystallite is longer random */
        PGderotate (&vx, &vy, &vz, Alpha, hkl_info.csx, hkl_info.csy, hkl_info.csz);
      }
      /* Repeat loop for next scattering event. */
    } while (intersect); /* end do (intersect) (multiple scattering loop) */
  } /* if intersect */
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif

if (_comp->_index == 4) { // EXTEND 'sample'
  if (!SCATTERED) ABSORB; /* perfect beam stop */
}

  #undef reflections
  #undef geometry
  #undef mosaic_AB
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef radius
  #undef delta_d_d
  #undef mosaic
  #undef mosaic_a
  #undef mosaic_b
  #undef mosaic_c
  #undef recip_cell
  #undef barns
  #undef ax
  #undef ay
  #undef az
  #undef bx
  #undef by
  #undef bz
  #undef cx
  #undef cy
  #undef cz
  #undef p_transmit
  #undef sigma_abs
  #undef sigma_inc
  #undef aa
  #undef bb
  #undef cc
  #undef order
  #undef extra_order
  #undef RX
  #undef RY
  #undef powder
  #undef PG
  #undef deltak
  #undef hkl_info
  #undef offdata
  #undef hkl_list
  #undef tau_list
  return;
} /* class_Single_crystal_trace */

void class_PSD_monitor_4PI_trace(_class_PSD_monitor_4PI *_comp
  , _class_particle *_particle) {
  ABSORBED=SCATTERED=RESTORE=0;
  #define nx (_comp->nx)
  #define ny (_comp->ny)
  #define filename (_comp->filename)
  #define nowritefile (_comp->nowritefile)
  #define radius (_comp->radius)
  #define restore_neutron (_comp->restore_neutron)
  #define PSD_N (_comp->PSD_N)
  #define PSD_p (_comp->PSD_p)
  #define PSD_p2 (_comp->PSD_p2)
  SIG_MESSAGE("[_det_trace] component det=PSD_monitor_4PI() TRACE [PSD_monitor_4PI:0]");

  double t0, t1, phi, theta;
  int i, j;

  if (sphere_intersect (&t0, &t1, x, y, z, vx, vy, vz, radius) && t1 > 0) {
    if (t0 < 0)
      t0 = t1;
    /* t0 is now time of intersection with the sphere. */
    mcPROP_DT (t0);
    phi = atan2 (x, z);
    i = floor (nx * (phi / (2 * PI) + 0.5));
    if (i >= nx)
      i = nx - 1; /* Special case for phi = PI. */
    else if (i < 0)
      i = 0;
    theta = asin (y / radius);
    j = floor (ny * (theta + PI / 2) / PI + 0.5);
    if (j >= ny)
      j = ny - 1; /* Special case for y = radius. */
    else if (j < 0)
      j = 0;

    double p2 = p * p;
    #pragma omp atomic update
    PSD_N[i][j] = PSD_N[i][j] + 1;

    #pragma omp atomic update
    PSD_p[i][j] = PSD_p[i][j] + p;

    #pragma omp atomic update
    PSD_p2[i][j] = PSD_p2[i][j] + p2;

    SCATTER;
  }
  if (restore_neutron) {
    RESTORE_NEUTRON (INDEX_CURRENT_COMP, x, y, z, vx, vy, vz, t, sx, sy, sz, p);
  }
#ifndef NOABSORB_INF_NAN
  /* Check for nan or inf particle parms */ 
  if(isnan(p + t + vx + vy + vz + x + y + z)) ABSORB;
  if(isinf(fabs(p) + fabs(t) + fabs(vx) + fabs(vy) + fabs(vz) + fabs(x) + fabs(y) + fabs(z))) ABSORB;
#else
  if(isnan(p)  ||  isinf(p)) printf("NAN or INF found in p,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(t)  ||  isinf(t)) printf("NAN or INF found in t,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vx) || isinf(vx)) printf("NAN or INF found in vx, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vy) || isinf(vy)) printf("NAN or INF found in vy, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(vz) || isinf(vz)) printf("NAN or INF found in vz, %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(x)  ||  isinf(x)) printf("NAN or INF found in x,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(y)  ||  isinf(y)) printf("NAN or INF found in y,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
  if(isnan(z)  ||  isinf(z)) printf("NAN or INF found in z,  %s (particle %lld)\n",_comp->_name,_particle->_uid);
#endif
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return;
} /* class_PSD_monitor_4PI_trace */

/* *****************************************************************************
* instrument 'templateNMX' TRACE
***************************************************************************** */

#ifndef FUNNEL
int raytrace(_class_particle* _particle) { /* single event propagation, called by mccode_main for templateNMX:TRACE */

  /* init variables and counters for TRACE */
  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++;} while(0)
  #define ABSORB ABSORB0
  DEBUG_ENTER();
  DEBUG_STATE();
  _particle->flag_nocoordschange=0; /* Init */
  _class_particle _particle_save=*_particle;
  /* the main iteration loop for one incoming event */
  while (!ABSORBED) { /* iterate event until absorbed */
    /* send particle event to component instance, one after the other */
    /* begin component Origin=Progress_bar() [1] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_Origin_var._rotation_is_identity) {
        if(!_Origin_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _Origin_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_Origin_var._position_relative, _Origin_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 1) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_Origin_var._name);
      DEBUG_STATE();
      class_Progress_bar_trace(&_Origin_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component Origin [1] */
    /* begin component source=Source_simple() [2] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_source_var._rotation_is_identity) {
        if(!_source_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _source_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_source_var._position_relative, _source_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 2) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_source_var._name);
      DEBUG_STATE();
      class_Source_simple_trace(&_source_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component source [2] */
    /* begin component slit=Slit() [3] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_slit_var._rotation_is_identity) {
        if(!_slit_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _slit_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_slit_var._position_relative, _slit_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 3) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_slit_var._name);
      DEBUG_STATE();
      class_Slit_trace(&_slit_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component slit [3] */
#ifndef NOSPLIT
    /* start SPLIT at sample */
    if (!ABSORBED) {
    _class_particle Split_sample_particle=*_particle;
    int Split_sample_counter;
    int SplitS_sample = _instrument_var.REPS;
    #pragma omp target teams num_teams(64) thread_limit(16) loop
    for (Split_sample_counter = 0; Split_sample_counter< SplitS_sample; Split_sample_counter++) {
      randstate_t randbackup = *_particle->randstate;
      *_particle=Split_sample_particle;
      *_particle->randstate = randbackup;
      p /= SplitS_sample > 0 ? SplitS_sample : 1;
#endif
    /* begin component sample=Single_crystal() [4] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_sample_var._rotation_is_identity) {
        if(!_sample_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _sample_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_sample_var._position_relative, _sample_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 4) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_sample_var._name);
      DEBUG_STATE();
      class_Single_crystal_trace(&_sample_var, _particle); /* contains EXTEND code */
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component sample [4] */
    /* begin component det=PSD_monitor_4PI() [5] */
    if (!_particle->flag_nocoordschange) { // flag activated by JUMP to pass coords change
      if (_det_var._rotation_is_identity) {
        if(!_det_var._position_relative_is_zero) {
          coords_get(coords_add(coords_set(x,y,z), _det_var._position_relative),&x, &y, &z);
        }
      } else {
          mccoordschange(_det_var._position_relative, _det_var._rotation_relative, _particle);
      }
    }
    if (!ABSORBED && _particle->_index == 5) {
      _particle->flag_nocoordschange=0; /* Reset if we came here from a JUMP */
      _particle_save = *_particle;
      DEBUG_COMP(_det_var._name);
      DEBUG_STATE();
      class_PSD_monitor_4PI_trace(&_det_var, _particle);
      if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
      _particle->_index++;
      if (!ABSORBED) { DEBUG_STATE(); }
    } /* end component det [5] */
#ifndef NOSPLIT
    } /* end SPLIT at sample */
    } /* if (!ABSORBED) relating to SPLIT at sample */
#endif
    if (_particle->_index > 5)
      ABSORBED++; /* absorbed when passed all components */
  } /* while !ABSORBED */

  DEBUG_LEAVE()
  particle_restore(_particle, &_particle_save);
  DEBUG_STATE()

  return(_particle->_index);
} /* raytrace */

/* loop to generate events and call raytrace() propagate them */
void raytrace_all(unsigned long long ncount, unsigned long seed) {

  // if on GPU and mcdotrace just exit
  #if defined(OPENACC) || defined(_OPENMP)
  if (!mcdotrace) {
  #endif

  /* CPU-loop */
  unsigned long long loops;
  loops = ceil((double)ncount/gpu_innerloop);
  /* if on GPU, printf has been globally nullified, re-enable here */
  #if defined(OPENACC) || defined(_OPENMP)
  #undef strlen
  #undef strcmp
  #undef exit
  #undef printf
  #undef sprintf
  #undef fprintf
  #endif

  #if defined(OPENACC) || defined(_OPENMP)
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around GPU kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
    #endif
    loops=1;
    gpu_innerloop = ncount;
    #if defined(OPENACC) || defined(_OPENMP)
  }
    #endif

  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    #if defined(OPENACC) || defined(_OPENMP)
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);
    #endif

#pragma omp target data map(tofrom: _Origin_var)
#pragma omp target data map(tofrom: _source_var)
#pragma omp target data map(tofrom: _slit_var)
#pragma omp target data map(tofrom: _sample_var)
#pragma omp target data map(tofrom: _det_var)
#pragma omp target data map(to:_instrument_var)
  {
    #pragma omp target teams num_teams(64) thread_limit(16) loop
    for (unsigned long pidx=0 ; pidx < gpu_innerloop ; pidx++) {
      _class_particle particleN = mcgenstate(); // initial particle
      _class_particle* _particle = &particleN;
      particleN._uid = pidx;
      #ifdef USE_MPI
      particleN._uid += mpi_node_rank * ncount; 
      #endif

      srandom(_hash((pidx+1)*(seed+1)));

      raytrace(_particle);
    } /* inner for */
    seed = seed+gpu_innerloop;
  } /* target data map section */
} /* CPU for */
  MPI_MASTER(
  printf("*** TRACE end *** (%i)\n",_instrument_var._counter);
  );

  // if on GPU and mcdotrace just exit
  #if defined(OPENACC) || defined(_OPENMP)
  }
  #endif

} /* raytrace_all */

#endif //no-FUNNEL

#ifdef FUNNEL
// Alternative raytrace algorithm which iterates all particles through
// one component at the time, can remove absorbs from the next loop and
// switch between cpu/gpu.
void raytrace_all_funnel(unsigned long long ncount, unsigned long seed) {

  // if on GPU and mcdotrace just exit
  #if defined(OPENACC) || defined(_OPENMP)
  if (!mcdotrace) {
  #endif
  // set up outer (CPU) loop / particle batches
  unsigned long long loops;

  /* if on GPU, printf has been globally nullified, re-enable here */
   #if defined(OPENACC) || defined(_OPENMP)
   #undef strlen
   #undef strcmp
   #undef exit
   #undef printf
   #undef sprintf
   #undef fprintf
   #endif
   #pragma omp target data map(tofrom: _Origin_var)
   #pragma omp target data map(tofrom: _source_var)
   #pragma omp target data map(tofrom: _slit_var)
   #pragma omp target data map(tofrom: _sample_var)
   #pragma omp target data map(tofrom: _det_var)
   #pragma omp target data map(tofrom:_instrument_var)
 { 
  #if defined(OPENACC) || defined(_OPENMP)
  loops = ceil((double)ncount/gpu_innerloop);
  if (ncount>gpu_innerloop) {
    printf("Defining %llu CPU loops around kernel and adjusting ncount\n",loops);
    mcset_ncount(loops*gpu_innerloop);
  } else {
  #endif
    loops=1;
    gpu_innerloop = ncount;
  #if defined(OPENACC) || defined(_OPENMP)
  }
  #endif

  // create particles struct and pointer arrays (same memory used by all batches)
  _class_particle* particles = malloc(gpu_innerloop*sizeof(_class_particle));
  _class_particle* pbuffer = malloc(gpu_innerloop*sizeof(_class_particle));
  double* weights = malloc(gpu_innerloop*sizeof(double));
  long livebatchsize = gpu_innerloop;

  #undef ABSORB0
  #undef ABSORB
  #define ABSORB0 do { DEBUG_ABSORB(); MAGNET_OFF; ABSORBED++; } while(0)
  #define ABSORB ABSORB0
  // outer loop / particle batches
  for (unsigned long long cloop=0; cloop<loops; cloop++) {
    if (loops>1) fprintf(stdout, "%d..", (int)cloop); fflush(stdout);

    // init particles
    #pragma omp target teams num_teams(64) thread_limit(16) loop map(tofrom: particles[0:livebatchsize], weights[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      // generate particle state, set loop index and seed
      particles[pidx] = mcgenstate();
      _class_particle* _particle = particles + pidx;
      _particle->_uid = pidx;
      #ifdef USE_MPI
      _particle->_uid += mpi_node_rank * ncount; 
      #endif
      int old;
      #pragma omp atomic capture
      {
        old=_instrument_var._counter+1; _instrument_var._counter=old;
      }
      weights[pidx]=p;
      srandom(_hash((pidx+1)*(seed+1))); // _particle->state usage built into srandom macro
    }

    double psum=0;
    // Check that we populated GPU with data and get back a reasonable sum
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      psum+=weights[pidx];
    }
   printf("** Particle creation end weightsum=%g\n",psum);

    // iterate components

    #pragma omp target teams num_teams(64) thread_limit(16) loop map(tofrom: particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // Origin
    if (!ABSORBED && _particle->_index == 1) {
#ifndef MULTICORE
        if (_Origin_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _Origin_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_Origin_var._position_relative, _Origin_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Progress_bar_trace(&_Origin_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // source
    if (!ABSORBED && _particle->_index == 2) {
#ifndef MULTICORE
        if (_source_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _source_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_source_var._position_relative, _source_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Source_simple_trace(&_source_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // slit
    if (!ABSORBED && _particle->_index == 3) {
#ifndef MULTICORE
        if (_slit_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _slit_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_slit_var._position_relative, _slit_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Slit_trace(&_slit_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }
    }

    // SPLIT with available livebatchsize 
    long mult_sample;
    livebatchsize = sort_absorb_last(particles, pbuffer, livebatchsize, gpu_innerloop, 1, &mult_sample);
    //printf("livebatchsize: %ld, split: %ld\n",  livebatchsize, mult);

    #pragma omp target teams num_teams(64) thread_limit(16) loop map(tofrom: particles[0:livebatchsize])
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      _class_particle* _particle = &particles[pidx];
      _class_particle _particle_save;

      // sample
    if (!ABSORBED && _particle->_index == 4) {
#ifndef MULTICORE
        if (_sample_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _sample_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_sample_var._position_relative, _sample_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_Single_crystal_trace(&_sample_var, _particle); /* contains EXTEND code */
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }

      // det
    if (!ABSORBED && _particle->_index == 5) {
#ifndef MULTICORE
        if (_det_var._rotation_is_identity)
          coords_get(coords_add(coords_set(x,y,z), _det_var._position_relative),&x, &y, &z);
        else
#endif
          mccoordschange(_det_var._position_relative, _det_var._rotation_relative, _particle);
        _particle_save = *_particle;
        class_PSD_monitor_4PI_trace(&_det_var, _particle);
        if (_particle->_restore)
        particle_restore(_particle, &_particle_save);
        _particle->_index++;
      }
      weights[pidx]=p;
    }

    psum=0;
    // Check that we populated GPU with data and get back a reasonable sum
    for (unsigned long pidx=0 ; pidx < livebatchsize ; pidx++) {
      psum+=weights[pidx];
    }
   printf("** Particle TRACE end weightsum=%g\n",psum);

    // jump to next viable seed
    seed = seed + gpu_innerloop;
  } // outer loop / particle batches

  free(particles);
  free(pbuffer);
 } /* data map region end*/

  printf("\n");
  // if on GPU and mcdotrace just exit
  printf("*** TRACE end *** (%i)\n",_instrument_var._counter);
  #if defined(OPENACC) || defined(_OPENMP)
  }
  #endif
} /* raytrace_all_funnel */
#endif // FUNNEL

#undef x
#undef y
#undef z
#undef vx
#undef vy
#undef vz
#undef t
#undef sx
#undef sy
#undef sz
#undef p
#undef mcgravitation
#undef mcMagnet
#undef allow_backprop
#undef _mctmp_a
#undef _mctmp_b
#undef _mctmp_c
#if defined(OPENACC) || defined(_OPENMP)
#undef strlen
#undef strcmp
#undef exit
#undef printf
#undef sprintf
#undef fprintf
#endif
#undef SCATTERED
#undef RESTORE
#undef RESTORE_NEUTRON
#undef STORE_NEUTRON
#undef ABSORBED
#undef ABSORB
#undef ABSORB0
/* *****************************************************************************
* instrument 'templateNMX' and components SAVE
***************************************************************************** */

_class_Progress_bar *class_Progress_bar_save(_class_Progress_bar *_comp
) {
  #define profile (_comp->profile)
  #define percent (_comp->percent)
  #define flag_save (_comp->flag_save)
  #define minutes (_comp->minutes)
  #define IntermediateCnts (_comp->IntermediateCnts)
  #define StartTime (_comp->StartTime)
  #define EndTime (_comp->EndTime)
  #define CurrentTime (_comp->CurrentTime)
  #define infostring (_comp->infostring)
  SIG_MESSAGE("[_Origin_save] component Origin=Progress_bar() SAVE [Progress_bar:0]");

  MPI_MASTER (fprintf (stdout, "\nSave [%s]\n", instrument_name););
  if (profile && strlen (profile) && strcmp (profile, "NULL") && strcmp (profile, "0")) {
    char filename[256];
    if (!strlen (profile) || !strcmp (profile, "NULL") || !strcmp (profile, "0"))
      strcpy (filename, instrument_name);
    else
      strcpy (filename, profile);
    DETECTOR_OUT_1D ("Intensity profiler", "Component index [1]", "Intensity", "prof", 1, mcNUMCOMP, mcNUMCOMP - 1, &(instrument->counter_N[1]),
                     &(instrument->counter_P[1]), &(instrument->counter_P2[1]), filename);
  }
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_save */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_save(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->nx)
  #define ny (_comp->ny)
  #define filename (_comp->filename)
  #define nowritefile (_comp->nowritefile)
  #define radius (_comp->radius)
  #define restore_neutron (_comp->restore_neutron)
  #define PSD_N (_comp->PSD_N)
  #define PSD_p (_comp->PSD_p)
  #define PSD_p2 (_comp->PSD_p2)
  SIG_MESSAGE("[_det_save] component det=PSD_monitor_4PI() SAVE [PSD_monitor_4PI:0]");

  if (!nowritefile) {
    DETECTOR_OUT_2D ("4PI PSD monitor", "Longitude [deg]", "Latitude [deg]", -180, 180, -90, 90, nx, ny, &PSD_N[0][0], &PSD_p[0][0], &PSD_p2[0][0], filename);
  }
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_save */



int save(FILE *handle) { /* called by mccode_main for templateNMX:SAVE */
  if (!handle) siminfo_init(NULL);

  /* call iteratively all components SAVE */
  class_Progress_bar_save(&_Origin_var);




  class_PSD_monitor_4PI_save(&_det_var);

  if (!handle) siminfo_close(); 

  return(0);
} /* save */

/* *****************************************************************************
* instrument 'templateNMX' and components FINALLY
***************************************************************************** */

_class_Progress_bar *class_Progress_bar_finally(_class_Progress_bar *_comp
) {
  #define profile (_comp->profile)
  #define percent (_comp->percent)
  #define flag_save (_comp->flag_save)
  #define minutes (_comp->minutes)
  #define IntermediateCnts (_comp->IntermediateCnts)
  #define StartTime (_comp->StartTime)
  #define EndTime (_comp->EndTime)
  #define CurrentTime (_comp->CurrentTime)
  #define infostring (_comp->infostring)
  SIG_MESSAGE("[_Origin_finally] component Origin=Progress_bar() FINALLY [Progress_bar:0]");

  time_t NowTime;
  time (&NowTime);
  fprintf (stdout, "\nFinally [%s: %s]. Time: ", instrument_name, dirname ? dirname : ".");
  if (difftime (NowTime, StartTime) < 60.0)
    fprintf (stdout, "%g [s] ", difftime (NowTime, StartTime));
  else if (difftime (NowTime, StartTime) > 3600.0)
    fprintf (stdout, "%g [h] ", difftime (NowTime, StartTime) / 3600.0);
  else
    fprintf (stdout, "%g [min] ", difftime (NowTime, StartTime) / 60.0);
  fprintf (stdout, "\n");
  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_finally */

_class_Single_crystal *class_Single_crystal_finally(_class_Single_crystal *_comp
) {
  #define reflections (_comp->reflections)
  #define geometry (_comp->geometry)
  #define mosaic_AB (_comp->mosaic_AB)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define zdepth (_comp->zdepth)
  #define radius (_comp->radius)
  #define delta_d_d (_comp->delta_d_d)
  #define mosaic (_comp->mosaic)
  #define mosaic_a (_comp->mosaic_a)
  #define mosaic_b (_comp->mosaic_b)
  #define mosaic_c (_comp->mosaic_c)
  #define recip_cell (_comp->recip_cell)
  #define barns (_comp->barns)
  #define ax (_comp->ax)
  #define ay (_comp->ay)
  #define az (_comp->az)
  #define bx (_comp->bx)
  #define by (_comp->by)
  #define bz (_comp->bz)
  #define cx (_comp->cx)
  #define cy (_comp->cy)
  #define cz (_comp->cz)
  #define p_transmit (_comp->p_transmit)
  #define sigma_abs (_comp->sigma_abs)
  #define sigma_inc (_comp->sigma_inc)
  #define aa (_comp->aa)
  #define bb (_comp->bb)
  #define cc (_comp->cc)
  #define order (_comp->order)
  #define extra_order (_comp->extra_order)
  #define RX (_comp->RX)
  #define RY (_comp->RY)
  #define powder (_comp->powder)
  #define PG (_comp->PG)
  #define deltak (_comp->deltak)
  #define hkl_info (_comp->hkl_info)
  #define offdata (_comp->offdata)
  #define hkl_list (_comp->hkl_list)
  #define tau_list (_comp->tau_list)
  SIG_MESSAGE("[_sample_finally] component sample=Single_crystal() FINALLY [Single_crystal:0]");

  #ifdef USE_MPI
  if (mpi_node_rank == mpi_node_root) {
    #endif

    if (hkl_info.flag_warning)
      fprintf (stderr, "Single_crystal: %s: Error message was repeated %i times with absorbed neutrons.\n", NAME_CURRENT_COMP, hkl_info.flag_warning);

    /* in case this instance is used in a SPLIT, we can recommend the
       optimal iteration value */
    if (hkl_info.max_tau_count >= MCSX_REFL_SLIST_SIZE) {
      fprintf (stderr, "Warning (%s): The reflection short list buffer was exhausted at least once. Please consider redefining MCSX_REFL_SLIST_SIZE > %d\n",
               NAME_CURRENT_COMP, MCSX_REFL_SLIST_SIZE);
    }

    if (hkl_info.nb_refl_count) {
      double split_iterations = (double)hkl_info.nb_reuses / hkl_info.nb_refl_count + 1;
      double split_optimal = (double)hkl_info.nb_refl / hkl_info.nb_refl_count;
      if (split_optimal > split_iterations + 5)
        printf ("Single_crystal: %s: Info: you may highly improve the computation efficiency by using\n"
                "    SPLIT %i COMPONENT %s=Single_crystal(order=1, ...)\n"
                "  in the instrument description %s.\n",
                NAME_CURRENT_COMP, (int)split_optimal, NAME_CURRENT_COMP, instrument_source);
    }
    #ifdef USE_OPENCL
    if (oclContext_SX.Kernel) {
      int iDevice = 0;
      // clear OpenCL memory

      if (oclContext_SX.GPUContext)
        clReleaseContext (oclContext_SX.GPUContext);
      if (oclContext_SX.Kernel)
        clReleaseKernel (oclContext_SX.Kernel);
      if (oclContext_SX.CommandQueue[iDevice])
        clReleaseCommandQueue (oclContext_SX.CommandQueue[iDevice]);

      if (d_L)
        clReleaseMemObject (d_L);
      if (d_T)
        clReleaseMemObject (d_T);
      if (d_tau_count)
        clReleaseMemObject (d_tau_count);
      if (d_coh_refl)
        clReleaseMemObject (d_coh_refl);
      if (d_coh_xsect)
        clReleaseMemObject (d_coh_xsect);
    }
    #endif

    #ifdef USE_MPI
  }
  #endif
  #undef reflections
  #undef geometry
  #undef mosaic_AB
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef radius
  #undef delta_d_d
  #undef mosaic
  #undef mosaic_a
  #undef mosaic_b
  #undef mosaic_c
  #undef recip_cell
  #undef barns
  #undef ax
  #undef ay
  #undef az
  #undef bx
  #undef by
  #undef bz
  #undef cx
  #undef cy
  #undef cz
  #undef p_transmit
  #undef sigma_abs
  #undef sigma_inc
  #undef aa
  #undef bb
  #undef cc
  #undef order
  #undef extra_order
  #undef RX
  #undef RY
  #undef powder
  #undef PG
  #undef deltak
  #undef hkl_info
  #undef offdata
  #undef hkl_list
  #undef tau_list
  return(_comp);
} /* class_Single_crystal_finally */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_finally(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->nx)
  #define ny (_comp->ny)
  #define filename (_comp->filename)
  #define nowritefile (_comp->nowritefile)
  #define radius (_comp->radius)
  #define restore_neutron (_comp->restore_neutron)
  #define PSD_N (_comp->PSD_N)
  #define PSD_p (_comp->PSD_p)
  #define PSD_p2 (_comp->PSD_p2)
  SIG_MESSAGE("[_det_finally] component det=PSD_monitor_4PI() FINALLY [PSD_monitor_4PI:0]");

  destroy_darr2d (PSD_N);
  destroy_darr2d (PSD_p);
  destroy_darr2d (PSD_p2);
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_finally */



int finally(void) { /* called by mccode_main for templateNMX:FINALLY */

  siminfo_init(NULL);
  save(siminfo_file); /* save data when simulation ends */

  /* call iteratively all components FINALLY */
  class_Progress_bar_finally(&_Origin_var);



  class_Single_crystal_finally(&_sample_var);

  class_PSD_monitor_4PI_finally(&_det_var);

  siminfo_close(); 

  return(0);
} /* finally */

/* *****************************************************************************
* instrument 'templateNMX' and components DISPLAY
***************************************************************************** */

  #define magnify     mcdis_magnify
  #define line        mcdis_line
  #define dashed_line mcdis_dashed_line
  #define multiline   mcdis_multiline
  #define rectangle   mcdis_rectangle
  #define box         mcdis_box
  #define circle      mcdis_circle
  #define cylinder    mcdis_cylinder
  #define sphere      mcdis_sphere
  #define cone        mcdis_cone
  #define polygon     mcdis_polygon
  #define polyhedron  mcdis_polyhedron
_class_Progress_bar *class_Progress_bar_display(_class_Progress_bar *_comp
) {
  #define profile (_comp->profile)
  #define percent (_comp->percent)
  #define flag_save (_comp->flag_save)
  #define minutes (_comp->minutes)
  #define IntermediateCnts (_comp->IntermediateCnts)
  #define StartTime (_comp->StartTime)
  #define EndTime (_comp->EndTime)
  #define CurrentTime (_comp->CurrentTime)
  #define infostring (_comp->infostring)
  SIG_MESSAGE("[_Origin_display] component Origin=Progress_bar() DISPLAY [Progress_bar:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  #undef profile
  #undef percent
  #undef flag_save
  #undef minutes
  #undef IntermediateCnts
  #undef StartTime
  #undef EndTime
  #undef CurrentTime
  #undef infostring
  return(_comp);
} /* class_Progress_bar_display */

_class_Source_simple *class_Source_simple_display(_class_Source_simple *_comp
) {
  #define radius (_comp->radius)
  #define yheight (_comp->yheight)
  #define xwidth (_comp->xwidth)
  #define dist (_comp->dist)
  #define focus_xw (_comp->focus_xw)
  #define focus_yh (_comp->focus_yh)
  #define E0 (_comp->E0)
  #define dE (_comp->dE)
  #define lambda0 (_comp->lambda0)
  #define dlambda (_comp->dlambda)
  #define flux (_comp->flux)
  #define gauss (_comp->gauss)
  #define target_index (_comp->target_index)
  #define pmul (_comp->pmul)
  #define srcArea (_comp->srcArea)
  #define square (_comp->square)
  #define tx (_comp->tx)
  #define ty (_comp->ty)
  #define tz (_comp->tz)
  SIG_MESSAGE("[_source_display] component source=Source_simple() DISPLAY [Source_simple:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (square == 1) {
    
    rectangle("xy",0,0,0,xwidth,yheight);
  } else {
    
    circle("xy",0,0,0,radius);
  }
  if (dist) {
    dashed_line(0,0,0, -focus_xw/2+tx,-focus_yh/2+ty,tz, 4);
    dashed_line(0,0,0,  focus_xw/2+tx,-focus_yh/2+ty,tz, 4);
    dashed_line(0,0,0,  focus_xw/2+tx, focus_yh/2+ty,tz, 4);
    dashed_line(0,0,0, -focus_xw/2+tx, focus_yh/2+ty,tz, 4);
  }
  #undef radius
  #undef yheight
  #undef xwidth
  #undef dist
  #undef focus_xw
  #undef focus_yh
  #undef E0
  #undef dE
  #undef lambda0
  #undef dlambda
  #undef flux
  #undef gauss
  #undef target_index
  #undef pmul
  #undef srcArea
  #undef square
  #undef tx
  #undef ty
  #undef tz
  return(_comp);
} /* class_Source_simple_display */

_class_Slit *class_Slit_display(_class_Slit *_comp
) {
  #define xmin (_comp->xmin)
  #define xmax (_comp->xmax)
  #define ymin (_comp->ymin)
  #define ymax (_comp->ymax)
  #define radius (_comp->radius)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define isradial (_comp->isradial)
  SIG_MESSAGE("[_slit_display] component slit=Slit() DISPLAY [Slit:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);

  if (is_unset (radius)) {
    double xw, yh;
    xw = (xmax - xmin) / 2.0;
    yh = (ymax - ymin) / 2.0;
    multiline (3, xmin - xw, (double)ymax, 0.0, (double)xmin, (double)ymax, 0.0, (double)xmin, ymax + yh, 0.0);
    multiline (3, xmax + xw, (double)ymax, 0.0, (double)xmax, (double)ymax, 0.0, (double)xmax, ymax + yh, 0.0);
    multiline (3, xmin - xw, (double)ymin, 0.0, (double)xmin, (double)ymin, 0.0, (double)xmin, ymin - yh, 0.0);
    multiline (3, xmax + xw, (double)ymin, 0.0, (double)xmax, (double)ymin, 0.0, (double)xmax, ymin - yh, 0.0);
  } else {
    circle ("xy", 0, 0, 0, radius);
  }
  #undef xmin
  #undef xmax
  #undef ymin
  #undef ymax
  #undef radius
  #undef xwidth
  #undef yheight
  #undef isradial
  return(_comp);
} /* class_Slit_display */

_class_Single_crystal *class_Single_crystal_display(_class_Single_crystal *_comp
) {
  #define reflections (_comp->reflections)
  #define geometry (_comp->geometry)
  #define mosaic_AB (_comp->mosaic_AB)
  #define xwidth (_comp->xwidth)
  #define yheight (_comp->yheight)
  #define zdepth (_comp->zdepth)
  #define radius (_comp->radius)
  #define delta_d_d (_comp->delta_d_d)
  #define mosaic (_comp->mosaic)
  #define mosaic_a (_comp->mosaic_a)
  #define mosaic_b (_comp->mosaic_b)
  #define mosaic_c (_comp->mosaic_c)
  #define recip_cell (_comp->recip_cell)
  #define barns (_comp->barns)
  #define ax (_comp->ax)
  #define ay (_comp->ay)
  #define az (_comp->az)
  #define bx (_comp->bx)
  #define by (_comp->by)
  #define bz (_comp->bz)
  #define cx (_comp->cx)
  #define cy (_comp->cy)
  #define cz (_comp->cz)
  #define p_transmit (_comp->p_transmit)
  #define sigma_abs (_comp->sigma_abs)
  #define sigma_inc (_comp->sigma_inc)
  #define aa (_comp->aa)
  #define bb (_comp->bb)
  #define cc (_comp->cc)
  #define order (_comp->order)
  #define extra_order (_comp->extra_order)
  #define RX (_comp->RX)
  #define RY (_comp->RY)
  #define powder (_comp->powder)
  #define PG (_comp->PG)
  #define deltak (_comp->deltak)
  #define hkl_info (_comp->hkl_info)
  #define offdata (_comp->offdata)
  #define hkl_list (_comp->hkl_list)
  #define tau_list (_comp->tau_list)
  SIG_MESSAGE("[_sample_display] component sample=Single_crystal() DISPLAY [Single_crystal:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  if (hkl_info.shape == 0) { /* cylinder */
    circle ("xz", 0, yheight / 2.0, 0, radius);
    circle ("xz", 0, -yheight / 2.0, 0, radius);
    line (-radius, -yheight / 2.0, 0, -radius, +yheight / 2.0, 0);
    line (+radius, -yheight / 2.0, 0, +radius, +yheight / 2.0, 0);
    line (0, -yheight / 2.0, -radius, 0, +yheight / 2.0, -radius);
    line (0, -yheight / 2.0, +radius, 0, +yheight / 2.0, +radius);
  } else if (hkl_info.shape == 1) { /* box */
    double xmin = -0.5 * xwidth;
    double xmax = 0.5 * xwidth;
    double ymin = -0.5 * yheight;
    double ymax = 0.5 * yheight;
    double zmin = -0.5 * zdepth;
    double zmax = 0.5 * zdepth;
    multiline (5, xmin, ymin, zmin, xmax, ymin, zmin, xmax, ymax, zmin, xmin, ymax, zmin, xmin, ymin, zmin);
    multiline (5, xmin, ymin, zmax, xmax, ymin, zmax, xmax, ymax, zmax, xmin, ymax, zmax, xmin, ymin, zmax);
    line (xmin, ymin, zmin, xmin, ymin, zmax);
    line (xmax, ymin, zmin, xmax, ymin, zmax);
    line (xmin, ymax, zmin, xmin, ymax, zmax);
    line (xmax, ymax, zmin, xmax, ymax, zmax);
  } else if (hkl_info.shape == 2) { /* sphere */
    circle ("xy", 0, 0.0, 0, radius);
    circle ("xz", 0, 0.0, 0, radius);
    circle ("yz", 0, 0.0, 0, radius);
  } else if (hkl_info.shape == 3) { /* OFF file */
    off_display (offdata);
  }
  #undef reflections
  #undef geometry
  #undef mosaic_AB
  #undef xwidth
  #undef yheight
  #undef zdepth
  #undef radius
  #undef delta_d_d
  #undef mosaic
  #undef mosaic_a
  #undef mosaic_b
  #undef mosaic_c
  #undef recip_cell
  #undef barns
  #undef ax
  #undef ay
  #undef az
  #undef bx
  #undef by
  #undef bz
  #undef cx
  #undef cy
  #undef cz
  #undef p_transmit
  #undef sigma_abs
  #undef sigma_inc
  #undef aa
  #undef bb
  #undef cc
  #undef order
  #undef extra_order
  #undef RX
  #undef RY
  #undef powder
  #undef PG
  #undef deltak
  #undef hkl_info
  #undef offdata
  #undef hkl_list
  #undef tau_list
  return(_comp);
} /* class_Single_crystal_display */

_class_PSD_monitor_4PI *class_PSD_monitor_4PI_display(_class_PSD_monitor_4PI *_comp
) {
  #define nx (_comp->nx)
  #define ny (_comp->ny)
  #define filename (_comp->filename)
  #define nowritefile (_comp->nowritefile)
  #define radius (_comp->radius)
  #define restore_neutron (_comp->restore_neutron)
  #define PSD_N (_comp->PSD_N)
  #define PSD_p (_comp->PSD_p)
  #define PSD_p2 (_comp->PSD_p2)
  SIG_MESSAGE("[_det_display] component det=PSD_monitor_4PI() DISPLAY [PSD_monitor_4PI:0]");

  printf("MCDISPLAY: component %s\n", _comp->_name);
  circle ("xy", 0, 0, 0, radius);
  circle ("xz", 0, 0, 0, radius);
  circle ("yz", 0, 0, 0, radius);
  #undef nx
  #undef ny
  #undef filename
  #undef nowritefile
  #undef radius
  #undef restore_neutron
  #undef PSD_N
  #undef PSD_p
  #undef PSD_p2
  return(_comp);
} /* class_PSD_monitor_4PI_display */


  #undef magnify
  #undef line
  #undef dashed_line
  #undef multiline
  #undef rectangle
  #undef box
  #undef circle
  #undef cylinder
  #undef sphere

int display(void) { /* called by mccode_main for templateNMX:DISPLAY */
  printf("MCDISPLAY: start\n");

  /* call iteratively all components DISPLAY */
  class_Progress_bar_display(&_Origin_var);

  class_Source_simple_display(&_source_var);

  class_Slit_display(&_slit_var);

  class_Single_crystal_display(&_sample_var);

  class_PSD_monitor_4PI_display(&_det_var);

  printf("MCDISPLAY: end\n");

  return(0);
} /* display */

void* _getvar_parameters(char* compname)
/* enables settings parameters based use of the GETPAR macro */
{
  #if defined(OPENACC) || defined(_OPENMP)
    #define strcmp(a,b) str_comp(a,b)
  #endif
  if (!strcmp(compname, "Origin")) return (void *) &(_Origin_var);
  if (!strcmp(compname, "source")) return (void *) &(_source_var);
  if (!strcmp(compname, "slit")) return (void *) &(_slit_var);
  if (!strcmp(compname, "sample")) return (void *) &(_sample_var);
  if (!strcmp(compname, "det")) return (void *) &(_det_var);
  return 0;
}

void* _get_particle_var(char *token, _class_particle *p)
/* enables setpars based use of GET_PARTICLE_DVAR macro and similar */
{
  return 0;
}

int _getcomp_index(char* compname)
/* Enables retrieving the component position & rotation when the index is not known.
 * Component indexing into MACROS, e.g., POS_A_COMP_INDEX, are 1-based! */
{
  if (!strcmp(compname, "Origin")) return 1;
  if (!strcmp(compname, "source")) return 2;
  if (!strcmp(compname, "slit")) return 3;
  if (!strcmp(compname, "sample")) return 4;
  if (!strcmp(compname, "det")) return 5;
  return -1;
}

/* embedding file "metadata-r.c" */

/** --- Contents of  metadata-r.c ---------------------------------------------------------------------------------- */
// Created by Gregory Tucker, Data Management Software Centre, European Spallation Source ERIC on 07/07/23.
#ifndef MCCODE_NAME
#include "metadata-r.h"
#endif

char * metadata_table_key_component(char* key){
  if (strlen(key) == 0) return NULL;
  char sep[2] = ":\0"; // matches any number of repeated colons
  // look for the separator in the provided key; strtok is allowed to modify the string, so copy it
  char * tok = malloc((strlen(key) + 1) * sizeof(char));
  if (!tok) {
    fprintf(stderr,"Error allocating token\n");
    exit(-1);
  }
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided) -- but we need to move the pointer
  char * comp = malloc((1 + strlen(pch)) * sizeof(char));
  if (!comp) {
    fprintf(stderr,"Error allocating comp\n");
    exit(-1);
  }
  strcpy(comp, pch);
  if (tok) free(tok);
  return comp;
}
char * metadata_table_key_literal(char * key){
  if (strlen(key) == 0) return NULL;
  char sep[3] = ":\0";
  char * tok = malloc((strlen(key) + 1 ) * sizeof(char));
  if (!tok) {
    fprintf(stderr,"Error allocating token\n");
    exit(-1);
  }
  strcpy(tok, key);
  char * pch = strtok(tok, sep); // this *is* the component name (if provided)
  if (pch) pch = strtok(NULL, sep); // either NULL or the literal name
  char * name = NULL;
  if (pch) {
    name = malloc((1 + strlen(pch)) * sizeof(char));
    if (!name) {
      fprintf(stderr,"Error allocating name\n");
	exit(-1);
    }
    strcpy(name, pch);
  }
  if (tok) free(tok);
  return name;
}
int metadata_table_defined(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0){
    /* This is 0 instead of `no` independent of any wildcard-matching logic
     * because a caller _already_ knows `no` and can verify
     * that `key` is not "" at call-time. So returning `no` is useless.
     */
    return 0;
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  // look through the table for the matching component and literal names
  int number = 0;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source)){
      if (name == NULL || !strcmp(name, tab[i].name)) ++number;
    }
  }
  if (comp) free(comp);
  if (name) free(name);
  return number;
}

char * metadata_table_name(int no, metadata_table_t * tab, char *key){
    if (strlen(key) == 0){
        return NULL;
    }
    char * comp = metadata_table_key_component(key);
    char * name = metadata_table_key_literal(key);
    if (name == NULL) {
        for (int i=0; i<no; ++i){
            if (!strcmp(comp, tab[i].source)){
                name = malloc((strlen(tab[i].name) + 1) * sizeof(char));
		if (!name) {
		  fprintf(stderr,"Error allocating metadata_table_name\n");
		  exit(-1);
		}
                strcpy(name, tab[i].name);
                break;
            }
        }
    } else {
        int found=0;
        for (int i=0; i<no; ++i){
            if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) {
                found = 1;
                break;
            }
        }
        if (!found) free(name);
    }
    free(comp);
    return name;
}

char * metadata_table_type(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to check type of non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to check type of literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].type;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}

char * metadata_table_literal(int no, metadata_table_t * tab, char * key){
  if (strlen(key) == 0) {
    fprintf(stderr, "Unable to retrieve literal for non-existent key\n");
    exit(1);
  }
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  if (name == NULL){
    fprintf(stderr, "Unable to retrieve literal for component %s without its name\n", comp);
    free(comp);
    exit(1);
  }
  char * type = NULL;
  for (int i=0; i<no; ++i){
    if (!strcmp(comp, tab[i].source) && !strcmp(name, tab[i].name)) type = tab[i].value;
  }
  if (comp) free(comp);
  if (name) free(name);
  return type;
}
void metadata_table_print_all_keys(int no, metadata_table_t * tab){
  for (int i=0; i<no; ++i){
    printf("%s::%s ", tab[i].source, tab[i].name);
  }
  printf("\n");
}
int metadata_table_print_all_components(int no, metadata_table_t * tab){
  int count = 0;
  char ** known = malloc(no * sizeof(char*));
  if (!known) {
    fprintf(stderr,"Error allocating table of known metadata\n");
    exit(-1);
  }
  for (int i=0; i<no; ++i){
    int unknown = 1;
    for (int j=0; j<count; ++j) if (!strcmp(tab[i].source, known[j])) unknown = 0;
    if (unknown) known[count++] = tab[i].source;
  }
  size_t nchar = 0;
  for (int i=0; i<count; ++i) nchar += strlen(known[i]) + 1;
  char * line = malloc((nchar + 1) * sizeof(char));
  char * linetmp = malloc((nchar + 1) * sizeof(char));
  if (!line || !linetmp) {
    fprintf(stderr,"Error allocating metadata print arrays\n");
    exit(-1);
  }
  line[0] = '\0';
  for (int i=0; i<count; ++i) sprintf(linetmp, "%s%s ", line, known[i]);
  line=linetmp;
  line[strlen(line)] = '\0'; // eat the trailing space
  printf("%s\n", line);
  free(line);
  free(linetmp);
  free(known);
  return count;
}
int metadata_table_print_component_keys(int no, metadata_table_t * tab, char * key){
  char * comp = metadata_table_key_component(key);
  char * name = metadata_table_key_literal(key);
  int count = 0;
  for (int i=0; i<no; ++i) if (!strcmp(tab[i].source, comp) && (name == NULL || !strcmp(tab[i].name, name))) {
    if (name == NULL) printf("%s ", tab[i].name);
    ++count;
  }
  if (name != NULL) printf("%d", count); // replace count by strlen(tab[i].value)?
  printf("\n");
  return count;
}
/* -------------------------------------------------------------------------------------Contents of  metadata-r.c --- */
/* End of file "metadata-r.c". */

/* embedding file "mccode_main.c" */

/*******************************************************************************
* mccode_main: McCode main() function.
*******************************************************************************/
int mccode_main(int argc, char *argv[])
{
  /*  double run_num = 0; */
  time_t  t;
  clock_t ct;

#ifdef USE_MPI
  char mpi_node_name[MPI_MAX_PROCESSOR_NAME];
  int  mpi_node_name_len;
#endif /* USE_MPI */

#ifdef MAC
  argc = ccommand(&argv);
#endif

#ifdef USE_MPI
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_node_count); /* get number of nodes */
  MPI_Comm_rank(MPI_COMM_WORLD, &mpi_node_rank);
  MPI_Comm_set_name(MPI_COMM_WORLD, instrument_name);
  MPI_Get_processor_name(mpi_node_name, &mpi_node_name_len);
#endif /* USE_MPI */

  ct = clock();

  // device and host functional RNG seed
  struct timeval tm;
  gettimeofday(&tm, NULL);
  mcseed = (long) tm.tv_sec*1000000 + tm.tv_usec;
  mcstartdate = (long)tm.tv_sec;  /* set start date before parsing options and creating sim file */
  // init global _particle.randstate for random number use
  // during init(), finally() and display(). NOTE: during trace, a local
  // "_particle" variable is present and thus used instead.
  //
  // PW: srandom deferred until init() since we did not read seed input from commandline
  //srandom(_hash(mcseed-1));

#ifdef USE_MPI
  /* *** print number of nodes *********************************************** */
  if (mpi_node_count > 1) {
    MPI_MASTER(
    printf("Simulation '%s' (%s): running on %i nodes (master is '%s', MPI version %i.%i).\n",
      instrument_name, instrument_source, mpi_node_count, mpi_node_name, MPI_VERSION, MPI_SUBVERSION);
    );
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per noe */
  }
#endif /* USE_MPI */

#if defined(OPENACC) || defined(_OPENMP)
#ifdef USE_MPI
  int num_devices = acc_get_num_devices(acc_device_nvidia);
  if(num_devices>0){
    int my_device = mpi_node_rank % num_devices;
    acc_set_device_num( my_device, acc_device_nvidia );
    printf("Have found %d GPU devices on rank %d. Will use device %d.\n", num_devices, mpi_node_rank, my_device);
  }else{
    printf("There was an issue probing acc_get_num_devices, fallback to host\n");
    acc_set_device_type( acc_device_host );
  }
#endif
#endif

  /* *** parse options ******************************************************* */
  SIG_MESSAGE("[" __FILE__ "] main START");
  mcformat = getenv(FLAVOR_UPPER "_FORMAT") ?
             getenv(FLAVOR_UPPER "_FORMAT") : FLAVOR_UPPER;
  instrument_exe = argv[0]; /* store the executable path */
  /* read simulation parameters and options */
  mcparseoptions(argc, argv); /* sets output dir and format */


#ifdef USE_MPI
  if (mpi_node_count > 1) {
    /* share the same seed, then adapt random seed for each node */
    MPI_Bcast(&mcseed, 1, MPI_LONG, 0, MPI_COMM_WORLD); /* root sends its seed to slaves */
    mcseed += mpi_node_rank; /* make sure we use different seeds per node */
  }
#endif


/* *** install sig handler, but only once !! after parameters parsing ******* */
#ifndef NOSIGNALS
#ifdef SIGQUIT
  if (signal( SIGQUIT ,sighandler) == SIG_IGN)
    signal( SIGQUIT,SIG_IGN);   /* quit (ASCII FS) */
#endif
#ifdef SIGABRT
  if (signal( SIGABRT ,sighandler) == SIG_IGN)
    signal( SIGABRT,SIG_IGN);   /* used by abort, replace SIGIOT in the future */
#endif
#ifdef SIGTERM
  if (signal( SIGTERM ,sighandler) == SIG_IGN)
    signal( SIGTERM,SIG_IGN);   /* software termination signal from kill */
#endif
#ifdef SIGUSR1
  if (signal( SIGUSR1 ,sighandler) == SIG_IGN)
    signal( SIGUSR1,SIG_IGN);   /* display simulation status */
#endif
#ifdef SIGUSR2
  if (signal( SIGUSR2 ,sighandler) == SIG_IGN)
    signal( SIGUSR2,SIG_IGN);
#endif
#ifdef SIGHUP
  if (signal( SIGHUP ,sighandler) == SIG_IGN)
    signal( SIGHUP,SIG_IGN);
#endif
#ifdef SIGILL
  if (signal( SIGILL ,sighandler) == SIG_IGN)
    signal( SIGILL,SIG_IGN);    /* illegal instruction (not reset when caught) */
#endif
#ifdef SIGFPE
  if (signal( SIGFPE ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* floating point exception */
#endif
#ifdef SIGBUS
  if (signal( SIGBUS ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);    /* bus error */
#endif
#ifdef SIGSEGV
  if (signal( SIGSEGV ,sighandler) == SIG_IGN)
    signal( SIGSEGV,SIG_IGN);   /* segmentation violation */
#endif
#endif /* !NOSIGNALS */


  // init executed by master/host
  siminfo_init(NULL); /* open SIM */
  SIG_MESSAGE("[" __FILE__ "] main INITIALISE");
  init();


#ifndef NOSIGNALS
#ifdef SIGINT
  if (signal( SIGINT ,sighandler) == SIG_IGN)
    signal( SIGINT,SIG_IGN);    /* interrupt (rubout) only after INIT */
#endif
#endif /* !NOSIGNALS */

/* ================ main particle generation/propagation loop ================ */
#ifdef USE_MPI
  /* sliced Ncount on each MPI node */
  mcncount = mpi_node_count > 1 ?
    floor(mcncount / mpi_node_count) :
    mcncount; /* number of rays per node */
#endif

// MT specific init, note that per-ray init is empty
#if RNG_ALG == 2
  mt_srandom(mcseed);
#endif


// main raytrace work loop
#ifndef FUNNEL
  // legacy version
  raytrace_all(mcncount, mcseed);
#else
  MPI_MASTER(
  // "funneled" version in which propagation is more parallelizable
  printf("\nNOTE: CPU COMPONENT grammar activated:\n 1) \"FUNNEL\" raytrace algorithm enabled.\n 2) Any SPLIT's are dynamically allocated based on available buffer size. \n");
	     );
  raytrace_all_funnel(mcncount, mcseed);
#endif


#ifdef USE_MPI
 /* merge run_num from MPI nodes */
  if (mpi_node_count > 1) {
  double mcrun_num_double = (double)mcrun_num;
  mc_MPI_Sum(&mcrun_num_double, 1);
  mcrun_num = (unsigned long long)mcrun_num_double;
  }
#endif


  // save/finally executed by master node/thread/host
  finally();


#ifdef USE_MPI
  MPI_Finalize();
#endif /* USE_MPI */


  return 0;
} /* mccode_main */
/* End of file "mccode_main.c". */

/* end of generated C code templateNMX.c */
