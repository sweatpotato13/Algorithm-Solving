#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/1043
ll parent[1000001];
ll Find(ll x){

	if(x == parent[x]){
		return x;
	}
	else{
		ll y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}
void Union(ll x, ll y){
	x = Find(x);
	y = Find(y);
	parent[y] = x;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    ll k;
    cin >> k;
    vll know(k);
    repn(i,n) parent[i] = i;
    rep(i,k) cin >> know[i];
    vector<vll> v(51);
    rep(i,m){
        ll e;
        cin >> e;
        ll curr, prev;
        rep(j,e){
            if(j >= 1){
                prev = curr;
                cin >> curr;
                Union(prev,curr);
            }
            else cin >> curr;
            v[i].push_back(curr);
        }
    }
    for(auto k : v){
        bool flag = false;
        for(auto l : k){
            if(flag) break;
            for(auto q : know){
                if(Find(l) == Find(q)){
                    flag = true;
                    break;
                }
            }
        }
        if (flag) m--;
    }
    cout << m;
    return 0;
}
