#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k;
int arr[11][11];
int land[11][11];
int re[11][11];
int xp[8] = {-1,-1,-1,0,0,1,1,1};
int yp[8] = {-1,0,1,-1,1,-1,0,1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            land[i][j] = 5;
        }
    }
    vector<int> vv[11][11];
    vector<pair<int,int>> tr;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >>z;
        vv[x][y].push_back(z);
        tr.push_back(make_pair(x,y));
    }
    for(int i=0;i<k;i++){
        vector<int> vt[11][11];
        vector<pair<int,int>> tt;
        for(int j=1;j<=n;j++){
            for(int t=1;t<=n;t++){
                re[j][t] = 0;
            }
        }
        for(int j=0;j<tr.size();j++){
            int x = tr[j].first;
            int y = tr[j].second;
            sort(vv[x][y].begin(), vv[x][y].end());
            int flag = 0;

            for(int t=0;t<vv[x][y].size();t++){
                if(land[x][y] - vv[x][y][t] < 0)
                    re[x][y] += vv[x][y][t]/2;
                else {
                    land[x][y] -= vv[x][y][t];
                    vt[x][y].push_back(vv[x][y][t]+1);
                    flag = 1;
                }
            }
            if(flag == 1)
                tt.push_back(make_pair(x,y));
            vv[x][y].clear();
        }
        tr.clear();
        for(int j=0;j<tt.size();j++){
            int x = tt[j].first;
            int y = tt[j].second;
            for(int t=0;t<vt[x][y].size();t++){
                if(vv[x][y].size() == 0)
                    tr.push_back(make_pair(x,y));
                vv[x][y].push_back(vt[x][y][t]);
                if(vt[x][y][t] % 5 == 0) {
                    for (int p = 0; p < 8; p++) {
                        int xx = x + xp[p];
                        int yy = y + yp[p];
                        if (xx < 1 || xx >= n+1 || yy < 1 || yy >= n+1)
                            continue;
                        if(vv[xx][yy].size() == 0)
                            tr.push_back(make_pair(xx,yy));
                        vv[xx][yy].push_back(1);
                    }
                }
            }
        }
        for(int j=1;j<=n;j++) {
            for (int l = 1; l <= n; l++) {
                land[j][l] += (arr[j][l] + re[j][l]);
            }
        } // 겨울
    }

    int cnt = 0;
    for(int i=0;i<tr.size();i++){
        int x = tr[i].first;
        int y = tr[i].second;
        cnt += vv[x][y].size();
    }
    cout << cnt << "\n";
    return 0;
}
