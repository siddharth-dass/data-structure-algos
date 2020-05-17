int Solution::climbStairs(int A) {
    int dp[A+2];
    /*A represents no.of steps here. dp will represent the level.
    if A= 1 means there are 2 levels i.e lev 1 and lev 2
    if A = 2 means there are three levels 1,2 and 3.
    So we precompute upto level 3. No of levels = steps + 1.
    Considering 1-based indexing here i.e there is no level 0
    */
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    if(A ==1)
        return 1;
    else if(A == 2)
        return 2;
    for(int i =3; i<A+2;i++){
        dp[i+1] = 0;
        dp[i+1] = dp[i+1-1] + dp[i+1-2];
    }

    return dp[A+1];
}
