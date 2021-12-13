#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[21][21];
int tmp;
vector<pair<int,int>> v[21];
int dfs(int x){

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            tmp += arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j)
                continue;
            int sum = arr[i][j] + arr[j][i];
            v[i].push_back(make_pair(j,sum));
        }
    }

    return 0;
}
