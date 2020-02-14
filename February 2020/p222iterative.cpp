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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode * curr = nodes.front();
            nodes.pop();
            sum++;
            if(curr->left){
                nodes.push(curr->left);
            }
            if(curr->right){
                nodes.push(curr->right);
            }
        }
        return sum;
    }
};
