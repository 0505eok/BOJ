#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int visited[9][9];
int arr[9][9];
int wall;
int n,m;
int xpos[4] = {-1,0,1,0};
int ypos[4] = {0,1,0,-1};
vector<pair<int,int>> v;

int bfs()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 1)
                visited[i][j] = 1;
            else
                visited[i][j] = 0;
        }
    }

    queue<pair<int,int>> q;

    for(int i=0;i<v.size();i++)
    {
        q.push(make_pair(v[i].first, v[i].second));
    }

    while(!q.empty())
    {
        int x,y;
        x = q.front().first;
        y = q.front().second;
        q.pop();


        if(visited[x][y] != 0)
            continue;

        visited[x][y] = 2;

        for(int i=0;i<4;i++)
        {
            if(x+xpos[i] < 0 || x+xpos[i] >= n || y+ypos[i] < 0 || y+ypos[i] >= m)
                continue;

            if(arr[x+xpos[i]][y+ypos[i]] == 1) {
                continue;
            }

            if(visited[x+xpos[i]][y+ypos[i]] !=0)
                continue;

            q.push(make_pair(x+xpos[i],y+ypos[i]));
        }
    }

    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j] == 0)
                count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];

            if(arr[i][j] == 2)
                v.push_back(make_pair(i,j));
        }
    }

    int max = 0;
    for(int i=0;i<n*m-2;i++)
    {
        if(arr[i/m][i%m] != 0)
            continue;

        for(int j=i+1;j<n*m-1;j++)
        {
            if(arr[j/m][j%m] != 0)
                continue;

            for(int k=j+1;k<n*m;k++)
            {
                if(arr[k/m][k%m] != 0)
                    continue;

                arr[i/m][i%m] = 1;
                arr[j/m][j%m] = 1;
                arr[k/m][k%m] = 1;

                int tmp = bfs();
                if(tmp > max) {
                    /*cout << tmp << "\n";
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<m;j++)
                            cout << visited[i][j] << " ";
                        cout << "\n";
                    }
                    cout << "\n";*/
                    max = tmp;
                }

                arr[i/m][i%m] = 0;
                arr[j/m][j%m] = 0;
                arr[k/m][k%m] = 0;
            }
        }
    }

    cout << max;

    return 0;
}
