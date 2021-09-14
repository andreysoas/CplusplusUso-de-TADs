/* -----------------------------------------------------------------------------
 Universidade Federal do Ceará - Centro de Ciências - Departamento de Computação
 Disciplina Estruturas de Dados - CK0109 - Turma 02 - Semestre Letivo 2020.2

 Molde de Resposta para o Exercício Obrigatório nº 11: Dicionário via Lista Enc.

 Autor: Professor Pablo Mayckon Silva Farias, em 26/03/2021.

 TAREFA: leia o enunciado presente na plataforma de correção automática da
         disciplina, o qual é complementado por informações específicas
         presentes neste arquivo, e em seguida complete a implementação abaixo
         no lugares indicados com "COMPLETE AQUI".
----------------------------------------------------------------------------- */

// Não é necessário incluir nenhum outro cabeçalho além de <new>.

#include <new>
#include<iostream>
using std::nothrow;

// -----------------------------------------------------------------------------

/* Este exerc�cio consiste em implementar um dicion�rio utilizando lista
 * duplamente encadeada (n�o-circular e sem sentinela) como estrutura de dados,
 * e permitindo percurso via iterador.
 * As chaves ter�o tipo TC e os valores tipo TV.
 * Qualquer chave pode ocorrer no m�ximo uma vez no dicion�rio.
 *
 * A implementa��o abaixo j� fornece a defini��o de noh e o ponteiro inicial da
 * lista encadeada. � obrigat�rio utiliz�-los como est�o (isto �, sem
 * alterar-lhes as defini��es), inclusive mantendo-os com acesso "p�blico" (que
 * � o padr�o para "struct"), pois o programa de testes percorrer� os nohs da
 * lista durante os testes (uma implementa��o mais realista poderia deixar a
 * implementa��o privada e declarar um tipo de testes como "friend", mas, por
 * simplicidade, todos os dados-membros do Dicion�rio ser�o p�blicos neste
 * exerc�cio). Observe, por�m, que a implementa��o do iterador ficar� privada,
 * pois o programa de testes apenas usar� os iteradores, sem investigar-lhes
 * a representa��o interna. */

template <typename TC, typename TV>
struct Dicionario
  {
   /* Conforme explicado acima, as definições de "Noh" e de "prim" não podem
    * ser alteradas, para viabilizar uma inspeção interna da lista. */

   struct Noh {  TC chave;  TV valor;  Noh *ant, *prox;  };

   Noh *prim;

   /* Lembre que esta será uma lista duplamente encadeada padrão, ou seja,
    * não-circular e sem sentinela. Portanto, quando não houver nó anterior
    * / próximo ou um primeiro nó, então ant / prox / prim devem ser nulos,
    * respectivamente. */

   struct Iterador
     {
      friend Dicionario;  /* Esta declaração apenas permite que, mais abaixo,
                           * as funções-membro do dicionário consigam acessar
                           * os membros privados da definição do iterador,
                           * caso você precise disso. */

      private:

      /* COMPLETE AQUI: Defina aqui os campos necessários à implementação
       *                do iterador.
       *
       * ATENÇÃO: a definição deve ser tal que um iterador que se refira a um
       *          elemento (chave e valor) do dicionário continue válido mesmo
       *          que aconteçam inserções ou remoções de OUTROS elementos no
       *          dicionário. Observe que isso é complicado de se fazer numa
       *          implementação baseada em vetor, mas é simples nesta
       *          implementação com lista encadeada. */
		Noh *p;
      public:

      bool operator == (Iterador i)
        {
         /* COMPLETE AQUI: Defina esta função, que deve se retornar "true" se o
          *                iterador atual for igual ao iterador "i", ou "false"
          *                em caso contrário. */
          return p==i.p;
        }

      bool operator != (Iterador i)
        {
         /* COMPLETE AQUI: Defina esta função, que deve se retornar "true" se o
          *                iterador atual for diferente do iterador "i", ou
          *                "false" em caso contrário. */
          return p!=i.p;
        }

      /* No lugar do operador "*", esta implementação de iterador possui as
       * funções "chave" e "valor" abaixo. */

      TC chave ()
        {
         /* COMPLETE AQUI: Defina esta função, que deve retornar a chave do
          *                elemento apontado pelo iterador. */
          return p->chave;
        }

      TV valor ()
        {
         /* COMPLETE AQUI: Defina esta função, que deve retornar o valor do
          *                elemento apontado pelo iterador. */
          return p->valor;
        }

      void operator ++ ()
        {
         /* COMPLETE AQUI: Defina esta função, que deve fazer o iterador passar
          *                ao próximo elemento do dicionário, ou então ao fim
          *                do dicionário, caso o iterador já esteja no último
          *                elemento. */
          p=p->prox;
        }

     }; // struct Iterador

   // --------------------------------------------------------------------------

   // Abaixo estão as funções-membro públicas do dicionário.

   void inicializar ()
     {
      /* COMPLETE AQUI: Defina esta função, que deve inicializar o dicionário,
       *                deixando-o vazio. */
       prim=nullptr;
     }

   Iterador inicio ()
     {
      /* COMPLETE AQUI: Defina esta função, que deve retornar um iterador
       *                apontando para o primeiro elemento do dicionário, caso
       *                haja elementos, ou então para o "fim" do dicionário,
       *                caso ele esteja vazio. */
       Iterador it;
       it.p=prim; // interpretando fim como sendo o ponteiro nulo
       return it;
	 }

   Iterador fim ()
     {
      /* COMPLETE AQUI: Defina esta função, que deve retornar um iterador
       *                apontando para o "fim" do dicionário. */
       Iterador it;
	   //while(it.p->dir!=nullptr)++it;
	   it.p=nullptr;
       return it;
     }

   Iterador procurar (TC chv)
     {
      /* COMPLETE AQUI: Defina esta função, que serve para localizar uma chave
       *                no dicionário. Se a chave estiver presente, deve ser
       *                retornado um iterador apontando para ela e seu valor
       *                correspondente; em caso contrário, deve ser retornado
       *                um iterador apontando para o "fim" do dicionário. */
       Iterador it;
       
	   for(it=inicio();it!=fim();++it){
	   	if(it.chave()==chv)break;
	   }
       
       return it;
     }

   Iterador inserir (TC chv, TV val)
     {
      /* COMPLETE AQUI: Defina esta função, que deverá permitir inserções no
       *                dicionário. Podem ocorrer 3 casos:
       *
       * Caso 1: A chave "chv" já está presente no dicionário: nesse caso, a
       *         função deve manter o dicionário inalterado e retornar um
       *         iterador apontando para a chave "chv" e o valor já
       *         correspondente a ela no dicionário (o qual pode ser igual a ou
       *         diferente de "val").
       *
       * Caso 2: A chave "chv" não ocorre no dicionário, mas ocorre falha na
       *         alocação de um novo nó. Nesse caso, o dicionário deve ser
       *         mantido inalterado e a função deve retornar um iterador
       *         apontando para o "fim" do dicionário.
       *
       * Caso 3: A chave "chv" não ocorre no dicionário e não acontece falha de
       *         alocação de memória. Nesse caso, a função deve inserir "chv" e
       *         "val" no dicionário, e deve retornar um iterador apontando para
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
      /* COMPLETE AQUI: Defina esta função, que recebe um iterador apontando
       *                para algum elemento (chave e valor) do dicionário, e que
       *                deve então removê-lo.
       *
       * Atenção: observe que esta versão da função, ao invés de receber uma
       *          chave (que então precisaria ser procurada), já recebe um
       *          iterador relativo à chave que precisa ser removida, bastando
       *          então realizar a remoção propriamente dita. Não é necessário
       *          testar a validade do iterador: a função já deve pressupor que
       *          o iterador é válido e portanto se refere a algum elemento
       *          (chave e valor) do dicionário. */
	   
	   if(i.p->prox != nullptr)i.p->prox->ant=i.p->ant;
		
       if(i.p->ant != nullptr)i.p->ant->prox=i.p->prox;
	   
	   if(prim==i.p)prim=i.p->prox;

	   delete i.p;
     }

   void terminar ()
     {
      /* COMPLETE AQUI: Defina esta função, que deve desalocar os nós utilizados
       *                para armazenar os elementos do dicionário. */
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
