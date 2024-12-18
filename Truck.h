#ifndef TRUCK_H_INCLUDED
#define TRUCK_H_INCLUDED

<<<<<<< HEAD
#include <iostream>
=======
//Sementara kayak gini dulu, ini belum disambungin ke Rute.h soalnya
#include <iostream>
#include <string>
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
using namespace std;

#define first(L) (L).first
#define next(P) (P)->next
#define info(P) (P)->info

<<<<<<< HEAD
typedef struct elm_Truck* adr_Truck;

struct Truck {
=======
typedef struct t_elm_Truck* adr_Truck;
typedef struct t_elm_Road* adr_Road;

typedef struct {
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
    string name;
    int jumlahRoda;
    double kapasitas;
    double bensin;
    int muatan;
<<<<<<< HEAD
};

struct elm_Truck {
    Truck info;
    adr_Truck next;
};

struct TruckList {
    adr_Truck first;
};
=======
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
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)

void CreateTruck(TruckList &T);
adr_Truck Alokasi(Truck x);
void addTruck(TruckList &T, Truck x);
void AddMuatan(TruckList &T, string name, int muatan);
void deleteMuatan(TruckList &T, string name, int muatan);
<<<<<<< HEAD
void deleteTruck(TruckList &T, string x);
double biayaPengiriman(TruckList L, string name, double biayaPerMuatan, double biayaPerKm, double jarak);

#endif // TRUCK_H_INCLUDED
=======
void deleteTruck(TruckList &T, string name);
double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak);
double KapasitasMaksimal(TruckList &T, string name);
void HanyaLewat(TruckList &T, string name);
bool ApakahMacetatauHambatan(TruckList &T, string gudang, string jalur);
void CatatJalur(TruckList &T, string gudang, string jalur, string truk);
string JalurAlternatif(RoadList &R, string gudang, string jalur);
void PilihRute(TruckList &T, RoadList &R, string gudang, string jalur, string truk, double bensin, double muatan, double jarak);
#endif // TRUK_H_INCLUDED
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
