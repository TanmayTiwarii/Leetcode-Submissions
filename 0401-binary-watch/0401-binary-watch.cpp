class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                if(__builtin_popcount(i)+__builtin_popcount(j)==turnedOn){
                    string a,b;
                    a=to_string(i);
                    if(j==0){
                        b="00";
                    }
                    else if(j<=9){
                        b="0"+to_string(j);
                    }
                    else{
                        b=to_string(j);
                    }
                    ans.push_back(a+":"+b);
                }
            }
        }
        return ans;
    }
};