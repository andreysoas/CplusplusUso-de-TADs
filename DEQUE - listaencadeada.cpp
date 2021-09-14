#include<iostream>
#include<new>

using std::nothrow;
using std::cout;

template<typename T>
struct deque{
	struct noh{noh *ant,*prox;T elem;};
	noh *esq;
	noh *dir;
	
	void inicializar(){
		esq=dir=nullptr;
	}
	
	bool vazio(){
		return (esq==nullptr) && (dir==nullptr);
	}
	
	T consultar_esq(){//deque não vazio
		return esq->elem;
	}
	
	T consultar_dir(){
		return dir->elem;
	}
	
	bool inserir_esq(T e){
		noh* n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->ant=nullptr;n->elem=e;n->prox=esq;
		
		if(vazio()){
		//	n->prox=nullptr;
			dir=n;	
		}else{
		//	n->prox=esq; Isso poderia estar aqui, mas se tiver vazio, então esq==nullptr, funciona pros dois casos
			esq->ant=n;
		}
		esq=n;
		return false;
	}
	
	bool inserir_dir(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->prox=nullptr;n->elem=e;n->ant=dir; //ANÁLOGO DE ESQ
		
		if(vazio()){
			esq=n;
		}else{
			dir->prox=n;
		}
		dir=n;
		return false;
	}
	
	void remover_esq(){//deque não-vazio
		noh *n=esq;esq=esq->prox;
		if(esq==nullptr){
			dir=nullptr;
		}else{
			esq->ant=nullptr;
		}
		delete n;
	}
	
	void remover_dir(){
		noh *n=dir; dir=dir->ant;
		if(dir==nullptr){
			esq=nullptr;
		}else{
			dir->prox=nullptr;
		}
		delete n;
	}
	
	void printar(){
		noh *n=esq;
		for(;;){
			if(n==nullptr)break;
			cout<<"- "<<n->elem<<'\n';
			n=n->prox;
		}
	}
};

template<typename T>
struct deque{
	struct noh{T elem;noh *ant,*prox;};
	noh *esq;noh *dir;
	
	void inicializar(){
		esq=nullptr;
		dir=nullptr;
	}
	
	bool vazia(){
		return esq==nullptr && dir==nullptr;
	}
	
	bool inserir_esq(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=esq;n->ant=nullptr;
		if(vazia()){
			dir=n;
		}else{
			esq->ant=n;
		}
		esq=n;
		return false;
	}
	
	bool inserir_dir(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->ant=dir;n->prox=nullptr;
		if(vazia()){
			esq=n;
		}else{
			dir->prox=n;
		}
		dir=n;
		return false;
	}
	
	void remover_esq(){
		noh *n=esq;
		esq=esq->prox;
		if(esq==nullptr){
			dir=nullptr;
		}else{
			esq->ant=nullptr;
		}
		delete n;
	}
	
	void remover_dir(){
		noh *n=dir;
		dir=dir->ant;
		if(dir==nullptr){
			esq=nullptr;
		}else{
			dir->prox=nullptr;
		}
		delete n;
	}
	
	T consultar_esq(){
		return esq->elem;
	}
	
	T consultar_dir(){
		return dir->elem;
	}
};



int main(){
	deque<int> d;
	d.inicializar();
	d.inserir_dir(1);
	d.inserir_esq(2);
	d.inserir_dir(4);
	d.remover_dir();
	d.inserir_esq(3);
	d.remover_dir();
	d.remover_dir();
	d.remover_dir();
	d.inserir_dir(1);
	d.printar();
}
