#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] += n;
            if (s[i]  > 90)
            {
                s[i] = s[i] - 26;
                
            }
        }
        else if (s[i] >= 97 && s[i] <= 122)
        {
            
            if (s[i] +n > 122)
            {
                s[i] = s[i] + n - 26;
            }
            else
            {
                s[i] = s[i] + n;
            }
        }
        else if (s[i] == 32)
        {

        }
    }
    return s;
}