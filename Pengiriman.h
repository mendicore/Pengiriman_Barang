#ifndef PENGIRIMAN_H_INCLUDED
#define PENGIRIMAN_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define Info(P)             (P)->Info
#define FirstEdge(P)        (P)->FirstEdge
#define FirstTruck(P)       (P).FirstTruck
#define NextVertex(P)       (P)->NextVertex
#define NextEdge(P)         (P)->NextEdge
#define NextTruck(P)        (P)->NextTruck
#define StartGudang(G)      (G).StartGudang
#define StartPomBensin(G)   (G).StartPomBensin

typedef struct Gudang       Infotype_Gudang;
typedef struct Jalan        Infotype_Edge;
typedef struct Pom_Bensin   Infotype_PomBensin;
typedef struct Truck        Infotype_Truck;

typedef struct Vertex_Gudang_Elmt*       Addr_Vertex_Gudang;
typedef struct Edge_Elmt*                Addr_Edge;
typedef struct Vertex_PomBensin_Elmt*    Addr_Vertex_PomBensin;
typedef struct Truck_Elmt*               Addr_Truck;


const int maxGudang = 100;

//informasi gudang
struct Gudang
{
    string nama;
    string lokasi;
    int kapasitas;
    int barang;
};

struct Pom_Bensin
{
    string nama;
    string lokasi;
    double stokBensin;
};

//informasi jalan
struct Jalan
{
    Gudang gudang;
    Pom_Bensin pomBensin;
    string nama;
    double jarak;
    bool macet;
};

//informasi truck
struct Truck
{
    string nama;
    int kapasitas;
    int muatan;
    double bensin;
};

//elemen vertex
struct Vertex_Gudang_Elmt
{
    Infotype_Gudang Info;
    Addr_Vertex_Gudang NextVertex;
    Addr_Edge FirstEdge;
};

//elemen edge
struct Edge_Elmt
{
    Infotype_Edge Info;
    Addr_Edge NextEdge;
};

//elemen pom bensin
struct Vertex_PomBensin_Elmt
{
    Infotype_PomBensin Info;
    Addr_Vertex_PomBensin NextVertex;
    Addr_Edge FirstEdge;
};

/*
{Elemen vertex (gudang dan pom bensin digabung)}
struct Vertex_Elmt 
{
    string tipe; {"Gudang" atau "PomBensin", setara char*}
    Infotype_Gudang gudang;
    Infotype_PomBensin pomBensin;
    Addr_Vertex NextVertex;
    Addr_Edge FirstEdge;
};
*/

//elemen truck
struct Truck_Elmt
{
    Infotype_Truck Info;
    Addr_Truck NextTruck;
};

//graph
struct Graph
{
    Addr_Vertex_Gudang StartGudang;
    Addr_Vertex_PomBensin StartPomBensin;
};

//list truck
struct TruckList
{
    Addr_Truck FirstTruck;
};

void Create_Graph(Graph &G);
void Create_Truck(TruckList &T);

Addr_Vertex_Gudang     Alokasi_Gudang(Infotype_Gudang infogudang);
Addr_Edge              Alokasi_Edge(Infotype_Edge infoEdge);
Addr_Vertex_PomBensin  Alokasi_PomBensin(Infotype_PomBensin infoPomBensin);
Addr_Truck             Alokasi_Truck(Infotype_Truck infoTruck);

Addr_Vertex_Gudang     Find_Vertex_Gudang(Graph &G, string nama);
Addr_Edge              Find_Edge(Graph &G, string nama);
Addr_Vertex_PomBensin  Find_Vertex_PomBensin(Graph &G, string nama);
Addr_Truck             Find_Truck(TruckList &T, string nama);

void Add_Vertex_Gudang(Graph &G, Addr_Vertex_Gudang P);
void Add_Vertex_PomBensin(Graph &G, Addr_Vertex_PomBensin P);
void Add_Truck(TruckList &T, Addr_Truck P);
void InsertLast_Edge(Graph &G, Addr_Vertex_Gudang nodeGudang, Addr_Vertex_PomBensin nodePomBensin, Addr_Edge newEdge);

void Delete_Vertex_Gudang(Graph &G, Addr_Vertex_Gudang &P);
void Delete_Vertex_PomBensin(Graph &G, Addr_Vertex_PomBensin &P);
void Delete_Truck(TruckList &T, Addr_Truck &P);

void Connecting_Gudang_TakBerarah(Graph &G, string gudang1, string gudang2, string jalan, double jarak, string macet);
void Connecting_Gudang_Berarah(Graph &G, string gudang1, string gudang2, string jalan, double jarak, string macet);
void Disconnecting_Gudang1(Graph &G, string gudang1, string gudang2);
void Disconnecting_Gudang2(Graph &G, string gudang1, string gudang2);

void Connecting_PomBensin_To_Gudang_TakBerarah(Graph &G, string gudang, string pomBensin, string jalan, double jarak, string macet);
void Connecting_Gudang_To_PomBensin_TakBerarah(Graph &G, string pomBensin, string gudang, string jalan, double jarak, string macet);
void Connecting_PomBensin_To_Gudang_Berarah(Graph &G, string gudang, string pomBensin, string jalan, double jarak, string macet);
void Connecting_Gudang_To_PomBensin_Berarah(Graph &G, string pomBensin, string gudang, string jalan, double jarak, string macet);

void Disconnecting_PomBensin_To_Gudang(Graph &G, string gudang, string pomBensin);
void Disconnecting_Gudang_To_PomBensin(Graph &G, string pomBensin, string gudang);

Addr_Vertex_PomBensin Cari_PomBensin_Terdekat(Graph &G, Addr_Vertex_Gudang gudang, Addr_Vertex_PomBensin pomBensin);
void Rute_Tercepat(Graph &G, Addr_Truck truk, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima, int jumBarang);
Addr_Edge Rute_Alternatif(Graph &G, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima);
Addr_Edge Rute_Alternatif_Tidak_Macet(Graph &G, Addr_Vertex_Gudang pengirim, Addr_Vertex_Gudang penerima);
void Catat_Jalan(Graph &G, Infotype_Gudang &gudangA, Infotype_Gudang &GudangB, Infotype_Edge &jalur, Infotype_Truck &truk);

void Show_Graph(Graph &G);
void Show_Trucks(TruckList &T);
double mutlakGanda(double x);
#endif // PENGIRIMAN_H_INCLUDED