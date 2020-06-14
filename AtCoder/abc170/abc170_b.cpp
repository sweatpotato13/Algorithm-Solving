#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc170/tasks/abc170_b
string ans[2] = {"No", "Yes"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool isAnswer = false;
    ll x,y;
    cin >> x >> y;

    if(y >= 2*x && y <= 4*x && y % 2 == 0){
        isAnswer = true;
    }

    cout << ans[isAnswer];

	return 0;
}