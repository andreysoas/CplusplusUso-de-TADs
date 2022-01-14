
#include <new>
#include<iostream>
using std::nothrow;

// -----------------------------------------------------------------------------

template <typename TC, typename TV>
struct Dicionario
  {

   struct Noh {  TC chave;  TV valor;  Noh *ant, *prox;  };

   Noh *prim;

   struct Iterador
     {
      friend Dicionario;  

      private:
		Noh *p;
	   
      public:

      bool operator == (Iterador i)
        {

          return p==i.p;
        }

      bool operator != (Iterador i)
        {

          return p!=i.p;
        }
	   

      TC chave ()
        {
          return p->chave;
        }

      TV valor ()
        {
          return p->valor;
        }

      void operator ++ ()
        {
          p=p->prox;
        }

     }; // struct Iterador

   // --------------------------------------------------------------------------.

   void inicializar ()
     {
       prim=nullptr;
     }

   Iterador inicio ()
     {
       Iterador it;
       it.p=prim; // interpretando fim como sendo o ponteiro nulo
       return it;
	 }

   Iterador fim ()
     {
       Iterador it;
	   //while(it.p->dir!=nullptr)++it;
	   it.p=nullptr;
       return it;
     }

   Iterador procurar (TC chv)
     {
       Iterador it;
       
	   for(it=inicio();it!=fim();++it){
	   	if(it.chave()==chv)break;
	   }
       
       return it;
     }

   Iterador inserir (TC chv, TV val)
     {
       /*
       * Caso 1: A chave "chv" jÃ¡ estÃ¡ presente no dicionÃ¡rio: nesse caso, a
       *         funÃ§Ã£o deve manter o dicionÃ¡rio inalterado e retornar um
       *         iterador apontando para a chave "chv" e o valor jÃ¡
       *         correspondente a ela no dicionÃ¡rio (o qual pode ser igual a ou
       *         diferente de "val").
       *
       * Caso 2: A chave "chv" nÃ£o ocorre no dicionÃ¡rio, mas ocorre falha na
       *         alocaÃ§Ã£o de um novo nÃ³. Nesse caso, o dicionÃ¡rio deve ser
       *         mantido inalterado e a funÃ§Ã£o deve retornar um iterador
       *         apontando para o "fim" do dicionÃ¡rio.
       *
       * Caso 3: A chave "chv" nÃ£o ocorre no dicionÃ¡rio e nÃ£o acontece falha de
       *         alocaÃ§Ã£o de memÃ³ria. Nesse caso, a funÃ§Ã£o deve inserir "chv" e
       *         "val" no dicionÃ¡rio, e deve retornar um iterador apontando para
       *         a nova chave. */
       Iterador it=procurar(chv);
       if(it==fim()){
       	Noh *n=new(nothrow) Noh;
       	if(n==nullptr)return fim();
       	
       	n->chave=chv;n->valor=val;
		n->prox=prim;n->ant=nullptr;
		if(prim!=nullptr)prim->ant=n;
		prim=n;
       	
		it.p=n;
	   }
	   
	   return it;
     }

   void remover (Iterador i)
     {
	   
	   if(i.p->prox != nullptr)i.p->prox->ant=i.p->ant;
		
       if(i.p->ant != nullptr)i.p->ant->prox=i.p->prox;
	   
	   if(prim==i.p)prim=i.p->prox;

	   delete i.p;
     }

   void terminar ()
     {
       for(Iterador it=inicio();it!=fim();){
       	++it;delete prim;prim=it.p;
	   }
     }

  };  // struct Dicionario

// -----------------------------------------------------------------------------
/*
int main(){
	Dicionario<int,int> d;
	d.inserir(1,1);
	d.inserir(2,2);
	d.inserir(3,3);
	d.inserir(4,4);
	d.inserir(5,5);
	
	Dicionario<int,int>::Iterador a=d.procurar(1);
	d.remover(a);
	for(Dicionario<int,int>::Iterador it=d.inicio();it!=d.fim();++it)std::cout<<it.chave()<<","<<it.valor()<<"\n";
}*/
