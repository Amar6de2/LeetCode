class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            prefix[i]=sum;
        }
        sum=0;
        vector<int> dp1(n);//will give max subarray sum from 0 to i
        vector<int> starting(n);//will give the starting indexes of the subarray with max sum from 0 to i.
        for(int i=0;i<n;i++)
        {if(i<k)
            {
                sum+=nums[i];
                dp1[i]=sum;
                starting[i]=0;
            }
            else
            {
                sum=sum+nums[i]-nums[i-k];
                if(sum>dp1[i-1])
                {
                    dp1[i]=sum;
                    starting[i]=i-k+1;
                }
                else
                {
                    dp1[i]=dp1[i-1];
                    starting[i]=starting[i-1];}}}
        sum=0;
        vector<int> dp2(n);//returns max subarray sum from i to n-1
        vector<int> ending(n);// ending[i] -> gives me the index from which max subarray starts from 
        for(int i=n-1;i>=0;i--)
        {
            if(i+k>n-1)
            {   sum+=nums[i];
                dp2[i]=sum;
                ending[i]=i;
            }
            else
            {
                sum=sum+nums[i]-nums[i+k];
                if(sum>=dp2[i+1])
                {
                    dp2[i]=sum;
                    ending[i]=i;
                }
                else
                {
                    dp2[i]=dp2[i+1];
                    ending[i]=ending[i+1];
                }
            }
        }
        //middle element can start from : k to n-2k as after n-2k we will be having exactly 2k-1 elements
        int a=-1e9;
        int s1,s2,s3;
        for(int midstart=k;midstart<=n-2*k;midstart++)
        {
           int midend=midstart+k-1;
           int midsum=prefix[midend]-prefix[midstart]+nums[midstart];
           int b=midsum+dp1[midstart-1]+dp2[midend+1];
           if(b>a)
           {
            a=b;
            s1=starting[midstart-1];
            s2=midstart;
            s3=ending[midend+1];
           }
        }
        vector<int> ans;
        ans.push_back(s1);
        ans.push_back(s2);
        ans.push_back(s3);
        return ans;
        
        
    }
};