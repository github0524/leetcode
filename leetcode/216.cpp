#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
public:
    void backtracking(int k, int n, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == n) result.push_back(path);
            else return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            path.push_back(i);
            sum = sum + i;
            backtracking(k, n, i + 1);
            path.pop_back();
            sum = sum - i;
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);
        return result;
    }
};
int main()
{
    Solution so;
    so.combinationSum3(9, 45);
    return 0;
}