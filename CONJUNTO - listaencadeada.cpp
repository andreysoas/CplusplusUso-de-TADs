#include<iostream>
#include<new>

using std::cout;
using std::nothrow;

template<typename T>
struct Conjunto{
	private:
	struct noh{noh *prox;T elem;};
	noh *prim,ult; //Pode implementar como pilha
	
	public:
	void iniciar(){
		prim=nullptr;
	}
	
	bool vazio(){
		return prim==nullptr;
	}
	
	/*
	bool inserir(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=nullptr;
		
		if(vazio()){
			prim=n;
		}else{
			ult->prox=n;
		}
		
		ult=n;
		return false;
	}
	*/
		
	bool inserir(T e){//INSERÇÃO TAL QUAL A PILHA
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=prim;
		prim=n;
		return false;
	}
	
	bool pertence(T e){
		for(noh *n=prim;n!=nullptr;n=n->prox){
			if(n->elem=e)return true;
		}
		return false;
	}
	
	bool inserir_testando(T e){
		if(pertence(e))return false;
		return inserir(e);
	}
	
	void remover(T e){ //Vamos olhar sempre pro próximo
		if(vazio())return; //não faz nada
		noh *n=prim;
		if(prim->elem==e){ //se tá no primeiro
			delete n;
			prim=prim->prox;
		}else{
			for(;n->prox!=nullptr;n=n->prox)
			if((n->prox)->elem==e){
				noh *p=n->prox;
				n->prox=p->prox;
				delete p;
			}
		}	
	}
	
	void terminar(){
		for(noh *p,*n=prim;n!=nullptr;n=p){
			p=n->prox; delete n;
		}
		
	}
};

template<typename T>
struct conjunto{
	struct noh{T elem;noh *prox;};
	noh *prim;
	
	void inicializar(){
		prim==nullptr;
	}
	
	bool pertence(T e){
		for(noh *n=prim;n!=nullptr;n=n>prox){
			if(n->elem==e)return true;
		}
		return false;
	}
	
	bool inserir(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=prim;
		prim=n;
		return false;
	}
	
	void remover(T e){
		noh *n=prim;
		if(prim->elem==e){
			prim=n->prox;
		}else{
			for(;n->prox!=nullptr;n=n->prox){
				if(n->prox->elem==e){
					noh *aux=n;
					n=aux->prox;
					aux->prox=n->prox;
				}
			}
		}
		delete n;
	}
};






