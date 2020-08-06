#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll,ll,ll> tl3;
// https://www.acmicpc.net/problem/12515
ll formingMagicSquare(vector<vector<ll>> s) {
    int all[8][3][3]  = {{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
                    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
                    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
                    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
                    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
                    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
                    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
                    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}};
        
    ll ans = INT_MAX;
    for(int i = 0;i<8;i++){
        ll temp = 0;
        for(int x = 0;x<3;x++){
            for(int y = 0;y<3;y++){
                temp += abs(all[i][x][y] - s[x][y]);
            }
        }
        ans = min(temp, ans);
    }

    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);
        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
    }
    ll result = formingMagicSquare(s);
    cout << result << "\n";


    return 0;
}
