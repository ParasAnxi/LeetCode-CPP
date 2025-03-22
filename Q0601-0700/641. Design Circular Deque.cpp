class MyCircularDeque
{
public:
    vector<int> v;
    int front;
    int rear;
    int count;
    int k;
    MyCircularDeque(int k)
    {
        v = vector<int>(k, 0);
        front = 0;
        rear = k - 1;
        this->k = k;
        count = 0;
    }
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = (front - 1 + k) % k;
        v[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        rear = (rear + 1) % k;
        v[rear] = value;
        count++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % k;
        count--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + k) % k;
        count--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        else
        {
            return v[front];
        }
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return v[rear];
        }
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */