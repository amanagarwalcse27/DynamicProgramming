#include<bits/stdc++.h>
using namespace std;

//minimum deletions and insertions to convert one string into other jb LCS wala case ho

int minOperations(string &s1, string &s2) 
    {
        
        if(s1 == s2) return 0; //agr equal h toh no deletion and insertion required 
      
      //finding LCS
         int n = s1.size();
        int m = s2.size();
        
       vector<vector<int>> dp(n+1,vector<int> (m+1,-1)); 
       
       for(int i = 0; i < n+1;i++)
       {
           for(int j = 0 ; j < m+1;j++)
           {
               if(i == 0 || j == 0)
               {
                   dp[i][j] = 0;
               }
           }
       }
       
       for(int i = 1; i < n+1;i++)
       {
           for(int j = 1; j < m+1;j++)
           {
               if(s1[i - 1] == s2[j-1])
               {
                   dp[i][j] = 1 + dp[i-1][j-1];
               }
               else 
               {
                   dp[i][j] = max(dp[i-1][j],dp[i][j-1]); //max left ya top me se
               }
           }
       }
       
       return  n + m - 2*dp[n][m];    //total distinctin two strings mil jayenge isse jo ki insertion + deletion se bn skte
     }
        