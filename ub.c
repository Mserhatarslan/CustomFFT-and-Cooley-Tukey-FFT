#include <stdio.h>

int main()
{
    const int x = 67; 
    int* ptr = (int*)&x; 
    *ptr = 78; 
    
    printf("x = %d ", x);
}
