#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int Solution::numDecodings(string A) {
    int n = A.size();
    vector<int>dp(n+1,0);
    dp[0] = 1;
    if(A[0] == '0')
        return 0;
    else
        dp[1] = 1;
    for(int i = 2; i<=n;i++){//1-based indexing helped to ease a lot of corner case handling
        if(A[i-1] != '0'){
            dp[i]+=dp[i-1];
        }
        stringstream sn;
        sn<<A.substr(i-2,2);int num;sn>>num;
        if(num >= 10 && num<=26){
                /*
                the condition should be if(num >= 10 && num<=26) as that represent that
                 it is able to make 2 digit number. So just change that.
                */
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}

/*
Question
Ways to Decode
Problem Description
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message denoted by string A containing digits, determine the total number of ways to decode it.


Problem Constraints
1 <= length(A) <= 105


Input Format
The first and the only argument is a string A.


Output Format
Return an integer, representing the number of ways to decode the string.


Example Input
Input 1:
 A = "12"
Input 2:
 A = "8"


Example Output
Output 1:
 2
Output 2:
 1


Example Explanation
Explanation 1:
 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:
 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.


Erroneous code(Lot of hardcoidng for corner case ahndling)
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int Solution::numDecodings(string A) {
    int n = A.size();
    if(n == 1)
        return 1;
    else if(A[0] == '0')
        return 0;
    else if(A[n-1] == '0'){
        stringstream ss;
        ss<<A.substr(n-2,2);
        int num;
        ss>>num;
        if(num>26)
            return 0;
    }
    vector<int>dp(n,0);
    dp[0] = 1;
    for(int i=1;i<n;i++){
        stringstream ss;
        ss<<A.substr(i-1,2);
        int num;
        ss>>num;
        // cout<<"i = "<<i<<" "<<" "<<A.substr(i-1,2)<<" "<<num<<endl;
        if(A[i] == '0' && num>26)
            return 0;
        else if(A[i] =='0' && num <=26){
            if(A[i-1] == '0')
                return 0;
            if((i-2)>=0 && A[i-2]!= '0')
                dp[i] += (dp[i-2]-dp[i-1]);
            else if((i-2)>=0 && A[i-2] =='0')
                dp[i] += dp[i-1];
            else if((i-2) < 0)
                dp[i] += dp[i-1];
        }
        else if(A[i] !='0' && num>26){
            dp[i] += dp[i-1];
        }else if(A[i] !='0' && num<=26){
            if(A[i-1] == '0')
                dp[i] += dp[i-1];
            else if(A[i-1] !='0'){
                if(i-2 >=0)
                    dp[i] += dp[i-1] + dp[i-2];
                else
                    dp[i]+=dp[i-1]+1;
            }
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<dp[i]<<" ";
    // cout<<endl;
    return dp[n-1];
}


SOLUTION APPROACH
Lets first look at the bruteforce solution.
It only makes sense to look at 1 digit or 2 digit pairs ( as 3 digit sequence will be greater than 26 ).
So, when looking at the start of the string, we can either form a one digit code, and then look at the ways
 of forming the rest of the string of length L - 1, or we can form 2 digit code if its valid and add up the
ways of decoding rest of the string of length L - 2.
This obviously is exponential. The code would go something like the following :
 int ways(string &s, int startIndex) {
    // BASE CASES

    int answer = 0;
if (isValid(s[startIndex])) answer += ways(s, startIndex + 1);
    if (isValid(s[startIndex] + s[startIndex + 1])) answer += ways(s, startIndex + 2);
    return answer;
 }
Note that in this case, startIndex can only take L number of values. Can you use the fact to store the result
 so that the function processing does not happen so many times ?

*/
