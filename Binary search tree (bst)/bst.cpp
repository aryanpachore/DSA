#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};

node* InsertintoBst(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }

    if (d > root->data) {
        root->right = InsertintoBst(root->right, d);
    } else {
        root->left = InsertintoBst(root->left, d);
    }

    return root;
}

node* takeInput() {
    node* root = NULL;
    int data;
    cin >> data;

    while (data != -1) {
        root = InsertintoBst(root, data);
        cin >> data;
    }
    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


int minElement(node* root){
    node* temp = root;
    while(temp->left!= NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxElement(node* root){
    node* temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    return temp->data;
}

node* deleteFrombst(node* root , int x){
    if(root == NULL){
        return root;
    }
    if(root->data == x){
        //0child

        if(root->right==NULL && root->left==NULL){
            delete root;
        }
        //1child

        if(root->right!=NULL && root->left==NULL){
            node* temp = root;
            root = root->right;
            delete temp;
        }
        if(root->right==NULL && root->left!=NULL){
            node* temp = root;
            root = root->left;
            delete temp;
        }

        //2child
        if(root->right!=NULL && root->left!=NULL){
            int mini = minElement(root->right);
            root->data=mini;
            root->right = deleteFrombst(root->right,mini);
            return root;
        }


    }else if(root->data > x){
        root->left = deleteFrombst(root->left , x);
    }else{
        root->right = deleteFrombst(root->right , x);
    }
}

int main() {
    cout << "Enter data to create BST" << endl;
    node* root = takeInput();
    levelOrderTraversal(root);
    return 0;
}
