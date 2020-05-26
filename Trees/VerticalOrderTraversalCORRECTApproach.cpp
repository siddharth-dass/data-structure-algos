/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*This is the correct approach in which we take into consideration the case when two nodes are on the same vertical line
BUT different depth. In that scenario the node with less depth sud come first and the node at greater depth should come
later. TO ENSURE this we use LEVEL ORDER TRAVERSAL*/
 vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > result;
    // Base case
    if (!A) return result;
    // Create a map of horizontalDistance, ListOfTreeNodes(at that horizontalDistance)
    map <int,vector<int> > m;

    // Create queue to do level order traversal.
    // Every item of queue contains node and horizontal distance.
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(A, 0)); // root's horizontalDistance is zero

    while(!q.empty()) {
        // get the queue front
        pair<TreeNode*,int> front = q.front();
        q.pop();
        int currentHorizontalDistance = front.second;
        TreeNode* currentTreeNode = front.first;

        // insert current node to hash map
        m[currentHorizontalDistance].push_back(currentTreeNode -> val);

        if (currentTreeNode -> left != NULL) {
             q.push(make_pair(currentTreeNode -> left, currentHorizontalDistance - 1));
        }
        if (currentTreeNode -> right != NULL) {
            q.push(make_pair(currentTreeNode -> right, currentHorizontalDistance + 1));
        }
    }
     // Traverse the map and print nodes at every horigontal distance
    for (map<int,vector<int> > :: iterator it = m.begin(); it != m.end(); it++) {
        result.push_back(it -> second);
    }
    return result;
}



//  void getVerticalOrder(TreeNode* root, int hd, map<int, vector<int>> &m){
//     if(root == NULL)
//         return;
//     m[hd].push_back(root->val);
//     getVerticalOrder(root->left,hd-1,m);
//     getVerticalOrder(root->right, hd+1,m);
//  }
// vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
//     map<int, vector<int>> m;
//     vector<vector<int>> ans;
//     getVerticalOrder(A,0,m);
//     map<int, vector<int>>:: iterator it;
//     for(it=m.begin();it!=m.end();it++)
//         ans.push_back(it->second);
//     return ans;
// }
