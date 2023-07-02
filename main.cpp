#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {9, 23, 12, 2, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Measure execution time
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    // Measure space complexity
    int space = sizeof(arr) + sizeof(n);
    cout << "Space complexity: " << space << " bytes" << endl;

    return 0;
}

/*Waktu: Dalam kasus terburuk, Insertion Sort memiliki kompleksitas waktu O(n^2). Pada setiap iterasi, elemen saat ini dibandingkan dengan elemen-elemen sebelumnya dalam urutan terurut dan ditempatkan pada posisi yang tepat. Dalam kasus terburuk, di mana array dalam keadaan terbalik, setiap elemen harus bergeser ke posisi awal, yang menghasilkan n perulangan dalam iterasi pertama, n-1 perulangan dalam iterasi kedua, dan seterusnya, memberikan total n(n-1)/2 perulangan.
Ruang: Insertion Sort menggunakan jumlah ruang konstan, yaitu O(1), karena hanya ada penggunaan variabel tambahan dan tidak ada alokasi memori tambahan yang bergantung pada ukuran input.
Insertion Sort memiliki kelebihan yaitu efisien untuk jumlah data kecil atau data yang hampir terurut. Namun, untuk jumlah data yang besar, metode pengurutan lain seperti Quick Sort atau Merge Sort yang memiliki kompleksitas waktu lebih baik seperti O(nlogn) biasanya lebih disukai.
*/
