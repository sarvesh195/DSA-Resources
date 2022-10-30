class MyCircularDeque {
    int size, front, rear, *arr;
public:
    MyCircularDeque(int k) : size(k), front(-1), rear(-1), arr(new int[k]) {  } 
   
    //put front at right place then insert
    bool insertFront(int value) {
        if (isFull())  return false;
        if (isEmpty()) front = rear = 0;
        else if (front == 0) front = size -1;
        else front--;
        arr[front] = value;
        return true;
    }
    //put rear at right place then insert
    bool insertLast(int value) {
        if (isFull())  return false;
        if (isEmpty()) front = rear = 0;
        else if (rear == size-1)  rear = 0;
        else rear++;
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())  return false;
        if (front == rear) front = rear = -1;
        else if (front == size-1) front = 0;
        else front++;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())  return false;
        if (rear == front) front = rear = -1;
        else if (rear == 0) rear = size-1; 
        else rear--;
        return true;
    }
    
    int getFront() { return isEmpty() ? -1 : arr[front]; }
    
    int getRear() { return isEmpty() ? -1 : arr[rear]; }
    
    bool isEmpty() { return (front == -1); }
    
    bool isFull() { return ((front == 0 && rear == size-1) || (rear == front-1)); }
    
    //optional fix memory leak in the code
    ~MyCircularDeque ()
    {
        delete []arr;
    }
};
