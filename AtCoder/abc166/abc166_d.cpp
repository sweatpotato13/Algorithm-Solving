#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc166/tasks/abc166_d
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    ll a,b;
    for(a = -120;a<=120;a++){
        for(b=-120;b<=120;b++){
            if(pow(a,5) - pow(b,5) == x){
                goto EXIT;
            }
        }
    }
    EXIT:
    cout << a << " " << b;
  
	return 0;
}