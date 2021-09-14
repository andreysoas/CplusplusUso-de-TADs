#include<iostream>
#include<new>

using std::cout;
using std::nothrow;

template<typename T>
int busca_binaria(T *v,int n, T x){
	int i=0;f=n-1;
	
	while(i<=f){
		int m=(i+f)/2;  //para evitar transbordo/OVERFLOW: m=i+(f-i)/2;
		
		if(x==v[m])return m;
		
		if(x<v[m])f=m-1;
		else	i=m+1;
	}
	
	return -1;
}

int main(){
	int v[10]={1,2,3,4,5,6,7,8,9,10};
	
	cout<<busca_binaria(v,10,7);
}



int i=0;int f=n-1;

while(i<=f){
	
	int meio=i+(f-i)/2;
	
	if(v[meio]==x)return meio;
	
	if(x<meio)f=meio-1;
	else	i=meio+1;
}

return -1;


