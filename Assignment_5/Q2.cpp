#include <iostream>
using namespace std;
class SinglyLinkedList{
    class Node{int data;Node* next;};
    Node* head;
public:
    SinglyLinkedList(){head=NULL;}
    void create(int a[],int n){
        head=new Node{a[0],NULL};
        Node* t=head;
        for(int i=1;i<n;i++){t->next=new Node{a[i],NULL};t=t->next;}
    }
    void countAndDelete(int key){
        int c=0;
        Node* t=head;
        while(t){if(t->data==key)c++;t=t->next;}
        while(head&&head->data==key){Node* d=head;head=head->next;delete d;}
        Node* curr=head;
        while(curr&&curr->next){
            if(curr->next->data==key){Node* d=curr->next;curr->next=d->next;delete d;}
            else curr=curr->next;
        }
        cout<<"Count: "<<c<<", Updated Linked List: ";
        t=head;
        while(t){cout<<t->data; if(t->next) cout<<"->"; t=t->next;}
        cout<<"."<<endl;
    }
};
int main(){
    SinglyLinkedList s;
    int a[]={1,2,1,2,1,3,1};
    s.create(a,7);
    s.countAndDelete(1);
}

