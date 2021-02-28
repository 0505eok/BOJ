#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sol()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i=0;i<n;i++)
    {
        int s,m;
        cin >> s >> m;
        v.push_back(make_pair(s,m));
    }

    sort(v.begin(), v.end());

    int tmp = v[0].second;
    int cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(v[i].second > tmp)
            continue;
        cnt++;
        tmp = v[i].second;
    }

    cout << cnt << "\n";

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        sol();
    }
    return 0;
}
