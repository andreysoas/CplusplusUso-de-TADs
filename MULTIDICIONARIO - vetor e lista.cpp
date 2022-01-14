#include <new>

using std::nothrow;



template <typename TC, typename TV> // TC: Tipo das Chaves. TV: Tipo dos Valores
struct Multidicionario
  {

   // --------------------------------------------------------------------------

    struct noh{
       	TV valor;noh *prox;
	};

   struct Multiconjunto
     {

       TC chv_conj;noh *prim=nullptr;

      struct Iterador  // Relativo ao Multiconjunto, nÃ£o ao Multidicionario.
        {

	 noh *p;
			
         bool operator == (Iterador i)
           {
             return p==i.p;
           }

         bool operator != (Iterador i)
           {
             return p!=i.p;
           }

         TV operator * ()
           {
             return p->valor;
           }

         void operator ++ ()
           {
             p=p->prox;
           }

        };  


      Iterador inicio ()//v[i].inicio();
        {
          Iterador it;
          it.p=prim;
          return it;
        }

      Iterador fim ()
        {
          Iterador it;
          it.p=nullptr;
          return it;
        }

     };  

   
   Multiconjunto *v;int n,tam; //vetor de multiconjuntos

   void deletar(noh *n){
   	for(noh *aux=n;n!=nullptr;aux=n){
   		n=n->prox;delete aux;
	}
   }
   
   bool redimensionar(int novo_tam){
   	
   	Multiconjunto *u=new(nothrow) Multiconjunto[novo_tam];
   	if(u==nullptr)return true;
   	for(int i=0;i<n;++i){
   		u[i]=v[i];
	}
	delete[] v;
	v=u;
   	tam=novo_tam;
   	return false;
   	
   }
   
   bool inicializar ()
     {

       v=new(nothrow) Multiconjunto[1];
       if(v==nullptr)return true;
       tam=1;n=0;
       return false;
     }

   Multiconjunto procurar (TC chv)
     {

       for(int i=0;i<n;++i){
       	if(v[i].chv_conj==chv)return v[i];
	   }
	   
	   Multiconjunto m;
	   return m;
     }

   bool inserir (TC chv, TV val)
     {
       
	   noh *novo=new(nothrow) noh;
	   if(novo==nullptr)return true;
       novo->valor=val;
       // --------------------------------------------
	   for(int i=0;i<n;++i){
    	   if(v[i].chv_conj==chv){
		   	novo->prox=v[i].prim;v[i].prim=novo;return false;
		   }//A CHAVE EXISTE
	   }
	   //-----------------------------------------------
	   if(n==tam){bool erro=redimensionar(tam*2);if(erro)return erro;}
	   Multiconjunto m;m.chv_conj=chv;
	   v[n]=m;novo->prox=v[n].prim;v[n].prim=novo;
	   ++n;
	   
	   return false;
     }

   bool remover (TC chv)
     {

       for(int i=0;i<n;++i){
       	if(v[i].chv_conj==chv){
		   deletar(v[i].prim);v[i]=v[n-1];--n;
		   if(tam>1 && n*4<=tam){bool erro=redimensionar(tam/2);return erro;}
		   return false;
		   } //chama função para desalocar a lista
	   }
	   
	   return false;
     }

   void terminar ()
     {
       for(int i=0;i<n;++i){
       	deletar(v[i].prim);
	   }
       
       delete v;
     }

  };  // struct Multidicionario ------------------------------------------------


// ----------------------------------------------------------------------------- */
