#include "Pengiriman.h"

// create
void Create_Graph(Graph &G) {
    StartGudang(G) = NULL;
    StartPomBensin(G) = NULL;
}

void Create_Truck(TruckList &T){
    FirstTruck(T) = NULL;
}

// alokasi
Addr_Vertex_Gudang Alokasi_Gudang(Infotype_Gudang infogudang) {
    Addr_Vertex_Gudang P = new Vertex_Gudang_Elmt;
    if (P != NULL) {
        Info(P) = infogudang;
        NextVertex(P) = NULL;
        FirstEdge(P) = NULL;
    }
    return P;
}

Addr_Edge Alokasi_Edge(Infotype_Edge infoEdge) {
    Addr_Edge P = new Edge_Elmt;
    if (P != NULL) {
        Info(P) = infoEdge;
        NextEdge(P) = NULL;
    }
    return P;
}

Addr_Vertex_PomBensin Alokasi_PomBensin(Infotype_PomBensin infoPomBensin) {
    Addr_Vertex_PomBensin P = new Vertex_PomBensin_Elmt;
    if (P != NULL){
        Info(P) = infoPomBensin;
        NextVertex(P) = NULL;
        FirstEdge(P) = NULL;
    }
    return P;
}

Addr_Truck Alokasi_Truck(Infotype_Truck infoTruck) {
    Addr_Truck P = new Truck_Elmt;
    if (P != NULL) {
        Info(P) = infoTruck;
        NextTruck(P) = NULL;
    }
    return P;
}

// find
Addr_Vertex_Gudang Find_Vertex_Gudang(Graph &G, string nama) {
    Addr_Vertex_Gudang P = StartGudang(G);
    while (P != NULL) {
        if (Info(P).nama == nama) {
            return P;
        }
        P = NextVertex(P);
    }
    return NULL;
}

Addr_Edge Find_Edge(Graph &G, string nama) {
    Addr_Vertex_Gudang P = G.StartGudang;

    while (P != NULL) {
        Addr_Edge E = FirstEdge(P);
        while (E != NULL) {
            if (Info(E).nama == nama) {
                return E;  //
            }
            E = NextEdge(E);
        }
        P = NextVertex(P);
    }

    return NULL;
}

Addr_Vertex_PomBensin Find_Vertex_PomBensin(Graph &G, string nama) {
    Addr_Vertex_PomBensin P = StartPomBensin(G);
    while (P != NULL) {
        if (Info(P).nama == nama) {
            return P;
        }
        P = NextVertex(P);
    }
    return NULL;
}

Addr_Truck Find_Truck(TruckList &T, string nama) {
    Addr_Truck P = FirstTruck(T);
    while (P != NULL) {
        if (Info(P).nama == nama) {
            return P;
        }
        P = NextTruck(P);
    }
    return NULL;
}

// add
void Add_Vertex_Gudang(Graph &G, Addr_Vertex_Gudang P) {
    if (StartGudang(G) == NULL) {
        StartGudang(G) = P;
    } else {
        Addr_Vertex_Gudang Q = StartGudang(G);
        while (NextVertex(Q) != NULL) {
            Q = NextVertex(Q);
        }
        NextVertex(Q) = P;
    }
}

void Add_Vertex_PomBensin(Graph &G, Addr_Vertex_PomBensin P) {
    if (StartPomBensin(G) == NULL) {
        StartPomBensin(G) = P;
    } else {
        Addr_Vertex_PomBensin Q = StartPomBensin(G);
        while (NextVertex(Q) != NULL) {
            Q = NextVertex(Q);
        }
        NextVertex(Q) = P;
    }
}


void Add_Truck(TruckList &T, Addr_Truck P) {
    if (FirstTruck(T) == NULL) {
        FirstTruck(T) = P;
    } else {
        Addr_Truck Q = FirstTruck(T);
        while (NextTruck(Q) != NULL) {
            Q = NextTruck(Q);
        }
        NextTruck(Q) = P;
    }
}

// delete
void Delete_Vertex_Gudang(Graph &G, Addr_Vertex_Gudang P) {
   if (StartGudang(G) == NULL) {
        cout << "Tidak ada gudang yang tersedia!" << endl;
        return;
    }

    if (StartGudang(G) == P) {
        StartGudang(G) = NextVertex(P);
    } else {
        Addr_Vertex_Gudang Q = StartGudang(G);
        while (Q != NULL && NextVertex(Q) != P) {
            Q = NextVertex(Q);
        }

        if (Q != NULL) {
            NextVertex(Q) = NextVertex(P);
        }
    }
    delete P;
}

void Delete_Vertex_PomBensin(Graph &G, Addr_Vertex_PomBensin P) {
    if (StartPomBensin(G) == NULL) {
        cout << "Tidak ada pom Bensin yang tersedia!" << endl;
        return;
    }

    if (StartPomBensin(G) == P) {
        StartPomBensin(G) = NextVertex(P);
    } else {
        Addr_Vertex_PomBensin Q = StartPomBensin(G);
        while (Q != NULL && NextVertex(Q) != P) {
            Q = NextVertex(Q);
        }
        if (Q != NULL) {
            NextVertex(Q) = NextVertex(P);
        }
    }
    delete P;
}

void Delete_Truck(TruckList &T, Addr_Truck P) {
     if (FirstTruck(T) == NULL) {
        cout << "List Truck kosong!" << endl;
        return;
    }

    if (FirstTruck(T) == P) {
        FirstTruck(T) = NextTruck(P);
    } else {
        Addr_Truck Q = FirstTruck(T);
        while (Q != NULL && NextTruck(Q) != P) {
            Q = NextTruck(Q);
        }

        if (Q != NULL) {
            NextTruck(Q) = NextTruck(P);
        }
    }
    delete P;
}

// connecting  & disconnecting gudang
void Connecting_Gudang(Graph &G, string gudang1, string gudang2, string jalan, double jarak, string macet) {
    Addr_Vertex_Gudang vertexGudang1 = Find_Vertex_Gudang(G, gudang1);
    Addr_Vertex_Gudang vertexGudang2 = Find_Vertex_Gudang(G, gudang2);

    if (vertexGudang1 == NULL) {
        cout << "Gudang " << gudang1 << " tidak ditemukan!" << endl;
        return;
    }
    if (vertexGudang2 == NULL) {
        cout << "Gudang " << gudang2 << " tidak ditemukan!" << endl;
        return;
    }

    Infotype_Edge edge;
    edge.gudang = Info(vertexGudang2);
    edge.nama = jalan;
    edge.jarak = jarak;

    if (macet == "ya" || macet == "Ya") {
        edge.macet = true;
    } else if (macet == "tidak" || macet == "Tidak") {
        edge.macet = false;
    } else {
        cout << "Input untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
        return;
    }

    Addr_Edge newEdge = Alokasi_Edge(edge);
    NextEdge(newEdge) = FirstEdge(vertexGudang1);
    FirstEdge(vertexGudang1) = newEdge;

    Addr_Edge reverseEdge = Alokasi_Edge(edge);
    Info(reverseEdge).gudang = Info(vertexGudang1);
    NextEdge(reverseEdge) = FirstEdge(vertexGudang2);
    FirstEdge(vertexGudang2) = reverseEdge;

    cout << "Jalan antara " << gudang1 << " dan " << gudang2 << " telah berhasil dihubungkan!" << endl;
}



void Disconnecting_Gudang(Graph &G, string gudang1, string gudang2) {
    Addr_Vertex_Gudang vertexGudang1 = Find_Vertex_Gudang(G, gudang1);
    Addr_Vertex_Gudang vertexGudang2 = Find_Vertex_Gudang(G, gudang2);

    if (vertexGudang1 == NULL) {
        cout << "Gudang " << gudang1 << " tidak ditemukan!" << endl;
        return;
    }
    if (vertexGudang2 == NULL) {
        cout << "Gudang " << gudang2 << " tidak ditemukan!" << endl;
        return;
    }

    Addr_Edge prevEdge1 = NULL;
    Addr_Edge currEdge1 = FirstEdge(vertexGudang1);

    while (currEdge1 != NULL && Info(currEdge1).gudang.nama != gudang2) {
        prevEdge1 = currEdge1;
        currEdge1 = NextEdge(currEdge1);
    }

    if (currEdge1 != NULL) {
        if (prevEdge1 == NULL) {
            FirstEdge(vertexGudang1) = NextEdge(currEdge1);
        } else {
            NextEdge(prevEdge1) = NextEdge(currEdge1);
        }
        delete currEdge1;
        cout << "Jalan antara " << gudang1 << " dan " << gudang2 << " telah diputus!" << endl;
    } else {
        cout << "Jalan antara " << gudang1 << " dan " << gudang2 << " tidak ditemukan!" << endl;
    }

    Addr_Edge prevEdge2 = NULL;
    Addr_Edge currEdge2 = FirstEdge(vertexGudang2);

    while (currEdge2 != NULL && Info(currEdge2).gudang.nama != gudang1) {
        prevEdge2 = currEdge2;
        currEdge2 = NextEdge(currEdge2);
    }

    if (currEdge2 != NULL) {
        if (prevEdge2 == NULL) {
            FirstEdge(vertexGudang2) = NextEdge(currEdge2);
        } else {
            NextEdge(prevEdge2) = NextEdge(currEdge2);
        }
        delete currEdge2;
        cout << "Jalan antara " << gudang2 << " dan " << gudang1 << " telah diputus!" << endl;
    } else {
        cout << "Jalan antara " << gudang2 << " dan " << gudang1 << " tidak ditemukan!" << endl;
    }
}


// connecting & disconnecting pom bensin dengan gudang atau sebaliknya
void Connecting_PomBensin_To_Gudang(Graph &G, string gudang, string pomBensin, string jalan, double jarak, string macet) {
    Addr_Vertex_PomBensin vertexPomBensin = Find_Vertex_PomBensin(G, pomBensin);
    Addr_Vertex_Gudang vertexGudang = Find_Vertex_Gudang(G, gudang);

    if (vertexPomBensin != NULL && vertexGudang != NULL) {
        Infotype_Edge edge;
        edge.gudang = Info(vertexGudang);
        edge.nama = jalan;
        edge.jarak = jarak;

        if (macet == "ya" || macet == "Ya") {
            edge.macet = true;
        } else if (macet == "tidak" || macet == "Tidak") {
            edge.macet = false;
        } else {
            cout << "Input untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
            return;
        }

        Addr_Edge newEdge = Alokasi_Edge(edge);
        if (newEdge == NULL) {
            cout << "Gagal mengalokasikan edge baru." << endl;
            return;
        }

        NextEdge(newEdge) = FirstEdge(vertexPomBensin);
        FirstEdge(vertexPomBensin) = newEdge;

        Infotype_Edge reverseEdgeInfo;
        reverseEdgeInfo.gudang = Info(vertexGudang);  // Isi dengan info gudang
        reverseEdgeInfo.pomBensin = Info(vertexPomBensin);
        reverseEdgeInfo.nama = jalan;
        reverseEdgeInfo.jarak = jarak;
        reverseEdgeInfo.macet = edge.macet;

        Addr_Edge reverseEdge = Alokasi_Edge(reverseEdgeInfo);
        if (reverseEdge == NULL) {
            cout << "Gagal mengalokasikan reverse edge." << endl;
            return;
        }

        NextEdge(reverseEdge) = FirstEdge(vertexGudang);
        FirstEdge(vertexGudang) = reverseEdge;

        cout << "Jalan antara Pom Bensin " << pomBensin << " dan Gudang " << gudang << " telah berhasil dihubungkan!" << endl;
    } else {
        cout << "Pom Bensin atau Gudang tidak ditemukan!" << endl;
    }
}




void Connecting_Gudang_To_PomBensin(Graph &G, string pomBensin, string gudang, string jalan, double jarak, string macet) {
    Addr_Vertex_Gudang vertexGudang = Find_Vertex_Gudang(G, gudang);
    Addr_Vertex_PomBensin vertexPomBensin = Find_Vertex_PomBensin(G, pomBensin);

    if (vertexGudang != NULL && vertexPomBensin != NULL) {
        Infotype_Edge edge;
        edge.pomBensin = Info(vertexPomBensin);
        edge.nama = jalan;
        edge.jarak = jarak;

        if (macet == "ya" || macet == "Ya") {
            edge.macet = true;
        } else if (macet == "tidak" || macet == "Tidak") {
            edge.macet = false;
        } else {
            cout << "Input untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
            return;
        }

        Addr_Edge newEdge = Alokasi_Edge(edge);
        if (newEdge == NULL) {
            cout << "Gagal mengalokasikan edge baru." << endl;
            return;
        }

        NextEdge(newEdge) = FirstEdge(vertexGudang);
        FirstEdge(vertexGudang) = newEdge;

        Infotype_Edge reverseEdgeInfo;
        reverseEdgeInfo.gudang = Info(vertexGudang);
        reverseEdgeInfo.pomBensin = Info(vertexPomBensin);
        reverseEdgeInfo.nama = jalan;
        reverseEdgeInfo.jarak = jarak;
        reverseEdgeInfo.macet = edge.macet;

        Addr_Edge reverseEdge = Alokasi_Edge(reverseEdgeInfo);
        if (reverseEdge == NULL) {
            cout << "Gagal mengalokasikan reverse edge." << endl;
            return;
        }

        NextEdge(reverseEdge) = FirstEdge(vertexPomBensin);
        FirstEdge(vertexPomBensin) = reverseEdge;

        cout << "Jalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " telah berhasil dihubungkan!" << endl;
    } else {
        cout << "Gudang atau Pom Bensin tidak ditemukan!" << endl;
    }
}


void Disconnecting_PomBensin_Gudang(Graph &G, string gudang, string pomBensin) {
    Addr_Vertex_PomBensin vertexPomBensin = Find_Vertex_PomBensin(G, pomBensin);
    Addr_Vertex_Gudang vertexGudang = Find_Vertex_Gudang(G, gudang);

    if (vertexPomBensin == NULL || vertexGudang == NULL) {
        cout << "Gudang atau Pom Bensin tidak ditemukan!" << endl;
        return;
    }

    Addr_Edge edge = FirstEdge(vertexPomBensin);
    Addr_Edge prevEdge = NULL;

    while (edge != NULL) {
        if (Info(edge).gudang.nama == gudang) {
            if (prevEdge == NULL) {
                FirstEdge(vertexPomBensin) = NextEdge(edge);
            } else {
                NextEdge(prevEdge) = NextEdge(edge);
            }
            delete edge;  // Mengganti free() dengan delete
            cout << "Jalan antara Pom Bensin " << pomBensin << " dan Gudang " << gudang << " telah diputus." << endl;
            return;
        }
        prevEdge = edge;
        edge = NextEdge(edge);
    }
    cout << "Jalan antara Pom Bensin " << pomBensin << " dan Gudang " << gudang << " tidak ditemukan!" << endl;
}

void Disconnecting_Gudang_PomBensin(Graph &G, string pomBensin, string gudang) {
    Addr_Vertex_Gudang vertexGudang = Find_Vertex_Gudang(G, gudang);
    Addr_Vertex_PomBensin vertexPomBensin = Find_Vertex_PomBensin(G, pomBensin);

    if (vertexPomBensin == NULL || vertexGudang == NULL) {
        cout << "Gudang atau Pom Bensin tidak ditemukan!" << endl;
        return;
    }

    Addr_Edge edge = FirstEdge(vertexGudang);
    Addr_Edge prevEdge = NULL;

    while (edge != NULL) {
        if (Info(edge).gudang.nama == pomBensin) {
            if (prevEdge == NULL) {
                FirstEdge(vertexGudang) = NextEdge(edge);
            } else {
                NextEdge(prevEdge) = NextEdge(edge);
            }
            delete edge;
            cout << "Jalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " telah diputus." << endl;
            return;
        }
        prevEdge = edge;
        edge = NextEdge(edge);
    }
    cout << "Jalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " tidak ditemukan!" << endl;
}


// main fitur
Addr_Vertex_PomBensin Cari_PomBensin_Terdekat(Graph &G, Addr_Vertex_Gudang gudang) {
    Addr_Vertex_PomBensin pomBensin = StartPomBensin(G);
    Addr_Vertex_PomBensin nearestPom = NULL;
    int minDistance = INT_MAX;

    while (pomBensin != NULL) {
        int distance = abs(gudang->Info.lokasi[0] - pomBensin->Info.lokasi[0]);
        if (distance < minDistance) {
            minDistance = distance;
            nearestPom = pomBensin;
        }
        pomBensin = pomBensin->NextVertex;
    }

    return nearestPom;
}

Addr_Edge Rute_Alternatif(Graph &G, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima){
     Addr_Edge edge = FirstEdge(pengirim);

    while (edge != NULL) {
        if (edge->Info.gudang.nama != penerima->Info.nama && !edge->Info.macet) {
            return edge;
        }
        edge = edge->NextEdge;
    }
    return NULL;
}

void Catat_Jalan(Graph &G);

void Rute_Tercepat(Graph &G, Addr_Truck truk, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima, int jumBarang) {
    double biayaPerjalanan = 0;
    Addr_Edge edge = FirstEdge(pengirim);
    bool ditemukan = false;

    // Pencarian rute pertama
    while (edge != NULL) {
        if (edge->Info.gudang.nama == penerima->Info.nama) {
            cout << "Mengambil jalan: " << edge->Info.nama << " dengan jarak: " << edge->Info.jarak << endl;

            if (edge->Info.macet) {
                cout << "Jalan ini macet, menghindari!" << endl;
                edge = edge->NextEdge;
                continue;
            }

            truk->Info.bensin -= edge->Info.jarak * 0.1;
            biayaPerjalanan += edge->Info.jarak * 100;

            cout << "Sisa bensin truk: " << truk->Info.bensin << endl;

            if (truk->Info.bensin <= 0) {
                Addr_Vertex_PomBensin pomBensinTerdekat = Cari_PomBensin_Terdekat(G, pengirim);

                if (pomBensinTerdekat != NULL) {
                    double bensinDiPom = pomBensinTerdekat->Info.stokBensin;
                    double bensinYangDiperlukan = abs(truk->Info.bensin);

                    if (bensinDiPom >= bensinYangDiperlukan) {
                        truk->Info.bensin += bensinYangDiperlukan;
                        pomBensinTerdekat->Info.stokBensin -= bensinYangDiperlukan;
                        cout << "Bensin truk diisi ulang di pom bensin terdekat!" << endl;
                        cout << "Sisa bensin pom bensin: " << pomBensinTerdekat->Info.stokBensin << endl;
                    } else {
                        cout << "Stok bensin di pom bensin terdekat tidak cukup!" << endl;
                    }
                } else {
                    cout << "Tidak ada pom bensin terdekat!" << endl;
                    return; // Keluar dari fungsi jika tidak ada pom bensin
                }
            }

            cout << "Pengiriman berhasil!" << endl;
            cout << "Sisa bensin truk: " << truk->Info.bensin << endl;
            break;
        }
        edge = edge->NextEdge;
    }

    // Jika rute tidak ditemukan, tawarkan untuk mencari rute alternatif
    if (edge == NULL) {
        cout << "Rute ke gudang penerima tidak ditemukan!" << endl;

        string pilihan;
        cout << "Apakah Anda ingin mencari rute alternatif? (ya/tidak): ";
        cin >> pilihan;

        if (pilihan == "ya" || pilihan == "Ya") {
            // Pencarian rute alternatif (memanggil fungsi untuk mencari rute alternatif)
            edge = Rute_Alternatif(G, pengirim, penerima);
            if (edge != NULL) {
                cout << "Rute alternatif ditemukan: " << edge->Info.nama << " dengan jarak: " << edge->Info.jarak << endl;

                truk->Info.bensin -= edge->Info.jarak * 0.1;
                biayaPerjalanan += edge->Info.jarak * 100;

                cout << "Sisa bensin truk: " << truk->Info.bensin << endl;
                cout << "Total biaya perjalanan: " << biayaPerjalanan << endl;
            } else {
                cout << "Tidak ada rute alternatif yang ditemukan!" << endl;
            }
        } else {
            cout << "Pengiriman dibatalkan. Tidak ada rute yang ditemukan." << endl;
        }
    } else {
        // Jika rute ditemukan, transfer barang
        pengirim->Info.barang -= jumBarang;
        penerima->Info.barang += jumBarang;
        cout << "Total biaya perjalanan: " << biayaPerjalanan << endl;
    }
}



// menampilkan graph dan list

void Show_Graph(Graph &G) {
    cout << "<<===================================================================================>>" << endl;
    cout << "                                       GRAPH                                           " << endl;
    cout << "<<----------------------------------------------------------------------------------->>" << endl;

    if (StartGudang(G) != NULL) {
        for (Addr_Vertex_Gudang N = StartGudang(G); N != NULL; N = NextVertex(N)) {
            cout << "\tGudang: " << left << setw(25) << Info(N).nama
                 << ", berlokasi di " << Info(N).lokasi << endl
                 << "\t\tKapastitas: " << left << setw(10) << Info(N).kapasitas
                 << " | Jumlah barang: " << Info(N).barang << endl;

            cout << "<<===================================================================================>>" << endl;
            cout << left << setw(15) << "[Nama Gudang]"
                 << setw(20) << "[Nama Jalan]"
                 << setw(15) << "[Lokasi]"
                 << setw(10) << "[Jarak]"
                 << setw(15) << "[Status Macet]" << endl;
            cout << "<<----------------------------------------------------------------------------------->>" << endl;

            // Tampilkan tetangga (edge) yang menghubungkan Gudang ke Pom Bensin
            for (Addr_Edge E = FirstEdge(N); E != NULL; E = NextEdge(E)) {
                    cout << left
                         << setw(15) << E->Info.gudang.nama
                         << setw(20) << E->Info.nama
                         << setw(15) << E->Info.gudang.lokasi
                         << setw(10) << E->Info.jarak
                         << setw(15) << (E->Info.macet ? "Ya" : "Tidak")
                         << endl;
                // Menampilkan Pom Bensin sebagai tetangga jika ada
                if (E->Info.pomBensin.nama != "") {
                    cout << "\tTetangga: Pom Bensin " << E->Info.pomBensin.nama << endl;
                }
            }
            cout << "<<----------------------------------------------------------------------------------->>" << endl << endl;
        }
    } else {
        cout << "Graf Kosong (Gudang)" << endl;
    }


    if (StartPomBensin(G) != NULL) {
        for (Addr_Vertex_PomBensin P = StartPomBensin(G); P != NULL; P = NextVertex(P)) {
            cout << "\tPom Bensin: " << left << setw(25) << Info(P).nama
                 << " berlokasi di " << Info(P).lokasi << endl
                 << "\t\tStok bensin      : " << left << setw(10) << Info(P).stokBensin << endl
                 << "\t\tTetangga         : " << endl;

            cout << "<<===================================================================================>>" << endl;
            cout << left << setw(15) << "[Nama Pom Bensin]"
                 << setw(20) << "[Nama Jalan]"
                 << setw(15) << "[Lokasi]"
                 << setw(10) << "[Jarak]"
                 << setw(15) << "[Status Macet]" << endl;
            cout << "<<----------------------------------------------------------------------------------->>" << endl;

            // Tampilkan tetangga (edge) yang menghubungkan Pom Bensin ke Gudang
            for (Addr_Edge E = FirstEdge(P); E != NULL; E = NextEdge(E)) {
                cout << left << setw(15) << E->Info.pomBensin.nama
                     << setw(20) << E->Info.nama
                     << setw(15) << E->Info.pomBensin.lokasi
                     << setw(10) << E->Info.jarak
                     << setw(15) << (E->Info.macet ? "Ya" : "Tidak")
                     << endl;

                // Menampilkan Gudang sebagai tetangga jika ada
                if (E->Info.gudang.nama != "") {
                    cout << "\tTetangga: Gudang " << E->Info.gudang.nama << endl;
                }
            }
            cout << "<<----------------------------------------------------------------------------------->>" << endl << endl;
        }
    } else {
        cout << "Graf Kosong (Pom Bensin)" << endl;
    }
}



void Show_Trucks(TruckList &T) {
    Addr_Truck P = FirstTruck(T);

    if (P == NULL) {
        cout << "Tidak ada truck dalam daftar." << endl;
        return;
    }

    cout << "======================= DAFTAR TRUCK =======================\n";
    cout << left << setw(20) << "[Nama Truck]"
         << setw(15) << "[Kapasitas]"
         << setw(15) << "[Muatan]"
         << "[Bensin]" << endl;
    cout << "-------------------------------------------------------------\n";

    while (P != NULL) {
        cout << left << setw(20) << Info(P).nama
             << setw(15) << Info(P).kapasitas
             << setw(15) << Info(P).muatan
             << Info(P).bensin << "L" << endl;

        P = NextTruck(P);
    }
    cout << "=============================================================\n";
}

