/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* tree(vector<int> &A, vector<int> &B,int start , int end,unordered_map<int,int> &mp, int & pre)
{
    if(start>end)
    return NULL;
    int curr=A[pre];
    pre++;
    TreeNode* t=new TreeNode(curr);
    if(start==end)
    return t;
    int index = mp[curr];
    t->left = tree(A,B,start,index-1,mp, pre);
    t->right = tree(A,B,index+1,end,mp, pre);
    return t;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n=B.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[B[i]]=i;
    }
    int pre = 0;
    TreeNode *root = tree(A,B,0,n-1,mp, pre);
    return root;
}

