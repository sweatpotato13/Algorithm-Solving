#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc196/tasks/abc196_e
const ll INF = numeric_limits<ll>::max() / 4;
void chmin(ll& a, ll b){ if(a > b) a = b; }
void chmax(ll& a, ll b){ if(a < b) a = b; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    ll low = -INF, high = INF, add = 0;
    for(ll i = 0; i < N; i++){
        ll A, T;
        cin >> A >> T;
        if(T == 1){
            low += A;
            high += A;
            add += A;
        }
        else if(T == 2){
            chmax(low, A);
            chmax(high, A);
        }
        else{
            chmin(low, A);
            chmin(high, A);
        }
    }
    ll Q;
    cin >> Q;
    for(ll i = 0; i < Q; i++){
        ll x;
        cin >> x;
        cout << clamp(x + add, low, high) << '\n';
    }

    return 0;
}
