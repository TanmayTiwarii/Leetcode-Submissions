class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
        }
        long long rowsum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                rowsum+=grid[i][j];
            }
            if(rowsum*2==sum){
                return true;
            }
        }
        long long columnsum=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                columnsum+=grid[j][i];
            }
            if(columnsum*2==sum){
                return true;
            }
        }
        return false;
    }
};