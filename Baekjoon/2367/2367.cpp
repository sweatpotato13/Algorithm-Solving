#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/2367
ll capa[303][303] = {0,};
ll flow[303][303] = {0,};
ll arr[101] = {0,};
vector<ll> adj[303];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, d;
    cin >> n >> k >> d;
    for(int i = 0;i<d;i++){
        cin >> arr[i];
    }
    for(int i = 2;i<n+2;i++){
        capa[0][i] += k;
        adj[0].push_back(i);
        adj[i].push_back(0);
        ll tt;
        cin >> tt;
        for(int j = 0;j<tt;j++){
            ll a;
            cin >> a;
            capa[i][a+n+1] += 1;
            adj[i].push_back(a+n+1);
            adj[a+n+1].push_back(i);
        }
    }
    ll ans = 0;
    ll s = 0, t =  1;
    for(int i = n+2;i<n+2+d;i++){
        capa[i][t] += arr[i-n-2];
        adj[i].push_back(t);
        adj[t].push_back(i);
    }
    while(1){
        ll prev[303];
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
