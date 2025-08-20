//total ways btane h coin chenge ke
#include <bits/stdc++.h>
using namespace std;

/* recursive code
int solve(vector<int> &coins,int n,int amount)
   {
      if(n == 0)
      {
        if (amount == 0) return 1;
        return 0;
      }
      if(amount == 0) return 1;

      int notpick = solve(coins,n-1,amount);
      
      int pick = 0;
      if(amount - coins[n-1] >= 0)
      {
        pick = solve(coins,n,amount - coins[n-1]);
      }

      return pick + notpick;  //for total ways pick + notpick

   }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();

       return solve(coins,n,amount);  
    }
    */
        int solve(vector<int> &coins,int n,int sum,vector<vector<int>> &dp)
      {
        if(n == 0)
      {
        if (sum == 0) return 1;
        return 0;
      }
      if(sum == 0) return 1;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        int notpick = solve(coins,n-1,sum,dp);
        
        int pick = 0;
        
        if(sum - coins[n-1] >= 0)
        {
          pick = solve(coins,n,sum - coins[n-1],dp);
        }
        
        return dp[n][sum] = pick + notpick;
    }
    int change(int sum, vector<int>& coins)
    {
         //recursive code
        int n = coins.size();
        
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        
        return solve(coins,n,sum,dp);
    } 
