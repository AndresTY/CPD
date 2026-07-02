# Bench_Pthreads — Matrix Multiplication: Pthreads vs. OpenMP

Benchmarks matrix multiplication under two parallelization models on the
same problem — **raw POSIX threads** (manual thread lifecycle, explicit
work partitioning via a `arg_threads` struct passed to each worker) and
**OpenMP** (`#pragma omp parallel for`) — to compare hand-managed
threading against a compiler-directed model on identical workloads.

> **Co-authored with Juan Pablo Barrios Suarez** as part of the Parallel
> and Distributed Computing coursework at Universidad Sergio Arboleda.
> Attribution preserved in the original source file headers.

## Variants

| File | Model | Data | Notes |
|---|---|---|---|
| `mm_main.c` | OpenMP (`mm_lib.c`) | `int` | Default target |
| `mm_main_double.c` | Pthreads (manual `pthread_create`/`pthread_join`) | `double` | Explicit work split across `Num_Hilos` threads via a shared arg struct |
| `mm_main_double_rnd.c` | Pthreads | `double`, randomized init | Same as above with randomized matrix values |
| `mm_main_t.c` | Pthreads | — | Additional threading variant |

Each Pthreads worker receives a slice of the output matrix (rows
partitioned by `ID_hilo`) through `arg_threads { matA, matB, matC,
Num_Hilos, size, ID_hilo }`, avoiding shared mutable state between
threads beyond the read-only input matrices.

## Build & run

```bash
make            # builds mm_main, mm_main_double, mm_main_double_rnd
./mm_main_double <N> <num_threads>        # N must be divisible by num_threads
make clean
```

`lanzador.pl` sweeps a range of matrix sizes / thread counts and collects
timing results into `results/`.

## Requirements

- `gcc` with `-lpthread -fopenmp -lm`
- `perl` (for the `lanzador.pl` sweep script)
