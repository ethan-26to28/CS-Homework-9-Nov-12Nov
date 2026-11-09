#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> freq(1000001, 0);

    int left = 0;
    int distinct = 0;
    int bestLeft = 0;
    int bestRight = 0;
    int maxLength = 0;

    for (int right = 0; right < n; right++) {

        if (freq[a[right]] == 0) {
            distinct++;
        }

        freq[a[right]]++;

        while (distinct > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0) {
                distinct--;
            }
            left++;
        }

        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            bestLeft = left;
            bestRight = right;
        }
    }
    cout << bestLeft + 1 << " " << bestRight + 1 << endl;
    return 0;
}