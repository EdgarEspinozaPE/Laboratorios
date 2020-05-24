#include<iostream>
using namespace std;
class Punto{
private:
	int x;
	int y;
public:
	Punto(){
		x=0;
		y=0;
	}
	Punto(Punto &o){
		x=o.getX();
		y=o.getY();
	}
	Punto(int new_x,int new_y){
		x=new_x;
		y=new_y;
	}
	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
	void setX(const int nuevo_x){
		x=nuevo_x;
	}
	void setY(const int nuevo_y){
		y=nuevo_y;
	}
	void MostrarPunto(){
		cout<<"("<<x<<":"<<y<<") ";
	}
};
class ArreglodePuntos{
private:	
	Punto *a;
	int size;
	void redimensionar(int n){
		size=n;
		ArreglodePuntos A(*this);
		*this=A;
	}			
public:
	Punto getPunto(){
		return *a;
	}
	void MostrarArreglo(){
		for(int i=0;i<size;i++){
			a[i].MostrarPunto();
		}
		cout<<endl;
	}
	const int getSize()const{
		return this->size;	
	}
	void pushback(const Punto &o){
		redimensionar(size+1);
		a[size-1]=o;
	}
	void insert(const int posicion,const Punto &p){
		if(posicion>size-1){
			cout<<"Posicion no váilida";
			return;
		}
		redimensionar(size+1);
		for(int i=size-1;i>posicion;i--){
			a[i]=a[i-1];
		}
		a[posicion]=p;
	}
	void remove(const int posicion){
		for(int i=posicion;i<size-1;i++){
			a[i]=a[i+1];
		}
		redimensionar(size-1);
	}
	void clear(){
		delete[] a;
		redimensionar(0);
	}
	ArreglodePuntos(const Punto puntos[],const int tam){
		this->size=tam;	
		a=new Punto[size];
		for(int i=0;i<size;i++){
			a[i]=puntos[i];
		}
		
	}
	ArreglodePuntos(const ArreglodePuntos &o){
		a=new Punto[o.getSize()];
		size=o.getSize();
		for(int i=0;i<size;i++){
			a[i]=o.a[i];
		}
	}
	
	/*~ArreglodePuntos(){
		delete[] a; 
	}
	*/ 
	
};
int main(){
	Punto P,N(10,15),S(12,8),T(11,11);
	Punto puntos[]={P,N};
	cout<<P.getX()<<"\n";
	cout<<P.getY()<<"\n";
	cout<<N.getX()<<"\n";
	cout<<N.getY()<<"\n";
	ArreglodePuntos A(puntos,2);
	A.MostrarArreglo();
	A.pushback(S);
	A.MostrarArreglo();
	A.insert(2,T);
	A.MostrarArreglo();
	A.remove(0);
	A.MostrarArreglo();
	A.clear();
	A.MostrarArreglo();
	A.pushback(N);
	A.MostrarArreglo();
	return 0;
}
