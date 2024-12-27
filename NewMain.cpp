#include "Pengiriman.h"

int main(int argc, char** argv)
{
    Graph G;
    TruckList T;

    Create_Graph(G);
    Create_Truck(T);

    Infotype_Gudang gudangs[10] = {
        {"Makmur", "Jakarta", 5000, 4200},
        {"Sentosa", "Surabaya", 7000, 6700},
        {"Sejahtera", "Bandung", 6000, 5100},
        {"Mandiri", "Semarang", 8000, 6900},
        {"Surya", "Medan", 5500, 4800},
        {"Cemerlang", "Yogyakarta", 4500, 3900},
        {"Emas", "Bali", 6500, 6200},
        {"Sehat", "Surabaya", 5500, 4700},
        {"Otomotif", "Jakarta", 7000, 6300},
        {"Bagus", "Bekasi", 8000, 7200}
    };

    for (int i = 0; i < 10; ++i) {
        Addr_Vertex newGudang = Alokasi_Vertex("Gudang", gudangs[i], {});
        Add_Vertex(G, newGudang, "Gudang");
    }

    Infotype_PomBensin pombensins[3] = {
        {"Pertamina", "Cibubur", 15000},
        {"Shell", "Cibubur", 12000},
        {"Total", "Bandung", 10000}
    };

     for (int i = 0; i < 3; ++i) {
        Addr_Vertex newPomBensin = Alokasi_Vertex("PomBensin", {}, pombensins[i]);
        Add_Vertex(G, newPomBensin, "PomBensin");
    }


    Infotype_Truck trucks[2] = {
        {"Vortex", 8000, 0, 150},
        {"Titan", 10000, 0,  120}
    };

     for (int i = 0; i < 2; ++i) {
        Addr_Truck newTruck = Alokasi_Truck(trucks[i]);
        Add_Truck(T, newTruck);
    }

    Connecting_Vertex(G, "Makmur", "Sejahtera", "Jalan Merpati Raya", 3.5, "tidak");
    Connecting_Vertex(G, "Sejahtera", "Mandiri", "Jalan Pahlawan", 1.2, "ya");
    Connecting_Gudang_To_PomBensin(G, "Makmur", "Total", "Jalan Bunga Melati", 4.7, "tidak");
    Connecting_PomBensin_To_Gudang(G, "Total", "Surya", "Jalan Cendrawasih", 2.3, "tidak");
    Connecting_Vertex(G, "Surya", "Mandiri", "Jalan Mutiara Biru", 5.1, "tidak");
    Connecting_Vertex(G, "Mandiri", "Emas", "Jalan Damarwulan ", 6, "tidak");
    Connecting_Vertex(G, "Mandiri", "Cemerlang", "Jalan Seroja ", 2.8, "tidak");
    Connecting_Gudang_To_PomBensin(G, "Cemerlang", "Pertamina", "Jalan Kenanga", 3.9, "ya");
    Connecting_PomBensin_To_Gudang(G, "Pertamina", "Emas", "Jalan Taman Sari ", 1.6, "tidak");
    Connecting_PomBensin_To_Gudang(G, "Pertamina", "Sehat", "Jalan Gunung Bromo ", 7.4, "tidak");
    Connecting_Vertex(G, "Emas", "Otomotif", "Jalan Surya Kencana", 4.2, "tidak");
    Connecting_Vertex(G, "Emas", "Bagus", "Jalan Bintang Laut", 3, "ya");
    Connecting_Vertex(G, "Sehat", "Otomotif", "Jalan Cipta Karya ", 2.5, "tidak");
    Connecting_Vertex(G, "Bagus", "Otomotif", "Jalan Alam Raya ", 5.6, "tidak");
    Connecting_Vertex(G, "Bagus", "Sentosa", "Jalan Puspa Indah ", 6.8, "tidak");
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
                Addr_Vertex newGudang = Alokasi_Vertex("Gudang", gudang, {});
                Add_Vertex(G, newGudang, "Gudang");
                break;
            }

            case 2 : {
                // Hapus Gudang
                cout << endl << "Masukkan nama Gudang yang ingin dihapus: ";
                cin.ignore();
                getline(cin, warehouse1);
                Addr_Vertex delGudang = Find_Vertex(G, warehouse1, "Gudang");
                 if (delGudang != NULL) {
                    Delete_Vertex(G, delGudang, "Gudang");
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
                Addr_Vertex newPomBensin = Alokasi_Vertex("PomBensin", {}, pombensin);
                Add_Vertex(G, newPomBensin, "PomBensin");
                break;
            }

            case 4 : {
                 // Hapus Pom Bensin
                cout << endl << "Masukkan nama Pom Bensin yang ingin dihapus: ";
                cin.ignore();
                getline(cin, station);
                Addr_Vertex stationToDelete = Find_Vertex(G, station, "PomBensin");
                if (stationToDelete != NULL) {
                    Delete_Vertex(G, stationToDelete, "PomBensin");
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
                cin.ignore();
                getline(cin, macet);
                Connecting_Vertex(G, warehouse1, warehouse2, rute, jarak, macet);
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

                Addr_Vertex disconnect1 = Find_Vertex(G, warehouse1, "Gudang");
                Addr_Vertex disconnect2 = Find_Vertex(G, warehouse2, "Gudang");

                if (disconnect1 != NULL && disconnect2 != NULL) {
                    Disconnecting_Vertex(G, warehouse1, warehouse2);
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
                cin.ignore();
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
                cin.ignore();
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

                Addr_Vertex disconnect1 = Find_Vertex(G, warehouse1, "Gudang");
                Addr_Vertex disconnect2 = Find_Vertex(G, station, "PomBensin");

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

                Addr_Vertex disconnect1 = Find_Vertex(G, station, "PomBensin");
                Addr_Vertex disconnect2 = Find_Vertex(G, warehouse1, "Gudang");

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
                        Addr_Vertex foundPengirim = Find_Vertex(G, warehouse1, "Gudang");
                        if (foundPengirim != NULL) {
                            if (foundPengirim->gudang.barang != 0) {
                                cout << "Masukan nama gudang penerima: ";
                                getline(cin, warehouse2);
                                Addr_Vertex foundPenerima = Find_Vertex(G, warehouse2, "Gudang");
                                if(foundPenerima != NULL) {
                                    Infotype_Gudang pengirim = foundPengirim->gudang;
                                    // Menampilkan informasi gudang pengirim
                                    cout << endl << "Informasi Gudang pengirim " << pengirim.nama << endl;
                                    cout << "Lokasi                     : " << pengirim.lokasi << endl;
                                    cout << "Kapasitas Gudang           : " << pengirim.kapasitas << endl;
                                    cout << "Jumlah Barang di Gudang    : " << pengirim.barang << endl << endl;

                                    // Menampilkan informasi gudang penerima
                                    Infotype_Gudang penerima = foundPenerima->gudang;
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
                                        break;
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
            case 0:
                cout << "Terima kasih telah menggunakan layanan 'Manajer Gudang'" << endl;
                break;
            default:
                cout << "angka yang dimasukkan tidak valid, silahkan coba lagi!" << endl;
                break;
        }
    }while(choice != 0);
    return 0;
}
