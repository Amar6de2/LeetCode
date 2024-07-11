class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        map<pair<int,int>,int> m;//{node,current bit ki haalat}-> vis or not
        queue<pair<int,int>> q;
        int n=graph.size();
        for(int i=0;i<n;i++){q.push({i,(1<<i)});}
        int allnodevis=pow(2,n)-1;
        int step=0;
        while(!q.empty())
        {
          int s=q.size();
          
          while(s--)
          {
            int node=q.front().first;
            int bit=q.front().second;q.pop();
            if(bit==allnodevis){return step;}
            for(auto adjnode:graph[node])
            {
                int newbit=bit | (1<<adjnode);
                if(m.find({adjnode,newbit})==m.end())
                {q.push({adjnode,newbit});
                 m[{adjnode,newbit}]=1;}
            }
          }
          step++;
        }
        return 0;

        
    }
};