class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     
       vector<vector<pair<int,int>>> adj(n + 1);
        for(auto time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [t, src] = pq.top();
            pq.pop();
            if (t > dist[src]) continue; // optimization

            for(auto [nbrNode, nbrTime] : adj[src]){
                if(dist[src] + nbrTime < dist[nbrNode]){
                    dist[nbrNode] = dist[src] + nbrTime;
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};