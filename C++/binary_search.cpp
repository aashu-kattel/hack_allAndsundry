#include<iostream>
using namespace std;

bool binary_search(int n, int a[10],int key){
  int s=0;
  int e=n-1;
  while(s<=e){
    int mid=(s+e/2);
    if(a[mid]>key){
      e=mid-1;
    }
    else if(a[mid]<key){
      s=mid+1;
    }
    else if(a[mid]==key){
      return true;
    }
  } 
  return false;
}

int main(){
  int key,n;
  cin>>n;
  cout<<"enter key you want to search ";
  cin>>key;
  int a[10];
  for(int i=0;i<10;i++){
    cin>>a[i];
  }
 cout<<binary_search(n,a,key);

  return 0;
}
