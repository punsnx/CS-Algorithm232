#include <iostream>
using namespace std;

typedef struct _Node{
    short data;
    _Node *next;
}Node;

void addNode(Node **head,short data){
    Node *newNode = new Node;
    newNode->next = NULL;
    newNode->data = data;

    Node *cur = *head,*prev=NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }
    while(cur && cur->data < data){
        prev = cur;
        cur = cur->next;
    }
    if(cur && prev==NULL){
        newNode->next = cur;//head
        *head = newNode;
        return;
    }
    prev->next = newNode;
}

int main(){
    return 0;
}