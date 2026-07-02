# Benchmark — Matrix Multiplication Benchmarking Methodology

A statistically-driven benchmark comparing matrix multiplication under
**deterministic** vs. **randomized** input initialization, focused on
methodology rather than raw speed: automated sweeps across matrix sizes,
thousands of repetitions per configuration, and post-hoc statistical
analysis of the results.

## What it measures

| Variant | Init | Purpose |
|---|---|---|
| `mmClassic.c` | Deterministic values | Baseline timing, reproducible across runs |
| `mmClassicRND.c` | Randomized values (`rnd_values`, filled 3x per run) | Checks whether input distribution affects cache behavior / timing variance |
| `mmClassic_int.c` | `int` matrices | Compares integer vs. floating-point multiplication cost |

Shared logic (matrix init, multiplication, CPU count via
`sysconf(_SC_NPROCESSORS_ONLN)`) lives in `modulo.c` / `modulo.h`.

## Benchmark methodology

`lanzador.pl` / `lanzador_int.pl` / `lanzador_RND.pl` automate the sweep:
for each matrix size in a configurable load list, the target binary is
run **5000 times** and each timing is appended to
`results/<binary>-carga-<size>.txt`. This repetition count is what makes
the results usable statistically (mean/stdev) rather than anecdotal.

```bash
make                    # builds mmClassic, mmClassicRND, mmClassic_int
perl lanzador.pl        # sweep runs, writes results/*.txt
```

## Analysis

`AnalisisDatos.ipynb` loads the raw timing files, computes mean/stdev per
configuration, and produces the comparison charts in
[`graficas/`](./graficas): bar charts per load size, histograms of timing
distribution, and time-vs-load curves for classic vs. randomized
initialization.

> Note: the notebook references a local filesystem path (`PATH = ...`) —
> update it to point at your own `results/` directory before re-running.

## Requirements

- `gcc`
- `perl`
- Python 3 with `matplotlib`, Jupyter, for the analysis notebook