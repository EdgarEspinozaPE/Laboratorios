#include <iostream>
template<typename T>
class Linkedlist;

template<typename T>
std::ostream& operator<<(std::ostream& out,Linkedlist<T> a){
	for(class Linkedlist<T>::Iterator iterator = a.begin();iterator != a.end(); iterator++){ 
		out << *iterator << " "; 
	} 
	out<<"\n";
}

template<typename T>
class Nodo{
private:
	T elem;
	Nodo<T>* next;
	friend class Linkedlist<T>;
public:
	Nodo(){
		this->elem=0;
		this->next=NULL;
	}
	Nodo(T elem){
		this->elem=elem;
		this->next=NULL;
	}
};
template<typename T>
class Linkedlist{
private:
	int size;
	Nodo<T>* head;
	Nodo<T>* tail;
public:
	Linkedlist(){
		this->size=0;
		this->head=NULL;
		this->tail=head;
	}
	Linkedlist(T n){
		Nodo<T> *a1=new Nodo<T>(n);
		this->size=1;
		this->head=a1;
		this->tail=head;
	}
	Linkedlist(T n[],int size){
		Nodo <T>*a1=new Nodo<T>(n[0]);
		this->head=a1;
		this->size=1;
		this->tail=head;
		for(int i=1;i<size;i++){
			this->pushback(n[i]); 
		}		
	}
	Linkedlist(Linkedlist &list){
		if(list.head!=NULL){
			this->size=1;
			Nodo <T>*a1=new Nodo<T>(list.head->elem);
			this->head=a1;
			a1=list.head;
			for(Linkedlist<T>::Iterator iterador=++list.begin();iterador!=list.end();iterador++){
				a1=a1->next;
				this->pushback(a1->elem);
			}
		}
	}
	~Linkedlist(){
		Nodo <T>*borrador;
		while(head!=NULL){
			borrador=head;
			head=borrador->next;
			delete borrador;
		}
	}
	class Iterator{ 
    private: 
        Nodo<T>* actualnodo; 
        int posicion;
        friend Linkedlist;
    public: 
    Iterator(){
        actualnodo=head;
        posicion=0;
	} 
    Iterator(Nodo<T>* nuevonodo){
        actualnodo=nuevonodo;
        this->posicion=0;
    }
  
        Iterator& operator=(Nodo<T>* othernodo) 
        { 
            this->actualnodo = othernodo; 
            return *this; 
        } 
		Iterator& operator--(){
			
		} 
        Iterator& operator++(){ 
            if (actualnodo){
                actualnodo = actualnodo->next;
				posicion++;            
			}
            return *this; 
        } 
  
        Iterator operator++(T){ 
            Iterator iterator = *this; 
            ++*this; 
            return iterator; 
        } 
  
        bool operator!=(const Iterator& iterator) 
        { 
            return actualnodo != iterator.actualnodo; 
        } 
  
        T operator*() 
        { 
            return actualnodo->elem; 
        }
    }; 
    Iterator begin(){
		return Iterator(head);
	}
	Iterator end(){
		return Iterator(tail->next);
	}
	void pushback(T n){
		if(head==NULL){
			head = new Nodo<T>(n);
			tail = head;
		}
		else if(size==1){
			tail = new Nodo<T>(n);
			head->next=tail;
		}
		else{
			Nodo<T>* newnodo= new Nodo<T>(n);
			tail->next=newnodo;
			tail=newnodo;
		}
		this->size++;
	}
	void insert(T n,int position){
		if(position<=this->size){
			if(head==NULL){
				this->pushback(n);
			}
			else if(position==0){
				this->pushfront(n);
			}
			else if(position==size){
				this->pushback(n);
			}
			else{
				Nodo<T>* newnodo = new Nodo<T>(n);
				Linkedlist<T>::Iterator itr=this->begin();
				for(itr;itr.posicion!=position-1;itr++);
				Nodo<T>* aux=itr.actualnodo->next;
				itr.actualnodo->next=newnodo;
				newnodo->next=aux;
			}
			this->size++;
		}
		
		else
			std::cout<<"Posicion no valida \n";
	}
	void pushfront(T n){
		if(head==NULL){
			head = new Nodo<T>(n);
			tail = head;
		}
		else if(size==1){
			head = new Nodo<T>(n);
			head->next=tail;
		}
		else{
			Nodo<T>* newnodo= new Nodo<T>(n);
			newnodo->next=head;
			head=newnodo;
		}
		this->size++;
	}
};
int main(){
	int A[]={2,6,3,1,8,5};
	Linkedlist <int>B(A,6);
	Linkedlist <int>C(4);
	Linkedlist <int>D=B;
	std::cout<<B;
	std::cout<<D;
	D.insert(4,3);
	C.pushback(3);
	std::cout<<C;
	C.pushfront(8);
	std::cout<<D;
	std::cout<<C;
	return 0;
}
//link: https://github.com/EdgarEspinozaPE/Laboratorios
