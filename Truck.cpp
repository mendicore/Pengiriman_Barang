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

void addTruck(TruckList &T, adr_Truck x){
    if (x != NULL)
    {
        next(x) = first(T);
        first(T) = x;
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
    for (adr_Truck P = first(T); P != nullptr; P = next(P))
    {
        if (info(P).name == name)
        {
            return info(P).kapasitas;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
    return 0.0;
}

double BensinperKapasitas(TruckList &T, string name, double bensin, double muatan, double jarak){
    for (adr_Truck P = first(T); P != nullptr; P = next(P))
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

void isiBensin(TruckList &T, Graph &G, string name, infotype_Truck truk, double bensin, double muatan, double jarak) {
    Graph_Pom_Bensin A;
    CreatePomBensin(A);
    Addr_Bensin P = FindBensin(A, name);

    double maksBensin = KapasitasMaksimal(T, truk.name);

    for (adr_Truck R = T.first; R != nullptr; R = R->next) {
        if (R->info.name == truk.name && P->info.nama == name) {
            if (bensin < maksBensin) {
                double neededBensin = maksBensin - bensin;
                bensin += neededBensin;
                cout << "Truk " << name << " telah diisi " << neededBensin << " liter gas." << endl;
                return;
            }
            break;
        }
    }
    cout << "Truck dengan nama " << name << " tidak ditemukan!" << endl;
}

void HanyaLewat(TruckList &T, string name){
    cout << "Truck " << name << " hanya lewat, tidak ada muatan yang ditambah atau dikurangi." << endl;
}

bool ApakahMacetatauHambatan(Graph &G, const Infotype_Node &gudang, const Infotype_Edge &jalur){
    Addr_Node node = FindNode(G, gudang.nama);
    if (node != NULL)
    {
        for (Addr_Edge P = FirstEdge(node); P != NULL; P = NextEdge(P))
        {
            if (info(P).namaJalan == jalur.namaJalan)
            {
                int count = 0;
                for (Addr_Node Q = Start(G); Q != NULL; Q = NextNode(Q))
                {
                    count++;
                }
                if (count > 1)
                {
                    cout << "Jalur " << jalur.namaJalan << " macet karena ada lebih dari 1 truk." << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void CatatJalur(Graph &G, const Infotype_Node &gudangA, const Infotype_Node &GudangB, const Infotype_Edge &jalur, const infotype_Truck &truk) {
    Addr_Node nodeA = FindNode(G, gudangA.nama);
    Addr_Node nodeB = FindNode(G, GudangB.nama);
    if (nodeA != NULL && nodeB != NULL && ! info(nodeA).nama.empty() && ! info(nodeB).nama.empty()) {
        Addr_Edge newEdge1 = AlokasiEdge({jalur.namaJalan, 0, 0});
        if (newEdge1 != NULL) {
            NextEdge(newEdge1) = FirstEdge(nodeA);
            FirstEdge(nodeA) = newEdge1;
            cout << "Jalur dari " << gudangA.nama << " melalui " << jalur.namaJalan << " ke " << GudangB.nama << " dengan truk " << truk.name << " telah dicatat." << endl;
        } else {
            cout << "Gagal mengalokasikan edge baru." << endl;
        }
    } else {
        cout << "Gudang pengirim atau penerima tidak ditemukan!" << endl;
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

void Pengiriman(TruckList &T, Graph &G, const Infotype_Node &gudangA, const Infotype_Node &gudangB, const Infotype_Edge &jalur, const infotype_Truck &truk, double bensin, double muatan, double jarak){
    if (ApakahMacetatauHambatan(G, gudangA, jalur) || ApakahMacetatauHambatan(G, gudangB, jalur) || jalur.macet == true)
    {
        TempList jalurAlternatif;
        CreateTempList(jalurAlternatif);
        jalurAlternatifDFS(G, gudangA, gudangB, jalur);
        AlJikstra(G, gudangA, gudangB, jalurAlternatif);

    }
    double bensinDiperlukan = BensinperKapasitas(T, truk.name, bensin, muatan, jarak);
    if(BensinperKapasitas(T, truk.name, bensin, muatan, jarak) < bensinDiperlukan)
    {
        InfoType_Bensin R;
        cout << "Masukkan lokasi pom bensin: ";
        getline(cin, R.lokasi);
        isiBensin(T, G, R.lokasi, truk, bensin, muatan, jarak);
    }
    cout << "Rute yang dipilih: " << jalur.namaJalan << " dengan bensin yang diperlukan: " << bensinDiperlukan << " liter." << endl;
}