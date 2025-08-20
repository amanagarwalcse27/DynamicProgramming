//ek item ko kitni bhi baar le skte h 
//age ek baar nhi liya toh nhi lenge kbhi 
//agr le liya toh kitni baar le skte h 
/*recursive code
int solve(int n,vector<int>& val, vector<int>& wt, int W)
     {
         if(n == 0 || W == 0) return 0;
         
         int notpick = solve(n-1,val,wt,W);
         
         int pick = INT_MIN;
         //if(pick)
         if(W - wt[n-1] >= 0)
         {
             pick =val[n-1] + solve(n,val,wt,W - wt[n-1]);
         }
         
         return max(pick ,notpick);
     }
   
    int knapSack(vector<int>& val, vector<int>& wt, int W) 
    {
        int n = val.size();
        
       return solve(n,val,wt,W);
        recursive code */
    
        int solve(int n,vector<int>& val, vector<int>& wt, int W,vector<vector<int>> &dp)
      {
         if(n == 0 || W == 0) return 0;
         
         if(dp[n][W] != -1) return dp[n][W];
         
         int notpick = solve(n-1,val,wt,W,dp);
         
         int pick = INT_MIN;
         //if(pick)
         if(W - wt[n-1] >= 0)
         {
             pick =val[n-1] + solve(n,val,wt,W - wt[n-1],dp);
         }
         
         return dp[n][W] =  max(pick ,notpick);
      }
      
        int knapSack(vector<int>& val, vector<int>& wt, int W) 
     {
        int n = val.size();
        
        vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
        
       return solve(n,val,wt,W,dp);
     }

