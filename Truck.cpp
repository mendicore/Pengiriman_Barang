#include "Truck.h"

void CreateTruck(TruckList &T){
    first(T) = NULL;
}

adr_Truck Alokasi(Truck x){
    adr_Truck P = new elm_Truck;
    if (P != NULL)
    {
        info(P) = x;
        next(P) = NULL;
    }
    return P;
}

void addTruck(TruckList &T, Truck x){
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

void HanyaLewat(TruckList &T, string name){
    cout << "Truck " << name << " hanya lewat, tidak ada muatan yang ditambah atau dikurangi." << endl;
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

/*
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
*/

bool ApakahMacetatauHambatan(Graph &G, string gudang, string jalur){
    Addr_Node node = FindNode(G, gudang);
    if (node != NULL)
    {
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P))
        {
            if (P->Info.namaJalan == jalur)
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

/*
void CatatJalur(RoadList &R, string gudang, string jalur, string truk)
{
    for (adr_Road P = first(R); P != NULL; P = next(P))
    {
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P))
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
*/

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
string JalurAlternatif(Graph &G, string gudang, string jalur){
    Addr_Node node = FindNode(G, gudang);

    if (node != NULL){
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P)){
            if (P->Info.namaJalan == jalur){
                for (Addr_Edge Q = FirstEdge(node); Q != NULL; Q = NextEdge(Q)){
                    if (Q->Info.namaJalan != jalur){
                        cout << "Jalur alternatif yang tersedia: " << Q->Info.namaJalan << endl;
                        return Q->Info.namaJalan;
                    }
                }
            }
        }
    }
    cout << "Tidak ada jalur alternatif tersedia." << endl;
    return "";
}
*/

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

string JalurAlternatif(Graph &G, string gudang, string jalur){
    Addr_Node node = FindNode(G, gudang);

    if (node != NULL){
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P)){
            if (P->Info.namaJalan == jalur){
                for (Addr_Edge Q = FirstEdge(node); Q != NULL; Q = NextEdge(Q)){
                    if (Q->Info.namaJalan != jalur){
                        cout << "Jalur alternatif yang tersedia: " << Q->Info.namaJalan << endl;
                        return Q->Info.namaJalan;
                    }
                }
            }
        }
    }
    cout << "Tidak ada jalur alternatif tersedia." << endl;
    return "";
}


void PilihRute(TruckList &T, Graph &G, string gudang, string jalur, string truk, double bensin, double muatan, double jarak){
    if (ApakahMacetatauHambatan(G, gudang, jalur))
    {
        jalur = JalurAlternatif(G, gudang, jalur);
    }
    double bensinDiperlukan = (muatan / 1000.0) * bensin * jarak;
    CatatJalur(G, gudang, jalur, truk);
    cout << "Rute yang dipilih: " << jalur << " dengan bensin yang diperlukan: " << bensinDiperlukan << " liter." << endl;
}
