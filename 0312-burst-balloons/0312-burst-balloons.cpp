class Solution {
public:

    int func(vector<int>& a, int l, int r,vector<vector<int>> &dp){
        if(l>r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans = 0;
        for(int i=l;i<=r;i++){
            if(i==l){
                ans = max(ans,a[l-1]*a[i]*a[r+1]+func(a,l+1,r,dp));
            }
            else if(i==r){
                ans = max(ans,a[l-1]*a[i]*a[r+1]+func(a,l,r-1,dp));
            }
            else {
                ans = max(ans,a[l-1]*a[i]*a[r+1] + func(a,l,i-1,dp)+func(a,i+1,r,dp));
            }
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> a;
        a.push_back(1);
        vector<vector<int>> dp(nums.size()+5,vector<int>(nums.size()+5,-1));
        for(auto it: nums){
            a.push_back(it);
        }
        a.push_back(1);
        return func(a,1,nums.size(),dp);
    }
};