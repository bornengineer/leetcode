class MyCircularQueue {
public:
    vector<int> v;
    int rear = 0 , front = 0, size = 0;
    
    MyCircularQueue(int k) {
        v.resize(k); // resizing it to 'k'
        fill(v.begin(), v.end(), -1); // filling all indexes of queue to -1
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        //to handle the first enqueue
        if(isEmpty()){
            rear = 0;
            front = 0;
            v[rear] = value;
            size++;
            return true;
        }
        rear++;
        // to handle the circular behaviour of queue
        rear = rear % v.size();
        v[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        // here we will put -1 to the front & increment it
        v[front] = -1;
        size--;
        front++;
        // to handle the circular behaviour of queue
        front = front % v.size();
        return true;
    }
    
    int Front() {
        return v[front];
    }
    
    int Rear() {
        return v[rear];
    }
    
    bool isEmpty() {
        return size == 0;     
    }
    
    bool isFull() {
        return size == v.size();
    }
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