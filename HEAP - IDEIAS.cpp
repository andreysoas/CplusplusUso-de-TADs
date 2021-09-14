#include<iostream>
#include<new>

using std::nothrow;
using std::cout;

//CHEGAR NO PAI = i-1)/2
//CHEGAR NOS FILHOS = 2i+1 , 2i+2

// O ELEMENTO N�O TEM DOIS FILHOS SE O C�LCULO DOS FILHOS FOR MAIOR QUE n 

//Total de elementos. Dado o total de n�veis, o total de elementos do monte cheio � 2^n -1 


//O HEAPSORT -> APLICAR O ALGORITMO DE DESCIDA AO VETOR RECEBIDO, AP�S
// O VETOR ESTAR EM FORMA DE MONTE, RETIRE O M�XIMO E ENVIE-O PARA O FINAL, DECRES�A O n, APLIQUE A ORDEM DE MONTE E ENT�O
// FA�A ISSO SUCESSIVAMENTE PARA O MONTE CADA VEZ MENOR. ASSIM, O VETOR ESTAR� ORDENADO AO FINAL.


/* OBSERVEMOS QUE NO MOMENTO QUE RETIRAMOS O M�XIMO E O ENVIAMOS PARA O FINAL
	O �LTIMO ELEMENTO DO MONTE VAI PARA A RAIZ, E ENT�O SER� APLICADA A ESTRAT�GIA DE DESCER, ASSIM VALIDANDO O MONTE. */

template<typename T>
void descer(T *v, int n, int i){
	for(;;){//V[I] � maior ou igual aos seus filhos?
		int esq = 2*i + 1; if(esq>=n)break; // se ele n�o tem filho esquerdo, ent�o ele n�o tem direito.
		
		int dir = esq+1; // 2*i + 2
		
		int max;
		
		if(dir < n && v[dir] > v[esq])max=dir; // checa se tem filho direito e se ele � maior que o esquerdo.
		else 						  max=esq;
		
		if(v[i]>=v[max])break; // se o pai for maior, ent�o para o processo.
		
		T copia_de_vi = v[i]; v[i]=v[max]; v[max] = copia_de_vi; i=max; // N�o era maior, troca os dois e i agora � max para continuar a descida.
	}
}

//pai(i) = (i-1)/2

template<typename T>
void heapsort(T *v, int n){
	
	for(int i=((n-2)/2);i>=0;--i){descer(v,n,i);} // n-2 porq o �ndice do elemento � n-1 - ESTA FUN��O CHAMA A DESCIDA PARA OS ELEMENTOS DO PEN�LTIMO N�VEL
	
	while(n>0){ // ordena 
		T max = v[0]; v[0] = v[n-1]; --n, descer(v,n,0);
		v[n] = max;
	}
}

template<typename T>
int busca_binaria(T *v,int n,T e){
	int a=0,b=n-1;
	while(a<=b){
		
		int med=a+((b-a)/2);
		
		if(v[med]==e)return med;
		
		if(e<v[med])b=med;
		else		a=med;
	}
	return -1;
}

int main(){
	int v[15]={2,3,4,9,5,8,12,1,23,25,17,19,19,45,15};
	
	for(int i=0;i<15;++i){
		cout<<v[i]<<' ';
	}
	cout<<'\n';
	heapsort(v,15);
	
	for(int i=0;i<15;++i){
		cout<<v[i]<<' ';
	}
	
	cout<<"\n"<<"Procurando o 17...\n";
	
	int indice = busca_binaria(v,15,17);
	if(indice!=-1)cout<<"Achei na: "<<indice<<'\n';
}

/*
void descer(T *v, int n, int i){
	for(;;){
		int esq=(2*i)+1;if(esq>=n)break; //Checa se tem o filho esquerdo, se n�o -> para
		
		int dir=esq+1;	// calcula o filho direito
		
		int max;	
		
		if( dir<n && v[dir]>v[esq] )max=dir;  //Decis�o sobre qual o maior dos dois se houver filho direito.
		else 			  			max=esq;
		
		if(v[i]>=v[max])break;	// se o maior dos filhos � menor -> para
		
		T troca=v[i];v[i]=v[max];v[max]=troca;i=max;  // se n�o for -> troca os dois de lugar e define o novo i para continuar a descida
	}
}

void heapsort(T *v, int n){
	for(int i=(n-1-1)/2;i>=0;--i){
		descer(v,n,i);
	}
	
	while(n>0){
		T max=v[0]; // pega o m�ximo
		v[0]=v[n-1]; // passa o �ltimo para o in�cio, para aplicar a descida
		--n;	// decrementa o n�mero de elementos do monte
		descer(v,n,0);	// desce o �ltimo que foi para a raiz
		v[n]=max;	// copia o max retirado no in�cio para o final do vetor
	}
}

--------------------------------------------------------------------------------------------------

// PRIMEIRO O ALGORITMO DE DESCIDA
template<typename T>   
void descer(T *v,int n, int i){
	for(;;){
		int esq=2*i + 1; if(esq>=n)break;
		
		int dir=esq+1;
		
		int min; // o vai tomar o ind�ce do maior filho
		
		if(dir<n && v[dir]<v[esq])min=dir;
		else 				min=esq;
		
		if(v[i]<=v[min])break;
		
		T auxiliar=v[min];v[min]=v[i];v[i]=auxiliar;i=min;
	}
	
}

// SEGUNDO O ALGORITMO DE ORDENA��O - CRIANDO O MONTE DE M�NIMO
template<typename T>
void heapsort(T *v,int n){
	for(int i=(n-1-1)/2;i>=0;--i){ //come�a do pai do �ltimo A CRIAR O MONTE
		descer(v,n,i);
	}
	
	while(n>1){
		T ult = v[0];v[0]=v[n-1];--n;descer(v,n,0);v[n]=ult;
	}
}


int main(){
	int v[10]={5,9,8,6,7,10,4,2,1,3};
	heapsort(v,10);
	for(int i=0;i<10;++i)cout<<v[i]<<' ';
}



BUSCA BIN�RIA:--------------------------------------------------------------------

bool busca_binaria(T *v,int n, T e){
	while(a<=b){
		int a=0;
		int b=n-1;
		
		med=a+((b-a)/2);
		
		if(v[med]==e)return true;
		
		if(e<v[men])b=med;
		else		a=med;
	}
	return false;
}

*/
