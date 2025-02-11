#include "Rute.h"

void CreateGraph(Graph &G)
{
    Start(G) = Null;
}

void CreatePomBensin(Graph_Pom_Bensin &GPB)
{
    Start(GPB) = Null;
}

void CreateTempList(TempList &L)
{
    L.pertama = Null;
}

Addr_TempList AlokasiTempList(Infotype_TempList x)
{
    Addr_TempList P = new Elmt_TempList;
    info(P) = x;
    nextTempList(P) = Null;
    return P;
}

Addr_Node AlokasiNode(Infotype_Node nameNode)
{
    Addr_Node P = new Elmt_Node;
    if (P != Null)
    {
        info(P) = nameNode;
        NextNode(P) = Null;
        FirstEdge(P) = Null;
    }
    return P;
}

Addr_Edge AlokasiEdge(Infotype_Edge info)
{
    Addr_Edge newEdge = new Elmt_Edge;
    if (newEdge != Null)
    {
        info(newEdge) = info;
        NextEdge(newEdge) = NULL;
    }
    return newEdge;
}

Addr_Bensin AlokasiBensin(InfoType_Bensin infoBensin)
{

    Addr_Bensin P = new Elmt_Bensin;
    if (P != Null)
    {
        info(P) = infoBensin;
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
        while (NextNode(temp) != Null)
        {
            temp = NextNode(temp);
        }
        NextNode(temp) = P;
    }
}

void deleteNode(Graph &G, Addr_Node &P)
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
    P = Null;
}

void AddNewPomBensin(Graph_Pom_Bensin &GPB, Addr_Bensin P)
{
    if (Start(GPB) == Null)
    {
        Start(GPB) = P;
    }
    else
    {
        Addr_Bensin temp = Start(GPB);
        while (nextBensinList(temp) != Null)
        {
            temp = nextBensinList(temp);
        }
        nextBensinList(temp) = P;
    }
}

void deletePomBensin(Graph_Pom_Bensin &GPB, Addr_Bensin &P)
{
    while (FirstBensin(P) != Null)
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
    P = Null;
}

Addr_Node FindNode(Graph G, string data)
{
    for(Addr_Node P = Start(G); P != Null; P = NextNode(P))
    {
        if (info(P).nama == data)
        {
            return P;
        }
    }
    return Null;
}

Addr_Bensin FindBensin(Graph_Pom_Bensin GPB, string data)
{
    for(Addr_Bensin P = Start(GPB); P != Null; P = nextBensinList(P))
    {
        if(info(P).nama == data)
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

void InsertLast_Edge(Graph &G, Addr_Node node, Addr_Edge newEdge)
{
    if (FirstEdge(node) == Null)
    {
        FirstEdge(node) = newEdge;
    }
    else
    {
        Addr_Edge temp = FirstEdge(node);
        while (NextEdge(temp) != Null)
        {
            temp = NextEdge(temp);
        }
        NextEdge(temp) = newEdge;
    }
}

void InsertLast_Edge_Bensin(Graph &G, Addr_Node nodeGudang, Addr_Bensin nodePomBensin, Addr_Edge newEdge)
{
    if (nodeGudang != Null)
    {
        if (FirstEdge(nodeGudang) == Null)
        {
            FirstEdge(nodeGudang) = newEdge;
        }
        else
        {
            Addr_Edge temp = FirstEdge(nodeGudang);
            while (NextEdge(temp) != Null)
            {
                temp = NextEdge(temp);
            }
            NextEdge(temp) = newEdge;
        }
    }
    else if (nodePomBensin != Null)
    {
        if (FirstBensin(nodePomBensin) == Null)
        {
            FirstBensin(nodePomBensin) = newEdge;
        }
        else
        {
            Addr_Edge temp = FirstBensin(nodePomBensin);
            while (NextEdge(temp) != Null)
            {
                temp = NextEdge(temp);
            }
            NextEdge(temp) = newEdge;
        }
    }
}

void Connecting_TakBerarah(Graph &G, string node1, string node2, string jalan, double jarak, int waktu, string macet)
{
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, node2);

    if (P1 != Null && P2 != Null)
    {
        if (jalan != "" && jarak > 0 && waktu > 0 && macet != "")
        {
            Jalan JalanBaru1 = {info(P2), {}, jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E1 = FindEdge_Hubung(G, P1, node1, AlokasiEdge(JalanBaru1));
            InsertLast_Edge(G, P2, E1);

            Jalan JalanBaru2 = {info(P1), {}, jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E2 = FindEdge_Hubung(G, P2, node2, AlokasiEdge(JalanBaru2));
            InsertLast_Edge(G, P1, E2);
        }
        else
        {
            cout << "Data jalan tidak valid!" << endl;
        }
    }
    else
    {
        cout << "Salah satu atau kedua node tidak ditemukan!" << endl;
    }
}

void Connecting_Berarah(Graph &G, string node1, string node2, string jalan, double jarak, int waktu, string macet)
{
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, node2);

    if (P1 != Null && P2 != Null)
    {
        if (jalan != "" && jarak > 0 && waktu > 0 && macet != "")
        {
            Jalan JalanBaru1 = {info(P2), {}, jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E1 = FindEdge_Hubung(G, P1, node1, AlokasiEdge(JalanBaru1));
            InsertLast_Edge(G, P2, E1);
        }
        else
        {
            cout << "Data jalan tidak valid!" << endl;
        }
    }
    else
    {
        cout << "Salah satu atau kedua node tidak ditemukan!" << endl;
    }
}

void Connecting_Gudang_Bensin_TakBerarah(Graph &G, Graph_Pom_Bensin &GPB, string node1, string tempatBensin, string jalan, double jarak, int waktu, string macet)
{
    Addr_Node P1 = FindNode(G, node1);
    Addr_Bensin P2 = FindBensin(GPB, tempatBensin);

    if (P1 != Null && P2 != Null)
    {
        if (jalan != "" && jarak > 0 && waktu > 0 && macet != "")
        {
            Jalan JalanBaru1 = {{}, info(P2), jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E1 = FindEdge_Bensin(GPB, P2, tempatBensin, AlokasiEdge(JalanBaru1));
            InsertLast_Edge(G, P1, E1);

            Jalan JalanBaru2 = {info(P1), {}, jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E2 = FindEdge_Hubung(G, P1, node1, AlokasiEdge(JalanBaru2));
            InsertLast_Edge_Bensin(G, P1, P2, E2);
        }
        else
        {
            cout << "Data jalan tidak valid!" << endl;
        }
    }
    else
    {
        cout << "Salah satu atau kedua node tidak ditemukan!" << endl;
    }
}

void Connecting_Gudang_Bensin_Berarah(Graph &G, Graph_Pom_Bensin &GPB, string node1, string tempatBensin, string jalan, double jarak, int waktu, string macet)
{
    Addr_Node P1 = FindNode(G, node1);
    Addr_Bensin P2 = FindBensin(GPB, tempatBensin);

    if (P1 != Null && P2 != Null)
    {
        if (jalan != "" && jarak > 0 && waktu > 0 && macet != "")
        {
            Jalan JalanBaru1 = {{}, info(P2), jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E1 = FindEdge_Bensin(GPB, P2, tempatBensin, AlokasiEdge(JalanBaru1));
            InsertLast_Edge(G, P1, E1);
        }
        else
        {
            cout << "Data jalan tidak valid!" << endl;
        }
    }
    else
    {
        cout << "Salah satu atau kedua node tidak ditemukan!" << endl;
    }
}

void Connecting_Bensin_Gudang_TakBerarah(Graph &G, Graph_Pom_Bensin &GPB, string tempatBensin, string node2, string jalan, double jarak, int waktu, string macet)
{
    Addr_Bensin P1 = FindBensin(GPB, tempatBensin);
    Addr_Node P2 = FindNode(G, node2);

    if (P1 != Null && P2 != Null)
    {
        if (jalan != "" && jarak > 0 && waktu > 0 && macet != "")
        {
            Jalan JalanBaru1 = {info(P2), {}, jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E1 = FindEdge_Hubung(G, P2, tempatBensin, AlokasiEdge(JalanBaru1));
            InsertLast_Edge_Bensin(G, P2, P1, E1);

            Jalan JalanBaru2 = {{}, info(P1), jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E2 = FindEdge_Bensin(GPB, P1, tempatBensin, AlokasiEdge(JalanBaru2));
            InsertLast_Edge(G, P2, E2);
        }
        else
        {
            cout << "Data jalan tidak valid!" << endl;
        }
    }
    else
    {
        cout << "Salah satu atau kedua node tidak ditemukan!" << endl;
    }
}

void Connecting_Bensin_Gudang_Berarah(Graph &G, Graph_Pom_Bensin &GPB, string tempatBensin, string node2, string jalan, double jarak, int waktu, string macet)
{
    Addr_Bensin P1 = FindBensin(GPB, tempatBensin);
    Addr_Node P2 = FindNode(G, node2);

    if (P1 != Null && P2 != Null)
    {
        if (jalan != "" && jarak > 0 && waktu > 0 && macet != "")
        {
            Jalan JalanBaru1 = {info(P2), {}, jalan, jarak, waktu, (macet == "ya" || macet == "Ya") ? true : false};
            Addr_Edge E1 = FindEdge_Hubung(G, P2, tempatBensin, AlokasiEdge(JalanBaru1));
            InsertLast_Edge_Bensin(G, P2, P1, E1);
        }
        else
        {
            cout << "Data jalan tidak valid!" << endl;
        }
    }
    else
    {
        cout << "Salah satu atau kedua node tidak ditemukan!" << endl;
    }
}

Addr_Edge FindEdge_Hubung(Graph &G, Addr_Node PNode, string data, Addr_Edge P)
{
    while(P != Null)
    {
        for(Addr_Node temp = Start(G); temp != Null; temp = NextNode(temp))
        {
            if (info(temp).nama == data)
            {
                return P;
            }
        }
        P = NextEdge(P);
    }
    return Null;
}

Addr_Edge FindEdge_Bensin(Graph_Pom_Bensin &GPB, Addr_Bensin PBensin, string data, Addr_Edge P)
{
    while(P != Null)
    {
        for(Addr_Bensin temp = Start(GPB); temp != Null; temp = nextBensinList(temp))
        {
            if(info(temp).nama == data)
            {
                return P;
            }
        }
        P = NextEdge(P);
    }
    return Null;
}

string FindLastTempList(const TempList &L)
{
    Addr_TempList P = L.pertama;
    while (P != nullptr && nextTempList(P) != nullptr)
    {
        P = nextTempList(P);
    }

    return (P ? info(P) : "");
}

void DeleteFirst_Bensin(Graph_Pom_Bensin &G, Addr_Bensin PBensin, Addr_Edge &P)
{
    if (FirstBensin(PBensin) != Null)
    {
        P = FirstBensin(PBensin);
        FirstBensin(PBensin) = NextEdge(FirstBensin(PBensin));
        delete P;
    }
}

void DeleteFirst_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P)
{
    if (FirstEdge(PNode) != Null)
    {
        P = FirstEdge(PNode);
        FirstEdge(PNode) = NextEdge(FirstEdge(PNode));
        delete P;
    }
}

void DeleteFirst_Edge_Bensin(Graph &G, Addr_Bensin PBensin, Addr_Edge &P)
{
    if (FirstBensin(PBensin) != Null)
    {
        P = FirstBensin(PBensin);
        FirstBensin(PBensin)= NextEdge(FirstBensin(PBensin));
        delete P;
    }
}

void DeleteLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P)
{
    if (FirstEdge(PNode) != Null)
    {
        Addr_Edge temp = FirstEdge(PNode);
        if (NextEdge(temp) == Null)
        {
            P = temp;
            FirstEdge(PNode = Null);
            delete P;
        }
        else
        {
            while (NextEdge(NextEdge(temp)) != Null)
            {
                temp = NextEdge(temp);
            }
            P = NextEdge(temp);
            NextEdge(temp) = Null;
            delete P;
        }
    }
}

void DeleteLast_Edge_Bensin(Graph &G, Addr_Bensin PBensin, Addr_Edge &P)
{
    if (FirstBensin(PBensin) != Null)
    {
        Addr_Edge temp = FirstBensin(PBensin);
        if (NextEdge(temp) == Null)
        {
            P = temp;
            FirstBensin(PBensin = Null);
            delete P;
        }
        else
        {
            while (NextEdge(NextEdge(temp)) != Null)
            {
                temp = NextEdge(temp);
            }
            P = NextEdge(temp);
            NextEdge(temp) = Null;
            delete P;
        }
    }
}

void DeleteAfter_Edge(Graph &G, Addr_Node PNode, Addr_Edge Prec, Addr_Edge &P)
{
    for(Addr_Edge temp = FirstEdge(PNode); temp != Null; temp = NextEdge(temp))
    {
        if (temp == Prec)
        {
            P = NextEdge(temp);
            if (P != Null)
            {
               NextEdge(temp) = NextEdge(P);
               delete P;
            }
            break;
        }
    }
}

void DeleteAfter_Edge_Bensin(Graph &G, Addr_Bensin PBensin, Addr_Edge Prec, Addr_Edge &P)
{
    for(Addr_Edge temp = FirstBensin(PBensin); temp != Null; temp = NextEdge(temp))
    {
        if (temp == Prec)
        {
            P = NextEdge(temp);
            if (P != Null)
            {
               NextEdge(temp) = NextEdge(P);
               delete P;
            }
            break;
        }
    }
}

void Delete_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge)
{
   Addr_Edge Eout,prec;

	if (PEdge == FirstEdge(PNode))
    {
		DeleteFirst_Edge(G,PNode,Eout);
	}
	else if (NextEdge(PEdge) == Null)
	{
		DeleteLast_Edge(G,PNode,Eout);
	}
	else
	{
		prec = FirstEdge(PNode);
		while (NextEdge(prec) != PEdge)
		{
			prec = NextEdge(prec);
		}
		DeleteAfter_Edge(G,PNode,prec,Eout);
	}
}

void Delete_Edge_Gudang_PomBensin(Graph &G, Addr_Node gudang, Addr_Bensin bensin, Addr_Edge jalan)
{
    Addr_Edge Eout, prec;

    // Delete edge from Gudang to Pom Bensin
    if (jalan == FirstEdge(gudang))
    {
        DeleteFirst_Edge(G, gudang, Eout);
    }
    else if (NextEdge(jalan) == Null)
    {
        DeleteLast_Edge(G, gudang, Eout);
    }
    else
    {
        prec = FirstEdge(gudang);
        while (NextEdge(prec) != jalan)
        {
            prec = NextEdge(prec);
        }
        DeleteAfter_Edge(G, gudang, prec, Eout);
    }

    // Delete edge from Pom Bensin to Gudang
    Addr_Edge prevEdge = Null;
    for(Addr_Edge edge = FirstBensin(bensin); edge != Null; edge = NextEdge(edge))
    {
        if (info(edge).gudang.nama == info(gudang).nama)
        {
            if (prevEdge == Null)
            {
                DeleteFirst_Edge_Bensin(G, bensin, edge);
            }
            else
            {
                DeleteAfter_Edge_Bensin(G, bensin, prevEdge, edge);
            }
            break;
        }
        prevEdge = edge;
    }
}

void Disconnecting_TakBerarah(Graph &G, string node1, string node2)
{
    Addr_Node PNode1 = FindNode(G, node1);
    Addr_Node PNode2 = FindNode(G, node2);

    if (PNode1 != Null && PNode2 != Null)
    {
        Addr_Edge PEdge1 = FindEdge_Putus(G, PNode1, node2);
        Addr_Edge PEdge2 = FindEdge_Putus(G, PNode2, node1);

        if (PEdge1 != Null)
        {
            Delete_Edge(G, PNode1, PEdge1);
        }
        if (PEdge2 != Null)
        {
            Delete_Edge(G, PNode2, PEdge2);
        }
    }
}

void Disconnecting_Berarah(Graph &G, string node1, string node2)
{
    Addr_Node PNode1 = FindNode(G, node1);
    Addr_Node PNode2 = FindNode(G, node2);

    if (PNode1 != Null && PNode2 != Null)
    {
        Addr_Edge PEdge1 = FindEdge_Putus(G, PNode1, node2);

        if (PEdge1 != Null)
        {
            Delete_Edge(G, PNode1, PEdge1);
        }
    }
}

void Disconnecting_Gudang_Bensin_TakBerarah(Graph &G, Graph_Pom_Bensin &GPB, string node1, string tempatBensin)
{
    Addr_Node PNode1 = FindNode(G, node1);
    Addr_Bensin PNode2 = FindBensin(GPB, tempatBensin);

    if (PNode1 != Null && PNode2 != Null)
    {
        Addr_Edge PEdge1 = FindEdge_Bensin(GPB, PNode2, tempatBensin);
        Addr_Edge PEdge2 = FindEdge_Putus(G, PNode1, node1);

        if (PEdge1 != Null)
        {
            Delete_Edge_Gudang_PomBensin(G, PNode1, PNode2, PEdge1);
        }
        if (PEdge2 != Null)
        {
            Delete_Edge_Gudang_PomBensin(G, PNode1, PNode2, PEdge2);
        }
    }
}

void Disconnecting_Gudang_Bensin_Berarah(Graph &G, Graph_Pom_Bensin &GPB, string node1, string tempatBensin)
{
    Addr_Node PNode1 = FindNode(G, node1);
    Addr_Bensin PNode2 = FindBensin(GPB, tempatBensin);

    if (PNode1 != Null && PNode2 != Null)
    {
        Addr_Edge PEdge1 = FindEdge_Bensin(GPB, PNode2, tempatBensin);

        if (PEdge1 != Null)
        {
            Delete_Edge_Gudang_PomBensin(G, PNode1, PNode2, PEdge1);
        }
    }
}

void Disconnecting_Bensin_Gudang_TakBerarah(Graph &G, Graph_Pom_Bensin &GPB, string tempatBensin, string node2)
{
    Addr_Bensin PNode1 = FindBensin(GPB, tempatBensin);
    Addr_Node PNode2 = FindNode(G, node2);

    if (PNode1 != Null && PNode2 != Null)
    {
        Addr_Edge PEdge1 = FindEdge_Putus(G, PNode2, node2);
        Addr_Edge PEdge2 = FindEdge_Bensin(GPB, PNode1, tempatBensin);

        if (PEdge1 != Null)
        {
            Delete_Edge_Gudang_PomBensin(G, PNode2, PNode1, PEdge1);
        }
        if (PEdge2 != Null)
        {
            Delete_Edge_Gudang_PomBensin(G, PNode2, PNode1, PEdge2);
        }
    }
}

void Disconnecting_Bensin_Gudang_Berarah(Graph &G, Graph_Pom_Bensin &GPB, string tempatBensin, string node2)
{
    Addr_Bensin PNode1 = FindBensin(GPB, tempatBensin);
    Addr_Node PNode2 = FindNode(G, node2);

    if (PNode1 != Null && PNode2 != Null)
    {
        Addr_Edge PEdge1 = FindEdge_Putus(G, PNode2, node2);

        if (PEdge1 != Null)
        {
            Delete_Edge_Gudang_PomBensin(G, PNode2, PNode1, PEdge1);
        }
    }
}

Addr_Edge FindEdge_Putus(Graph &G, Addr_Node PNode, string data)
{
    for(Addr_Edge P = Start(G); P != Null; P = NextEdge(P))
    {
        for(Addr_Node temp = Start(G); temp != Null; temp = NextNode(temp))
        {
            if (info(temp).nama == data)
            {
                return P;
            }
        }
    }
    return Null;
}

Addr_Edge FindEdge_Bensin(Graph_Pom_Bensin &GPB, Addr_Bensin PBensin, string data)
{
    for(Addr_Edge P = FirstBensin(PBensin); P != Null; P = NextEdge(P))
    {
        for(Addr_Bensin temp = Start(GPB); temp != Null; temp = nextBensinList(temp))
        {
            if(info(temp).nama == data)
            {
                return P;
            }
        }
    }
    return Null;
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
        InsertLast_TempList(T, AlokasiTempList(info(D).gudang.nama));
        cout << "info bangunan" << info(D).gudang.nama << endl;
        AlJikstra(G, info(D).gudang, selesai, T);
    }
}

void catatTempList(const TempList &asal, TempList &tujuan)
{
    CreateTempList(tujuan);

    for(Addr_TempList P = asal.pertama; P != nullptr; P = nextTempList(P))
    {
        InsertLast_TempList(tujuan, AlokasiTempList(info(P)));
    }
}

void asistenJalurAlternatifDFS(Graph &G, const Infotype_Node &GudangSekarang, const Infotype_Node &GudangTujuan, int WaktuSekarang, int &WaktuMinimal, TempList &L, TempList &jalanTerbaik, const Infotype_Edge &namaJalanBlok)
{
    if(GudangSekarang.nama == GudangTujuan.nama)
    {
        if(WaktuSekarang < WaktuMinimal)
        {
            WaktuMinimal = WaktuSekarang;
            catatTempList(L, jalanTerbaik);
        }
        return;
    }

    Addr_Node P = FindNode(G, GudangSekarang.nama);
    if(P == nullptr)
    {
        return;
    }

    for(Addr_Edge Gjalan = FirstEdge(P); Gjalan != Null; Gjalan = NextEdge(Gjalan))
    {
        bool terblokir = (info(Gjalan).namaJalan == namaJalanBlok.namaJalan);
        bool dilewati = (telahDikunjungi(L, info(Gjalan).gudang.nama));

        if(!terblokir && !dilewati)
        {
            InsertLast_TempList(L, AlokasiTempList(info(Gjalan).gudang.nama));
            cout << "Menuju jalan " << info(Gjalan).namaJalan << " menuju gudang " << info(Gjalan).gudang.nama << " memakan waktu " << info(Gjalan).waktu << endl;
            asistenJalurAlternatifDFS(G, info(Gjalan).gudang, GudangTujuan, WaktuSekarang + info(Gjalan).waktu, WaktuMinimal, L, jalanTerbaik, namaJalanBlok);
            Delete_Templist(L);
            cout << "Kembali ke kota " << FindLastTempList(L) << endl;
        }
    }
}

void jalurAlternatifDFS(Graph &G, const Infotype_Node &awalGudang, const Infotype_Node &tujuanGudang, const Infotype_Edge &namaJalanBlok)
{
    TempList dikunjungi;
    CreateTempList(dikunjungi);

    TempList jalurTerbaik;
    CreateTempList(jalurTerbaik);

    InsertLast_TempList(dikunjungi, AlokasiTempList(awalGudang.nama));

    int waktuMinimal = INT_MAX;

    asistenJalurAlternatifDFS(G, awalGudang, tujuanGudang, 0, waktuMinimal, dikunjungi, jalurTerbaik, namaJalanBlok);

    if(waktuMinimal == INT_MAX)
    {
        cout << "Tidak ada jalur alternatif yang tersedia." << endl;
        return;
    }
    else
    {
        cout << "Jalur alternatif terbaik membutuhkan waktu: " << waktuMinimal << endl;

        cout << "Waktu tercepat: ";
        bool cetakPertama = true;
        for(Addr_TempList P = jalurTerbaik.pertama; P != nullptr; P = nextTempList(P))
        {
            if(!cetakPertama)
            {
                cout << " -> ";
            }
            cout << P->info;
            cetakPertama = false;
        }
        cout << endl;
    }
}

Addr_Edge findShortestRute(Graph G, Addr_Node AG, TempList AT)
{
    Addr_Edge E = FirstEdge(AG);
    Addr_Edge terpendek = E;
    while(E != nullptr)
    {
        if(info(E).waktu < info(terpendek).waktu && !telahDikunjungi(AT, info(E).gudang.nama))
        {
            terpendek = E;
        }
        E = NextEdge(E);
    }
    return terpendek;
}

bool telahDikunjungi(TempList AT, string Gudang)
{
    for(Addr_TempList R = AT.pertama; R != nullptr; R = nextTempList(R))
    {
        if(info(R) == Gudang)
        {
            return true;
        }
    }
    return false;
}

void ShowAllGudangJalur(Graph &G)
{
    cout << "Graph G: " << endl;
    if (Start(G) != Null)
    {
        for (Addr_Node N = Start(G); N != Null; N = NextNode(N))
        {
            cout << "\tGudang " << info(N).nama << " berlokasi di " << info(N).lokasi
                 << " dengan kapasitas " << info(N).kapasitas << " dan jumlah "
                 << info(N).jumlah << " memiliki tetangga berupa: " << endl;
            cout << "<<=================================================================================>>" << endl;
            cout << left << setw(15) << "[Nama Gudang]"
                 << setw(20) << "[Nama Pom Bensin]"
                 << setw(20) << "[Nama Jalan]"
                 << setw(10) << "[Jarak]"
                 << setw(20) << "[Macet]"
                 << setw(15) << "[Durasi Perjalanan]"
                 << endl;
            cout << "<<----------------------------------------------------------------------------------->>" << endl;

            for (Addr_Edge E = FirstEdge(N); E != Null; E = NextEdge(E))
            {
                cout << left << setw(15) << info(E).gudang.nama
                     << setw(20) << info(E).pomBensin.nama
                     << setw(20) << info(E).namaJalan
                     << setw(10) << info(E).jarak
                     << setw(20) << info(E).macet
                     << setw(15) << info(E).waktu
                     << endl;
            }
            cout << "<<----------------------------------------------------------------------------------->>" << endl << endl;

        }
    }
    else
    {
        cout << "Graf Kosong" << endl;
    }
}

void ShowAllPomBensin(Graph_Pom_Bensin &GPB)
{
    if(Start(GPB) != Null)
    {
        for(Addr_Bensin B = Start(GPB); B != Null; B = nextBensinList(B))
        {
            cout << "Nama pom bensin: " << info(B).nama << endl;
            cout << "Lokasi pom bensin: " << info(B).lokasi << endl;
            cout << "Kapasitas tangki pom bensin: " << info(B).kapasitas << endl;
            cout << "Jumlah dispenser bensin : " << info(B).jumlah << endl;
            /*
            for (Addr_Node gudang = B->keGudang; gudang != Null; gudang = NextNode(gudang))
            {
                cout << "Gudang yang terhubung: " << info(gudang).nama << endl;
                for (Addr_Edge jalur = FirstEdge(gudang); jalur != NULL; jalur = NextEdge(jalur))
                {
                    cout << "  - Jalan: " << info(jalur).namaJalan << ", Jarak: " << info(jalur).jarak << " km, Waktu: " << info(jalur).waktu << " detik" << endl;
                }
            }
            */
        }
    }
    else
    {
		cout << "Tidak ada pom bensin" << endl;
	}
}

void showPeta(Graph &G, Graph_Pom_Bensin &GPB)
{
    // Display nodes
    cout << "Gudang dalam graf:" << endl;
    for (Addr_Node node = Start(G); node != Null; node = NextNode(node))
    {
        cout << "Nama gudang: " << info(node).nama << endl
         << "Lokasi gudang: "<< info(node).lokasi << endl
         << "Kapasitas gudang: " << info(node).kapasitas << endl
         << "Jumlah gudang: " << info(node).jumlah << endl <<
         "Tinggi gudang: " << info(node).tinggi << endl;
    }

    // Display edges (node)
    cout << "Jalur dalam graf:" << endl;
    for (Addr_Node node = Start(G); node != Null; node = NextNode(node))
    {
        for (Addr_Edge jalurGudang = FirstEdge(node); jalurGudang != Null; jalur = NextEdge(jalurGudang))
        {
            cout << "  - Jalan: " << info(jalurGudang).namaJalan << ", Jarak: " << info(jalurGudang).jarak << " km, Waktu: " << info(jalurGudang).waktu << " detik" << endl;
        }
    }

    // Display gas station
    cout << "Pom Bensin dalam graf: " << endl;
    for (Addr_Node gasNode = Start(GPB); gasNode != Null; gasNode = NextNode(gasNode))
    {
        cout << "Nama pom Bensin: " << info(gasNode).nama << endl
        << "Lokasi Pom Bensin: " << info(gasNode).lokasi << endl
        << "Kapasitas Pom Bensin: " << info(gasNode).kapasitas << endl
        << "Jumlah Pom Bensin: " << info(gasNode).jumlah << endl;
    }

    // Display edges (gas station)
    cout << "Jalur dalam graf:" << endl;
    for (Addr_Node gasNode = Start(GPB); gasNode != Null; gasNode = NextNode(gasNode))
    {
        for (Addr_Edge jalurBensin = FirstEdge(gasNode); jalurBensin != Null; jalurBensin = NextEdge(jalurBensin))
        {
            cout << "  - Jalan: " << info(jalurBensin).namaJalan << ", Jarak: " << info(jalurBensin).jarak << " km, Waktu: " << info(jalurBensin).waktu << " detik" << endl;
        }
    }

    //Display storage and roads
    ShowAllGudangJalur(G);
    // Display gas stations
    ShowAllPomBensin(GPB);
}

void ShowTempList(TempList L)
{
    for(Addr_TempList P = L.pertama; P != Null; P = nextTempList(P))
    {
        cout << info(P) << " ";
    }
    cout << endl;
}

void Delete_Templist(TempList &L)
{
    Addr_TempList P = L.pertama;

    if(P == nullptr)
    {
        return;
    }

    if(nextTempList(P) == nullptr)
    {
        delete P;
        L.pertama = Null;
        return;
    }

    while(nextTempList(nextTempList(P)) != nullptr)
    {
        P = nextTempList(P);
    }

    delete nextTempList(P);
    nextTempList(P) = nullptr;
}