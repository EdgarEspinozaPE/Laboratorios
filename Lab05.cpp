#include <iostream>

class Nodo{
private:
	int elem;
	Nodo* next;
	friend class Linkedlist;
public:
	Nodo(){
		this->elem=0;
		this->next=NULL;
	}
	Nodo(int elem){
		this->elem=elem;
		this->next=NULL;
	}
};
class Linkedlist{
private:
	int size;
	Nodo* head;
public:
	Linkedlist(){
		this->size=0;
		this->head=NULL;
	}
	Linkedlist(int n){
		Nodo *a1=new Nodo(n);
		this->size=1;
		this->head=a1;
	}
	Linkedlist(int n[],int size){
		Nodo *a1=new Nodo(n[0]);
		this->head=a1;
		this->size=1;
		for(int i=1;i<size;i++){
			this->insert(n[i]);
		}		
	}
	~Linkedlist(){
		Nodo *chasqueador;
		while(head!=NULL){
			chasqueador=head;
			head=chasqueador->next;
			int n=chasqueador->elem;
			delete chasqueador;
			std::cout<<n<<" borrado ";
		}
	}
	bool esta(int n){
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
};
int main(){
	int A[]={2,6,3,1,8};
	Linkedlist B(A,5);
	B.print();
	B.remove(6);
	B.print();
	B.insert(9);
	B.print();
	B.insert(3);
	B.print();
	return 0;
}
