#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

//Sementara kayak gini dulu, ini belum disambungin ke Rute.h soalnya
#include <iostream>
#include <string>
using namespace std;

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info

typedef struct t_elm_Truck* adr_Truck;
typedef struct t_elm_Road* adr_Road;

typedef struct {
    string name;
    int jumlahRoda;
    double kapasitas;
    double bensin;
    int muatan;
} Truck;

typedef struct t_elm_Truck {
    Truck info;
    adr_Truck next;
} elm_Truck;

typedef struct {
    adr_Truck first;
} TruckList;

typedef struct{
    string name;
    adr_Truck trucks;
    adr_Road next;
} Road;

typedef struct t_elm_Road
{
    Road info;
    adr_Road next;
} elm_Road;

typedef struct
{
    adr_Road first;
} RoadList;

void CreateTruck(TruckList &T);
adr_Truck Alokasi(Truck x);
void addTruck(TruckList &T, Truck x);
void AddMuatan(TruckList &T, string name, int muatan);
void deleteMuatan(TruckList &T, string name, int muatan);
void deleteTruck(TruckList &T, string name);
double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak);
double KapasitasMaksimal(TruckList &T, string name);
void HanyaLewat(TruckList &T, string name);
double BensinperKapasitas(TruckList &T, string name, double bensin, int muatan, double jarak);
bool ApakahMacetatauHambatan(Graph &G, string gudang, string jalur);
void CatatJalur(Graph &G, string gudang, string jalur, string truk);
// string JalurAlternatif(RoadList &R, string gudang, string jalur);
void PilihRute(TruckList &T, Graph &G, string gudang, string jalur, string truk, double bensin, double muatan, double jarak);
#endif // TRUK_H_INCLUDED