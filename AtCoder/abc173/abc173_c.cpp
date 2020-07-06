#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://atcoder.jp/contests/abc173/tasks/abc173_c
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll h,w,k;
    cin >> h >> w >> k;
    char c[6][6] ={0,};
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            cin >> c[i][j];
        }
    }

    ll ans=0;
    for(int R = 0;R<(1 << h);R++){
        for(int C = 0; C<(1 << w);C++){
            ll black = 0;
            for(int i = 0;i<h;i++){
                for(int j = 0;j<w;j++){
                    if((R >> i)%2==0 && (C >> j)%2 == 0 && c[i][j] == '#')
                        black++;
                }
            }
            if(black == k) ans++;
        }
    }

    cout << ans;

	return 0;
}
