#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>
#include "rlutil.h"
#include<iomanip>

using namespace std;

void Lanzamientos(int *v);
void ordenarDescendente (int vec[], int tam);
int Mayorvrepetidos(int vec[], int tam);
int MayorNumrepetidos(int vec[], int tam);
int NumJugadas(int v[], int tam);
void unJugador(string jugador, int tam);
int dosJugadores(string name1, string name2);
void dibujar_dado(char dado[5][8],int x);
void mostrar_num1(int x);
void mostrar_num2(int x);
void mostrar_num3(int x);
void mostrar_num4(int x);
void mostrar_num5(int x);
void mostrar_num6(int x);
void mostrar_dados(int valdados[], int cantdados);
void entreTurnosUnJugador(int puntos, int turnos, string nombre);
void entreTurnosDosJugadores(int turnos, int puntos1, int puntos2, string nombre1, string nombre2);
void entreTurnosDosJugadores2(int turnos, int puntos1, int puntos2, string nombre1, string nombre2);
void puntuacionMasAlta(string nombre, int puntuacion);
void menu();

/// LANZAMIENTO DE DADOS ///
void Lanzamientos( int v[6]){
int i, dimension=6;
 srand(time(0));
 for (i=0;i<dimension;i++){
    v[i]=1+(rand()%6);
 }
}
/// FUNCIONES PARA LAS COMBINACIONES ///
void ordenarDescendente (int vec[], int tam){
    int temp;
    for(int i = 0;i<tam;i++){
        for(int j = 0;j<tam;j++){
            if(vec[j]<vec[j+1]){
                temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }

}

 int Mayorvrepetidos(int vec[], int tam){
     ordenarDescendente(vec,tam);
     int c, b = 0, maxRep, nroRep;
     for(int i=0; i < tam;i++){
        c=1;
        for(int j=0;j<tam;j++){
            if(j!=i){
                if(vec[i] == vec[j]){
                    c++;
                }
            }
        }
        if(b==0){
            maxRep=c;
            nroRep=vec[i];
            b=1;
        }else{
            if(c>maxRep){
                maxRep=c;
                nroRep=vec[i];
            }
        }
     }
return maxRep;
}

int MayorNumrepetidos(int vec[], int tam){
     ordenarDescendente(vec,tam);
     int c, b = 0, maxRep, nroRep;
     for(int i=0; i < tam;i++){
        c=1;
        for(int j=0;j<tam;j++){
            if(j!=i){
                if(vec[i] == vec[j]){
                    c++;
                }
            }
        }
        if(b==0){
            maxRep=c;
            nroRep=vec[i];
            b=1;
        }else{
            if(c>maxRep){
                maxRep=c;
                nroRep=vec[i];
            }
        }
     }
return nroRep;
}

//// COMBINACIONES ///
 bool sumadedados(int vec[],int tam){
 bool resultado=false;
 if(Mayorvrepetidos(vec, tam)==2){
      resultado=true;
}
return resultado;}

 bool TrioX(int vec[], int tam) {
     bool resultado=false;
     if(Mayorvrepetidos(vec,tam)>=3&&Mayorvrepetidos(vec,tam)<6){
        resultado=true;
     }

return resultado;}

bool SexTetox(int vec[],int tam){
bool resultado=false;
int contador=0;
for(int i=0;i<tam;i++){
    if(vec[i]!=6){
        contador++;
    }
}
if(contador==6&&Mayorvrepetidos(vec, tam)==6){
    resultado=true;
}
return resultado;}
bool sexteto6(int vec[],int tam){
bool resultado=false;
   int a=0;
  for(int i=0;i<tam;i++){
    if(vec[i]==6){
       a++;
    }
  }
  if(a==6&&Mayorvrepetidos(vec, tam)==6){
    resultado=true;
  }
return resultado;}

bool escalera(int vec[], int tam) {
bool resultado=false;
    if(Mayorvrepetidos(vec,5)==1){
        resultado=true;
    }
}

int NumJugadas(int v[], int tam){
    int Jugada;
if(sumadedados(v,5)==true){
 Jugada=1;
}
if(TrioX(v,5)==true){
 Jugada=2;
}
if(SexTetox(v,5)==true){
 Jugada=3;
}
if(sexteto6(v,5)==true){
 Jugada=4;
}
return Jugada;
}

//UN JUGADOR

int unJugador(string name){

    system("color 4f");

    //DATOS DEL JUGADOR

    int vec[5]; //DADOS

    //DATOS PARA LOS DADOS

    //PUNTUACION
    int puntuacionActual = 0, maximo = 0, puntuacionFinal = 0, suma = 0, bandera = 0;

    //DATOS PARA COMBINACIONES
    int num, jugada;
    string nombreJugadas;

    //RONDAS
    int ronda = 1;

    //LANZAMIENTO Y PUNTOS
     while (puntuacionFinal < 500){
            maximo = 0;
            entreTurnosUnJugador(puntuacionFinal,ronda,name);
        for(int h = 0; h<3;h++){
           puntuacionActual = 0;
           cout << ""  << endl;
           Lanzamientos(vec);
           num = MayorNumrepetidos(vec,5);
           jugada = NumJugadas(vec,5);
            switch(jugada){
 case 1:
     for(int i=0;i<6;i++){
     puntuacionActual+=vec[i];
     }
     if(puntuacionActual > maximo){
     maximo = puntuacionActual;
     }
    nombreJugadas = "Suma de dados";
     break;
 case 2:
    puntuacionActual=num*10;
    if(puntuacionActual > maximo){
        maximo = puntuacionActual;
    }
    nombreJugadas = "Trio X++";
    break;
 case 3:
    puntuacionActual=num*50;
    if(puntuacionActual > maximo){
        maximo = puntuacionActual;
    }
    nombreJugadas = "Sexteto X ";
    break;
 case 4:
    puntuacionActual=0;
    puntuacionFinal=0;
    if(puntuacionActual > maximo){
        maximo = puntuacionActual;
    }
    nombreJugadas = "Sexteto 6";
    break;
 }

 puntuacionFinal += puntuacionActual;
           cout << "               | Un jugador | Turno de " << name << " | Lanzamiento: "<< h+1 << " | Ronda: " << ronda << " | Puntuacion Obtenida: "<< puntuacionFinal << "|" <<endl;
                cout << "               -------------------------------------------------------------------------------"<<endl;
                cout << "                                            | Maximo puntaje en la ronda: " << maximo <<endl;
                cout << ""<<endl;
                cout << "                                            | Puntaje obtenido en este lanzamiento: " << puntuacionActual <<endl;
                cout << ""<<endl;
                cout << "                                            | Jugada: " << nombreJugadas <<endl;
                mostrar_dados(vec,6);

                //IF PARA QUE SE TERMINE EL JUEGO
                  if (puntuacionFinal > 500) {
                        cout << ""<<endl;
                        cout << ""<<endl;
                        cout << " | Has Ganado, has conseguido una puntuacion de " << puntuacionFinal <<  endl;
                        cout << ""<<endl;
        system(                                                    "pause");
        system(                                                     "cls");
        break;}
        else if(ronda == 10){
                cout << ""<<endl;
                cout << ""<<endl;
             cout << " | El juego se termino por excederse de la cantidad de 10 rondas, has conseguido una puntuacion de " <<  puntuacionFinal<<  endl;
             cout << ""<<endl;
        system(                                                    "pause");
        system(                                                     "cls");
        break;
        }
        cout << " "<<endl;
        system("pause");
        system("cls");
        }
        ronda++;
                system("cls");
    }

  return puntuacionFinal;}
 //DOS JUGADORES

int dosJugadores(string name1, string name2) {
    system("color 4f");

    int cont = 0;

    //DATOS DE LOS JUGADORES
    int vec1[6]; //DADOS 1
    int vec2[6]; //DADOS 2

    //DATOS PARA LOS DADOS

    //PUNTUACION
    int puntuacionActualJ1 = 0, puntuacionActualJ2 = 0, puntuacionFinalJ1 = 0, puntuacionFinalJ2 = 0;

    //DATOS PARA COMBINACIONES
    int jugada, num, bandera;
    string nombreJugadas;

    //RONDAS
    int rondas = 1, rondaJ1 = 0, rondaJ2 = 0;
    bool juegoCorriendo = true;

    //LANZAMIENTO Y PUNTOS
    while (juegoCorriendo) {
        //LANZAMIENTOS DEL JUGADOR 1
        int maximo = 0;
        if (cont % 2 == 0) {
            entreTurnosDosJugadores(rondaJ1 + 1, puntuacionFinalJ1, puntuacionFinalJ2, name1, name2);
            rondaJ1++;
            cont++;
            puntuacionActualJ1 = 0;
            for (int h = 0; h < 3; h++) {
                Lanzamientos(vec1);
                num = MayorNumrepetidos(vec1, 5);
                jugada = NumJugadas(vec1, 5);
                switch (jugada) {
                    case 1:
                        puntuacionActualJ1 = 0; // Reiniciar la puntuación actual si se obtiene una nueva jugada
                        for (int i = 0; i < 6; i++) {
                            puntuacionActualJ1 += vec1[i];
                        }
                        if (puntuacionActualJ1 > maximo) {
                            maximo = puntuacionActualJ1;
                        }
                        nombreJugadas = "Suma de dados";
                        break;
                    case 2:
                        puntuacionActualJ1 = num * 10;
                        if (puntuacionActualJ1 > maximo) {
                            maximo = puntuacionActualJ1;
                        }
                        nombreJugadas = "Trio X++";
                        break;
                    case 3:
                        puntuacionActualJ1 = num * 50;
                        if (puntuacionActualJ1 > maximo) {
                            maximo = puntuacionActualJ1;
                        }
                        nombreJugadas = "Sexteto X";
                        break;
                    case 4:
    puntuacionActualJ1=0;
    puntuacionFinalJ1=0;
    if(puntuacionActualJ1 > maximo){
        maximo = puntuacionActualJ1;
    }
    nombreJugadas = "Sexteto 6";
    break;
 }

          puntuacionFinalJ1 += puntuacionActualJ1;
                if (puntuacionFinalJ1 > 500) {
                        cout << ""<<endl;
                        cout << ""<<endl;
                    cout << "El juego se termino, " << name1 << " consiguio una puntuacion de " << puntuacionFinalJ1 << endl;
                        cout << ""<<endl;
                        juegoCorriendo = false;
                    system("pause");
                    system("cls");
                    break;
                } else if (rondaJ1 >= 10) {
                        cout << ""<<endl;
                        cout << ""<<endl;
                    cout << "El juego se termino por excederse de la cantidad de 10 rondas, has conseguido una puntuacion de " << puntuacionFinalJ1 << endl;
                        cout << ""<<endl;
                        juegoCorriendo = false;
                    system("                               pause");
                    system("                               cls");
                    break;
                }
                cout << "               | Dos jugadores | Turno de " << name1 << " | Lanzamiento: " << h + 1 << " | Ronda: " << rondaJ1 << " | Puntuacion Obtenida: " << puntuacionFinalJ1 << "|" << endl;
                cout << "               -------------------------------------------------------------------------------" << endl;
                cout << "                                            | Maximo puntaje en la ronda: " << maximo << endl;
                cout << "" << endl;
                cout << "                                            | Puntaje obtenido en este lanzamiento: " << puntuacionActualJ1 << endl;
                cout << "" << endl;
                cout << "                                            | Jugada: " << nombreJugadas << endl;
                mostrar_dados(vec1, 6);
                cout << " " << endl;
                system("pause");
                system("cls");
            }
        }
        //LANZAMIENTOS DEL JUGADOR 2
        else {
            entreTurnosDosJugadores2(rondaJ2 + 1, puntuacionFinalJ1, puntuacionFinalJ2, name1, name2);
            rondaJ2++;
            cont++;
            puntuacionActualJ2 = 0;
            for (int h = 0; h < 3; h++) {
                Lanzamientos(vec2);
                num = MayorNumrepetidos(vec2, 6);
                jugada = NumJugadas(vec2, 6);
                switch (jugada) {
                    case 1:
                        puntuacionActualJ2 = 0; // Reiniciar la puntuación actual si se obtiene una nueva jugada
                        for (int i = 0; i < 6; i++) {
                            puntuacionActualJ2 += vec2[i];
                        }
                        if (puntuacionActualJ2 > maximo) {
                            maximo = puntuacionActualJ2;
                        }
                        nombreJugadas = "Suma de dados";
                        break;
                    case 2:
                        puntuacionActualJ2 = num * 10;
                        if (puntuacionActualJ2 > maximo) {
                            maximo = puntuacionActualJ2;
                        }
                        nombreJugadas = "Trio X++";
                        break;
                    case 3:
                        puntuacionActualJ2 = num * 50;
                        if (puntuacionActualJ2 > maximo) {
                            maximo = puntuacionActualJ2;
                        }
                        nombreJugadas = "Sexteto X";
                        break;
                    case 4:
    puntuacionActualJ2=0;
    puntuacionFinalJ2=0;
    if(puntuacionActualJ2 > maximo){
        maximo = puntuacionActualJ2;
    }
    nombreJugadas = "Sexteto 6";
    break;
 }
               puntuacionFinalJ2 += puntuacionActualJ2;
                if (puntuacionFinalJ2 > 500) {
                        cout << ""<<endl;
                        cout << ""<<endl;
                    cout << "El juego se termino, " << name2 << " consiguio una puntuacion de " << puntuacionFinalJ2 << endl;
                        cout << ""<<endl;
                        juegoCorriendo = false;
                    system("pause");
                    system("cls");
                    break;
                } else if (rondaJ2 >= 10) {
                        cout << ""<<endl;
                        cout << ""<<endl;
                    cout << "El juego se termino por excederse de la cantidad de 10 rondas, has conseguido una puntuacion de " << puntuacionActualJ2 << endl;
                        cout << ""<<endl;
                        juegoCorriendo = false;
                    system("pause");
                    system("cls");
                    break;
                }
                cout << "               | Dos jugadores | Turno de " << name2 << " | Lanzamiento: " << h + 1 << " | Ronda: " << rondaJ2 << " | Puntuacion Obtenida: " << puntuacionFinalJ2 << "|" << endl;
                cout << "               -------------------------------------------------------------------------------" << endl;
                cout << "                                            | Maximo puntaje en la ronda: " << maximo << endl;
                cout << "" << endl;
                cout << "                                            | Puntaje obtenido en este lanzamiento: " << puntuacionActualJ2 << endl;
                cout << "" << endl;
                cout << "                                            | Jugada: " << nombreJugadas << endl;
                mostrar_dados(vec2, 6);
                cout << " " << endl;
                system("pause");
                system("cls");
            }
        }
    }
     if (puntuacionFinalJ1 > puntuacionFinalJ2) {
            return puntuacionFinalJ1;
    } else if (puntuacionFinalJ2 > puntuacionFinalJ1) {
        return puntuacionFinalJ2;
    }
}
void mostrarPuntuacionMasAlta(string nombre, int puntuacion){
    system("color 4f");
            system("pause");
    system("cls");
    cout << "            ---------------------------------------------------------------------------------"<<endl;
    cout << "                El/La jugador/a "<< nombre << " tuvo una puntuacion de " << puntuacion << " siendo la mas alta del juego " <<endl;
    cout << "            ---------------------------------------------------------------------------------"<<endl;
        system("pause");
    system("cls");
}

// MENU

void menu() {
    int opcion;
    int ultimaPuntuacionP1 = 0, ultimaPuntuacionP2 = 0;
    int ultimaPuntuacion = 0, puntuacionMasAlta = 0;
    string name, name1, name2;
    string nombre;

    while (opcion != 4) {
        system("color 4f");

        cout << "                                         ------------- MENU DE OPCIONES --------------" << endl;
        cout << "                                         |                                           |"<<endl;
        cout << "                                         |         1. UN JUGADOR                     |" << endl;
        cout << "                                         |         2. DOS JUGADORES                  |" << endl;
        cout << "                                         |         3. MOSTRAR PUNTUACION MAS ALTA    |" << endl;
        cout << "                                         |         4. Salir                          |" << endl;
        cout << "                                         |                                           |"<<endl;
        cout << "                                         ---------------------------------------------" << endl;
        cout << endl;
        cout << "                                                          Opcion: *";
        cin >> opcion;

        switch (opcion) {
            case 1:
    //INGRESO DE NOMBRE
    system("cls");
    cout << "                                              Opcion De Un Jugador:" << endl;
    cout << endl;
    cout <<"                                                Ingrese un Nombre:.. ";
    cin >> name;
    system("pause");
    system("cls");
                ultimaPuntuacion = unJugador(name);
                if(ultimaPuntuacion > puntuacionMasAlta){
                    puntuacionMasAlta = ultimaPuntuacion;
                    nombre = name;
                }
                break;
            case 2:
                    //NOMBRES
    system("cls");
    cout << "                                              Opcion De Dos Jugadores:" << endl;
    cout << endl;
    cout <<"                                               Ingrese el nombre del Jugador 1:.. ";
    cin >> name1;
    system("pause");
    system("cls");
    cout << "                                              Opcion De Dos Jugadores:" << endl;
    cout << endl;
    cout << "                                               Nombre del jugador 1: " << name1 << endl;
    cout << endl;
    cout <<"                                               Ingrese el nombre del Jugador 2:.. ";
    cin >> name2;
    system("pause");
    system("cls");
        cout << "                                              Opcion De Dos Jugadores:" << endl;
    cout << endl;
    cout << "                                               Nombre del jugador 1: " << name1 << endl;
    cout << endl;
    cout <<"                                               Nombre del jugador 2: " << name2 << endl;
    system("pause");
    system("cls");
                ultimaPuntuacion = dosJugadores(name1,name2);
                if(ultimaPuntuacion >= puntuacionMasAlta){
                    puntuacionMasAlta = ultimaPuntuacion;
                }
                break;
            case 3:
                mostrarPuntuacionMasAlta(nombre,puntuacionMasAlta);
                break;
            default:
                if (opcion > 4) {
                    cout << "                           El Numero De La Opcion Ingresada No Es Valido, Vuelva a Intentarlo" << endl;
                }
                system("pause");
                system("cls");
                break;
        }
    }
    cout << "                                                    Salio del Programa" << endl;
}

void entreTurnosUnJugador(int puntos, int turnos, string nombre){
    system("color 4f");
     cout << "               -----------------------------------------------------------------------" << endl;
     cout << "                                                                                      " << endl;
     cout << "                                            Ronda Nro "<<turnos<<"                    " <<endl;
     cout << "                                                                                      " << endl;
     cout << "                                         Puntaje de "<<nombre<<": "<<puntos<<"        " << endl;
     cout << "                                                                                      " << endl;
     cout << "               -----------------------------------------------------------------------" << endl;
     cout << "" << endl;
    system("pause");
    system("cls");
}

void entreTurnosDosJugadores(int turnos, int puntos1, int puntos2, string nombre1, string nombre2){
    system("color 4f");
     cout << "               ---------------------------------------------------------------------" << endl;
     cout << "                                                                                    " << endl;
     cout << "                                            Ronda Nro "<<turnos<<"                  " <<endl;
     cout << "                                                                                    " << endl;
     cout << "                                            Turno de: "<<nombre1<<"                         "<< endl;
     cout << "                                                                                    " << endl;
     cout << "                                          Puntaje de "<<nombre1<<": "<<puntos1<<"               " << endl;
     cout << "                                                                                    " << endl;
     cout << "                                          Puntaje de "<<nombre2<<": "<<puntos2<<"               " << endl;
     cout << "                                                                                    " << endl;
     cout << "               ---------------------------------------------------------------------" << endl;
     cout << "" << endl;
    system("pause");
    system("cls");
}

void entreTurnosDosJugadores2(int turnos, int puntos1, int puntos2, string nombre1, string nombre2){
    system("color 4f");
     cout << "               ---------------------------------------------------------------------" << endl;
     cout << "                                                                                    " << endl;
     cout << "                                            Ronda Nro "<<turnos<<"                  " <<endl;
     cout << "                                                                                    " << endl;
     cout << "                                            Turno de: "<<nombre2<<"                         "<< endl;
     cout << "                                                                                    " << endl;
     cout << "                                          Puntaje de "<<nombre1<<": "<<puntos1<<"               " << endl;
     cout << "                                                                                    " << endl;
     cout << "                                          Puntaje de "<<nombre2<<": "<<puntos2<<"               " << endl;
     cout << "                                                                                    " << endl;
     cout << "               ---------------------------------------------------------------------" << endl;
     cout << "" << endl;
    system("pause");
    system("cls");
}

void dibujar_dado(char dado[5][8],int x)
{
    x=x*7;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<8;j++)
        {
            gotoxy(j+x+1, i+4);
            switch(dado[i][j])
            {
           case 'Q':
            cout << (char)201;
            break;
           case 'E':
            cout << (char)187;
            break;
           case 'Z':
            cout << (char)200;
            break;
           case 'C':
            cout << (char)188;
            break;
           case 'W':
            cout << (char)205;
            break;
           case 'A':
            cout << (char)186;
            break;
           case 'S':
            cout << (char)4;
            break;
           case '-':
            cout << (char)32;
            break;
            }
        }
    }
}

void mostrar_num1(int x)
{
    char dado[5][8]=
    {
        {"QWWWWWE"},
        {"A-----A"},
        {"A--S--A"},
        {"A-----A"},
        {"ZWWWWWC"}
    };
    dibujar_dado(dado,x);
}
void mostrar_num2(int x)
{
    char dado[5][8]=
    {
        {"QWWWWWE"},
        {"A-S---A"},
        {"A-----A"},
        {"A---S-A"},
        {"ZWWWWWC"}
    };
    dibujar_dado(dado,x);
}
void mostrar_num3(int x)
{
    char dado[5][8]=
    {
        {"QWWWWWE"},
        {"A-S---A"},
        {"A--S--A"},
        {"A---S-A"},
        {"ZWWWWWC"}
    };
    dibujar_dado(dado,x);
}
void mostrar_num4(int x)
{
    char dado[5][8]=
    {
        {"QWWWWWE"},
        {"A-S-S-A"},
        {"A-----A"},
        {"A-S-S-A"},
        {"ZWWWWWC"}
    };
    dibujar_dado(dado,x);
}
void mostrar_num5(int x)
{
    char dado[5][8]=
    {
        {"QWWWWWE"},
        {"A-S-S-A"},
        {"A--S--A"},
        {"A-S-S-A"},
        {"ZWWWWWC"}
    };
    dibujar_dado(dado,x);
}
void mostrar_num6(int x)
{
   char dado[5][8]=
   {
       {"QWWWWWE"},
       {"A-SSS-A"},
       {"A-----A"},
       {"A-SSS-A"},
       {"ZWWWWWC"}
   };
   dibujar_dado(dado,x);
}

void mostrar_dados(int valdados[], int cantdados)
{
    int i;
    for (i=0;i<cantdados;i++)
    {

        switch(valdados[i])
        {
        case 1:
            mostrar_num1(i);
            break;
        case 2:
            mostrar_num2(i);
            break;
        case 3:
            mostrar_num3(i);
            break;
        case 4:
            mostrar_num4(i);
            break;
        case 5:
            mostrar_num5(i);
            break;
        case 6:
            mostrar_num6(i);
            break;
        }
    }
}
