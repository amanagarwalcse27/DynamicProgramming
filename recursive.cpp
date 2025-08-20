#include<bits/stdc++.h>
using namespace std;

    int solve(int W, vector<int> &val, vector<int> &wt, int n)
  {
    // Base Case: No more items or no capacity
       if (n == 0 || W == 0)
       return 0;

       
       int notpick = solve(W,val,wt,n-1);

       int pick = INT_MIN;
    // If current item can be picked
        if (W - wt[n-1] >= 0)
       {
         pick = val[n - 1] + solve(W - wt[n - 1], val, wt, n - 1);
       }
       
       return max(pick, notpick);
  }

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size(); // or wt.size(), both must be equal

    return solve(W, val, wt, n);
}