#include <iostream>
#include <winbgim.h>

class FigurasGeometrica{
    public:
        virtual void  dibujar()=0;
};

//╔═══════════════════════════════════════════════════════════════════════════╗
//║ FigurasGeometrica                                                        ║
//║  │                                                                        ║
//║  ├─[Punto]                                                                ║
//║ ...   │                                                                   ║
//║      ...                                                                  ║
//╚═══════════════════════════════════════════════════════════════════════════╝

//════════════════════════════════════════════════════════════════════════════╗
    class Punto : public FigurasGeometrica{                                //║
                                                                            //║
        protected:                                                          //║
                    int x, y, color;                                        //║
        public:                                                             //║
                    // CONSTRUCTORES Y DESTRUCTOR                           //║
                    Punto(int x = 0, int y = 0, int color = WHITE);         //║
                    Punto(Punto&);                                          //║
                   ~Punto();                                                //║
                                                                            //║
                    // METODOS HEREDADOS                                    //║
                    void dibujar(void);                                     //║
                                                                            //║
                    // GETTERS & SETTERS                                    //║
                int X();     int Y();                                       //║
               void X(int); void Y(int);                                    //║
               void COLOR(int);                                             //║
                                                                            //║
                    // SOBRECARGA DE OPERADORES                             //║
             Punto& operator = (Punto& P);                                  //║
                                                                            //║
                    // UTILITARIOS                                          //║
             double distancia(Punto& p);                                    //║
};                                                                          //║
//════════════════════════════════════════════════════════════════════════════╝


//╔═══════════════════════════════════════════════════════════════════════════╗
//║ FigurasGeometrica                                                        ║
//║  │                                                                        ║
//║  ├─Punto                                                                  ║
//║ ... ├─[Plano]                                                             ║
//║    ...                                                                    ║
//╚═══════════════════════════════════════════════════════════════════════════╝

//════════════════════════════════════════════════════════════════════════════╗
    class Plano: public Punto{                                              //║
                                                                            //║
        private:                                                            //║
                float escala;                                               //║
                int unidades;                                               //║
        public:                                                             //║
                 // CONSTRUCTOR Y DESTRUCOR                                 //║
                 Plano(  Punto& Centro,                                     //║
                         float escala = 50,                                 //║
                           int unidad =  1,                                 //║
                           int color  = WHITE);                             //║
                                                                            //║
                 // METODOS HEREDADOS                                       //║
            void dibujar();                                                 //║
};                                                                          //║
//════════════════════════════════════════════════════════════════════════════╝

  class Punto3D : public Punto{

    private:

            int z;

    public:

            Punto3D( int x = 0, int = 0, int = 0);
           ~Punto3D();
        int Z();
       void Z(int);

};

//════════════════════════════════════════════════════════════════════════════╗
  class Figura2D : public FigurasGeometrica{                               //║
                                                                            //║
    public:                                                                 //║
                                                                            //║
        virtual double area()      = 0;                                     //║
        virtual double perimetro() = 0;                                     //║
                                                                            //║
};                                                                          //║
//════════════════════════════════════════════════════════════════════════════╝


class Recta : public FigurasGeometrica{

    protected:

        int m, b, color;

    public:

            Recta(int m = 0 , int b = 0  , int color = WHITE);

        int M();
        int B();
       void M(int m);
       void B(int b);
        int Y(int x);
       void dibujar();

};

class Segmento : public Recta {

    private:

        Punto I;
        Punto F;

    public:

        Segmento( Punto , Punto , int color);
        void dibujar();
};

class Circulo:
        public Punto,
        public Figura2D{
    private:
        double r;
    public:
             Circulo(int x = 0 , int y = 0, float r = 0);
             Circulo(Punto &, float);
            ~Circulo();
        void dibujar();
       double area();
      double perimetro();
      double R();
        void R(float);
      Punto& centro();
};

struct defVentana{
    int ancho;
    int alto;
    int izquierda;
    int arriba;
    std::string titulo;
    int id;
};
class Ventana{
    struct defVentana definicion;
    int estado;
    public:
        Punto Centro;
        Ventana(
                int ancho = 400,
                int alto  = 400,
                int izquierda      = 0,
                int arriba         = 0,
                std::string titulo = "Sin título");
        void activar(void);
        void centroRelativo(Punto &);
        void desactivar(void);
};

