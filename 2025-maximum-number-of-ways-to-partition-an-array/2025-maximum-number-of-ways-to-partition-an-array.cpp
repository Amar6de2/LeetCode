class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        long long int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){sum+=nums[i];}
        vector<long long int> diff(n);
        diff[0]=-1*sum;
        for(int i=1;i<n;i++)
        {
            diff[i]=diff[i-1]+2*nums[i-1];
        }
        map<long long int,int> left;
        map<long long int,int> right;
        for(int i=1;i<n;i++){right[diff[i]]++;}
        int ans=right[0];
        for(int j=0;j<n;j++)
        {
            if(j>0)
            {
                left[diff[j]]++;
                 if(right[diff[j]]>0){right[diff[j]]--;}
            }
            long long int dif=(long long int )k-nums[j];
            int count=0;
            count+=left[dif];
            count+=right[-dif];
            ans=max(ans,count);
        }
        return ans;
    }
};