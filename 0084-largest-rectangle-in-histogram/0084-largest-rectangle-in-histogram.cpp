/*
This is a code to calculate the maximum area of rectangle in any given histogram.
Data Structures used here is stack in order to calculate the previous smaller elements and next smaller elements.
Time Complexity=O(n)
Space Complexity=O(n)
*/
class Solution {
public:
   vector<int> ps(vector<int> heights,int n)
   {   vector<int> ans(n);
       stack<int> s;
       s.push(-1);
       for(int i=0;i<n;i++)
       {int curr=heights[i];
        while(s.top()!=-1 && heights[s.top()]>=curr)
        {s.pop();}
        ans[i]=s.top();
        s.push(i);}
        return ans;
   }

   vector<int> ns(vector<int> arr,int n)
   {
       vector<int> ans2(n);
       stack<int> s;
       s.push(-1);
       for(int j=(n-1);j>=0;j--)
       {int curr=arr[j];
        while(s.top()!=-1 && arr[s.top()]>=curr)
        {s.pop();}
        ans2[j]=s.top();
        s.push(j);}
        return ans2;
   }


    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int> prevsmall;int area;int maxarea=0;
        //calculate the previous small(ps)
        prevsmall=ps(heights,n);
        //calculate the next small(ns)
        vector<int> nextsmall;
        nextsmall=ns(heights,n);
        for(int y=0;y<n;y++)
        {
         int l=heights[y];
         if(nextsmall[y]==-1){nextsmall[y]=n;}
         int b=nextsmall[y]-prevsmall[y]-1;
         area=l*b;
         maxarea=max(area,maxarea);
            
        }
        
        return maxarea;
    }
};