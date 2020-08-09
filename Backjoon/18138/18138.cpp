#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/18138
ll isVisited[201] = {0,};
ll room[201] = {0,};
vector<ll> v[201];
bool dfs(ll n){
    if(isVisited[n]){
        return false;
    }
    else{
        isVisited[n]++;
        for(auto k : v[n]){
            if(!room[k]|| dfs(room[k])){
                room[k] = n;
                return true;
            }
        }
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    vector<ll> shirt(n+1);
    vector<ll> kara(m+1);
    for(int i = 1;i<=n;i++){
        cin >> shirt[i];
    }
    for(int i = 1;i<=m;i++){
        cin >> kara[i];
    }
    for(int i = 1;i<=n;i++){
        ld w = shirt[i] * 1.0;
        ld w2 = w * 0.5;
        ld w34 = w * 0.75;
        ld w54 = w * 1.25;
        for(int j = 1;j<=m;j++){
            ld k = kara[j] * 1.0;
            if((w2 <= k && k <= w34) || (w <= k && k <= w54)){
                v[i].push_back(j);
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        memset(isVisited,0,sizeof(isVisited));
        if(dfs(i)) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
