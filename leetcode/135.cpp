/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 // @lc code=start
/*
class Solution {
public:
    int candy(vector<int>& ratings) {
        //把整个直线上的点画出一张折线图，第一个点算0，上升+1，下降-1
        vector<int> candy;
        int MIN=0,rest;
        int total = 0,total2=0,total3=0;//等号的不同用法，也是不对的，可能有时候等号是加有时候是减去，有时候是向右，这个具体情况无法考虑
        candy.resize(ratings.size());
        if (ratings.size() == 1) return 1;
        for (int i = 1; i < ratings.size(); i++)
        {
            rest = ratings[i] - ratings[i - 1];
            candy[i] =rest > 0 ? candy[i-1]+1 : ( candy[i-1] - 1);
            //这个写法每次只选1和candy最小的，但是MIN却不在迭代中
            //MIN = min(1, candy[i]);
            MIN = min(MIN, candy[i]);
            total += candy[i];
        }
        //MIN最大都是0，糖果最少一颗
        return total + (1 - MIN) * ratings.size();
    }
};
*/
// @lc code=end
//当当candy[i]>candy[i+1时]，candy[i+1]=candy+1

//看似从左向右比一次，然后从右向左比一次，这样的逻辑似乎没有什么关联
//但是真的得关键在于，第一次比较的时候比的是左比右大的点应该选择右+1，还是第一轮左边的值，当然是取二者中最大的，符合题目要求比临近的都大。
//初始数组全部赋值是1

class Solution {
public:
    int candy(vector<int>& ratings) {
        /*从左到右*/
        vector<int> value(ratings.size(), 1);
        int sum = 0;
        if (ratings.size() < 2) {
            return 1;
        }
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                value[i + 1] = value[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i >= 1; i--) {
            if (ratings[i] < ratings[i - 1]) {
                value[i - 1] = value[i - 1] > value[i] + 1 ? value[i - 1] : value[i] + 1;
            }
        }
        for (auto k : value)
        {
            sum += k;
        }
        return sum;
    }
};

int main() {
    Solution so;
    vector<int> nums = { 1,3,4,5,2 };
    cout << so.candy(nums) << endl;
    return 0;
}
