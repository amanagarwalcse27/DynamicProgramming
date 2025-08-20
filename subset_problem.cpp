#include<bits/stdc++.h>
using namespace std;

// memoization code using knapsack code
// if only one array given then it is wt array of knapsack 
// then made some changes in knapsack code

const int MAX_N = 201;
const int SUM = 10001;
int dp[MAX_N][SUM];  //define outside the class for tabulation

    bool isSubsetSum(vector<int>& arr, int sum)
    {
        int n = arr.size();
        int i = 0, j = 0;
        
        //intialization of table
        for( i = 0 ; i < n+1;i++)  dp[i][0] = true;
        for(j = 0; j <m+1;j++)     dp[0][j] = false;
        
        //built table now by making changes in knapsack code
        //wt array replace by given array and W replace by sum 
        for(int i = 1; i < n+1;i++)
        {
            for(int j = 1 ; j < sum + 1;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j- arr[i-1]] || dp[i-1][j];
                }
                else 
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
        
    }
    