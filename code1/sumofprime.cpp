#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005; // Adjust this based on the maximum possible input

vector<long long> sumOfPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<long long> prefixSum(n + 1, 0);

    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + (isPrime[i] ? i : 0);
    }

    return prefixSum;
}

int main() {
    int t;
    cin >> t;
    vector<int> testCases(t);

    // Store all the test cases
    for (int i = 0; i < t; i++) {
        cin >> testCases[i];
    }

    int maxN = *max_element(testCases.begin(), testCases.end());
    vector<long long> primeSums = sumOfPrimes(maxN);

    // Print the results for each test case
    for (int i = 0; i < t; i++) {
        cout << primeSums[testCases[i]] << endl;
    }

    return 0;
}
