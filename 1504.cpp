#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int dis[4][801];
int main(){
    memset(dis, -1, sizeof(dis));

    int n,e,p1,p2;
    cin >> n >> e;
    vector<pair<int,int>> v[n+1];
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    cin >> p1 >> p2;

    int src[4] = {1,p1,p1,p2};
    int dest[4] = {-1,p2,n,n};
    for(int t=0;t<4;t++) {
        int ss = src[t];
        int dd = dest[t];
        priority_queue<pair<int, int>> pq;
        pq.push({0, ss});
        dis[t][ss] = 0;
        while (!pq.empty()) {
            int cur = -pq.top().first;
            int cp = pq.top().second;
            pq.pop();
            if(dd != -1 && dd == cp)
                break;
            for (int i = 0; i < v[cp].size(); i++) {
                int next = cur + v[cp][i].first;
                int np = v[cp][i].second;
                if (dis[t][np] != -1 && dis[t][np] < next)
                    continue;
                dis[t][np] = next;
                pq.push({-next, np});
            }
        }
    }

    int common = dis[1][p2];
    int ans = min(dis[0][p2] + dis[2][n], dis[0][p1] + dis[3][n]);
    ans += common;
    if(dis[0][n] == -1 || dis[0][p1] == -1 || dis[0][p2] == -1)
        ans = -1;
    cout << ans << "\n";
}