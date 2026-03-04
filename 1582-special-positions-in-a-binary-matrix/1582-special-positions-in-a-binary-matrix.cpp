class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size(),0) , column(mat[0].size(),0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                row[i]+=mat[i][j];
                column[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(row[i]==1 && column[j]==1 && mat[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};