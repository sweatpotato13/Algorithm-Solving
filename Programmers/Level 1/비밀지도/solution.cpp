#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<vector<int>> v1(n,vector<int>(n));
    vector<vector<int>> v2(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        int temp = arr1[i];
        for(int j = n-1;j>=0;j--){
            int val = temp % 2;
            v1[i][j] = val;
            temp/=2;
        }
        temp = arr2[i];
        for(int j = n-1;j>=0;j--){
            int val = temp % 2;
            v2[i][j] = val;
            temp/=2;
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(v1[i][j] == 0 && v2[i][j] == 0){
                answer[i] += ' ';
            }
            else
                answer[i] += "#";
        }
    }
    return answer;
}