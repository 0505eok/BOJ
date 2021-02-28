#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    int *W = new int[n+1];
    int *V = new int[n+1];

    for(int i=1;i<=n;i++)
    {
        cin >> W[i] >> V[i];
    }

    int **arr = new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        arr[i] = new int[k+1];
    }

    for(int i=0;i<=k;i++)
        arr[0][i] = 0;

    for(int i=1;i<=n;i++)
    {
        arr[i][0] = 0;
        for(int j=1;j<=k;j++)
        {
            if(W[i] > j)
                arr[i][j] = arr[i-1][j];
            else
            {
                if(arr[i-1][j] > arr[i-1][j-W[i]] + V[i])
                    arr[i][j] = arr[i-1][j];
                else
                    arr[i][j] = arr[i-1][j-W[i]] + V[i];
            }
        }
    }
    cout << arr[n][k];

    return 0;
}
