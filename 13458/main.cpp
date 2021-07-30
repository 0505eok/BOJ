#include <iostream>
using namespace std;
int arr[1000001];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int b,c;
    cin >> b >> c;
    long long cnt = 0;
    for(int i=0;i<n;i++){
        arr[i] -= b;
        cnt++;
        if(arr[i] <= 0)
            continue;
        cnt += arr[i]/c;
        if(arr[i]%c != 0)
            cnt++;
    }
    cout << cnt;
}

