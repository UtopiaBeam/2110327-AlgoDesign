// AUTHOR: Rodchananat Khunakornophat
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int, int> pii;

priority_queue<pii> pq;



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> t(n); // initial size = n
    for (int i=0; i<n; i++){
        cin >> t[i];
        pq.push(pii{0, i});
    }  
    while (m--){
        pii next = pq.top();
        pq.pop();
        cout << -next.first << '\n';
        pq.push(pii{next.first-t[next.second], next.second});
    }
    return 0;
}