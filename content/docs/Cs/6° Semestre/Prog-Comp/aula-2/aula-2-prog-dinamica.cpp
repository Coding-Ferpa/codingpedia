#include <iostream>
#include <vector>

int fib_memo(int k, std::vector<int> &memo) {
  if (k <= 1)
    return k;

  if (memo[k] != -1)
    return memo[k];

  memo[k] = fib_memo(k - 1, memo) + fib_memo(k - 2, memo);
  return memo[k];
}

int fib_tabo(int k) {
  std::vector<int> dp(k + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= k; i++)
    dp[i] = dp[i - 1] + dp[i - 2];

  return dp[k];
}

// NUMERO CATALAO
int numero_catalao(int n) {
  std::vector<int> dp(n + 1, 1);
  int c = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++)
      dp[i] += dp[j] * dp[i - j - 1];
  }

  return dp[n];
}

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> memo(N + 1, -1);
  std::cout << "FIB MEMO: " << fib_memo(N, memo) << std::endl;
  std::cout << "FIB TAB: " << fib_tabo(N) << std::endl;
  std::cout << "CATALAO DP: " << numero_catalao(N) << std::endl;
}
