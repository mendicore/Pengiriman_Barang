#include "Rute.h"

using namespace std;

int main(){
    Graph G;
    TruckList T;

    Create_Graph(G);
    Create_Truck(T);

    Infotype_Gudang gudang1, gudang2, gudang3, gudang4, gudang5, gudang6, gudang7, gudang8, gudang9, gudang10;

    // Gudang 1
    gudang1.nama = "Makmur";
    gudang1.lokasi = "Jakarta";
    gudang1.kapasitas = 5000;
    gudang1.barang = 4200;
    Addr_Vertex_Gudang newGudang1 = Alokasi_Gudang(gudang1);
    Add_Vertex_Gudang(G, newGudang1);

    // Gudang 2
    gudang2.nama = "Sentosa";
    gudang2.lokasi = "Surabaya";
    gudang2.kapasitas = 7000;
    gudang2.barang = 6700;
    Addr_Vertex_Gudang newGudang2 = Alokasi_Gudang(gudang2);
    Add_Vertex_Gudang(G, newGudang2);

    // Gudang 3
    gudang3.nama = "Sejahtera";
    gudang3.lokasi = "Bandung";
    gudang3.kapasitas = 6000;
    gudang3.barang = 5100;
    Addr_Vertex_Gudang newGudang3 = Alokasi_Gudang(gudang3);
    Add_Vertex_Gudang(G, newGudang3);

    // Gudang 4
    gudang4.nama = "Mandiri";
    gudang4.lokasi = "Semarang";
    gudang4.kapasitas = 8000;
    gudang4.barang = 6900;
    Addr_Vertex_Gudang newGudang4 = Alokasi_Gudang(gudang4);
    Add_Vertex_Gudang(G, newGudang4);

    // Gudang 5
    gudang5.nama = "Surya";
    gudang5.lokasi = "Medan";
    gudang5.kapasitas = 5500;
    gudang5.barang = 4800;
    Addr_Vertex_Gudang newGudang5 = Alokasi_Gudang(gudang5);
    Add_Vertex_Gudang(G, newGudang5);

    // Gudang 6
    gudang6.nama = "Cemerlang";
    gudang6.lokasi = "Yogyakarta";
    gudang6.kapasitas = 4500;
    gudang6.barang = 3900;
    Addr_Vertex_Gudang newGudang6 = Alokasi_Gudang(gudang6);
    Add_Vertex_Gudang(G, newGudang6);

    // Gudang 7
    gudang7.nama = "Emas";
    gudang7.lokasi = "Bali";
    gudang7.kapasitas = 6500;
    gudang7.barang = 6200;
    Addr_Vertex_Gudang newGudang7 = Alokasi_Gudang(gudang7);
    Add_Vertex_Gudang(G, newGudang7);

    // Gudang 8
    gudang8.nama = "Sehat";
    gudang8.lokasi = "Surabaya";
    gudang8.kapasitas = 5500;
    gudang8.barang = 4700;
    Addr_Vertex_Gudang newGudang8 = Alokasi_Gudang(gudang8);
    Add_Vertex_Gudang(G, newGudang8);

    // Gudang 9
    gudang9.nama = "Otomotif";
    gudang9.lokasi = "Jakarta";
    gudang9.kapasitas = 7000;
    gudang9.barang = 6300;
    Addr_Vertex_Gudang newGudang9 = Alokasi_Gudang(gudang9);
    Add_Vertex_Gudang(G, newGudang9);

    // Gudang 10
    gudang10.nama = "Bagus";
    gudang10.lokasi = "Bekasi";
    gudang10.kapasitas = 8000;
    gudang10.barang = 7200;
    Addr_Vertex_Gudang newGudang10 = Alokasi_Gudang(gudang10);
    Add_Vertex_Gudang(G, newGudang10);

    Infotype_PomBensin pombensin1, pombensin2, pombensin3;

    // Pom Bensin 1
    pombensin1.nama = "Pertamina";
    pombensin1.stokBensin = 15000;
    pombensin1.lokasi = "Cibubur";
    Addr_Vertex_PomBensin newPomBensin1 = Alokasi_PomBensin(pombensin1);
    Add_Vertex_PomBensin(G, newPomBensin1);

    // Pom Bensin 2
    pombensin2.nama = "Shell";
    pombensin2.stokBensin = 12000;
    pombensin2.lokasi = "Bogor";
    Addr_Vertex_PomBensin newPomBensin2 = Alokasi_PomBensin(pombensin2);
    Add_Vertex_PomBensin(G, newPomBensin2);

    // Pom Bensin 3
    pombensin3.nama = "Total";
    pombensin3.stokBensin = 10000;
    pombensin3.lokasi = "Bandung";
    Addr_Vertex_PomBensin newPomBensin3 = Alokasi_PomBensin(pombensin3);
    Add_Vertex_PomBensin(G, newPomBensin3);


    Infotype_Truck truck1, truck2;

    // Truck 1
    truck1.nama = "Vortex";
    truck1.kapasitas = 8000;
    truck1.muatan = 0;
    truck1.bensin = 150;
    Addr_Truck newTruck1 = Alokasi_Truck(truck1);
    Add_Truck(T, newTruck1);

    // Truck 2
    truck2.nama = "Titan";
    truck2.kapasitas = 10000;
    truck2.muatan = 0;
    truck2.bensin = 120;
    Addr_Truck newTruck2 = Alokasi_Truck(truck2);
    Add_Truck(T, newTruck2);


    Connecting_Gudang(G, "Makmur", "Sejahtera", "Jalan Merpati Raya", 3.5, "tidak");
    Connecting_Gudang(G, "Sejahtera", "Mandiri", "Jalan Pahlawan", 1.2, "ya");
    Connecting_Gudang_To_PomBensin(G, "Makmur", "Total", "Jalan Bunga Melati", 4.7, "tidak");
    Connecting_PomBensin_To_Gudang(G, "Total", "Surya", "Jalan Cendrawasih", 2.3, "tidak");
    Connecting_Gudang(G, "Surya", "Mandiri", "Jalan Mutiara Biru", 5.1, "tidak");
    Connecting_Gudang(G, "Mandiri", "Emas", "Jalan Damarwulan ", 6, "tidak");
    Connecting_Gudang(G, "Mandiri", "Cemerlang", "Jalan Seroja ", 2.8, "tidak");
    Connecting_Gudang_To_PomBensin(G, "Cemerlang", "Pertamina", "Jalan Kenanga", 3.9, "ya");
    Connecting_PomBensin_To_Gudang(G, "Pertamina", "Emas", "Jalan Taman Sari ", 1.6, "tidak");
    Connecting_PomBensin_To_Gudang(G, "Pertamina", "Sehat", "Jalan Gunung Bromo ", 7.4, "tidak");
    Connecting_Gudang(G, "Emas", "Otomotif", "Jalan Surya Kencana", 4.2, "tidak");
    Connecting_Gudang(G, "Emas", "Bagus", "Jalan Bintang Laut", 3, "ya");
    Connecting_Gudang(G, "Sehat", "Otomotif", "Jalan Cipta Karya ", 2.5, "tidak");
    Connecting_Gudang(G, "Bagus", "Otomotif", "Jalan Alam Raya ", 5.6, "tidak");
    Connecting_Gudang(G, "Bagus", "Sentosa", "Jalan Puspa Indah ", 6.8, "tidak");
    Connecting_Gudang_To_PomBensin(G, "Otomotif", "Shell", "Jalan Pahlawan Tani", 4.3, "tidak");
    Connecting_PomBensin_To_Gudang(G, "Shell", "Sentosa", "Jalan Cempaka Putih  ", 2.9, "tidak");

    int choice, jumBarang;
    string warehouse1, warehouse2, station, truck, rute, macet;
    double jarak;
    do{
        cout << "<<===========================================" << endl;
        cout << "                     MENU                    " << endl;
        cout << "===========================================>>" << endl;
        cout << "1.  Tambah Gudang" << endl;
        cout << "2.  Hapus Gudang" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "3.  Tambah Pom bensin" << endl;
        cout << "4.  Hapus Pom bensin" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "5.  Tambah Truck" << endl;
        cout << "6.  Hapus Truck" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "7.  Hubungkan Gudang" << endl;
        cout << "8.  Putuskan Gudang" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "9.  Hubungkan Gudang dengan Pom bensin" << endl;
        cout << "10. Hubungkan Pom bensin dengan Gudang" << endl;
        cout << "11. Putuskan Gudang dengan Pom bensin" << endl;
        cout << "12. Putuskan Pom Bensin dengan Gudang" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "13. Tampilkan Graph" << endl;
        cout << "14. Tampilkan semua Truck" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "15. Lakukan pengiriman." << endl;
        cout << "0.  Keluar" << endl;
        cout << "<===========================================>" << endl;
        cout << "Pilih pilihan: ";
        cin >> choice;
        cout << endl;

        switch(choice) {
            case 1 : {
                // Tambah Gudang
                Infotype_Gudang gudang;
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, gudang.nama);
                cout << "Masukkan lokasi Gudang: ";
                getline(cin, gudang.lokasi);
                cout << "Masukkan kapasitas Gudang: ";
                cin >> gudang.kapasitas;
                cout << "Masukkan jumlah Barang di Gudang: ";
                cin >> gudang.barang;
                if(gudang.kapasitas <= gudang.barang){
                    cout << "Jumlah barang tidak bisa melebihi kapasitas gudang!" << endl;
                }
                Addr_Vertex_Gudang newGudang = Alokasi_Gudang(gudang);
                Add_Vertex_Gudang(G, newGudang);

                cout << "\n Gudang " << gudang.nama << " berhasil ditambahkan!" << endl;
                break;
            }

            case 2 : {
                // Hapus Gudang
                cout << endl << "Masukkan nama Gudang yang ingin dihapus: ";
                cin.ignore();
                getline(cin, warehouse1);
                Addr_Vertex_Gudang delGudang = Find_Vertex_Gudang(G, warehouse1);
                 if (delGudang != NULL) {
                    Delete_Vertex_Gudang(G, delGudang);
                    cout << "Gudang " << warehouse1 << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Gudang dengan nama " << warehouse1 << " tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 3 : {
                 // Tambah Pom Bensin
                Infotype_PomBensin pombensin;
                cout << endl << "Masukkan nama Pom bensin: ";
                cin.ignore();
                getline(cin, pombensin.nama);
                cout << endl << "Masukkan lokasi Pom bensin: ";
                getline(cin, pombensin.lokasi);
                cout << endl << "Masukkan stok bahan bakar: ";
                cin >> pombensin.stokBensin;
                Addr_Vertex_PomBensin newPomBensin = Alokasi_PomBensin(pombensin);
                Add_Vertex_PomBensin(G, newPomBensin);
                cout << "Pom bensin " << pombensin.nama << " berhasil ditambahkan!" << endl << endl;
                break;
            }

            case 4 : {
                 // Hapus Pom Bensin
                cout << endl << "Masukkan nama Pom Bensin yang ingin dihapus: ";
                cin.ignore();
                getline(cin, station);
                Addr_Vertex_PomBensin stationToDelete = Find_Vertex_PomBensin(G, station);
                if (stationToDelete != NULL) {
                    Delete_Vertex_PomBensin(G, stationToDelete);
                    cout << "Pom Bensin " << station << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Pom Bensin dengan nama " << station << " tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 5 : {
                 // Tambah Truck
                Infotype_Truck truck;
                cout << endl << "Masukkan nama Truck: ";
                cin.ignore();
                getline(cin, truck.nama);
                cout << "Masukkan kapasitas truck: ";
                cin >> truck.kapasitas;
                cout << "Masukkan jumlah bensin: ";
                cin >> truck.bensin;

                truck.muatan = 0;
                Addr_Truck newTruck = Alokasi_Truck(truck);
                Add_Truck(T, newTruck);
                cout << "Truck " << truck.nama << " berhasil ditambahkan!" << endl << endl;
                break;
            }

            case 6 : {
                // Hapus Truck
                cout << endl << "Masukkan nama Truck yang ingin dihapus: ";
                cin.ignore();
                getline(cin, truck);
                Addr_Truck delTruck = Find_Truck(T, truck);
                if (delTruck != NULL) {
                    Delete_Truck(T, delTruck);
                   cout << "Truck " << truck << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Truck dengan nama " << truck << " tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 7 : {
                 // Sambungkan Kedua Gudang
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, warehouse1);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, warehouse2);
                cout << "Masukkan nama jalan: ";
                getline(cin, rute);
                cout << "Masukkan jarak antar Gudang: ";
                cin >> jarak;
                cout << "Apakah jalan macet? (ya/tidak) ";
                getline(cin, macet);
                Connecting_Gudang(G, warehouse1, warehouse2, rute, jarak, macet);
                cout << "Gudang " << warehouse1 << " dan " << warehouse2 << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 8 : {
                // Putuskan Kedua Gudang
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, warehouse1);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, warehouse2);

                Addr_Vertex_Gudang disconnect1 = Find_Vertex_Gudang(G, warehouse1);
                Addr_Vertex_Gudang disconnect2 = Find_Vertex_Gudang(G, warehouse2);

                if (disconnect1 != NULL && disconnect2 != NULL) {
                    Disconnecting_Gudang(G, warehouse1, warehouse2);
                    cout << "Rute antara Gudang " << warehouse1 << " dan " << warehouse2 << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Salah satu atau kedua Gudang tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 9 : {
                 // Sambungkan Gudang dengan Pom Bensin
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, warehouse1);
                cout << "Masukkan nama Pom bensin: ";
                getline(cin, station);
                cout << "Masukkan nama jalan: ";
                getline(cin, rute);
                cout << "Masukkan jarak Gudang dan Pom Bensin: ";
                cin >> jarak;
                cout << "Apakah jalan macet? (ya/tidak) ";
                getline(cin, macet);
                Connecting_Gudang_To_PomBensin(G, warehouse1, station, rute, jarak, macet);
                cout << "Gudang " << warehouse1 << " dan Pom Bensin " << station << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 10 : {
                  // Sambungkan Gudang dengan Pom Bensin
                cout << endl << "Masukkan nama Pom bensin: ";
                cin.ignore();
                getline(cin, station);
                cout << "Masukkan nama Gudang: ";
                getline(cin, warehouse1);
                cout << "Masukkan nama jalan: ";
                getline(cin, rute);
                cout << "Masukkan jarak Gudang dan Pom Bensin: ";
                cin >> jarak;
                cout << "Apakah jalan macet? (ya/tidak) ";
                getline(cin, macet);
                Connecting_PomBensin_To_Gudang(G, warehouse1, station, rute, jarak, macet);
                cout << "Pom Bensin " << station << " Gudang " << warehouse1 << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 11 : {
                // Putuskan Gudang dengan Pom Bensin
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, warehouse1);
                cout << "Masukkan nama Pom bensin: ";
                getline(cin, station);

                Addr_Vertex_Gudang disconnect1 = Find_Vertex_Gudang(G, warehouse1);
                Addr_Vertex_PomBensin disconnect2 = Find_Vertex_PomBensin(G, station);

                if (disconnect1 != NULL && disconnect2 != NULL) {
                    Disconnecting_Gudang_PomBensin(G, warehouse1, station);
                    cout << "Rute antara Gudang " << warehouse1 << " dan Pom bensin " << station << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Salah satu atau kedua bangunan tersebut tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 12 : {
                // Putuskan Pom Bensin dengan Gudang
                cout << endl << "Masukkan nama Pom bensin: ";
                cin.ignore();
                getline(cin, station);
                cout << "Masukkan nama Gudang: ";
                getline(cin, warehouse1);

                Addr_Vertex_PomBensin disconnect1 = Find_Vertex_PomBensin(G, station);
                Addr_Vertex_Gudang disconnect2 = Find_Vertex_Gudang(G, warehouse1);

                if (disconnect1 != NULL && disconnect2 != NULL) {
                    Disconnecting_PomBensin_Gudang(G, station, warehouse1);
                    cout << "Rute antara Pom bensin  " << warehouse1 << " dan Gudang" << station << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Salah satu atau kedua bangunan tersebut tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 13 : {
                // menampilkan graph
                Show_Graph(G);
                break;
            }

            case 14 : {
                // menampilkan list truck
                Show_Trucks(T);
                break;
            }

            case 15 : {
                // melakukan pengiriman
                Show_Trucks(T);
                cout << "Masukan nama truck yang ingin digunakan: ";
                cin.ignore();
                getline(cin, truck);
                Addr_Truck truk = Find_Truck(T, truck);
                if (truk != NULL) {
                    if(truk->Info.bensin >= 0) {
                        cout << "Masukan nama gudang pengirim: ";
                        getline(cin, warehouse1);
                        Addr_Vertex_Gudang foundPengirim = Find_Vertex_Gudang(G, warehouse1);
                        if (foundPengirim != NULL) {
                            if (foundPengirim->Info.barang != 0) {
                                cout << "Masukan nama gudang penerima: ";
                                getline(cin, warehouse2);
                                Addr_Vertex_Gudang foundPenerima = Find_Vertex_Gudang(G, warehouse2);
                                if(foundPenerima != NULL) {
                                    Infotype_Gudang pengirim = foundPengirim->Info;
                                    // Menampilkan informasi gudang pengirim
                                    cout << endl << "Informasi Gudang pengirim " << pengirim.nama << endl;
                                    cout << "Lokasi                     : " << pengirim.lokasi << endl;
                                    cout << "Kapasitas Gudang           : " << pengirim.kapasitas << endl;
                                    cout << "Jumlah Barang di Gudang    : " << pengirim.barang << endl << endl;

                                    // Menampilkan informasi gudang penerima
                                    Infotype_Gudang penerima = foundPenerima->Info;
                                    cout << endl << "Informasi Gudang penerima " << penerima.nama << endl;
                                    cout << "Lokasi                     : " << penerima.lokasi << endl;
                                    cout << "Kapasitas Gudang           : " << penerima.kapasitas << endl;
                                    cout << "Jumlah Barang di Gudang    : " << penerima.barang << endl << endl;

                                    // Meminta jumlah barang yang akan diantar
                                    cout << "Masukkan jumlah barang yang ingin diantar: ";
                                    cin >> jumBarang;
                                    if(jumBarang <= truk->Info.kapasitas && jumBarang <= pengirim.barang) {
                                        cout << "Pengiriman akan dilakukan dari Gudang " << pengirim.nama << " ke Gudang " << penerima.nama << endl;
                                        cout << "Jumlah barang yang akan dikirim: " << jumBarang << endl;
                                        Rute_Tercepat(G, truk, foundPengirim, foundPenerima, jumBarang); // Perbaikan titik koma
                                    } else {
                                        cout << "Tidak dapat mengangkut barang!" << endl;
                                        break;
                                    }
                                } else {
                                    cout << "Gudang penerima tidak ditemukan!" << endl;
                                    break;
                                }
                            } else {
                                cout << "Gudang pengirim tidak memiliki stok barang!" << endl;
                                break;
                            }
                        } else {
                            cout << "Gudang pengirim tidak ditemukan!" << endl;
                            break;
                        }
                    } else {
                        cout << "Truck tidak memiliki bensin!" << endl;
                        break;
                    }
                } else {
                    cout << "Truck tidak ditemukan!" << endl;
                    break;
                }
                break;
            }
        }
    }while(choice != 0);

    return 0;
}
