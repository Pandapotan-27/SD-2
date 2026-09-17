#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int nilai;
    Node* next;
};

// Menampilkan isi linked list
void tampilkan(Node* head) {
    Node* bantu = head;

    cout << "Isi Linked List: ";

    if (head == nullptr) {
        cout << "Kosong";
    }

    while (bantu != nullptr) {
        cout << bantu->nilai;

        if (bantu->next != nullptr) {
            cout << " -> ";
        }

        bantu = bantu->next;
    }

    cout << endl;
}

// Tambah node di awal
void tambahAwal(Node*& head, int nilai) {
    Node* baru = new Node;

    baru->nilai = nilai;
    baru->next = head;
    head = baru;
}

// Tambah node di akhir
void tambahAkhir(Node*& head, int nilai) {
    Node* baru = new Node;

    baru->nilai = nilai;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* bantu = head;

    while (bantu->next != nullptr) {
        bantu = bantu->next;
    }

    bantu->next = baru;
}

// Tambah setelah nilai tertentu
void tambahSetelah(Node*& head, int nilaiCari, int nilaiBaru) {
    Node* bantu = head;

    while (bantu != nullptr && bantu->nilai != nilaiCari) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan.\n";
        return;
    }

    Node* baru = new Node;

    baru->nilai = nilaiBaru;
    baru->next = bantu->next;
    bantu->next = baru;
}

// Hapus node berdasarkan nilai
void hapusNode(Node*& head, int nilai) {
    if (head == nullptr) {
        cout << "Linked List masih kosong.\n";
        return;
    }

    // Jika yang dihapus adalah head
    if (head->nilai == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Node berhasil dihapus.\n";
        return;
    }

    Node* bantu = head;

    while (bantu->next != nullptr &&
           bantu->next->nilai != nilai) {
        bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan.\n";
        return;
    }

    Node* hapus = bantu->next;
    bantu->next = hapus->next;

    delete hapus;

    cout << "Node berhasil dihapus.\n";
}

int main() {
    Node* head = nullptr;
    int pilihan, nilai, nilaiCari;

    do {
        cout << "\n===== MENU LINKED LIST =====\n";
        cout << "1. Tambah di Awal\n";
        cout << "2. Tambah di Akhir\n";
        cout << "3. Tambah Setelah Nilai Tertentu\n";
        cout << "4. Hapus Berdasarkan Nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;

            tambahAwal(head, nilai);
            tampilkan(head);
            break;

        case 2:
            cout << "Masukkan nilai: ";
            cin >> nilai;

            tambahAkhir(head, nilai);
            tampilkan(head);
            break;

        case 3:
            cout << "Masukkan nilai yang dicari: ";
            cin >> nilaiCari;

            cout << "Masukkan nilai baru: ";
            cin >> nilai;

            tambahSetelah(head, nilaiCari, nilai);
            tampilkan(head);
            break;

        case 4:
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> nilai;

            hapusNode(head, nilai);
            tampilkan(head);
            break;

        case 5:
            tampilkan(head);
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}