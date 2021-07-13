#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string solution(string s) {
    string answer = "";
    string tmp;
    vector<int> v1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v1.push_back(atoi(tmp.c_str()));
            tmp.clear();
        }
        else {
            tmp += s[i];
        }
    }
    v1.push_back(atoi(tmp.c_str()));
    sort(v1.begin(), v1.end(), greater<int>());
    answer += to_string(v1.back()) + " " + to_string(v1.front());
    return answer;
}