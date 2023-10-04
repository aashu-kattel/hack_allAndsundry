#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseStringWordWise(string input)
{
    //Write your code here
    string str;

    int r;
    int m = input.size();
    for(int i=m-1;i>=0;--i){
        if(input[i]==' '){
            r=m-i;
            m=i-1;
            str.append(input.substr(i+1,r));
            str.append(" ");

            // str+=input[i];
        }
    }
    str.append(input.substr(0,m+1));
    return str;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    
    cout << ans << endl;
}
