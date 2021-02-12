#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> tl3;
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define tc(t) while (t--)
// https://atcoder.jp/contests/abc191/tasks/abc191_c
string board[11];
ll dir[4][2] = {{0,0},{1,0},{0,1},{1,1}};
ll h,w;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    rep(i, h){
        cin >> board[i];
    }
    ll ans = 0;
    for(int i = 0;i<h-1;i++){
        for(int j = 0;j<w-1;j++){
            ll cnt = 0;
            for(int k = 0;k<4;k++){
                if(board[i+dir[k][0]][j+dir[k][1]] == '#') 
                    cnt++;
            }
            if(cnt == 1 || cnt == 3) ans++;
        }
    }
    cout << ans;
    return 0;
}
