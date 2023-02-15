/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
private:
    void insert(int elem);
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */


void insert(int elem, stack<int> &s){
    if(s.empty() || s.top() < elem){
        s.push(elem);
        return;
    }
    int temp = s.top();
    s.pop();
    insert(elem, s);
    s.push(temp);
}

void SortedStack::sort(){
    if(!s.empty()){
        int temp = s.top();
        s.pop();
        sort();
        insert(temp, s);
    }
}