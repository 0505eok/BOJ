#include <iostream>
#include <queue>

using namespace std;
char arr[1001][1001] = {'.',};
int w,h;
int xpo[4] = {-1,1,0,0};
int ypo[4] = {0,0,-1,1};
int Fire[1001][1001];

int sol(queue<pair<pair<int,int>,int>> fire, queue<pair<pair<int,int>,int>> sg){

    while(!fire.empty() && !sg.empty()) {
        int fx = fire.front().first.first;
        int fy = fire.front().first.second;
        int fs = fire.front().second;

        fire.pop();

        for (int i = 0; i < 4; i++) {
            int nx = fx + xpo[i];
            int ny = fy + ypo[i];
            if (arr[nx][ny] == '#' || arr[nx][ny] == '*')
                continue;
            if (nx < 1 || nx > h || ny < 1 || ny > w)
                continue;
            fire.push(make_pair(make_pair(nx, ny), fs + 1));
            arr[nx][ny] = '*';
            Fire[nx][ny] = fs + 1;
        }
    }
    while(!sg.empty())
    {
        int sx = sg.front().first.first;
        int sy = sg.front().first.second;
        int ss = sg.front().second;

        if(sx == 1 || sx == h || sy == 1 || sy == w)
            return ss+1;
        sg.pop();

        for(int i=0;i<4;i++)
        {
            int nx = sx + xpo[i];
            int ny = sy + ypo[i];
            if(arr[nx][ny] == '#' || arr[nx][ny] == '@')
                continue;
            if(Fire[nx][ny] <= ss+1 && arr[nx][ny] == '*')
                continue;
            sg.push(make_pair(make_pair(nx,ny),ss+1));
            arr[nx][ny] = '@';
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> w >> h;
        queue<pair<pair<int,int>,int>> fire;
        queue<pair<pair<int,int>,int>> sg;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '@')
                {
                    sg.push(make_pair(make_pair(i,j),0));
                }
                else if(arr[i][j] == '*')
                {
                    fire.push(make_pair(make_pair(i,j),0));
                }
            }
        }

        int ans = sol(fire,sg);

        if(ans == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans << "\n";

        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                arr[i][j] = '.';
                Fire[i][j] = 0;
            }
        }
    }
    return 0;
}
