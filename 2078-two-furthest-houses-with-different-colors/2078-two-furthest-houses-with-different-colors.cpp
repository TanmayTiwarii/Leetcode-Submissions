class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int l=0,r=colors.size()-1;
        int ans1=0,ans2=0;
        for(int i=1;i<colors.size();i++){
            if(colors[l]!=colors[i]){
                ans1=max(ans1,i-l);
            }
            if(colors[r]!=colors[i]){
                ans2=max(ans2,r-i);
            }
        }
        return max(ans1,ans2);
    }
};