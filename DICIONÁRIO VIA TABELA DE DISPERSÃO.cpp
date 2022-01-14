
#include <new>

using std::nothrow;


template <typename TC, typename TV, int h (TC,int) >
struct DicioDisp
  {

   struct Noh { TC chave;  TV valor;  Noh *prox; };

   Noh **T, sent;  
                  
   int m, n;       

   // --------------------------------------------------------------------------
   
   bool redimensionar(int novo_m){
   	Noh **u=new(nothrow) Noh*[novo_m];
   	if(u==nullptr)return true;
   	for(int i=0;i<novo_m;++i)u[i]=&sent;
   	
   	for(int i=0;i<m;++i){
   		if(T[i]!=&sent){
   			Noh *p=T[i];
   			Noh *nv;
   			for(;p!=&sent;p=nv){
   				nv=p->prox;
   				int j=h(p->chave,novo_m);
   				p->prox=u[j];
   				u[j]=p;
			   }
		   }
		   T[i]=nullptr;
	   }
	delete T;
	T=u;
	m=novo_m;
	
	return false;
   }

   bool iniciar ()
     {

       T=new(nothrow) Noh*[2];
       if(T==nullptr)return true;
       m=2;n=0;
       for(int i=0;i<m;++i)T[i]=&sent;
       
       return false;
     }

   //  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

   struct TBusca { bool existe;  TV valor; };

   TBusca procurar (TC chv)
     {

       int a=h(chv,m);
       TBusca tb;tb.existe=false;
       if(a<m){
       	for(Noh *nv=T[a];nv!=&sent;nv=nv->prox){
		   if(nv->chave==chv){
		   	tb.existe=true;
			tb.valor=nv->valor;
		   	return tb;
		   }
		}
	   }
       return tb;
       
     }

   //  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

   bool inserir (TC chv, TV val) 
     {

       if(n==m){
       	bool erro=redimensionar(m*2);if(erro)return erro; // Redimensionar tem que realocar as chaves existentes
	   }
       int i=h(chv,m);
       Noh *nv=new(nothrow) Noh;
       
       nv->chave=chv;nv->valor=val;
       nv->prox=T[i];T[i]=nv;++n;
       
       return false;
     }

   bool remover (TC chv)
     {
    	
    	int i=h(chv,m);
    	if(T[i]->chave==chv){
    		Noh *nv=T[i];T[i]=nv->prox;delete nv;--n;
		}else{
			
			for(Noh *nv=T[i];nv->prox!=&sent;nv=nv->prox){
    			if(nv->prox->chave==chv){
    				Noh *aux=nv->prox;nv->prox=aux->prox;delete aux;--n;break;
				}
			}
			
		}
		
		if(n*4<=m && m>2){bool erro=redimensionar(m/2);if(erro)return erro;}
		
		return false;
     }

   void desaloc(int i){
   	Noh *f=T[i];
   	for(Noh *aux=f;f!=&sent;aux=f){
   		f=f->prox;delete aux;
	   }
	   T[i]=nullptr;
   }
	

   void terminar ()
     {
       for(int i=0;i<m;++i){
       	desaloc(i);
	   }
	   delete[] T;n=0;
     }
     
     /*
     void printar(){
     	for(int i=0;i<m;++i){
     		std::cout<<"Chave: "<<i<<"\n";
     		for(Noh *n=T[i];n!=&sent;n=n->prox)std::cout<<n->valor<<" ";
     		std::cout<<"\n";
     		std::cout<<"---------------------------------\n";
		 }
	 }
	 */
  }; 

int metodo_da_divisao(int e,int m){
	return e%m;
}
/*
int main(){
	DicioDisp<int,double,metodo_da_divisao> d;
	if(!d.iniciar())std::cout<<"INICIANDO...\n";
	d.inserir(1,0.1);
	d.inserir(2,0.2);
	d.inserir(3,0.3);
	d.inserir(11,0.4);
	d.inserir(5,0.5);
	d.inserir(8,0.8);
	d.inserir(9,0.9);
	d.inserir(43,4.3);
	d.inserir(17,1.7);
	d.remover(1);
	d.remover(2);
	d.remover(3);
	d.remover(11);
	d.remover(5);
	d.printar();
}
*/
// -----------------------------------------------------------------------------
