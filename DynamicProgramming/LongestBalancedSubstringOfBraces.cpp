#include<stack>
/*Stack Approach*/
int Solution::LBSlength(const string A) {
    int n = A.size(),l;
    stack<int>s;
    int maxlength = INT_MIN;
    vector<int>remainingIndices;

    s.push(0);
    for(int i = 1;i<n;i++){
        if(s.empty()){
            s.push(i);
            continue;
        }
        switch(A[i]){
            case ')':if(A[s.top()] == '(')
                        s.pop();
                     else
                        s.push(i);
                    break;
            case '}':if(A[s.top()] == '{')
                        s.pop();
                     else
                        s.push(i);
                    break;
            case ']':if(A[s.top()] == '[')
                        s.pop();
                     else
                        s.push(i);
                    break;
            default:s.push(i);
                    break;
        }
    }
    if(s.empty())
        return n;//if stack is empty then entire string is balanced
    while(!s.empty()){
        remainingIndices.push_back(s.top());
        s.pop();
    }/*vector will contain the indices in reverse order as stack is LIFO*/
    l = remainingIndices.size();
    for(int i =l-2;i>=0;i--)
        maxlength = max((remainingIndices[i]- remainingIndices[i+1]-1),maxlength);
    /*The last unbalanced index will refer to the balanced substring till the last character in string
    Did not subtract extra -1 coz the last index of the substring will be included as balanced substring
    Similarly for the first un-balanced index from start
    Used this approach when failed for test-case
    ([[]]()}[]([[]]([[]]))[ ans is 14 for this
    */
    maxlength = max(maxlength,((n-1) - remainingIndices[0]));
    maxlength = max(maxlength,(remainingIndices[l-1] - 0));
    return maxlength;
}

/*
There can be 2 ways to solve this problem.

1. using Stack

Scan the string from beginning to end.
If current character is '(',
push its index to the stack. If current character is ')' and the
character at the index of the top of stack is '(', we just find a
matching pair so pop from the stack. Otherwise, we push the index of
')' to the stack.
After the scan is done, the stack will only
contain the indices of characters which cannot be matched. Then
let's use the opposite side - substring between adjacent indices
should be valid parentheses.
If the stack is empty, the whole input
string is valid. Otherwise, we can scan the stack to get longest
valid substring as described in step 3.


2. using DP(Complicated)

The solution uses DP. The main idea is as follows:
1) Construct an array longest[] . For any index i, longest[i] stores the longest length of valid parentheses which ends at i.
And the DP idea for any string s is :
2) If s[i] is any opening bracket, set longest[i] to 0, because any string ending with an opening bracket cannot be balanced.
3) If s[i] is a closing bracket and s[i-1] is it’s opening balancing bracket then, longest[i] = longest[i-2] + 2
4) If s[i] is a closing bracket and s[i-longest[i-1]-1] is it’s opening balancing bracket then, longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
5) Rest all the cases when s[i] is a closing bracket, longest[i] will be equal to 0.
For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.


*/
