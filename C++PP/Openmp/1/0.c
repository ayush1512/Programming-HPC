// ...existing code...
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <string.h>

volatile double blackhole = 0.0; // prevent optimization

static inline unsigned rng32(unsigned x) {
    return x * 1664525u + 1013904223u;
}

/* Simulated work: perform 'iters' simple ops */
static void do_work(int iters) {
    double x = 0.0;
    for (int i = 0; i < iters; ++i) {
        x += sin((double)(i + 1)) * 0.000001; // cheap math to spend cycles
    }
    blackhole += x;
}

enum pattern_t { PAT_UNIFORM=0, PAT_HEAVY=1, PAT_BURST=2 };

double run_schedule_uniform(int N, int base_work, int runs, int pattern) {
    double t0 = omp_get_wtime();
    for (int r = 0; r < runs; ++r) {
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < N; ++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) {
                unsigned v = rng32((unsigned)i);
                extra = (v % (base_work * 4));
            } else if (pattern == PAT_BURST) {
                unsigned v = rng32((unsigned)i);
                extra = ((v & 63) == 0) ? base_work * 20 : 0;
            }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

double bench_static(int N, int base_work, int runs, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(static)
        for (int i=0;i<N;++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
            else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

double bench_static_chunk(int N, int base_work, int runs, int chunk, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(static, /*chunk*/ 1)
        for (int i=0;i<N;++i) { /* placeholder replaced below */ }
    }
    // can't parametrize chunk in pragma easily; implement explicit loop below
    t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel
        {
            int tid = omp_get_thread_num();
            int nthreads = omp_get_num_threads();
            for (int start = tid * chunk; start < N; start += chunk * nthreads) {
                int end = start + chunk;
                if (end > N) end = N;
                for (int i = start; i < end; ++i) {
                    int extra = 0;
                    if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
                    else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
                    do_work(base_work + extra);
                }
            }
        }
    }
    return omp_get_wtime() - t0;
}

double bench_dynamic(int N, int base_work, int runs, int chunk, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(dynamic, 1)
        for (int i=0;i<N;++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
            else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

double bench_dynamic_chunk(int N, int base_work, int runs, int chunk, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(dynamic, 16)
        for (int i=0;i<N;++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
            else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

double bench_guided(int N, int base_work, int runs, int chunk, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(guided, 16)
        for (int i=0;i<N;++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
            else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

double bench_runtime(int N, int base_work, int runs, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(runtime)
        for (int i=0;i<N;++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
            else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

double bench_auto(int N, int base_work, int runs, int pattern) {
    double t0 = omp_get_wtime();
    for (int r=0;r<runs;++r) {
        #pragma omp parallel for schedule(auto)
        for (int i=0;i<N;++i) {
            int extra = 0;
            if (pattern == PAT_HEAVY) { unsigned v = rng32((unsigned)i); extra = (v % (base_work * 4)); }
            else if (pattern == PAT_BURST) { unsigned v = rng32((unsigned)i); extra = ((v & 63) == 0) ? base_work * 20 : 0; }
            do_work(base_work + extra);
        }
    }
    return omp_get_wtime() - t0;
}

int main(int argc, char **argv) {
    int N = 200000;            // number of iterations
    int base_work = 20;        // base inner loop iterations
    int runs = 3;              // how many repeats for timing
    int threads = 0;
    int pattern = PAT_UNIFORM;

    if (argc > 1) N = atoi(argv[1]);
    if (argc > 2) base_work = atoi(argv[2]);
    if (argc > 3) runs = atoi(argv[3]);
    if (argc > 4) pattern = atoi(argv[4]); // 0=uniform,1=heavy,2=burst
    if (argc > 5) threads = atoi(argv[5]);

    if (threads > 0) omp_set_num_threads(threads);

    printf("N=%d base_work=%d runs=%d threads=%d pattern=%d\n", N, base_work, runs, omp_get_max_threads(), pattern);

    double t;

    t = bench_static(N, base_work, runs, pattern);
    printf("static:   %8.4f s\n", t);

    t = bench_static_chunk(N, base_work, runs, 32, pattern);
    printf("static,32: %8.4f s\n", t);

    t = bench_dynamic_chunk(N, base_work, runs, 1, pattern);
    printf("dynamic,16: %8.4f s\n", t);

    t = bench_guided(N, base_work, runs, 16, pattern);
    printf("guided,16: %8.4f s\n", t);

    printf("Note: 'runtime' uses OMP_SCHEDULE env var (if set).\n");
    t = bench_runtime(N, base_work, runs, pattern);
    printf("runtime:  %8.4f s\n", t);

    t = bench_auto(N, base_work, runs, pattern);
    printf("auto:     %8.4f s\n", t);

    return 0;
}
// ...existing code...