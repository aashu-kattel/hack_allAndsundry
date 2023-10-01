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
    root->right=buildTree();

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

void inorder(Node* root){
    if(root==NULL){
        return;
    }

    //LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void leftview(Node* root, vector<int> &ans,int level){
    if(root==NULL) return;

    if(level==ans.size()){
        ans.push_back(root->data);
    }

    leftview(root->left,ans,level+1);
    leftview(root->right,ans,level+1);
}

int main(){

    Node* root=NULL;
    root=buildTree();

    levelwiseprint(root);

    cout<<endl;
    cout<<"Inorder traversal"<<":- ";
    inorder(root);

    cout<<endl;

    vector<int> ans;
    int level = 0;

    leftview(root,ans,level);

    cout<<"left view"<<":-";
    for(auto value : ans){
        cout<<value<<" ";
    }
    cout<<endl;


    

    return 0;
}
