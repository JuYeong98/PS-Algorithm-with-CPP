#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int a = 0;
    int b = a+1;
    vector<int> vec;
    cout << vec.size();
    if (skill.size() == 1)
    {
        for (int i = 0; i < skill_trees.size(); i++)
        {
            if (skill_trees[i].find(skill[0]) != -1)
                answer++;
        }
    }
    else if(skill.size()>=2){
        for (int i = 0; i < skill_trees.size(); i++)
        {
            a = 0;
            b = a + 1;
            //cout << "i:" << i << endl;
            while (1)
            {
                int k = skill_trees[i].find(skill[a]);//a번째 인덱스의 위치
                int j = skill_trees[i].find(skill[b]);//b번째 인덱스의 위치
               // cout << "a:" << a << "   b:" << b << endl;
                if (k == -1 && j > -1)//선행스킬이 없는데 뒤에가 있는경우
                {
                    //   cout << "break 1번" << endl;
                    break;
                }
                else if ((k > -1 && j > -1) && k > j)//둘 다 있는데 선행스킬이 뒤에있다면
                {
                    //   cout << "break 2번" << endl;
                    break;
                }
                if (b == skill.size() - 1)//b가 끝까지 간다면 a증가 b는 a+1
                {
                    a++;
                    b = a + 1;
                    if (a == skill.size() - 1)
                    {
                        answer++;
                        break;
                    }
                }
                else
                    b++;
            }
        }
    }

    return answer;
}