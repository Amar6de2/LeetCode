/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*
 This is a code to merge k sorted linked list and return the head of finally merged linked list.
Logic used here is of a minimum heap.I made a minimum heap of ListNode* data type,and specified it to keep the ListNode* with the minimum value in it at the top.Insert the first head of all the k lists into the heap and the top of the heap will give the minmum value head and pop it.Then check if the top element of the heap had a next or not.If it had a next head,then insert it into the heap and if it did not have a next head,do not push any head into the heap and continue till the heap is empty.
 Data Structure used are linked list and priority queues.
 Time Complexity =O(number of heads)
 Space Complexity=O(k)
*/
 
 #include<queue>
 class compare{public:
     bool operator()(ListNode* a,ListNode* b){
         if(a!=NULL && b!=NULL)
         { return a->val > b->val;}
          return false; }
         };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare> minheap;
     int k=lists.size();
  
    if(k==0){return NULL;}
    //step 1
    for(int i=0;i<k;i++)
    {if(lists[i]!=NULL){minheap.push(lists[i]);}}//input the non null elements
    ListNode* head=NULL;ListNode* tail=NULL;
    while(!minheap.empty())
    {
     ListNode* topi=minheap.top();//the top of the minheap
     minheap.pop();
     if(topi!=NULL && topi->next!=NULL){minheap.push(topi->next);}
     if(head==NULL)
     { head=topi;
       tail=topi;}
     else{ if(tail!=NULL)
      { tail->next=topi;
        tail=tail->next;}}}
        return head;
        
    }
};