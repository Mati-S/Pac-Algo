#include "Mapa.h"

#ifndef TP4_2021_C1_PARTIDA_H
#define TP4_2021_C1_PARTIDA_H

class Partida{
public:
    // @march: Esto no recibe el mapa como parámetro.
    Partida(Nat alto, Nat ancho, Coordenada s, Coordenada ll, set<Coordenada> f, set<Coordenada> p,set<Coordenada> ch);
    void resetearPartida();
    void moverse(Direccion dir);
    Coordenada actual() const;
    // @march: Podría ser const a derecha.
    bool gano();
    bool perdio();
    Nat puntaje() const;
    Nat inmunidad() const;
    Nat ancho() const;
    Nat alto() const;
    Coordenada salida() const;
    Coordenada llegada() const;
    // @march: ¿Porque no devuelven el mapa por referencia constante?
    set<Coordenada> conjChocos() const;
    set<Coordenada> conjFantasmas() const;
    set<Coordenada> conjParedes() const;
    set<Coordenada> chocosActuales() const;

private:
    Mapa mapa_;
    Coordenada actual_;
    Nat inmunidad_;
    Nat puntaje_;
};

#endif //TP4_2021_C1_PARTIDA_H
