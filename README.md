This FFT implementation directly computes the DFT using the formula without any decomposition. While this approach is straightforward,  it's not the most efficient way to compute the FFT, especially for large input sizes.

If you're interested in implementing the Cooley-Tukey FFT algorithm, you'll need to refactor your code to incorporate the divide-and-conquer strategy. 
The Cooley-Tukey algorithm typically involves recursively breaking down the DFT into smaller DFTs until you reach base cases that can be computed directly or using other algorithms 

I will share also Cooley Tukey 4-Radix FFT algorithm in this repository

# Key Points of FFT Calculation

## 2 Point FFT 

![image](https://github.com/Mserhatarslan/fft/assets/63358327/509a6981-8f53-4f5e-953e-ccc95e41db6b)

 FFT Results:
 
output[0] = 3.00 + 0.00i

output[1] = -1.00 + -0.00i

## 4 Point FFT 

![image](https://github.com/Mserhatarslan/fft/assets/63358327/0e70eff3-1be2-4114-ac84-9e34134e500d)

FFT Results:

output[0] = 10.00 + 0.00i

output[1] = -2.00 + 2.00i

output[2] = -2.00 + -0.00i

output[3] = -2.00 + -2.00i
