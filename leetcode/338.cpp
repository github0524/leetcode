#include <vector>
using namespace std;

class Solution {
public:
    int countone(int n)
    {
        int ret = 0;
        while (n)
        {
            if (n & 1 > 0) ret++;
            n = n >> 1;
        }
        return ret;
    }
    vector<int> countBits(int n) {
        vector<int> vec;
        for (int i = 0; i <= n; i++)
        {
            vec[i] = countone(i);
        }
        return vec;
    }
};

int main()
{
    Solution so;
    so.countBits(2);
    return 0;
}