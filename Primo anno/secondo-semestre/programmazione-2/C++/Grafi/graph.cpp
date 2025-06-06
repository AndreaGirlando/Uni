#include <iostream>
using namespace std;

class Edge{ // archi
    public:
        Edge(size_t _target, Edge* _next) : target(_target), next(_next) {}
        Edge* GetNext(){ return next; }
        size_t GetTarget() const { return target; }
        void Print() { cout << target << next << endl; }
    private:
        size_t target; //il numero alla quale questo arco punta
        Edge* next; //successivo nella lista di adiacenza
};

class Node{ // nodi
    public:
        Node() : head(nullptr){}
        ~Node();
        Edge* AddEdge(size_t target);
        Edge* GetHead()  { return head; }
    private:
        Edge* head; //testa della lista di adiacenza
};

class Graph{ //grafo
    public:
        Graph(size_t n): num_nodes(n) { nodes = new Node[n]; }
        ~Graph() { delete [] nodes; }

        size_t GetNumNodes() { return num_nodes; };
        size_t GetNumEdges();

        Graph& AddEdge(size_t source, size_t target){
            nodes[source].AddEdge(target);
            return *this;
        };
        void Print();
    private:
        Node* nodes; //come se fosse nodes[];
        size_t num_nodes;
};

int main(){

    int n = 7; //lasciamo il primo nodo non connesso in modo che si ha la numerazione da grafo normale
    Graph g(n);
    g.AddEdge(1,2).AddEdge(1,4).AddEdge(4,2).AddEdge(2,5).AddEdge(3,5).AddEdge(3, 6).AddEdge(5,4).AddEdge(6, 6);
    g.Print();
    cout << "Il numero di archi è: " << g.GetNumEdges() << endl;




    return 0;
}

Edge* Node::AddEdge(size_t target){
    Edge* newEdge = new Edge(target, head);
    head = newEdge;
    return newEdge;
}

Node::~Node(){
    Edge* e = head;
    while(e) {
        Edge* succ = e->GetNext();
        delete e;
        e = succ;
    }
}

void Graph::Print(){
    cout << "Il grafo ha " << num_nodes << " nodi" << endl;
    cout << "Gli archi sono: " << endl;
    for (size_t i = 0;i < num_nodes; i++){
        Edge* e = nodes[i].GetHead();
        while(e){
            cout << "Arco "  << e << " (" << i << ", " << e->GetTarget() << ")" << endl;
            e = e->GetNext();
        }
    }
}

size_t Graph::GetNumEdges(){
    size_t count = 0;
    for (size_t i = 0;i < num_nodes; i++){
        Edge* e = nodes[i].GetHead();
        while(e){
            count++;
            e = e->GetNext();
        }
    }
    return count;
}

