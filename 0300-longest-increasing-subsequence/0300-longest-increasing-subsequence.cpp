class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(ans.empty()){
                ans.push_back(nums[i]);
                continue;
            }
            int x = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            if(x<ans.size()){
                ans[x]=nums[i];
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans.size();
    }
};