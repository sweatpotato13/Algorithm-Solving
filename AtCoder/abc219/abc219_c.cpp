#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc219/tasks/abc219_c
int idx[30];
bool cmp(string a, string b)
{
	for(int i = 0; i < min(a.length(), b.length()); i++)
		if(a[i] != b[i])
			return idx[a[i] - 'a'] < idx[b[i] - 'a'];
	return a.length() < b.length();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string x;
    cin >> x;
    rep(i,26){
        idx[x[i]-'a'] = i;
    }
    ll n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }
    sort(all(s), cmp);
    rep(i,n) cout << s[i] << "\n";

    return 0;
}

