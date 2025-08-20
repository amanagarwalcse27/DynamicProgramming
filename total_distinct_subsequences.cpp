#include<bits/stdc++.h>
using namespace std;

//count btana h total kitni subsequences occur hongi string2 ki string1 me
//brute force
//generate all substrings using backtracking of string1 and check that they are equal to string2 or not 
//TC = O(2^n) works for small inputs

//method2 using picking not picking in subsequence matching
/*  recursive code 
int solve(string s, string t,int n,int m)
{
    if(n < m) return 0;
    if(m == 0) return 1;
    if(n == 1 && m == 1)return s[0] == t[0];

    //notpick
    int notpick = solve(s,t,n-1,m);  //length km hmesha s ki hogi jisme hm dhund rhe h 

    int pick = 0;
    if(s[n-1] == t[m-1])
    {
        pick = solve(s,t,n-1,m-1);
    }

    return pick + notpick;
}
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        
        return solve(s,t,n,m);
    }
    */

    int solve(string s, string t,int n,int m,vector<vector<int>> &dp)
{
    if(n < m) return 0;
    if(m == 0) return 1;
    if(n == 1 && m == 1)return s[0] == t[0];

    if(dp[n][m] != -1) return dp[n][m];

    //notpick
    int notpick = solve(s,t,n-1,m,dp);  //length km hmesha s ki hogi jisme hm dhund rhe h 

    int pick = 0;
    if(s[n-1] == t[m-1])
    {
        pick = solve(s,t,n-1,m-1,dp);
    }

    return dp[n][m] =  pick + notpick;
}
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));  //0 possible h toh intialization -1 se kro
        
        return solve(s,t,n,m,dp);
    }
