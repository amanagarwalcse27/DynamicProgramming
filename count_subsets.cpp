//total subsets btane h sum k ke
    int solve(vector<int> &nums,int i,int target,vector<vector<int>> &dp)
  {
    if( target == 0) return 1;
    if(i < 0)  return 0;

    if(dp[i][target] != -1) return dp[i][target];

    //not picked 
    int notpick = solve(nums,i-1,target,dp);
    
    int pick = 0;  //declare for safe
    //not picked
    if(target - nums[i] >= 0)
    {
     pick = solve(nums,i-1,target - nums[i],dp);
    }

    return dp[i][target] = pick + notpick;
}

int subset(vector<int> &nums,int target)
{
    int n = nums.size();

    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    return solve(nums,n-1,target,dp);  //passing n-1 so size becomes index 
}