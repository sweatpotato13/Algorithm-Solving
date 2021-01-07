#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// http://codeforces.com/problemset/problem/266/B
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int i = 0;i<t;i++){
        for(int j = 0;j<n-1;j++){
            if(s[j] == 'B' && s[j+1] == 'G'){
                swap(s[j],s[j+1]);
                j++;
            }
        }
    }
    cout << s << "\n";

	return 0;
}