#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/12761
ll a,b,n,m;
ll isVisited[100001] = {0,};
bool isAvailable(ll pt){
    if(pt >= 0 && pt <= 100000)
        return true;
    else return false;
}
void BFS(){
    ll dir[8] ={1,-1,a,b,-a,-b,a,b};
    queue<ll> q;
    q.push(n);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        if(cur == m){
            cout << isVisited[cur];
            return;
        }   
        for(int i = 0;i<8;i++){
            ll nxt;
            if(i>=6){
                nxt = cur * dir[i];
            }
            else{
                nxt = cur + dir[i];
            }
            if(isAvailable(nxt)){
                if(!isVisited[nxt]){
                    q.push(nxt);
                    isVisited[nxt] = isVisited[cur]+1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> n >> m;
    BFS();
    return 0;
}
