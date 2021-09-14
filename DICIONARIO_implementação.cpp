#include<iostream>
#include<new>
using std::cin;
using std::cout;
using std::nothrow;

template<typename TX, typename TY>
struct par{Tx x; Ty y;};

template<typename TC, typename TV>
struct Dicionario{
	private:
		
	par<TC,TV> *v;
	int tam_v,n;
	
	int indice(TC c){
		for(int i=0;i<n;++i){
			if(v[i].x==c)return i;
		}
		return -1;
	}
	
	
	bool redimensionar(int novo_tam){
		par<TC,TV> *u = new(nothrow) par<TC,TV>[novo_tam];
		if(u==nullptr)return true;
		for(int i=0;i<n;++i){
			u[i]=v[i]; //copia o par diretamente
		}
		delete[] v;
		v=u;
		tam_v=novo_tam;
		return false;
	}
	
	public:
		
	bool iniciar(){
		tam_v=1;
		v=new(nothrow) par<TC,TV>[1];
		if(v==nullptr)return true;
		n=0;
		return false;
	}
	
	
	par<bool,bool> inserir(TC c, TV vl){  //1° bool: inserção realizada, 2° bool: chave presente
	 par<bool,bool> p; int i = indice(c);
	 
	 if(i==-1){
	 	p.x=false;
	 	if(n==tam_v){
	 		p.y = redimensionar(2*tam_v); if(p.y)return p;
		 }
		 v[n].x=c; v[n].y=vl; ++n; p.y = false;
	 }else{	p.x=true;p.y=false;}
	 return p;
	}
	
	par<bool,bool> remover(TC c){// 1- chave presente ? 2- erro de alocação
		par<bool,bool> p;
		int i=indice(c);
		
		if(i==-1){
			p.x=false; p.y=false;
		}else{
			v[i]=v[n-1]; --n; p.x=true;
			if(4*n==tam_v){//se precisar redimensionar
				p.y = redimensionar(tam_v);
			}else{
				p.y=false;
			}
		}
		
		return p;
	}
	
	void terminar(){
		delete[] v;
	}
	
	par<bool,TV> consultar(TC c){
		Par<bool,TV> p;
		
		int i=indice(c);
		if(i==-1){
			p.x=false;
		}else{
			p.x=true;
			p.y=v[i].y;
		}
		
	return p;
	}
};



int main(){ //Dicionario tem um par: chave e o valor/dado 
	
	struct Notas {double ap1, ap2;};
	Dicionario<int,Notas> D;
	
	bool erro = D.iniciar(); if(erro) return true;
	
	for(;;){
		cout<<"Opções: \n\n"
			<<" i: inserir\n"
			<<" c: consultar\n"
			<<" r: remover\n"
			<<" outra letra: sair\n"
		cout<<"\n Opcao: "; char op; cin>>op;
		
		if(op=='i'){
			cout<<"Matricula: ";int m; cin>>m;
			//fazer a consulta da matricula
			par<bool,Notas> p = D.consultar(m);
			if(p.x){
				cout<<"Esta matricula ja esta no dicionario\n"
			}else{//se não tiver, a gente insere
			cout<<"AP1: "; Notas n; cin>>n.ap1;   //preenche Notas
			cout<<"AP2: "; cin>>n.ap2;
			
			Par<bool,bool> pe = D.inserir(m,n);//insere a matrícula e Notas
			
			if(pe.y){
				cout<<"Erro de alocacao!\n";return true;
			}
			}	
		}else if(op)
	}
	
	
	D.terminar();
}
