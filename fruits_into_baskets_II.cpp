#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed = 0;

        for (int i = 0; i < fruits.size(); ++i) {
            for (int j = 0; j < baskets.size(); ++j) {
                if (fruits[i] <= baskets[j]) {
                    baskets[j] = 0;
                    placed++;
                    break;
                }
            }
        }

        return fruits.size() - placed;
    }
};


int main(){

    Solution solution;

    vector<int> fruits = {6,5};
    vector<int> baskets = {3,5};

    int remaining = solution.numOfUnplacedFruits(fruits, baskets);

    cout << remaining << endl;

    return 0;
}
