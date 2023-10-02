#include <iostream>
using namespace std;
// implementing Node
class Node
{
public:
    int data;
    Node* next;

    Node(int v)
    {
        this->data = v;
        this->next = NULL;
    }
};
// Insertion 
//Insert at head
void addFirst(Node* &head, int d)
{
    // new node create called temp
    Node* temp = new Node(d);

    // temp's next pointer points towards head of the old node
    temp->next = head;

    // now, head points at the newly inserted node at the beginning(changing the position of head to new node)
    head = temp;
}

//insert at Tail
void addLast(Node* &tail, int d)
{
    // new node create called temp
    Node* temp = new Node(d);

    //present tail's next pointer points at temp node
    tail->next = temp;

    //tail always points at last node(tail's next=tail)
    tail = tail->next;
}

//insert at position
void addAtPosition(Node* &tail, Node* &head, int pos, int d)
{
    if(pos==1){
        addFirst(head, d);
        return;
    }// if the given position for inserting element is 1, addFirst is called.

    Node* temp= head;
    int cnt=1;
    
    if(temp->next==NULL){
        addLast(tail, d);
        return;
    }
    

    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }

    //creating a new node to insert
    Node* Nodenew = new Node(d);
    Nodenew->next=temp->next;
    temp->next=Nodenew;
    tail=Nodenew;
}

// Traverse in LL
void print(Node* &head){
    //initialize
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    //cout << node1->data << endl;
    //cout << node1->next << endl; // gives garbage value without a constructor of Node().

    //head points to node1
    Node* head= node1;
    Node* tail= node1;
    print(head);

    addLast(tail, 12);
    print(head);
    
    addLast(tail, 15);
    print(head);

    addLast(tail, 19);
    print(head);
    //----At head
    addFirst(head, 13);
    print(head);
    
    addFirst(head, 14);
    print(head);

    addFirst(head, 18);
    print(head);
    //--At position
    addAtPosition(tail, head, 3, 22);
    print(head);
    addAtPosition(tail, head, 1, 30); //if condition in addFirst is called.
    print(head);
    addAtPosition(tail, head, 10, 56);
    print(head);

    //to check for head and tail data
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    return 0;
}
