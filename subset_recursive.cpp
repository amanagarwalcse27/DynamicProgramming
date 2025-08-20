//hme btana h ki given sum exist krta h ya nhi

//recursive code
/*
bool solve(vector<int> &arr,int n,int i,int target,long long sum)
      {
          if(i == n)  //forward  moving code
          {
              if(sum == target) return 1;
              else return 0;
          }
          
          
          bool pick = solve(arr,n,i+1,target,sum + arr[i]);
          
          bool notpick = solve(arr,n,i+1,target,sum); 
          
          return pick || notpick;
      }

     bool isSubsetSum(vector<int>& arr, int target) 
     {
        int n = arr.size();
        int i = 0;
        long long  sum = 0;
        
        return solve(arr,n,i,target,sum);
     }
     */  
  //
     bool solve(vector<int> &nums,int i,int target,vector<vector<int>> &dp)
{
    if( target == 0) return 1;
    if(i < 0)  return false;

    if(dp[i][target] != -1) return dp[i][target];

    //not picked 
    int notpick = solve(nums,i-1,target,dp);
    
    int pick = 0;  //declare for safe
    //not picked
    if(target - nums[i] >= 0)
    {
     pick = solve(nums,i-1,target - nums[i],dp);
    }

    return dp[i][target] = pick || notpick;
}

bool subset(vector<int> &nums,int target)
{
    int n = nums.size();

    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    return solve(nums,n-1,target,dp);  //passing n-1 so size becomes index 
}