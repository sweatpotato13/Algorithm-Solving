#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc168/tasks/abc168_a
string ans[3] = {"hon","pon","bon"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n;
	ll val = n % 10;
	switch(val){
		case 2:
		case 4:
		case 5:
		case 7:
		case 9:
			cout << ans[0] << "\n";
			break;
		case 0:
		case 1:
		case 6:
		case 8:
			cout << ans[1] << "\n";
			break;
		case 3:
			cout << ans[2] << "\n";
			break;
		default:
			break;
	}

    return 0;
}