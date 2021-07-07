#include "aed2_Fichin.h"

// Completar

aed2_Fichin:: aed2_Fichin(Nat largo, Nat alto, Coordenada inicio, Coordenada llegada, set<Coordenada> paredes, set<Coordenada> fantasmas, set<Coordenada> chocolates):
        fichin_(largo, alto, inicio,llegada, fantasmas, paredes, chocolates){
}

void aed2_Fichin:: nuevaPartida(Jugador j) {
    fichin_.nuevaPartida(j);
}

// IMPORTANTE: Debe devolver:
// - GANO si al mover se gana la partida
// - PERDIO si al mover se pierde la partida
// - SIGUE en cualquier otro caso
ResultadoMovimiento aed2_Fichin:: mover(Direccion d) {
    return fichin_.mover(d);
}

bool aed2_Fichin:: alguienJugando() const {
    return fichin_.jugando();
}

Jugador aed2_Fichin:: jugadorActual() const{
    return fichin_.jugadorActual();
}

map<Jugador, Puntaje> aed2_Fichin:: ranking() const{
    return fichin_.verRanking();
}

pair<Jugador, Puntaje> aed2_Fichin:: objetivo() const{
    return fichin_.objetivo();
}

Coordenada aed2_Fichin:: jugador() const{
    Coordenada c= fichin_.jugador();
    return make_pair(c.first+1,c.second+1);
}

Nat aed2_Fichin:: cantidadMovimientos() const{
    return fichin_.cantidadMovimientos();
}

Nat aed2_Fichin:: inmunidad() const{
    return fichin_.inmunidad();
}

Nat aed2_Fichin:: largo() const{
    return fichin_.mapa().alto();
}

Nat aed2_Fichin:: alto() const{
    return fichin_.mapa().ancho();
}

Coordenada aed2_Fichin::  inicio() const{
    Coordenada c= fichin_.mapa().salida();
    return make_pair(c.first+1,c.second+1);
}

Coordenada aed2_Fichin:: llegada() const{
    Coordenada c= fichin_.mapa().llegada();
    return make_pair(c.first+1,c.second+1);
}

set<Coordenada> aed2_Fichin:: paredes() const{
    return fichin_.mapa().conjParedes();
}

set<Coordenada> aed2_Fichin:: fantasmas() const{
    return fichin_.mapa().conjFantasmas();
}

set<Coordenada> aed2_Fichin:: chocolatesIniciales() const{
    return fichin_.mapa().conjChocos();
}

set<Coordenada> aed2_Fichin:: chocolatesActuales() const {
    return fichin_.mapa().chocosActuales();
}

