class Solution {
public:
    int f(int i,vector<int> arr,int k,int n)
    {
        if(i==n){return 0;}
        int maxi=-1e9;int maxsum=-1e9;
        for(int ind=i;ind<min(n,i+k);ind++)
        {
           maxi=max(maxi,arr[ind]);
           int way=(ind-i+1)*maxi;
           way+=f(ind+1,arr,k,n);
           maxsum=max(maxsum,way);
        }
        return maxsum;
        }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        //return f(0,arr,k,n);
        vector<int> dp(n+1,0);
        dp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        { int maxi=-1e9;int maxsum=-1e9;
          for(int ind=i;ind<min(n,i+k);ind++)
          {
            maxi=max(maxi,arr[ind]);
            int way=(ind-i+1)*maxi;
            way+=dp[ind+1];
            maxsum=max(maxsum,way);
          }
          dp[i]=maxsum;
        }
        return dp[0];// we do not reduce arr[n-1] here. why?
                     //at ind th posn.. we add arr[ind] so at n-1 position...we will add arr[n-1] so if we decrease arr[n-1]...we will get wrong answer....therefore do not decrease it!
        
    }
};