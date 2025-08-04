#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false; // Because number cant be 100 because then reverse would have to be 001

        unsigned int reverse_order = 0;
        while (x > reverse_order) {
            reverse_order = reverse_order * 10 + x % 10;
            x /= 10;

        }

        return x == reverse_order || x == reverse_order / 10;
    }
};


int main() {

  Solution solution;
  int x = 1234321;

  bool check = solution.isPalindrome(x);

  cout << check << endl;
  return 0;
}
