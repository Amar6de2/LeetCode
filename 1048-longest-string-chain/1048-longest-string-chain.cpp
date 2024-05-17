class Solution {
public:
    bool solve(string str1,string str2)
    {
        int n=str1.size();
        int m=str2.size();
        int i=0;//of str1
        int j=0;
        while(i<n)
        {
            if(str1[i]==str2[j]){j++;}
            i++;
        }
        return (i==n) && (j==m);
    }
    int longestStrChain(vector<string>& words) {
        map<int,vector<int>> m;//length->index
        vector<string> w;int maxi=0;
        for(int i=0;i<words.size();i++)
        {   
            int len=words[i].size();
            maxi=max(maxi,len);
            m[len].push_back(i);
        }
        for(int i=0;i<=maxi;i++)
        {
            for(auto it2:m[i])
            {
                w.push_back(words[it2]);
            }
        }
        vector<int> dp(words.size(),1);int maxlen=1;
        for(int i=1;i<words.size();i++)
        {
          for(int j=0;j<i;j++)
          {
            if((w[i].size()-1==w[j].size()) && solve(w[i],w[j]) && 1+dp[j]>dp[i] )
            {
              dp[i]=1+dp[j];
              maxlen=max(maxlen,dp[i]);
            }
          }
        }
        return maxlen;
        
    }
};