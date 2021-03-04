#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> v[501];
int t[501];
int visited[501];

int dfs(int x){
    if(v[x].size() == 0) {
        visited[x] = t[x];
        return t[x];
    }
    int tmp = 0;
    for(int i=0;i<v[x].size();i++)
    {
        if(visited[v[x][i]] != 0)
            tmp = max(tmp,visited[v[x][i]]);
        else
            tmp = max(tmp,dfs(v[x][i]));
    }
    visited[x] = tmp + t[x];

    return visited[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> t[i];
        for(int j=0;;j++)
        {
            int x;
            cin >> x;
            if(x == -1)
                break;
            v[i].push_back(x);
        }
    }

    for(int i=1;i<=n;i++)
        cout << dfs(i) << "\n";

    return 0;
}
