#include <iostream>
#include <string>
using namespace std;

struct Siswa {
    long int NIS;
    string nama;
    string kelas;
};

struct Node {
    Siswa siswa;
    Node* next;
};

Node* head = NULL;

void insertFront(Siswa mhs) {
    Node* newNode = new Node(); 
    newNode->siswa = mhs;

    newNode->next = head;
    head = newNode;
    cout << "Berhasil memasukkan diawal: " << mhs.nama << " " << mhs.kelas << endl;
}

void insertRear(Siswa mhs) {
    Node* newNode = new Node();
    newNode->siswa = mhs;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Berhasil memasukkan diakhir: " << mhs.nama << " " << mhs.kelas << endl;
}

void insertAfterNode(Node* prevNode, Siswa mhs) {
    if (prevNode == NULL) {
        cout << "Node sebelumnya tidak boleh NULL!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->siswa = mhs;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    cout << "Berhasil memasukkan setelah " << prevNode->siswa.nama << endl;
}

void deleteFront() {
    if (head == NULL) {
        cout << "List kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Menghapus data pertama: " << temp->siswa.nama << " " << temp->siswa.kelas << endl;
    delete temp; 
}

void deleteRear() {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }
    
    if (head->next == NULL) {
        cout << "Menghapus data terakhir: " << head->siswa.nama << head->siswa.kelas << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "Menghapus data terakhir: " << temp->next->siswa.nama << " " << head->siswa.kelas << endl;
    delete temp->next;
    temp->next = NULL;
}

void display() {
    Node* temp = head;
    cout << "\n--- Daftar Siswa ---" << endl;
    while (temp != NULL) {
        cout << "[" << temp->siswa.NIS << "] " << temp->siswa.nama << " " << "[" << temp->siswa.kelas << "]" << endl;
        temp = temp->next;
    }
    cout << "------------------------\n" << endl;
}

int main() {
    Siswa m1 = {557821, "Almas Yafi", "VI/A"};
    Siswa m2 = {569855, "Ahmad Syafii", "IV/C"};
    Siswa m3 = {549842, "Kevin Aris", "V/D"};

    insertFront(m1);   
    insertRear(m3);      
    insertAfterNode(head, m2); 

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}