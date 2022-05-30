#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc222/tasks/abc222_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,p;
    cin >> n >> p;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        if(a < p) ans++;
    }
    cout << ans;

	return 0;
}