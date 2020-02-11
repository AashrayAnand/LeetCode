/*
 *
 * Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.
 *
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
    TreeNode* bstToGst(TreeNode* root) {
        help(root, 0);
        return root;
    }
   
    int help(TreeNode *curr, int pre){
       if(!curr){
            return 0;
        }
       
      if(isLeaf(curr)){
            curr->val += pre;
            return curr->val;
        }
      
        int rSum = help(curr->right, pre);
        curr->val += rSum;
        int lSum = help(curr->left, curr->val);
        // if there are left children, percolate the left
        // child sum to the parent of current node
        return lSum > 0 ? lSum : curr->val;
    }
   
    bool isLeaf(TreeNode *node){
        return node && !node->left && !node->right;
    }
};
