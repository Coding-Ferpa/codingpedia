// using heap because it is faster to initialize fr
#include <iostream>
#include <vector>
#include <random>

using namespace std;

#define N 5

#define left(i) (int(2 * i) + 1)
#define right(i) (int(2 * i) + 2)

int search(int k, vector<int>& h, int i = 0) {
    if (i >= N + 1)
        return -1;

    if (h[i] == k)
        return h[i];

    int left = search(k, h, left(i));
    int right = search(k, h, right(i));

    if (left == k) {
        cout << k << " found at " << left(i) << endl;
        return left;
    }

    if (right == k) {
        cout << k << " found at " << right(i) << endl;
        return right;
    }

    return -1;
}

int main() {
    vector<int> heap(N + 1);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 100);

    for (int i = 0; i < N; ++i)
        heap[i] = dis(gen);

    search(5, heap);
}