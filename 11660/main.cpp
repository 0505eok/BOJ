#include <iostream>


using namespace std;
int arr[1026][1026];
int tab[1026][1026];

int cal(int a, int b, int c, int d)
{
    int sum = 0;
    sum = tab[c][d] - tab[a-1][d] - tab[c][b-1] + tab[a-1][b-1];
    return sum;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            tab[i][j] = tab[i][j-1] + tab[i-1][j] + arr[i][j] - tab[i-1][j-1];
        }
    }

    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << cal(a,b,c,d) << "\n";
    }

    return 0;
}
