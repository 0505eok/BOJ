#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
long long cal(int s, int e)
{
    int middle = (s+e)/2;
    long long left;
    long long right;
    if(s != e)
    {
        left = cal(s,middle);
        right = cal(middle+1,e);
        long long tmp = max(left,right);

        int l = middle;
        int r = middle+1;
        long long sum = arr[l]+arr[r];
        long long m = min(arr[l],arr[r]);
        long long Max = sum*m;

        while(l > s || r < e)
        {
            if(r < e && (l == s || arr[l-1] < arr[r+1]))
            {
                r++;
                m = min(m,(long long)arr[r]);
                sum += arr[r];
                Max = max(Max,m*sum);
            }
            else
            {
                l--;
                m = min(m,(long long)arr[l]);
                sum += arr[l];
                Max = max(Max,m*sum);
            }

        }

        Max = max(Max,tmp);

        return Max;
    }else
    {
        return (long long)arr[s]*arr[s];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }

    cout << cal(1,n) << "\n";
    return 0;
}
