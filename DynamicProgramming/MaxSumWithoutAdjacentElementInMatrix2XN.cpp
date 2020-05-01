int Solution::adjacent(vector<vector<int> > &A) {
    //Approach 1
    int n=A[0].size();
    int B[n];
    for(int i=0;i<n;i++)
        B[i]=max(A[0][i],A[1][i]);
    int pi = B[0],pe = 0,incl,excl;
    for(int i = 1;i<n;i++){
        incl = pe + B[i];
        excl = max(pi,pe);
        pi = incl;
        pe = excl;
    }
    return max(pi,pe);

    //Approach 2
    // int n=A[0].size();
    // int B[n];
    // for(int i=0;i<n;i++)
    //     B[i]=max(A[0][i],A[1][i]);

    // int dp[n];
    // dp[0]=B[0];
    // dp[1]=max(B[0],B[1]);1 is chosen or not depends whether inclusion of 0 gives optimum or its exclusion gives optimum
    // for(int i=2;i<n;i++)
    // {
    //     dp[i]=max((B[i]+dp[i-2]),dp[i-1]);
            //exclude current = dp[i-1]
            //include cureent = B[i]+dp[i-2] //[i-2] coz consecutive can't be selected
    // }
    // return dp[n-1];
}

/*This problem is extension of https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

*/
