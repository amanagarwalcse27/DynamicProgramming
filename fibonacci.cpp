#include <iostream>
using namespace std;

/*
int fib(int n) 
{
    if(n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}*/
int fib(int n, vector<int>& dp) 
{
    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}
int main() 
{
    int n = 10;
    vector<int> dp(n+1, -1);
    cout << "Fibonacci of " << n << " is " << fib(n, dp);
    return 0;
}