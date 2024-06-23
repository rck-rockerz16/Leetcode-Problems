class MyCircularDeque {
private:
    int* Deque;
    int size;
    int front = -1;
    int rear = -1;

public:
    MyCircularDeque(int k) {
        size = k;
        Deque = new int[size];
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        if (isEmpty())
            front = 0, rear = 0;
        else
            front = (front - 1 + size) % size;

        Deque[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        if (isEmpty())
            front = 0, rear = 0;
        else
            rear = (rear + 1) % size;
        Deque[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        if (front == rear)
            front = -1, rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        if (front == rear)
            front = -1, rear = -1;
        else
            rear = (rear - 1 + size) % size;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return Deque[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return Deque[rear];
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear == (front - 1 + size) % size); }
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