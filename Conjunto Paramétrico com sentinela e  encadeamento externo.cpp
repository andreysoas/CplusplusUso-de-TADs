#include<iostream>
#include<new>
using std::cout;
using std::nothrow;
//ENCADEAMENTO EXTERNO
template<typename T, int f(int e, int m)> //parametrização de funções
struct ConjTD{
	
	private:
	struct Noh{T elem; Noh *prox;};
	Noh **v; int m,n; //Ponteiro para ponteiro para Noh
	Noh *sentinel;
	
	public:
		
	bool inicializar(){
		m=1;n=0;
		
		v=new(nothrow) Noh*[m]; //inicializa a tabela
		if(v==nullptr)return true;
		sentinel=new(nothrow) Noh;	//inicializa a sentinela
		if(sentinel==nullptr){delete[] v;return true;}//se der problema na alocação da sentinela -> desaloca o vetor anterior
		
		for(int i=0;i<m;++i)v[i]=sentinel;
		
		return false;
	}
		
	bool pertence(T e){
		int i = f(e,m);
		sentinel->elem = e;
		Noh *n=v[i];
		while(n->elem!=e){
			n=n->prox;
		}
		return n!=sentinel;
	}
	
	bool redimensionar(int novo_m){
		//REAPONTAR OS PONTEIROS
	}
	
	bool inserir(T e){
		if(n==m){bool erro=redimensionar(m*2); if(erro)return true;}
		
		int i=f(e,m);//aplicação da função de hash
		Noh *n=new(nothrow) Noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=v[i];v[i] = n;
		return false;
	}
	//rever
	bool remover(T e){
		int i=f(e,m);
		Noh *n=v[i];
		if(n->elem)
		for(;n!=sentinela;n=n->prox){
			if(n->elem==e)
		}
	}
	
};

int f(int e, int m){ //função que será enviada como parâmetro
	return e%m;
}

int main(){ //MEXER DEPOIS NA IMPLEMENTAÇÃO
	ConjTD<int,f> c; //Passa o tipo T e a função esperada do template
	c.inicializar();
	c.inserir(1);k
	c.inserir(2);
	if(c.pertence(2))cout<<"oloko";
}
