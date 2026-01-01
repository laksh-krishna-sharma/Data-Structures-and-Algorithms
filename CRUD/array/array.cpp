#include <bits/stdc++.h>
using namespace std;

class ArrayCRUD {
   private:
    int sz;
    int* a;

   public:
    // Constructer -> Create Memory
    ArrayCRUD(int size) {
        sz = size;
        a = new int[sz];
    }

    // Insert
    void insert() {
        for (int i = 0; i < sz; i++) {
            cin >> a[i];
        }
    }

    // Read
    void read() const {
        for (int i = 0; i < sz; i++) {
            cout << a[i] << "\n";
        }
    }

    // Update
    void update(int indx, int val) {
        if (indx < 0 || indx >= sz) {
            cout << "Invalid Index\n";
        }
        a[indx] = val;
        cout << "Updated: " << a[indx] << "\n";
    }

    // Delete
    void remove(int indx) {
        if (indx < 0 || indx >= sz) {
            cout << "Invalid Index\n";
        }
        a[indx] = 0;
        cout << "Deleted: " << indx << "\n";
    }

    // Destructor → Free Memory
    ~ArrayCRUD() { delete[] a; }
};

int main() {
    int sz;
    cin >> sz;

    ArrayCRUD arr(sz);

    arr.insert();
    arr.read();

    int indx, val;
    cin >> indx >> val;
    arr.update(indx, val);

    int delIndx;
    cin >> delIndx;
    arr.remove(delIndx);

    return 0;
}
