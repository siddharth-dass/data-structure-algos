string Solution::solve(string A) {
    long long n = stoll(A);
    // cout<<n<<endl;
    for(int digits =64; digits>=2; digits--){
        // cout<<"Loop started"<<endl;
        long long low = 2;
        long long high = n-1;
        while(low<=high){
            long long mid =low + (high - low)/2;
            // cout<<"Mid = "<<mid<<endl;
            long long sum = 0;
            for(int i = 0; i<digits; i++){
                sum = sum + (long long)(pow(mid, i));
            }
            if(sum == n)
                return to_string(mid);
            if(sum < n)
                low = mid +1;
            else
                high = mid -1;
        }
    }
    // cout<<"Dint find anything"<<endl;
    return to_string(n-1);
}
