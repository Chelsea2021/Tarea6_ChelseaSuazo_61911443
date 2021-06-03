#include <iostream>
#include<stdlib.h>

using namespace std;

class Hospedaje{
	private: //Atributos
		string nombre;
		int edad;
		string id;
	
	public: //Metodos
		Hospedaje(string,int,string);
		void mostrarHospedaje();
		
};

class Hoteles : public Hospedaje{
	private:
		string servicios;
	public:
		Hoteles(string,int,string,string);
		void mostrarHoteles();
};

class Apartamentos : public Hospedaje{
	private:
		string renta;
	public: 
		Apartamentos(string,int,string,string);
		void mostrarApartamentos();
};

class Habitaciones : public Hoteles{
	private:
		int numero;
	public:
		Habitaciones(string,int,string,string,int);
		void mostrarHabitaciones();
};

class AirBnb : public Hospedaje{
	private:
		int cantidad;
	public:
		AirBnb(string,int,string,int);
		void mostrarAirBnb();
};
//Constructor de  la clase Hospedaje(Clase Padre)
Hospedaje::Hospedaje(string _nombre,int _edad,string _id){
	nombre = _nombre;
	edad = _edad;
	id = _id;
	
}

void Hospedaje::mostrarHospedaje(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
	cout<<"Numero de identidad: "<<id<<endl;

}

//Constructor de la clase Hoteles(Clase Hija-Padre)
Hoteles::Hoteles(string _nombre,int _edad,string _id,string _servicios) : Hospedaje(_nombre,_edad,_id){
	servicios = _servicios;
}

void Hoteles::mostrarHoteles(){
	mostrarHospedaje();
	cout<<"Servicios a su disposicion: "<<servicios<<endl;
}

//Constructor de la clase Apartamentos(Clase Hija)
Apartamentos::Apartamentos(string _nombre,int _edad,string _id,string _renta) : Hospedaje(_nombre,_edad,_id){
	renta = _renta;
}

void Apartamentos::mostrarApartamentos(){
	mostrarHospedaje();
	cout<<"Periodo de tiempo estimado a rentar: "<<renta<<endl;
}

//Constructor de la clase Habitaciones(Clase Hija)
Habitaciones::Habitaciones(string _nombre,int _edad,string _id,string _servicios,int _numero) : Hoteles(_nombre,_edad,_id,_servicios){
	numero = _numero;
}

void Habitaciones::mostrarHabitaciones(){
	mostrarHoteles();
	cout<<"Numero de habitaciones: "<<numero<<endl;
}

//Constructor de la clase AirBnb(Clase Hija)
AirBnb::AirBnb(string _nombre,int _edad,string _id,int _cantidad) : Hospedaje(_nombre,_edad,_id){
	cantidad = _cantidad;
}

void AirBnb::mostrarAirBnb(){
	mostrarHospedaje();
	cout<<"Cantidad de personas a hospedarse: "<<cantidad<<endl;
}

int main() {
	char x[50];
	char r[50];
	int r2;
	int e;
	string l;
	int n;
	int c;
	int h;
	int r1;
	int r3;
	int total1=0;
	int total2=0;
	int total3=0;
	printf( "---------------RESERVA YA---------------\n" );
	printf( "Tenemos a su disposicion diferentes opciones de hospedaje:\n" );
	printf( "1)Hoteles\n2)Apartamentos\n3)AirBnb\n\n" );
	printf( "Contamos con los siguientes precios (* persona)\n" );
	printf( "Para Hoteles el precio de habitacion por noche es de $50, que incluye estadia y alimentacion (desayuno, almuerzo y cena)\n" );
	printf( "Para Apartamentos el precio es de $150 el mes (Pueden rentarse por periodo de tiempo mayor, meses o anios)\n" );
	printf( "Para AirBnb el precio es de $100 por noche (se permite el hospedaje de mas de una persona en una habitacion o casa)\n \n");
	
	printf( "-------------INGRESAR DATOS-------------\n" );
	printf( "Favor ingrese su nombre completo para su registro\n" );
	gets(x);
	printf( "Ingrese su edad\n" );
	scanf("%i",&e);
	cin.ignore(1000000, '\n');
	cout<<"Ingrese su numero de identidad sin espacios\n";
	cin>>l;
	cin.ignore(1000000, '\n');
	printf( "Ingrese numero acorde a las opciones de hospedaje\n" );
	scanf("%i",&n);


	
	

	
	if(n == 1){
		cin.ignore(1000000, '\n');
		cout<<"Ingrese la cantidad de noches que estara en el hotel" <<endl;
		cin>>r1;
		printf( "Ingrese el numero de la cantidad de habitaciones que ocupara\n" );
		scanf("%i",&h);
		cout<<"----------------Cliente----------------"<<endl;
		cout<<"Tipo de hospedaje seleccionado: Hotel\n";
		Habitaciones habitaciones1(x,e,l,"desayuno, almuerzo y cena",h);
		habitaciones1.mostrarHabitaciones();
		total1 = r1* 50;
		cout<<"El total a pagar es de: $"<<total1<<endl;
	}
	
	if(n == 2){
		cin.ignore(1000000, '\n');
		printf( "Ingrese periodo de tiempo a rentar apartamento, puede especificar en meses\n" );
		gets(r);
		cout<<"Favor confirmar el periodo de tiempo a rentar apartamento, solo con datos numericos" <<endl;
		cin>>r2;
	
		cout<<"----------------Cliente----------------"<<endl;
		cout<<"Tipo de hospedaje seleccionado: Apartamento\n";
		Apartamentos apartamentos1(x,e,l,r);
		apartamentos1.mostrarApartamentos();
		total2 = r2* 150;	
		cout<<"El total a pagar es de: $"<<total2<<endl;\
	}
	
	if(n == 3){
		cin.ignore(1000000, '\n');
		cout<<"Ingrese la cantidad de noches que nos visitara" <<endl;
		cin>>r3;
		printf( "Ingrese el numero de la cantidad de personas a hospedarse\n" );
		scanf("%i",&c);
		cout<<"----------------Cliente----------------"<<endl;
		cout<<"Tipo de hospedaje seleccionado: AirBnb\n";
		AirBnb airbnb1(x,e,l,c);
		airbnb1.mostrarAirBnb();
		total3 = r3* 100;	
		cout<<"El total a pagar es de: $"<<total3<<endl;
	
	}
	

	printf( "Su registro a sido efectuado de forma exitosa!!!\n" );
	printf( "LE ESPERAMOS!!!\n" );
	
	
	
	system("pause");
	return 0;
}
