#include<iostream>
#include<vector>

#define INF 25000001
using namespace std;

int n,m,w;
int dis[501][501];
int main(){
    int tc;
    cin >> tc;
    for(int i=0;i<tc;i++){
        cin >> n >> m >> w;

        for(int a=1;a<=n;a++){
            for(int b=1;b<=n;b++){
                dis[a][b] = INF;
            }
        }

        for(int j=0;j<m;j++){
            int s,e,t;
            cin >> s >> e >> t;
            dis[s][e] = min(dis[s][e],t);
            dis[e][s] = min(dis[e][s],t);
        }
        for(int j=0;j<w;j++){
            int s,e,t;
            cin >> s >> e >> t;
            dis[s][e] = min(dis[s][e], -t);
        }

        for(int s=1;s<n+1;s++){
            for(int e=1;e<n+1;e++){
                for(int mid=1;mid<n+1;mid++){
                    int cur = dis[s][mid] + dis[mid][e];
                    if(dis[s][e] < cur)
                        continue;
                    dis[s][e] = cur;
                }
            }
        }

        int flag = 0;
        for(int a=1;a<n+1;a++){
            if(dis[a][a] < 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}