/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class info{public:
     int maxi;
     int mini;
     int isbst;
     int sum;
 };
 info maxsumm(TreeNode* root,int &maxsum)
 {
     if(root==NULL){info p;p.maxi=INT_MIN;p.mini=INT_MAX;p.isbst=true;p.sum=0;return p;}
     info l=maxsumm(root->left,maxsum);
     info r=maxsumm(root->right,maxsum);
     info ans;
     ans.maxi=max(root->val,r.maxi);
     ans.mini=min(root->val,l.mini);
     ans.sum=root->val+l.sum+r.sum;
     bool c=false;
     if(root->val>l.maxi && root->val<r.mini)
     {c=true;}
     if(l.isbst && r.isbst && c){ans.isbst=true;}
     else{ans.isbst=false;}
     if(ans.isbst==true){maxsum=max(maxsum,ans.sum);}
     else{ans.sum=0;}
     return ans;

 }
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxsum=INT_MIN;
        info r=maxsumm(root,maxsum);
        if(maxsum<0){return 0;}
        return maxsum;

        
    }
};