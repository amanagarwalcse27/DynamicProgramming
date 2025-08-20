//converting recursive code into iterative code 
//making table first then returning answer

#include<bits/stdc++.h>
using namespace std;

//recursive code ka base case bottom up me intialization bnata h

/* we can declare it globally also outside the class and for declaring inside class use static also
const int MAX_N = 1001;
const int MAX_W = 1001;
int dp[MAX_N][MAX_W];  // ✅ declare globally (or with fixed size inside function)

then intialize with two for loops 
*/


int knapsack(int W, vector<int> &val, vector<int> &wt) 
{
    int n = val.size();

    // dp[i][w] = max value for first i items with capacity w
    //1. the base case of recursive code is intialization in bottomup
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table
    for (int i = 1; i < n + 1; i++) 
    {
        for (int j = 1; j < W + 1; j++) 
        {
            //2. the loop body is the choice diagram code of recursive code
            if (wt[i - 1] <= j) 
            {
                // include the item or exclude it
                dp[i][j] = max(
                    val[i - 1] + dp[i - 1][j - wt[i - 1]],  // include
                    dp[i - 1][j]                            // exclude
                );
            } 
            else 
            {
                dp[i][j] = dp[i - 1][j];  // can't include, just exclude
            }
        }
    }

    return dp[n][W];  // final answer
}

