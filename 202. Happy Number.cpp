/*
 * compute until n == 1 or a previous number has appeared
 * use a set to keep track of appeared numbers
**/
class Solution {
public:
    bool isHappy(int n) {
        set<int> sumTemp;
        while (n != 1) {
            int sum = 0;
            int temp;
            while (n) {
                temp = n % 10;      // last digit
                sum += temp * temp;
                n /= 10;            // shift n
            }
            n = sum;
            
            if(sumTemp.find(n)==sumTemp.end()){
                sumTemp.insert(n);
            }
            else {
                return false;
            }
        }
        return true;
    }
};