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
// https://www.acmicpc.net/problem/1446
priority_queue<ll, vector<ll>, greater<ll>> pq;
vector<pll> v[10001];
ll cost[10001] = {0,};
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

    ll n,d;
    cin >> n >> d;
    for(int i = 0;i<n;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    for(int i = 0;i<=d;i++){
        v[i].push_back({1,i+1});
    }
    fill_n(cost,10001,INT_MAX);
    dijkstra(0);
    cout << cost[d];

    return 0;
}


