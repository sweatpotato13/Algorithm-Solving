#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
// https://codeforces.com/problemset/problem/61/A
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b;
    cin >> a >> b;
    for(int i = 0;i<a.length();i++){
        ll temp = (a[i]-'0') ^ (b[i]-'0');
        cout << temp;
    } 
	return 0;

}