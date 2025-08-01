#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> st;
    int Min;

    void update_min()
    {
        stack<int> tmp;
        int m = INT_MAX;
        while (!st.empty())
        {
            tmp.push(st.top());
            m = min(m, st.top());
            st.pop();
        }
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
        Min = m;
    }
public:
    MinStack() {
        // st = new stack<int>();
        Min = INT_MAX;
    }

    void push(int val) {
        st.push(val);
        if (val < Min) Min = val;
    }

    void pop() {
        if (st.top() == Min)
        {
            st.pop();
            update_min();
        }
        else
        {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return Min;
    }
};

int main()
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_1 = obj->getMin();
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */