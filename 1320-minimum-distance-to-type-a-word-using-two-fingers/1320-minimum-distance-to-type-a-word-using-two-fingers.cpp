class Solution {
public:
    int dp[301][27][27];
    int func(string &word, int i, int l1, int l2,unordered_map<int,pair<int,int>> &m){
        if(i==word.size()){
            return 0;
        }
        if(dp[i][l1][l2]!=-1){
            return dp[i][l1][l2];
        }
        int x = m[word[i]-'A'].first;
        int y = m[word[i]-'A'].second;

        int x1 = m[l1].first;
        int y1 = m[l1].second;
        int x2 = m[l2].first;
        int y2 = m[l2].second;

        int ans=min(abs(x-x1)+abs(y-y1)+func(word,i+1,word[i]-'A',l2,m),abs(x-x2)+abs(y-y2)+func(word,i+1,l1,word[i]-'A',m));
        return dp[i][l1][l2]=ans;
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        unordered_map<int,pair<int,int>> m;
        int temp=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                m[temp++]={i,j};
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<word.size();i++){
            for(int j=i+1;j<word.size();j++){
                ans=min(ans,func(word,0,word[i]-'A',word[j]-'A',m));
            }
        }
        return ans;
    }
};