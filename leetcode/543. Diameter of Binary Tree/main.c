/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) ((a)>(b)?(a):(b))

int helper(struct TreeNode *node, int *ans){
    if(node == NULL){
        return 0;
    }

    int left = helper(node->left, ans);
    int right = helper(node->right, ans);

    *ans = MAX(*ans, left+right+1);
    return MAX(left, right)+1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int ans = 0;
    helper(root, &ans);
    return ans-1;
}