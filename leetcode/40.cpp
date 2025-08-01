#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
public:
    void backtracking(vector<int>& candidates, int target, int startIndex)
    {
        if (sum > target) return;
        //ÖÕÖ¹Ìõ¼ş
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        //
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            sum = sum + candidates[i];
            backtracking(candidates, target, i + 1);
            path.pop_back();
            sum = sum - candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};

int main()
{
    Solution so;
    vector<int> candidates{ 10,1,2,7,6,1,5 };
    int target = 8;
    
    so.combinationSum2(candidates, target);
    return 0;
}