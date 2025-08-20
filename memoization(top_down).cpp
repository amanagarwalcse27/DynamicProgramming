#include<bits/stdc++.h>
using namespace std;

int solve(int W, vector<int> &val, vector<int> &wt, int n ,vector<vector<int>> &dp)
  {
    // Base Case: No more items or no capacity
       if (n == 0 || W == 0)
       return 0;

       
       if(dp[n][W] != -1) return dp[n][W];

       int notpick = solve(W,val,wt,n-1,dp);

       int pick = INT_MIN;

        if (W - wt[n-1] >= 0)  // If current item can be picked
       {
         pick = val[n - 1] + solve(W - wt[n - 1], val, wt, n - 1,dp);
       }
       
       return dp[n][W] =  max(pick, notpick);
  }

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size(); // or wt.size(), both must be equal

    vector<vector<int>> dp(n+1,vector<int> (W+1,-1));

    return solve(W, val, wt, n,dp);
}