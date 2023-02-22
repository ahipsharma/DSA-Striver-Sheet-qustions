/**
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/
int idx = 0;
void MyStack :: push(int x){
    if(top == 999)
        return;
    else{
        top++;
        arr[top] = x;
    }
}

//Function to remove an item from top of the stack.
int MyStack :: pop(){
    if(top == -1)
        return -1;
    else{
        int popEle = arr[top];
        top--;
        return popEle;
    }
}