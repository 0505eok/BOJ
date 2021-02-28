#include <iostream>
#include <queue>

using namespace std;

int n;
char arr[101][101];
int visited[101][101];
int visited2[101][101];
int xpos[4] = {1,-1,0,0};
int ypos[4] = {0,0,1,-1};

int bfs(int x, int y, int f)
{
    if(visited[x][y] == 1 && f == 1)
        return 0;
    else if(visited2[x][y] == 1 && f == 2)
        return 0;

    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty())
    {
        int a,b;
        a = q.front().first;
        b = q.front().second;
        q.pop();

        if(visited[a][b] == 1 && f == 1)
            continue;
        else if(visited2[a][b] == 1 && f == 2)
            continue;

        if(f == 1)
            visited[a][b] = 1;
        else if(f == 2)
            visited2[a][b] = 1;

        for(int i=0;i<4;i++)
        {
            int ax = a + xpos[i];
            int by = b + ypos[i];

            if(ax < 0 || ax >= n || by < 0 || by >= n)
            {
                if(visited[ax][by] == 1 && f == 1)
                    continue;
                else if(visited2[ax][by] == 1 && f == 2)
                    continue;
            }

            if(arr[a][b] == arr[ax][by] && f == 1)
                q.push(make_pair(ax,by));
            else if(f == 2)
            {
                if((arr[a][b] == 'R' || arr[a][b] == 'G') && (arr[ax][by] == 'R' || arr[ax][by] == 'G'))
                    q.push(make_pair(ax,by));
                else if(arr[a][b] == arr[ax][by])
                    q.push(make_pair(ax,by));
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int flag = bfs(i,j,1);

            if(flag == 0)
                continue;
            else
                cnt++;
        }
    }

    int cnt2 = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int flag = bfs(i,j,2);

            if(flag == 0)
                continue;
            else
                cnt2++;
        }
    }
    cout << cnt << " " << cnt2;

    return 0;
}
