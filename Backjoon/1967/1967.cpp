#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://acmicpc.net/problem/1967
vector<pair<ll,ll>> v[10001];
ll dist[10001]={0,};
bool isVisited[10001]={0,};
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
        maxValue = cost;
    }
    isVisited[start] = false;
}
void Bellman_Ford(ll n){
    ll maxV = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(auto k:v[j]){
                if (dist[k.first] > dist[j] + k.second){
                    dist[k.first] = dist[j] + k.second;
                    if(dist[k.first] > maxV){
                        maxV = dist[k.first];
                        maxNode = k.first;
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for(int i = 0;i<n-1;i++){
        ll s,e,t;
        cin >> s >> e >> t;
        v[s].push_back(make_pair(e,t));
        v[e].push_back(make_pair(s,t));
    }
    init(n);
    dist[1] = 0;
    Bellman_Ford(n);
    DFS(maxNode,0);
    cout << maxValue << "\n";
	return 0;

}
