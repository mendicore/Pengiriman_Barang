#include "Rute.h"

void CreateGraph(Graph &G) {
    Start(G) = NULL;
}

Addr_Node AlokasiNode(string nameNode) {
    Addr_Node P = new Elmt_Node;
    if (P != NULL) {
        Info(P) = nameNode;
        NextNode(P) = NULL;
        FirstEdge(P) = NULL;
    }
    return P;
}

Addr_Edge AlokasiEdge(Infotype_Edge infoEdge) {
    Addr_Edge P = new Elmt_Edge;
    if (P != NULL) {
        Info(P) = infoEdge;
        NextEdge(P) = NULL;
    }
    return P;
}

void AddNewNode(Graph &G, Addr_Node P) {
    if (Start(G) == NULL) {
        Start(G) = P;
    } else {
        Addr_Node temp = Start(G);
        while (NextNode(temp) != NULL) {
            temp = NextNode(temp);
        }
        NextNode(temp) = P;
    }
}

void deleteNode(Graph &G, Addr_Node P) {
    while (FirstEdge(P) != NULL) {
        DeleteFirst_Edge(G, P, FirstEdge(P));
    }

    if (Start(G) == P) {
        Start(G) = NextNode(P);
    } else {
        Addr_Node temp = Start(G);
        while (NextNode(temp) != P) {
            temp = NextNode(temp);
        }
        NextNode(temp) = NextNode(P);
    }

    delete P;
    P = NULL;
}



Addr_Node FindNode(Graph G, string data) {
    Addr_Node P = Start(G);
    while (P != NULL) {
        if (Info(P) == data) {
            return P;
        }
        P = NextNode(P);
    }
    return NULL;
}

void InsertLast_Edge(Graph &G, Addr_Node PNode, Addr_Edge PEdge) {
    if (FirstEdge(PNode) == NULL) {
        FirstEdge(PNode) = PEdge;
    } else {
        Addr_Edge temp = FirstEdge(PNode);
        while (NextEdge(temp) != NULL) {
            temp = NextEdge(temp);
        }
        NextEdge(temp) = PEdge;
    }
}

void Connecting(Graph &G, string node1, string node2, int distance) {
    Addr_Node P1 = FindNode(G, node1);
    Addr_Node P2 = FindNode(G, node2);
    if (P1 != NULL && P2 != NULL) {
        Addr_Edge E1 = AlokasiEdge(distance);
        InsertLast_Edge(G, P1, E1);
        Addr_Edge E2 = AlokasiEdge(distance);
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

////void findShortestRute(){}

void ShowAll(Graph &G) {
    Addr_Node P = Start(G);
    while (P != NULL) {
        cout << "Gudang " << Info(P);

        Addr_Edge E = FirstEdge(P);
        if (E != NULL) {
            cout << " -> ";
        }

        while (E != NULL) {
            Addr_Node connectedNode = FindNode(G, Info(NextNode(P)));
            cout << Info(E) << " km -> Gudang " << Info(connectedNode);
            E = NextEdge(E);
            if (E != NULL) {
                cout << " -> ";
            }
        }

        cout << endl;
        P = NextNode(P);
    }
}


