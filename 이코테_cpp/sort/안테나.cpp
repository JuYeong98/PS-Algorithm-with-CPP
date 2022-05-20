#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
bool compare(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}

int main(void){
    vector<int> houses;
    vector<int> dis;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int input;
        cin>>input;
        houses.push_back(input);
        dis.push_back(input);
    }
    sort(houses.begin(), houses.end());
    houses.erase(unique(houses.begin(), houses.end(),houses.end()));
    vector<pair<int, int>> total;
    int sum= 0 ;
    for(int i = 0; i<houses.size();i++){
        for(int j=0;j<dis.size();j++){
            sum += abs(houses[i]-dis[j]);
        }
        total.push_back({houses[i],sum});
        sum = 0;
    }
    // sort(total.begin(), total.end()), compare);

}