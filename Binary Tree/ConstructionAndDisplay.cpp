#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left=NULL;
    Node *right=NULL;
    Node(int data,Node *left,Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

Node *constructTree(vector<int> &arr){
/*  Steps:
    1. Make a node from first value of array and declare it as root node
    2. Create a stack of Pair of Node and integer to maintain state i.e stack<pair<Node*,int>> st;
    3. Make pair of root node and keep its state as 1
    4. Push root node into stack
    5. Keep an index value to track arrays values start it from 0;
    6. while(stack's size > 0):
        6.1. Check top of stack
            6.1.1. if( state of node == 1 ) add left child to it
            6.1.2. if( State of node == 2 ) add right child to it 
            6.1.2. if( State of node == 3 ) pop from stack; 

*/


    stack<pair<Node*,int>> st;
    Node *root=new Node(arr[0],nullptr,nullptr);
    st.push(make_pair(root,1));
    int i=0;
    while(st.size()>0){
        pair<Node *,int> p=st.top();
        if(p.second==1){
            i++;
            if(arr[i]!=-1){
                Node *lchild=new Node(arr[i],nullptr,nullptr);
                p.first->left=lchild;
                pair<Node*,int> lch=make_pair(lchild,1);
                p.second++;
                st.pop();
                st.push(p);
                st.push(lch);
            }else{
                p.second++;
                st.pop();
                st.push(p);
            }
        }else if(p.second==2){
            i++;
            if(arr[i]!=-1){
                Node *rchild=new Node(arr[i],nullptr,nullptr);
                p.first->right=rchild;
                pair<Node*,int> rch=make_pair(rchild,1);
                p.second++;
                st.pop();
                st.push(p);
                st.push(rch);
            }else{
                p.second++;
                st.pop();
                st.push(p);
            }
        }else{
            st.pop();
        }
    }
    return root;
}


void display(Node *root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        cout<<root->left->data<<"<- ";
    }else{
        cout<<". <- ";
    }
    cout<<root->data<<" -> ";
    if(root->right!=NULL){
        cout<<root->right->data<<"";
    }else{
        cout<<".";
    }
    cout<<endl;
    display(root->left);
    display(root->right);
}

int main() {
    vector<int> arr={50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    Node *root=constructTree(arr);
    display(root);
}
