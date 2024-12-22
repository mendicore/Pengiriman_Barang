#ifndef RUTE_H_INCLUDED
#define RUTE_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define info(P) (P)->info
#define NextNode(P)  	(P)->NextNode
#define NextEdge(P)  	(P)->NextEdge
#define nextTempList(P) (P)->nextTempList
#define nextBensinList(P) (P)->nextBensinList
#define FirstEdge(P) 	(P)->FirstEdge
#define FirstBensin(P) (P)->FirstBensin
#define Start(G) 		(G).Start
#define Null NULL

typedef struct vElmt Elmt_Node;
typedef struct eElmt Elmt_Edge;
typedef struct tempListElmt Elmt_TempList;
typedef struct bensinElmt Elmt_Bensin;
typedef Elmt_Node* Addr_Node;
typedef Elmt_Edge* Addr_Edge;
typedef Elmt_TempList* Addr_TempList;
typedef Elmt_Bensin* Addr_Bensin;

typedef struct{
   string nama;
   string lokasi;
   double kapasitas;
   int tinggi;
   int jumlah;
} Gudang;

/* kapasitas = jumlah liter tangki bensin.
   jumlah = jumlah dispenser bahan bakar*/
typedef struct
{
   string nama;
   string lokasi;
   double kapasitas;
   int jumlah;
} PomBensin;

typedef struct
{
    Gudang bangunan;
    string namaJalan;
    double jarak;
    int waktu;
} Jalan;

typedef string Infotype_TempList;
typedef PomBensin InfoType_Bensin;
typedef Gudang Infotype_Node;
typedef Jalan Infotype_Edge;

typedef struct
{
    Addr_TempList pertama;
} TempList;

typedef struct
{
    Addr_Bensin pertama;
} BensinList;

typedef struct {
    Addr_Node Start;
} Graph;

typedef struct {
    Addr_Bensin Start;
} Graph_Pom_Bensin;

struct vElmt {
   Infotype_Node info;
   Addr_Node NextNode;
   Addr_Edge FirstEdge;
};

struct tempListElmt
{
    Infotype_TempList info;
    Addr_TempList nextTempList;
};

struct eElmt {
   Infotype_Edge info;
   Addr_Edge NextEdge;
};

struct bensinElmt
{
    Addr_Node keGudang;
    InfoType_Bensin info;
    Addr_Bensin nextBensinList;
    Addr_Edge FirstBensin;
};

void CreateGraph(Graph &G);
void CreatePomBensin(Graph_Pom_Bensin &GPB);
void CreateTempList(TempList &L);
Addr_TempList AlokasiTempList(Infotype_TempList x);
Addr_Node AlokasiNode(Infotype_Node nameNode);
Addr_Edge AlokasiEdge(Infotype_Edge infoEdge);
Addr_Bensin AlokasiBensin(InfoType_Bensin infoBensin);
void AddNewNode(Graph &G, Addr_Node P);
void deleteNode(Graph &G, Addr_Node P);
void AddNewPomBensin(Graph_Pom_Bensin &GPB, Addr_Bensin P);
void deletePomBensin(Graph_Pom_Bensin &GPB, Addr_Bensin P);
Addr_Node FindNode(Graph G, string data);
Addr_Bensin FindBensin(Graph_Pom_Bensin GPB, string data);
void InsertLast_TempList(TempList& L, Addr_TempList P);
void InsertLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge);
void Connecting(Graph &G, string node1, string node2, string jalan, double jarak, int waktu);
void Connecting_Gudang_Bensin(Graph &G, string node1, string tempatBensin, string jalan, double jarak, int waktu);
void Connecting_Bensin_Gudang(Graph &G, string tempatBensin, string node2, string jalan, double jarak, int waktu);
Addr_Edge FindEdge(Graph &G, Addr_Node PNode, string data);
string FindLastTempList(const TempList &L);
void DeleteFirst_Bensin(Graph_Pom_Bensin &G, Addr_Bensin PBensin, Addr_Edge &P);
void DeleteFirst_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P);
void DeleteLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P);
void DeleteAfter_Edge(Graph &G, Addr_Node PNode, Addr_Edge Prec, Addr_Edge &P);
void Delete_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge);
void Disconnecting(Graph &G, string node1, string node2);
void Disconnecting_Gudang_Bensin(Graph &G, string node1, string tempatBensin);
void Disconnecting_Bensin_Gudang(Graph &G, string tempatBensin, string node2);
void AlJikstra(Graph G, Infotype_Node Mulai, Infotype_Node selesai, TempList T);
void catatTempList(const TempList &asal, TempList &tujuan);
void asistenJalurAlternatifDFS(Graph &G, const Infotype_Node &GudangSekarang, const Infotype_Node &GudangTujuan, int WaktuSekarang, int &WaktuMinimal, TempList &L, TempList &jalanTerbaik, const Infotype_Edge &namaJalanBlok);
void jalurAlternatifDFS(Graph &G, const Infotype_Node &awalGudang, const Infotype_Node &tujuanGudang, const Infotype_Edge &namaJalanBlok);
Addr_Edge findShortestRute(Graph G, Addr_Node AG, TempList AT);
bool telahDikunjungi(TempList AT, string Gudang);
void ShowAllGudangJalur(Graph &G);
void ShowAllPomBensin(Graph_Pom_Bensin &GPB);
void showPeta(Graph &G, Graph_Pom_Bensin &GPB);
void ShowTempList(TempList L);
void Delete_Templist(TempList &L);
#endif // RUTE_H_INCLUDED