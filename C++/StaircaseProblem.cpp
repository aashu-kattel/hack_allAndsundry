#include<iostream>
using namespace std;
int findWays(int i)
{
    if (i==0) return 1;
    if(i<0) return 0;
    
    return findWays(i-1)+findWays(i-2);  
}
int main(){
    // int n;
    // cin>>n;
    cout<<"ways with minimum steps:"<< findWays(1);
}
