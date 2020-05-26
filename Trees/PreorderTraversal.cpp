/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<iostream>
 #include<vector>
 #include<stack>
 using namespace std;
vector<int> Solution::preorderTraversal(TreeNode* A) {
    TreeNode* curr = A;
    vector<int> preorder;
    stack<TreeNode*> s;
    while(curr != NULL || s.empty() == false){
        while(curr != NULL){
            preorder.push_back(curr->val);
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
    return preorder;
}
