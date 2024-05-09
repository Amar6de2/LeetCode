class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<long long int> count(n,1);
        int maxlenindex=0;
        int maxlen=1;
        for(int ind=1;ind<n;ind++)
        {
            for(int i=0;i<ind;i++)
            {
              if(nums[ind]>nums[i] && 1+dp[i]>dp[ind])
              {
                dp[ind]=1+dp[i];
                count[ind]=count[i];
              }
              else if(nums[ind]>nums[i] && 1+dp[i]==dp[ind])
              {
                count[ind]=count[ind]+count[i];
              }
              if (dp[ind]>maxlen)
              {
                maxlen=dp[ind];
                maxlenindex=ind;
              }
            }
        }
        return maxlen;
        
    }
};