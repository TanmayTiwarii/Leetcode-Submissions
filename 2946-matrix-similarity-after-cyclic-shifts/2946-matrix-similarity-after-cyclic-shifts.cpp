class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                temp[i][j]=mat[i][(j+k)%mat[0].size()];
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]!=temp[i][j]){
                    return false;
                }
            }
            cout<<endl;
        }
        return true;
    }
};