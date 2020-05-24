bool possible(vector<int> &C,int n,int A, long long mid){
    int count = 1, sum=0;

    for(int i =0;i<n;i++){
        if(C[i] > mid)
            return false;
        if(sum + C[i] > mid){
            count++;
            sum =C[i];
        }
        else
            sum+=C[i];
    }
    if(count > A)
        return false;
    else
        return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long low = 0;
    long long high = 0;
    int n = C.size();
    // int largest = -INT_MAX;
    long long ans = 0;
    for(int i =0;i<n;i++){
        high += C[i];
        // low = max(low,C[i]);//the largest board
    }
    // if(A>=n)
    //     return ((low%10000003*B%10000003)%10000003);
    while(low<=high){
        // cout<<"Low = "<<low<<" High = "<<high;
        long long mid = low + (high -low)/2;
        // cout<<" Mid = "<<mid;
        if(possible(C,n,A,mid)){
            // cout<<" Possible"<<endl;
            high = mid -1;
            ans = mid;
        }else{
            // cout<<" Not Possible"<<endl;
            low = mid +1;
        }

    }

    return (int)((ans%10000003*B%10000003)%10000003);
}
/*
The answer space is [0, sum of all board size]. I was getting overflow error (-ve answer) coz
I was using int dataType instead of long long. No need to separately handle cases where A>C.size() or A==1.
They will be automatically considered.

if boardSize > mid or no.of Painters required > Available painters then it is a non-feasible solution so increase the mid

*/
