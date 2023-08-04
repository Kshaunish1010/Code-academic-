#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int x=a*2+d*2;
    if(c!=0||b!=0){
        x+=c+b-1;
    }
    if(x==(n-1)) cout<<"YES";
    else cout<<"NO";
    return 0;
}