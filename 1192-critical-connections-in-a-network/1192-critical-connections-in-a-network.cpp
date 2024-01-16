class Solution {
public:int pntr=0;
    void dfs(int node,int parent,vector<int> &dist,vector<int> &minn,vector<int> adj[],         vector<vector<int>> &ans,int vis[])
    {
        vis[node]=1;
        dist[node]=minn[node]=pntr++;
        for(auto neigh:adj[node])
        { if(neigh==parent){continue;}
            if(vis[neigh]==0){
                dfs(neigh,node,dist,minn,adj,ans,vis);
                minn[node]=min(minn[node],minn[neigh]);
                if(minn[neigh]>dist[node]){vector<int> v;v.push_back(neigh);v.push_back(node);ans.push_back(v);}
            }
            else{
                minn[node]=min(minn[node],minn[neigh]);
            }
        }

    }
       
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        //make an adj list first
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int vis[n];
        for(int i=0;i<n;i++){vis[i]=0;}

        vector<int> dist(n);
        vector<int> minn(n);
        vector<vector<int>> ans;
        dfs(0,-1,dist,minn,adj,ans,vis);
        return ans;

       
        
    }
};