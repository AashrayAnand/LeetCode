/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return sum(root, false, false);
    }
    
    int sum(TreeNode* curr, bool grandParent, bool parent){
        if(!curr){
            return 0;
        }
        
        return (grandParent ? curr->val : 0) + sum(curr->left, parent, curr->val % 2 == 0) + sum(curr->right, parent, curr->val % 2 == 0);
    }
    
};
