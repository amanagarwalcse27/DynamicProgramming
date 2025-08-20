#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 1;
vector<int> dp(MAX_N, -1);

int solve(int n, int k,vector<int>& h) 
{
    if (n == 0) return 0;

    if (dp[n] != -1) return dp[n];
    
    int cost = INT_MAX;
     for(int j = 1; j <= k;j++)
     {
         if(n - j >= 0)
         {
       cost = min(cost,solve(n - j,k,h) + abs(h[n] - h[n - j]));
         }
     }
     
     return dp[n] = cost;
}
int main() 
{
    int n,k;
    cin >>n>>k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) 
    {
        cin>>h[i];
    }        

    cout << solve(n - 1,k,h) << endl;

    return 0;
}