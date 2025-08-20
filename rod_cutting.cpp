//pura code knapsack ka jaise bs agr weight array not given then make weight array first, all code as it is unbounded knapsack jaisa+
 
    int solve(int n, vector<int>& val, vector<int>& wt, int W, vector<vector<int>> &dp)
    {
        if(n == 0 || W == 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        int notpick = solve(n-1, val, wt, W, dp);
        
        int pick = INT_MIN;
        if(W - wt[n-1] >= 0)
        {
            pick = val[n-1] + solve(n, val, wt, W - wt[n-1], dp); // unbounded -> call with same n
        }
        
        return dp[n][W] = max(pick, notpick);
    }
    
    int cutRod(vector<int> &val) 
    {
        int n = val.size();
        
        vector<int> wt(n);
        
        for(int i = 0; i < n; i++)  //make wt array if not given then all code same as unbounded knapsack
        {
            wt[i] = i + 1;  // for rod cutting: piece length = index + 1
        }
      
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, val, wt, n, dp);
    }


        