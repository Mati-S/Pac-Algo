#ifndef TP4_2021_C1_MAPA_H
#define TP4_2021_C1_MAPA_H

#include "Tipos.h"

class Mapa{
public:
    Mapa(Nat alto, Nat ancho, Coordenada s, Coordenada ll, set<Coordenada> f, set<Coordenada> p,set<Coordenada> ch);
    void resetearChocos();
    Coordenada salida() const;
    Coordenada llegada() const;
    vector< vector<bool> >& fantasmas();
    vector< vector<bool> >& paredes();
    vector< vector<bool> >& chocolates();
    Nat alto() const;
    Nat ancho() const;
    set<Coordenada> conjChocos() const;
    set<Coordenada> conjFantasmas() const;
    set<Coordenada> conjParedes() const;
    set<Coordenada> chocosActuales() const;
private:
    Nat alto_;
    Nat ancho_;
    Coordenada salida_;
    Coordenada llegada_;
    vector< vector<bool> > chocolates_;
    vector< vector<bool> >fantasmas_;
    vector< vector<bool> > paredes_;
    set<Coordenada> chocosOri_;
    set<Coordenada> fantasmasOri_;
    set<Coordenada> paredesOri_;
};

#endif //TP4_2021_C1_MAPA_H
