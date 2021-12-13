#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
int arr[51][10];
vector<int> v;
vector<pair<int,int>> inning(int start, int in){
    int o_cnt = 0;
    int base[5] = {0,0,0,0,0};
    int i = start-1;
    for(;;i++){
        if(i == 9)
            i = 0;
        base[0] = 1;
        int roo = arr[in][v[i]];
        if(roo == 0) {
            o_cnt++;
            if(o_cnt == 3)
                break;
            continue;
        }
        for(int k=0;k<roo;k++) {
            for (int j = 3; j >= 0; j--) {
                base[j + 1] += base[j];
                base[j] = 0;
            }
        }
    }
    vector<pair<int,int>> tmp;
    tmp.push_back(make_pair(i+2,base[4]));
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=9;i++)
        v.push_back(i);

    int mx = -1;
    do{
        if(v[3] != 1)
            continue;
        vector<pair<int,int>> s;
        int score = 0;
        s.push_back(make_pair(1,0));
        for(int i=1;i<=n;i++){
            int start = s[0].first;
            score += s[0].second;
            s = inning(start, i);
        }
        score += s[0].second;
        mx = max(mx,score);
    }while(next_permutation(v.begin(), v.end()));

    cout << mx << "\n";
    return 0;
}
