
# include<bits/stdc++.h>
using namespace std;
//0(n^3)
void bst(vector<int>arr){

    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(n,0));
     vector<vector<int>>s(n,vector<int>(n,0));

    for(int g=0; g<n; g++){
        for(int i=0, j=g; j<n; i++,j++){
            if(g==0){
                dp[i][j]=arr[i];
            }
            else{
                    dp[i][j]=INT_MAX;
                    int ans=0;
                for(int k=i; k<=j ; k++){
                        ans+=arr[k];
                    int tc= (k==i? 0 :dp[i][k-1] )+(k==j? 0 : dp[k+1][j]);
                   if(tc<dp[i][j]){
                    dp[i][j]= tc;
                    s[i][j]=k;
                                       }


                }

                dp[i][j]+=ans;
            }








        }
    }
cout<<dp[0][n-1]<<"is the cost";









}












int main(){

int n;
cin>>n;
vector<int>v(n,0);

for(int i=0; i<n; i++){
    cin>>v[i];
}


bst(v);


















}
