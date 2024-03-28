class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        int V=n;
        vector<pair<int,int>> adj[V];
        for(int i=0;i<flights.size();i++)
        {
            
                int u=flights[i][0];
                int v=flights[i][1];
                int wt=flights[i][2];
                adj[u].push_back({v,wt});
            
        }        
          
        
        vector<int> dist(V,1e9);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            int stop=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            if(stop>k){continue;}//stop of k must include the dest but we cannot allow it to go beyond k
            for(auto j:adj[node])
            {
                int adjnode=j.first;
                int wt=j.second;
                if(dis+wt<dist[adjnode])
                {dist[adjnode]=dis+wt;
                 q.push({stop+1,{adjnode,dist[adjnode]}});}

            }
        }
        if(dist[dst]==1e9){return -1;}
        return dist[dst];
        
    }
};