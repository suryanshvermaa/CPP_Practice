#include<iostream>
using namespace std;
template<typename T>
class Queue{
    int start,end,currSize;
    T* qu;
    int size;
public:
    Queue(int size){
        this->size=size;
        start=-1;
        end=-1;
        currSize=0;
        qu=new T[size];
    }
    ~Queue(){
        delete[] qu;
    }
    void push(T x){
        if(currSize==size) cout<<"full"<<endl;
        else if(currSize==0){
            currSize++;
            start++;
            end++;
            qu[end]=x;
        }
        else{
            currSize++;
            end=(end+1)%size;
            qu[end]=x;
        }
    }
    T top(){
        if(currSize==0) return T();
        else return qu[start];
    }
    void pop(){
        if(currSize==0) return;
        else if(currSize==1){
            currSize--;
            start=-1;
            end=-1;
        }
        else{
            currSize--;
            start=(start+1)%size;
        }
    }
};
int main(){
    Queue<int> qu(10);
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(5);
    qu.push(9);
    qu.pop();
    cout<<qu.top()<<endl;
    return 0;
}