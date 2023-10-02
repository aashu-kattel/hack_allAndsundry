#include<bits/stdc++.h>
using namespace std;

bool palindrome(vector<int> &arr , int size){
    int s = 0;
    int e = size-1;

    while(s<=e){
        if(arr[s]==arr[e]){
            s++;
            e--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool ans = palindrome(arr,n);

    cout<<ans<<endl;



return 0;
}
