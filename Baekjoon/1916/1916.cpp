#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1916
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<pll> v[1001];
ll cost[1001] = {0,};
void dijkstra(ll s){
    pq.push(s);
    cost[s] = 0;
    while(!pq.empty()){
        ll cur = pq.top();
        pq.pop();
        for(int i = 0;i<v[cur].size();i++){
            if(cost[cur] + v[cur][i].first < cost[v[cur][i].second]){
                cost[v[cur][i].second] = cost[cur] + v[cur][i].first;
                pq.push(v[cur][i].second);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    fill_n(cost,1001,INT_MAX);
    for(int i = 0;i<m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    ll s,e;
    cin >> s >> e;
    dijkstra(s);
    cout << cost[e];

    return 0;
}


