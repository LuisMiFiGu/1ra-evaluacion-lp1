#include <iostream>
using namespace std;
int main(){
float peso=0;
float altura=0;
string nombre;
float IMC=0;
cout<<"INGRESE SU NOMBRE: ";
cin>>nombre;
cout<<"\nINGRESE SU PESO: ";
cin>>peso;
cout<<"\nINGRESE SU ALTURA: ";
cin>>altura;
while(peso==0){
	cout<<"\nINGRESE OTRA VEZ SU PESO: ";
    cin>>peso;
}
while(altura==0){
	cout<<"\nINGRESE OTRA VEZ SU ALTURA: ";
    cin>>altura;
}
altura= altura*0.01;
IMC= peso/(altura*altura);
if(IMC<16.00){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE INFRAPESO: DELGADEZ SEVERA";
}else if(IMC>=16 && IMC<=16.99){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE INFRAPESO: DELGADEZ MODERADA";
}else if(IMC>=17.00 && IMC<=18.49){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE INFRAPESO: DELGADEZ ACEPTABLE";
}else if(IMC>=18.50 && IMC<=24.99){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE PESO NORMAL";
}else if(IMC>=25.00 && IMC<=29.99){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE SOBREPESO";
}else if(IMC>=30.00 && IMC<=34.99){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE OBESO: TIPO 1";
}else if(IMC>=35.00 && IMC<=40.0){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE OBESO: TIPO 2";
}else if(IMC>40.00){
	cout<<nombre;
	cout<<" SU IMC (INDICE DE MASA CORPORAL) ES DE: "<<IMC;
	cout<<" SU CLASIFICACION ES DE OBESO: TIPO 3";
}
return 0;
}
