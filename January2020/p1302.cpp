#include <vector>
/*Given a binary tree, return the sum of values of its deepest leaves.

e.g.

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

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
    int maxDepth = 0;
    int sum = 0;
    int deepestLeavesSum(TreeNode* root) {
        // sum is 0 if node is null
        sum = 0;
        help(root, 0);
        return sum;
    }
    
    void help(TreeNode *curr, int depth){
        if(curr){
            if(depth > maxDepth){
                maxDepth = depth;
                sum = curr->val;
            } else if(depth == maxDepth){
                sum += curr->val;
            }
            help(curr->left, depth + 1);
            help(curr->right, depth + 1);
        }
    }
};
