#include "Figuras.h"
#include <math.h>
#include <iostream>
#include <winbgim.h>


//      PUNTO

// ==== Constructores y destructor ===========

        Punto::Punto(int x, int y, int color){

        this -> x     = x;
        this -> y     = y;
        this -> color = color;
}

        Punto::Punto(Punto &P){

        this -> x     = P.x;
        this -> y     = P.y;
        this -> color = P.color;}

        Punto::~Punto(){ x = 0; y = 0; color = 0;}
// ------------------------------------------

//  PUNTO
// ==== METODOS ===============================================================
 double Punto::distancia(Punto& p) {

        return sqrt( pow( (p.x - x),2) + pow( (p.y - y),2));

}

   void Punto::dibujar() {

        putpixel(x,y,color);

}
   void Punto::COLOR(int color) { this->color = color;}

   void Punto::X(int x) { this -> x = x; }
   void Punto::Y(int y) { this -> y = y; }

    int Punto::X() { return x; }
    int Punto::Y() { return y; }

 Punto& Punto::operator = (Punto& P) {

        this -> x     = P.x;
        this -> y     = P.y;
        this -> color = P.color;

        return *this;

}

// PUNTO3D
// ==== Constructores y destructor ===========

        Punto3D::Punto3D(int x, int y, int z)
                :Punto(x,y) {

        this -> z = z;

}
        Punto3D::~Punto3D() { z = 0; }

// ==== METODOS ===============================================================
    int Punto3D::Z() { return z; }

   void Punto3D::Z(int z) { this -> z = z; }

// ----------------------------------------------------------------------------

        Plano::Plano(Punto& Centro, float escala, int unidades , int color){

        x = Centro.X();
        y = Centro.Y();
        this -> color  = color;
        this -> escala = escala;
        this -> unidades = unidades;

}
   void Plano::dibujar(){

        setcolor(color);

        line( x , 0 , x             , getmaxheight() );
        line( 0 , y , getmaxwidth() , y              );
       /* for(int x = c ; x >= 0 ; x=x-escala)
            line(x,Centro.Y(),x,Centro.Y()+3);
        c = getmaxwidth();
        for(int x = Centro.X() ; x <= c ; x=x+escala)
            line(x,Centro.Y()-3,x,Centro.Y());

        for(int y = Centro.Y() ; y >= 0 ; y=y-escala)
            line(Centro.X()-3,y,Centro.X(),y);
        c = getmaxheight();
        for(int y = Centro.Y() ; y <= c ; y=y+escala)
            line(Centro.X(),y,Centro.X()+3,y);

        */
    }

        Recta::Recta(int m , int b, int color){

            this -> m     = m;
            this -> b     = b;
            this -> color = color;

}

   void Recta::M( int m) { this -> m = m; }
   void Recta::B( int b) { this -> b = b; }

    int Recta::M() { return m; }
    int Recta::B() { return b; }

    int Recta::Y(int x) { return m*x + b; }

   void Recta::dibujar(){

        setcolor(color);

        line(0, this -> Y(0) , getmaxwidth(), this -> Y(getmaxwidth()));

}

        Segmento::Segmento(Punto I, Punto F , int color)
                 :Recta((F.Y()-I.Y())/(F.X()-I.X()) ,0, color){

                 this -> I     = I;
                 this -> F     = F;
}

   void Segmento::dibujar(){

        setcolor(color);
        line(I.X(),I.Y(),F.X(),F.Y());
   }

// Circulo  CONSTR1UCTORES Y DESTRUCTOR

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
