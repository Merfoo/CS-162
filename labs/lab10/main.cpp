#include <iostream>
#include <sys/time.h>

using namespace std;

int fibonacciRec(int n)
{
    if(n <= 1)
        return n;

    return fibonacciRec(n - 1) + fibonacciRec(n - 2);
}

int fibonacciItr(int n)
{
    if(n <= 1)
        return n;

    int a = 0;
    int b = 1;

    for(int i = 0; i < n; i++)
    {
        int c = a + b;
        a = b;
        b = c;   
    }

    return a;
}

int factorialT(int n, int result = 1)
{
    if(n == 1)
        return result;

    return factorialT(n - 1, n * result);
}

int factorial(int n)
{
    if(n == 1)
        return 1;

    return n * factorial(n - 1);
}

double getSecs(struct timeval beg, struct timeval end)
{
    return (end.tv_usec - beg.tv_usec);
}

int main()
{
    struct timeval beg, end, diff;
    
    gettimeofday(&beg, NULL);
    cout << factorial(100000) << endl;
    gettimeofday(&end, NULL);
    cout << "Recursive: " << getSecs(beg, end) << endl;
    
//    cout << fibonacciItr(25) << endl;
//    cout << "Iterative Fibonacci: " << getSecs(t) << endl;

    return 0;
}
