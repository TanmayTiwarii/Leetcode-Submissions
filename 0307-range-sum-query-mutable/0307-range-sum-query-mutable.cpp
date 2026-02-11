class NumArray {
public:
    int seg[3*(int)1e5];
    int n;
    NumArray(vector<int>& nums) {
        build(0,0,nums.size()-1,nums);
        n=nums.size();
        for(int i=0;i<2*n;i++){
            cout<<seg[i]<<" ";
        }
        cout<<endl;
    }
    int build(int root,int low,int high,vector<int> &nums){
        if(low==high){
           return seg[root]=nums[low];
        }
        int mid = (low+high)/2;
        seg[2*root+1] = build(2*root+1,low,mid,nums);
        seg[2*root+2] = build(2*root+2,mid+1,high,nums);
        seg[root] = seg[2*root+2] + seg[2*root+1];
        return seg[root];
    }
    int change(int index,int val, int root, int low, int high){
        if(low==high && index==low){
            seg[root]=val;
            return seg[root];
        }
        if(index>high || index<low){
            return seg[root];
        }
        int mid=(low+high)/2;
        seg[root*2+1] = change(index,val,root*2+1,low,mid);
        seg[root*2+2] = change(index,val,root*2+2,mid+1,high);
        seg[root] = seg[root*2+2] + seg[root*2+1];
        return seg[root];
    }
    void update(int index, int val) {
        change(index,val,0,0,n-1);
    }
    int sum(int root,int left,int right, int low,int high){
        if(low>right || left>high){
            return 0;
        }
        if(low>=left && high<=right){
            return seg[root];
        }
        else{
            int mid=(low+high)/2;
            return sum(root*2+1,left,right,low,mid)+sum(root*2+2,left,right,mid+1,high);
        }

    }
    int sumRange(int left, int right) {
        return sum(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */