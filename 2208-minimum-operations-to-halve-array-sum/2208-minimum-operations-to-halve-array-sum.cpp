class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0,tempsum=0,ans=0;
        for(auto it:nums){
            pq.push(it);
            sum+=it;
            tempsum+=it;
        }
        while(2*tempsum>sum){
            double x = pq.top();
            pq.pop();
            tempsum-=x/2.0;
            x=x/2.0;
            pq.push(x);
            ans++;
        }
        return ans;
    }
};