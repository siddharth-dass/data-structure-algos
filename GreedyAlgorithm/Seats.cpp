int Solution::seats(string A) {
    int MOD = 10000003;
    int N = A.size();
    vector<int> B;

    for(int i = 0; i<N;i++)
        if(A[i] =='x')
            B.push_back(i);

    int n = B.size();
    if(n==0)
        return 0;
    int mid = n/2;
    int median = n & 1 ? B[mid] : (B[mid-1] + B[mid])/2;//0 based indexing so [mid-1] && [mid]

    int empty = A[median]=='x' ? median -1 : median;

    int cost = 0;

    //left of median
    for(int i = median -1; i>=0;--i){//need not start from median
        if(A[i] == 'x'){
            cost += empty - i; // empty will never cross i
            empty --;

            if(cost>=MOD)
                cost%=MOD;
        }
    }

    empty = median +1; //the postion median is already taken care for
    for(int i = median +1; i<N;++i){
        if(A[i] == 'x'){
            cost += i - empty;
            empty ++;

            if(cost>=MOD)
                cost%=MOD;
        }
    }

    return cost;
}

//Why median will give answer
//string :  .x..x..x.
//positions where x are present {1, 4, 7}
//Median is 4. So we will move all x near our median.
//1st person would need to jump 2 steps and 3rd person would also
//need to jump 2 steps. Total answer = 4.
//
//Only Median has to be used.

//Why does the solution of finding the median and moving
//all people near the median will work? Prove it?

//Some persons move left, some persons move right.But They should never
//move cross each other, otherwise they can just take the new seat of
//each others, reducing the total moves.
//
//If two persons move in the same direction, then there is no need for one
//person to cross the other one. They can switch their new seats,
//resulting the same number of move.
//
//
//Hence, we can find an optimized solution, such that the order of seats
//were kept. For a solution that L persons on the left move right, M
//persons in the middle don't move, and R persons on the right move left.
//- If L > M+R, we can improve the solution by shift left by one seat
//- If L + M < R, we can improve the solution by shift right by one seat
//- Otherwise ( |L - R| < M ), we reach a local minimal.
//
//
//Then it is easy to show that a solution constructed by aligning the
//median meet the requirement.
//
//
//If you found the proof complex, you may want to compare it with a
//classical question: If we want to move all the people to one seat,
//which is the best seat? Obviously the one where most of the cluster is present
