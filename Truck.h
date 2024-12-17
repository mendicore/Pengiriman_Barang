#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info

typedef struct elm_Truck* adr_Truck;

struct Truck {
    string name;
    int jumlahRoda;
    double kapasitas;
    double bensin;
    int muatan;
};

struct elm_Truck {
    Truck info;
    adr_Truck next;
};

struct TruckList {
    adr_Truck first;
};

void CreateTruck(TruckList &T);
adr_Truck Alokasi(Truck x);
void addTruck(TruckList &T, Truck x);
void AddMuatan(TruckList &T, string name, int muatan);
void deleteMuatan(TruckList &T, string name, int muatan);
void deleteTruck(TruckList &T, string x);
double biayaPengiriman(TruckList L, string name, double biayaPerMuatan, double biayaPerKm, double jarak);

#endif // TRUCK_H_INCLUDED
