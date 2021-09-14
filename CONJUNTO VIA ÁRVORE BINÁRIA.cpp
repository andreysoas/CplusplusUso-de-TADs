#include<iostream>
#include<new>
using std::nothrow;
using std::cout;

template<typename T>
struct ConjAB{
	struct noh{T elem;noh *esq,*dir;};
	noh *raiz;int i=0;
	
	void inicializar(){
		raiz = nullptr;
	}
	
	bool vazio(){return raiz==nullptr;}
	
	bool inserir(T e){                 //pré-cond "e" não está no conjunto.
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->esq=n->dir=nullptr;  //PREENCHIMENTO DO NOH
		
		if(vazio()){
			raiz=n;
		}else{
			noh *p=raiz;
			
			for(;;){
				if(n->elem < p->elem){
					if(p->esq == nullptr){p->esq=n;break;}
					else				 {p=p->esq;}
				}else{
					if(p->dir == nullptr){p->dir=n;break;}
					else                 {p=p->dir;}
				}
			}
		}
		return false;
	}
	
	bool pertence(T e){
		if(!vazio()){
			noh *n=raiz;
			
			while(n!=nullptr){
				if(n->elem=e){return true;}
				else{
					if(e<n->elem){n=n->esq;}
					else		 {n=n->dir;}
				}	
			}
		}
		
		return false;
	}
	
	bool remover(T e){
		
	}
	
	bool terminar(){                         //PÓS-ORDEM
		//while(!vazio())remover(raiz->elem);
		desalocar(raiz);
	}
	

	void imprimir(noh *n){					//EM ORDEM						IMPRIME EM ORDEM
	if(n!=nullptr){imprimir(n->esq);cout<<n->elem<<'\n';imprimir(n->dir);}
	}
	
										//n = Raíz 		//função que chama a função recursiva
	void imprimir_profundidades(){imp_rec(raiz,1);} //total de nohs no caminho, incluindo as extremidades.
	
	void imp_rec(noh *n, int prof_n){ //recebe o ponteiro do noh e a sua profundidade. //PRÉ-ORDEM
		if(n!=nullptr){				  //Se não for nulo -> imprime a profundidade.
			cout<<n->elem<<": "<<prof_n<<'\n';
			
			imp_rec(n->esq, prof_n+1);
			imp_rec(n->dir, prof_n+1);
		}
	}
	
	//void imprimir_alturas(){alt_rec(T n);} //total de níveis da base até o noh em questão, incluindo extremidades.
	
	int alt_rec(noh *n){       	//descobrir a altura dos dois filhos, decidir qual a maior e adicionar 1
		if(n==nullptr)return 0; 
		
		int ae = alt_rec(n->esq);
		int ad = alt_rec(n->dir);
		
		int an;
		
		if( ae >= ad)an =  ae+1;
		else		 an =  ad+1;
		
		cout<<n->elem<<': '<<an<<'\n'; return an;
	}
	
	private:
	void desalocar(noh *n){ //envio a raíz
		if(n!=nullptr){desalocar(n->esq);desalocar(n->dir);delete n;} //REVER OS CÓDIGOS RECURSIVOS
	}
};







/*

void terminar(){			//função pública
	desalocar(raiz);
}


void desalocar(noh *n){
	if(n!=nullptr){
		desalocar(n->esq);desalocar(n->dir);delete n;
	}
}


void print_crescente(){  //função pública
	printar(raiz);
}

void printar(noh *n){
	if(n!=nullptr){
		printar(n->esq);cout<<n->elem<<'\n'<<printar(n->dir);
	}
}

void imprimir_profundidades(){
	prof_rec(raiz,1);         //pré-cond: há pelo menos a raíz
}

void prof_rec(noh *n, int i){
	if(n!=nullptr){
		cout<<n->elem<<"\n";
		
		prof_rec(n->esq,i+1); // é mandado um contador incrementado a cada chamada
		prof_rec(n->dir,i+1);// é mandado um contador incrementado a cada chamada da função
	}
}

void imprimir_altura(){
	int a=alt_rec(raiz);
}

int alt_rec(noh *n){ //Aqui vamos contar a altura das duas sub-àrvores principais e escolher a maior
	if(n==nullptr)return 0;
	int ae = alt_rec(n->esq); //altura da sub-esquerda
	int ad = alt_rec(n->dir); //altura da sub-direita
		
	int an;					  //Retorno -> escolhendo a maior
		
	if( ae >= ad)an =  ae+1;
	else		 an =  ad+1;
		
	cout<<n->elem<<': '<<an<<'\n'; return an;
}
 */
 
int main(){
	ConjAB<int> a;
	
	int i = 1;
	
	while(true){
		std::cin>>i;
		if(i==-1)break;
		a.inserir(i);
	}
	
	a.imprimir(a.raiz);
}
