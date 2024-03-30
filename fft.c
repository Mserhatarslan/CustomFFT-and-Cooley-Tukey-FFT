#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

#define M_PI 3.14159265358979323846
#define FFT_SIZE 8192 

typedef double complex cplx;

void performFFT(const cplx fft_in[], cplx fft_out[])
{
    bool isEmpty = true;

    for (int i = 0; i < FFT_SIZE; i++) {

        if (creal(fft_in[i]) != 0.0 || cimag(fft_in[i]) != 0.0) {
            isEmpty = false;
            break;
        }
    }
    assert(!isEmpty);

    for (int i = 0; i < FFT_SIZE; i++) {

        fft_out[i] = 0;
        for (int j = 0; j < FFT_SIZE; j++) {
            fft_out[i] += fft_in[j] * cexp(-I * 2 * M_PI * i * j / FFT_SIZE);
        }
    }
}

int main(void)
{
    const cplx fft_in[FFT_SIZE] = { 1.0 + 0.0 * I, 2.0 + 0.0 * I};
    clock_t start, end;
    double cpu_time_used;

    cplx fft_out[FFT_SIZE]; 
      start = clock(); // Başlangıç zamanını kaydet
    performFFT(fft_in, fft_out); 
     end = clock(); // Bitiş zamanını kaydet

    printf(" FFT Results:\n");
    
    for (int i = 0; i < FFT_SIZE; i++) {
        printf("output[%d] = %.2lf + %.2lfi\n", i, creal(fft_out[i]), cimag(fft_out[i]));
    }
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Execution time = %lf seconds\n", cpu_time_used); // İşlem süresini hesapla ve yazdır
    return 0; 
}
