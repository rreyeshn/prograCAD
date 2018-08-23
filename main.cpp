#include <iostream>
#include "Figuras.h"
#include <winbgim.h>
using namespace std;

int main()
{
    Ventana v1(400,400);
    v1.centroRelativo( *(new Punto(200,200)));

    v1.activar();

    RectaHorizontal EjeX(0);
    RectaVertical EjeY(0);

    EjeX.Centrar(v1.Centro);
    EjeY.Centrar(v1.Centro);

    EjeX.dibujar();
    EjeY.dibujar();

    getch();
    v1.desactivar();
}
