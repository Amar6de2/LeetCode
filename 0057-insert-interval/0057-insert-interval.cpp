class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //we will divide left in left and right and the center parts will be overlapping with with thw newinterval
        int i=0;
        int n=intervals.size();
        vector<vector<int>> ans;
        while(i<n && newInterval[0]>intervals[i][1])
        {
          ans.push_back({intervals[i][0],intervals[i][1]});
          i++;
        }
        
        //now jab tak we dont reach till right we shall iterate
        //right part means that lowest element of intevral will be greater than newinterval s last element
        //so till we reach the right: overlap
        while(i<n && intervals[i][0]<=newInterval[1])//till right condisitons are ot reahced
        {//why the equality sign?: see for right part,the lowest number from intervals //must  be greater than the maximum number from newinterval,equality is not allowed in right //side
           newInterval[0]=min(newInterval[0],intervals[i][0]);
           newInterval[1]=max(newInterval[1],intervals[i][1]);i++;
        }
        ans.push_back(newInterval);
        while(i<n)
        {
            ans.push_back({intervals[i][0],intervals[i][1]});i++;
        }
        return ans;
    }
};
//left part means the region of numbers which are ABSOLUTELY SMALLER THEN newinterval region.  the max element of left will interval[i][1] and the minimum element of newinterval will be its first element so if the first element is greater so it will mean ki left is vaid