#include <iostream>
using namespace std;

template <typename T>
class Stack{
    int maxSize;
    int t;
    T* arr;
public:
    Stack(int size = 10){
        t = -1;
        maxSize = size;
        arr = new T[size];
    }
    ~Stack(){
        delete[] arr;
    }

    void push(T x){
        if (t + 1 == maxSize) {
            cout << "stack is full" << endl;
            return;
        }
        t++;
        arr[t] = x;
    }

    T top(){
        if (t == -1) {
            cout << "stack is empty" << endl;
            return T();
        }
        return arr[t];
    }

    void pop(){
        if (t == -1) {
            cout << "stack is empty" << endl;
            return;
        }
        t--;
    }
};

int main(){
    Stack<int> st(20);
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