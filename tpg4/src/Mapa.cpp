#include "Mapa.h"

Mapa:: Mapa(Nat alto, Nat ancho, Coordenada s, Coordenada ll, set<Coordenada> f, set<Coordenada> p,set<Coordenada> ch):
alto_(alto), ancho_(ancho), salida_(make_pair(s.first-1, s.second-1)), llegada_(make_pair(ll.first-1, ll.second-1)), chocosOri_(ch), fantasmasOri_(f), paredesOri_(p) {
    fantasmas_ = vector < vector < bool >> (alto, vector<bool>(ancho, false));
    for (Coordenada i: f) {
        int x= i.first-1, y= i.second-1;
        for (int j = max(-3,-x); j <= min(3,(int)alto-1-x); ++j) {
            for (int k = max(-3,-y); k <= min(3,(int)ancho-1-y); ++k) {
                if (abs(k)+abs(j)<= 3)
                    fantasmas_[x+j][y+k]= true;
            }
        }
    }
    paredes_ = vector < vector < bool >> (alto, vector<bool>(ancho, false));
    for (Coordenada i: p) {
        paredes_[i.first-1][i.second-1] = true;
    }
    chocolates_ = vector < vector < bool >> (alto, vector<bool>(ancho, false));
    for (Coordenada i: ch) {
        chocolates_[i.first-1][i.second-1] = true;
    }
    /*for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            std::cout<<fantasmas_[i][j]<<" ";
        }
        std:: cout<<endl;
    }
    std::cout<<endl;*/
}

void Mapa:: resetearChocos() {
    for (Coordenada i: chocosOri_) {
        chocolates_[i.first-1][i.second-1] = true;
    }
}

Coordenada Mapa:: salida() const {
    return salida_;
}

Coordenada Mapa:: llegada() const{
    return llegada_;
}

vector< vector<bool> >& Mapa:: fantasmas() {
    return fantasmas_;
}

vector< vector<bool> >& Mapa:: paredes() {
    return paredes_;
}

vector< vector<bool> >& Mapa:: chocolates() {
    return chocolates_;
}

Nat Mapa:: alto() const {
    return alto_;
}

Nat Mapa::ancho() const {
    return ancho_;
}

set<Coordenada> Mapa::conjChocos() const {
    return chocosOri_;
}

set<Coordenada> Mapa::conjFantasmas() const {
    return fantasmasOri_;
}

set<Coordenada> Mapa::conjParedes() const {
    return paredesOri_;
}

set<Coordenada> Mapa::chocosActuales() const {
    set<Coordenada> res;
    for (int i = 0; i < alto_; ++i) {
        for (int j = 0; j < ancho_; ++j) {
            if (chocolates_[i][j])
                res.insert(make_pair(i+1,j+1));
        }
    }
    return res;
}