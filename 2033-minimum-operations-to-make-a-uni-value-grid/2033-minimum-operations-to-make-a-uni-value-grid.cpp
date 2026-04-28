class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if(grid.size()==1 && grid[0].size()==1){
            return 0;
        }
        int rem = grid[0][0]%x;
        vector<int> v;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                v.push_back(grid[i][j]);
                if(grid[i][j]%x!=rem){
                    return -1;
                }
            }
        }
        sort(v.begin(),v.end());
        int x1 = v[(grid.size()*grid[0].size())/2-1], x2 = v[(grid.size()*grid[0].size())/2];
        int c1=0,c2=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                c1+=abs(x1-grid[i][j])/x;
                c2+=abs(x2-grid[i][j])/x;
            }
        }
        return min(c1,c2); 
    }
};