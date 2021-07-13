using namespace std;

long long solution(int w, int h) {
    long long a = 0;
    for (int i = 0; i < w; i++)
    {
        long long b = i * h;
        a = a + b / w;
    }
    return 2*a;
}

