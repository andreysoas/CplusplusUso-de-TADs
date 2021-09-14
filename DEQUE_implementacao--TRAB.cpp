#include<iostream>
#include<new>
using std::nothrow;
using std::cout;
using std::cin;

//REVER AS C�PIAS DOS ELEMENTOS, PARA ELES SEREM COPIADOS NA ORDEM CERTA

template<typename T>
struct Deque{
	T *v;
	int dir,esq,tam;
	};
	
	 template <typename T> bool inicializar(Deque<T> &D){
		D.tam=1;
		D.v=new(nothrow) T[D.tam];
		if(D.v==nullptr)return true;
		D.dir=D.esq=-1;
		return false;
	}
	
	 template <typename T> bool vazio(Deque<T> &D){
		return D.dir==-1 && D.esq==-1;
	}
	
	 template <typename T> bool inserir_esq(Deque<T> &D,T e){
		if(vazio(D)){
			D.esq=1;D.dir=0;
		}else{
			if(D.esq==0){ //CASO EM QUE ESQ<=DIR
				if(D.dir==D.tam-1){// ELEMENTOS NO MEIO DO VETOR
				//realocar
				D.tam=D.tam*2;
				T *u = new(nothrow) T[D.tam];
				for(int i=0;D.esq<=D.dir;++i){
					u[i]=D.v[D.esq];
					++D.esq;	
				}
				delete[] D.v;
				D.v=u;
				D.esq=D.tam;
				//dir=dir;
				}else{//ent�o tem espa�o do outro lado do vetor
					D.esq=D.tam;			
				}
			}else if(D.esq==D.dir+1){//CASO EM QUE ESQ>DIR
				//realocar
				D.tam=D.tam*2;
				T *u = new(nothrow) T[D.tam];
				for(int i=0;;++i){
					u[i]=D.v[D.esq];
					if(D.esq==D.dir)break;
					++D.esq;
					if(D.esq==D.tam/2)D.esq=0; //tam/2 pq j� modifiquei tam
				}
				delete[] D.v;
				D.v=u;
				D.esq=D.tam;
				D.dir=D.tam/2 -1;
			}
		}
		--D.esq;//passar pro lado de l�
		D.v[D.esq]=e;
		return false;
	}
	
	 template <typename T> bool inserir_dir(Deque<T> &D, T e){
		if(vazio(D)){
			D.esq=0;
		}else{
			if(D.dir==D.tam-1){//CASO EM QUE DIR>ESQ
				if(D.esq==0){//SE T� CHEIO
				//realocar
				D.tam=D.tam*2;
				T *u = new(nothrow) T[D.tam];
				for(int i=0;D.esq<=D.dir;++i){        //rever a c�pia
					u[i]=D.v[D.esq];
					++D.esq;
				}
				delete[] D.v;
				D.v=u;
				D.esq=0;
				//dir=dir;
				}else{
					D.dir=-1;			
				}
			}else if(D.dir==D.esq-1){               //rever a c�pia
				//realocar
				D.tam=D.tam*2;
				T *u = new(nothrow) T[D.tam];
				for(int i=0;;++i){
					u[i]=D.v[D.esq];
					if(D.dir==D.esq)break;
					++D.esq;
					if(D.esq==D.tam/2)D.esq=0;
				}
				delete[] D.v;
				D.v=u;
				D.esq=0;
				D.dir=D.tam/2 -1;
			}
		}
		++D.dir;
		D.v[D.dir]=e;
		return false;
	}
	
	//------------------------------------------------------
	// N�O VAI HAVER CONTRA��O DO VETOR - RETRABALHAR ESSAS FUN��ES
	
	 template <typename T> T remover_esq(Deque<T> &D){
		T elemento=D.v[D.esq];
		++D.esq;
		if(D.esq==D.dir+1){//a fila vai ficar vazia
			D.dir=-1;D.esq=-1;
		}else if(D.esq==D.tam){
			D.esq=0;
		}
		return elemento;
	}
	
	 template <typename T> T remover_dir(Deque<T> &D){
		T elemento=D.v[D.dir];
		--D.dir;
		if(D.dir==D.esq-1){//a fila fica vazia
			D.dir=-1;D.esq=-1;
		}else if(D.dir==-1){
			D.dir=D.tam-1;
		}
		return elemento;
	}
	
	template <typename T> void terminar (Deque<T> &D){
		delete[] D.v;
	}
	
