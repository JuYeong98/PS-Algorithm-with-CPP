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
                int k = skill_trees[i].find(skill[a]);//a��° �ε����� ��ġ
                int j = skill_trees[i].find(skill[b]);//b��° �ε����� ��ġ
               // cout << "a:" << a << "   b:" << b << endl;
                if (k == -1 && j > -1)//���ེų�� ���µ� �ڿ��� �ִ°��
                {
                    //   cout << "break 1��" << endl;
                    break;
                }
                else if ((k > -1 && j > -1) && k > j)//�� �� �ִµ� ���ེų�� �ڿ��ִٸ�
                {
                    //   cout << "break 2��" << endl;
                    break;
                }
                if (b == skill.size() - 1)//b�� ������ ���ٸ� a���� b�� a+1
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