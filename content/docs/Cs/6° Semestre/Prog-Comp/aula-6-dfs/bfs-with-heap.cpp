#include <iostream>
#include <vector>
#include <queue>
#include <random>

using namespace std;

#define N 5

#define left(i) (2 * i + 1)
#define right(i) (2 * i + 2)

int bfs(int k, vector<int>& h) {
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int i = q.front();
		q.pop();

		if (i >= h.size())
            continue;

		if (h[i] == k) {
			cout << k << " found at index " << i << endl;
			return i;
		}

		if (left(i) < h.size())
            q.push(left(i));
            
		if (right(i) < h.size())
            q.push(right(i));
	}

	cout << k << " not found" << endl;
	return -1;
}

int main() {
	vector<int> heap(N + 1);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 100);

	for (int i = 0; i < N + 1; ++i)
		heap[i] = dis(gen);

	int k = 5;
	bfs(k, heap);
}
