#include "Truck.h"
#include <iostream>

using namespace std;

void CreateTruck(TruckList &T) {
    first(T) = NULL;
}

adr_Truck Alokasi(Truck x) {
    adr_Truck P = new elm_Truck; 
    if (P != NULL) {
        info(P) = x;     
        next(P) = NULL; 
    }
    return P;
}

void addTruck(TruckList &T, Truck x) {
    adr_Truck P = Alokasi(x);
    if (P != NULL) {
        next(P) = T.first; 
        first(T) = P;
    }
}

void AddMuatan(TruckList &T, string name, int muatan) {
    adr_Truck P = T.first;
    while (P != NULL) {
        if (info(P).name == name) {
            info(P).muatan += muatan;
            cout << "Muatan " << muatan << " telah ditambahkan pada truck " << name << "." << endl;
            return;
        }
        P = next(P);
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

void deleteMuatan(TruckList &T, string name, int muatan) {
    adr_Truck P = T.first;
    while (P != NULL) {
        if (info(P).name == name) {
            if (info(P).muatan >= muatan) {
                info(P).muatan -= muatan;
                cout << "Muatan " << muatan << " telah dihapus dari truck " << name << "." << endl;
            } else {
                cout << "Muatan tidak cukup untuk dihapus!" << endl;
            }
            return;
        }
        P = next(P);
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

void deleteTruck(TruckList &T, string name) {
    adr_Truck P = first(T), prev = NULL;
    
    if (P != NULL && P->info.name == name) {
        first(T) = next(P); 
        delete P;
        cout << "Truck dengan nama " << name << " telah dihapus." << endl;
        return;
    }

    while (P != NULL && info(P).name != name) {
        prev = P;
        P = next(P);
    }

    if (P == NULL) {
        cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
        return;
    }

    next(prev) = next(P);
    delete P;
    cout << "Truck dengan nama " << name << " telah dihapus." << endl;
}

double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak) {
    adr_Truck P = first(T);
    while (P != NULL) {
        if (info(P).name == name) {
            double totalBiaya = (info(P).muatan * biayaPerMuatan) + (jarak * biayaPerKm);
            return totalBiaya;
        }
        P = next(P);
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

