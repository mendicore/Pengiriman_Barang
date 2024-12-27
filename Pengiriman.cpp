#include "Pengiriman.h"

// create
void Create_Graph(Graph &G) {
    Start(G) = NULL;
}

void Create_Truck(TruckList &T) {
    FirstTruck(T) = NULL;
}

// alokasi
Addr_Vertex Alokasi_Vertex(string tipe, Infotype_Gudang gudang, Infotype_PomBensin pomBensin) {
    Addr_Vertex P = new Vertex_Elmt;

    if (P != NULL) {
        P->tipe = tipe;

        if (tipe == "Gudang") {
            if (gudang.nama.empty()) {
                P->gudang = {"Tidak Diketahui", "Tidak Diketahui", 0, 0};
            } else {
                P->gudang = gudang;
            }
        }
        else if (tipe == "PomBensin") {
            if (pomBensin.nama.empty()) {
                P->pomBensin = {"Tidak Diketahui", "Tidak Diketahui", 0.0};
            } else {
                P->pomBensin = pomBensin;
            }
        }

        P->NextVertex = NULL;
        P->FirstEdge = NULL;
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

Addr_Truck Alokasi_Truck(Infotype_Truck infoTruck) {
    Addr_Truck P = new Truck_Elmt;
    if (P != NULL) {
        Info(P) = infoTruck;
        NextTruck(P) = NULL;
    }
    return P;
}

// find
Addr_Vertex Find_Vertex(Graph &G, string nama, string tipe) {
    Addr_Vertex P = Start(G);
    while (P != NULL) {
        if (P->tipe == tipe) {
            if (tipe == "Gudang" && P->gudang.nama == nama) {
                return P;
            }
            if (tipe == "PomBensin" && P->pomBensin.nama == nama) {
                return P;
            }
        }
        P = NextVertex(P);
    }
    return NULL;
}

Addr_Edge Find_Edge(Graph &G, string nama) {
    Addr_Vertex P = Start(G);
    while (P != NULL) {
        Addr_Edge E = FirstEdge(P);
        while (E != NULL) {
            if (Info(E).nama == nama) {
                return E;
            }
            E = NextEdge(E);
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
void Add_Vertex(Graph &G, Addr_Vertex P, string tipe) {
    if (Start(G) == NULL) {
        Start(G) = P;
    } else {
        Addr_Vertex Q = Start(G);
        while (NextVertex(Q) != NULL) {
            Q = NextVertex(Q);
        }
        NextVertex(Q) = P;
    }

    if (tipe == "Gudang") {
        cout << "\nGudang " << P->gudang.nama << " berhasil ditambahkan!" << endl;
    } else if (tipe == "PomBensin") {
        cout << "\nPom Bensin " << P->pomBensin.nama << " berhasil ditambahkan!" << endl;
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
    cout << "\ntruk " << P->Info.nama << " berhasil ditambahkan!" << endl;
}

// delete
void Delete_Vertex(Graph &G, Addr_Vertex P, string tipe) {
    if (Start(G) == NULL) {
        cout << "Tidak ada vertex yang tersedia!" << endl;
        return;
    }

    if (Start(G) == P) {
        Start(G) = NextVertex(P);
    } else {
        Addr_Vertex Q = Start(G);
        while (Q != NULL && NextVertex(Q) != P) {
            Q = NextVertex(Q);
        }

        if (Q != NULL) {
            NextVertex(Q) = NextVertex(P);
        }
    }

    if (tipe == "Gudang") {
        cout << "\nGudang " << P->gudang.nama << " berhasil dihapus!" << endl;
    } else if (tipe == "PomBensin") {
        cout << "\nPom Bensin " << P->pomBensin.nama << " berhasil dihapus!" << endl;
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

// insert last
void InsertLast_Edge(Graph &G, Addr_Vertex vertex, Addr_Edge edge) {
    if (FirstEdge(vertex) == NULL) {
        FirstEdge(vertex) = edge;
    } else {
        Addr_Edge lastEdge = FirstEdge(vertex);
        while (NextEdge(lastEdge) != NULL) {
            lastEdge = NextEdge(lastEdge);
        }
        NextEdge(lastEdge) = edge;
    }
}


// connecting  & disconnecting gudang
void Connecting_Vertex(Graph &G, string vertex1, string vertex2, string jalan, double jarak, string macet) {
    // Temukan vertex berdasarkan nama dan tipe
    Addr_Vertex vertex1Addr = Find_Vertex(G, vertex1, "Gudang");
    Addr_Vertex vertex2Addr = Find_Vertex(G, vertex2, "Gudang");

    if (vertex1Addr == NULL) {
        cout << "\nGudang " << vertex1 << " tidak ditemukan!" << endl;
        return;
    }
    if (vertex2Addr == NULL) {
        cout << "\nGudang " << vertex2 << " tidak ditemukan!" << endl;
        return;
    }

    // Menyiapkan data jalan untuk vertex1
    Jalan jalanBaru1;
    if (vertex1Addr->tipe == "Gudang") {
        jalanBaru1.nama = jalan;
        jalanBaru1.jarak = jarak;
        jalanBaru1.macet = (macet == "ya" || macet == "Ya");
        jalanBaru1.gudang = vertex2Addr->gudang;  // Menggunakan info Gudang
    } else if (vertex1Addr->tipe == "PomBensin") {
        jalanBaru1.nama = jalan;
        jalanBaru1.jarak = jarak;
        jalanBaru1.macet = (macet == "ya" || macet == "Ya");
        jalanBaru1.pomBensin = vertex2Addr->pomBensin;  // Menggunakan info PomBensin
    }

    Addr_Edge edge1 = Alokasi_Edge(jalanBaru1);
    InsertLast_Edge(G, vertex1Addr, edge1);

    // Menyiapkan data jalan untuk vertex2
    Jalan jalanBaru2;
    if (vertex2Addr->tipe == "Gudang") {
        jalanBaru2.nama = jalan;
        jalanBaru2.jarak = jarak;
        jalanBaru2.macet = (macet == "ya" || macet == "Ya");
        jalanBaru2.gudang = vertex1Addr->gudang;  // Menggunakan info Gudang
    } else if (vertex2Addr->tipe == "PomBensin") {
        jalanBaru2.nama = jalan;
        jalanBaru2.jarak = jarak;
        jalanBaru2.macet = (macet == "ya" || macet == "Ya");
        jalanBaru2.pomBensin = vertex1Addr->pomBensin;  // Menggunakan info PomBensin
    }

    Addr_Edge edge2 = Alokasi_Edge(jalanBaru2);
    InsertLast_Edge(G, vertex2Addr, edge2);

    cout << "\nJalan antara " << vertex1 << " dan " << vertex2 << " telah berhasil dihubungkan!" << endl;
}

void Disconnecting_Vertex(Graph &G, string gudang1, string gudang2) {
    // Mencari vertex dengan tipe "Gudang" dan nama gudang1 dan gudang2
    Addr_Vertex vertexGudang1 = Find_Vertex(G, gudang1, "Gudang");
    Addr_Vertex vertexGudang2 = Find_Vertex(G, gudang2, "Gudang");

    if (vertexGudang1 == NULL) {
        cout << "\nGudang " << gudang1 << " tidak ditemukan!" << endl;
        return;
    }
    if (vertexGudang2 == NULL) {
        cout << "\nGudang " << gudang2 << " tidak ditemukan!" << endl;
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
        cout << "\nJalan antara " << gudang1 << " dan " << gudang2 << " telah diputus!" << endl;
    } else {
        cout << "\nJalan antara " << gudang1 << " dan " << gudang2 << " tidak ditemukan!" << endl;
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
        cout << "\nJalan antara " << gudang2 << " dan " << gudang1 << " telah diputus!" << endl;
    } else {
        cout << "\nJalan antara " << gudang2 << " dan " << gudang1 << " tidak ditemukan!" << endl;
    }
}


// connecting & disconnecting pom bensin dengan gudang atau sebaliknya
void Connecting_PomBensin_To_Gudang(Graph &G, string pomBensin, string gudang, string jalan, double jarak, string macet) {
    Addr_Vertex vertexPomBensin = Find_Vertex(G, pomBensin, "PomBensin");
    Addr_Vertex vertexGudang = Find_Vertex(G, gudang, "Gudang");

    if (vertexPomBensin != NULL && vertexGudang != NULL) {
        Jalan jalanBaru;
        jalanBaru.gudang = vertexGudang->gudang;
        jalanBaru.pomBensin = vertexPomBensin->pomBensin;
        jalanBaru.nama = jalan;
        jalanBaru.jarak = jarak;

        if (macet == "ya" || macet == "Ya") {
            jalanBaru.macet = true;
        } else if (macet == "tidak" || macet == "Tidak") {
            jalanBaru.macet = false;
        } else {
            cout << "\nInput untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
            return;
        }

        Addr_Edge newEdge = new Edge_Elmt;
        if (newEdge == NULL) {
            cout << "\nGagal mengalokasikan edge baru." << endl;
            return;
        }
        newEdge->Info = jalanBaru;
        newEdge->NextEdge = NULL;
        InsertLast_Edge(G, vertexPomBensin, newEdge);

        Jalan jalanBaruReverse = jalanBaru;
        Addr_Edge reverseEdge = new Edge_Elmt;
        if (reverseEdge == NULL) {
            cout << "\nGagal mengalokasikan reverse edge." << endl;
            return;
        }
        reverseEdge->Info = jalanBaruReverse;
        reverseEdge->NextEdge = NULL;
        InsertLast_Edge(G, vertexGudang, reverseEdge);

        cout << "\nJalan antara Pom Bensin " << pomBensin << " dan Gudang " << gudang << " telah berhasil dihubungkan!" << endl;
    } else {
        cout << "\nPom Bensin atau Gudang tidak ditemukan!" << endl;
    }
}

void Connecting_Gudang_To_PomBensin(Graph &G, string gudang, string pomBensin, string jalan, double jarak, string macet) {
    Addr_Vertex vertexGudang = Find_Vertex(G, gudang, "Gudang");
    Addr_Vertex vertexPomBensin = Find_Vertex(G, pomBensin, "PomBensin");

    if (vertexPomBensin != NULL && vertexGudang != NULL) {
        Infotype_Edge edge;
        edge.gudang = vertexGudang->gudang;
        edge.pomBensin = vertexPomBensin->pomBensin;
        edge.nama = jalan;
        edge.jarak = jarak;

        if (macet == "ya" || macet == "Ya") {
            edge.macet = true;
        } else if (macet == "tidak" || macet == "Tidak") {
            edge.macet = false;
        } else {
            cout << "\nInput untuk macet tidak valid. Gunakan 'ya' atau 'tidak'." << endl;
            return;
        }

        Addr_Edge newEdge = Alokasi_Edge(edge);
        if (newEdge == NULL) {
            cout << "\nGagal mengalokasikan edge baru." << endl;
            return;
        }
        InsertLast_Edge(G, vertexGudang, newEdge);

        Infotype_Edge reverseEdgeInfo = edge;
        Addr_Edge reverseEdge = Alokasi_Edge(reverseEdgeInfo);
        if (reverseEdge == NULL) {
            cout << "\nGagal mengalokasikan reverse edge." << endl;
            return;
        }
        InsertLast_Edge(G, vertexPomBensin, reverseEdge);

        cout << "\nJalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " telah berhasil dihubungkan!" << endl;
    } else {
        cout << "\nGudang atau Pom Bensin tidak ditemukan!" << endl;
    }
}


void Disconnecting_Gudang_PomBensin(Graph &G, string pomBensin, string gudang) {
    Addr_Vertex vertexGudang = Find_Vertex(G, gudang, "Gudang");
    Addr_Vertex vertexPomBensin = Find_Vertex(G, pomBensin, "PomBensin");

    if (vertexPomBensin == NULL || vertexGudang == NULL) {
        cout << "\nGudang atau Pom Bensin tidak ditemukan!" << endl;
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
            delete edge; // Menghapus edge
            cout << "\nJalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " telah diputus." << endl;
            return;
        }
        prevEdge = edge;
        edge = NextEdge(edge);
    }
    cout << "\nJalan antara Gudang " << gudang << " dan Pom Bensin " << pomBensin << " tidak ditemukan!" << endl;
}


void Disconnecting_PomBensin_Gudang(Graph &G, string gudang, string pomBensin) {
    Addr_Vertex vertexPomBensin = Find_Vertex(G, pomBensin, "PomBensin");
    Addr_Vertex vertexGudang = Find_Vertex(G, gudang, "Gudang");

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
            delete edge;
            cout << "\nJalan antara Pom Bensin " << pomBensin << " dan Gudang " << gudang << " telah diputus." << endl;
            return;
        }
        prevEdge = edge;
        edge = NextEdge(edge);
    }
    cout << "\nJalan antara Pom Bensin " << pomBensin << " dan Gudang " << gudang << " tidak ditemukan!" << endl;
}


// main fitur
Addr_Vertex FindPomBensinTerdekat(Addr_Vertex current) {
    Addr_Vertex nearestPom = nullptr;
    double minDistance = 1000000;

    Addr_Edge edge = current->FirstEdge;
    while (edge != nullptr) {
        if (edge->Info.pomBensin.stokBensin > 0) {
            double distance = edge->Info.jarak;
            if (distance < minDistance) {
                minDistance = distance;
                nearestPom = edge->NextVertex;
            }
        }
        edge = edge->NextEdge;
    }

    return nearestPom;
}




void Rute_Alternatif(Graph &G, Addr_Vertex pengirim, Addr_Vertex penerima, double bensin) {
    static bool visited[maxGudang] = {false};

    if (pengirim == penerima) {
        cout << "Rute alternatif ditemukan.\n";
        return;
    }

    visited[pengirim->tipe[0]] = true;

    Addr_Edge edge = pengirim->FirstEdge;
    while (edge != nullptr) {
        if (!edge->Info.macet && !visited[edge->NextVertex->tipe[0]] && bensin >= edge->Info.jarak) {
            double remaining_bensin = bensin - edge->Info.jarak;
            cout << "Melalui jalan dari " << pengirim->tipe << " ke " << edge->NextVertex->tipe << " dengan bensin tersisa: " << remaining_bensin << "\n";
            Rute_Alternatif(G, edge->NextVertex, penerima, remaining_bensin);
        }
        edge = edge->NextEdge;
    }

    visited[pengirim->tipe[0]] = false;
}


void Rute_Tercepat(Graph &G, Addr_Truck truk, Addr_Vertex pengirim, Addr_Vertex penerima, int jumBarang) {
    Addr_Vertex current = pengirim;
    double bensin = truk->Info.bensin;
    double totalBiaya = 0.0;
    bool found = false;

    vector<string> jalur;

    cout << "Jalur yang dilewati: ";

    while (current != nullptr && !found) {
        jalur.push_back(current->tipe);

        if (current == penerima) {
            found = true;
            break;
        }

        Addr_Edge edge = current->FirstEdge;
        bool moved = false;

        while (edge != nullptr) {
            if (!edge->Info.macet && bensin - edge->Info.jarak >= 0) {
                bensin -= edge->Info.jarak;
                totalBiaya += edge->Info.jarak;
                current = edge->NextVertex;
                moved = true;
                break;
            }
            edge = edge->NextEdge;
        }

        if (!moved) {
            cout << "Tidak ada jalan yang dapat dilalui, tidak dapat mencapai tujuan.\n";
            break;
        }

        if (bensin <= 0) {
            cout << "Bensin habis, mencari pom bensin terdekat...\n";
            Addr_Vertex nearestPom = FindPomBensinTerdekat(current);
            if (nearestPom != nullptr) {
                cout << "Pom bensin terdekat ditemukan di " << nearestPom->tipe << "\n";
                bensin = 100.0;
                current = nearestPom;
            } else {
                cout << "Tidak ada pom bensin terdekat, tidak dapat mencapai tujuan.\n";
                break;
            }
        }
    }

    for (const string& t : jalur) {
        cout << t << " -> ";
    }

    if (found) {
        cout << penerima->tipe << "\nRute tercepat ditemukan dengan total biaya: " << totalBiaya << endl;
    } else {
        cout << "\nTidak dapat mencapai tujuan.\n";
        string pilihan;
        cout << "Apakah Anda ingin mencari rute alternatif? (ya/tidak): ";
        cin >> pilihan;

        if (pilihan == "ya" || pilihan == "Ya") {
            Rute_Alternatif(G, pengirim, penerima, bensin);
        }
    }
}




// menampilkan graph dan list
void Show_Graph(Graph &G) {
    cout << "<<===================================================================================>>" << endl;
    cout << "                                       GRAPH                                           " << endl;
    cout << "<<----------------------------------------------------------------------------------->>" << endl;

    // Menampilkan Gudang dan Pom Bensin
    if (Start(G) != NULL) {
        // Perulangan untuk menampilkan Gudang dan Pom Bensin
        for (Addr_Vertex V = Start(G); V != NULL; V = NextVertex(V)) {
            if (!V->gudang.nama.empty()) {
                // Menampilkan Gudang
                cout << "\tGudang: " << left << setw(25) << V->gudang.nama
                     << ", berlokasi di " << V->gudang.lokasi << endl
                     << "\t\tKapastitas: " << left << setw(10) << V->gudang.kapasitas
                     << " | Jumlah barang: " << V->gudang.barang << endl;
                cout << "<<===================================================================================>>" << endl;
                cout << left << setw(15) << "[Nama Gudang]"
                     << setw(20) << "[Nama Jalan]"
                     << setw(15) << "[Lokasi]"
                     << setw(10) << "[Jarak]"
                     << setw(15) << "[Status Macet]" << endl;
                cout << "<<----------------------------------------------------------------------------------->>" << endl;

                // Tampilkan tetangga (edge) yang menghubungkan Gudang ke Pom Bensin
                for (Addr_Edge E = FirstEdge(V); E != NULL; E = NextEdge(E)) {
                    cout << left
                         << setw(15) << E->Info.gudang.nama
                         << setw(20) << E->Info.nama
                         << setw(15) << E->Info.gudang.lokasi
                         << setw(10) << E->Info.jarak
                         << setw(15) << (E->Info.macet ? "Ya" : "Tidak")
                         << endl;

                    // Menampilkan Pom Bensin sebagai tetangga jika ada
                    if (!E->Info.pomBensin.nama.empty()) {
                        cout << "\tTetangga: Pom Bensin " << E->Info.pomBensin.nama << endl;
                    }
                }
                cout << "<<----------------------------------------------------------------------------------->>" << endl << endl;
            }

            if (!V->pomBensin.nama.empty()) {
                // Menampilkan Pom Bensin
                cout << "\tPom Bensin: " << left << setw(25) << V->pomBensin.nama
                     << " berlokasi di " << V->pomBensin.lokasi << endl
                     << "\t\tStok bensin: " << left << setw(10) << V->pomBensin.stokBensin << endl
                     << "\t\tTetangga: " << endl;

                cout << "<<===================================================================================>>" << endl;
                cout << left << setw(15) << "[Nama Pom Bensin]"
                     << setw(20) << "[Nama Jalan]"
                     << setw(15) << "[Lokasi]"
                     << setw(10) << "[Jarak]"
                     << setw(15) << "[Status Macet]" << endl;
                cout << "<<----------------------------------------------------------------------------------->>" << endl;

                // Tampilkan tetangga (edge) yang menghubungkan Pom Bensin ke Gudang
                for (Addr_Edge E = FirstEdge(V); E != NULL; E = NextEdge(E)) {
                    cout << left << setw(15) << E->Info.pomBensin.nama
                         << setw(20) << E->Info.nama
                         << setw(15) << E->Info.pomBensin.lokasi
                         << setw(10) << E->Info.jarak
                         << setw(15) << (E->Info.macet ? "Ya" : "Tidak")
                         << endl;

                    // Menampilkan Gudang sebagai tetangga jika ada
                    if (!E->Info.gudang.nama.empty()) {
                        cout << "\tTetangga: Gudang " << E->Info.gudang.nama << endl;
                    }
                }
                cout << "<<----------------------------------------------------------------------------------->>" << endl << endl;
            }
        }
    } else {
        cout << "Graf Kosong (Gudang dan Pom Bensin)" << endl;
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
