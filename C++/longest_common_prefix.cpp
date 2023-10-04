#include<bits/stdc++.h>
using namespace std;

string longestprefix(vector<string> &s){
    int i=0;
    string ans;

    while(true){
        char curr = 0;
        for(auto str : s){
            if(i>=str.size()){
                curr=0;
                break;
            }

            if(curr==0){
                curr=str[i];
            }else if(curr!=str[i]){
                curr=0;
                break;
            }
        }
        if(curr==0){
            break;
        }
        ans.push_back(curr);
        i++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    string ans = longestprefix(s);
    cout<<ans<<endl;

    return 0;
}
