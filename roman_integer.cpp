#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> char_to_int = {{'I',1}, {'V',5}, {'X',10}, {'L', 50}, {'C',100}, {'D', 500} ,{'M',1000}};

        int value = 0;
        for (int i = 0; i < s.length(); ++i){
            int num = char_to_int[s[i]];

            if (i >= s.length() - 1){
                value += num;
                break;
            }

            int next_num = char_to_int[s[i+1]];
            if (num < next_num){
                value -= num;
            }else{
                value += num;
            }
        }

        return value;
    }
};

int main(){

   Solution solution;
   string s = "MCMXCIV";
   cout << solution.romanToInt(s) << endl;
   return 0;
}
