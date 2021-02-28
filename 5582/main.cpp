#include <iostream>

using namespace std;

int arr[4001][4001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1;
    string str2;
    cin >> str1 >> str2;

    int max = 0;
    for(int i=1;i<=str1.size();i++)
    {
        for(int j=1;j<=str2.size();j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                arr[i][j] = arr[i-1][j-1] + 1;
                if(arr[i][j] > max)
                    max = arr[i][j];
            }
        }
    }

    cout << max;
    return 0;
}
