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
vector<int> Solution::inorderTraversal(TreeNode* A) {
    TreeNode* curr = A;
    vector<int> inorder;
    stack<TreeNode*> st;

    while(curr != NULL || st.empty() == false){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        inorder.push_back(curr->val);
        curr = curr->right;
    }
    return inorder;
}
