#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/16480
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll R,r;
    cin >> R >> r;
    // https://en.wikipedia.org/wiki/Euler%27s_theorem_in_geometry
    cout << (R*R) - (2*R*r);


	return 0;
}
