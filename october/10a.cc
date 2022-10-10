#include <cstdio>
using namespace std;

#define K 10001
#define MOD 1000000007

int dp[2][K];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	dp[1][0] = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = 0;
		for (int j = 0; j <= k; j++) {
			tmp = (tmp + dp[(i-1)&1][j]) % MOD;
			if (j >= i) tmp = (tmp - dp[(i-1)&1][j-i] + MOD) % MOD;
			dp[i&1][j] = tmp;
		}
	}
	printf("%d\n", dp[n&1][k]);
	return 0;
}