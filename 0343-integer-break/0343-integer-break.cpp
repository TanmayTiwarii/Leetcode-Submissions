class Solution {
public:
    int func(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,i*(func(n-i,dp)));
        }
        return dp[n] = ans;
    }

    int integerBreak(int n) {
        int ans=0;
        vector<int> dp(n+1,-1);
        for(int i=1;i<n;i++){
            ans=max(ans,i*(func(n-i,dp)));
        }
        return ans;
    }
};