#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

void div_sorted(int n)
{
    vector<int> ls;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ls.push_back(i);
        if((n/i)!=i)
        {
            ls.push_back(n/i);
        }
        }
    }
    sort(ls.begin(), ls.end());
    for(auto it: ls)
    {
        cout<<it<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    div_sorted(n);
}
