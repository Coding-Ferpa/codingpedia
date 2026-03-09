// problema: https://olimpiada.ic.unicamp.br/pratique/p2/2020/f2/quebra/
#include <bits/stdc++.h>

using namespace std;

#define MAX 505
#define inf 0x3f3f3f3f;

int dp[MAX][MAX][MAX];
vector<int> vec_i, vec_j;

int solve(int p, int i, int j) {
  if (dp[p][i][j])
    return dp[p][i][j];

  // verificar indices 
  //
  // retornar solve com a multiplicacao
}

int main() {
  int n, m1, m2;
  scanf("%d", &n);

  cin >> m1;
  for (int i = 0; i < m2; i++)
    cin >> vec_i[i];

  cin >> m2;
  for (int i = 0; i < m2; i++)
    ::cin >> vec_j[i];

  cout << solve(0, 0, 0) << "\n";
}
