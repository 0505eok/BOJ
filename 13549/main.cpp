#include <iostream>
#include <queue>

using namespace std;

int visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s,e;
    cin >> s >> e;

    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,s));

    int x,t;

    while(!q.empty())
    {
        t = -1 * q.top().first;
        x = q.top().second;
        q.pop();

        if(x == e)
            break;

        if(visited[x] == 1)
            continue;
        else
        {
            visited[x] = 1;

            if(x + 1 <= 100000)
                q.push(make_pair(-(t+1),x+1));

            if(x - 1 >= 0)
                q.push(make_pair(-(t+1),x-1));

            if(x*2 <= 100000)
                q.push(make_pair(-t,x*2));
        }
    }

    cout << t;

    return 0;
}

// 수정 여부 판단
// 수정 22
// 찐막
