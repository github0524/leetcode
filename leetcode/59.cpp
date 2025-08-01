#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int index = 1;
        //���浱ǰλ��

        //if (n == 1) {
        //    m[0][0] = 1;
        //    return m;
        //}
        int len = n-1;
        int x=0, y=-1;
        int step=1;
        while (len >= 0)
        {
            y++;
            if (len==0)
            {
                m[x][y] = index;
                break;
            }
            //����
            while (step <= len)
            {
                m[x][y] = index;
                index++;
                y++;
                step++;
            }
            step = 1;
            //����
            while (step <= len)
            {
                m[x][y] = index;
                index++;
                x++;
                step++;
            }
            step = 1;
            //����
            while (step <= len)
            {
                m[x][y] = index;
                index++;
                y--;
                step++;
            }
            step = 1;
            //����
            while (step <= len)
            {
                m[x][y] = index;
                index++;
                x--;
                step++;
            }
            x++;
            step = 1;
            len = len - 2;

        }
        return m;
    }
};

int main()
{
    Solution so;
    auto m = so.generateMatrix(3);
    return 0;
}