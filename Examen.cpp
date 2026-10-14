#include <iostream>
using namespace std;
int main(){
	int var=0; 
	int par=0; 
	int impar=0;
	while (var<=40){
		var=var + 1;
		if(var%2==0){
			par=par+var;
		}
	}
	var=0;
	while (var<=25){
		var=var+1;
		if(var%2==1){
			impar=impar+var;
		}
	}
	cout<<"LA SUMA DE TODOS LOS NUMEROS PARES DE 0 A 40 ES DE "<<par;
	cout<<"\n LA SUMA DE TODOS LOS NUMEROS IMPARES DE 0 A 25 ES DE "<<impar;
	return 0;
}
