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

void InsertLast_Edge(Graph &G, Addr_Vertex_Gudang nodeGudang, Addr_Vertex_PomBensin nodePomBensin, Addr_Edge newEdge) {
    if (nodeGudang != NULL) {
        if (nodeGudang->FirstEdge == NULL) {
            nodeGudang->FirstEdge = newEdge;
        } else {
            Addr_Edge temp = nodeGudang->FirstEdge;
            while (temp->NextEdge != NULL) {
                temp = temp->NextEdge;
            }
            temp->NextEdge = newEdge;
        }
    } else if (nodePomBensin != NULL) {
        if (nodePomBensin->FirstEdge == NULL) {
            nodePomBensin->FirstEdge = newEdge;
        } else {
            Addr_Edge temp = nodePomBensin->FirstEdge;
            while (temp->NextEdge != NULL) {
                temp = temp->NextEdge;
            }
            temp->NextEdge = newEdge;
        }
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

    Jalan jalanBaru1;
    jalanBaru1.gudang = Info(vertexGudang2);
    jalanBaru1.nama = jalan;
    jalanBaru1.jarak = jarak;

    if (macet == "ya" || macet == "Ya") {
        jalanBaru1.macet = true;
    } else if (macet == "tidak" || macet == "Tidak") {
        jalanBaru1.macet = false;
    } else {
        cout << "Input untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
        return;
    }
    Addr_Edge edge1 = Alokasi_Edge(jalanBaru1);
    InsertLast_Edge(G, vertexGudang1, NULL, edge1);

    Jalan jalanBaru2;
    jalanBaru2.gudang = Info(vertexGudang1);
    jalanBaru2.nama = jalan;
    jalanBaru2.jarak = jarak;

    if (macet == "ya" || macet == "Ya") {
        jalanBaru2.macet = true;
    } else if (macet == "tidak" || macet == "Tidak") {
        jalanBaru2.macet = false;
    } else {
        cout << "Input untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
        return;
    }
    Addr_Edge edge2 = Alokasi_Edge(jalanBaru2);
    InsertLast_Edge(G, vertexGudang2, NULL, edge2);

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
        Jalan jalanBaru1;
        jalanBaru1.gudang = Info(vertexGudang);
        jalanBaru1.pomBensin = Info(vertexPomBensin);
        jalanBaru1.nama = jalan;
        jalanBaru1.jarak = jarak;

        if (macet == "ya" || macet == "Ya") {
            jalanBaru1.macet = true;
        } else if (macet == "tidak" || macet == "Tidak") {
            jalanBaru1.macet = false;
        } else {
            cout << "Input untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
            return;
        }

        Addr_Edge newEdge = Alokasi_Edge(jalanBaru1);
        if (newEdge == NULL) {
            cout << "Gagal mengalokasikan edge baru." << endl;
            return;
        }
        InsertLast_Edge(G, vertexGudang, NULL, newEdge);

        // Create reverse edge
        Jalan jalanBaru2;
        jalanBaru2.gudang = Info(vertexGudang);
        jalanBaru2.pomBensin = Info(vertexPomBensin);
        jalanBaru2.nama = jalan;
        jalanBaru2.jarak = jarak;
        jalanBaru2.macet = jalanBaru1.macet;

        Addr_Edge reverseEdge = Alokasi_Edge(jalanBaru2);
        if (reverseEdge == NULL) {
            cout << "Gagal mengalokasikan reverse edge." << endl;
            return;
        }
        InsertLast_Edge(G, NULL, vertexPomBensin, reverseEdge);

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
        edge.gudang = Info(vertexGudang);
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
        InsertLast_Edge(G, vertexGudang, NULL, newEdge);

        // Create reverse edge
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
        InsertLast_Edge(G, NULL, vertexPomBensin, reverseEdge);

        cout << "Jalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " telah berhasil dihubungkan!" << endl;
    } else {
        cout << "Gudang atau Pom Bensin tidak ditemukan!" << endl;
    }
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


// main fitur
Addr_Vertex_PomBensin Cari_PomBensin_Terdekat(Graph &G, Addr_Vertex_Gudang gudang) {
    Addr_Vertex_PomBensin pomBensin = StartPomBensin(G);
    Addr_Vertex_PomBensin nearestPom = NULL;
    int minDistance = INT_MAX;

    while (pomBensin != NULL) {
        int distance = abs(Info(gudang).lokasi[0] - Info(pomBensin).lokasi[0]);
        if (distance < minDistance) {
            minDistance = distance;
            nearestPom = pomBensin;
        }
        pomBensin = pomBensin->NextVertex;
    }

    return nearestPom;
}

Addr_Edge Rute_Alternatif(Graph &G, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima) {
    Addr_Edge edge = FirstEdge(pengirim);

    while (edge != NULL) {
        if (!Info(edge).gudang.nama.empty() && Info(edge).gudang.nama != Info(penerima).nama && !Info(edge).macet) {
            return edge;
        }
        edge = edge->NextEdge;
    }
    return NULL;
}


void Catat_Jalan(Graph &G, Infotype_Gudang &gudangA, Infotype_Gudang &GudangB, Infotype_Edge &jalur, Infotype_Truck &truk) {
    Addr_Vertex_Gudang nodeA = Find_Vertex_Gudang(G, gudangA.nama);
    Addr_Vertex_Gudang nodeB = Find_Vertex_Gudang(G, GudangB.nama);
    if (nodeA != NULL && nodeB != NULL && !Info(nodeA).nama.empty() && !Info(nodeB).nama.empty()) {
        Addr_Edge newEdge1 = Alokasi_Edge({jalur.nama, 0, 0});
        if(newEdge1 != NULL){
        NextEdge(newEdge1) = FirstEdge(nodeA);
        FirstEdge(nodeA) = newEdge1;
        }
        cout << "Jalur dari " << gudangA.nama << " melalui " << jalur.nama << " ke " << GudangB.nama << " dengan truk " << truk.nama << " telah dicatat." << endl;
    }
}


void Rute_Tercepat(Graph &G, Addr_Truck truk, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima, int jumBarang) {
    double biayaPerjalanan = 0;
    Addr_Edge edge = FirstEdge(pengirim);

    // Pencarian rute pertama
    while (edge != NULL) {
        if (!Info(edge).gudang.nama.empty() && Info(edge).gudang.nama == Info(penerima).nama) {
            cout << "Mengambil jalan: " << Info(edge).nama << " dengan jarak: " << Info(edge).jarak << endl;

            if (Info(edge).macet) {
                cout << "Jalan ini macet, menghindari!" << endl;
                edge = NextEdge(edge);
                continue;
            }

            Info(truk).bensin -= Info(edge).jarak * 0.1;
            biayaPerjalanan += Info(edge).jarak * 100;

            cout << "Sisa bensin truk: " << truk->Info.bensin << endl;

            if (Info(truk).bensin <= 0) {
                Addr_Vertex_PomBensin pomBensinTerdekat = Cari_PomBensin_Terdekat(G, pengirim);

                if (pomBensinTerdekat != NULL) {
                    double bensinDiPom = pomBensinTerdekat->Info.stokBensin;
                    double bensinYangDiperlukan = abs(truk->Info.bensin);

                    if (bensinDiPom >= bensinYangDiperlukan) {
                        Info(truk).bensin += bensinYangDiperlukan;
                        Info(pomBensinTerdekat).stokBensin -= bensinYangDiperlukan;
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
        edge = NextEdge(edge);
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
                cout << "Rute alternatif ditemukan: " << Info(edge).nama << " dengan jarak: " << Info(edge).jarak << endl;

                Info(truk).bensin -= Info(edge).jarak * 0.1;
                biayaPerjalanan += Info(edge).jarak * 100;

                cout << "Sisa bensin truk: " << Info(truk).bensin << endl;
                cout << "Total biaya perjalanan: " << biayaPerjalanan << endl;
            } else {
                cout << "Tidak ada rute alternatif yang ditemukan!" << endl;
            }
        } else {
            cout << "Pengiriman dibatalkan. Tidak ada rute yang ditemukan." << endl;
        }
    } else {
        // Jika rute ditemukan, transfer barang
        Info(pengirim).barang -= jumBarang;
        Info(penerima).barang += jumBarang;
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