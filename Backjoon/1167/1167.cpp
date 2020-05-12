#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/1167
vector<pair<ll,ll>> v[100001];
ll dist[100001]={0,};
bool isVisited[100001]={0,};
ll maxValue = 0;
ll maxNode = 0;
void init(ll n){
    for(int i = 0;i<=n;i++){
        dist[i] = INT_MAX;
    }
}
void DFS(ll start, ll cost){
    isVisited[start] = true;
    for(int i = 0;i<v[start].size();i++){
        pair<ll,ll> p = v[start][i];
        if(!isVisited[p.first]){
            isVisited[p.first] = true;
            DFS(p.first, cost + p.second);
            isVisited[p.first] = false;
        }
    }
    if(cost > maxValue){
        maxNode = start;
        maxValue = cost;
    }
    isVisited[start] = false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
        ll s,e,w;
        cin >> s;
        cin >> e;
        while(e != -1){
            cin >> w;
            v[s].push_back({e,w});
            cin >> e;
        }
    }
    init(n);
    dist[1] = 0;
    DFS(1,0);
    DFS(maxNode,0);
    cout << maxValue << "\n";
	return 0;

}
