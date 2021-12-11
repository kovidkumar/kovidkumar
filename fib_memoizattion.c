
#include <stdio.h>
#include <stdlib.h>

int fib(int n, int* memo)
{
    if(n<0) return 0;
    if(n==1) return 1;
    if(memo[n] != 0) return memo[n];
    
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];

}
void allfib(int n)
{
    int *memo = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf(" %d = %d\n", i, fib(i, memo));
    }
    
    
}
int main() {
    // Write C code here
    printf("Hello world");
    allfib(10);
    
    
    return 0;
}