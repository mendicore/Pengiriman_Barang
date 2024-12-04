#ifndef RUTE_H_INCLUDED
#define RUTE_H_INCLUDED

#include <iostream>

using namespace std;

#define Info(P)  	    (P)->Info
#define NextNode(P)  	(P)->NextNode
#define NextEdge(P)  	(P)->NextEdge
#define FirstEdge(P) 	(P)->FirstEdge
#define Start(G) 		  (G).Start

typedef struct vElmt Elmt_Node;
typedef struct eElmt Elmt_Edge;
typedef Elmt_Node* Addr_Node;
typedef Elmt_Edge* Addr_Edge;

typedef string Infotype_Node;
typedef int Infotype_Edge;

typedef struct {
    Addr_Node Start;
} Graph;

struct vElmt {
   Infotype_Node Info;
   Addr_Node NextNode;
   Addr_Edge FirstEdge;
};

struct eElmt {
   Infotype_Edge Info;
   Addr_Edge NextEdge;
};

void CreateGraph(Graph &G);
Addr_Node AlokasiNode(string nameNode);
Addr_Edge AlokasiEdge(Infotype_Edge infoEdge);
void AddNewNode(Graph &G, Addr_Node P);
void deleteNode(Graph &G, Addr_Node P);
Addr_Node FindNode(Graph G, string data);
void InsertLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge);
void Connecting(Graph &G, string node1, string node2, int distance);
Addr_Edge FindEdge(Graph &G, Addr_Node PNode, string data);
void DeleteFirst_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P);
void DeleteLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge &P);
void DeleteAfter_Edge(Graph &G, Addr_Node PNode, Addr_Edge Prec, Addr_Edge &P);
void Delete_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge);
void Disconnecting(Graph &G, string node1, string node2);
//void findShortestRute(); // blum diimplementasi
void ShowAll(Graph &G);

#endif // RUTE_H_INCLUDED
