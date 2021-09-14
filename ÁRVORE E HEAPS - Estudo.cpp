#include<iostream>
#include<new>

using std::nothrow;
using std::cout;

// ALGORITMOS 

template<typename T>
int busca_binaria(T *v,int n,T e){
	int a=0;int b=n-1;
	
	while(a<=b){
		int meio=a+(b-a)/2;
		
		if(v[meio]==e)return meio;
		
		if(e<v[meio])b=meio-1;
		else 		 a=meio+1;
	}
	
	return -1;
}

template<typename T>
void descer(T *v,int n, int i){
	for(;;){
		int f_esq=2*i + 1; if(f_esq>=n)break;
		
		int f_dir=f_esq+1;
		
		int max;
		
		if(f_dir<n && v[f_dir]>v[f_esq])max=f_dir;
		else						    max=f_esq;
		
		if(v[i]>=v[max])break;
		
		T troca=v[i];v[i]=v[max];v[max]=troca;i=max;
	}
}

template<typename T>
void heapsort(T *v,int n){
	for(int i=n-1;i>=0;--i){  //primeiro: APLICAR A DESCIDA
		descer(v,n,(i-1)/2);
	}
	
	while(n>1){
		T e=v[0];v[0]=v[n-1];--n;descer(v,n,0);v[n]=e;
	}
}


/*
int main(){
	int v[20]={10,2,3,7,9,6,4,8,5,1,18,15,13,11,12,20,17,14,16,19};
	
	heapsort(v,20);
	
	int indice=busca_binaria(v,20,17);
	std::cout<<"indice: "<<indice<<'\n';
	
	for(int i=0;i<20;++i){
		std::cout<<v[i]<<' ';
	}
}

*/
///////////////////////////////////////////////////////////////////////////
//                             ÁRVORE                                   //
/////////////////////////////////////////////////////////////////////////

template<typename T>
struct conjAB{
	struct noh{
		noh *esq,*dir; T elem;
	};
	
	noh *raiz;
	
	void inicializar(){
		raiz=nullptr;
	}
	
	bool vazio(){
		return raiz==nullptr;
	}
	
	bool inserir(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->esq=n->dir=nullptr;
		
		if(vazio()){
			raiz=n;
		}else{
			noh *aux=raiz;
			for(;;){
				if(e<aux->elem){
					if(aux->esq==nullptr){aux->esq=n;break;}
					else				  aux=aux->esq;
				}else{//maior
					if(aux->dir==nullptr){aux->dir=n;break;}
					else 				  aux=aux->dir;
				}
			}
			
		}
		return false;
	}
	
	bool pertence(T e){
		
		for(noh *n=raiz;n!=nullptr;){
			if(n->elem==e)return true;
			
			if(e<n->elem)n=n->esq;
			else	 	 n=n->dir;
		}
		
		return false;
	}
	
//------------------------------RECURSIVAS-------------------------------------
	
	void terminar(){
		terminar_rec(raiz);	
	}
	
	void terminar_rec(noh *n){
		if(n!=nullptr){
			terminar_rec(n->esq);terminar_rec(n->dir);delete n;
		}
	}
	
	//-------------------------------------------------------------------------
	
	void altura(){
		cout<<"Altura: "<<altura_rec(raiz);
	}
	
	int altura_rec(noh *n){
		if(n==nullptr)return 0;
		
		int ae=altura_rec(n->esq);
		int ad=altura_rec(n->dir);
		
		int an;
		
		if(ae>=ad)an=ae+1;
		else	  an=ad+1;
		
		return an;
	}
	
	//--------------------------------------------------------------------------
	
	void profundidades(){
		prof_rec(raiz,1);
	}
	
	void prof_rec(noh *n, int i){
		if(n!=nullptr){
			prof_rec(n->esq,i+1);
			prof_rec(n->dir,i+1);
			
			cout<<"Noh: "<<n->elem<<", Profundidade: "<<i<<'\n';	
		}
		
	}
	
	//---------------------------------------------------------------------------
	
	void imprimir(){
		imprimir_rec(raiz);
	}
	
	void imprimir_rec(noh *n){
		if(n!=nullptr){
			imprimir_rec(n->dir);cout<<n->elem<<' ';imprimir_rec(n->esq);
		}
	}
};

struct Monte{
	double *v; int n;
};

void decrescente(conjAB<double>::noh *n,Monte &M){
	if(n!=nullptr){
		decrescente(n->dir,M);M.v[M.n]=n->elem;++M.n;decrescente(n->esq,M);
	}
}

bool criar_monte(conjAB<double>::noh *raiz,Monte &M){
	M.v=new(nothrow) double[M.n];
	if(M.v=nullptr)return true;
	for(int i=0;i<M.n;++i)M.v[i]=1;
	//int guard=M.n;
	//decrescente(raiz,M);
	//M.n=guard;
	//cout<<"blz";
	for(int i=0;i<M.n;++i)cout<<M.v[i]<<' ';
	return false;
}

int main(){
	conjAB<double> c;
	
	c.inicializar();
	c.inserir(20);
	c.inserir(10);
	c.inserir(21);
	c.inserir(8);
	c.inserir(11);
	c.inserir(7);
	c.inserir(9);
	c.inserir(15);
	c.inserir(13);
	c.inserir(14);
	c.inserir(25);
	c.inserir(22);
	c.inserir(27);
	c.inserir(26);
	Monte m;
	m.n=14;
	m;
	
	if(criar_monte(c.raiz,m))cout<<"wtf";
}


/*
template<typename T>
int busca_binaria(T *v,int n,T e){
	int a=0,b=n-1;
	
	while(a<=b){
		int meio=a+(b-a)/2;
		
		if(v[meio]==e)return meio;
		
		if(e<v[meio])b=meio-1;
		else		 a=meio+1;
	}
	return -1;
}


template<typename T>
void descer(T *v,int n,int i){
	for(;;){
		int esq=2*i +1;if(esq>=n)break;
		
		int dir=esq+1;
		
		int max;
		
		if(dir<n && v[dir]>v[esq])max=dir;
		else					  max=esq;
		
		if(v[i]>=v[max])break;
		
		int troca=v[i];v[i]=v[max];v[max]=troca;i=max;
	}
	
}

template<typename T>
void heapsort(T *v,int n){
	for(int i=(n-1-1)/2;i>=0;--i){
		descer(v,n,i);
	}
	
	while(n>1){
		T e=v[0];v[0]=v[n-1];--n;descer(v,n,0);v[n]=e;
	}
}

int main(){
	int v[20]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	heapsort(v,20);
	
	for(int i=0;i<20;++i){
		cout<<v[i]<<" ";
	}
	
	cout<<"\nINDICE DO ELEMENTO 16:"<<busca_binaria(v,20,16);
}
*/












