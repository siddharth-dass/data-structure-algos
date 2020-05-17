int steps(int n){
    if(n < 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    return steps(n-2) + steps(n-1);
}

int Solution::climbStairs(int A) {
    return steps(A);
}
/*
Stairs
Problem Description
You are climbing a stair case and it takes A steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Problem Constraints
1 <= A <= 36


Input Format
The first and the only argument contains an integer A, the number of steps.


Output Format
Return an integer, representing the number of ways to reach the top.


Example Input
Input 1:
 A = 2
Input 2:
 A = 3


Example Output
Output 1:
 2
Output 2:
 3

*/
