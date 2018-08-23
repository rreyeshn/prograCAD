#include <iostream>
class FigurasGeometricas{
    public:
        virtual void  dibujar()=0;
};
class Figuras2D : public FigurasGeometricas{
    public:
        virtual double area()      = 0;
        virtual double perimetro() = 0;
};
class Punto: public FigurasGeometricas{
    protected:
        int x, y;
    public:
             Punto(int x = 0, int y = 0);
             Punto(Punto&);
            ~Punto();
        void dibujar(void);
        int  X();
        int  Y();
        void X(int);
        void Y(int);
        Punto & operator=(Punto& otroPunto);
};
class Punto3D: public Punto{
    private:
        int z;
    public:
        Punto3D(int x = 0, int = 0, int = 0);
        int Z();
        void Z(int);
};
class Recta: public FigurasGeometricas{
    protected:
        Punto Centro;
    public:
        void Centrar(Punto& OtroPunto);
};
class RectaVertical: public Recta{
    private:
        int x;
    public:
          RectaVertical(int x = 0);
     void dibujar();
};
class RectaHorizontal: public Recta{
    private:
        int y;
    public:
          RectaHorizontal(int y = 0);
     void dibujar();
};


class Circulo:
        public Punto,
        public Figuras2D{
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

