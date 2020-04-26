#include<iostream>
#include<map>
using namespace std;
int fib(int A);
map<int,int> m;
int fib(int A){
    auto itr = m.find(A);
    if(itr != m.end()){//means the number is already calculated
        return itr->second;
    }
    m[A] = fib(A-1) + fib(A-2);

    return m[A];
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int A;
    cin>>A;
    m[0] = 0;
    m[1] = 1;
    cout<<fib(A)<<endl;
    return 0;
}
