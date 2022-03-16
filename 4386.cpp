#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int parent[101];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b){
    if(a > b)
        swap(a,b);
    parent[a] = b;
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
        parent[i] = i;

    vector<pair<float,float>> stars;
    for(int i=0;i<n;i++){
        float x,y;
        cin >> x >> y;
        stars.push_back({x,y});
    }

    vector<pair<float,pair<int,int>>> dis;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            float dist = pow((stars[i].first-stars[j].first),2) + pow((stars[i].second-stars[j].second),2);
            dist = sqrt(dist);
            dis.push_back({dist,{i,j}});
        }
    }

    sort(dis.begin(), dis.end());

    float ans = 0;
    int cnt = 0;
    for(int i=0;i<dis.size();i++){
        float dist = dis[i].first;
        int a = dis[i].second.first;
        int b = dis[i].second.second;
        a = find(a);
        b = find(b);
        if(a != b) {
            merge(a, b);
            cnt++;
            ans += dist;
            if(cnt == n)
                break;
        }
    }

    cout.precision(3);
    cout << ans << "\n";

}