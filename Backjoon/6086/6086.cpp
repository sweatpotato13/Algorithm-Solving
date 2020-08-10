#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/6086
ll capa[52][52] = {0,};
ll flow[52][52] = {0,};
vector<ll> adj[52];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
        char s,e;
        ll v;
        cin >> s >> e >> v;
        if('A' <= s && s <= 'Z')
            s = s - 'A';
        else s = s - 'a' + 26;
        if('A' <= e && e <= 'Z')
            e = e - 'A';
        else e = e - 'a' + 26;
        capa[s][e] += v;
        capa[e][s] += v;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    ll ans = 0;
    ll s = 0, t =  'Z'-'A';
    while(1){
        ll prev[52];
        memset(prev,-1,sizeof(prev));
        queue<ll> q;
        q.push(s);
        while(!q.empty()){
            ll cur = q.front();
            q.pop();
            for(int i = 0;i<adj[cur].size();i++){
                ll next = adj[cur][i];
                if(prev[next] != -1){
                    continue;
                }
                if(capa[cur][next] - flow[cur][next] > 0){
                    q.push(next);
                    prev[next] = cur;
                    if(next == t) break;
                }
            }
        }
        if(prev[t] == -1) break;
        ll f = INT_MAX;
        for(int i = t;i != s;i = prev[i]){
            f = min(f, capa[prev[i]][i] - flow[prev[i]][i]);
        }
        for(int i = t;i!=s;i=prev[i]){
            flow[prev[i]][i] += f;
            flow[i][prev[i]] -= f;
        }
        ans += f;
    }
    cout << ans;
    return 0;
}
