#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc172/tasks/abc172_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a;
    cin >> a;
    cout << a + pow(a,2) + pow(a,3);

	return 0;
}