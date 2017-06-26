#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>

using namespace std;


int dim = 15;




struct Jugador{
    string nombre;
    int intento[6];
    int total;
};



    int menu();
    void JugadorNuevo(Jugador j[]);
    void Partida(Jugador[]);

    void AgregaJugador(Jugador[],int []);
    void ModficaTamanoJugadores(Jugador [],int *);
    void MuestraGanador(Jugador[]);
    void Resultados(Jugador[]);



int main()
{
menu();
Jugador jugadores[dim];

//
//ptrPuntos = puntos;


int totales[dim];




int op= 0;
    do {

        cout<<menu()<<endl;

        cin>>op;
        int item = 0;
        char opcion;

        switch (op){

            case 1:


                JugadorNuevo(jugadores);



                break;

            case 0:

                return 0;


            break;

            default :

            break;



        }




        }while(op!='0');
    }


int menu(){ //Metodo encargado de Mostrar el de Menu en Consola

    int resultado=0;

    string menu = "Control de Puntaje\n";
    menu+= "1 - Inicio de Partida \n";
    menu+= "0 - SALIR\n\n";

    cout<<menu<<endl;


return resultado;
//Fin de Metodo Menu
}

void JugadorNuevo(Jugador j[]){ /*Metodo que generar un Jugador nuevo y lo agrega al Arreglo de Jugadores*/
    int puntos[6] = {10,5,4,3,2,1};

    int tam = sizeof(*j)/sizeof(Jugador);
    int pos;
    int num = 0;
    int cont=0;
    char op;
    string Ganador;

        do{
        pos = (j[cont].nombre=="")?cont:0;

        if(pos!=0){
            string nombre="";


                cout<<"Digite el nombre del jugador?"<<endl;
                    cin>>nombre;
            j[pos].nombre = nombre;

    for (int i=0;i<=6; i++){
        srand(time(0));

        num = rand()%6;

        j[pos].intento[i]= puntos[num];



        j[pos].total+=j[pos].intento[i];

       // Ganador = (j[pos].total>j[++pos].total)?j[pos].nombre:"perdedor";
            }


        }


        cont++;
        cout<<"Desear agregar otro Jugador?||'s'/'n'||"<<endl;
        cin>>op;
        }while ((cont<=tam)||(op!='n'));


    }






void Resultados(Jugador js[]){//Metodo que evalua el puntaje mayor y muestra el ganador

int tam = (sizeof(*js)/sizeof(Jugador));
int i=0;
string Ganador;
int ptosGanador = 0;
    do {
        if((js[i].total>js[++i].total)&& (js[i].total >30)){

            Ganador = js[i].nombre;
            ptosGanador = js[i].total;

            } else{
              cout<<"Lo siento no hay ganador"<<endl;

             }
       i++;



      }while(i<=tam);

 cout<<"El Ganador es "<< Ganador <<" con " <<ptosGanador<<"puntos"<<endl;

    }







