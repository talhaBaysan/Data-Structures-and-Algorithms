/*
 * Program  : Nth Fibonacci using bottom-up approach
 * Language : C
 */

#include<stdio.h>

int Fibonacci(int N)
{
    //if N = 2, we need to store 3 fibonacci members(0,1,1)
    //if N = 3, we need to store 4 fibonacci members(0,1,1,2)
    //In general to compute Fib(N), we need N+1 size array.
    int Fib[N+1],i;

    //we know Fib[0] = 0, Fib[1]=1
    Fib[0] = 0;
    Fib[1] = 1;

    for(i = 2; i <= N; i++)
        Fib[i] = Fib[i-1]+Fib[i-2];

    //last index will have the result
    return Fib[N];
}

int main()
{
    int n;
    printf("kacinci terimi hesaplamak istiyorsunuz?");
    scanf("%d",&n);

    //if n == 0 or n == 1 the result is n
    if(n <= 1)
        printf("Fib(%d) = %d\n",n,n);
    else
        printf("Fib(%d) = %d\n",n,Fibonacci(n));

    return 0;
}
