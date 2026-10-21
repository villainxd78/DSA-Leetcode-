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
    bool iSidentical(TreeNode * root1,TreeNode * root2){
        if(root1==NULL&& root2==NULL){
            return true;
        }else if(root1 == NULL || root2 == NULL){
            return false;
        }
        if(root1->val!=root2 ->val){
            return false;
        }
        return iSidentical(root1->left,root2->left) && iSidentical(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot == NULL){
            return true;
        }
        else if(root==NULL || subRoot == NULL){
            return false;
        }
        if(root->val == subRoot->val){
            if(iSidentical(root,subRoot)){
                return true;
            }
        }
        int isleftsubtree = isSubtree(root->left,subRoot);
        if(!isleftsubtree){
            return isSubtree(root->right,subRoot);
        }
        return true;
    }
};