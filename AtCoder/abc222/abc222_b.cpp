#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://atcoder.jp/contests/abc222/tasks/abc222_a
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;
    for(int i = 0;i<4-n.length();i++){
        cout << 0;
    }
    cout << n;

	return 0;
}