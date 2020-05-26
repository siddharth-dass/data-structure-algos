/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*There is some out of order element insertion into the vector at particular level.
 The vectors for each level are appearing in order but the element inside vector are out of order for some.
 Haven't resolved that yet and went for TreeMap impleemntation
 */
 void findMinMax(TreeNode* A, int &smallest, int &largest, int d){
     if(A == NULL)
        return;
     smallest = min(smallest,d);
     largest = max(largest,d);
     findMinMax(A->left,smallest,largest,d-1);
     findMinMax(A->right,smallest,largest,d+1);
 }

 void printNode(TreeNode* A, vector<vector<int>> &ans ,int line, int distance,int lastIndex, int max){
     if(A == NULL)
        return;
     if(distance == line)
         ans[lastIndex-max + distance].push_back(A->val);
     printNode(A->left,ans,line, distance -1,lastIndex,max);
     printNode(A->right,ans,line, distance +1,lastIndex,max);
 }

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> ans;
    int min = INT_MAX;
    int max = -INT_MAX;
    findMinMax(A,min, max,0);
    for(int i = min; i<=max;i++){
        vector<int>a;
        ans.push_back(a);
    }
    int lastIndex = max-min;//for both min<=0

    for(int line_no = min;line_no<=max;line_no++)
        printNode(A, ans, line_no, 0,lastIndex,max);
    return ans;
}
