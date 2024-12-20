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

void CreateTruck(TruckList &T);
adr_Truck Alokasi(Truck x);
void addTruck(TruckList &T, Truck x);
void AddMuatan(TruckList &T, string name, int muatan);
void deleteMuatan(TruckList &T, string name, int muatan);
void deleteTruck(TruckList &T, string name);
void showAllTruck(TruckList &T);
double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak);
double KapasitasMaksimal(TruckList &T, string name);
void HanyaLewat(TruckList &T, string name);
bool ApakahMacetatauHambatan(Graph &G, string gudang, string jalur);
void CatatJalur(Graph &G, string gudang, string jalur, string truk);
string JalurAlternatif(Graph &G, string gudang, string jalur);
void PilihRute(TruckList &T, Graph &G, string gudang, string jalur, string truk, double bensin, double muatan, double jarak);

#endif // TRUCK_H_INCLUDED
