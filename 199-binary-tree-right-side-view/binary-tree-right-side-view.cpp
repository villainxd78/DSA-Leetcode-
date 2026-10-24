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
    void helper(TreeNode * root,int depth,vector<int>&rightview){
        if(root==NULL){
            return;
        }
        if(rightview.size()<depth){
            rightview.push_back(root->val);
        }
        helper(root->right,depth+1,rightview);
        helper(root->left,depth+1,rightview);

        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rightview;
         helper(root,1,rightview);
         return rightview;
    }
};