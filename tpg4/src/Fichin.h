#include "Tipos.h"
#include "Mapa.h"
#include "Partida.h"
#include "string_map.h"

#ifndef TP4_2021_C1_FICHIN_H
#define TP4_2021_C1_FICHIN_H

class Fichin{
public:
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
    const Mapa& mapa() const;

private:
    //Mapa mapa_;
    Partida partida_;
    bool jugando_;
    Jugador jugador_;
    string_map<list<pair<Jugador, Nat> >::iterator > jugadores_;
    list<pair<Jugador, Nat> > listaJugadores_;
};

#endif //TP4_2021_C1_FICHIN_H
