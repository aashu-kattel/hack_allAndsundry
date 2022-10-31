#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   string putStar(int j, string s){
      string temp = "";
      for(int i = 0; i < s.size(); i++){
         if(i == j)temp += "*";
         else temp += s[i];
      }
      return temp;
   }
   int ladderLength(string b, string e, vector<string>& w) {
      if(find(w.begin(), w.end(), e) == w.end() || !b.size() || !e.size() || !w.size())return 0;
      map < string , vector <string> > m;
      for(int i = 0; i < w.size(); i++){
         string x = w[i];
         for(int j = 0; j < x.size(); j++){
            string inter = putStar(j,x);
            m[inter].push_back(x);
         }
      }
      queue < pair <string, int> > q;
      q.push({b, 1});
      map <string, int> visited;
      while(!q.empty()){
         pair < string, int > s = q.front();
         q.pop();
         string x = s.first;
         int l = s.second;
         for(int i = 0; i < x.size(); i++){
            string temp = putStar(i ,x);
            for(int j = 0; j < m[temp].size(); j++){
               string aa = m[temp][j];
               if(aa == e)return l+1;
               if(!visited[aa]){
                  q.push({aa, l+1});
                  visited[aa] = 1;
               }
            }
         }
      }
      int level = 0;
      return 0;
   }
};
main(){
   vector<string> v = {"hot","dot","dog","lot","log","cog"};
   Solution ob;
   cout << (ob.ladderLength("hit", "cog", v));
}
