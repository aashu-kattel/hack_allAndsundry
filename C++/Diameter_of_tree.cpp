#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(){
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    Node* root = new Node(data);
    root->left = buildTree();

    root->right = buildTree();

    return root;

}

void levelwiseprint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int height(Node* root){

    if(root==NULL){
        return 0;
    }

   int leftans = height(root->left);
    int rightans = height(root->right);

    int ans = max(leftans,rightans) + 1;

    return ans;
}


int diameter(Node* root){

if(root==NULL) return 0;

int op1 = diameter(root->left);
int op2 = diameter(root->right);

int op3 = height(root->left) + height(root->right);

int ans = max(op1,max(op2,op3));

return ans;



}

int main(){

    Node* root = NULL;
    root = buildTree();

    levelwiseprint(root);
cout<<endl;

int h = height(root);

cout<<h<<endl;


cout<<endl;

int d = diameter(root);

cout<<d<<endl;
    return 0;
}
