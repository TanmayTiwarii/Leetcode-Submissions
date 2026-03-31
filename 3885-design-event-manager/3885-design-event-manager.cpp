class EventManager {
public:
    struct cmp {
        bool operator()(pair<int,int> &a, pair<int,int> &b) {
            if (a.first == b.first) {
                return a.second > b.second;  // ascending second
            }
            return a.first < b.first;        // descending first
        }
    };
    map<int,int> latest;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    EventManager(vector<vector<int>>& events) {
        for(auto it:events){
            pq.push({it[1],it[0]});
            latest[it[0]]=it[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        pq.push({newPriority,eventId});
        latest[eventId]=newPriority;
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [p,e] = pq.top();
            if(latest[e]!=p){
                pq.pop();
            }
            else{
                break;
            }
        }
        if(pq.empty()){
            return -1;
        }
        auto [p,e] = pq.top();
        latest[e]=-1;
        pq.pop();
        return e;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */