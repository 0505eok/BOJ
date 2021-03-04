#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,k,s;
int arr[401][401];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin >> a >> b;
        arr[a][b] = -1;
        arr[b][a] = 1;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j] == 0) {
                    if (arr[i][k] == arr[k][j])
                        arr[i][j] = arr[i][k];
                }
            }
        }
    }

    cin >> s;
    for(int i=0;i<s;i++)
    {
        int a,b;
        cin >> a >> b;
        cout << arr[a][b] << "\n";
    }




}

/*-------bfs 사용한거-------*/
/*int n,k,s;
vector<int> v[401];
int arr[401][401];
void bfs(int x){
    if(v[x].size() == 0)
        return;

    queue<pair<int,int>>q;
    q.push(make_pair(x,0));

    while(!q.empty()){
        int t = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int i=0;i<v[t].size();i++)
        {
            if(arr[x][v[t][i]] < d+1) {
                arr[x][v[t][i]] = d + 1;
                q.push(make_pair(v[t][i], d + 1));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j] = -1;
        }
    }

    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }

    for(int i=1;i<=n;i++)
        bfs(i);

    cin >> s;
    for(int i=0;i<s;i++)
    {
        int a,b;
        cin >> a >> b;
        int aa = arr[a][b];
        int bb = arr[b][a];
        if(aa == -1 && bb == -1)
            cout << 0 << "\n";
        else if(aa == -1)
            cout << 1 << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}*/
