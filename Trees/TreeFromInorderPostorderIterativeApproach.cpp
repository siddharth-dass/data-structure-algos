class Solution {
    public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            if(inorder.size() == 0)return NULL;
            TreeNode* p;
            TreeNode* root;
            vector<int> vint;
            vector<TreeNode*> vtn;
            root = new TreeNode(postorder.back());
            vtn.push_back(root);
            postorder.pop_back();
            while(true)
            {
                if(inorder.back() == vtn.back()->val)
                {
                    p = vtn.back();
                    vtn.pop_back();
                    inorder.pop_back();
                    if(inorder.size() == 0) break;
                    if(vtn.size())
                        if(inorder.back() == vtn.back()->val)continue;
                    p->left = new TreeNode(postorder.back());
                    postorder.pop_back();
                    vtn.push_back(p->left);
                }
                else
                {
                    p = new TreeNode(postorder.back());
                    postorder.pop_back();
                    vtn.back()->right = p;
                    vtn.push_back(p);
                }
            }
            return root;
        }
};
