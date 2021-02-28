#include <iostream>
#include <queue>

using namespace std;

int number[10];
int visited[1000011][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int a;
        cin >> a;
        number[a] = 1;
    }

    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(100,0),0));

    int num,cnt,flag;
    while(!q.empty())
    {
        num = q.front().first.first;
        cnt = q.front().first.second;
        flag = q.front().second;
        q.pop();

        if(num == n)
            break;

        if(visited[num][flag] == 1) {
            continue;
        }

        visited[num][flag] = 1;

        // +,- 일 때
        if(num < 1000011)
            q.push(make_pair(make_pair(num + 1, cnt + 1),0));
        if (num > 0)
            q.push(make_pair(make_pair(num - 1, cnt + 1),0));

        // 일반 번호 일 때
        if(flag == 1 || num == 100) {
            for (int i = 0; i < 10; i++) {
                if (number[i] == 1)
                    continue;

                if (flag == 1 && num * 10 + i < 1000011)
                    q.push(make_pair(make_pair(num * 10 + i, cnt + 1),1));
                else if(flag == 0)
                    q.push(make_pair(make_pair(i, cnt + 1),1));
            }
        }
    }

    cout << cnt;

    return 0;
}
