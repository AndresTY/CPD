# Planets — Python vs. Cython Performance Comparison

An N-body-style planetary motion simulation (gravity, velocity, position
integration) implemented twice — once in pure Python, once in Cython —
to measure, with real numbers, what compiling the hot loop actually buys
you.

## What it does

Both `planets.py` (pure Python) and `planets_cy.pyx` (Cython, `cdef`
typed fields and `nogil` math) implement the same physics: a single
gravitational body integrated forward in time over `n_steps`, with
force computed from distance to the origin each step. `mimikyu.py` runs
both implementations across a range of step counts, times each with
`timer.py`, and appends the results to `results/planeta-<steps>.csv`.

## Measured results

Averaged over the runs in `results/`:

| Steps | Python (s) | Cython (s) | Speedup |
|---|---|---|---|
| 1,000,000 | 2.76 | 1.52 | **1.82x** |
| 50,000,000 | 137.26 | 77.94 | **1.76x** |

The ~1.8x speedup comes entirely from removing Python's per-attribute
dynamic dispatch (`cdef public double x,y,z,...` vs. plain Python
attributes) and releasing the GIL in the inner math (`nogil`) — no
algorithmic change between the two versions.

## Build & run

```bash
python setup.py build_ext --inplace        # compiles planets_cy.pyx -> .so
python mimikyu.py -s 1000000                # run both variants for 1M steps
```

Full analysis and charts: [`data analyzer.ipynb`](./data%20analyzer.ipynb).

## Requirements

- Python 3
- `Cython`, a C compiler toolchain (for `build_ext`)
- `pandas` / `matplotlib` (for the analysis notebook)