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
// https://www.acmicpc.net/problem/14490
ll strToll(string s){
	ll res = 0;
	ll tens = 1;
	reverse(all(s));
	for(auto k : s){
		res += (k-'0')*tens;
		tens *= 10;
	}
	return res;
}
ll gcd(ll a, ll b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	else return gcd(b, a%b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	string s;
	cin >> s;
	ll a, b;
	string temp = "";
	for(auto k : s){
		if(k != ':') temp += k;
		else{
			a = strToll(temp);
			temp = "";
		}
	}
    b = strToll(temp);
	ll g = gcd(a,b);
	cout << a/g << ":" << b/g;
	
}
