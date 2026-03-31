class Solution {
public:
    int func(vector<int>& nums,int i, int k, int op1, int op2,vector<vector<vector<int>>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][op1][op2]!=-1){
            return dp[i][op1][op2];
        }
        int ans = nums[i]+func(nums,i+1,k,op1,op2,dp);
        if(op1>0){
            ans = min(ans,(nums[i]+1)/2 + func(nums,i+1,k,op1-1,op2,dp));
        }
        if(op2>0 && nums[i]>=k){
            ans = min(ans,nums[i]-k + func(nums,i+1,k,op1,op2-1,dp));
        }
        if(op1>0 && op2>0){
            if(nums[i]>=k){
                ans = min(ans,(nums[i]-k+1)/2 + func(nums,i+1,k,op1-1,op2-1,dp));
            }
            if((nums[i]+1)/2>=k){
                ans = min(ans,(nums[i]+1)/2-k + func(nums,i+1,k,op1-1,op2-1,dp));
            }
        }
        return dp[i][op1][op2]=ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return func(nums,0,k,op1,op2,dp);
    }
};