#include <iostream>
#include <vector>
using namespace std;

int visited[1001];
int rec(int a, vector<int> v, vector<int> *g){
    if(g[a].size() == 0)
    {
        visited[a] = v[a];
        return v[a];
    }

    int max = 0;
    for(int i=0;i<g[a].size();i++)
    {
        int tmp;
        if(visited[g[a][i]] != -1)
            tmp = visited[g[a][i]];
        else
            tmp = rec(g[a][i], v, g);

        if(max < tmp)
            max = tmp;
    }
    visited[a] = max + v[a];
    return max + v[a];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int test=0;test<t;test++)
    {
        int n,k,m;
        cin >> n >> k;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++)
            cin >> v[i];

        for(int i=0;i<=n;i++)
            visited[i] = -1;

        vector<int> *g = new vector<int>[n+1];
        for(int i=0;i<k;i++)
        {
            int s,e;
            cin >> s >> e;
            g[e].push_back(s);
        }

        cin >> m;

        int max = 0;
        for(int i=0;i<g[m].size();i++)
        {
            int tmp = rec(g[m][i], v, g);
            if(max < tmp)
                max = tmp;
        }

        cout << max + v[m] << "\n";
    }
    return 0;
}
