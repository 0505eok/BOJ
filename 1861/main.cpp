#include <iostream>
#include <queue>
using namespace std;

int arr[100][100];
int visited[100][100];
int xp[4] = {-1,1,0,0};
int yp[4] = {0,0,-1,1};
char dir[4] = {'U','D','L','R'};
int ma = -10001;
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<pair<int,int>,pair<string,int>>> q; // x,y,d,s
    q.push(make_pair(make_pair(0,0),make_pair("",arr[0][0])));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int s = q.front().second.second;
        string d = q.front().second.first;

        q.pop();

        for(int i=0;i<4;i++){
            int xx = x + xp[i];
            int yy = y + yp[i];
            int ss = s + arr[xx][yy];
            string dd = d + dir[i];
            if(visited[xx][yy] != 0)
                continue;
            q.push(make_pair(make_pair(xx,yy),make_pair(d,ss)));
            visited[xx][yy] = 1;
        }
    }

    return 0;
}
