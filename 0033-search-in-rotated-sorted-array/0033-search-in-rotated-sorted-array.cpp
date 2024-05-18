class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;int e=nums.size()-1;
        while(s<=e)
        {
            int m=(s+e)/2;
            if(nums[m]==target){return m;}
            //left sorted
            if(nums[m]>=nums[s])//remember to include the m th index !
                //for the case when there is {3,1} and target is 1
            {
                if(nums[s]<=target && target<=nums[m]){e=m-1;}
                else{s=m+1;}
            }
            else
            {
                if(nums[e]>=target && nums[m]<=target){s=m+1;}
                else{e=m-1;}
            }
        }
        return -1;
        
    }
};