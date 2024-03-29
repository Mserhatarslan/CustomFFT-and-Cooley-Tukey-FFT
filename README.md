This FFT implementation directly computes the DFT using the formula without any decomposition. While this approach is straightforward,  it's not the most efficient way to compute the FFT, especially for large input sizes.

If you're interested in implementing the Cooley-Tukey FFT algorithm, you'll need to refactor your code to incorporate the divide-and-conquer strategy. 
The Cooley-Tukey algorithm typically involves recursively breaking down the DFT into smaller DFTs until you reach base cases that can be computed directly or using other algorithms 

I will share also Cooley Tukey 4-Radix FFT algorithm in this repository
