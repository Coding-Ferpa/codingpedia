#include <bits/stdc++.h>

using namespace std;

typedef struct vertex {
  long long x, y;
} vertex;

void check_point_location(vector<long long> &polygon_x,
                          vector<long long> &polygon_y, 
                          const vertex point,
                          int n) {
  bool inside = false;
  bool boundary = false;

  for (int i = 0; i < n; i++) {
    vertex p1 = {polygon_x[i], polygon_y[i]};
    vertex p2 = {polygon_x[(i + 1) % n], polygon_y[(i + 1) % n]};

    long long cross_product =
        (p2.y - p1.y) * (point.x - p1.x) - (p2.x - p1.x) * (point.y - p1.y);

    bool within_x = point.x >= min(p1.x, p2.x) && point.x <= max(p1.x, p2.x);
    bool within_y = point.y >= min(p1.y, p2.y) && point.y <= max(p1.y, p2.y);

    if (cross_product == 0 && within_x && within_y) {
      boundary = true;
      break;
    }

    if ((p1.y > point.y) != (p2.y > point.y)) {
      double x_intersect = (double)(p2.x - p1.x) * (point.y - p1.y) / (double)(p2.y - p1.y) + p1.x;
      if (point.x < x_intersect) 
        inside = !inside;
    }
  }

  if (boundary)
    cout << "BOUNDARY" << endl;
  else if (inside)
    cout << "INSIDE" << endl;
  else
    cout << "OUTSIDE" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<long long> polygon_x(n);
  vector<long long> polygon_y(n);
  vector<vertex> points_to_check(m);

  for (int i = 0; i < n; i++)
    cin >> polygon_x[i] >> polygon_y[i];

  for (int i = 0; i < m; i++)
    cin >> points_to_check[i].x >> points_to_check[i].y;

  for (const vertex &point : points_to_check)
    check_point_location(polygon_x, polygon_y, point, n);

  return 0;
}
