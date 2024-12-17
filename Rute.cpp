#include "Rute.h"

void CreateGraph(Graph &G)
{
    Start(G) = NULL;
}

void CreatePomBensin(Graph_Pom_Bensin &GPB)
{
    Start(GPB) = Null;
}

Addr_TempList AlokasiTempList(Infotype_TempList x)
{
    Addr_TempList P = new tempListElmt;
    Info(P) = x;
    nextTempList(P) = Null;
    return P;
}

Addr_Node AlokasiNode(Infotype_Node nameNode)
{
    Addr_Node P = new Elmt_Node;
    if (P != NULL)
    {
        Info(P) = nameNode;
        NextNode(P) = Null;
        FirstEdge(P) = Null;
    }
    return P;
}

Addr_Edge AlokasiEdge(Infotype_Edge infoEdge)
{
    Addr_Edge P = new Elmt_Edge;
    if (P != NULL)
    {
        Info(P) = infoEdge;
        NextEdge(P) = Null;
    }
    return P;
}

Addr_Bensin AlokasiBensin(InfoType_Bensin infoBensin)
{
    Addr_Bensin P = new Elmt_Bensin;
    if (P != NULL)
    {
        Info(P) = infoBensin;
        nextBensinList(P) = Null;
    }
    return P;
}

void AddNewNode(Graph &G, Addr_Node P)
{
    if (Start(G) == Null)
    {
        Start(G) = P;
    }
    else
    {
        Addr_Node temp = Start(G);
        while (NextNode(temp) != NULL)
        {
            temp = NextNode(temp);
        }
        NextNode(temp) = P;
    }
}

void deleteNode(Graph &G, Addr_Node P)
{
    while (FirstEdge(P) != Null)
    {
        DeleteFirst_Edge(G, P, FirstEdge(P));
    }

    if (Start(G) == P)
    {
        Start(G) = NextNode(P);
    }
    else
    {
        Addr_Node temp = Start(G);
        while (NextNode(temp) != P)
        {
            temp = NextNode(temp);
        }
        NextNode(temp) = NextNode(P);
    }
    delete P;
    P = NULL;
}

void AddNewPomBensin(Graph_Pom_Bensin &GPB, Addr_Bensin P)
{
    if (Start(GPB) == NULL)
    {
        Start(GPB) = P;
    }
    else
    {
        Addr_Bensin temp = Start(GPB);
        while (nextBensinList(temp) != NULL)
        {
            temp = nextBensinList(temp);
        }
        nextBensinList(temp) = P;
    }
}

void deletePomBensin(Graph_Pom_Bensin &GPB, Addr_Bensin P)
{
    while (FirstBensin(P) != NULL)
    {
        DeleteFirst_Bensin(GPB, P, FirstBensin(P));
    }

    if (Start(GPB) == P)
    {
        Start(GPB) = nextBensinList(P);
    }
    else
    {
        Addr_Bensin temp = Start(GPB);
        while (nextBensinList(temp) != P)
        {
            temp = nextBensinList(temp);
        }
        nextBensinList(temp) = nextBensinList(P);
    }
    delete P;
    P = NULL;
}

Addr_Node FindNode(Graph G, string data)
{
    Addr_Node P = Start(G);
    while (P != NULL)
    {
        if (Info(P).nama == data)
        {
            return P;
        }
        P = NextNode(P);
    }
    return Null;
}

Addr_Bensin FindBensin(Graph_Pom_Bensin GPB, string data)
{
    for(Addr_Bensin P = Start(GPB); P != Null; P = nextBensinList(P))
    {
        if(Info(P).nama == data)
        {
            return P;
        }
    }
    return Null;
}

void InsertLast_TempList(TempList& L, Addr_TempList P)
{
    if(L.pertama == Null)
    {
        L.pertama = P;
    }
    else
    {
        Addr_TempList last = L.pertama;
        while(nextTempList(last) != Null)
        {
            last = nextTempList(last);
        }
        nextTempList(last) = P;
    }
}

void InsertLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge) {
    if (FirstEdge(PNode) == NULL)
    {
        FirstEdge(PNode) = PEdge;
    }
    else
    {
        Addr_Edge temp = FirstEdge(PNode);
        while (NextEdge(temp) != NULL)
        {
            temp = NextEdge(temp);
        }
        NextEdge(temp) = PEdge;
    }
}

void Connecting(Graph &G, string node1, string node2, string jalan, double jarak, int waktu)
{
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, node2);
    if (P1 != NULL && P2 != NULL)
    {
        Jalan JalanBaru1 = {node2, jalan, jarak, waktu};
        Addr_Edge E1 = AlokasiEdge(JalanBaru1);
        InsertLast_Edge(G, P1, E1);
        Jalan JalanBaru2 = {node1, jalan, jarak, waktu};
        Addr_Edge E2 = AlokasiEdge(JalanBaru2);
        InsertLast_Edge(G, P2, E2);
    }
}

void Connecting_Gudang_Bensin(Graph &G, string node1, string tempatBensin, string jalan, double jarak, int waktu)
{
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, tempatBensin);
    if (P1 != NULL && P2 != NULL)
    {
        Jalan JalanBaru1 = {tempatBensin, jalan, jarak, waktu};
        Addr_Edge E1 = AlokasiEdge(JalanBaru1);
        InsertLast_Edge(G, P1, E1);
        Jalan JalanBaru2 = {node1, jalan, jarak, waktu};
        Addr_Edge E2 = AlokasiEdge(JalanBaru2);
        InsertLast_Edge(G, P2, E2);
    }
}

void Connecting_Bensin_Gudang(Graph &G, string tempatBensin, string node2, string jalan, double jarak, int waktu)
{
    Addr_Node P1 = FindNode(G, tempatBensin);
    Addr_Node P2 = FindNode(G, node2);
    if (P1 != NULL && P2 != NULL)
    {
        Jalan JalanBaru1 = {node2, jalan, jarak, waktu};
        Addr_Edge E1 = AlokasiEdge(JalanBaru1);
        InsertLast_Edge(G, P1, E1);
        Jalan JalanBaru2 = {tempatBensin, jalan, jarak, waktu};
        Addr_Edge E2 = AlokasiEdge(JalanBaru2);
        InsertLast_Edge(G, P2, E2);
    }
}

Addr_Edge FindEdge(Graph &G, Addr_Node PNode, string data) {
    Addr_Edge P = FirstEdge(PNode);
    while (P != NULL) {
        Addr_Node temp = Start(G);
        while (temp != NULL) {
            if (Info(temp).nama == data) {
                return P;
            }
            temp = NextNode(temp);
        }
        P = NextEdge(P);
    }
    return NULL;
}

void DeleteFirst_Bensin(Graph_Pom_Bensin &G, Addr_Bensin PBensin, Addr_Edge &P)
{
    if (FirstBensin(PBensin) != NULL)
    {
        P = FirstBensin(PBensin);
        FirstBensin(PBensin) = NextEdge(FirstBensin(PBensin));
        delete P;
    }
}

void DeleteFirst_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P) {
    if (FirstEdge(PNode) != NULL) {
        P = FirstEdge(PNode);
        FirstEdge(PNode) = NextEdge(FirstEdge(PNode));
        delete P;
    }
}

void DeleteLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P) {
    if (FirstEdge(PNode) != NULL) {
        Addr_Edge temp = FirstEdge(PNode);
        if (NextEdge(temp) == NULL) {
            P = temp;
            FirstEdge(PNode = NULL);
            delete P;
        } else {
            while (NextEdge(NextEdge(temp)) != NULL) {
                temp = NextEdge(temp);
            }
            P = NextEdge(temp);
            NextEdge(temp) = NULL;
            delete P;
        }
    }
}

void DeleteAfter_Edge(Graph &G, Addr_Node PNode, Addr_Edge Prec, Addr_Edge &P) {
    Addr_Edge temp = FirstEdge(PNode);
    while (temp != NULL) {
        if (temp == Prec) {
            P = NextEdge(temp);
            if (P != NULL) {
               NextEdge(temp) = NextEdge(P);
                delete P;
            }
            break;
        }
        temp = NextEdge(temp);
    }
}

void Delete_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge) {
   Addr_Edge Eout,prec;

	if (PEdge == FirstEdge(PNode)) {
		DeleteFirst_Edge(G,PNode,Eout);
	}
	else if (NextEdge(PEdge) == NULL ){
		DeleteLast_Edge(G,PNode,Eout);
	}
	else {
		prec = FirstEdge(PNode);
		while (NextEdge(prec)!= PEdge) {
			prec=NextEdge(prec);
		}
		DeleteAfter_Edge(G,PNode,prec,Eout);
	}
}

void Disconnecting(Graph &G, string node1, string node2) {
    Addr_Node PNode1 = FindNode(G, node1);
    Addr_Node PNode2 = FindNode(G, node2);

    if (PNode1 != NULL && PNode2 != NULL) {
        Addr_Edge PEdge1 = FindEdge(G, PNode1, node2);
        Addr_Edge PEdge2 = FindEdge(G, PNode2, node1);

        if (PEdge1 != NULL) {
            Delete_Edge(G, PNode1, PEdge1);
        }
        if (PEdge2 != NULL) {
            Delete_Edge(G, PNode2, PEdge2);
        }
    }
}

void Disconnecting_Gudang_Bensin(Graph &G, string node1, string tempatBensin)
{
    Addr_Node PNode1 = FindNode(G, node1);
    Addr_Node PNode2 = FindNode(G, tempatBensin);

    if (PNode1 != NULL && PNode2 != NULL) {
        Addr_Edge PEdge1 = FindEdge(G, PNode1, tempatBensin);
        Addr_Edge PEdge2 = FindEdge(G, PNode2, node1);

        if (PEdge1 != NULL) {
            Delete_Edge(G, PNode1, PEdge1);
        }
        if (PEdge2 != NULL) {
            Delete_Edge(G, PNode2, PEdge2);
        }
    }
}

void Disconnecting_Bensin_Gudang(Graph &G, string tempatBensin, string node2)
{
    Addr_Node PNode1 = FindNode(G, tempatBensin);
    Addr_Node PNode2 = FindNode(G, node2);

    if (PNode1 != NULL && PNode2 != NULL) {
        Addr_Edge PEdge1 = FindEdge(G, PNode1, node2);
        Addr_Edge PEdge2 = FindEdge(G, PNode2, tempatBensin);

        if (PEdge1 != NULL) {
            Delete_Edge(G, PNode1, PEdge1);
        }
        if (PEdge2 != NULL) {
            Delete_Edge(G, PNode2, PEdge2);
        }
    }
}

// Sekalian kalau butuh
void AlJikstra(Graph G, Infotype_Node Mulai, Infotype_Node selesai, TempList T)
{
    if(Mulai.nama == selesai.nama)
    {
        cout << "Gudang " << Mulai.nama << " adalah gudang terakhir" << endl;
        return;
    }

    Addr_Node X = FindNode(G, Mulai.nama);
    Addr_Edge D = findShortestRute(G, X, T);
    if(D != Null)
    {
        InsertLast_TempList(T, AlokasiTempList(Info(D).bangunan.nama));
        cout << "info bangunan" << Info(D).bangunan.nama << endl;
        AlJikstra(G, D->Info.bangunan, selesai, T);
    }
}

Addr_Edge findShortestRute(Graph G, Addr_Node AG, TempList AT)
{
    Addr_Edge E = FirstEdge(AG);
    Addr_Edge terpendek = E;
    while(E != Null)
    {
        if(Info(E).waktu < Info(terpendek).waktu && !telahDikunjungi(AT, E->Info.bangunan.nama))
        {
            terpendek = E;
        }
        E = NextEdge(E);
    }
    return terpendek;
}

bool telahDikunjungi(TempList AT, string Gudang)
{
    for(Addr_TempList R = AT.pertama; R != Null; R = nextTempList(R))
    {
        if(Info(R) == Gudang)
        {
            return true;
        }
    }
    return false;
}

void ShowAllGudangJalur(Graph &G) {
    cout<<"Graph G: " << endl;
	if (Start(G) != Null)
    {
		for(Addr_Node N = Start(G); N != Null; N = NextNode(N))
        {
			cout<<"<<==========================>>"<< endl;
			cout<<"Gudang "<< Info(N).nama << " berlokasi di " << Info(N).lokasi <<  " dengan kapasitas "<< Info(N).kapasitas << " dan jumlah " << Info(N).jumlah
			<< " memiliki tetangga berupa: "<< endl;
			cout<<"=============================="<< endl;
			for(Addr_Edge E = N->FirstEdge; E != Null; E = E->NextEdge)
			{
				cout << "Nama gudang: " << Info(E).bangunan.nama << endl;
				cout << "Nama jalan: " << Info(E).namaJalan << endl;
				cout << "Jarak antar-Gudang: " << Info(E).jarak << endl;
				cout << "Durasi jalur : " << E->Info.waktu << endl;
			}
			cout << "<<==========================>>"<< endl;
			cout << endl;
		}
	}
	else
    {
		cout<< "Graf Kosong" << endl;
	}
}

void ShowAllPomBensin(Graph_Pom_Bensin &GPB)
{
    if(Start(GPB) != Null)
    {
        for(Addr_Bensin B = Start(GPB); B != Null; B = nextBensinList(B))
        {
            cout << "Nama pom bensin: " << Info(B).nama << endl;
            cout << "Lokasi pom bensin: " << Info(B).lokasi << endl;
            cout << "Kapasitas tangki pom bensin: " << Info(B).kapasitas << endl;
            cout << "Jumlah dispenser bensin : " << Info(B).jumlah << endl;
        }
    }
    else
    {
		cout<< "Tidak ada pom bensin" << endl;
	}
}