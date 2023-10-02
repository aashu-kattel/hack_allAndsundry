#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
int coinChange(int n, vector<int>& memo)
{

    if(n==0)
    return 0;
    if(memo[n]!=0)
    return memo[n];
    int c1, c2;
    if(n>=1)
    {
    c1= coinChange(n-1,memo);
    }
    if(n>=2){
    c2= coinChange(n-2, memo);
    }
    int result= 1+min(c1, c2);
    memo[n]=result;
    return memo[n];
}
int main()
{
    int n=100;
    vector<int> memo(n+1);
    cout<<coinChange(n, memo);
}
