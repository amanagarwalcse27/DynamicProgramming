#include<bits/stdc++.h>
using namespace std;
  /*
    int solve(vector<int> &arr,int n,int previndex,int index)
    {
        if( index == n) return 0;
        
        //nhi liya toh previndex whi rhega current ke liye currindex+1
        int notpick = solve(arr,n,previndex,index+1);
         
         int pick = 0;
         //pick condition
         if(previndex == -1 || arr[index] > arr[previndex])
         {
            pick = 1 + solve(arr,n,index,index + 1);
         }
         
         return max(pick,notpick);
    }
    int lis(vector<int>& arr) 
    {
         int n = arr.size();
         
         int previndex = -1;
         int index = 0;
         
       return  solve(arr,n,previndex,currindex);
       */ 
       
       int solve(vector<int> &arr,int n,int previndex,int index,vector<vector<int>> &dp)
    {
        if(index == n) return 0;
        
        if(dp[index][previndex + 1] != -1) return dp[index][previndex + 1];
        
        //nhi liya toh previndex whi rhega current ke liye currindex+1
        int notpick = solve(arr,n,previndex,index+1,dp);
         
         int pick = 0;
         //pick condition
         if(previndex == -1 || arr[index] > arr[previndex])
         {
            pick = 1 + solve(arr,n,index,index + 1,dp);
         }
         
         return  dp[index][previndex + 1] = max(pick,notpick);
    }
       
        int lis(vector<int>& arr) 
     {
         int n = arr.size();
         
         int previndex = -1;
         int index = 0;
         
         vector<vector<int>> dp(n,vector<int> (n+1,-1));  //dp columns ki size n+1 as previndex can take -1 to n-1 values 
         
       return  solve(arr,n,previndex,index,dp);  
    }