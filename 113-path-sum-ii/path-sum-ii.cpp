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
    void helper(TreeNode *root, int s, vector<int>&temp,  vector<vector<int>>&ans,int target){
           if(root == nullptr){
            return ;
           }
           s+= root->val;
           temp.push_back(root->val);
           if(root->right==NULL && root->left==NULL){
            if(s==target){
              ans.push_back(temp);

            }
            temp.pop_back();
            return;
           }
           helper(root->left,s,temp,ans,target);
    helper(root->right,s,temp,ans,target);
    temp.pop_back();
    return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = 0;
        helper(root,sum,temp,ans,targetSum);
        return ans;

    }

    };
