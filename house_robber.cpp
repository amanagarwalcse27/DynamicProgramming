#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101;
vector<int> dp(MAX_N, -1);
/* recursive code
int solve(vector<int> &nums,int n)
   {
    /*
      if(n == 0) return 0;   //if size is 0 no elemnt in array
      if(n == 1) return nums[n-1];  //if size is 1 means 1 elemnt in array
      if(n == 2) return max(nums[n-1],nums[n-2]);

      //agr i liya h toh i+2 me jayenge
      int pick = nums[n-1] + solve(nums,n-2);  //index of house is n-1 
      
      //agr i nhi liya h toh i+1 pr jayenge
      int notpick = solve(nums,n-1);

      return max(pick,notpick); 
   }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
      
      return  solve(nums,n);
      */

int solve(vector<int>& nums, int n) 
{
    if (n == 0) return nums[0];
    if (n == 1) return max(nums[0], nums[1]);
    if (dp[n] != -1) return dp[n];

    int pick = nums[n] + solve(nums, n - 2);
    
    int notpick = solve(nums, n - 1);

    return dp[n] = max(pick, notpick);
}

int rob(vector<int>& nums) 
{
    fill(dp.begin(), dp.end(), -1);  // 🧼 Reset before solving either do this or declare the dp vector here only
    int n = nums.size();

    return solve(nums, n - 1);  //calling with index here as passing n-1
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n; 
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) cin >> nums[i];
        cout << rob(nums) << endl;
    }
    return 0;
}
