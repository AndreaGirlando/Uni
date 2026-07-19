#include <iostream>
using namespace std;

class Patient{
    public:
        Patient(int _id, string _name, string _condition): id(_id), name(_name), condition(_condition) {}
        int getId(){return id;};
        string getName(){return name;};
        string getCondition(){return condition;};
        void setId(int _id){id=_id;}
        void setName(string _name){name=_name;}
        void setCondition(string _condition){condition=_condition;}
        friend ostream& operator<<(ostream& stream, Patient& value);
    private:
        int id;
        string name;
        string condition;
};

ostream& operator<<(ostream& stream, Patient& value){
    cout << "Paziente(" << value.id << "): \n\tNome: " << value.name << " \n\tCondizione: " << value.condition;
    return stream;
}

template<typename T> class Queue;
template<typename T> class Node{
    public:
        Node(T* _value, Node<T>* _next = nullptr): value(_value), next(_next) {}
        void stampa(){
            cout << *(value);
            cout << "\n\tNext: " << next;
        }
        friend class Queue<T>;
    private:
        T* value;
        Node<T>* next;
};


template<typename T> class Queue{
    public:
        Queue():head(nullptr), tail(nullptr), numberOfNode(0){}
        ~Queue(){
            for(int i = 0;i<tempNumberOfNode; i++){
                dequeue();
            }
        }
        void enqueue(T* temp){
            Node<T>* nodo = new Node<T>(temp);
            if(head == nullptr && tail == nullptr){
                head = nodo;
                tail = nodo;
                numberOfNode++;
            }
            else{
                tail->next = nodo;
                tail = nodo;
                numberOfNode++;
            }
        }
        void enqueuePriority(T* temp, int priority){
            if(priority == 0){
                enqueue(temp);
            }
            else{
                T** array = new T*[numberOfNode];
                int tempNumberOfNode = numberOfNode;
                for(int i = 0;i<tempNumberOfNode; i++){
                    array[i] = dequeue();
                }
                for(int i = 0;i<tempNumberOfNode; i++){
                    enqueue(array[i]);
                    if(i == (tempNumberOfNode-priority)-1){
                        enqueue(temp);
                    }

                }

            }
        }
        T* dequeue(){
            Node<T>* nodo = head;
            T* value = nullptr;
            if(head == tail){
                head = nullptr;
                tail = nullptr;
                value = nodo->value;
                delete nodo;
                numberOfNode--;
                return value;
            }else{
                head = head->next;
                value = nodo->value;
                delete nodo;
                numberOfNode--;
                return value;
            }
            return value;
        }
        bool isEmpty(){
            return head == nullptr && tail == nullptr;
        }
        void stampaCoda(){ //teoricamente illegale ma utile per visualizzare la coda
            Node<T>* tempHead = head;
            while(tempHead != nullptr){
                tempHead->stampa();
                cout << "\n\n";
                tempHead = tempHead->next;
            }
        }
        int getLen(){ return numberOfNode; }
    private:
        int numberOfNode;
        Node<T>* head;
        Node<T>* tail;
};

int main(){

    Queue<Patient> coda;
    coda.enqueue(new Patient(1,"Giovanni","Male"));
    coda.enqueue(new Patient(2,"Marco","Male"));
    coda.enqueue(new Patient(3,"Luca","Male"));
    coda.enqueue(new Patient(4,"Matteo","Male"));
    coda.enqueue(new Patient(5,"Simone","Male"));
    coda.enqueue(new Patient(6,"Andrea","Male"));
    coda.enqueue(new Patient(7,"Mario","Male"));
    coda.enqueuePriority(new Patient(8,"Lorenzo","Male"),3);
    coda.enqueuePriority(new Patient(9,"Marco","Male"),1);
    coda.stampaCoda();

    cout << endl;
    return 0;
}