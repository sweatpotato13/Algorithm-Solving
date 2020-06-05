#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc167/tasks/abc167_b
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b,c,k;
    cin >> a >> b >> c >> k;

    if(k < a){
        cout << k;
    }
    else if(k >= a && k <= a+b){
        cout << a;
    }
    else{
        cout << a - (k-(a+b));
    }

	return 0;

}