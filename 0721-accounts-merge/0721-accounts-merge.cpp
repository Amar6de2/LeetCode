class disjoint{
    public:
    vector<int> size,par;
    disjoint(int n)
    {size.resize(n);//0 based indexing
     par.resize(n);
     for(int i=0;i<n;i++)
     {size[i]=1;
      par[i]=i;}}
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
        if(size[ulp_u]<size[ulp_v])
        {size[ulp_v]+=size[ulp_u];
          par[ulp_u]=ulp_v;}
          else{par[ulp_v]=ulp_u;
               size[ulp_u]+=size[ulp_v];}}
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjoint dj(n);//n nodes have been formed representing names from 0 to n-1 in accounts vector
        unordered_map<string,int> Mailtonum;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)//j starts from 1 as we are ignoring the name right now
            {
                string mail=accounts[i][j];
                if(Mailtonum.find(mail)==Mailtonum.end())//not present
                {
                    Mailtonum[mail]=i;
                }
                else{//same email pe join kar diya and join nahi kiya
                      dj.unionbysize(i,Mailtonum[mail]);
                    } }}
                    vector<vector<string>> mails(n);
                    for(auto j:Mailtonum)
                    {
                        int node=dj.findpar(j.second);
                        string mail=j.first;
                        mails[node].push_back(mail);
                    }
                    vector<vector<string>> ans(n);int c=0;
                    for(int i=0;i<n;i++)
                    {
                        string name=accounts[i][0];
                        if(mails[i].size()==0){continue;}
                        sort(mails[i].begin(),mails[i].end());
                        ans[c].push_back(name);
                        for(auto h:mails[i])
                        {ans[c].push_back(h);}
                       c++;}
                       for(int i=0;i<n;i++){if(ans[i].size()==0){ans.pop_back();}}
                 
                    return ans;


        

    }
};