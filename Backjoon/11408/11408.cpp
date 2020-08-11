#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11408
ll c[888][888] ={0,};
ll f[888][888] ={0,};
ll d[888][888] ={0,};
vector<ll> adj[888];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    ll s = 810, t = 820;
    for(int i = 1;i<=n;i++){
        c[s][i] = 1;
        adj[i].push_back(s);
        adj[s].push_back(i);
    }
    for(int i = 1;i<=m;i++){
        c[i+400][t] = 1;
        adj[i+400].push_back(t);
        adj[t].push_back(i+400);
    }
    for(int i = 1;i<=n;i++){
        ll p;
        cin >> p;
        while(p--){
            ll nm,co;
            cin >> nm >> co;
            adj[i].push_back(nm+400);
            adj[nm+400].push_back(i);
            d[i][nm+400] = co;
            d[nm+400][i] = -co;
            c[i][nm+400] = 1;
        }
    }
    ll ansCnt = 0;
    ll ansCost = 0;
    while (1)
    {
        ll prev[888], dist[888];
        bool isVisited[888] = { 0 };
        queue<int> q;
        fill(prev, prev + 888, -1);
        fill(dist, dist + 888, INT_MAX);
        dist[s] = 0;
        isVisited[s] = true;
        q.push(s);
        while (!q.empty())
        {
            ll cur = q.front();
            q.pop();
            isVisited[cur] = false;
            for (int i = 0; i < adj[cur].size(); i++){
                ll next = adj[cur][i];
                if (c[cur][next] - f[cur][next] > 0 && dist[next] > dist[cur] + d[cur][next]){
                    dist[next] = dist[cur] + d[cur][next];
                    prev[next] = cur;
                    if (!isVisited[next]){
                        q.push(next);
                        isVisited[next] = true;
                    }
                }
            }
        }
        if (prev[t] == -1)
            break;
        ll flow = INT_MAX;
        for (int i = t; i != s; i = prev[i])
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        for (int i = t; i != s; i = prev[i]){
            ansCost += flow * d[prev[i]][i];
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        ansCnt++;
    }
    cout << ansCnt << "\n" << ansCost;
    return 0;
}
