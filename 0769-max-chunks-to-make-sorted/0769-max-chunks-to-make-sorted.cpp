class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m=-1,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>m){
                m=arr[i];
            }
            if(m==i){
                ans++;
            }
        }
        return ans;
    }
};