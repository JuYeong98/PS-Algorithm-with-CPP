    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    #include <map>
    using namespace std;

    int solution(vector<int> priorities, int location) {
        int answer = 0;
        multimap<int, int> print;
        for (int i = 0; i < priorities.size(); i++)
        {
            print.insert(pair<int, int>(i, priorities[i]));   
        }
        multimap<int, int>::iterator iter;
    
        for (iter = print.begin(); print.size()!=0;)
        {
            if (iter->second == *max_element(priorities.begin(), priorities.end()))//가장 큰 것이라면 
            {
                //cout << "max_element:" << *max_element(priorities.begin(), priorities.end()) << endl;
                priorities.erase(max_element(priorities.begin(), priorities.end()));//가장 큰 것을 지우고
                answer++;
               // cout << "iter->first" << iter->first <<"   print_size:"<<print.size()<< endl;
                if (iter->first == location)
                {
                    break;
                }
            }
            iter++;
            if (iter == print.end())
            {
                iter = print.begin();
            }
        }
  
        return answer;
    }