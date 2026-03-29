class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftmax=height[left],rightmax=height[right],ans=0;
        while(left<right){
            if(leftmax<rightmax){
                ans += leftmax - height[left];
                left++;
                leftmax = max(leftmax,height[left]);
            }
            else{
                ans += rightmax - height[right];
                right--;
                rightmax = max(rightmax,height[right]); 
            }
        } 
        return ans;
    }
};