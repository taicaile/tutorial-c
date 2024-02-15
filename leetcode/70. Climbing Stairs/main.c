#include <stdio.h>
#include <stdlib.h>

/*
int climbStairs(int n){

    if(n<=2){
        return n;
    }

    return climbStairs(n-1) + climbStairs(n-2);
}
*/

int climbStairs(int n);

int climbStairs(int n)
{

    int p=0, q=0,r=1;

    for(int i=1; i<=n; ++i)
    {
        p = q;
        q = r;
        r = p + q;
    }
    return r;
}

int main()
{
    int inputN = 0;

    puts("Please type the input N:");
    scanf("%d", &(inputN));

    printf("The output is: %d", climbStairs(inputN));
    printf("\n");

    return 0;
}
