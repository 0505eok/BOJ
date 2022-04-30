#include<iostream>
#include<vector>
#include<map>

using namespace std;

int N,M,O;
int sx,sy;
int arr[21][21];
vector<pair<pair<int,int>,pair<int,int>>> v;
int checked[401];
map<pair<int,int>,int> m;
int dist[401][401];
int xp[4] = {-1,0,1,0};
int yp[4] = {0,-1,0,1};

void solution(){
    int cc = 0;
    while(1){
        int idx = -1;
        int cur = 500;
        int start = m[{sx,sy}];
        for(int i=0;i<v.size();i++){
            if(checked[i] == 1)
                continue;
            int a = v[i].first.first;
            int b = v[i].first.second;
            int tmp = m[{a,b}];
            if(dist[start][tmp] == -1)
                continue;
            if(cur >= dist[start][tmp]){
                if(cur == dist[start][tmp]){
                    if(v[idx].first.first > v[i].first.first){
                        idx = i;
                        cur = dist[start][tmp];
                    }else if(v[idx].first.first == v[i].first.first){
                        if(v[idx].first.second > v[i].first.second){
                            idx = i;
                            cur = dist[start][tmp];
                        }
                    }
                }else{
                    idx = i;
                    cur = dist[start][tmp];
                }
            }
        }
        if(idx == -1){
            cout << -1 << "\n";
            break;
        }
        checked[idx] = 1;
        int toP = cur;
        int toD = dist[m[{v[idx].first.first,v[idx].first.second}]][m[{v[idx].second.first,v[idx].second.second}]];
        if(toD == -1 || toP + toD > O){
            cout << -1 << "\n";
            break;
        }
        O -= toP;
        O += toD;
        sx = v[idx].second.first;
        sy = v[idx].second.second;
        cc++;
        if(cc == v.size()){
            cout << O << "\n";
            break;
        }
    }
}

int main(){
    cin >> N >> M >> O;

    int cnt = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> arr[i][j];
            m.insert({{i,j},cnt++});
        }
    }

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt;j++){
            dist[i][j] = -1;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(arr[i][j] == 1)
                continue;
            int src = m[{i,j}];
            dist[src][src] = 0;
            for(int k=0;k<4;k++){
                int x = i + xp[k];
                int y = j + yp[k];
                if(x <= 0 || x > N || y <=0 || y > N)
                    continue;
                if(arr[x][y] == 1)
                    continue;
                int tar = m[{x,y}];
                dist[src][tar] = 1;
                dist[tar][src] = 1;
            }
        }
    }

    cin >> sx >> sy;

    for(int i=0;i<M;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v.push_back({{a,b},{c,d}});
    }

    for(int r=0;r<cnt;r++){
        for(int i=0;i<cnt;i++){
            for(int j=0;j<cnt;j++){
                if(dist[i][r] == -1 || dist[r][j] == -1)
                    continue;
                int tmp = dist[i][r] + dist[r][j];
                if(dist[i][j] == -1 || dist[i][j] > tmp)
                    dist[i][j] = tmp;
            }
        }
    }

    solution();
}