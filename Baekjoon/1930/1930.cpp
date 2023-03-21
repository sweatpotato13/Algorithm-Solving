#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/1930
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
        bool isSame = false;
        vector<ll> a(4);
        vector<ll> b(4);
        for(int i = 0;i<4;i++){
            cin >> a[i];
        }
        for(int i = 0;i<4;i++){
            cin >> b[i];
        }
        ll arr[12][4] = {0,};
        for(int i = 0;i<4;i++){
            vector<ll> temp;
            if(i == 0){
                temp.push_back(b[1]);
                temp.push_back(b[2]);
                temp.push_back(b[3]);
            }
            else if(i == 1){
                temp.push_back(b[2]);
                temp.push_back(b[0]);
                temp.push_back(b[3]);
            }
            else if(i == 2){
                temp.push_back(b[0]);
                temp.push_back(b[1]);
                temp.push_back(b[3]);
            }
            else if(i == 3){
                temp.push_back(b[1]);
                temp.push_back(b[0]);
                temp.push_back(b[2]);
            }
            for(int j = 0;j<3;j++){
                arr[i*3+j][0] = b[i];
                for(int k = 1;k<=3;k++){
                    arr[i*3+j][k] = temp[k-1];
                }
                temp.insert(temp.begin(),temp[2]);
            }
        }
		for (int i = 0; i < 12; i++) {
			if (arr[i][0] != a[0])
				continue;
			if (arr[i][1]==a[1]&&arr[i][2]==a[2]&&arr[i][3]==a[3]) {
				isSame = true;
				break;
			}
		}
        cout << isSame << "\n";
    }
	return 0;
}