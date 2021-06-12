#include <bits/stdc++.h>
using namespace std;
const long INF = (int)1e9 + 7;

int n;

int h[10001];
long memo[10001];

long dp (int pos) {
	if (pos < 0 or pos >= n)
		return INF;
	if (memo[pos] != -1)
		return memo[pos];
	long ans = INF;
	if (pos >= 1)
		ans = min(ans, abs(h[pos] - h[pos - 1]) + dp(pos - 1));
	if (pos >= 2)
		ans = min(ans, abs(h[pos] - h[pos - 2]) + dp(pos - 2));
	memo[pos] = ans;
	return ans;
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < n; i++)
		memo[i] = -1;
	memo[0] = 0;
	cout << dp(n - 1) << "\n";
	return 0;
}
