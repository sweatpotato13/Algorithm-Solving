#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto k : arr){
        answer += (double)k;
    }
    answer /= arr.size();
    return answer;
}
