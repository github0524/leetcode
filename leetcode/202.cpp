#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (true)
        {
            n = getSum(n);
            if (n == 1)return true;
            if (hash.count(n))return false;
            hash.insert(n);
        }
        return false;
    }
};

int main()
{
    Solution so;
    so.isHappy(2);
    return 0;
}