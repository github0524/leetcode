#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (st.empty())
                st.push(i);
            if (temperatures[i] <= temperatures[st.top()])
            {
                st.push(i);
                continue;
            }
            while ( !st.empty() && temperatures[i] > temperatures[st.top()] )
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};

int main()
{
    Solution so;
    vector<int> vec{ 73,74,75,71,69,72,76,73 };
    so.dailyTemperatures(vec);
    return 0;
}