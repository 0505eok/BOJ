#include <iostream>
#include <vector>

using namespace std;

int bus[101][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if(bus[from][to] != 0)
            bus[from][to] = min(cost, bus[from][to]);
        else
            bus[from][to] = cost;

    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(bus[i][k] != 0 && bus[k][j] != 0)
                {
                    int tmp = bus[i][k] + bus[k][j];
                    if(i == j)
                        bus[i][j] = 0;
                    else if(bus[i][j] == 0 || bus[i][j] > tmp)
                        bus[i][j] = tmp;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout << bus[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
