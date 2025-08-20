#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;
vector<int> dp(MAX_N, -1);   //don't pass globally for leetcode gfg this can give wrong answers

int solve(int n, vector<int>& h) 
{
    if (n == 0) return 0;   //here n == 0 means if index is zero 

    if (dp[n] != -1) return dp[n];

    int cost1 = solve(n - 1, h) + abs(h[n] - h[n - 1]);   

    int cost2 = INT_MAX;
    
    if (n > 1)
        cost2 = solve(n - 2, h) + abs(h[n] - h[n - 2]);

    return dp[n] = min(cost1, cost2);
}

int main() 
{
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> h[i];
    }
    cout << solve(n - 1, h) << endl;  //calling with  n-1 will convert to index now last stone index is n and second last stone is n-1 and the
    //if we call with n only then it remains size only then last stone index is n-1 and second last stone index is n-2 aand first index is a[0]

    return 0;
}
  