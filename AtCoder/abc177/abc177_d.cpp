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
// https://atcoder.jp/contests/abc177/tasks/abc177_d
ll fa[212121];
ll sz[212121];
void init(ll n){
    for(int i = 0;i<n;i++){
        fa[i] = i;
        sz[i] = 1;
    }
}
ll find(ll x){
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(ll x, ll y){
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (sz[x] < sz[y])
        swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    init(n+1);
    for(int i = 0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        merge(a,b);
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        if(fa[i] == i) ans = max(ans,sz[i]);
    }
    cout << ans;

    return 0;
}