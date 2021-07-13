#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
string make_small_alpha(string a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (65 <= a[i]&&a[i] <= 90) {//대문자이면
            a[i] += 32; //소문자로 만든다.
        }
    }
    return a;
}
bool is_alpha(char c)
{
    return (97 <= c && c <= 122);
}
int solution(string str1, string str2) {
    
    int answer = 0;
    str1 = make_small_alpha(str1);
    cout << "str1:" << str1 << endl;
    str2 = make_small_alpha(str2);
    cout << "str2:" << str2 << endl;
    vector<string> one;
    vector<string> one_copy;
    vector<string> two;
    vector<string> two_copy;
    string tmp = "";
    for (int i = 0; i < str1.size() - 1; i++)
    {
        tmp = "";
        if (is_alpha(str1[i]) == 0)
            continue;
        else if (is_alpha(str1[i])==1)
        {
            if (is_alpha(str1[i + 1]) == 0)
            {
                i++;
                continue;
            }
            else if (is_alpha(str1[i + 1]))
            {
                tmp += str1[i]; tmp += str1[i + 1]; one.push_back(tmp); one_copy.push_back(tmp); cout << "tmp:" << tmp << endl;
            }
        }
    }
    for (int i = 0; i < str2.size() - 1; i++)
    {
        tmp = "";
        if (is_alpha(str2[i]) == 0)
            continue;
        else if (is_alpha(str2[i]))
        {
            if (is_alpha(str2[i + 1]) == 0)
            {
                i++;
                   continue;
            }
            else if (is_alpha(str2[i + 1]))
            {
                tmp += str2[i]; tmp += str2[i + 1]; two.push_back(tmp); two_copy.push_back(tmp); 
            }
        }
    }
   
    for (int i = 0; i < two_copy.size(); i++)
        one_copy.push_back(two_copy[i]);
    sort(one_copy.begin(), one_copy.end());
    one_copy.erase(unique(one_copy.begin(), one_copy.end()), one_copy.end()); 
   
    double A=0.0, B=0.0;
    for (int i = 0; i < one_copy.size(); i++)
    {
        int a = count(one.begin(), one.end(),one_copy[i]); int b = count(two.begin(), two.end(), one_copy[i]);
        if (a >= 1&&b>=1)
        {
            if (a > b) {
                A += b;
                B += a;
            }
            else if (a == b) {
                A += a;
                B += a;
            }
            else {
                A += a;
                B += b;
            }
        }
        else if (a >= 0 && b == 0) {//one만 있는경우
            B += a;
        }
        else if (b >= 0 && a == 0) {
            B += b;
        }
    }
   
    if (A == 0 && A == B)
    {
        A = 1; B = 1;
    }
    double C = A / B;
    int result = C * 65536;
    return result;
}


