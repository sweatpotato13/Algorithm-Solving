#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/1298
ll isVisited[101] = {0,};
ll room[101] = {0,};
vector<ll> v[101];
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
    for(int i = 1;i<=m;i++){
        ll s,e;
        cin >> s >> e;
        v[s].push_back(e);
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
