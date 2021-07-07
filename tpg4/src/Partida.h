#include "Mapa.h"

#ifndef TP4_2021_C1_PARTIDA_H
#define TP4_2021_C1_PARTIDA_H

class Partida{
public:
    Partida(Nat alto, Nat ancho, Coordenada s, Coordenada ll, set<Coordenada> f, set<Coordenada> p,set<Coordenada> ch);
    void resetearPartida();
    void moverse(Direccion dir);
    Coordenada actual() const;
    bool gano();
    bool perdio();
    Nat puntaje() const;
    Nat inmunidad() const;
    const Mapa& mapa() const;

private:
    Mapa mapa_;
    Coordenada actual_;
    Nat inmunidad_;
    Nat puntaje_;
};

#endif //TP4_2021_C1_PARTIDA_H
