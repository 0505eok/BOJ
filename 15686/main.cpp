#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[51][51];
vector<pair<int,int>> chi;
vector<pair<int,int>> hom;
int visited[51];
int mi = 100000000;
void dfs(int idx, int cnt){
    if(cnt == m){
        int dist = 0;
        for(int i=0;i<hom.size();i++){
            int dis = 100000000;
            for(int j=0;j<chi.size();j++){
                if(visited[j] == 1){
                    int temp = abs(chi[j].first - hom[i].first) + abs(chi[j].second - hom[i].second);
                    dis = min(temp, dis);
                }
            }
            dist += dis;
        }
        mi = min(mi,dist);
        return;
    }
    if(idx == chi.size())
        return;

    visited[idx] = 1; // 해당 치킨집 골랐을 때
    dfs(idx+1,cnt+1);
    visited[idx] = 0; // 해당 치킨집 안골랐을 때
    dfs(idx+1,cnt);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2)
                chi.push_back(make_pair(i,j));
            else if(arr[i][j] == 1)
                hom.push_back(make_pair(i,j));
        }
    }

    dfs(0,0);
    cout << mi << "\n";

    return 0;
}
