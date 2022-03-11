#include<iostream>
#include<queue>
#include<vector>
#define INF 100000001
using namespace std;

int n,m;
int st, en;
vector<pair<int,int>> bus[1001];
vector<pair<int,int>> dist(1001, {INF,-1});
priority_queue<pair<int,int>> pq;
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int s,e,t;
        cin >> s >> e >> t;
        bus[s].push_back({t,e});
    }
    cin >> st >> en;

    dist[st] = {0,-1};
    pq.push({0,st});

    while(!pq.empty()){
        int p = pq.top().second;
        int cur = -pq.top().first;
        pq.pop();

        if(cur > dist[p].first)
            continue;

        for(int i=0;i<bus[p].size();i++){
            int next = cur + bus[p][i].first;
            int nd = bus[p][i].second;
            if(dist[nd].first != INF && next >= dist[nd].first)
                continue;
            dist[nd] = {next, p};
            pq.push({-next, nd});
        }
    }

    vector<int> route;
    route.push_back(en);
    int tmp = en;
    while(tmp != st){
        route.push_back(dist[tmp].second);
        tmp = dist[tmp].second;
    }

    cout << dist[en].first << "\n" << route.size() << "\n";
    for(int i=route.size()-1;i>=0;i--){
        cout << route[i] << " ";
    }
}