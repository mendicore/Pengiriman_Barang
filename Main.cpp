#include "Rute.h"

int main(int argc, char** argv) {
    Graph G;
    Graph_Pom_Bensin GPB;
    CreateGraph(G);
    CreatePomBensin(GPB);
    int choice;
    string node1, node2, station, namaJalan;
    double distance;
    int waktu;

    do {
        cout << "Menu Pilihan:" << endl;
        cout << "1. Tambah Gudang" << endl;
        cout << "2. Hapus Gudang" << endl;
        cout << "3. Tambah Pom bensin" << endl;
        cout << "4. Hapus Pom bensin" << endl;
        cout << "5. Hubungkan Gudang" << endl;
        cout << "6. Putuskan Gudang" << endl;
        cout << "7. Hubungkan Gudang dengan Pom bensin" << endl;
        cout << "8. Hubungkan Pom bensin dengan Gudang" << endl;
        cout << "9. Putuskan Gudang dengan Pom bensin" << endl;
        cout << "10. Putuskan Pom Bensin dengan Gudang" << endl;
        cout << "11. Tampilkan semua gudang & jarak" << endl;
        cout << "12. Cari rute tercepat" << endl;
        cout << "13. Tampilkan pom bensin" << endl;
        cout << "14. Mencari jalur alternatif " << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Infotype_Node namaGudang;
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, namaGudang.nama);
                cout << endl << "Masukkan lokasi Gudang: ";
                getline(cin, namaGudang.lokasi);
                cout << endl << "Masukkan kapasitas Gudang: ";
                cin >> namaGudang.kapasitas;
                cout << endl << "Masukkan jumlah Gudang: ";
                cin >> namaGudang.jumlah;
                Addr_Node newNode = AlokasiNode(namaGudang);
                AddNewNode(G, newNode);
                cout << "Gudang " << namaGudang.nama << " berhasil ditambahkan!" << endl << endl;
                break;
            }

            case 2: {
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
                cout << endl << "Masukkan nama Gudang yang ingin dihapus: ";
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

            case 6: {
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

            case 7: {
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

            case 8: {
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

            case 9: {
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

            case 10: {
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


            case 11: {
                cout << endl << "Menampilkan Gudang dan Jarak:" << endl;
                ShowAllGudangJalur(G);
                break;
            }

            case 12: {
                TempList T;
                Infotype_Node gudang1, gudang2;
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, gudang1.nama);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, gudang2.nama);
                AlJikstra(G, gudang1, gudang2, T);
                break;
            }

            case 13:
            {
                cout << endl << "Semua Pom Bensin: " << endl;
                ShowAllPomBensin(GPB);
                break;
            }

            case 14:
                {
                    Infotype_Node gudang1, gudang2;
                    Infotype_Edge jalan;
                    cout << endl << "Masukkan nama Gudang pertama: ";
                    cin.ignore();
                    getline(cin, gudang1.nama);
                    cout << endl << "Masukkan nama Gudang kedua: ";
                    getline(cin, gudang2.nama);
                    cout << endl << "Masukkan nama jalan: ";
                    getline(cin, jalan.namaJalan);
                    jalurAlternatifDFS(G, gudang1, gudang2, jalan);
                    break;
                }

            case 0: {
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
