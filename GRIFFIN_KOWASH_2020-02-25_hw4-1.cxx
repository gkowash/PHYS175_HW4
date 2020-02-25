#include <iostream>

using namespace std;

//function to find the sum of Fibonacci sequence up to maxVal
int fib(int maxVal) {
  int values[3] = {0,1,1};
  int total = 0;
  while (values[2] <= maxVal) {
    if (values[2] % 2 == 0) {
      total += values[2];
    }
    values[0] = values[1];
    values[1] = values[2];
    values[2] = values[0] + values[1];
  }
  return total;
}

int main() {
  cout << "Sum of all Fibbonacci numbers up to 4,000,000: " << fib(4000000) << endl;
  return 1;
}
