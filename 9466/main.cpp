#include <iostream>
#include <vector>

using namespace std;

int visited[100001];
vector<int>v[100001];
int cnt;
int n;
int team;
int depth;
int final;

void dfs(int s)
{
    if(visited[s] == 1)
    {
        team = s;
        final = depth;
        return;
    }

    final = 1;

    visited[s] = 1;
    depth++;

    dfs(v[s][0]);

    if(team == s)
    {
        final = depth-1;
    }
    depth--;

    return;
}

void sol()
{
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        visited[i] = 0;
    }

    cnt = 0;

    for(int i=1;i<=n;i++)
    {
        int p;
        cin >> p;
        v[i].push_back(p);
    }

    for(int i=1;i<=n;i++)
    {
        team = -1;
        final = 0;
        dfs(i);
        cnt += final;
    }

    cout << cnt << "\n";

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i=0;i<t;i++)
    {
        sol();

        for(int i=1;i<=n;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}
