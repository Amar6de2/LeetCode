class Solution {
public:
    bool f(int i,int j,string &s,string &p,vector<vector<int>> &dp)
    {   if(i<0 && j<0){return true;}
        if(i<0)//means p is remaining 
        {
          for(;j>=0;j=j-2)//why j=j-2? har alternate position min * hona chahiye!
          {
            if(p[j]!='*'){return false;}
          }
          return true;
         }
         if(j<0)
         {return false;}
        if(dp[i][j]!=-1){return dp[i][j];}
        if(s[i]!=p[j])
        {
         if(p[j]=='.')//means it will match with one character of s
         {
           return dp[i][j]=f(i-1,j-1,s,p,dp);
         }
         else if(p[j]=='*')//agar star hai toh ooske peeche ka elemnt ya th 0 times ya 1 times aayega
         {
          if(p[j-1]!=s[i] && p[j-1]!='.')//means zero times le lenge but if there is dot then we need to go the else part as . is itself a special character which can equalise one character of s
          {
            return dp[i][j]=f(i,j-2,s,p,dp);
          }
          else 
          {
            return dp[i][j]=f(i-1,j,s,p,dp) | f(i,j-2,s,p,dp);
          }
         }
         else
         {
            return dp[i][j]=false;
         }
        }
        else
        {
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return f(s.size()-1,p.size()-1,s,p,dp);
    }
};