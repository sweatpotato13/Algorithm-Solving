#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/16953
map<ll,ll> m;
ll a,b;
void BFS(){
    queue<ll> q;
    q.push(a);
    while(!q.empty()){
        ll e = q.front();
        q.pop();
        if(e > b){
            continue;
        }
        q.push(e*2);
        m[e*2] = m[e] + 1; 
        q.push(e*10+1);
        m[e*10+1] = m[e] + 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;
    m[a] = 1;
    m[b] = -1;
    BFS();
    cout << m[b] << "\n";

    return 0;
}
