class Solution {
public:
    int func(int start,int end,vector<int> &cuts,vector<vector<int>> &dp,int left,int right){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int cost=INT_MAX;
        for(int i=left;i<=right;i++){
            int c1=func(start,cuts[i],cuts,dp,left,i-1);
            int c2=func(cuts[i],end,cuts,dp,i+1,right);
            cost=min(cost,(end-start)+c1+c2);
        }
        return dp[left][right]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>>dp(101,vector<int>(101,-1));
        sort(cuts.begin(),cuts.end());
        return func(0,n,cuts,dp,0,cuts.size()-1);
    }
};