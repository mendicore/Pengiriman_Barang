#include "Rute.h"

void CreateGraph(Graph &G)
{
    Start(G) = NULL;
}

Addr_TempList AlokasiTempList(Infotype_TempList x)
{
    Addr_TempList P = new tempListElmt;
    P->info = x;
    P->nextTempList = Null;
    return P;
}

Addr_Node AlokasiNode(string nameNode)
{
    Addr_Node P = new Elmt_Node;
    if (P != NULL)
    {
        Info(P) = nameNode;
        NextNode(P) = NULL;
        FirstEdge(P) = NULL;
    }
    return P;
}

Addr_Edge AlokasiEdge(Infotype_Edge infoEdge)
{
    Addr_Edge P = new Elmt_Edge;
    if (P != NULL)
    {
        Info(P) = infoEdge;
        NextEdge(P) = NULL;
    }
    return P;
}

void AddNewNode(Graph &G, Addr_Node P)
{
    if (Start(G) == NULL)
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

void deleteNode(Graph &G, Addr_Node P) {
    while (FirstEdge(P) != NULL)
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



Addr_Node FindNode(Graph G, string data)
{
    Addr_Node P = Start(G);
    while (P != NULL)
    {
        if (Info(P) == data)
        {
            return P;
        }
        P = NextNode(P);
    }
    return NULL;
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
        while(last->nextTempList != Null)
        {
            last = last->nextTempList;
        }
        last->nextTempList = P;
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

Addr_Edge FindEdge(Graph &G, Addr_Node PNode, string data) {
    Addr_Edge P = FirstEdge(PNode);
    while (P != NULL) {
        Addr_Node temp = G.Start;
        while (temp != NULL) {
            if (Info(temp) == data) {
                return P;
            }
            temp = NextNode(temp);
        }
        P = NextEdge(P);
    }
    return NULL;
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

// Sekalian kalau butuh
void AlJikstra(Graph G, Infotype_Node Mulai, Infotype_Node selesai, TempList T)
{
    if(Mulai == selesai)
    {
        cout << "Gudang " << Mulai << " adalah gudang terakhir" << endl;
        return;
    }

    Addr_Node X = FindNode(G, Mulai);
    Addr_Edge D = findShortestRute(G, X, T);
    if(D != Null)
    {
        InsertLast_TempList(T, AlokasiTempList(D->Info.bangunan));
        cout << "info bangunan" << D->Info.bangunan << endl;
        AlJikstra(G, D->Info.bangunan, selesai, T);
    }
}

Addr_Edge findShortestRute(Graph G, Addr_Node AG, TempList AT)
{
    Addr_Edge E = AG->FirstEdge;
    Addr_Edge terpendek = E;
    while(E != Null)
    {
        if(E->Info.waktu < terpendek->Info.waktu && !telahDikunjungi(AT, E->Info.bangunan))
        {
            terpendek = E;
        }
        E = E->NextEdge;
    }
    return terpendek;
}

bool telahDikunjungi(TempList AT, string Gudang)
{
    for(Addr_TempList R = AT.pertama; R != Null; R = R->nextTempList)
    {
        if(R->info == Gudang)
        {
            return true;
        }
    }
    return false;
}

void ShowAll(Graph &G) {
    cout<<"Graph G: " << endl;
	if (G.Start != Null)
    {
		for(Addr_Node N = G.Start; N != Null; N = N->NextNode)
        {
			cout<<"<<==========================>>"<< endl;
			cout<<"Kota "<< N->Info <<" tetangganya: "<< endl;
			cout<<"=============================="<< endl;
			for(Addr_Edge E = N->FirstEdge; E != Null; E = E->NextEdge)
			{
				cout << "Nama gudang: " << E->Info.bangunan << endl;
				cout << "Nama jalan: " << E->Info.namaJalan << endl;
				cout << "Jarak antar-Gudang: " << E->Info.jarak << endl;
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