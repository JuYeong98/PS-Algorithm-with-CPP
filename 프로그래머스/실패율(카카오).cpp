#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages) {//N�� ���������� ���� 
    vector<int> answer;
    multiset<int> stage_ordered;
    multiset<int> passed_num;
    multimap<double, int,greater<int>> people_in_stage;//������ key ���� �������� ����
    int num_of_people = stages.size(); //num_of_people �� ������ �ϴ� ��� ������� �� 
    for (int i = 0; i < num_of_people; i++)
    {
        stage_ordered.insert(stages[i]); //��Ƽ�¿� �������ν� �ڵ����� ����
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
    multimap<double, int, greater<double>> people_in_stage;//������ key ���� �������� ����
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