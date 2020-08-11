#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/11377
ll isVisited[1001] = {0,};
ll room[1001] = {0,};
vector<ll> v[1001];
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

    ll n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i<=n;i++){
        ll e;
        cin >> e;
        for(int j = 0;j<e;j++){
            ll s;
            cin >> s;
            v[i].push_back(s);
        }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        memset(isVisited,0,sizeof(isVisited));
        if(dfs(i)) {
            ans++;
        }
    }

    ll cnt = 0;
    for (int i = 1;i<=n;i++) {
        memset(isVisited, 0, sizeof(isVisited));
        if (dfs(i)) {
            ans++;
            cnt++;
        }
        if(cnt == k) break;
    }
    cout << ans;


    return 0;
}
