# C Fundamentals for Parallel Computing

A warm-up workshop building the C fundamentals needed before moving into
threading and parallel algorithms: pointer arithmetic, structs, manual
memory layout, and matrix operations implemented from scratch (no
libraries) over a static memory pool.

## What's implemented

- Basic numeric routines (`product`, day/week/year date conversion,
  Euclidean distance) exercising structs and return-by-value.
- Pointer-driven sequence generation and printing (`get_numbers`,
  `arrPrintMatrix`) using raw pointer arithmetic instead of indexing.
- **NxN matrix operations** (`add_matrix`, `sub_matrix`, `mult_matriz`)
  operating directly on a flat `double*` buffer with manual row/column
  offset computation — the same layout style used later in
  [`Bench_Pthreads`](../Bench_Pthreads) and [`Benchmark`](../Benchmark)
  for the parallel matrix multiplication benchmarks.
- A statically allocated memory pool (`MEM_CHUNK`, 64M doubles) used
  in place of dynamic allocation per matrix, to keep the exercise focused
  on pointer mechanics.

## Build & run

```bash
make app        # build the CLI driver
make test        # run every exercise in sequence
make clean        # remove object files
make clear        # full clean
```

Individual exercises can be run directly, e.g.:

```bash
make product        # exercise 1
make mutl_NxN        # exercise 10 (matrix multiplication)
```

Full exercise list and mapping to `make` targets: see the original
[workshop PDF](./Taller_C_01.pdf).

## Environment

- `gcc` 12.1+
- Standard C library only (`math.h`, `stdio.h`, `stdlib.h`, `string.h`)

## Reference

Kernighan, B. & Ritchie, D. — *The C Programming Language*