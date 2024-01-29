class MyQueue
{
public:
    stack<int> front;
    stack<int> back;
    MyQueue()
    {
    }

    void push(int x)
    {
        front.push(x);
    }

    int pop()
    {
        int x;
        if (back.empty() == false)
        {
            x = back.top();
            back.pop();
            return x;
        }
        else
        {
            while (front.empty() == false)
            {
                back.push(front.top());
                front.pop();
            }
            x = back.top();
            back.pop();
            return x;
        }
    }

    int peek()
    {
        if (back.empty() == false)
            return back.top();
        else
        {
            while (front.empty() == false)
            {
                back.push(front.top());
                front.pop();
            }

            return back.top();
        }
    }

    bool empty()
    {
        return back.empty() && front.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */