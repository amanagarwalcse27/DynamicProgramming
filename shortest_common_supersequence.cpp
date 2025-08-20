#include<bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        for(int i = 0; i < n+1;i++)
        {
            dp[i][0] = 0;
            
        }
        
        for(int j = 0; j < m+1;j++)
        {
            dp[0][j] = 0;
            
        }
        
        for(int i = 1; i < n+1;i++)
        {
            for(int j = 1; j < m+1;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else 
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
        
    }
    
    //shortest common supersequence tb aayega jb lCS ho.
    int shortestCommonSupersequence(string &s1, string &s2) 
    {
        int n1 = s1.size();
        int n2 = s2.size();
        
        return n1 + n2 - LCS(s1,s2);
    }