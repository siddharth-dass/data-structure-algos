
int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(),A.end()); //for finding possible min diff
    vector<int>B(n-2);
    int sol = INT_MAX;

    for(int i = 0; i<n;i++){
        for(int j = i+1; j<n;j++){
            int b = 0;
            for(int k = 0; k<n;k++){//forming the new array excluding A[i] and A[j]
                if((k!=i) && (k!=j)){
                    B[b++] = A[k];
                }
            }

            int sum = 0;
            for(int k = 0; k<n-3;k+=2){//alternate pairs
                sum += B[k+1] - B[k];
            }

            sol = min(sol,sum);
        }
    }

    return sol;
}


//A = [2, 4, 1, 10, 6, 15]
//
//2 4 = 2
//2 1 = 1
//2 10 = 8
//2 6 = 4
//2 15 = 13
//4 1 = 3
//4 10 = 6
//4 6 =2
//4 15 = 11
//1 10 = 9
//1 6 = 5
//1 15 = 14
//10 6 = 4
//10 15 = 5
//6 15 = 9

//Pseudo code
//for i = 0 to n
//for j = i+1 to n
//temparr = [all element of array except element at index i and j]
//sort temparr
//take sum of diff of adjacent pairs r.g A[1]-A[0] + A[3] - A[2] ....so on.
//it will be one possible answer.
//keep track of min answer in this loop and return at the end.
//
//We need to take alternate pairs i.e A[1]-A[0] + A[3] - A[2] ... [0,1],[2,3],[4,5] coz
//We are making pairs [1,2],[3,4] for some other i and j and for the given extracted
//array not conatining i and j we cannot have the pairs [1,2] and [2,3] because if [1,2]
//gives me min diff then 2 is taken so it should not pair up with [2,3]
// Also in sorted elements, the nearest ones hav smallest diff possible.
