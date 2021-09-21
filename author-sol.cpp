#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		// check the bits which are set in b[i - 1] if they are a subset of the
		// bits which are set in b[i] for all valid i, and if this condition is not true
		// for some i, then the answer is 0
		bool checker = true;
		for (int i = 1; i < n; i++) {
			if ((b[i - 1] & b[i]) != b[i - 1]) {
				checker = false;
				break;
			}
		}
		if (!checker) {
			cout << 0 << '\n';
			continue;
		}
		// we need to count the total number of set bits (1-bit) of all the elements
		// except the last element since we will already count it the moment we encounter
		// a new set bit (1-bit) from the preceding elements (if there are)
		int one_bit = 0;
		for (int i = 0; i < n - 1; i++) {
			int m = b[i];
			while (m > 0) {
				one_bit += (m & 1);
				m >>= 1;
			}
		}
		// the answer is 2 raise to the total number of set bits (1-bit)
		int res = 1;
		for (int i = 0; i < one_bit; i++) {
			res = (res * 2) % MOD;
		}
		cout << res << '\n';
	}
	return 0;
}
