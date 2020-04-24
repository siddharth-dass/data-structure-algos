int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int time = INT_MIN;

    for(int i = 0; i<A.size();i++){
        int diff = abs(A[i] - B[i]);
        time = max(time,diff);
    }

    return time;
}
