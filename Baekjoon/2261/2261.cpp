#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://www.acmicpc.net/problem/2261
vector<pll> v;
ll getSqr(ll a){
	return a*a;
}
ll getDist(pll a, pll b){
	return getSqr(a.first-b.first) + getSqr(a.second-b.second);
}
bool cmp(pll a, pll b) {
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}
ll getMin(ll s, ll e) {
    if (e - s == 1)
        return 1e9;
    int m = (s + e) / 2;
    ll d = min(getMin(s, m), getMin(m, e));
    vector<pll> p; 
    for (int i = s; i < e; i++) {
        if (getSqr(v[i].first -  v[m].first) <= d)
            p.push_back(v[i]);
    }
    sort(p.begin(), p.end(), cmp); 
    for (int i = 0; i < p.size(); i++) {
        for (int j = i + 1; j < p.size() && j < i + 7; j++) { 
            d = min(d, getDist(p[i], p[j])); 
        }
    }
    return d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n;
	v.resize(n);
	for(int i = 0;i<n;i++){
		ll s,e;
		cin >> s >> e;
		v[i] = {s,e};
	}
	sort(all(v));
	cout << getMin(0,n);

    return 0;
}