//longest common subsequence nikalna h dono string me se
#include<bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2,int n,int m)
  {  
    //base case 
      if(n == 0 || m == 0) return 0;
      
      if(s1[n-1] == s2[m-1]) // if last elelmnt of both are equal reduce the string size by 1 in both 
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
        
    }

    int main()
    {
        string s1,s2;
        cin>>s1>>s2;

        cout<<lcs(s1,s2)<<endl;
    }