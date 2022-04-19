#include <iostream>

using namespace std;

int main(){
	int n, x1,x2,cont=0;
	
	cout<<"Ingrese el numero de la tabla que deseas multiplicar: "<<endl;
	cin>>n;
	cout<<"Ingresa el numero que elijas dentro del rango que elijas: "<<endl;
	cin>>x1;
	cin>>cont;
	
	do{
	
	x2=x1*n;
	cout<<x1<<" x "<<n<<" = "<<x2<<endl;
	x1=x1+1;
	
	}while(x1<=cont);
	
	
	return 0;
}
