#include <bits/stdc++.h>
#include <queue>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m;

  priority_queue<int> max_result;
  priority_queue<int, vector<int>, greater<int>> min_result;

  cin >> n >> m;

  int inputs[n];

  for (int i = 0; i < n; i++) {
    cin >> inputs[i];
  }

  for (int i : inputs) {
    max_result.push(i);
    min_result.push(i);
  }

  for (int i = 0; i < m; i++) {
    int max_result_local = max_result.top();
    max_result.pop();
    int min_result_local = min_result.top();

    int k1 = ceil(max_result_local / 2);
    int k2 = floor(max_result_local / 2);

    max_result.push(k1);
    max_result.push(k2);

    min_result.push(k1);
    min_result.push(k2);

    max_result_local = max_result.top();
    min_result_local = min_result.top();
    cout << max_result_local - min_result_local;

    if (i != m - 1)
      cout << " ";
  }
  cout << endl;
}
