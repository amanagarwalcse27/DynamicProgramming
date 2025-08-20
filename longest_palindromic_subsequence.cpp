#include<bits/stdc++.h>
using namespace std;

/*
int solve(string &s1, string &s2,int n,int m)
  {
      if(n == 0 || m == 0) return 0;
      
      if(s1[n-1] == s2[m-1])
      {
          return 1 + solve(s1,s2,n-1,m-1);
      }
      
      else 
      {
          return max(solve(s1,s2,n-1,m) , solve(s1,s2,n,m-1));
      }
  }
  
    int lcs(string &s1, string &s2) 
    {
        int n = s1.size();
        int m = s2.size();
        
       return  solve(s1,s2,n,m);
       */
       
       /*
       int solve(string &s1, string &s2,int n,int m,vector<vector<int>> &dp)
   {
      if(n == 0 || m == 0) return 0;
      
      if(dp[n][m] != -1) return dp[n][m];
      
      if(s1[n-1] == s2[m-1])
      {
          return  dp[n][m] = 1 + solve(s1,s2,n-1,m-1,dp);
      }
      
          return dp[n][m] =  max(solve(s1,s2,n-1,m,dp) , solve(s1,s2,n,m-1,dp));
      
   }
  
    int lcs(string &s1, string &s2) 
    {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
       return  solve(s1,s2,n,m,dp);
       */
    
//bottom up code for lcs
    int longestCommonSubsequence(string &s1, string &s2) 
    {
        int n = s1.size();
        int m = s2.size();
        
       vector<vector<int>> dp(n+1,vector<int> (m+1,-1)); 
       
       //intialization of table using base case of recursion
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
               if(s1[i - 1] == s2[j-1])   //agr equal h toh 
               {
                   dp[i][j] = 1 + dp[i-1][j-1];
               }
               else   //agr equal nhi h toh
               {
                   dp[i][j] = max(dp[i-1][j],dp[i][j-1]); //max left ya top me se
               }
           }
       }   
       return dp[n][m];  //last column is answer
     }
     
    int longestPalindromeSubseq(string s) 
    {
        //longest palindromic subsequence ke liye ek string toh given string hogi 
        //and other string reverse hogi given string ka now apply LCS on these two strings
        string s1 = s;

        reverse(s.begin(),s.end());
        string s2 = s;

        return longestCommonSubsequence(s1,s2);
        
    }

    int main()
    {
        string s;
        cin>>s;


    }