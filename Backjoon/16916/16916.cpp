#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://acmicpc.net/problem/16916
vector<ll> pi;
vector<ll> ans;
void getPi(string p){
    ll pLen = p.length();
    ll j = 0;
    pi.resize(pLen);
    for(int i = 1;i<pLen;i++){
    while(j > 0 && p[i] != p[j]) 
        j = pi[j-1]; 
        if(p[i] == p[j]) 
            pi[i] = ++j;
    }
}
void KMP(string t, string p){
    getPi(p);
    ll tLen = t.length();
    ll pLen = p.length();
    ll j = 0;
    for(int i = 0 ; i < tLen ; i++){ 
        while(j>0 && t[i] != p[j]) 
        j = pi[j-1]; 
        if(t[i] == p[j]){ 
            if(j == pLen-1){ 
                ans.push_back(i-pLen+1); 
                j = pi[j]; 
            }
            else 
                j++;  
        } 
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t,p;
    getline(cin, t);
    getline(cin, p);

    KMP(t,p);

	if(ans.size()){
		cout << 1 << "\n";
	}
	else{
		cout << 0 << "\n";
	}

	return 0;
}
