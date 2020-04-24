#include <bits/stdc++.h>
using namespace std;

/*Approach 1 is correct but its O(N^2) which is not sufficient to pass the time limit.

You can improve complexity by following
1) If sum of gas is more than sum of cost, does it imply that there always is a solution ? yes
2) Lets say you start at i, and hit first negative of sum(gas) - sum(cost) at j.
We know TotalSum(gas) - TotalSum(cost) > 0. What happens if you start at j + 1 instead ?
Does it cover the validity clause for i to j already ? i.e if for given i to j circuit is breaking then
for any k in(i,j] the circuit will break so better shift start position to j+1

Applying all these observations you can write simply like this */

int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int gasTotal = 0;
    int costTotal = 0;
    int tank =0;
    int start = 0;
    for(int i =0;i<gas.size();i++){
        gasTotal += gas[i];
        costTotal += cost[i];
        tank += gas[i] - cost[i];
        if(tank <0){
            tank = 0;
            start = i+1;
        }
    }
    if(gasTotal < costTotal)
        return -1;
    else
        return start;
}

//Approach 1 tried to check all the possible indices from where we can start but TLE coz O(N^2)
/*int Solution(const vector<int> &A, const vector<int> &B) {
    vector<int>ans;
    vector<int>c;
    int n = A.size();
    int f =1;
    for(int i = 0; i<n;i++){
        if(B[i] <= A[i]){
            c.push_back(i);
            f = 0;
        }
    }
    if(f)
        return -1;

    for(int i =0;i<c.size();i++){
        int start = c[i];
        int curr = start;
        int tank = 0;
        int flag = 0;
        while(true){
            tank += A[curr];
            if(tank >= B[curr]){
                tank -= B[curr];
                curr +=1;

                if(curr >= n)
                    curr = 0;
                if(curr == start){
                    flag = 1;
                    break;
                }
            }
            else
                break;
        }
        if(flag)
            ans.push_back(start);
    }
    sort(ans.begin(),ans.end());
    return ans[0];
}*/

//Approach 2
int main(){
    const vector<int> A {959, 329, 987, 951, 942, 410, 282, 376, 581, 507, 546, 299, 564, 114, 474, 163, 953, 481, 337, 395, 679, 21, 335, 846, 878, 961, 663, 413, 610, 937, 32, 831, 239, 899, 659, 718, 738, 7, 209 };

    const vector<int>B {862, 783, 134, 441, 177, 416, 329, 43, 997, 920, 289, 117, 573, 672, 574, 797, 512, 887, 571, 657, 420, 686, 411, 817, 185, 326, 891, 122, 496, 905, 910, 810, 226, 462, 759, 637, 517, 237, 884};

    return Solution(A,B);
}
