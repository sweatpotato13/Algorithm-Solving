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
// https://www.acmicpc.net/problem/1976
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
    repn(i,n){
        parent[i]=i;
    }
    repn(i,n){
        repn(j,n){
            ll e;
            cin >> e;
            if(e)
                Union(i,j);
        }
    }
    ll a,b;
    cin >> a;
    b = Find(a);
    for(int i = 1;i<m;i++){
        cin >> a;
        if(b != Find(a)){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
