class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,c=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                l++;
            }
            else if(moves[i]=='R'){
                r++;
            }
            else{
                c++;
            }
        }
        return max(l,r)-min(l,r)+c;
    }
};