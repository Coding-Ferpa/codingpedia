#include <iostream>
#include <vector>

using namespace std;

long long products_at_time(long long time, const std::vector<int> &k) {
  long long count = 0;
  for (int interval : k) {
    if (interval > 0) {
      count += time / interval;
    }
  }
  return count;
}

void solve_with_binary_search() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  long long t;
  std::cin >> n >> t;

  std::vector<int> k(n);
  for (int i = 0; i < n; i++) {
    std::cin >> k[i];
  }

  if (n == 1) {
    cout << t * k[0] << endl;
    return;
  }

  long long low = 0;
  long long high = 1e18;
  long long ans = high;

  while (low <= high) {
    long long mid = low + (high - low) / 2;

    if (products_at_time(mid, k) >= t) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  std::cout << ans << std::endl;
}

int main() {
  solve_with_binary_search();
  return 0;
}
