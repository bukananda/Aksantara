#include <iostream>
using std::string;

class Contact {
    private:
        string nama;
        string tempat_tinggal;
        string alamat;
        string kekuatan;
    public:
        Contact(string nama = "", string tempat_tinggal = "", string alamat = "", string kekuatan = ""){
            this->nama = nama;
            this->tempat_tinggal = tempat_tinggal;
            this->alamat = alamat;
            this->kekuatan = kekuatan;
        }

        string getName(){
            return this->nama;
        }

        string getTempatTinggal(){
            return this->tempat_tinggal;
        }

        string getAddress(){
            return this->alamat;
        }

        string getPower(){
            return this->kekuatan;
        }
};

class PhoneBook {
    private:
        int i = 0;
        Contact array_kontak[8];
    public:
        void ADD(Contact kontak){
            array_kontak[i] = kontak;
            i++;
            i %= 8;
            std::cout << "\n\nKontak telah disimpan" << "\n";
            std::cout << "Nama: "<< kontak.getName() << "\n";
            std::cout << "Tempat Tinggal: " << kontak.getTempatTinggal() << "\n";
            std::cout << "Alamat: " << kontak.getAddress() << "\n";
            std::cout << "Kekuatan: " << kontak.getPower() << "\n\n";
        }

        void SEARCH(){
            int pilihan_kontak;

            std::cout << "Pilihan kontak yang ada pada PhoneBook" << "\n";
            for (int j = 0; j < 8; j++){
                if (!array_kontak[j].getName().empty()){
                    std::cout << j+1 << ". " << array_kontak[j].getName() << "\n";
                } else {
                    break;
                };
            };

            std::cout << "Pilihan: ";
            std::cin >> pilihan_kontak;

            std::cout << "\n";
            if (!array_kontak[pilihan_kontak-1].getName().empty()){
                std::cout << "Nama: "<< array_kontak[pilihan_kontak-1].getName() << "\n";
                std::cout << "Tempat Tinggal: " << array_kontak[pilihan_kontak-1].getTempatTinggal() << "\n";
                std::cout << "Alamat: " << array_kontak[pilihan_kontak-1].getAddress() << "\n";
                std::cout << "Kekuatan: " << array_kontak[pilihan_kontak-1].getPower() << "\n\n";
            } else {
                std::cout << "Pilihan kontak yang anda cari tidak ada pada PhoneBook" << "\n\n";
            };
        }

        void EXIT(){
            i = 0;
            for (int l = 0; l < 8; l++){
                array_kontak[l] = Contact("","","","");
            };
            std::cout << "\nSemua data yang ada pada PhoneBook telah terhapus";
        }
};

int main(){
    PhoneBook buku_telepon;
    bool running = 1;
    int pilihan;

    string nama_kontak, tempat_tinggal, alamat, kekuatan;

    while (running) {
        std::cout << "Pilihan user" << "\n";
        std::cout << "1. Menambah kontak\n2. Mencari kontak\n3. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;
        switch (pilihan) {
            case 1:
                std::cout << "\nMasukkan nama kontak: ";
                std::getline(std::cin >> std::ws, nama_kontak);

                std::cout << "Masukkan tempat tinggal: ";
                std::getline(std::cin >> std::ws, tempat_tinggal);

                std::cout << "Masukkan alamat: ";
                std::getline(std::cin >> std::ws, alamat);

                std::cout << "Masukkan kekuatan: ";
                std::getline(std::cin >> std::ws, kekuatan);

                buku_telepon.ADD(Contact(nama_kontak, tempat_tinggal, alamat, kekuatan));
                break;

            case 2:
                buku_telepon.SEARCH();
                break;

            case 3:
                buku_telepon.EXIT();
                running = 0;
                break;

            default:
                std::cout << "Input invalid\n\n";
                break;
        }
    }

    return 0;
}