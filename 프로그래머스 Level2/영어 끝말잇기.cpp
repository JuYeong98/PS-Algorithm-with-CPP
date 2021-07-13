#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int num = words.size() / n;
    if (num * n != words.size())
        num++;
    int order = 0;
    cout << "num:" << num << endl;
    vector<vector<string>> people(n, vector<string>(num, " "));
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < n&&order<words.size(); j++)
        {
            people[j][i] = words[order];
            auto it = find(words.begin(), words.end(), words[order]);
            int index = distance(words.begin(), it);
            cout << "it:" << *it << " index: " << index << endl;
            if (index !=order)
            {
                int a = (order + 1) % n;
                if (a == 0)
                    a = n;
                int b = (order + 1) / n;
                if (b * n != order + 1)
                    b++;
                answer.push_back(a);
                answer.push_back(b);
                return answer;
            }
            if (order == words.size()-1)
            {
                answer.push_back(0);
                answer.push_back(0);
                return answer;
            }
            string first = words[order];
            order++;
            string second = words[order];
            if (first[first.size() - 1] != second[0])
            {
                int a = (order+1) % n;
                if (a == 0)
                    a = n;
                int b = (order + 1) / n;
                if (b * n != order + 1)
                    b++;
                answer.push_back(a);
                answer.push_back(b);
                return answer;
            }
        }
    }
    return answer;
}