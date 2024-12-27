#ifndef PENGIRIMAN_H_INCLUDED
#define PENGIRIMAN_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

#define Info(P)             (P)->Info
#define FirstEdge(P)        (P)->FirstEdge
#define NextVertex(P)       (P)->NextVertex
#define NextEdge(P)         (P)->NextEdge
#define FirstTruck(P)       (P).FirstTruck
#define NextTruck(P)        (P)->NextTruck
#define Start(G)            (G).Start

typedef struct Gudang       Infotype_Gudang;
typedef struct Jalan        Infotype_Edge;
typedef struct Pom_Bensin   Infotype_PomBensin;
typedef struct Truck        Infotype_Truck;

typedef struct Vertex_Elmt* Addr_Vertex;
typedef struct Edge_Elmt*   Addr_Edge;
typedef struct Truck_Elmt*  Addr_Truck;

const int maxGudang = 100;

// Informasi gudang
struct Gudang {
    string nama;
    string lokasi;
    int kapasitas;
    int barang;
};

// Informasi pom bensin
struct Pom_Bensin {
    string nama;
    string lokasi;
    double stokBensin;
};

// Informasi jalan
struct Jalan {
    string nama;
    double jarak;
    bool macet;
    Infotype_Gudang gudang;
    Infotype_PomBensin pomBensin;
};

// Informasi truck
struct Truck {
    string nama;
    int kapasitas;
    int muatan;
    double bensin;
};

// Elemen vertex (gudang dan pom bensin digabung)
struct Vertex_Elmt {
    string tipe; // "Gudang" atau "PomBensin"
    Infotype_Gudang gudang;
    Infotype_PomBensin pomBensin;
    Addr_Vertex NextVertex;
    Addr_Edge FirstEdge;
};

// Elemen edge
struct Edge_Elmt {
    Infotype_Edge Info;
    Addr_Edge NextEdge;
    Addr_Vertex NextVertex;
};

// Elemen truck
struct Truck_Elmt {
    Infotype_Truck Info;
    Addr_Truck NextTruck;
};

// Graph
struct Graph {
    Addr_Vertex Start;
};

// List truck
struct TruckList {
    Addr_Truck FirstTruck;
};

// Fungsi dan prosedur
void Create_Graph(Graph &G);
void Create_Truck(TruckList &T);

Addr_Vertex Alokasi_Vertex(string tipe, Infotype_Gudang gudang, Infotype_PomBensin pomBensin);
Addr_Edge   Alokasi_Edge(Infotype_Edge infoEdge);
Addr_Truck  Alokasi_Truck(Infotype_Truck infoTruck);

Addr_Vertex Find_Vertex(Graph &G, string nama, string tipe);
Addr_Edge   Find_Edge(Graph &G, string nama);
Addr_Truck  Find_Truck(TruckList &T, string nama);

void Add_Vertex(Graph &G, Addr_Vertex P, string tipe);
void Add_Truck(TruckList &T, Addr_Truck P);
void InsertLast_Edge(Graph &G, Addr_Vertex PNode, Addr_Edge PEdge);

void Delete_Vertex(Graph &G, Addr_Vertex P, string tipe);
void Delete_Truck(TruckList &T, Addr_Truck P);

void InsertLast_Edge(Graph &G, Addr_Vertex vertex, Addr_Edge edge);

void Connecting_Vertex(Graph &G, string vertex1, string vertex2, string jalan, double jarak, string macet);
void Disconnecting_Vertex(Graph &G, string vertex1, string vertex2);

void Connecting_PomBensin_To_Gudang(Graph &G, string gudang, string pomBensin, string jalan, double jarak, string macet);
void Connecting_Gudang_To_PomBensin(Graph &G, string pomBensin, string gudang, string jalan, double jarak, string macet);
void Disconnecting_Gudang_PomBensin(Graph &G, string pomBensin, string gudang);
void Disconnecting_PomBensin_Gudang(Graph &G, string gudang, string pomBensin);

Addr_Vertex FindPomBensinTerdekat(Addr_Vertex current);
void Rute_Tercepat(Graph &G, Addr_Truck truk, Addr_Vertex pengirim, Addr_Vertex penerima, int jumBarang);
void Rute_Alternatif(Graph &G, Addr_Vertex pengirim, Addr_Vertex penerima, double bensin);

void Show_Graph(Graph &G);
void Show_Trucks(TruckList &T);
#endif // PENGIRIMAN_H_INCLUDED
