class Solution {
public:
    bool checkfordone(vector<vector<int>> &grid,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {if(grid[i][j]==1){return false;}}
        }
        return true;
    }
    int bfs(vector<vector<int>>& grid,int n,int m)
    {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {if(grid[i][j]==2){q.push({i,j}); vis[i][j]=1;}}
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int time=0;
        while(!q.empty())
        {   bool l=true;int s=q.size();//this is an important step !!!! we need to fix the s value !
            for(int i=0;i<s;i++)
            {int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<=3;k++)
            {
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0)
                {grid[nr][nc]=2;
                 vis[nr][nc]=1;
                 l=false; q.push({nr,nc});}
            }}
        if(l==false){time=time+1;l=true;}
        if(checkfordone(grid,n,m)){return time;}


    }
    return -1;
    }
    bool isempty(vector<vector<int>> grid,int n,int m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0){return false;}
            }
    }
    return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();int m=grid[0].size();
        if(isempty(grid,n,m)){return 0;}
        else{
        int ans=bfs(grid,n,m);

        return ans;
        
    }}
};