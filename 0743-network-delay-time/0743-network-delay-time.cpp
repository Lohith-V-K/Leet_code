class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(const auto it:times)
        {
            adj[it[0]].push_back({it[1],it[2]});

        }
        const int INF=numeric_limits<int>::max()/4;
        vector<int>dist(n+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        dist[k]=0;
        minheap.push({0,k});
        while(!minheap.empty())
        {
            auto it=minheap.top();
            int node=it.second;
            int currtime=it.first;
            minheap.pop();
            if(currtime!=dist[node])
            continue;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int time=it.second;
                if(currtime+time<dist[adjnode])
                {
                    dist[adjnode]=currtime+time;
                    minheap.push({currtime+time,adjnode});
                }
            }
        }
        int ans=0;
        for(int node=1;node<=n;node++)
        {
            if(dist[node]==INF)
            return -1;
            ans=max(ans,dist[node]);
        }
        return ans;
    }
};