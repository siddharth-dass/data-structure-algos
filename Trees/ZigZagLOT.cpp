/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    queue<TreeNode*> primary;
    queue<TreeNode*> secondary;

    if(A == NULL)
        return ans;

    TreeNode* curr = A;
    primary.push(curr);
    bool reverse = false;
    vector<int> temp;
    while(!primary.empty()){
        curr = primary.front();
        primary.pop();

        if(reverse){
            temp.insert(temp.begin(),curr->val);
        } else {
            temp.push_back(curr->val);
        }

        if(curr->left)
            secondary.push(curr->left);
        if(curr->right)
            secondary.push(curr->right);

        if(primary.empty() && !secondary.empty()){
            ans.push_back(temp);
            temp.clear();

            swap(primary,secondary);
            reverse = !reverse;
        }
    }
    ans.push_back(temp);
    return ans;
}

