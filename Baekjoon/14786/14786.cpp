#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/14786
double a,b,c;
double f(double x) {
	return a*x + b*sin(x)-c;
}
double fp(double x) {
	return (a + b*cos(x));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	// https://en.wikipedia.org/wiki/Newton%27s_method
	ll cnt = 100000;
	double x0, x1;
	cin >> a >> b >> c;
	x0 = 1;
	while(cnt--){
		x1 = x0;
		x0 = x1 - (f(x1) / fp(x1));
	}
	cout.precision(19);
	cout << x0 << "\n";
    return 0;
}
