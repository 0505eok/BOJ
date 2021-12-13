#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m,d;
int arr[16][16];
int c;
int mma = 0;
vector<int> v;
vector<pair<int,int>> sel(int x){
    int mi = d+1;
    int mx = -1;
    int my = -1;
    for(int i=0;i<c;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0)
                continue;
            int dis = abs(i-c) + abs(j-x);
            if(dis < mi){
                mi = dis;
                mx = i;
                my = j;
            }else if(dis == mi){
                if(my > j){
                    mx = i;
                    my = j;
                }
            }
        }
    }
    vector<pair<int,int>> temp;
    temp.push_back(make_pair(mx,my));
    return temp;
}

int attack(){
    int cnt = 0;
    int prev[16][16];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            prev[i][j] = arr[i][j];
        }
    }
    while(c >= 0) {
        vector<pair<int, int>> tmp;
        vector<pair<int, int>> t;
        for (int i = 0; i < v.size(); i++) {
            tmp = sel(v[i]);
            if(tmp[0].first == -1)
                continue;
            t.push_back(make_pair(tmp[0].first, tmp[0].second));
        }

        for (int i = 0; i < t.size(); i++) {
            int x = t[i].first;
            int y = t[i].second;
            if (arr[x][y] == 0)
                continue;
            arr[x][y] = 0;
            cnt++;
        }
        c--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = prev[i][j];
        }
    }
    return cnt;
}

/*void dfs(int a, int b){
    if(b == 3){
        c = n;
        int tmp = attack();
        mma = max(tmp, mma);
        return;
    }
    if(b + (m-a) < 3)
        return;

    v.push_back(a);
    dfs(a+1,b+1);
    v.pop_back();
    dfs(a+1,b);
}
*/
void cal_per(){
    vector<int> per;
    for(int i=0;i<m;i++){
        if(i < 3)
            per.push_back(1);
        else
            per.push_back(0);
    }
    do{
        for(int i=0;i<m;i++){
            if(per[i] == 1)
                v.push_back(i);
        }
        c = n;
        int tmp = attack();
        mma = max(tmp, mma);
        v.clear();
    }while(prev_permutation(per.begin(), per.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    //dfs(0,0);
    cal_per();

    cout << mma << "\n";
    return 0;
}
