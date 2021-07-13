#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {//N은 스테이지의 개수 
    vector<int> answer;
    multiset<int> stage_ordered;
    multiset<int> passed_num;
    multimap<double, int,greater<int>> people_in_stage;//들어오는 key 값을 내림차순 정렬
    int num_of_people = stages.size(); //num_of_people 은 게임을 하는 모든 사람들의 수 
    for (int i = 0; i < num_of_people; i++)
    {
        stage_ordered.insert(stages[i]); //멀티셋에 넣음으로써 자동으로 정렬
    }

    for (int i = 1; i <= N + 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= N + 1; j++)
        {
            sum += stage_ordered.count(j);
        }
        if (i != N + 1) {
            int a = stage_ordered.count(i);
            double avg = (double)a / sum;
             cout << "avg: " << avg <<"   i:"<<i<< endl;
            people_in_stage.insert(pair<double, int>(avg, i));
        }
    }
    multimap<double, int,greater<int>>::iterator iter;
    for (iter = people_in_stage.begin(); iter != people_in_stage.end(); iter++)
    {
        cout << "first :" << (iter)->first << "  second:" << (iter)->second << endl;
        answer.push_back(iter->second);
    }
    return answer;
}

int main(void)
{
    multimap<double, int, greater<double>> people_in_stage;//들어오는 key 값을 내림차순 정렬
    people_in_stage.insert(pair<double, int>(1.125, 1));
    people_in_stage.insert(pair<double, int>(2.429, 2));
    people_in_stage.insert(pair<double, int>(2.5, 3));
    people_in_stage.insert(pair<double, int>(4.5, 4));
    people_in_stage.insert(pair<double, int>(0, 5));

    multimap<double, int, greater<int>>::iterator iter;
    vector<int> answer;
    for (iter = people_in_stage.begin(); iter != people_in_stage.end(); iter++)
    {
        cout << "first :" << (iter)->first << "  second:" << (iter)->second << endl;
        answer.push_back(iter->second);
    }
}