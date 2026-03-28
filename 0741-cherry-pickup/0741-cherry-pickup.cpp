class Solution {
public:
    int func(vector<vector<int>>& grid,int r1,int c1,int r2,int c2,vector<vector<vector<vector<int>>>> &dp){
        int n = grid.size();
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(dp[r1][c1][r2][c2]!=-1){
            return dp[r1][c1][r2][c2];
        }
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        int ans = 0;
        ans+=grid[r1][c1];
        if(r1!=r2){
            ans+=grid[r2][c2];
        }
        int a = func(grid,r1+1,c1,r2+1,c2,dp);
        int b = func(grid,r1+1,c1,r2,c2+1,dp);
        int c = func(grid,r1,c1+1,r2+1,c2,dp);
        int d = func(grid,r1,c1+1,r2,c2+1,dp);
        return  dp[r1][c1][r2][c2] =  ans + max({a, b, c, d});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<vector<int>>>> dp(
            n,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    n,
                    vector<int>(n, -1)
                )
            )
        );
        return max(func(grid,0,0,0,0,dp),0);
    }
};