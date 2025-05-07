#include <iostream>
using namespace std;

const int MAKS_MK = 10;     // Maksimum jumlah matakuliah
const int BIAYA_PER_SKS = 125000;

class Mahasiswa {
public:
    void input();
    void tampil();
    int hitungTotalSKS(int index);  // Fungsi rekursif

private:
    string nim;
    string nama;
    string matkul[MAKS_MK];
    int sks[MAKS_MK];
    int jumlahMatkul;
};

void Mahasiswa::input() {
    cout << "Masukkan NIM: ";
    cin >> nim;
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Jumlah Matakuliah yang diambil: ";
    cin >> jumlahMatkul;

    for (int i = 0; i < jumlahMatkul; i++) {
        cin.ignore();
        cout << "\nMatakuliah ke-" << (i + 1) << ": ";
        getline(cin, matkul[i]);
        cout << "Jumlah SKS untuk " << matkul[i] << ": ";
        cin >> sks[i];
    }
}

int Mahasiswa::hitungTotalSKS(int index) {
    if (index < 0)
        return 0;
    return sks[index] + hitungTotalSKS(index - 1);
}

void Mahasiswa::tampil() {
    cout << "\n\n===== RINCIAN PEMBAYARAN SKS =====\n";
    cout << "NIM           : " << nim << endl;
    cout << "Nama Mahasiswa: " << nama << endl;

    cout << "\nDaftar Matakuliah:\n";
    for (int i = 0; i < jumlahMatkul; i++) {
        cout << "- " << matkul[i] << " (" << sks[i] << " SKS)\n";
    }

    int totalSKS = hitungTotalSKS(jumlahMatkul - 1);
    int totalBiaya = totalSKS * BIAYA_PER_SKS;
    float diskon = totalBiaya * 0.15f;
    float bayarAkhir = totalBiaya - diskon;

    cout << "\nTotal SKS         : " << totalSKS << endl;
    cout << "Total Biaya SKS   : Rp. " << totalBiaya << endl;
    cout << "Potongan Pandemi  : Rp. " << diskon << endl;
    cout << "Total Pembayaran  : Rp. " << bayarAkhir << endl;
}

int main() {
    Mahasiswa mhs;
    mhs.input();
    mhs.tampil();

    return 0;
}

