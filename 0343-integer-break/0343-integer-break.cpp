class Solution {
public:
    int integerBreak(int n) {
        int ans=0;
        vector<int> dp(n+1,1);
        for(int len = 1;len<=n;len++){
            for(int i=1;i<=len;i++){
                if(len==n && i==n){
                    continue;
                }
                dp[len] = max(dp[len], i*dp[len-i]);
            }
        }
        return dp[n];
    }
};