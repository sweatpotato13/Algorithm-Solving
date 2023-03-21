#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://www.acmicpc.net/problem/1067
const double PI = acos(-1);
typedef complex<double> cpx;
void FFT(vector<cpx> &f, cpx w){
	ll n = f.size();
	if(n == 1) return ;
	vector<cpx> even(n/2), odd(n/2);
	for(int i = 0;i<n;i++){
		if(i%2 == 0) even[i/2] = f[i];
		else odd[i/2] = f[i];
	}
	FFT(even, w*w);
	FFT(odd, w*w);
	cpx wp(1,0);
	for(int i = 0;i<n/2;i++){
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}
vector<cpx> multiply(vector<ll> A, vector<ll> B){
	vector<cpx> a(all(A));
	vector<cpx> b(all(B));
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);
 
    cpx w(cos(2*PI/n), sin(2*PI/n));
 
    FFT(a, w);
    FFT(b, w);
 
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
 
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	vector<ll> a(2*n),b(n);
	for(int i = 0;i<n;i++){
		ll e;
		cin >> e;
		a[i] = a[i+n] = e;
	}
	for(int i = 0;i<n;i++){
		cin >> b[i];
	}
	reverse(all(b));
	ll res = 0;
	vector<cpx> ans = multiply(a,b);
	for(int i = 0;i<sz(ans);i++){
		if(res < round(ans[i].real())){
			res = round(ans[i].real());
		}
	}
	cout << res << "\n";
	return 0;
}