#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<pair<int,pair<int,int>>> v;
int parent[1001];
int Find(int a){
    if(parent[a] == 0) return a;
    else return parent[a] = Find(parent[a]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    for(int i=0;i<v.size();i++){
        int a = Find(v[i].second.first);
        int b = Find(v[i].second.second);
        if(a!=b) {
            cnt += v[i].first;
            parent[b] = a;
        }
    }

    cout << cnt << "\n";

    return 0;
}
