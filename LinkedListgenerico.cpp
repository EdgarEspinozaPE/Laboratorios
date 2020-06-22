#include <iostream>

template<typename T>
class Nodo{
private:
	
public:
	T elem;
	Nodo<T>* next;
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
public:
	Linkedlist(){
		this->size=0;
		this->head=NULL;
	}
	Linkedlist(T n){
		Nodo<T> *a1=new Nodo<T>(n);
		this->size=1;
		this->head=a1;
	}
	Linkedlist(T n[],int size){
		Nodo <T>*a1=new Nodo<T>(n[0]);
		this->head=a1;
		this->size=1;
		for(int i=1;i<size;i++){
			//this->insert(n[i]);  arreglar el insert
		}		
	}
	Linkedlist(Linkedlist &list){
		if(list.head!=NULL){
			this->size=1;
			Nodo <T>*a1=new Nodo<T>(list.head->elem);
			this->head=a1;
			a1=list.head;
			for(int i=1;i<list.size;i++){
				a1=a1->next;
				this->insert(a1->elem);
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
	void insert(T n)
	/*bool esta(T n){
		Nodo* newnodo;
		newnodo=head;
		while(newnodo!=NULL&&newnodo->elem<=n){
			if(newnodo->elem==n){
				return true;
			}
			newnodo=newnodo->next;
		}
		return false;
	}
	
	void insert(int n){
		if(esta(n)==false){
			Nodo* newnodo = new Nodo(n);
			Nodo* a1=head;
			Nodo* a2=NULL; 
			while((a1!=NULL)&&(a1->elem<n)){
				a2=a1;
				a1=a1->next;
			}
			if(head==a1){
				head = newnodo;
			}
			else{
				a2->next=newnodo;
			}
			newnodo->next=a1;
			this->size++;
		}
	}
	void remove(int n){
		if(head!=NULL){
			Nodo *buscado;
			buscado=head;
			Nodo *a1=NULL;
			while(buscado->elem!=n && buscado!=NULL){
				a1=buscado;
				buscado=buscado->next;
			}
			if(buscado==NULL){
				std::cout<<"No existe el elemento en la lista";
				return;
			}
			else if(a1==NULL){
				head=head->next;
				delete buscado;
			}
			else{
				a1->next=buscado->next;
				delete buscado;
			}
			this->size--;
		}
	}
	void print(){
		Nodo *actual=new Nodo();
		actual=head;
		for(int i=0;i<size;i++){
			std::cout<<actual->elem<<" ";
			actual=actual->next;
		}
		std::cout<<"\n";
	}
	*/
};
int main(){
	int A[]={2,6,3,1,8};
	Linkedlist <int>B(A,5);
	
	return 0;
}
//link: https://github.com/EdgarEspinozaPE/Laboratorios
