#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/11725
char tree[26][2] = {0,};
void preorder(char n){
	if(n == '.') return;
	cout << n;
	preorder(tree[n-'A'][0]);
	preorder(tree[n-'A'][1]);
}
void inorder(char n){
	if(n == '.') return;
	inorder(tree[n-'A'][0]);
	cout << n;
	inorder(tree[n-'A'][1]);
}
void postorder(char n){
	if(n == '.') return;
	postorder(tree[n-'A'][0]);
	postorder(tree[n-'A'][1]);
	cout << n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	ll n;
	cin >> n;
	for(int i = 0;i<n;i++){
		char c,l,r;
		cin >> c >> l >> r;
		tree[c-'A'][0] = l;
		tree[c-'A'][1] = r;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

    return 0;
}