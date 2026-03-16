class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [distance,u] = pq.top();
            pq.pop();
            for(auto [v,weight]:adj[u]){
                if(dist[u]+weight<dist[v]){
                    dist[v]=dist[u]+weight;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};