/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int value) {
        // Add the new element to the back of q1
        q1.push(value);
        // Move all elements from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        // Swap the names of q1 and q2 so that q1 always holds the top element
        swap(q1, q2);
    }

//Function to pop an element from stack using two queues. 
int QueueStack :: pop(){
    if (q2.empty()) {
            // stack is empty
            return -1;
    } else {
        int popped_element = q2.front();
        q2.pop();
        return popped_element;
    }
}