#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};


void insertAthead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    head = n; 
}



void insertAttail(node* &head, int val) {
        node* n = new node(val);

        if (head == NULL) {
            head = n;
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }



void insertAtanyposition(node* head , int pos, int val) {
    node *n = new node(val), *r = head;
    int count = 1;
    
    // If the position is  0 then add at the beginning of the list.
    if (pos == 0){
        insertAthead(head, val);
        return ;
    }
    /* Create a loop so that we can traverse till the required position */
    while (count < pos && r != NULL) {
        r = r->next;
        count++;
    }
    n->next = r;
    r->next = n;
}  



// deletion of a node from linked list 

void deleteAthead(node* &head) {
    node* todelete= head;
    head=head->next;
    delete todelete;
}


void Deletenode(node* &head,int val){
    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        deleteAthead(head);
        return;
        }
node* temp=head;
while(temp->next->data!=val){
    temp=temp->next;
}
node* todelete=temp->next;
temp->next=temp->next->next;

delete todelete;
}



void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



bool search(node *head, int key){
   
   node* temp = head;
   while(temp!=NULL){
      if(temp->data==key) {
         return true;
      }
      temp=temp->next;
   }
   return false;
} 

// reversing k nodes in Linked list


node* reversek(node *head,int k ){
    node* curr = NULL;
    node* prev=NULL;
    node* next;
    int count =0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL){
        head->next = reversek(next,k);
    }
    return prev;
}

int main() {
    node* head = NULL;
    insertAttail(head, 1);
    insertAttail(head, 2);
    insertAttail(head, 3);
    print(head);
    
    insertAthead(head, 4);
    print(head);

    // cout<<search(head,5);

    Deletenode(head, 1);
    print(head);

    return 0;
}
