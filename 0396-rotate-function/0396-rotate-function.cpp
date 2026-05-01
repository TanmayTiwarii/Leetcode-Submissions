class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            dp[0]+=nums[i]*i;
            sum+=nums[i];
        }
        int m=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = dp[i-1] + sum - nums[nums.size()-i]*nums.size();
            m=max(m,dp[i]);
        }
        return m;
    }
};