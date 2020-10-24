#include <vector>
#include <iostream>
using namespace std;

class MyCircularQueue {
public:
    vector<int> v;
    int start=0;
    int end=0;
    int numberOfElements=0;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        v.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(end==v.size())
            end=0;
        v[end++]=value;
        cout<<"end index is " << end<<endl;
        numberOfElements++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isFull())
            return false;
        if(start==v.size())
            start=0;
        start++;
        numberOfElements--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return v[start];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return v[end-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return numberOfElements==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return numberOfElements>=v.size();
    }
};


int main(int argc, char const *argv[])
{
    MyCircularQueue* obj = new MyCircularQueue(3);
    obj->enQueue(1);
    obj->enQueue(2);
    obj->enQueue(3);
    obj->enQueue(4);    
    int rearValue = obj->Rear();
    cout<<rearValue<<endl;
    return 0;
}
