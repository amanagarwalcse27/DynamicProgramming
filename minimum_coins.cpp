#include<bits/stdc++.h>
using namespace std;

/*
    int solve(vector<int> &coins,int n,int amount)
    {
        if(n == 0)   //yha tk kbhi pahuchenga hi nhi code 
        {
          if(amount == 0) return 1;
          return 0;
        }

        if(n == 1)
        {
            if(amount % coins[0] == 0) return amount/coins[0];   //agr bnana possible h toh

            else return 1e9;  //agr locically bnana possible nhi h kisi bhi combination se toh larger number return krdo like 1e9
         
        }

        int notpick = solve(coins,n-1,amount);
        
        int pick = 1e9;
        if(amount - coins[n-1] >= 0)
        {
           pick = 1 + solve(coins,n,amount - coins[n-1]);
        }

        return min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();

        int ans = solve(coins,n,amount);

        if(ans < 1e9) return ans;

        else return -1;
        */

        int solve(vector<int> &coins,int n,int amount,vector<vector<int>> &dp)
    {
        /*
        if(n == 0)   //yha tk kbhi pahuchenga hi nhi code 
        {
          if(amount == 0) return 1;
          return 0;
        } */

        if(n == 1)
        {
            if(amount % coins[0] == 0) return amount/coins[0];   //agr bnana possible h toh

            else return 1e9;  //agr locically bnana possible nhi h kisi bhi combination se toh very large number return krdo like 1e9
         
        }
        
        if(dp[n-1][amount] != -1) return dp[n-1][amount];

        int notpick = solve(coins,n-1,amount,dp);
        
        int pick = 1e9;
        if(amount - coins[n-1] >= 0)
        {
           pick = 1 + solve(coins,n,amount - coins[n-1],dp);
        }

        return dp[n-1][amount] =  min(pick,notpick);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int> (amount + 1,-1));

        int ans = solve(coins,n,amount,dp);

         if(ans < 1e9) return ans;

        else return -1;
   
    }
};