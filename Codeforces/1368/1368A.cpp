#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://codeforces.com/problemset/problem/1368/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        ll ans = 1;
        ll a,b,n;
        cin >> a >> b >> n;
		if(a>b)
		{
			swap(a,b);
		}
		if(a+b > n)
		{
			cout<<1<<'\n';
			continue;
		}
		ll a0 = b,a1 = a+b;
		while(a1 <= n)
		{
			ans++;
			swap(a0,a1);
			a1+=a0;
		}
        cout << ans << "\n";
    }

	return 0;
}