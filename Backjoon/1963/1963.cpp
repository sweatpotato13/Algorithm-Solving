#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1963
ll che[101010] ={0,};
bool isVisited[101010] = {0,};
void getChe(ll num) {
    for (int i = 2; i <= num; i++) {
        che[i] = i;
    }
    for (int i = 2; i <= num; i++) { 
        if (che[i] == 0) 
            continue;
        for (int j = i + i; j <= num; j += i) {
            che[j] = 0;
        }
    }
}
ll after(ll og, ll b, ll d){
    ll res;
    ll aa = og/1000;
    ll bb = (og/100)%10;
    ll cc = (og/10)%10;
    ll dd = og%10;
    if(d == 0){
        res = aa*1000 + bb*100 + cc*10 + b;
    }
    else if(d == 1){
        res = aa*1000 + bb*100 + b*10 + dd;
    }
    else if(d == 2){
        res = aa*1000 + b*100 + cc*10 + dd;
    }
    else{
        if(b == 0) res = 0;
        else res = b*1000 + bb*100 + cc*10 + dd;
    }
    return res;
}
ll BFS(ll s, ll e){
    ll ans = -1;
    queue<pll> q;
    q.push({s,0});
    isVisited[s] = true;
    while(!q.empty()){
        ll cur = q.front().first;
        ll cnt = q.front().second;
        q.pop();
        if(cur == e){
            ans = cnt;
            break;
        }
        for(int i = 0;i<4;i++){
            for(int j = 0;j<10;j++){
                ll next = after(cur,j,i);
                if(che[next] && cur != next && !isVisited[next]){
                    isVisited[next] = true;
                    q.push({next,cnt+1});
                }
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    getChe(10101);
    ll t;
    cin >> t;
    while(t--){
        memset(isVisited,0,sizeof(isVisited));
        ll s,e;
        cin >> s >> e;
        if(s == e) {
            cout << 0 << "\n";
            continue;
        }
        ll ans = 0; 
        ans = BFS(s,e);
        if(ans == -1) cout << "Impossible\n";
        else cout << ans << "\n";
    }

    return 0;
}
