class Disjointset{public: vector<int> par;
                          vector<int> size;
      Disjointset(int n)
      {
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
      }
     int findpar(int node)
     {
        if(node==par[node]){return node;}
        return par[node]=findpar(par[node]);
     }                    
     void unionbysize(int u,int v)
     {
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u==ulp_v){return;}
        if(size[ulp_u]>size[ulp_v])
        {
          par[ulp_v]=ulp_u;
          size[ulp_u]+=size[ulp_v];
        }
        else
        {
          par[ulp_u]=ulp_v;
          size[ulp_v]+=size[ulp_u];
        }
     }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans=vals.size();
        int n=vals.size();
        Disjointset dj(n);
        map<int,vector<int>> m;
        for(int i=0;i<vals.size();i++)
        {
            m[vals[i]].push_back(i);
        }
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> is_active(n,0);
        for(auto it: m)
        {
            vector<int> nodes=it.second;
            for(auto node: nodes)
            {
              for(auto adjnode:adj[node])
              {
                if(is_active[adjnode])
                {
                    dj.unionbysize(node,adjnode);
                }}
                is_active[node]=1;
            }
            vector<int> par_of_nodes;
            for(auto node: nodes)
            {par_of_nodes.push_back(dj.findpar(node));}
            sort(par_of_nodes.begin(),par_of_nodes.end());
            for(int j=0;j<par_of_nodes.size();j++)
            {
                long long count=0;
                int curr_par=par_of_nodes[j];
                while(j<par_of_nodes.size() && curr_par==par_of_nodes[j]){j++;count++;}
                j--;
                int form=((count*(count-1))/2);
                ans+=form;
            }
        }
        return ans;
       
}};