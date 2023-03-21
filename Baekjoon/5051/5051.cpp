#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/5051
typedef complex<double> base;
void fft(vector<base> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * acos(-1) / len * (invert ? -1 : 1);
    base wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      base w(1);
      for (int j = 0; j < len / 2; j++) {
        base u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (int i = 0; i < n; i++) a[i] /= n;
  }
}

void multiply(const vector<ll> &a, const vector<ll> &b, vector<ll> &res) {
  vector<base> fa(a.begin(),a.end()), fb(b.begin(),b.end());
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  res.resize(n);
  for (int i = 0; i < n; i++)
    res[i] = ll(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	vector<ll> rem(2*n);
	for(ll i = 1;i<n;i++){
		rem[i*i%n]++;
	}
	vector<ll> tmp(2*n);
	for(ll i = n;i<2*n;i++){
		rem[i] = rem[i-n];
		tmp[i-n] = rem[i];
	}
	vector<ll> ret;
	multiply(rem,tmp,ret);
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		ans += rem[i]*ret[i+n];
		ans += rem[i]*rem[2*i%n];
	}
	cout << ans/2 << "\n";
	return 0;
}