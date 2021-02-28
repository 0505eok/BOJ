#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> V[20001];
int v,e,s;
int d[20001];

priority_queue<pair<int,int>> pq;

void di()
{
    for(int i=1;i<=v;i++)
        d[i] = 1000000000;

    d[s] = 0;

    pq.push(make_pair(0,s));
    while(!pq.empty())
    {
        int weight = -1*pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(d[current] < weight)
            continue;

        for(int i=0;i<V[current].size();i++)
        {
            int next = V[current][i].first;

            if(d[next] > weight + V[current][i].second)
            {
                d[next] = weight + V[current][i].second;
                pq.push(make_pair(-d[next],next));
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> v >> e;
    cin >> s;

    int a,b,c;
    for(int i=0;i<e;i++)
    {
        cin >> a >> b >> c;
        V[a].push_back(make_pair(b,c));
    }

    di();

    for(int i=1;i<=v;i++)
    {
        if(d[i] == 1000000000)
            cout << "INF" << "\n";
        else
            cout << d[i] << "\n";
    }

    return 0;
}
