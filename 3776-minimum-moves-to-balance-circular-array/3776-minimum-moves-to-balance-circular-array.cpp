class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum = 0;
        int neg = -1;
        for(int i=0;i<balance.size();i++){
            sum+=balance[i];
            if(balance[i]<0){
                neg=i;
            }
        }
        if(sum<0){
            return -1;
        }
        if(neg==-1){
            return 0;
        }
        long long a=1,ans=0;
        int left=neg,right=neg;
        while(balance[neg]<0){
            left=(left-1+balance.size())%balance.size();
            right=(right+1)%balance.size();
            int add = min(abs(balance[neg]),balance[left]+balance[right]);
            ans+=add*a;
            a++;
            balance[neg]+=add;
        }
        return ans;

    }
};