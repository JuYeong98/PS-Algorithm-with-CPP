    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    using namespace std;
    vector<int> duplication(vector<int>& a, vector <int>& b) {
        vector<int>::iterator iter;
        vector<int>::iterator iter_b;
        vector<int> c = a; //a의 값 복사

        for (iter_b = b.begin(); iter_b != b.end(); iter_b++) {
            for (iter = c.begin(); iter != c.end();) {
                if (*iter == *iter_b)
                    iter = c.erase(iter); //중복 제거
                else
                    iter++;
            }
        }
        return c; //결과 반환
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
            
            if ((it_a== all_remove_lost.end()&&it_b== all_remove_lost.end())|| (it_a == all_remove_lost.end() && it_b != all_remove_lost.end()))//양옆에 둘다 없거나 앞에 애는 없고 뒤에 애는 있을경우
            {
                if ((*it) - 1 != 0)
                    all_remove_lost.push_back((*it) - 1);
            }
            else if ((it_a != all_remove_lost.end() && it_b == all_remove_lost.end()))//전에있는것은 차있고 뒤에 번호는 비어있음
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