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
            Nat puntosAnt= jugadores_[jugador_]->second;
            if (puntosAct< puntosAnt){
                (jugadores_[jugador_])->second = puntosAct;
            }
        }else{
            listaJugadores_.push_front(make_pair(jugador_,puntosAct));
            jugadores_.insert(make_pair(jugador_,listaJugadores_.begin()));
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
    map<Jugador, Nat> jugadores;
    for(pair<Jugador, Nat> i: listaJugadores_){
        jugadores[i.first] = i.second;
    }
    return jugadores;
}

pair<Jugador, Nat> Fichin:: objetivo() const{
    Nat puntos= jugadores_.at(jugador_)->second;
    Nat obj2= 0; //puntos;
    Jugador obj1= jugador_;
    for (pair<Jugador, Nat> i: listaJugadores_) {
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

const Mapa& Fichin:: mapa() const {
    return partida_.mapa();
}