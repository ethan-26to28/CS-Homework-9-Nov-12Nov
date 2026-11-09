#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> list(n);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    sort(list.begin(), list.end());

    vector<int> best(n);
    int left = 0;

    for (int right = 0; right < n; right++) {
        while (list[right] - list[left] > k) {
            left++;
        }

        best[right] = right - left + 1;
    }

    vector<int> prefix(n);
    prefix[0] = best[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i - 1], best[i]);
    }

    int answer = 0;
    left = 0;

    for (int right = 0; right < n; right++) {
        while (list[right] - list[left] > k) {
            left++;
        }

        int first = right - left + 1;
        int second = 0;

        if (left > 0) {
            second = prefix[left - 1];
        }

        answer = max(answer, first + second);
    }

    cout << answer << endl;

    return 0;
}