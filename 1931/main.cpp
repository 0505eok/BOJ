#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int s;
        int e;
        cin >> s >> e;
        v.push_back(make_pair(e,s));
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int end = -1;
    for(int i=0;i<v.size();i++){
        if(v[i].second >= end){
            end = v[i].first;
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
