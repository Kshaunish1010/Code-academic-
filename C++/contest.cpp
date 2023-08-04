#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
  unordered_map<pair<int, int>, bool, hash_pair> um;
  int flag=1;
  int x=0,y=0;
  um[{x,y}]=true;
  for(int i=0;i<n;i++){
    if(s[i]=='R'){
        x++;
    }
    else if(s[i]=='L'){
        x--;
    }
    else if(s[i]=='U'){
        y++;
    }
    else if(s[i]=='D'){
        y--;
    }
    if(um[{x,y}]==true) {cout<<"YES";
    flag=0;}
    else{
        um[{x,y}]=true;
    }
  }
  if(flag)  cout<<"NO";
  return 0;
}