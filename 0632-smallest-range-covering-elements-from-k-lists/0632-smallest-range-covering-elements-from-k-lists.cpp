/*
This code is to give the smallest possible range(difference between max and min must be minimised) which includes at least one number from each list.
Logic used here is of a min heap,as in order to minimise the difference between max and min in the range,we have to increase our min.Therefore we increase our min by moving ahead in the array and if the array ends,we break our loop.
I have made a class Node(containing row,column and data) and made a minheap of data type Node* and specified to keep the element with least data at the top.
Data Structures used is priority queue. 
Time Complexity=O(number of elements)
Space Complexity=O(k).
*/
#include<queue>
class Solution {
public:
    class Node{
        public:int data;int row;int column;
        Node(int d,int i,int j)
        {
        this->data=d;
        this->row=i;
        this->column=j;
        }
    };
    class compare{public:
      bool operator()(Node* a,Node* b){
          return a->data>b->data;
      }};
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        int low;int high;//yeh arry karenge answer
        int maxi=INT_MIN;
        priority_queue<Node*,vector<Node*>,compare> minheap;
        for(int i=0;i<nums.size();i++)
        {maxi=max(maxi,nums[i][0]);
        minheap.push(new Node(nums[i][0],i,0));}
        high=maxi;low=minheap.top()->data;
        while(!minheap.empty())
        {
        Node* topi=minheap.top();//top of minheap
        minheap.pop();
        int d=topi->data;
        int i=topi->row;
        int j=topi->column;
        if((high-low)>(maxi-d)){high=maxi;low=d;}
        if(j+1<nums[i].size())
        {maxi=max(maxi,nums[i][j+1]);//the newer element can be greater than maxi hence update the maxi                                           
         minheap.push(new Node(nums[i][j+1],i,j+1));
          }else{break;}//break if smaller list is over
        }
        ans.push_back(low);
        ans.push_back(high);
        return ans;}
};