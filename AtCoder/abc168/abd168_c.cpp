#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://atcoder.jp/contests/abc168/tasks/abc168_c
long double getRad(long double th){
	return th * 3.14159265358979323846 / 180;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	long double ans;
	long double a,b,h,m;
	cin >> a >> b >> h >> m;
	long double temp = a*a + b*b;
	long double h_angle = h * 30;
	long double m_angle = m * 6;
	h_angle += m_angle/12;
	long double th = getRad(abs(h_angle - m_angle));
	ans = temp - 2*a*b*cos(th);
	ans = sqrt(ans);
    cout << fixed;
	cout.precision(20);
	cout << ans << "\n";


    return 0;
}