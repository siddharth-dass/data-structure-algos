int Solution::bulbs(vector<int> &A) {
    int switches = 0;
    for(int i =0; i<A.size();i++){
        int rem = switches %2;
        if(rem == 0 && A[i] == 0){
            switches += 1;
        }else if(rem == 0 && A[i] == 1){
            continue;
        }else if(rem != 0 && A[i] == 0){
            continue;
        }else if(rem != 0 && A[i] == 1){
            switches +=1;
        }
    }
    return switches;
}

//if no of switches is odd and A[i] = 0 then due to odd switches it must
// have turned on so no need to switch. Same for other three cases.
// In each case we are greedily minimising the no.of switches by checking the state
// and no of switches performed
