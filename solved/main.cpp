#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int visited[100][100];
int xp[4] = {-1,0,1,0};
int yp[4] = {0,-1,0,1};

int main() {
    int n;
    cin >> n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string str;
        cin >>  str;
        v.push_back(str);
    }

    int cnt = 0;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 1)
                continue;

            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            char color = v[i][j];
            visited[i][j] = 1;
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++) {
                    int xx = x + xp[k];
                    int yy = y + yp[k];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= n)
                        continue;
                    if (v[xx][yy] != color)
                        continue;
                    if (visited[xx][yy] == 1)
                        continue;
                    q.push(make_pair(xx, yy));
                    visited[xx][yy] = 1;
                }
            }
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
