//Nama: Jaka Saputra
//NPM: G1A016020
//Kelas: Informatika-B

#include <iostream>
using namespace std;

struct DLL{ //struct
    
    int Number;
    DLL* next;
    DLL* prev;

};

DLL *first, *last, *cur, *add, *after, *addLast, *afterNode, *del;

//deklarasi node awal
void buatDll (int Num){
    first = new DLL;  
    first->Number = Num;
    first->prev = NULL;
    first->next = NULL;
    last = first;
}
//insert first
void insertFirst (int Num){
    add = new DLL;
    add->Number = Num;
    add->prev = NULL;
    add->next = first;
    first->prev = add;
    first = add;
}
//insert after
void insertAfter(int Num, int pos){
    after= new DLL;
    after->Number = Num;
//transversing
    cur = first;
    int nomor = 1 ;
    while (nomor < pos -1 ){
        cur = cur->next;
        nomor++;       
    }
    afterNode = cur->next;
    after->prev = cur;
    after->next = afterNode;
    cur->next = after;
    afterNode->prev = after; 
}
//insert last
void insertLast(int Num){
    addLast = new DLL;
    addLast->Number= Num;
    addLast->prev = last;
    addLast->next = NULL;
    last->next = addLast;
    last = addLast;  
}
//deleteFirst
void deleteFirst(){
    del = first;
    first = first->next;
    first->prev = NULL;
    delete del;
}
//deleteAfter
void deleteAfter(int pos){
    int nomor = 1;
    cur = first;
    while (nomor < pos -1 ){
        cur = cur->next;
        nomor++;
    }
    del = cur->next;
    afterNode = del->next;
    cur->next = afterNode;
    afterNode->prev = cur;
    delete del;
} 
//deleteLast
void deleteLast(){
    del = last;
    last = last->prev;
    last->next = NULL;
    delete del;
}
//search
int search(int key){
    DLL* p = first;
    int i = 1;
    while (p->Number != key){
        p = p->next;
        i++;
    }
    return i;
}
//print
void printDLL(){
    cur = first;
    while (cur != NULL){
        cout << cur-> Number << " ";
        cur = cur->next;
    }
    cout<<endl;    
}

int main(){

    buatDll(12); //create Node
    printDLL(); //print

    insertFirst(32); //insert First
    printDLL(); //print

    insertFirst(24); //insert First
    printDLL(); //print

    insertAfter(4,3); //insert After "menyisipkan node di posisi ke-3"
    printDLL(); //print

    insertAfter(1,4); //insert After "menyisipkan node di posisi ke-4"
    printDLL(); //print

    insertLast(5); //insert last
    printDLL(); //print

    deleteFirst(); //delete first
    printDLL(); //print

    deleteAfter(3); //delete after "menghapus node di posisi ke-3"
    printDLL(); //print

    deleteLast(); //delete last
    printDLL(); //print

    int key; //key search
    cout<<"masukkan data yang ingin dicari"; //menginput kan data yang ingin di cari 
    cin>>key;
    cout<<"data "<< key << " diurutan ke- "<< search(key); 
}