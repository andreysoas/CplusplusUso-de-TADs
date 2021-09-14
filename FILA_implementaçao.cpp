#include<iostream>
#include<new>
using std::cout;
using std::cin;
using std::nothrow;

template<typename T>
struct fila{
	T *v;
	int ini;
	int fim;
	int tam;
	
	bool inicializar(){
		tam=1;
		v=new(nothrow) T[tam];
		if(v==nullptr)return true;
		ini=-1;
		fim=-1;
		return false;
	}
	
	bool enfilar(T e){
		if(vazia()){
			ini=0;
		}else{
			if(fim==ini-1 || (fim+1)%tam==ini){//segunda checagem é interessante
				tam=tam*2;
				T *u=new(nothrow) T[tam];
				if(u==nullptr)return true;
				for(int i=0;;++i){
					u[i]=v[ini];
					if(ini==fim){
						fim=i; //fim vai ser o numero de iterações
						break;
					}
					++ini;
					if(ini==tam)ini=0;	
				}
				delete[] v;
				v=u;
				ini=0;
			} 
		}
		//EXECUTE FINAL
		++fim;v[fim]=e;
		return false;
	}
	
	bool desenfilar(){
		++ini;
		if(ini==fim+1){//fila vazia
			ini=fim=-1;
		}else if(ini==tam){
			ini=0;
		}
		if(ini<=fim){
			double n = fim-ini+1;
			if(n/tam<=0.25){
				tam=tam/2;
				T *u=new(nothrow) T[tam];
				if(u==nullptr)return true;
				int total_elementos=n;
				for(int i=0;i<total_elementos;++i){
					u[i]=v[ini];
					++ini;
				}
				
				delete[] v;
				v=u;
				ini=0;fim=total_elementos-1;
			}
		}else if(ini>fim){
			double n = tam - ini + (fim+1);
			if(n/tam<=0.25){
				tam=tam/2;
				T *u=new(nothrow) T[tam];
				if(u==nullptr)return true;
				int total_elementos=n;
				for(int i=0;i<total_elementos;++i){
					if(ini==tam)ini=0;
					u[i]=v[ini];
					++ini;
				}
				
				delete[] v;
				v=u;
				ini=0;fim=total_elementos-1;
			}
		}
		
		return false;
	}
	
	bool vazia(){
		return ini==-1;
	}
	
	void terminar(){
		delete[] v;
	}
	
	void printar(){
		if(vazia()){
			cout<<"Fila vazia";
		}else if(ini<=fim){
			for(int i=ini;;){
				cout<<v[i]<<"\n";
				if(i==fim)break;
				++i;
			}
		}else{
			for(int i=ini;;){
				if(i==tam)i=0;
				cout<<v[i]<<"\n";
				if(i==fim)break;
				++i;
			}
		}
	}
	
	void print(){
		for(int i=0;i<tam;++i){
			cout<<v[i]<<"aqui\n";
		}
	}
};
/*
int main(){
	fila<int> f;
	f.inicializar();
	f.enfilar(1);
	f.desenfilar();
	f.printar();	
}
*/
