#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;       // array untuk menyimpan elemen stack
    int top;        // indeks elemen paling atas
    int capacity;   // kapasitas maksimal stack

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Fungsi Push
    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack penuh! Tidak bisa menambahkan data.\n";
            return;
        }
        arr[++top] = value;
        cout << value << " berhasil ditambahkan ke stack.\n";
    }

    // Fungsi Pop
    void pop() {
        if (top == -1) {
            cout << "Stack kosong! Tidak ada data yang bisa dihapus.\n";
            return;
        }
        cout << arr[top--] << " berhasil dihapus dari stack.\n";
    }

    // Fungsi Peek
    void peek() {
        if (top == -1) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Elemen paling atas: " << arr[top] << endl;
    }

    // Fungsi IsEmpty
    bool isEmpty() {
        return top == -1;
    }

    // Fungsi Size
    int size() {
        return top + 1;
    }
};

int main() {
    int kapasitas;
    cout << "Masukkan kapasitas maksimal stack: ";
    cin >> kapasitas;

    Stack s(kapasitas);
    int pilihan, data;

    do {
        cout << "\n=== MENU STACK ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. IsEmpty\n";
        cout << "5. Size\n";
        cout << "6. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            s.push(data);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            cout << (s.isEmpty() ? "Stack kosong\n" : "Stack tidak kosong\n");
            break;
        case 5:
            cout << "Jumlah elemen dalam stack: " << s.size() << endl;
            break;
        case 6:
            cout << "Keluar program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}