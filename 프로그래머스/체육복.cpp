    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    using namespace std;
    vector<int> duplication(vector<int>& a, vector <int>& b) {
        vector<int>::iterator iter;
        vector<int>::iterator iter_b;
        vector<int> c = a; //a�� �� ����

        for (iter_b = b.begin(); iter_b != b.end(); iter_b++) {
            for (iter = c.begin(); iter != c.end();) {
                if (*iter == *iter_b)
                    iter = c.erase(iter); //�ߺ� ����
                else
                    iter++;
            }
        }
        return c; //��� ��ȯ
    }
    int solution(int n, vector<int> lost, vector<int> reserve) {
        int answer = 0;
        vector<int> all;
        vector<int> reserve_2;
        vector<int> lost_2;
        vector<int>::iterator it;
        vector<int> reserve_remove_lost;
        vector<int> all_remove_lost;
        reserve_2 = reserve;
        lost_2 = lost;
        for (int i = 1; i <= n; i++)
        {
            all.push_back(i);
        }  
        reserve_remove_lost = duplication(reserve_2, lost_2);
        lost = duplication(lost_2, reserve_2);
        all_remove_lost = duplication(all, lost);
        answer = all_remove_lost.size();
        for (it = reserve_remove_lost.begin(); it != reserve_remove_lost.end();it++)
        {
            auto it_a = find(all_remove_lost.begin(), all_remove_lost.end(), ((*it) - 1));
            auto it_b = find(all_remove_lost.begin(), all_remove_lost.end(), ((*it) + 1));
            cout << "*it" << *it << "  " << endl;
            
            if ((it_a== all_remove_lost.end()&&it_b== all_remove_lost.end())|| (it_a == all_remove_lost.end() && it_b != all_remove_lost.end()))//�翷�� �Ѵ� ���ų� �տ� �ִ� ���� �ڿ� �ִ� �������
            {
                if ((*it) - 1 != 0)
                    all_remove_lost.push_back((*it) - 1);
            }
            else if ((it_a != all_remove_lost.end() && it_b == all_remove_lost.end()))//�����ִ°��� ���ְ� �ڿ� ��ȣ�� �������
            {
                if((*it)!=n)
                    all_remove_lost.push_back((*it) + 1);
                
            }
        }
        answer = all_remove_lost.size();
        return answer;
    }
    int main(void)
    {

    }