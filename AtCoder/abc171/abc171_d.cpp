#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc171/tasks/abc171_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll sum = 0;
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll,ll> m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        sum += a[i];
        m[a[i]]++;
    }
    ll q;
    cin >> q;
    vector<ll> b(q), c(q);
    for(int i = 0;i<q;i++){
        cin >> b[i] >> c[i];
    }

    for(int i = 0;i<q;i++){
        ll diff = c[i] - b[i];
        ll cnt = m[b[i]];
        m[c[i]] += m[b[i]];
        m[b[i]] = 0;
        sum += (diff * cnt);
        cout << sum << "\n";
    }    
	return 0;
}
