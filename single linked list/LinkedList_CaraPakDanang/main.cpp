#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};
node *Node, *head;

void BuatLinkedlist(node *temp, int x){
    node *tail;
    head = new node();
    head->data = x;
    head->next = NULL;
    tail = head;
}

void InsertDepan(node *temp, int x){
    temp = new node();
    temp->data = x;
    if(head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void InsertBelakang(node *temp, int x){
    node *tail;
    temp = new node();
    temp->data = x;
    if(head == NULL){
        head = temp;
    }
    else{
        temp->data = x;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }

}

void InsertIntermediate(node *temp, int x, int pos){
    node* cur;
    temp = new node();
    temp->data = x;

    cur = head;
    int nomor = 1;
    while (nomor < pos - 1){
        cur = cur->next;
        nomor++;
    }
    temp->next = cur->next;
    cur->next = temp;
}

void HapusDepan(node *hapus){
    if (head == NULL){
        cout<<"Linked List id empty, please creat new Linked List"<<endl;
    }
    else{
        hapus = new node();
        head = head->next;
        delete hapus;
    }

}

void HapusBelakang(node *temp){
    node *hapus, *tail;
    hapus = tail;
    temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
    delete hapus;
}

void DeleteIntermediate(node *temp, int pos){
    node *cur, *before, *hapus;
    int nomor = 1;
    while(nomor <= pos){
        if(nomor == pos -1){
            before = cur;
        }
        if(nomor == pos){
            hapus = cur;
        }
        cur = cur->next;
        nomor++;
    }
    before->next = cur;
    delete hapus;
}

void cetak(){
    node *cur;
    cur = head;
    while (cur != NULL){
        cout << "["<<cur->data<<"]";
        if (cur->next == NULL){
            break;
        }
        cout << " -> ";
        cur = cur->next;
    }

}


int main(){
    node temp;
    BuatLinkedlist(&temp, 9);
    InsertDepan(&temp, 5);
    InsertBelakang(&temp, 7);
    InsertDepan(&temp, 6);
    InsertBelakang(&temp, 4);
    InsertBelakang(&temp, 8);
    HapusDepan(&temp);
    HapusBelakang(&temp);
    InsertIntermediate(&temp, 11, 2);
    DeleteIntermediate(&temp, 2);
    cetak();

}
