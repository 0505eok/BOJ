#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>> g, int x, int n){
    vector<int> dis(n+1, -1);

    dis[x] = 0;
    priority_queue<pair<int,int>> q; // 거리, 현재지점
    q.push(make_pair(0,x));

    while(!q.empty()){
        int d = -q.top().first;
        int s = q.top().second;
        q.pop();
        if(dis[s] < d)
            continue;
        for(int i=0;i<g[s].size();i++){
            int to = g[s][i].first;
            int dist = g[s][i].second;
            if(dis[to] != -1 && dis[to] <= d + dist)
                continue;
            dis[to] = d + dist;
            q.push(make_pair(-dis[to], to));
        }
    }

    vector<int> ret;
    for(int i=0;i<=n;i++){
        ret.push_back(dis[i]);
    }
    return ret;
}

int main() {
    int n,m,x;

    cin >> n >> m >> x;

    vector<vector<pair<int,int>>> v(n+1);
    vector<vector<pair<int,int>>> rv(n+1);

    for(int i=0;i<m;i++){
        int s,e, t;
        cin >> s >> e >> t;
        v[s].push_back(make_pair(e,t));
        rv[e].push_back(make_pair(s,t));
    }

    vector<int> vv = dijkstra(v, x, n);
    vector<int> rvv = dijkstra(rv, x, n);

    int ans = -1;
    for(int i=1;i<vv.size();i++){
        ans = max(ans, vv[i]+rvv[i]);
    }
    cout << ans << "\n";
    return 0;
}
