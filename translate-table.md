# OpenACC to OpenMP
Minimal example conversion

| OPENACC                                                      | _OPENMP                                                           |
| ------------------------------------------------------------ | ----------------------------------------------------------------- |
| openacc.h                                                    | omp.h                                                             |
| accelmath.h                                                  | math.h                                                            |
| acc routine                                                  |                                                                   |
| acc routine seq                                              |                                                                   |
| acc declare create ()                                        | omp begin declare target<br>...<br>omp end declare target         |
| acc parallel loop present(...)                               | omp target teams loop map(...)                                    |
| acc parallel loop num_gangs(numgangs) vector_length(vecsize) | omp target teams loop                                             |
| acc loop seq                                                 | omp loop bind(thread)                                             |
| acc update device (...)                                      | omp target update to(...)                                         |
| acc update host(...)                                         | omp target update from(...)                                       |
| acc atomic                                                   | omp atomic update                                                 |
|                                                              | omp declare mapper(struct S s)  map(tofrom: s.name\[0:256\], ...) |
