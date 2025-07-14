#include <iostream>

using namespace std;

class Edge
{
public:
    Edge(size_t t, Edge* nx) : target(t), next(nx) {}
    Edge* GetNext() {return next;}
    size_t GetTarget() const {return target;}
private:
    size_t target;
    Edge* next; // puntatore al successivo elemento della lista di adiacenza
};

class Node
{
public:
    Node() : head(nullptr) {}
    ~Node();

    Edge* AddEdge(size_t target);
    Edge* GetHead() {return head;}
private:
    Edge* head; // testa della lista di adiacenza
};

enum NodeColor {white=0,grey=1,black=2};

class Graph
{
public:
    Graph(size_t n) : num_nodes(n),color(nullptr),d(nullptr),f(nullptr),pred(nullptr) {nodes = new Node[n];}
    ~Graph() {delete [] nodes;}

    size_t GetNumNodes() {return num_nodes;}
    size_t GetNumEdges();

    Graph& AddEdge(size_t source, size_t target) {nodes[source].AddEdge(target); return *this;}
    //void RemoveEdge();
    void Print();

    void DFS();
    void DFS_Visit(size_t u);
    void Print_DFS_results();
private:
    Node* nodes; // come se fosse Node nodes[];
    size_t num_nodes;
private:
    // array dinamici che mantengono le informazioni per la DFS
    size_t* d;
    size_t* f;
    NodeColor* color;
    int* pred;
    size_t time;
};

int main()
{
    int n = 7;
    Graph g(n);
    g.AddEdge(1,2).AddEdge(1,4).AddEdge(4,2).AddEdge(2,5).AddEdge(5,4).AddEdge(3,5).AddEdge(3,6).AddEdge(6,6);
    g.Print();
    cout << "Il numero di archi è: " << g.GetNumEdges() << endl;

    g.DFS();
    g.Print_DFS_results();

    return 0;
}


Node::~Node() 
{
    Edge* e = head;
    while (e) {
        Edge* succ = e->GetNext();
        delete e;
        e = succ;
    }
}

Edge* Node::AddEdge(size_t target)
{
    Edge* newEdge = new Edge(target,head);
    head = newEdge;
    return newEdge;
}

void Graph::Print() 
{
    cout << "Il grafo ha " << num_nodes << " nodi" << endl;
    cout << "Gli archi sono: " << endl;
    for (size_t i=0; i<num_nodes; i++)
    {
        Edge* e = nodes[i].GetHead();
        while(e)
        {
            cout <<  "Arco " << e << " (" << i << ", " << e->GetTarget() << ") " << endl; 
            e = e->GetNext();
        }
    }
}

size_t Graph::GetNumEdges()
{
    size_t count = 0;
    for (size_t i=0; i<num_nodes; i++)
    {
        Edge* e = nodes[i].GetHead();
        while(e)
        {
            count++;  
            e = e->GetNext();
        }
    }
    return count;
}

void Graph::DFS()
{
    if (color) {
        delete [] color;
        delete [] d;
        delete [] f;
        delete [] pred;
    }

    color = new NodeColor[num_nodes];
    d = new size_t[num_nodes];
    f = new size_t[num_nodes];
    pred = new int[num_nodes];

    for (int i=0; i< num_nodes; i++){
        color[i] = white;
        pred[i] = -1;
    }
    time = 0;
    for (int i=0; i< num_nodes; i++)
        if (color[i] == white)
            DFS_Visit(i);
}

void Graph::DFS_Visit(size_t u)
{
    color[u] = grey;
    d[u] = time++;
    Edge* e = nodes[u].GetHead();
    while(e) {
        size_t v = e->GetTarget();
        if (color[v] == white)
        {
            pred[v] = u;
            DFS_Visit(v);
        }
        e = e->GetNext();
    }
    color[u] = black;
    f[u] = time++;
}

void Graph::Print_DFS_results()
{
    for (int i=0; i<num_nodes; i++)
        cout << "Node " << i << ": color=" << color[i] << "; d=" << d[i] << "; f=" << f[i] << "; pred=" << pred[i] << endl;
}
