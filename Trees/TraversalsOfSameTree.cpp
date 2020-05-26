using namespace std;
bool verifytree(int preorder[], int inorder[], int postorder[],int len){
    // if the array lengths are 0,
    // then all of them are obviously equal
    if (len == 0)
        return 1;

    // if array lengths are 1,
    // then check if all of them are equal
    if (len == 1)
        return (preorder[0] == inorder[0])
               && (inorder[0] == postorder[0]);

    // search for first element of preorder
    // in inorder array
    int idx = -1;
    for (int i = 0; i < len; ++i)
        if (inorder[i] == preorder[0]) {
            idx = i;
            break;
        }

    if (idx == -1)
        return 0;

    // check for the left subtree
    int ret1 = verifytree(preorder + 1, inorder,
                         postorder, idx);

    // check for the right subtree
    int ret2 = verifytree(preorder + idx + 1, inorder + idx + 1,
                         postorder + idx, len - idx - 1);

    // return 1 only if both of them are
    // correct else 0
    return (ret1 && ret2);
}


int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    if(A.size() == B.size() && B.size() == C.size()){
        int n = A.size();
        int preorder[n];
        int inorder[n];
        int postorder[n];

        copy(A.begin(), A.end(), preorder);
        copy(B.begin(), B.end(), inorder);
        copy(C.begin(), C.end(), postorder);

        bool ans = verifytree(preorder,inorder,postorder,n);
        if(ans)
            return 1;
        else
            return 0;
    }

    return 0;
}
