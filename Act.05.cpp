#include <iostream>
#include <cmath> 
using namespace std;

class IFigura {
public:
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void mostrar() const = 0;
    virtual ~IFigura() {}
};


class FiguraBase : public IFigura {
protected:
    double _area = -1; 

public:
    double calcularArea() override {
        if (_area < 0) {
            cout << "Calculando área...\n";
            _area = calcularAreaReal();
        }
        return _area;
    }

    virtual double calcularAreaReal() = 0;
};


class Triangulo : public FiguraBase {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}

    double calcularAreaReal() override {
        return (base * altura) / 2.0;
    }

    double calcularPerimetro() const override {
        return 3 * base; 
    }

    void mostrar() const override {
        cout << "Triángulo:\n";
        cout << "Base: " << base << ", Altura: " << altura << "\n";
        cout << "Área: " << _area << ", Perímetro: " << calcularPerimetro() << "\n\n";
    }
};


class Circulo : public FiguraBase {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double calcularAreaReal() override {
        return M_PI * radio * radio;
    }

    double calcularPerimetro() const override {
        return 2 * M_PI * radio;
    }

    void mostrar() const override {
        cout << "Círculo:\n";
        cout << "Radio: " << radio << "\n";
        cout << "Área: " << _area << ", Perímetro: " << calcularPerimetro() << "\n\n";
    }
};


class Cuadrado : public FiguraBase {
private:
    double lado;
public:
    Cuadrado(double l) : lado(l) {}

    double calcularAreaReal() override {
        return lado * lado;
    }

    double calcularPerimetro() const override {
        return 4 * lado;
    }

    void mostrar() const override {
        cout << "Cuadrado:\n";
        cout << "Lado: " << lado << "\n";
        cout << "Área: " << _area << ", Perímetro: " << calcularPerimetro() << "\n\n";
    }
};


int main() {
    IFigura* figuras[] = {
        new Triangulo(3.0, 4.0),
        new Circulo(2.5),
        new Cuadrado(5.0)
    };

    for (IFigura* fig : figuras) {
        fig->calcularArea(); 
        fig->mostrar();      
        delete fig;          
    }

    return 0;
}
