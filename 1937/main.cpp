#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[501][501];
int visited[501][501];
int xpo[4] = {-1,1,0,0};
int ypo[4] = {0,0,-1,1};
vector<pair<int, pair<int,int>>> v;
int n;
int dp(){
    for(int i=0;i<v.size();i++)
    {
        int x = v[i].second.first;
        int y = v[i].second.second;

        for(int j=0;j<4;j++)
        {
            int nx = x + xpo[j];
            int ny = y + ypo[j];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if(arr[nx][ny] > arr[x][y])
            {
                if(visited[x][y] < visited[nx][ny] + 1)
                    visited[x][y] = visited[nx][ny] + 1;
            }
        }
        if(visited[x][y] == 0)
            visited[x][y] = 1;
    }

    int max = 0;
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[k][j] > max)
                max = visited[k][j];
        }
    }
    return max;
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
            v.push_back(make_pair(-arr[i][j], make_pair(i,j)));
        }
    }

    sort(v.begin(), v.end());

    cout << dp();

    return 0;
}
