This FFT implementation directly computes the DFT using the formula without any decomposition. While this approach is straightforward,  it's not the most efficient way to compute the FFT, especially for large input sizes.

If you're interested in implementing the Cooley-Tukey FFT algorithm, you'll need to refactor your code to incorporate the divide-and-conquer strategy. 
The Cooley-Tukey algorithm typically involves recursively breaking down the DFT into smaller DFTs until you reach base cases that can be computed directly or using other algorithms 

I will share also Cooley Tukey 4-Radix FFT algorithm in this repository

# Key Points of FFT Calculation

## 2 Point FFT 

![image](https://github.com/Mserhatarslan/fft/assets/63358327/509a6981-8f53-4f5e-953e-ccc95e41db6b)
```c++
fft_input array: 

          const cplx fft_in[FFT_SIZE] = { 1.0 + 0.0 * I, 2.0 + 0.0 * I};

FFT Results:
 
          output[0] = 3.00 + 0.00i

          output[1] = -1.00 + -0.00i
```

## 4 Point FFT 

![image](https://github.com/Mserhatarslan/fft/assets/63358327/0e70eff3-1be2-4114-ac84-9e34134e500d)

```c++
fft_input array: 

          const cplx fft_in[FFT_SIZE] = { 1.0 + 0.0 * I, 2.0 + 0.0 * I, 3.0 + 0.0 * I, 4.0 + 0.0 * I};

FFT Results:

          output[0] = 10.00 + 0.00i
          
          output[1] = -2.00 + 2.00i
          
          output[2] = -2.00 + -0.00i
          
          output[3] = -2.00 + -2.00i
```

This saves a lot of adds. (Note that each add and multiply here is a complex (not real) operation.)
If we use the following diagram for a complex multiply and add:

![image](https://github.com/Mserhatarslan/fft/assets/63358327/f5b92ffb-1175-4993-bd28-26a9e0fd7a04)

then we can diagram the 4-point DFT like so:

![image](https://github.com/Mserhatarslan/fft/assets/63358327/1cacfa8c-1217-4790-8052-66c8c7053153)

If we carry on to N = 8, N = 16, and other power-of-two discrete Fourier transforms,
we get...

Comparison between Custom FFT and Cooley Tukey FFT

N = 8192 FFT SIZE 
```c++
Cooley Tukey Execution time = 0.008748 seconds

Custom FFT Execution time = 3.195926 seconds
```

N = 32768 FFT SIZE 
```c++
Cooley Tukey Execution time = 0.011058 seconds

Custom FFT Execution time = 53.008854 seconds
```

N = 65536 FFT SIZE 
```c++
Cooley Tukey Execution time = 0.029321 seconds

Custom FFT Execution time = 210.001965 seconds
```

N = 131072 FFT SIZE 
```c++
Cooley Tukey Execution time = 0.124470 seconds

Custom FFT Execution time = 942.397679 seconds
```
