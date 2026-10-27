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
      int mindiff;
      int prev ;
      void inorder(TreeNode * root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        if(prev==-1){
            prev=root->val;
        }
        else{
            mindiff= min(mindiff,root->val-prev);
            prev = root->val;
        }
        inorder (root->right);
      }
    int getMinimumDifference(TreeNode* root) {
        mindiff = INT_MAX;
        prev = -1;
        inorder(root);
        return mindiff;
    }
};