// AUTHOR: Rodchananat Khunakornophat
#include <bits/stdc++.h>
using namespace std;
int tmp,n,i=0;
map<int,int> p;
long long ans=0;
int main(){
    cin>>n;
    for (;i<n;++i){
        cin>>tmp;
        p[tmp] = i;
    }
    i=0;
    for (auto v:p){
        cout << v.first << "," << v.second << "\n";
        ans+=abs(v.second-i);
        ++i;
    }
    cout<<ans;
    return 0;
}