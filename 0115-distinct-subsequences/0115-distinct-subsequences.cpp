class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        return helper(0, 0, s, t, dp);
    }

    long long helper(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        long long ways = 0;
        if (s[i] == t[j])
            ways = helper(i + 1, j + 1, s, t, dp) + helper(i + 1, j, s, t, dp);
        else
            ways = helper(i + 1, j, s, t, dp);

        return dp[i][j] = ways;
    }
};
