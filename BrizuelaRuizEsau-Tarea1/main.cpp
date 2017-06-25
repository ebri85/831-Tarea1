#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

int menu();

const int TAMANO = 4;


struct Jugador{
    string nombre;
    int intento[6];
    int total;
};

Jugador jugadores[TAMANO];


int puntos[6] = {10,5,4,3,2,1};


Jugador JugadorNuevo(int[]);
void Partida(Jugador[]);
int Aleatorio();
void AgregaJugador(Jugador[]);
void ModficaTamanoJugadores(Jugador []);
void MuestraGanador(Jugador[]);
void Resultados(Jugador[]);



int main()
{
menu();

int tam = (sizeof(jugadores)/sizeof(Jugador));

cout<<tam<<endl;

ModficaTamanoJugadores(jugadores);

int ta = (sizeof(jugadores)/sizeof(Jugador));
cout<<ta<<endl;
}


int menu(){ //Metodo encargado de Mostrar el de Menu en Consola

    int resultado = 0;

    string menu = "Control de Puntaje\n";
    menu+= "1 - Inicio de Jornada \n";
    menu+= "2 - Cerrar Partida \n";
    menu+= "0 - SALIR\n\n";

    cout<<menu<<endl;

return resultado;
//Fin de Metodo Menu
}

Jugador JugadorNuevo(int pts[]){ /*Metodo pasa por referencia el Jugador y genera sus valores de juego*/
    Jugador j;
    cout <<"Digite el nombre del Jugador"<<endl;
        cin >>j.nombre;

    int num = 0;

    for (int i=0;i<=TAMANO; i++){

        num = Aleatorio();
        j.intento[i] = pts[num];
        j.total+=j.intento[i];

    }

    return j;

}

int Aleatorio(){

    srand(time(0));

    int resultado;

    resultado = rand()%6;

return resultado;

}

void AgregaJugador(Jugador js[]){

string nombre;
int tam = (sizeof(js)/sizeof(Jugador));

    cout<<"Digite el nombre del jugador?"<<endl;
        cin>>nombre;

   for(int i=0;i<=tam;i++){
        if(js[i].nombre==nombre){

           cout<<"El Jugador " + nombre + " ya jugo"<<endl;


        }else {

            js[i]=JugadorNuevo(puntos);

        }

   }
}


void ModficaTamanoJugadores(Jugador j[]){

    int tam = (sizeof(j)/sizeof(Jugador));


    Jugador tempJug[tam];

    for(int i=0; i<=tam;i++){

        tempJug[i] = j[i];

    }

        //delete[] j;
        tam+= 2;

    //Jugador j[tam];

    for(int k =0; k<=tam;k++){


        j[k] = tempJug[k];

    }

}




