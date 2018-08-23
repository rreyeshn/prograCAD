#include "Figuras.h"
#include <math.h>
#include <iostream>
#include <winbgim.h>

// CONSTRUCTORES Y DESTRUCTOR
      Punto::Punto(int x, int y){ this->x = x;           this->y = y;}
      Punto::Punto(Punto &otroPunto)    { this->x = otroPunto.x; this->y = otroPunto.y; }
      Punto::~Punto(){x=0; y=0;}

// METODOS
  void Punto::dibujar(){ putpixel(x,y,WHITE);}
  void Punto::X(int x) { this->x = x;}
  void Punto::Y(int y) { this->y = y;}
   int Punto::X()      {return x;}
   int Punto::Y()      {return y;}
Punto& Punto::operator = (Punto& otroPunto){
    this->x = otroPunto.x;
    this->y = otroPunto.y;
    return *this;
}

// Punto3D
Punto3D::Punto3D(int x, int y, int z):Punto(x,y){ this->z = z; }

int  Punto3D::Z()     {return z;}
void Punto3D::Z(int z){this->z = z;}

void Recta::Centrar(Punto& OtroPunto){ Centro = OtroPunto; }

     RectaVertical::RectaVertical(int x){ this->x = x;}
void RectaVertical::dibujar() {
    line(x + Centro.X(),0              ,
         x + Centro.X(),getmaxheight());}

    RectaHorizontal::RectaHorizontal(int y){ this->y = y;}
void RectaHorizontal::dibujar() {
    line(0            ,y + Centro.Y(),
         getmaxwidth(),y + Centro.Y());}

// Circulo  CONSTRUCTORES Y DESTRUCTOR

       Circulo:: Circulo(int x , int y , float )            : Punto(x,y)     { this->r = r;}
       Circulo:: Circulo(Punto &otroPunto, float r = 1)     : Punto(otroPunto){this->r = r;}
       Circulo::~Circulo() {r = 0;}

// Circulo METODOS
double Circulo::area()      { return M_PI*r*r;}
double Circulo::perimetro() { return M_PI*2*r;}
double Circulo::R()         { return r; }
void   Circulo::R(float r)  { this->r = r; }
void   Circulo::dibujar()   { circle(x,y,r); }
Punto& Circulo::centro()    { return *(new Punto(X(),Y()));
}

Ventana::Ventana(int ancho, int alto, int izquierda, int arriba, std::string titulo){
    definicion.alto      = alto;
    definicion.ancho     = ancho;
    definicion.izquierda = izquierda;
    definicion.arriba    = arriba;
    definicion.titulo    = titulo;
}
void Ventana::activar() {
    estado = 1;
    definicion.id =
    initwindow(
               definicion.ancho,
               definicion.alto,
               definicion.titulo.data() ,
               definicion.izquierda,
               definicion.arriba);
}
void Ventana::desactivar(){
    estado = 0;
    closegraph(definicion.id);
}
void Ventana::centroRelativo(Punto& puntoCentro){ Centro = puntoCentro;}
