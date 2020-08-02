#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);
    answer[0] = x;
    for(int i = 1;i<n;i++){
        answer[i] = answer[0] * (i+1);
    }
    return answer;
}
