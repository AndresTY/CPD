# CPD — Parallel & Distributed Computing

A collection of small, focused projects exploring parallel and distributed
computing concepts in C and Python: threading models (Pthreads, OpenMP),
CPU-bound benchmarking methodology, and native-code acceleration (Cython).
Built as coursework for *Parallel and Distributed Computing* at
Universidad Sergio Arboleda, later cleaned up and documented individually.

## Projects

| Project | What it explores | Stack |
|---|---|---|
| [`fundamentals/`](./fundamentals) | C fundamentals as a foundation for parallelism: pointers, structs, manual memory layout, matrix operations | `C` |
| [`Bench_Pthreads/`](./Bench_Pthreads) | Matrix multiplication parallelized with Pthreads, tuned across thread counts | `C` `Pthreads` `OpenMP` |
| [`Benchmark/`](./Benchmark) | Benchmarking methodology for matrix multiplication (classic vs. randomized), with statistical analysis of results | `C` `Python` `Jupyter` |
| [`planets/`](./planets) | N-body planetary motion simulation: pure Python vs. Cython, measuring the real cost of the interpreter loop | `Python` `Cython` |

## Why this repo exists

Each folder isolates one variable in the parallel/performance space —
thread management, benchmarking rigor, or native compilation — rather than
mixing concerns into a single monolithic project. Read each project's own
README for build instructions and results; this file is only the map.

## Requirements (varies by project — see each README)

- GCC with `-lpthread -fopenmp` support
- Python 3 with Cython, NumPy, and Jupyter (for `planets/` and `Benchmark/`)

## Author

Andres Santiago Ducuara Velasquez ([@AndresTY](https://github.com/AndresTY))