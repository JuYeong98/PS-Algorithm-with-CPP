#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<int> combi;
    multimap<string, string> spy;
    int answer = 1;
    for (int i = 0; i < clothes.size(); i++)
    {
            spy.insert(pair<string, string>(clothes[i][1], clothes[i][0]));//멀티셋에 값을 넣어준다. 
    }//옷 종류는 중복가능
    multimap<string, string>::iterator iter;
    int count = 1;
    cout << "spy size" << spy.size() << endl;
    string it = "";
    for (iter = spy.begin(); iter != spy.end(); )
    {
        cout << "  iter:" << iter->first << endl;
        it = iter->first;
        iter++;
        if (it ==iter->first)//  1 1 1 2 2 3 3 3 3
        {
            count++;
        }
        else 
        {
            cout << "count : " << count<<endl;
            combi.push_back(count);
            count = 1;
        }
        
    
    }
    cout << endl;
    for (int i = 0; i < combi.size(); i++)
    {
        combi[i]++;
        answer = answer * combi[i];
    }
    answer--;
    return answer;
}