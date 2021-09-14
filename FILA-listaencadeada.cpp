#include<iostream>
#include<new>

using std::cin;
using std::cout;
using std::nothrow;


//template<typename T>
struct fila{
	struct noh{int elem;noh *prox;};
	noh *prim,*ult;
	
	void iniciar(){prim=nullptr;}
	
	bool vazia(){
		return prim==nullptr;
	}
	
	bool enfilar(int e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=nullptr;
		if(vazia()){
			prim=n;ult=n;
		}else{
			ult->prox=n;
			ult=n;
	}
		//ult=n;
		return false;
	}
	
	
	int primeiro(){
		return prim->elem; //ou (*prim).elem;
	}
	
	int desenfilar(){
		int a=prim->elem;
		noh *n=prim;prim=prim->prox;
		delete n;
		return a;			
	}
	
	void terminar(){
		while(!vazia()){desenfilar();}
	}
};

///ESTUDO
template<typename T>
struct fila{
	struct noh{T elem;noh *prox;};
	noh *prim;noh *ult;
	
	void inicializar(){
		prim=nullptr;
	}
	
	bool vazia(){
		return prim==nullptr;
	}
	
	bool enfilar(T e){
		noh *n=new(nothrow) noh;
		if(n==nullptr)return true;
		n->elem=e;n->prox=nullptr;
		
		if(vazia()){
			prim=n;
		}else{
			ult->prox=n;
		}
		
		ult=n;
		
		return false;
	}
	
	void desenfilar(){
		noh* n=prim;
		prim=n->prox;
		delete n;
	}
	
	T consultar_primeiro(){
		return prim->elem;
	}
	
};

int main(){
	
    fila f;
    f.iniciar();
    
    for(;;){
    	
        int e;
        cin>>e;
        
        if(e>0){
            
            for(int i=1;i<=e;++i){
            	if(f.vazia()){
            		cout<<"V";
				}else{
					cout<<f.desenfilar();	
				}
				
				if(i<e){
					cout<<" ";
				}else{
					cout<<"\n";
				}
			}
			
        }else if(e<0){
            bool erro=f.enfilar(e);
            if(erro)return erro;
        }else{
            while(!f.vazia()){
				cout<<f.desenfilar();	
				
				if(!f.vazia()){
					cout<<" ";
				}else{
					cout<<"\n";
				}
            }
            f.terminar();
            break;
        }
    }
    
}






















