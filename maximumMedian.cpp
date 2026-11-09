#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int mid = n / 2;
    for (int i = mid; i < n - 1; i++) {
        long long diff = a[i + 1] - a[i];
        long long cost = diff * (i - mid + 1);

        if (cost <= k) {
            k -= cost;
            a[mid] = a[i + 1];
        }
        else {
            a[mid] += k / (i - mid + 1);
            k = 0;
            break;
        }
    }

    if (k > 0) {
        a[mid] += k / (n - mid);
    }

    cout << a[mid] << endl;

    return 0;
}