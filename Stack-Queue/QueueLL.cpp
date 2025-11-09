#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val):val(val),next(NULL){}
};
class Queue{
    Node* start;
    Node* end;
    int s;
public:
    Queue():start(NULL),end(NULL),s(0){}
    void push(int x){
        if(start==NULL){
            Node* temp=new Node(x);
            start=temp;
            end=temp;
        }
        else{
            end->next=new Node(x);
            end=end->next;
        }
        s++;
    }
    int top(){
        if(s==0) return -1;
        else return start->val;
    }
    void pop(){
        if(s==0) return;
        else if(s==1){
           start=NULL;
           end=NULL; 
        }
        else{
            start=start->next;
        }
        s--;
    }
};
int main(){
    Queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(5);
    qu.push(9);
    qu.pop();
    cout<<qu.top()<<endl;
    return 0;
}