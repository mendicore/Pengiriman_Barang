#include "Truck.h"

int main(int argc, char** argv)
{
    TruckList T;
    Graph G;
    Graph_Pom_Bensin GPB;

    CreateGraph(G);
    CreatePomBensin(GPB);
    CreateTruck(T);
    Infotype_Node gudang1, gudang2, gudang3, gudang4, gudang5, gudang6, gudang7, gudang8, gudang9, gudang10;

    // Gudang 1
    gudang1.nama = "Makmur";
    gudang1.lokasi = "Jakarta";
    gudang1.kapasitas = 5000;
    gudang1.jumlah = 4200;
    Addr_Node newGudang1 = AlokasiNode(gudang1);
    AddNewNode(G, newGudang1);

    // Gudang 2
    gudang2.nama = "Sentosa";
    gudang2.lokasi = "Surabaya";
    gudang2.kapasitas = 7000;
    gudang2.jumlah = 6700;
    Addr_Node newGudang2 = AlokasiNode(gudang2);
    AddNewNode(G, newGudang2);

    // Gudang 3
    gudang3.nama = "Sejahtera";
    gudang3.lokasi = "Bandung";
    gudang3.kapasitas = 6000;
    gudang3.jumlah = 5100;
    Addr_Node newGudang3 = AlokasiNode(gudang3);
    AddNewNode(G, newGudang3);

    // Gudang 4
    gudang4.nama = "Mandiri";
    gudang4.lokasi = "Semarang";
    gudang4.kapasitas = 8000;
    gudang4.jumlah = 6900;
    Addr_Node newGudang4 = AlokasiNode(gudang4);
    AddNewNode(G, newGudang4);

    // Gudang 5
    gudang5.nama = "Surya";
    gudang5.lokasi = "Medan";
    gudang5.kapasitas = 5500;
    gudang5.jumlah = 4800;
    Addr_Node newGudang5 = AlokasiNode(gudang5);
    AddNewNode(G, newGudang5);

    // Gudang 6
    gudang6.nama = "Cemerlang";
    gudang6.lokasi = "Yogyakarta";
    gudang6.kapasitas = 4500;
    gudang6.jumlah = 3900;
    Addr_Node newGudang6 = AlokasiNode(gudang6);
    AddNewNode(G, newGudang6);

    // Gudang 7
    gudang7.nama = "Emas";
    gudang7.lokasi = "Bali";
    gudang7.kapasitas = 6500;
    gudang7.jumlah = 6200;
    Addr_Node newGudang7 = AlokasiNode(gudang7);
    AddNewNode(G, newGudang7);

    // Gudang 8
    gudang8.nama = "Sehat";
    gudang8.lokasi = "Surabaya";
    gudang8.kapasitas = 5500;
    gudang8.jumlah = 4700;
    Addr_Node newGudang8 = AlokasiNode(gudang8);
    AddNewNode(G, newGudang8);

    // Gudang 9
    gudang9.nama = "Otomotif";
    gudang9.lokasi = "Jakarta";
    gudang9.kapasitas = 7000;
    gudang9.jumlah = 6300;
    Addr_Node newGudang9 = AlokasiNode(gudang9);
    AddNewNode(G, newGudang9);

    // Gudang 10
    gudang10.nama = "Bagus";
    gudang10.lokasi = "Bekasi";
    gudang10.kapasitas = 8000;
    gudang10.jumlah = 7200;
    Addr_Node newGudang10 = AlokasiNode(gudang10);
    AddNewNode(G, newGudang10);

    InfoType_Bensin pombensin1;
    InfoType_Bensin pombensin2;
    InfoType_Bensin pombensin3;

    // Pom Bensin 1
    pombensin1.nama = "Pertamina";
    pombensin1.kapasitas = 15000;
    pombensin1.lokasi = "Cibubur";
    Addr_Bensin newPomBensin1 = AlokasiBensin(pombensin1);
    AddNewPomBensin(GPB, newPomBensin1);

    // Pom Bensin 2
    pombensin2.nama = "Shell";
    pombensin2.kapasitas = 12000;
    pombensin2.lokasi = "Bogor";
    Addr_Bensin newPomBensin2 = AlokasiBensin(pombensin2);
    AddNewPomBensin(GPB, newPomBensin2);

    // Pom Bensin 3
    pombensin3.nama = "Total";
    pombensin3.kapasitas = 10000;
    pombensin3.lokasi = "Bandung";
    Addr_Bensin newPomBensin3 = AlokasiBensin(pombensin3);
    AddNewPomBensin(GPB, newPomBensin3);


    infotype_Truck truck1, truck2;

    // Truck 1
    truck1.name = "Vortex";
    truck1.kapasitas = 8000;
    truck1.muatan = 0;
    truck1.bensin = 150;
    adr_Truck newTruck1 = Alokasi(truck1);
    addTruck(T, newTruck1);

    // Truck 2
    truck2.name = "Titan";
    truck2.kapasitas = 10000;
    truck2.muatan = 0;
    truck2.bensin = 120;
    adr_Truck newTruck2 = Alokasi(truck2);
    addTruck(T, newTruck2);


    Connecting(G, "Makmur", "Sejahtera", "Jalan Merpati Raya", 3.5, 20, "tidak");
    Connecting(G, "Sejahtera", "Mandiri", "Jalan Pahlawan", 1.2, 30, "tidak");
    Connecting_Gudang_Bensin(G, "Makmur", "Total", "Jalan Bunga Melati", 4.7, 50, "tidak");
    Connecting_Bensin_Gudang(G, "Total", "Surya", "Jalan Cendrawasih", 2.3, 30, "tidak");
    Connecting(G, "Surya", "Mandiri", "Jalan Mutiara Biru", 5.1, 17, "tidak");
    Connecting(G, "Mandiri", "Emas", "Jalan Damarwulan ", 6, 40, "tidak");
    Connecting(G, "Mandiri", "Cemerlang", "Jalan Seroja ", 2.8, 12, "tidak");
    Connecting_Gudang_Bensin(G, "Cemerlang", "Pertamina", "Jalan Kenanga", 3.9, 27, "ya");
    Connecting_Bensin_Gudang(G, "Pertamina", "Emas", "Jalan Taman Sari ", 1.6, 55, "tidak");
    Connecting_Bensin_Gudang(G, "Pertamina", "Sehat", "Jalan Gunung Bromo ", 7.4, 60, "tidak");
    Connecting(G, "Emas", "Otomotif", "Jalan Surya Kencana", 4.2, 20, "tidak");
    Connecting(G, "Emas", "Bagus", "Jalan Bintang Laut", 3, 15, "ya");
    Connecting(G, "Sehat", "Otomotif", "Jalan Cipta Karya ", 2.5, 56, "tidak");
    Connecting(G, "Bagus", "Otomotif", "Jalan Alam Raya ", 5.6, 25, "tidak");
    Connecting(G, "Bagus", "Sentosa", "Jalan Puspa Indah ", 6.8, 55, "tidak");
    Connecting_Gudang_Bensin(G, "Otomotif", "Shell", "Jalan Pahlawan Tani", 4.3, 15, "tidak");
    Connecting_Bensin_Gudang(G, "Shell", "Sentosa", "Jalan Cempaka Putih  ", 2.9, 22, "tidak");

    int choice;
    string node1, node2, station, namaJalan, macet;
    double distance;
    int waktu;

    do {
        cout << "<<===========================================" << endl;
        cout << "           SISTEM PENGIRIMAN BARANG          " << endl;
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
        cout << "13. Tampilkan semua gudang & jarak" << endl;
        cout << "14. Tampilkan semua pom bensin" << endl;
        cout << "15. Tampilkan semua Truck" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "16. Lakukan pengiriman." << endl;
        cout << "0.  Keluar" << endl;
        cout << "<===========================================>" << endl;
        cout << "Pilih pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Tambah Gudang
                Infotype_Node namaGudang;
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, namaGudang.nama);
                cout << "Masukkan lokasi Gudang: ";
                getline(cin, namaGudang.lokasi);
                cout << "Masukkan kapasitas Gudang: ";
                cin >> namaGudang.kapasitas;
                cout << "Masukkan jumlah Barang di Gudang: ";
                cin >> namaGudang.jumlah;
                if(namaGudang.kapasitas <= namaGudang.jumlah){
                    cout << "Jumlah barang tidak bisa melebihi kapasitas gudang!" << endl;
                }
                Addr_Node newNode = AlokasiNode(namaGudang);
                AddNewNode(G, newNode);
                cout << "---------------------------------------------" << endl;
                cout << "Gudang " << namaGudang.nama << " berhasil ditambahkan!" << endl;
                cout << "---------------------------------------------" << endl << endl;
                break;
            }

            case 2: {
                // Hapus Gudang
                cout << endl << "Masukkan nama Gudang yang ingin dihapus: ";
                cin.ignore();
                getline(cin, node1);
                Addr_Node nodeToDelete = FindNode(G, node1);
                if (nodeToDelete != NULL) {
                    deleteNode(G, nodeToDelete);
                    cout << "Gudang " << node1 << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Gudang dengan nama " << node1 << " tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 3: {
                // Tambah Pom Bensin
                InfoType_Bensin namaPom;
                cout << endl << "Masukkan nama Pom bensin: ";
                cin.ignore();
                getline(cin, namaPom.nama);
                cout << endl << "Masukkan lokasi Pom bensin: ";
                getline(cin, namaPom.lokasi);
                cout << endl << "Masukkan kapasitas tangki bahan bakar: ";
                cin >> namaPom.kapasitas;
                cout << endl << "Masukkan jumlah dispenser bahan bakar Pom bensin: ";
                cin >> namaPom.jumlah;
                Addr_Bensin newBensin = AlokasiBensin(namaPom);
                AddNewPomBensin(GPB, newBensin);
                cout << "Pom bensin " << namaPom.nama << " berhasil ditambahkan!" << endl << endl;
                break;
            }

            case 4: {
                // Hapus Pom Bensin
                cout << endl << "Masukkan nama Pom Bensin yang ingin dihapus: ";
                cin.ignore();
                getline(cin, station);
                Addr_Bensin stationToDelete = FindBensin(GPB, station);
                if (stationToDelete != NULL) {
                    deletePomBensin(GPB, stationToDelete);
                    cout << "Pom Bensin " << station << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Pom Bensin dengan nama " << station << " tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 5: {
                // Tambah Truck
                infotype_Truck truck;
                cout << endl << "Masukkan nama Truck: ";
                cin.ignore();
                getline(cin, truck.name);
                cout << "Masukkan jumlah roda Truck: ";
                cin >> truck.jumlahRoda;
                cout << "Masukkan kapasitas barang: ";
                cin >> truck.kapasitas;
                cout << "Masukkan kapasitas bensin: ";
                cin >> truck.bensin;

                truck.muatan = 0;
                addTruck(T, truck);

                cout << "Truck " << truck.name << " berhasil ditambahkan!" << endl << endl;
                break;
            }

            case 6: {
                // Hapus Truck
            }


            case 7: {
                // Sambungkan Kedua Gudang
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, node1);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, node2);
                cout << "Masukkan nama jalan: ";
                getline(cin, namaJalan);
                cout << "Masukkan jarak antar Gudang: ";
                cin >> distance;
                cout << "Masukkan waktu perjalanan: ";
                cin >> waktu;
                Connecting(G, node1, node2, namaJalan, distance, waktu);
                cout << "Gudang " << node1 << " dan " << node2 << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 8: {
                // Putuskan Kedua Gudang
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, node1);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, node2);

                Addr_Node PNode1 = FindNode(G, node1);
                Addr_Node PNode2 = FindNode(G, node2);

                if (PNode1 != NULL && PNode2 != NULL) {
                    Disconnecting(G, node1, node2);
                    cout << "Rute antara Gudang " << node1 << " dan " << node2 << " berhasil dihapus!" << endl << endl;
                } else {
                    cout << "Salah satu atau kedua Gudang tidak ditemukan!" << endl << endl;
                }
                break;
            }

            case 9: {
                // Sambungkan Gudang dengan Pom Bensin
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, node1);
                cout << "Masukkan nama Pom bensin: ";
                getline(cin, station);
                cout << "Masukkan nama jalan: ";
                getline(cin, namaJalan);
                cout << "Masukkan jarak Gudang dan Pom Bensin: ";
                cin >> distance;
                cout << "Masukkan waktu perjalanan: ";
                cin >> waktu;
                Connecting_Gudang_Bensin(G, node1, station, namaJalan, distance, waktu);
                cout << "Gudang " << node1 << " dan Pom Bensin " << station << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 10: {
                // Sambungkan Pom Bensin dengan Gudang
                cout << endl << "Masukkan nama Pom bensin: ";
                cin.ignore();
                getline(cin, station);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, node2);
                cout << "Masukkan nama jalan: ";
                getline(cin, namaJalan);
                cout << "Masukkan jarak Gudang dan Pom bensin: ";
                cin >> distance;
                cout << "Masukkan waktu perjalanan: ";
                cin >> waktu;
                Connecting_Bensin_Gudang(G, station, node2, namaJalan, distance, waktu);
                cout << "Pom Bensin " << station << " dan Gudang " << node2 << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 11: {
                // Putuskan Gudang dengan Pom Bensin
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, node1);
                cout << "Masukkan nama Pom bensin: ";
                getline(cin, station);

                Addr_Bensin PBensin = FindBensin(GPB, station);
                if(PBensin != Null)
                {
                    Addr_Node PNode1 = FindNode(G, node1);
                    Addr_Node PNode2 = FindNode(G, station);

                    if (PNode1 != NULL && PNode2 != NULL) {
                        Disconnecting(G, node1, station);
                        cout << "Rute antara Gudang " << node1 << " dan Pom bensin " << station << " berhasil dihapus!" << endl << endl;
                    } else {
                        cout << "Salah satu atau kedua bangunan tersebut tidak ditemukan!" << endl << endl;
                    }
                }
                else
                {
                    cout << "Pom bensin tidak ditemukan, tidak ada penghapusan!" << endl << endl;
                }
                break;
            }

            case 12: {
                // Putuskan Pom Bensin dengan Gudang
                cout << endl << "Masukkan nama Pom bensin: ";
                cin.ignore();
                getline(cin, station);
                cout << "Masukkan nama Gudang: ";
                getline(cin, node2);

                Addr_Bensin PBensin = FindBensin(GPB, station);
                if(PBensin != Null)
                {
                    Addr_Node PNode1 = FindNode(G, station);
                    Addr_Node PNode2 = FindNode(G, node2);

                    if (PNode1 != NULL && PNode2 != NULL) {
                        Disconnecting(G, station, node2);
                        cout << "Rute antara Pom Bensin " << station << " dan Gudang " << node2 << " berhasil dihapus!" << endl << endl;
                    } else {
                        cout << "Salah satu atau kedua bangunan tersebut tidak ditemukan!" << endl << endl;
                    }
                }
                else
                {
                    cout << "Pom bensin tidak ditemukan, tidak ada penghapusan!" << endl << endl;
                }
                break;
            }


            case 13: {
                // Menampilkan semua Gudang dan Jarak (nanti gabung gudang jalur, dan pom bensin menjadi 1 method Peta)
                cout << endl << "Menampilkan Gudang dan Jarak:" << endl;
                ShowAllGudangJalur(G);
                break;
            }

            case 14: {
                cout << endl << "Semua Pom Bensin: " << endl;
                ShowAllPomBensin(GPB);
                break;
                /* Cari Rute Tercepat
                TempList T;
                Infotype_Node gudang1, gudang2;
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, gudang1.nama);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, gudang2.nama);
                AlJikstra(G, gudang1, gudang2, T);
                break;*/
            }

            case 15:{
                // Menampilkan semua Pom Bensin
                cout << endl << "Daftar Truck: " << endl;
                showTrucks(T);
                break;
            }

            case 16: {
                // Lakukan pengiriman dan catat jalu
                infotype_Truck truck;
                Infotype_Node GudangA, GudangB;
                Infotype_Edge jalur;
                double bensin, barang, jarak, biayaPerMuatan;

                cout << "Masukkan nama truk yang akan digunakan: ";
                cin.ignore();
                getline(cin, truck.name);

                adr_Truck foundTruck = findTruck(T, truck); // Mencari truk berdasarkan nama
                if (foundTruck != NULL) {
                    cout << "Truk " << foundTruck->info.name << " ditemukan." << endl << endl;

                    // Memilih gudang pengirim
                    cout << "Masukkan nama gudang pengirim: ";
                    getline(cin, GudangA.nama);
                    Addr_Node foundNode1 = FindNode(G, GudangA.nama); // Mencari node gudang pengirim
                    if (foundNode1 != NULL) {
                        // Memilih gudang penerima
                        cout << "Masukkan nama gudang penerima: ";
                        getline(cin, GudangB.nama);
                        Addr_Node foundNode2 = FindNode(G, GudangB.nama); // Mencari node gudang penerima
                        if (foundNode2 != NULL) {
                            // Menampilkan informasi gudang pengirim
                            Infotype_Node pengirim = foundNode1->info;
                            cout << endl << "Informasi Gudang pengirim " << pengirim.nama << endl;
                            cout << "Lokasi                     : " << pengirim.lokasi << endl;
                            cout << "Kapasitas Gudang           : " << pengirim.kapasitas << endl;
                            cout << "Jumlah Barang di Gudang    : " << pengirim.jumlah << endl << endl;

                            // Menampilkan informasi gudang penerima
                            Infotype_Node penerima = foundNode2->info;
                            cout << endl << "Informasi Gudang penerima " << penerima.nama << endl;
                            cout << "Lokasi                     : " << penerima.lokasi << endl;
                            cout << "Kapasitas Gudang           : " << penerima.kapasitas << endl;
                            cout << "Jumlah Barang di Gudang    : " << penerima.jumlah << endl << endl;

                            // Meminta jumlah barang yang akan diantar
                            cout << "Masukkan jumlah barang yang ingin diantar: ";
                            cin >> barang;

                            // Mengecek apakah kapasitas truk cukup
                            if (foundTruck->info.kapasitas < barang) {
                                cout << "Jumlah barang melebihi kapasitas truk!" << endl;
                            }

                            foundTruck->info.kapasitas -= barang;
                            cout << "Barang berhasil diangkut. Kapasitas truk: " << foundTruck->info.kapasitas << endl;
                            cout << "Memulai pengiriman.....";

                            cout << "Masukkan jumlah bensin: ";
                            cin >> bensin;
                            cout << "Masukkan jarak 2 gudang: ";
                            cin >> jarak;

                            Pengiriman(T, G, pengirim, penerima, jalur, truck, bensin, barang, jarak);

                            foundTruck->info.kapasitas -= barang;
                            cout << "Barang berhasil diantar. Sisa kapasitas truk: " << foundTruck->info.kapasitas << endl;

                            cout << "Masukkan biaya yang diperlukan untuk sebuah perjalanan: ";
                            cin >> biayaPerMuatan;

                            double biayaPerKM = barang * jarak;
                            cout << "Total biaya: " << biayaPengiriman(T, truck.name, biayaPerMuatan, biayaPerKM, jarak) << endl;
                        } else {
                            cout << "Gudang penerima tidak ditemukan!" << endl;
                        }
                    } else {
                        cout << "Gudang pengirim tidak ditemukan!" << endl;
                    }
                } else {
                    cout << "Truk tidak ditemukan!" << endl;
                }
                break;
            }


            case 0: {
                // Keluar Program
                cout << endl << "Keluar dari program" << endl;
                break;
            }

            default: {
                cout << endl << "Pilihan tidak valid, coba lagi" << endl;
            }
        }
    } while (choice != 0);
    return 0;
}