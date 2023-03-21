#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/14425
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'a'; }
struct TrieNode {
	TrieNode* children[ALPHABETS];

	bool terminal;
	TrieNode() : terminal(false) {
		memset(children, NULL, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; ++i)
			if (children[i])
				delete children[i];
	}

	void insert(const char *key) {
		if (*key == 0)
			terminal = true;
		else {
			int next = toNumber(*key);

			if (children[next] == NULL)
				children[next] = new TrieNode;

			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char * key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	TrieNode *root = new TrieNode;
    ll n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        char s[500];
        cin >> s;
        root->insert(s);
    }
    ll ans = 0;
    for(int i = 0;i<m;i++){
        char s[500];
        cin >> s;
        TrieNode *res = root->find(s);
        if(res != NULL && res->terminal)
            ans++;
    }
    cout << ans;

	return 0;
}