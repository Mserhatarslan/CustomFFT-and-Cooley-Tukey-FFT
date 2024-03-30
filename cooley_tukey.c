#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define N 8192

// Bit reversal
void bit_reverse(complex double* x) {
    int i, j, k;
    for (i = 1, j = N / 2; i < N - 1; ++i) {
        if (i < j) {
            complex double temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
        k = N / 2;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }
}

// FFT algorithm
void fft(complex double* x) {
    bit_reverse(x);

    for (int n = 2; n <= N; n *= 2) {
        for (int i = 0; i < N; i += n) {
            for (int k = 0; k < n / 2; ++k) {
                complex double t = cexp(-I * 2 * PI * k / n) * x[i + k + n / 2];
                x[i + k + n / 2] = x[i + k] - t;
                x[i + k] += t;
            }
        }
    }
}

int main() {
    complex double x[N] = {1.0 + 0.0 * I, 2.0 + 0.0 * I, 3.0 + 0.0 * I, 4.0 + 0.0 * I,
                           5.0 + 0.0 * I, 6.0 + 0.0 * I, 7.0 + 0.0 * I, 8.0 + 0.0 * I};

    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Başlangıç zamanını kaydet

    fft(x); // FFT işlemini gerçekleştir

    end = clock(); // Bitiş zamanını kaydet

    printf("FFT Results:\n");
    for (int i = 0; i < N; ++i) {
        printf("output[%d] = %.2lf + %.2lfi\n", i, creal(x[i]), cimag(x[i]));
    }

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time = %lf seconds\n", cpu_time_used); // İşlem süresini hesapla ve yazdır
    return 0;
}
