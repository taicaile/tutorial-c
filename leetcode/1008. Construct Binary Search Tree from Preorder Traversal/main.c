/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* dfs(int* preorder, int lowerbound, int upperbound, int* index, int size){
    if(*index == size){
        return NULL;
    }
    printf("index: %d, %d, %d\n", *index, lowerbound, upperbound);

    int cur = preorder[*index];
    if(cur<lowerbound || cur>upperbound){
        return NULL;
    }

    (*index)++;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = cur;
    root->left = dfs(preorder, lowerbound, cur, index, size);
    root->right = dfs(preorder, cur, upperbound, index, size);
    return root;
}


struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {

    int index=0;
    return dfs(preorder, INT_MIN, INT_MAX, &index, preorderSize);
}