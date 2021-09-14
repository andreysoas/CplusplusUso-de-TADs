#include<iostream>
#include<new>

using std::cout;
using std::nothrow;

template<typename T>
struct deque{
	struct noh{T elem;noh *ant,*prox;};
	noh *esq,*dir;
	
	void inicializar(){
		dir=nullptr;esq=nullptr;
	}
	
	bool vazio(){
		return dir==nullptr;
	}
	
	bool inserir_esq(T e){
		noh *u=new(nothrow) noh;
		if(u==nullptr)return true;
		u->elem=e;u->ant=nullptr;u->prox=esq;
		
		if(vazio()){
			dir=u;
		}else{
			esq->ant=u;
		}
		esq=u;
		
		return false;
	}
	
	bool inserir_dir(T e){
		noh *u=new(nothrow) noh;
		if(u==nullptr)return true;
		u->elem=e;u->prox=nullptr;u->ant=dir;
		
		if(vazio()){
			esq=u;
		}else{
			dir->prox=u;
		}
		dir=u;
		
		return false;
	}
	
	void remover_esq(){
		if(!vazio()){
			noh *n=esq;
			esq=esq->prox;
			if(esq==nullptr)dir=nullptr;
			delete n;
		}	
	}
	
	void remover_dir(){
		if(!vazio()){
			noh *n=dir;
			dir=dir->ant;
			delete n;
		}
	}
	
	void destruir(){
		for(noh *n=dir;n!=nullptr;n=dir){
			dir=dir->ant;delete n;
		}
	}
	
	void printar(){
		for(noh *n=esq;n!=nullptr;n=n->prox){
			cout<<n->elem<<', ';
		}
	}
	
};

int main(){
	deque<int> d;
	d.inicializar();
	d.inserir_dir(1);
	d.inserir_esq(2);
	d.inserir_esq(3);
	d.inserir_dir(4);
}
