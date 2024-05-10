class Solution {
public:
    int f(int i,int j,vector<int> nums,vector<vector<int>> dp)
    {
        if(j<i){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        int maxi=-1e9;
        for(int ind=i;ind<=j;ind++)//ind is the index of the element such that the element is bursted at the very end!
        {
            int step=nums[i-1]*nums[ind]*nums[j+1];
            step+=f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
            maxi=max(maxi,step);
        }
        return dp[i][j]=maxi;   
    }
    int maxCoins(vector<int>& nums) {
       nums.push_back(1);
       nums.insert(nums.begin(),1);
       int n=nums.size();
       //base case: already defined
       vector<vector<int>> dp(n,vector<int>(n,0));
       for(int i=n-2;i>=1;i--)
       {
        for(int j=i;j<n-1;j++)//j can either be equal to i or greater than i!!
        {
            int maxi=-1e9;
            for(int ind=i;ind<=j;ind++)
            {
                int step=nums[i-1]*nums[ind]*nums[j+1];
                step+=dp[i][ind-1]+dp[ind+1][j];
                maxi=max(maxi,step);
            }
            dp[i][j]=maxi;
        }
       }
       return dp[1][n-2];

        
    }
};