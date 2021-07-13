#include <iostream>
#include <string>
#include <vector>


using namespace std;

string solution(int a, int b) {
    string answer = "";
    int sum = 0;
    for (int i = 1; i < a; i++)
    {
        switch (i) {
        case 2:
            sum += 29;
            cout <<i<<"  "<< sum << endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            sum += 30;
            cout << i << "  " << sum << endl;
            break;
        default:
            sum += 31;
            cout << i << "  " << sum << endl;
            break;
        }
    }
    sum = sum + b;
    int r;
    r = sum % 7;
    switch (r) {
    case 0:
        answer = "THU";
        break;
    case 1:
        answer = "FRI";
        break;
    case 2:
        answer = "SAT";
        break;
    case 3:
        answer = "SUN";
        break;
    case 4:
        answer = "MON";
        break;
    case 5:
        answer = "TUE";
        break;
    default:
        answer = "WED";
        break;
    }


    return answer;
}
int main(void)
{
    int a;
    int b;
    cin >> a >> b;
    cout << solution(a, b) << endl;
    return 0;
}