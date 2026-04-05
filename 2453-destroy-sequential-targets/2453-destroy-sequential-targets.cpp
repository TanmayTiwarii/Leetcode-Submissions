class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> count;
        for(auto it:nums){
            count[it%space]++;

        }
        int ans=INT_MAX,temp=0;
        for(auto it:nums){
            if(count[it%space]>=temp){
                if(count[it%space]==temp)
                ans=min(ans,it);
                else
                ans=it;
                temp=count[it%space];
            }
        }
        return ans;
        
    }
};