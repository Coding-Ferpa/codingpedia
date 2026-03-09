#include <iostream>

#include "stdlib.h"
#include "time.h"
#include <vector>

void initialize_arr(std::vector<int> &arr, int N) {
  srand(time(0));
  for (int i = 0; i < N; i++) {
    arr.push_back(rand() % N);
  }
}

void initialize_sum_arr(std::vector<int> &sum, std::vector<int> &vet, int N) {
  sum.push_back(0);

  for (int i = 1; i < N; i++) {
    sum.push_back(sum.at(i - 1) + vet.at(i));
  }
}

void print_arr(std::vector<int> &A) {
  std::cout << "Arr[";
  for (int i = 0; i < A.size(); i++)
    std::cout << A.at(i) << " ";

  std::cout << "]" << std::endl;
}

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> vet, sum;
  initialize_arr(vet, N);
  initialize_sum_arr(sum, vet, N);
  print_arr(vet);
  std::cout << std::endl;
  print_arr(sum);
}
