class Solution {
public:
    int f(int i,int j,vector<int> cuts,vector<vector<int>> dp)
    {   if(j<i){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int mini=1e9;
        for(int ind=i;ind<=j;ind++)
        {
           int step=cuts[j+1]-cuts[i-1];
           step+=f(i,ind-1,cuts,dp)+f(ind+1,j,cuts,dp);
           mini=min(mini,step);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int s=cuts.size();
        vector<vector<int>> dp(s,vector<int>(s,0));
        //base cases:already defined
        for(int i=s-2;i>=1;i--)
        {
            for(int j=i;j<s-1;j++)
            {
              int mini=1e8;
              for(int ind=i;ind<=j;ind++)
              {
                int c=cuts[j+1]-cuts[i-1];
                c+=dp[i][ind-1]+dp[ind+1][j];
                mini=min(mini,c);
              }
              dp[i][j]=mini;
            }
        }
        return dp[1][s-2];
    }
};