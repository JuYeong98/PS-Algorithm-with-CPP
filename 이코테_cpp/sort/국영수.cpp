#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Person{
public:
    string name;
    int kor, eng, math;
};

bool cmp(const Person &u, const Person &v){
    return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}

int main()
{
    int N;
    cin >> N;

    vector<Person> vec(N);

    for (int i = 0; i < N; i++)
        cin >> vec[i].name >> vec[i].kor >> vec[i].eng >> vec[i].math;

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << vec[i].name << "\n";
}