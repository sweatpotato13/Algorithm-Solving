#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// http://codeforces.com/problemset/problem/263/A
ll mat[5][5] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ans = 0;
    pll point = {0,0};
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin >> mat[i][j];
            if(mat[i][j]){
                point = {i,j};
            }
        }
    }

    ans = abs(point.first - 2) + abs(point.second - 2);
    cout << ans;

	return 0;

}