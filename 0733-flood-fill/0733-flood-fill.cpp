class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int og = image[sr][sc];
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        while(!q.empty()){
            auto [r,c] = q.front();
            image[r][c] = color;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && image[nr][nc]==og){
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};