#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/1865
vector<pair<ll,ll>> v[501];
ll dist[501] ={0,};
bool isAnswer = false;
void Bellman_Ford(ll n){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(auto k:v[j]){
                if (dist[k.first] > dist[j] + k.second){
                    dist[k.first] = dist[j] + k.second;
                    if(i == n) isAnswer = true;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll t;
    cin >> t;
    while(t--){
        isAnswer = false;
        ll n,m,w;
        cin >> n >> m >> w;
        for(ll i = 0;i<501;i++){
            dist[i] = INT_MAX;
            v[i].clear();
        }
        ll s,e,t;
        while(m--){
            cin >> s >> e >> t;
            v[s].push_back(make_pair(e,t));
            v[e].push_back(make_pair(s,t));
        }
        while(w--){
            cin >> s >> e >> t;
            v[s].push_back(make_pair(e,-t));
        }
        dist[1] = 0;
        Bellman_Ford(n);
        if(isAnswer) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
	return 0;

}
