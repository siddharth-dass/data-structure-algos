int Solution::solve(string A) {
    int n = A.size();
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][i] = 1;
    /*Sublength can't start from n and move to 2 coz the prior
    cells required for max calc won't be having any val*/
    for(int subLength = 2; subLength <= n;subLength++){
        for(int i =0; i<= n-subLength;i++){
            int j = i + subLength -1;
            if(A[i] == A[j] && subLength ==2)//handling string lengths of 2 with same chars Eg bb
                dp[i][j] =2;
            else if(A[i] == A[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j =0; j<n;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    return dp[0][n-1];
}
/*
First, Create a recurrence relation then we will think of optimizing that.
Let’s say for sequence A[0..n-1] , L(0,n-1) denotes the length of longest palidromic subsequence.
It will be calculated by:
-> If last and first character of the sequence are same, then L(0,n-1) = L(1,n-1) + 2
->Else, L(0,n-1) = max(L(0,n-2),L(1,n-1)) Since we can observe overlapping Subproblems,
we will optimize it using a dynamic programming solution.
*/
