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
class Solution {
public:
   class Info{
    public:
    bool isbst;
    int min;
    int max;
    int sum;
    Info(bool isbst,int min,int max,int sum){
        this->isbst = isbst;
        this->min = min;
        this->max = max;
        this->sum = sum;
    }
   };
    int maxsum;
   Info * largestsum(TreeNode * root){
    if(root==NULL){
        return new Info(true,INT_MAX,INT_MIN,0);
    }
    Info* leftInfo = largestsum(root->left);
    Info * rightInfo = largestsum( root ->right);
    int currmin = min(root->val,min(leftInfo->min,rightInfo->min));
    int currmax = max(root->val,max(leftInfo->max,rightInfo->max));
    int currsum = leftInfo ->sum + rightInfo ->sum + root->val;
    if(leftInfo->isbst && rightInfo->isbst && root->val>leftInfo->max && root->val<rightInfo->min){
        maxsum = max(maxsum,currsum);
        return new Info(true,currmin,currmax,currsum);
    }
    return new Info(false,currmin,currmax,currsum);
   }
    int maxSumBST(TreeNode* root) {
         largestsum(root);
         return maxsum;
    }
};