#include "Tipos.h"
#include "Mapa.h"
#include "Partida.h"

#ifndef TP4_2021_C1_FICHIN_H
#define TP4_2021_C1_FICHIN_H

class Fichin{
public:
    // @march: ¿porqué no reciben el mapa?
    Fichin(Nat largo, Nat alto, Coordenada inicio, Coordenada llegada, set<Coordenada> fantasmas, set<Coordenada> paredes, set<Coordenada> chocolates);
    void nuevaPartida(Jugador j);
    ResultadoMovimiento mover(Direccion dir);
    map<Jugador, Nat> verRanking() const;
    pair<Jugador, Nat> objetivo() const;
    bool jugando() const;
    Jugador jugadorActual() const;
    Coordenada jugador() const;
    Nat cantidadMovimientos() const;
    Nat inmunidad() const;
    // @march: ¿porqué no devuelven el mapa?
    Nat ancho() const;
    Nat alto() const;
    Coordenada inicio() const;
    Coordenada llegada() const;
    set<Coordenada> paredes() const;
    set<Coordenada> fantasmas() const;
    set<Coordenada> chocolatesIniciales() const;
    set<Coordenada> chocolatesActuales() const;

private:
    //Mapa mapa_;
    Partida partida_;
    bool jugando_;
    Jugador jugador_;
    map<Jugador, Nat> jugadores_;
};

#endif //TP4_2021_C1_FICHIN_H
