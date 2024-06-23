class MyCircularQueue {
private:
    int* Queue;
    int size;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        this->size = k;
        Queue = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty())
            front = 0, rear = 0;
        else
            rear = (rear + 1) % size;
        Queue[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        if (front == rear)
            front = -1, rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return Queue[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return Queue[rear];
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear == (front - 1 + size) % size); }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */