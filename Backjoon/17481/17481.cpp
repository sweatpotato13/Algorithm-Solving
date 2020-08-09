#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/17481
ll isVisited[1010] = {0,};
ll room[1010] = {0,};
vector<ll> v[1010];
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

    ll n, m;
    cin >> n >> m;
    map<string, ll> ma;
    for(int i = 1;i<=m;i++){
        string s;
        cin >> s;
        ma[s] = i;
    }
    for(int i = 1;i<=n;i++){
        ll k;
        cin >> k;
        for(int j = 0;j<k;j++){
            string s;
            cin >> s;
            v[i].push_back(ma[s]);
        }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        memset(isVisited,0,sizeof(isVisited));
        if(dfs(i)) {
            ans++;
        }
    }
    if(ans == n) cout << "YES";
    else{
        cout << "NO\n";
        cout << ans;
    }

    return 0;
}
