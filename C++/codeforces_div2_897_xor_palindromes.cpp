#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t,m;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        ll a=0;
        if(n%2){
            for(ll i=0;i<n/2;i++){
                if(s[i]!=s[n-1-i]) a++;
            }
            for(ll i=0;i<n+1;i++){
                if(i<a || n-i<a) cout<<0;
                else cout<<1;
            }
        }
        else{
            for(ll i=0;i<n/2;i++){
                if(s[i]!=s[n-1-i]) a++;
            }
            for(ll i=0;i<n+1;i++){
                if(i<a || n-i<a || (i-a)%2==1) cout<<0;
                else cout<<1;
            }
        }
        cout<<'\n';
    }
}
