/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int search(vector<int> &inorder,int data, int start, int end);
 TreeNode* treeGen(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd,int* pIndex);



TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int pIndex = n - 1;
    return treeGen(A,B,0,n-1,&pIndex);
}

TreeNode* treeGen(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd,int* pIndex){
    if(inStart > inEnd)
        return NULL;

    TreeNode* tNode = new TreeNode(postorder[*pIndex]);
    (*pIndex)--;
    // tNode->val = postorder[postIndex--];
    // tNode->left = NULL;
    // tNode->right = NULL;


    if(inStart == inEnd)
        return tNode;

    int index = search(inorder,tNode->val,inStart,inEnd);
    tNode->right = treeGen(inorder,postorder,index + 1,inEnd,pIndex); //first right subtree
    tNode->left = treeGen(inorder,postorder,inStart,index - 1,pIndex);//then left subtree

    return tNode;
}

int search(vector<int> &inorder,int data, int start, int end){
    int i;
    for(i = start; i<= end; i++){
        if(inorder[i] == data)
            return i;
    }
}
