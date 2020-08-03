/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int height(struct TreeNode* root){
    if(root) return 1 + fmax(height(root->left),height(root->right));
    else return 0;
}

double BFS(struct TreeNode* root, int level, int* num_elem){
    if(!root) return 0;
    
    if(level == 0){
       *num_elem += 1;
        return root->val;
    } 
    else return BFS(root->left, level-1, num_elem) + BFS(root->right, level-1, num_elem);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    *returnSize = height(root);
    double* result = malloc(*returnSize * sizeof(double));
    int* numElem = malloc(*returnSize * sizeof(int));
    
    for(int i = 0; i < *returnSize; i++){
        numElem[i] = 0;
        result[i] = BFS(root, i, &numElem[i]);
        
        if(numElem[i] != 0) result[i] /= numElem[i];        
    }
    
    return result;
}
