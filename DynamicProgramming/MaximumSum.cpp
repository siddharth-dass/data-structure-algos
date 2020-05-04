#include<vector>
using namespace std;
int Solution::solve(vector<int> &A, int B, int C, int D) {
    const int n = A.size();
    // vector<vector<int,3>,n> dp;
    int dp[n][3] = {0};
    dp[0][0] = B * A[0];
    dp[0][1] =dp[0][0] + C * A[0];
    dp[0][2] =dp[0][1] + D * A[0];
    for(int i=1;i<n;i++){
        dp[i][0],dp[i][1],dp[i][2] = 0;

        dp[i][0] = max(A[i]*B,dp[i-1][0]);
        dp[i][1] = max((dp[i][0] + A[i]*C), dp[i-1][1]);
        dp[i][2] = max((dp[i][1] + A[i]*D), dp[i-1][2]);
    }
    // for(int i=0;i<n;i++){
    //     for(int j =0;j<3;j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    return dp[n-1][2];
}
/*
The first key observation is i ≤ j ≤ k, so x*a[i] will always be the left maximum, and z*a[k] will always be the right maximum.
Create a left array where we store the left maximums for every element.
Create a right array where we store the right maximums for every element.
Then for every element, calculate the maximum value of the function possible.
For any index ind, the maximum at that position will always be (left[ind] + j * a[ind] + right[ind]),
find the maximum of this value for every element in the array and that will be your answer.

Create a dynamic programming table of size nx3.
In this, dp[i][0] stores maximum of value X·A[p] for p between 1 and i.
Similarly dp[i][1] stores the maximum value of X·A[p] + Y·A[q] such that p ≤ q ≤ i and
dp[i][2] stores maximum value of X·A[p] + Y·A[q] + Z·A[r] for p ≤ q ≤ r ≤ i.
*/
