#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc172/tasks/abc172_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans += (n/i) * (n/i+1) * i/2;
    }
    cout << ans;

	return 0;
}