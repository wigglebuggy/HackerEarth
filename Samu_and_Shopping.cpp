#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int dp[maxn][3], arr[maxn][3];
int t, n;
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				scanf ("%d", &arr[i][j]);
			}
		}
		memset (dp, 0, sizeof(dp));
		dp[0][0] = arr[0][0];
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][2];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = min (dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min (dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min (dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}
		printf("%d\n", min (dp[n - 1][0], min (dp[n - 1][1], dp[n - 1][2])));
	}
	return 0;
}