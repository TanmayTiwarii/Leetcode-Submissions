class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> a;
        for(auto it: arr){
            a.push_back({__builtin_popcount(it),it});
        }
        sort(a.begin(),a.end());
        for(int i=0;i<arr.size();i++){
            arr[i]=a[i].second;
        }
        return arr;
    }
};