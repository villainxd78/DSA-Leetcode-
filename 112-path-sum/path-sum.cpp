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
     bool helper(TreeNode * root, int target,int s){
        if(root==NULL){
            return false;
        }
        s+= root->val;
        if(root->left==NULL && root->right == NULL){
            if(s== target){
                return true;
            }
            return false;
            
        }
        return helper(root->left,target,s) || helper(root->right,target,s);
        }
     
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root,targetSum,sum);
    

       
    }
};