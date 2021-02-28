#include <iostream>
#include <queue>

using namespace std;

int xpos[4] = {-1,1,0,0};
int ypos[4] = {0,0,-1,1};
int sol(int n)
{
    int arr[126][126];
    int rupee[126][126];
    priority_queue<pair<int,pair<int,int>>> q;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> arr[i][j];
            rupee[i][j] = 125*125*10;
        }
    }

    q.push(make_pair(-arr[0][0],make_pair(0,0)));
    int sx,sy;
    int r;
    while(!q.empty())
    {
        sx = q.top().second.first;
        sy = q.top().second.second;
        r = -q.top().first;
        q.pop();

        if(sx == n-1 && sy == n-1)
            break;

        if(rupee[sx][sy] > r)
            rupee[sx][sy] = r;

        for(int k=0;k<4;k++)
        {
            int nx = sx + xpos[k];
            int ny = sy + ypos[k];
            if(nx<0 || nx >=n || ny<0 || ny >=n)
                continue;
            if(rupee[sx][sy] + arr[nx][ny] < rupee[nx][ny])
            {
                rupee[nx][ny] = rupee[sx][sy] + arr[nx][ny];
                q.push(make_pair(-rupee[nx][ny],make_pair(nx,ny)));
            }
        }
    }

    return rupee[n-1][n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    for(int i=1;;i++)
    {
        cin >> n;
        if(n == 0)
            break;

        int kkk = sol(n);
        cout << "Problem " << i << ": " << kkk << "\n";
    }
    return 0;
}
