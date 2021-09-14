#include <new>

using std::nothrow;



template <typename TC, typename TV> // TC: Tipo das Chaves. TV: Tipo dos Valores
struct Multidicionario
  {

   // --------------------------------------------------------------------------

   /* Como múltiplos valores, incluindo repetições, podem corresponder a uma
    * mesma chave num multidicionário, você deverá definir a seguir um tipo
    * Multiconjunto. */
    struct noh{
       	TV valor;noh *prox;
	};

   struct Multiconjunto
     {

      /* COMPLETE AQUI: defina aqui pelo menos os campos (dados-membro) do
       *                multiconjunto, podendo ser incluídas outras definições,
       *                se necessário. */

      // -----------------------------------------------------------------------

      /* O multiconjunto terá um iterador, que permitirá percorrer os valores
       * correspondentes a uma chave. */
       TC chv_conj;noh *prim=nullptr;

      struct Iterador  // Relativo ao Multiconjunto, não ao Multidicionario.
        {

         /* COMPLETE AQUI: defina aqui os campos (dados-membro) do iterador. */
			noh *p;
			
         bool operator == (Iterador i)
           {
            /* COMPLETE AQUI: Esta função deve retornar "true" se o iterador
             *                atual for igual ao iterador "i", ou "false" em
             *                caso contrário. */
             return p==i.p;
           }

         bool operator != (Iterador i)
           {
            /* COMPLETE AQUI: Esta função deve retornar "true" se o iterador
             *                atual for diferente do iterador "i", ou "false" em
             *                caso contrário. */
             return p!=i.p;
           }

         TV operator * ()
           {
            /* COMPLETE AQUI: Esta função deve retornar o valor apontado pelo
             *                iterador. */
             return p->valor;
           }

         void operator ++ ()
           {
            /* COMPLETE AQUI: Esta função deve fazer o iterador passar ao
             *                próximo valor do multiconjunto (ou então ao fim
             *                do multiconjunto, caso o iterador já esteja no
             *                último valor). */
             p=p->prox;
           }

        };  // struct Iterador

      // -----------------------------------------------------------------------

      /* Defina as funções-membro mencionadas a seguir, que são essenciais para
       * que se possa percorrer os valores do multiconjunto.
       *
       * IMPORTANTE: como o usuário do multidicionário utilizará o multiconjunto
       * apenas para conhecer os valores correspondentes a uma dada chave do
       * multidicionário, então operações como "inicializar", "inserir" e
       * "remover" NÃO SÃO EXIGIDAS abaixo. Entretanto, você pode defini-las,
       * caso precise delas internamente, nas operações do multidicionário. */

      Iterador inicio ()//v[i].inicio();
        {
         /* COMPLETE AQUI: Esta função deve retornar um iterador apontando para
          *                o primeiro valor do multiconjunto, caso haja algum,
          *                ou então para o fim do multiconjunto, caso o
          *                multiconjunto esteja vazio. */
          Iterador it;
          it.p=prim;
          return it;
        }

      Iterador fim ()
        {
         /* COMPLETE AQUI: Esta função deverá retornar um iterador apontando
          *                para o "fim" do multiconjunto. */
          Iterador it;
          it.p=nullptr;
          return it;
        }

     };  // struct Multiconjunto

   // --------------------------------------------------------------------------

   /* COMPLETE AQUI: defina os "campos" (dados-membro) do multidicionário,
    *                fazendo um Multiconjunto corresponder a cada chave.
    *
    * Caso deseje, você também pode definir tipos ou funções auxiliares,
    * tanto aqui como em outros lugares deste arquivo. */

   // --------------------------------------------------------------------------

   // Funções-membro do multidicionário:
   
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
      /* COMPLETE AQUI: Esta função deve inicializar o multidicionário,
       *                deixando-o vazio.
       *
       * Ela deve retornar "true" em caso de falha de alocação de memória (caso
       * alguma alocação seja necessária), e deve retornar "false" em caso de
       * execução bem-sucedida. */
       v=new(nothrow) Multiconjunto[1];
       if(v==nullptr)return true;
       tam=1;n=0;
       return false;
     }

   Multiconjunto procurar (TC chv)
     {
      /* COMPLETE AQUI: Esta função deve retornar o multiconjunto dos valores
       *                correspondentes à chave "chv", caso ela ocorra no
       *                multidicionário. Se a chave não estiver presente,
       *                então deve ser retornado um multiconjunto vazio.
       *
       * IMPORTANTE: esta função não prevê a ocorrência de falha de alocação de
       *             memória, partindo do pressuposto de que nenhuma alocação
       *             será necessária, afinal:
       *
       *   1. Se a chave estiver presente no multidicionário, então o
       *      multiconjunto a ser retornado já existe.
       *
       *   2. Se a chave não estiver presente, então deve ser possível criar e
       *      retornar um multiconjunto vazio sem realizar alocação de memória.
       */
       for(int i=0;i<n;++i){
       	if(v[i].chv_conj==chv)return v[i];
	   }
	   
	   Multiconjunto m;
	   return m;
     }

   bool inserir (TC chv, TV val)
     {
      /* COMPLETE AQUI: Esta função deve inserir a chave "chv" e o valor "val"
       *                no multidicionário.
       *
       * Mais especificamente, se a chave "chv" ainda não ocorre no
       * multidicionário, então ela e o valor "val" deve ser adicionados. Caso a
       * chave já ocorra no multidicionário, então o valor "val" deve ser
       * adicionado aos valores correspondentes a essa chave.
       *
       * A função deve retornar "true" em caso de falha de alocação de memória,
       * e deve retornar "false" em caso de excução bem-sucedida. */
       
	   
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
      /* COMPLETE AQUI: Esta função deve remover a chave "chv" do
       *                multidicionário (juntamente com os valores a ela
       *                correspondentes), caso ela ocorra. Se a chave não
       *                estiver presente, o multidicionário deve permanecer
       *                inalterado.
       *
       * A função deve retornar "true" em caso de falha de alocação de memória
       * (caso alguma alocação seja necessária), e deve retornar "false" em caso
       * de execução bem-sucedida. */
       for(int i=0;i<n;++i){
       	if(v[i].chv_conj==chv){
		   deletar(v[i].prim);v[i]=v[n-1];--n;
		   if(tam>1 && n*4<=tam){bool erro=redimensionar(tam/2);return erro;}
		   return false;
		   } //chama fun��o para desalocar a lista
	   }
	   
	   return false;
     }

   void terminar ()
     {
      /* COMPLETE AQUI: Esta função deve desalocar a memória dinamicamente
       *                alocada para o multidicionário (e consequentemente
       *                também a memória utilizada pelo Multiconjunto de cada
       *                chave). */
       for(int i=0;i<n;++i){
       	deletar(v[i].prim);
	   }
       
       delete v;
     }

  };  // struct Multidicionario ------------------------------------------------


// ----------------------------------------------------------------------------- */
