#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define X first
#define Y second
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://www.acmicpc.net/problem/5073
ll side[3] = {
    0,
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        cin >> side[0] >> side[1] >> side[2];
        sort(side, side+3);
        if(side[0] == 0 && side[1] == 0 && side[2] == 0) break;
        if(side[0] == side[1] && side[1] == side[2]){
            cout << "Equilateral\n";
        }
        else if(side[0] + side[1] <= side[2]){
            cout << "Invalid\n";
        }
        else if(side[0] == side[1] || side[1] == side[2]){
            cout << "Isosceles\n";
        }
        else{
            cout << "Scalene\n";
        }
    }

    return 0;
}