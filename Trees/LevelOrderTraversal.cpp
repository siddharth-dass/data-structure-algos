/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<queue>
 using namespace std;
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector <int>> ans;
    queue<TreeNode*> q;
    q.push(A);
    int currChild = 1;
    int nextChild = 0;
    vector<int>a;
    while(!q.empty()){
        TreeNode* nn = q.front();
        q.pop();
        a.push_back(nn->val);
        currChild--;
        if(nn->left != NULL){
            q.push(nn->left);
            nextChild++;
        }
        if(nn->right != NULL){
            q.push(nn->right);
            nextChild++;
        }
        if(currChild==0){
            ans.push_back(a);
            a.clear();
            currChild = nextChild;
            nextChild =0;
        }

    }
    return ans;
}
