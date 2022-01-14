#include<iostream>
#include<new>
//NOHS SÓ SÃO ALOCADOS QUANDO OCORRER UMA DESALOCAÇÃO
using std::cout;
using std::nothrow;

struct SimulAloc{
	struct Noh{int ini,tam; Noh *prox;};
	Noh *prim; 
	
	bool vazio(){
		return prim==nullptr;
	}
	
	bool inicializar(int ini, int tam){
		Noh *n=new(nothrow) Noh;
		if(n==nullptr)return true;
		n->ini=ini;n->tam=tam;n->prox=nullptr;
		prim=n;
		return false;
	}
	
	int alocar(int tam){
		Noh *n=prim;int inicio=-1;
		if(prim->tam >= tam){
			
			inicio=prim->tam + prim->ini - tam;
			prim->tam=prim->tam - tam;
			if(prim->tam == 0){//se toda a memoria for usada
				prim=prim->prox;
				delete n;
			}
		}else{
			
			for(;n->prox!=nullptr;n=n->prox){
				
				if(n->prox->tam >= tam){
				inicio=n->prox->tam+n->prox->ini - tam;
				n->prox->tam=n->prox->tam-tam;
				if(n->prox->tam==0){//se toda memória for usada
					Noh *u=n->prox;
					n->prox=n->prox->prox;
					delete u;
				}
					break;
				}
				
			}
		}
		
		return inicio;
	}

	bool desalocar(int ini,int tam){
	Noh *n=prim;
	if(vazio()){
		Noh *u=new(nothrow) Noh;
		if(u==nullptr)return true;
		u->ini=ini;u->tam=tam;u->prox=nullptr;
		prim=u;
	}else{
	for(;n!=nullptr;n=n->prox){              
		if(ini+tam <= n->ini){//tá atrás
			if(ini+tam < n->ini){
				Noh *u=new(nothrow) Noh;if(u==nullptr)return true;
				u->ini=ini;u->tam=tam;u->prox=n;
				if(n==prim)prim=u;
			}else{//é igual - vai emendar
				n->ini=ini;n->tam=n->tam + tam;
			}
			
		}else if(ini>=n->ini+n->tam){//tá colado em sequência
			if(ini > n->ini+n->tam){
				if(n->prox!=nullptr){
					if(ini+tam==n->prox->ini){
						// COLOCA NO n->prox
						n->prox->ini=ini;n->prox->tam=n->prox->tam+tam;
					}else if(ini+tam < n->prox->ini){
						Noh *u=new(nothrow) Noh;if(u==nullptr)return true;
						u->ini=ini;u->tam=tam;u->prox=n->prox;n->prox=u;
					}else{
						continue; //se passar daqui, então não chega no primeiro if
					}
				}else{
					Noh *u=new(nothrow) Noh;if(u==nullptr)return true;
					u->ini=ini;u->tam=tam;u->prox=n->prox;n->prox=u;
				}
			}else{
				if(n->prox!=nullptr){					//VOU EMENDAR, mas checar o próximo
					if(ini+tam==n->prox->ini){
						//n e prox viram um noh
						Noh *u=n->prox;
						n->tam=n->tam+tam+n->prox->tam;
						n->prox=u->prox;
						delete u;
					}else if(ini+tam < n->prox->ini){
						//MUDAR O n
						n->tam=n->tam+tam;
					}
				}else{
					n->tam=n->tam+tam;
				}
			
			}
		}
	break;
	}
	}
	return false;
	}


	void terminar(){
		for(Noh *n=prim;n!=nullptr;){
			n=n->prox;delete prim;prim=n;
		}
	}
	
		void printar(){
		for(Noh *n=prim;n!=nullptr;n=n->prox){
			cout<<"["<<n->ini<<" , "<<n->tam<<"]";
			if(n->prox==nullptr){
			cout<<"-> //";
			}else {
			cout<<"-> ";
			}
		}
		}
};
/*	
	
	void printar(){
		for(Noh *n=prim;n!=nullptr;n=n->prox){
			cout<<"["<<n->ini<<" , "<<n->tam<<"] -> ";
		}
	}
*/

/*
int main(){
	SimulAloc s;
	s.inicializar(100,150);
	s.alocar(50);
	s.desalocar(200,50);
	s.alocar(50);
	s.alocar(50);
	s.desalocar(200,50);
	s.desalocar(80,20);
	s.desalocar(160,20);
	s.desalocar(260,20);
	s.alocar(30);
	s.alocar(50);
	s.desalocar(200,50);
	s.alocar(40);
	s.printar();
	//s.terminar();
	//s.printar();
}
*/
