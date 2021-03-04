#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
vector<int> V[50001];
int visited[50001];
void make_tree(int n,vector<int> *v){
    if(v[n].size() == 0)
        return;
    visited[n] = 1;
    for(int i=0;i<v[n].size();i++)
    {
        if(visited[v[n][i]] == 1)
            continue;
        V[v[n][i]].push_back(n);
        make_tree(v[n][i], v);
    }
    return;
}

int find(int a, int b){
    vector<int> visited(n+1);
    int cur1 = a;
    int cur2 = b;

    while(1){
        if(visited[cur1] == 1)
            return cur1;
        visited[cur1] = 1;

        if(visited[cur2] == 1)
            return cur2;
        visited[cur2] = 1;

        if(cur1 == 1)
            visited[1] = 0;
        else
            cur1 = V[cur1][0];

        if(cur2 == 1)
            visited[1] = 0;
        else
            cur2 = V[cur2][0];

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> *v = new vector<int>[n+1];
    vector<int> size(n+1);
    for(int i=0;i<n-1;i++)
    {
        int s,e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    make_tree(1,v);
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        cout << find(a,b) << "\n";
    }
    return 0;
}
