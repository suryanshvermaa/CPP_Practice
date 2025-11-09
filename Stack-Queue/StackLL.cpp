#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data):data(data),next(nullptr){
    }
};
class Stack{
    int s;
    Node* t;
public:
    Stack(): s(0), t(nullptr) {}

    void push(int x){
      Node* temp = new Node(x);
      temp->next = t;
      t = temp;
      s++;
    }

    int top(){
        if(t==NULL) return -1;
        else return t->data;
    }

    void pop(){
        if(t==NULL) return;
        else{
            t = t->next;
            s--;
        }
    }
};

int main(){
    Stack st;
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    cout << st.top() << endl;
    st.push(4);
    st.push(4);
    cout << st.top() << endl;
    return 0;
}