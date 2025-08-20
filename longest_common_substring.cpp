#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) 
{
    int n = s1.size();
    int m = s2.size();

    // Step 1: DP table banaya jisme dp[i][j] longest common substring ka length rakhega
    // jo s1[i-1] aur s2[j-1] par end hoti hai
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int ans = 0; // Final answer store karne ke liye

    // Step 2: DP table fill karna start
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {

            // Step 2.1: Agar characters match karte hain
            if (s1[i - 1] == s2[j - 1]) 
            {
                // Toh 1 + pichli substring ki length add karo
                dp[i][j] = 1 + dp[i - 1][j - 1];

                // Step 3: Maximum length update karte jao
                ans = max(ans, dp[i][j]);
            } 
            // Step 2.2: Agar characters match nahi karte
            else 
            {
                // Toh substring break ho gayi, isliye 0 se dobara start karo
                dp[i][j] = 0;
            }
        }
    }

    // Step 4: Return the longest common substring length
    return ans;
}

