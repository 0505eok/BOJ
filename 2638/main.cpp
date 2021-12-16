#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xp[4] = {-1,0,1,0};
int yp[4] = {0,-1,0,1};

int bfs(vector<vector<int>> &visited, vector<vector<int>> &v){
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int xx = x + xp[i];
            int yy = y + yp[i];
            if(xx < 0 || xx >= v.size() || yy < 0 || yy >= v[0].size())
                continue;
            if(visited[xx][yy] == 1)
                continue;
            if(v[xx][yy] != 0) {
                v[xx][yy]++;
                continue;
            }
            visited[xx][yy] = 1;
            q.push(make_pair(xx,yy));
        }
    }
    int cnt = 0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == 0)
                continue;
            if(v[i][j] > 2) {
                cnt++;
                v[i][j] = 0;
            }else{
                v[i][j] = 1;
            }
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> w;
        for(int j=0;j<m;j++){
            int k;
            cin >> k;
            w.push_back(k);
        }
        v.push_back(w);
    }

    int cnt = 0;
    while(1){
        vector<vector<int>> visited;
        for(int i=0;i<n;i++){
            vector<int> tmp(m);
            visited.push_back(tmp);
        }
        if(bfs(visited, v) == 0)
            break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
