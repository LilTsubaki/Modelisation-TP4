#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "vector3d.h"
#include <string>

class Maillage
{
	Vector3D test;
	std::vector<Vector3D> geom; //contient les points du maillage
    std::vector<int> topo; //contient des triplets d'indice pour chaque triangle du maillage
    std::vector<Vector3D> normales; //contient les normales au point

    public:
        Maillage();
        Maillage(std::vector<Vector3D> geo, std::vector<int> top, std::vector<Vector3D> norm) : geom(geo), topo(top), normales(norm) {}
        Maillage(std::vector<Vector3D> geo, std::vector<int> top) : geom(geo), topo(top) {}


        // Utilitaires
        static Maillage lectureOff(const std::string nom);
        void Ecriture(std::string nom);
        ~Maillage();
};

