#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[300001];
vector<int> graph[300001];
vector<pair<int, int>> answer[300001]; 


bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.second < b.second;
	}
}
int travel(int start , int distance, int weighted){
    answer[start].push_back({distance , weighted});
    if(distance==0){
        //cout<<"end :"<<start<<"  distance :"<<weighted<<endl;
        return 0;
    }
    int count = graph[start].size();
    for(int i=0;i<count; i++){
        travel(graph[start][i] , distance-1, weighted + 1);
    }
    return 0;
}


int main(void){
    vector<int> solution;
    int N , M , K , X;
    cin>> N >> M >> K >>X;   
    for(int i = 0;i<M;i++){
        int a ,b;
        cin>>a >> b;
        graph[a].push_back(b);
    }
    travel(X , K, 0);
    int min = 3000006;
    for(int i=1;i<=N;i++){
        sort(answer[i].begin(), answer[i].end(), compare);
        //cout<<"to go: "<<answer[i][0].first <<"  gone:"<<answer[i][0].second<<endl;
        if(answer[i][0].first ==0){
            solution.push_back(i);
        }
    }
    sort(solution.begin(), solution.end());
    if(solution.size() ==0){
        cout<<-1;
    }
    for(int i=0;i<solution.size(); i++){
        cout<<solution[i]<<endl;
    }
    return 0;
}