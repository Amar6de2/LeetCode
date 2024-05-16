class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){return 0;}
        int n=routes.size();
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> adj;//will have a list of nodes and each row shows the routes 
        for(int i=0;i<n;i++)
        {
            for(auto it: routes[i])
            {
                adj[it].push_back(i);
            }
        }
        queue<int> q;//will contain bus routes available
        for(auto it:adj[source]){q.push(it);}
        int bus=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int route=q.front();q.pop();
                for(auto stops:routes[route])
                {
                    if(stops==target){return bus;}
                    for(auto r:adj[stops])
                    {
                        if(!vis[r]){vis[r]=1;q.push(r);}
                    }
                }
            }
            bus++;
        }
        return -1;


        
    }
};