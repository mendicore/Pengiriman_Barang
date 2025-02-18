#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include <iostream>
#include "Rute.h"
#include <string>
using namespace std;

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info
typedef struct t_elm_Truck* adr_Truck;

typedef struct
{
    string name;
    int jumlahRoda;
    double kapasitas;
    double bensin;
    int muatan;
} Truck;

typedef Truck infotype_Truck;

typedef struct t_elm_Truck
{
    infotype_Truck info;
    adr_Truck next;
} elm_Truck;

typedef struct
{
    adr_Truck first;
} TruckList;;

void CreateTruck(TruckList &T);
adr_Truck Alokasi(infotype_Truck x);
void addTruck(TruckList &T, adr_Truck x);
void AddMuatan(TruckList &T, string name, int muatan);
void deleteMuatan(TruckList &T, string name, int muatan);
void deleteTruck(TruckList &T, string name, adr_Truck &P);
adr_Truck findTruck(TruckList &T, infotype_Truck x);
void showTrucks(TruckList &T);
double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak);
double KapasitasMaksimal(TruckList &T, string name);
double BensinperKapasitas(TruckList &T, string name, double bensin, double muatan, double jarak);
void isiBensin(TruckList &T, Graph &G, Graph_Pom_Bensin &A, string name, infotype_Truck truk, double bensin, double muatan, double jarak);
void HanyaLewat(TruckList &T, string name);
bool ApakahMacetatauHambatan(Graph &G, const Infotype_Node &gudang, const Infotype_Edge &jalur);
void CatatJalur(Graph &G, const Infotype_Node &gudangA, const Infotype_Node &GudangB, const Infotype_Edge &jalur, const infotype_Truck &truk, string macet);
//string JalurAlternatif(Graph &G, string gudang, string jalur);
void Pengiriman(TruckList &T, Graph &G, Graph_Pom_Bensin &GPB, const Infotype_Node &gudangA, const Infotype_Node &gudangB, const Infotype_Edge &jalur, const infotype_Truck &truk, double bensin, double muatan, double jarak);
#endif // TRUCK_H_INCLUDED