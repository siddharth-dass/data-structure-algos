#include<map>
using namespace std;
map<int,int>m;
int partyWays(int A);

int partyWays(int A){
    auto itr = m.find(A);
    if(itr != m.end()){
        // cout<<A<<"->"<<itr->second<<endl;
        return (itr->second)%10003;
    }
    m[A] = partyWays(A-1) + ((A-1) * partyWays(A-2));
    return m[A]%10003;
}
int Solution::solve(int A) {
    m[1] = 1;
    m[2] = 2;
    return partyWays(A);
}
/*for 2 people no.of ways = 2
{A,B} = {A},{B},{AB}
{A,B,C} = 1->{A},{B},{C}
2-> {A},{BC}
3-> {B},{AC}
4->{C},{AB}

No of ways N can go alone is definitely (N-1) because whatever be the
ways in which (n-1) people would go, the Nth person would just tag ALONE

Couple- If i am the Nth person then i have (N-1) choices to choose a partner for me. Now the remaining (N-2) people can
go in F(N-2) ways so F(n) = (n-1) + (n-1)*F(n-2)
*/
