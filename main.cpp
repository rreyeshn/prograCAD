#include <iostream>
#include "Figuras.h"
#include <winbgim.h>
using namespace std;

int main()
{
    Ventana v1(400,400);
    Punto CentroVentana(200,200);
    v1.centroRelativo( CentroVentana);

    v1.activar();

    Plano Cartesiano( CentroVentana , 50 , 1 , BLUE );

    Cartesiano.dibujar();

    Recta A(1,0,RED);

    Segmento AB(  *(new Punto(300,100)),  *(new Punto(100,300)), GREEN);

    AB.dibujar();

    A.dibujar();



    getch();
    v1.desactivar();
}
