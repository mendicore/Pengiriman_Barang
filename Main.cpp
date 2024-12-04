#include <iostream>
#include "Rute.h"

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);
    int choice;
    string node1, node2;
    int distance;

    do {
        cout << "Menu Pilihan:" << endl;
        cout << "1. Tambah Gudang" << endl;
        cout << "2. Hapus Gudang" << endl;
        cout << "3. Hubungkan Gudang" << endl;
        cout << "4. Putuskan Gudang" << endl;
        cout << "5. Tampilkan semua gudang & jarak" << endl;
        cout << "6. Cari rute tercepat" << endl; //blm diimplementasi
        cout << "0. Keluar" << endl;
        cout << "Pilih pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string namaGudang;
                cout << endl << "Masukkan nama Gudang: ";
                cin.ignore();
                getline(cin, namaGudang);
                Addr_Node newNode = AlokasiNode(namaGudang);
                AddNewNode(G, newNode);
                cout << "Gudang " << namaGudang << " berhasil ditambahkan!" << endl << endl;
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
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, node1);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, node2);
                cout << "Masukkan jarak antar Gudang: ";
                cin >> distance;
                Connecting(G, node1, node2, distance);
                cout << "Gudang " << node1 << " dan " << node2 << " berhasil dihubungkan!" << endl << endl;
                break;
            }

            case 4: {
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

            case 5: {
                cout << endl << "Menampilkan Gudang dan Jarak:" << endl;;
                ShowAll(G);
                break;
            }

            case 6: {
                cout << endl << "Masukkan nama Gudang pertama: ";
                cin.ignore();
                getline(cin, node1);
                cout << "Masukkan nama Gudang kedua: ";
                getline(cin, node2);
                //FindShortestRoute(G, node1, node2);
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
