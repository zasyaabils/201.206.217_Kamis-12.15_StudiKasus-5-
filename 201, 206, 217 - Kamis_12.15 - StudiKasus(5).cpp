#include <iostream>
using namespace std;

class Mahasiswa {
	
public:
	void input();
	int hitung(int n,int biaya);
	void tampil();	
	
private:
	string nama, matkul[99], nim;
	int totalSks = 0, sks[99], jumlahMatkul, biaya = 125000, total_biaya;
	int j=0;
	
};
void Mahasiswa::input(){
	cout << "Masukkan Nama : ";
	cin >> nama;
	cin.ignore();
	cout << "Masukkan NIM : ";
	getline(cin,nim);
	cout << "Masukkan Jumlah MataKuliah : ";
	cin >> jumlahMatkul;
	
	cout << endl;
	
	for(int i=0; i<jumlahMatkul; i++ ){
	cin.ignore();
	cout << "Masukkan nama mata kuliah ke- " << (i+1) << ": ";
	getline(cin, matkul[i]);
	cout << "Masukkan jumlah SKS mata kuliah: ";
	cin >> sks[i];
	
	cout << endl;
	}
}

int Mahasiswa::hitung(int n, int biaya) {
	if(n<=0){
	return 0;
	}
	else{
	return biaya + hitung(n-1,biaya);
	}
}
void Mahasiswa::tampil(){
	cout << "+============================+" << endl;
	cout << "|PROGRAM HITUNG UKT MAHASISWA|" << endl;
	cout << "+============================+" << endl;
	cout << "|Masukkan Nama: " << nama << endl;
	cout << "|Masukkan NIM: " << nim << endl;
	cout << "|Masukkan Jumlah MataKuliah: " << jumlahMatkul << endl;
	cout << "+============================+";
	
	cout << "\nDaftar MataKuliah\n";
	for (int i=0; i < jumlahMatkul; i++){
	totalSks += sks[i];
		}
		cout << "\n=============================" << endl;
		cout << "Total Sks : " << totalSks << endl;
		total_biaya = hitung(totalSks,biaya);
		cout << "Total Pembayaran : " << total_biaya - (total_biaya  * 0.15) << endl;
		cout << "=============================" << endl;
}
	
		
int main() {
	Mahasiswa x;
	x.input();
	x.tampil();
	
	return 0;
}
