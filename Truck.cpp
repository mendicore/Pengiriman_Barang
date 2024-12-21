#include "Truck.h"

void CreateTruck(TruckList &T){
    first(T) = NULL;
}

adr_Truck Alokasi(infotype_Truck x) {
    adr_Truck P = new elm_Truck;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

void addTruck(TruckList &T, infotype_Truck x){
    adr_Truck P = Alokasi(x);
    if (P != NULL)
    {
        next(P) = first(T);
        first(T) = P;
    }
}

void AddMuatan(TruckList &T, string name, int muatan)
{
    for(adr_Truck P = first(T); P != NULL; P = next(P))
    {
        if (info(P).name == name)
        {
            info(P).muatan += muatan;
            cout << "Muatan " << muatan << " telah ditambahkan pada truck " << name << "." << endl;
            return;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

void deleteMuatan(TruckList &T, string name, int muatan){
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
                cout << "Muatan tidak cukup untuk dihapus!" << endl;
            }
            return;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

void deleteTruck(TruckList &T, string name){
    adr_Truck P = first(T), prev = NULL;

    if (P != NULL && P->info.name == name)
    {
        first(T) = next(P);
        delete P;
        cout << "Truck dengan nama " << name << " telah dihapus." << endl;
        return;
    }

    while (P != NULL && info(P).name != name)
    {
        prev = P;
        P = next(P);
    }

    if (P == NULL)
    {
        cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
        return;
    }

    next(prev) = next(P);
    delete P;
    cout << "Truck dengan nama " << name << " telah dihapus." << endl;
}

adr_Truck findTruck(TruckList &T, infotype_Truck x){
    adr_Truck P = first(T);
    while (P != NULL)
    {
        // Compare the 'name' member of the Truck with x.name
        if (info(P).name == x.name)
        {
            return P;
        }
        P = next(P);
    }
    return Null;
}


void showTrucks(TruckList &T) {
    adr_Truck P = first(T);
    cout << "<<==================================================================>>" << endl;
    while (P != NULL) {
        cout <<"[Nama] " << P->info.name << "\t[Roda} " << P->info.jumlahRoda << "\t[Max Barang] " <<  P->info.kapasitas <<
        "\t\t[Max Bensin] " << P->info.bensin << endl;
        P = P->next;
    }
    cout << "<<==================================================================>>" << endl << endl;

}

double biayaPengiriman(TruckList &T, string name, double biayaPerMuatan, double biayaPerKm, double jarak){
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

double KapasitasMaksimal(TruckList &T, string name){
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

double BensinperKapasitas(TruckList &T, string name, double bensin, int muatan, double jarak){
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

void HanyaLewat(TruckList &T, string name){
    cout << "Truck " << name << " hanya lewat, tidak ada muatan yang ditambah atau dikurangi." << endl;
}

bool ApakahMacetatauHambatan(Graph &G, string gudang, string jalur){
    Addr_Node node = FindNode(G, gudang);
    if (node != NULL)
    {
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P))
        {
            if (P->info.namaJalan == jalur)
            {
                int count = 0;
                for (Addr_Node Q = Start(G); Q != NULL; Q = NextNode(Q))
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
    }
    return false;
}

void CatatJalur(Graph &G, string gudang, string jalur, string truk){
    Addr_Node node = FindNode(G, gudang);
    if (node != NULL)
    {
        Addr_Edge newEdge = AlokasiEdge({jalur, 0, 0});
        newEdge->NextEdge = FirstEdge(node);
        FirstEdge(node) = newEdge;
        cout << "Jalur dari " << gudang << " melalui " << jalur << " dengan truk " << truk << " telah dicatat." << endl;
    }
}

/*
 Implementasi jalur alternatif
 Kemungkinan: cari jalur yang bukan sama dengan jalur yang sedang dikirim
             : jika ditemukan, tampilkan dan return jalur tersebut
            : jika tidak ditemukan, tampilkan pesan "Tidak ada jalur alternatif tersedia"

string JalurAlternatif(Graph &G, string gudang, string jalur){
    Addr_Node node = FindNode(G, gudang);

    if (node != NULL){
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P)){
            if (P->info.namaJalan == jalur){
                for (Addr_Edge Q = FirstEdge(node); Q != NULL; Q = NextEdge(Q)){
                    if (Q->info.namaJalan != jalur){
                        cout << "Jalur alternatif yang tersedia: " << Q->info.namaJalan << endl;
                        return Q->info.namaJalan;
                    }
                }
            }
        }
    }
    cout << "Tidak ada jalur alternatif tersedia." << endl;
    return "";
}
*/

// masih bingung implementasinya kayak gimana
void Pengiriman(TruckList &T, Graph &G, string gudang, string jalur, string truk, double bensin, double muatan, double jarak){
    if (ApakahMacetatauHambatan(G, gudang, jalur))
    {
        jalur = JalurAlternatif(G, gudang, jalur);
    }
    double bensinDiperlukan = (muatan / 1000.0) * bensin * jarak;
    CatatJalur(G, gudang, jalur, truk);
    cout << "Rute yang dipilih: " << jalur << " dengan bensin yang diperlukan: " << bensinDiperlukan << " liter." << endl;
}
