#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int N, Hi, Mi, X, A, B;
    cin >> N;
    vector<int> h(N), m(N);
    for (int i = 0; i < N; i++)
        cin >> h[i] >> m[i];
    cin >> X >> A >> B;
    int late_time = A * 60 + B;
    int rta, rtb;
    int min_time = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        int hi = h[i], mi = m[i];
        int time = hi * 60 + mi;
        int temp = late_time - time;
        if (temp >= X && temp < min_time)
        {
            min_time = temp;
            rta = hi;
            rtb = mi;
        }
    }
    cout << rta << " " << rtb;
    return 0;
}