#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/4358
const int MAXCHAR = 96;
int toNumber(const char c){ return c - 32;}
struct TrieNode{
    int cnt;
    bool terminal;
    struct TrieNode* children[MAXCHAR];
    TrieNode() : terminal(false), cnt(1){
        memset(children, 0, sizeof(children));
    }
    ~TrieNode(){
        for(int i = 0;i < MAXCHAR;i++) {
            if(children[i])
                delete children[i];
        }
    }
    void insert(const char* key){
        if((*key) == 0) terminal = true;
        else{
            int next = toNumber(*key);
            if(children[next] == NULL){
                children[next] = new struct TrieNode();
            }
            children[next]->insert(key+1);
        }
    }
    TrieNode* find(const char* key){
        if(*key == 0) return this;
        int next = toNumber(*key);
        if(children[next] == NULL) return NULL;
        return children[next]->find(key+1);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	TrieNode *root = new TrieNode;
    TrieNode *isExist;
    ll cnt = 0;
    vector<string> v;
    char s[32];
    while(!cin.getline(s,31).eof()){
        cnt++;
        if((isExist = root->find(s)) == NULL){
            v.push_back(s);
            root->insert(s);
        }
        else{
            isExist->cnt++;
        }
    }
    cout<<fixed;
    cout.precision(4);
    sort(all(v));
	
    for(int i = 0;i<v.size();i++){
        isExist = root->find(v[i].c_str());
        cout << v[i] << " " << ((ld)isExist->cnt / (ld)cnt) * 100 << "\n";
    }


	return 0;
}