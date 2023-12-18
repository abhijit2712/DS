#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void take_input(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << "\t"; 
        temp = temp->next;
    }

    cout << endl;
}

//2)Insert At head
void InsertAtHead(Node* &head,Node* &tail,int data){
    //step 1 : Create a Node
    Node* newNode = new Node(data);

    // step 2 : Empty Linked list case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    //Step 3: Point NewNode next to previous head
    newNode->next = head;

    //step 4:Point head to newNode
    head = newNode; 
}

//3)Insert At tail
void insertAtTail(Node* &head,Node* &tail,int data){
     //step 1 : Create a Node
    Node* newNode = new Node(data);

    // step 2 : Empty Linked list case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    
    //step 3 : Point tail->next to newnode
    tail->next = newNode;

    //step 4: Point tail to newNode
    tail = newNode;
}


//4)Insert At position

//find lenght of linked list 
int findLenght(Node* &head){
    if(head == NULL) return 0;
    int len = 1;
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


//Insert position funtion 
void insertAtPosition(int data,int position,Node* &head,Node* &tail){
    //Step 1: Empty linked list 
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 1){
        InsertAtHead(head,tail,data);
        return;
    }
    //Step 2 : find tha lenght of the string 
    int len = findLenght(head);

    if(len == position){
        insertAtTail(head,tail,data);
        return;
    }
    //Insert when postion is not starting and ending

    //step 1 : find the position of prev and curr
    int i = 1;
    Node* prev = head;
    Node* curr = head;

    while(i <= position){
        prev = curr;
        curr = curr->next;
        i++;
    }

    //step2 : create a new Node
    Node* newNode = new Node(data);

    //step3 : Point newNode next to curr
    newNode->next = curr;

    //step4 : point prev next to newNode
    prev->next = newNode;
}

void deleteAtBegin(Node* &head, Node* &tail){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
}

void deleteAtTail(Node* &head, Node* &tail,int position){
    //find prev
    int i =  1;
    Node* prev = head;

    while(i < position-1){
        prev = prev->next;
        i++;
    }

    //step 2 :
    prev->next = NULL;

    //step 3 : copy tail into the temp
    Node* temp = tail;

    //step 4 : point prev to tail
    tail = prev;

    //step 5 : delete the node
    delete temp;
    return;
}

void deleteOperation(int position,Node* &head, Node* &tail){
    if(head == NULL){
        cout << "Connot delete, LL is empty";
        return;
    }

    //delete firstm Node
    if(position == 1){
        deleteAtBegin(head,tail);
        return;
    }

    //find the length of last node
    int len = findLenght(head);

    //if position is last then delete the node
    if(position == len){
        deleteAtTail(head,tail,position);
        return;
    }


    int i = 0;
    Node* prev = NULL;
    Node* curr = head;

    while(i < position){
        prev = curr;
        curr = curr->next;
        i++;
    }

    //step2 : skip current node
    prev->next = curr->next;

    //step3 : make curr next NULL
    curr->next = NULL;

    //step4 : delete curr node
    delete curr;

    return;
}


int main(){
    take_input();

    Node *head = new Node(10);
    Node *tail = head;
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtPosition(70,1,head,tail);
    deleteOperation(1,head,tail);
    print(head);

    return 0;
}
