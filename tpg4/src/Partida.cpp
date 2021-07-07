#include "Partida.h"

Partida::Partida (Nat alto, Nat ancho, Coordenada s, Coordenada ll, set<Coordenada> f, set<Coordenada> p,set<Coordenada> ch): mapa_(alto, ancho, s, ll, f, p, ch), actual_(s), inmunidad_(0), puntaje_(0) {
    if (mapa_.chocolates()[actual_.first][actual_.second]){
        inmunidad_= 10;
        mapa_.chocolates()[actual_.first][actual_.second]= false;
    }
}

void Partida::resetearPartida() {
    mapa_.resetearChocos();
    puntaje_= 0;
    actual_= mapa_.salida();
    if (mapa_.chocolates()[actual_.first][actual_.second]){
        inmunidad_= 10;
        mapa_.chocolates()[actual_.first][actual_.second]= false;
    }else{
        inmunidad_= 0;
    }
}

void Partida:: moverse(Direccion dir) {
    Coordenada destino= actual_;
    if (dir == ARRIBA)
        destino.second = destino.second + 1;
    if (dir == ABAJO)
        destino.second = destino.second - 1;
    if (dir == DERECHA)
        destino.first++;
    if (dir == IZQUIERDA)
        destino.first--;
    int x= destino.first, y= destino.second;
    if (x >= 0 && x<mapa_.alto() && y>= 0 && y< mapa_.ancho()){
        if(!mapa_.paredes()[x][y]){
            actual_= destino;
            puntaje_++;
            if (mapa_.chocolates()[x][y]){
                inmunidad_= 10;
                mapa_.chocolates()[x][y]= false;
            }else{
                if (inmunidad_> 0)
                    inmunidad_--;
            }
        }
    }
}

Coordenada Partida:: actual() const {
    return actual_;
}

bool Partida:: gano(){
    return (actual_== mapa_.llegada());
}

bool Partida:: perdio(){
 return (mapa_.radioFantasma()[actual_.first][actual_.second] && inmunidad_== 0);
}

Nat Partida:: puntaje() const {
    return puntaje_;
}

Nat Partida:: inmunidad() const {
    return inmunidad_;
}

const Mapa& Partida::mapa() const {
    return mapa_;
}