class Solution {
public:
    int count(int rowmove,int colmove,int n,vector<vector<int>>& img1, vector<vector<int>>& img2)
    {   int overlap=0;//assuming img1 ke oopar img2 overlap karega
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
              if(i-rowmove>=0 && i-rowmove<n && j-colmove>=0 && j-colmove<n && (img1[i][j] & img2[i-rowmove][j-colmove]))
              {
                overlap++;
              }
            }
        }
        return overlap;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int  ans=0;
        for(int i=-n+1;i<=n-1;i++)
        {
            for(int j=-n+1;j<=n-1;j++)
            {
                ans=max(ans,count(i,j,n,img1,img2));
            }
        }
        return ans;
        
    }
};