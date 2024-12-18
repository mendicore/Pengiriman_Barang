#include "Truck.h"
<<<<<<< HEAD
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
=======

void CreateTruck(TruckList &T)
{
    first(T) = NULL;
}

adr_Truck Alokasi(Truck x)
{
    adr_Truck P = new elm_Truck;
    if (P != NULL)
    {
        info(P) = x;
        next(P) = NULL;
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
    }
    return P;
}

<<<<<<< HEAD
void addTruck(TruckList &T, Truck x) {
    adr_Truck P = Alokasi(x);
    if (P != NULL) {
        next(P) = T.first; 
=======
void addTruck(TruckList &T, Truck x)
{
    adr_Truck P = Alokasi(x);
    if (P != NULL)
    {
        next(P) = first(T);
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
        first(T) = P;
    }
}

<<<<<<< HEAD
void AddMuatan(TruckList &T, string name, int muatan) {
    adr_Truck P = T.first;
    while (P != NULL) {
        if (info(P).name == name) {
=======
void AddMuatan(TruckList &T, string name, int muatan)
{
    for(adr_Truck P = first(T); P != NULL; P = next(P))
    {
        if (info(P).name == name)
        {
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
            info(P).muatan += muatan;
            cout << "Muatan " << muatan << " telah ditambahkan pada truck " << name << "." << endl;
            return;
        }
<<<<<<< HEAD
        P = next(P);
=======
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

<<<<<<< HEAD
void deleteMuatan(TruckList &T, string name, int muatan) {
    adr_Truck P = T.first;
    while (P != NULL) {
        if (info(P).name == name) {
            if (info(P).muatan >= muatan) {
                info(P).muatan -= muatan;
                cout << "Muatan " << muatan << " telah dihapus dari truck " << name << "." << endl;
            } else {
=======
void deleteMuatan(TruckList &T, string name, int muatan)
{
    for(adr_Truck P = first(T); P != NULL; P = next(P))
    {
        if (info(P).name == name)
        {
            if (info(P).muatan >= muatan)
            {
                info(P).muatan -= muatan;
                cout << "Muatan " << muatan << " telah dihapus dari truck " << name << "." << endl;
            }
            else
            {
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
                cout << "Muatan tidak cukup untuk dihapus!" << endl;
            }
            return;
        }
<<<<<<< HEAD
        P = next(P);
=======
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

<<<<<<< HEAD
void deleteTruck(TruckList &T, string name) {
    adr_Truck P = first(T), prev = NULL;
    
    if (P != NULL && P->info.name == name) {
        first(T) = next(P); 
=======
void deleteTruck(TruckList &T, string name)
{
    adr_Truck P = first(T), prev = NULL;

    if (P != NULL && P->info.name == name)
    {
        first(T) = next(P);
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
        delete P;
        cout << "Truck dengan nama " << name << " telah dihapus." << endl;
        return;
    }

<<<<<<< HEAD
    while (P != NULL && info(P).name != name) {
=======
    while (P != NULL && info(P).name != name)
    {
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
        prev = P;
        P = next(P);
    }

<<<<<<< HEAD
    if (P == NULL) {
=======
    if (P == NULL)
    {
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
        cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
        return;
    }

    next(prev) = next(P);
    delete P;
    cout << "Truck dengan nama " << name << " telah dihapus." << endl;
}

<<<<<<< HEAD
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

=======
double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak)
{
    for(adr_Truck P = first(T); P != NULL; P = next(P))
    {
        if (info(P).name == name)
        {
            double totalBiaya = (info(P).muatan * biayaPerMuatan) + (jarak * biayaPerKm);
            return totalBiaya;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
    return 0.0;
}

double KapasitasMaksimal(TruckList &T, string name)
{
    for (adr_Truck P = first(T); P != NULL; P = next(P))
    {
        if (info(P).name == name)
        {
            return info(P).kapasitas;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
    return 0.0;
}

void HanyaLewat(TruckList &T, string name)
{
    cout << "Truck " << name << " hanya lewat, tidak ada muatan yang ditambah atau dikurangi." << endl;
}

double BensinperKapasitas(TruckList &T, string name, double bensin, int muatan, double jarak)
{
    for (adr_Truck P = first(T); P != NULL; P = next(P))
    {
        if (info(P).name == name)
        {
            double bensinDiperlukan = (muatan / info(P).kapasitas) * bensin * jarak;
            return bensinDiperlukan;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
    return 0.0;
}

bool ApakahMacetatauHambatan(RoadList &R, string gudang, string jalur)
{
     for (adr_Road P = first(R); P != NULL; P = next(P))
     {
         if (info(P).name == jalur)
         {
             int count = 0;
             for (adr_Truck Q = info(P).trucks; Q != NULL; Q = next(Q))
             {
                 count++;
             }
             if (count > 1)
             {
                 cout << "Jalur " << jalur << " macet karena ada lebih dari 1 truk." << endl;
                 return true;
             }
         }
     }
     return false;
}

void CatatJalur(RoadList &R, string gudang, string jalur, string truk)
{
    for (adr_Road P = first(R); P != NULL; P = next(P))
    {
        if (info(P).name == jalur)
        {
            adr_Truck newTruck = new elm_Truck;
            newTruck->info.name = truk;
            newTruck->next = info(P).trucks;
            info(P).trucks = newTruck;
            cout << "Jalur dari " << gudang << " melalui " << jalur << " dengan truk " << truk << " telah dicatat." << endl;
            return;
        }
    }
    adr_Road newRoad = new elm_Road;
    info(newRoad).name = jalur;
    info(newRoad).trucks = new elm_Truck;
    info(newRoad).trucks->info.name = truk;
    info(newRoad).trucks->next = NULL;
    next(newRoad) = first(R);
    first(R) = newRoad;
    cout << "Jalur dari " << gudang << " melalui " << jalur << " dengan truk " << truk << " telah dicatat." << endl;
}

string JalurAlternatif(RoadList &R, string gudang, string jalur)
{
    for (adr_Road P = first(R); P != NULL; P = next(P))
    {
        if (info(P).name != jalur)
        {
            int count = 0;
            for (adr_Truck Q = info(P).trucks; Q != NULL; Q = next(Q))
            {
                count++;
            }
            if (count <= 1)
            {
                return info(P).name;
            }
        }
    }
    return "Tidak ada jalur alternatif yang tersedia";
}

void PilihRute(TruckList &T, RoadList &R, string gudang, string jalur, string truk, double bensin, double muatan, double jarak)
{
    if (ApakahMacetatauHambatan(R, gudang, jalur))
    {
        jalur = JalurAlternatif(R, gudang, jalur);
    }
    double bensinDiperlukan = BensinperKapasitas(T, truk, bensin, muatan, jarak);
    CatatJalur(R, gudang, jalur, truk);
    cout << "Rute yang dipilih: " << jalur << " dengan bensin yang diperlukan: " << bensinDiperlukan << " liter." << endl;
}
>>>>>>> 4bb2cd9 (Tinggal mikirin cara sambungin 'Truck.h' dengan 'rute.h' doang sama benerin main program, baru beres)
