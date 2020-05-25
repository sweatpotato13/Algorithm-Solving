#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
// https://acmicpc.net/problem/2876
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n;
	cin >> n;
	vector<ll> A(n), B(n);
	for(int i = 0;i<n;i++){
		cin >> A[i] >> B[i];
	}
	ll len= 0, grade = 0;
	for(int i = 1;i<=5;i++){
		ll temp = 0;
		for(int j = 0;j<n;j++){
			if(A[j] == i || B[j] == i){
				temp++;
			}
			else temp = 0;
			if(temp > len){
				len = temp;
				grade = i;
			}
		}
	}
	cout << len << " " << grade << "\n";

	return 0;
}