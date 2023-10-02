#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void print(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int main(){

    Node* first = new Node(18);
        Node* second = new Node(11);

    Node* third = new Node(19);

    Node* fourth = new Node(28);

    Node* fifth = new Node(14);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next=fifth;
    fifth->next = NULL;

    print(first);

    return 0;
}
