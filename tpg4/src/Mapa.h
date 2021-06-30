#ifndef TP4_2021_C1_MAPA_H
#define TP4_2021_C1_MAPA_H

#include "Tipos.h"

class Mapa{
public:
    Mapa(Nat alto, Nat ancho, Coordenada s, Coordenada ll, set<Coordenada> f, set<Coordenada> p,set<Coordenada> ch);
    void resetearChocos();
    Coordenada salida() const;
    Coordenada llegada() const;
    // @march: Estos los haría const a derecha. Con chocolates no se puede
    // ya que lo usan para modificar el mapa. Sería más prolijo que haya otra
    // función para eliminar un chocolate.
    void eliminarChocolate(Coordenada);
    const vector< vector<bool> >& fantasmas();
    const vector< vector<bool> >& paredes();
    const vector< vector<bool> >& chocolates();
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
    // @march: Este fantasmas_ ya no son solo los fantasmas. También afecta
    // el rep. Charlar.
    vector< vector<bool> >fantasmas_;
    vector< vector<bool> > paredes_;
    set<Coordenada> chocosOri_;
    set<Coordenada> fantasmasOri_;
    set<Coordenada> paredesOri_;
};

#endif //TP4_2021_C1_MAPA_H
