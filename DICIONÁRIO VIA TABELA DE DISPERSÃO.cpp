/* -----------------------------------------------------------------------------
 Universidade Federal do Ceará - Centro de Ciências - Departamento de Computação
 Disciplina Estruturas de Dados - CK0109 - Turma 02 - Semestre Letivo 2020.2

 Molde de Resposta para o Exercício Obrigatório nº 14: Dicionário via Tab. de D.

 Autor: Professor Pablo Mayckon Silva Farias, em 01/04/2021.

 TAREFA: leia o enunciado presente na plataforma de correção automática da
         disciplina, o qual é complementado por informações específicas
         presentes neste arquivo, e em seguida complete a implementação abaixo
         no lugares indicados com "COMPLETE AQUI".
----------------------------------------------------------------------------- */

// Não é necessário incluir nenhum outro cabeçalho além de <new>.
//#include<iostream>
#include <new>

using std::nothrow;

// -----------------------------------------------------------------------------

/* Este exercício consiste em implementar um Dicionário utilizando Tabela de
 * Dispersão como estrutura de dados. A tabela de dispersão utilizará listas
 * simplesmente encadeadas, não-circulares, mas com um nó sentinela, que por
 * conveniência estará embutido na estrutura do dicionário. Cada chave pode
 * ocorrer no máximo uma vez no dicionário, e possuirá exatamente um valor
 * correspondente.
 *
 * Você pode introduzir definições auxiliares (tipos, funções, etc) onde desejar
 * neste arquivo, mas não pode alterar as definições já existentes, que nos
 * testes serão utilizadas exatamente como estão. Observe, em particular, que
 * os testes analisarão a tabela de dispersão por dentro.
 *
 * Abaixo, "h" é a função de dispersão a ser utilizada pelo dicionário. Observe
 * que ela é um parâmetro "template" do dicionário, ou seja, você não precisa
 * nem deve defini-la, mas sim apenas utilizá-la. O primeiro argumento de "h" é
 * a chave, e o segundo argumento de "h" é o tamanho da tabela de dispersão. */


template <typename TC, typename TV, int h (TC,int) >
struct DicioDisp
  {

   struct Noh { TC chave;  TV valor;  Noh *prox; };

   Noh **T, sent;  /* Observe que "sent" é um nó, embutido na estrutura do
                    * dicionário, e não um ponteiro. */

   int m, n;       /* "m" � o tamanho da tabela/do vetor "T".
                    * "n" � o n�mero de chaves armazenadas no dicion�rio. */

   /* IMPORTANTE: A sua implementa��o dever� utilizar a estrat�gia de
    *             redimensionamento eficiente de vetores ensinada na disciplina,
    * garantindo as seguintes rela��es entre o tamanho "m" da tabela e a
    * quantidade "n" das chaves:
    *
    *   1. Se n == 0, então m == 2.
    *
    *   2. Se n != 0, então n <= m < 4*n.
    *
    * Além disso, "m" deverá ser sempre uma potência de 2, isto é, m == 2^k,
    * para algum natural k >= 1. */

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
      /* COMPLETE AQUI: Esta função deve deixar o dicionário num estado válido,
       *                vazio e com m == 2.
       *
       * A função deve retornar "true" se e somente se houver falha de alocação
       * de memória. */
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
      /* COMPLETE AQUI: Esta função retorna uma estrutura simples do tipo TBusca
       *                definido acima: se a chave procurada existir no
       * dicionário, então o campo "existe" da estrutura retornada deverá valer
       * "true", e o campo "valor" deverá possuir o valor correspondente à
       * chave; se a chave não estiver presente no dicionário, então o campo
       * "existe" valerá "false" e o campo "valor" não fará sentido para quem
       * usar a função (nesse caso, a função não precisa nem deve preencher esse
       * campo). */
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

   bool inserir (TC chv, TV val) // Pré-condição: "chv" não existe no dicionário
     {
      /* COMPLETE AQUI: Esta função deve permitir inserções no dicionário, já
       *                partindo do pressuposto de que a chave "chv" não ocorre
       * no mesmo. A função deve retornar "true" se e somente se acontecer falha
       * de alocação de memória. */
       
       //checar se t� "cheio" se n=m
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
      /* COMPLETE AQUI: Esta função deve remover a chave "chv" e o valor a ela
       *                correspondente, caso ela ocorra no dicionário; se a
       * chave não ocorrer, então o dicionário deve ser mantido inalterado. A
       * função deve retornar "true" se e somente se houver falha de alocação de
       * memória. */
    	
    	// se m<n -> redimensionar, mas m>2
    	// Redimensionar precisa realocar as chaves
    	
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
      /* COMPLETE AQUI: Esta função deve desalocar a memória dinamicamente
       *                alocada para o dicionário. */
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
  };  // struct DicioDisp
  /*
int metodo_da_divisao(int e,int m){
	return e%m;
}

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
