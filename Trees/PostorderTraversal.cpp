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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    TreeNode* curr = NULL;
    stack<TreeNode*> first;
    stack<int> sec;
    vector<int> vec;

    if(A == NULL){
        return vec;
    }

    first.push(A);
    while(! first.empty()){
        curr = first.top();
        first.pop();
        sec.push(curr->val);

        if(curr->left)
            first.push(curr->left);
        if(curr->right)
            first.push(curr->right);
    }
    while(!sec.empty()){
        vec.push_back(sec.top());
        sec.pop();
    }
    return vec;
}
