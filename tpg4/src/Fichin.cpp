#include "Fichin.h"

Fichin:: Fichin(Nat largo, Nat alto, Coordenada inicio, Coordenada llegada, set<Coordenada> fantasmas, set<Coordenada> paredes, set<Coordenada> chocolates):
partida_(largo, alto, inicio, llegada, fantasmas, paredes, chocolates), jugando_(false), jugador_(""), jugadores_(){}

void Fichin:: nuevaPartida(Jugador j) {
    partida_.resetearPartida();
    jugando_= true;
    jugador_= j;
}


ResultadoMovimiento Fichin:: mover(Direccion dir) {
    partida_.moverse(dir);
    ResultadoMovimiento res= SIGUE;
    if(partida_.gano()){
        Nat puntosAct= partida_.puntaje();
        if (jugadores_.count(jugador_)){
            Nat puntosAnt= jugadores_[jugador_];
            if (puntosAct< puntosAnt){
                jugadores_[jugador_]= puntosAct;
            }
        }else{
            jugadores_[jugador_]= puntosAct;
        }
        res= GANO;
    }else{
        if (partida_.perdio())
            res= PERDIO;
    }
    jugando_= !(partida_.gano() || partida_.perdio());
    return res;
}

map<Jugador,Nat> Fichin:: verRanking() const {
    return jugadores_;
}

pair<Jugador, Nat> Fichin:: objetivo() const{
    Nat puntos= jugadores_.at(jugador_);
    Nat obj2= 0; //puntos;
    Jugador obj1= jugador_;
    for (pair<Jugador, Nat> i: jugadores_) {
        Nat sig= i.second;
        if(obj2<= sig && sig< puntos){
            obj2= sig;
            obj1= i.first;
        }
    }
    if (obj2== 0)
        obj2= puntos;
    return make_pair(obj1,obj2);
}

bool Fichin::jugando() const{
    return jugando_;
}

Jugador Fichin:: jugadorActual() const{
    return jugador_;
}

Coordenada Fichin:: jugador() const{
    return partida_.actual();
}

Nat Fichin:: cantidadMovimientos() const {
    return partida_.puntaje();
}

Nat Fichin:: inmunidad() const {
    return partida_.inmunidad();
}

Nat Fichin:: ancho() const{
    return partida_.ancho();
};

Nat Fichin:: alto() const {
    return partida_.alto();
}

Coordenada Fichin:: inicio() const {
    return partida_.salida();
}

Coordenada Fichin:: llegada() const {
    return partida_.llegada();
}

set<Coordenada> Fichin:: paredes() const {
    return partida_.conjParedes();
}

set<Coordenada> Fichin:: fantasmas() const {
    return partida_.conjFantasmas();
}

set<Coordenada> Fichin:: chocolatesIniciales() const {
    return partida_.conjChocos();
}

set<Coordenada> Fichin:: chocolatesActuales() const {
    return partida_.chocosActuales();
}