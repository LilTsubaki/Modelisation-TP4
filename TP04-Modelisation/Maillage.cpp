#include "stdafx.h"
#include "maillage.h"
#include <math.h>
#define M_PI           3.14159265358979323846

Maillage::Maillage()
{

}

void Maillage::calculNormalTriangle()
{
	Vector3D ab;
	Vector3D ac;
	for(int i = 0; i < topo.size(); i+=3)
	{
		ab = geom.at(topo.at(i+1)) - geom.at(topo.at(i));
		ac = geom.at(topo.at(i+2)) - geom.at(topo.at(i));
		normales.push_back(ab^ac);
	}
}


void Maillage::Ecriture(std::string nom)
{
    std::ofstream fichier(nom, std::ios::out | std::ios::trunc);
    if(fichier)
    {
        fichier << "o " << nom << std::endl;
        fichier << std::endl;
        Vector3D temp;
        for (int i = 0; i < geom.size(); ++i)
        {
             temp = geom.at(i);
             fichier << "v " << temp.x() << " " << temp.y() << " " << temp.z() << std::endl;
        }
        fichier << std::endl;
        for (int i = 0; i < normales.size(); ++i)
        {
             temp = normales.at(i);
             fichier << "vn " << temp.x() << " " << temp.y() << " " << temp.z() << std::endl;
        }
        fichier << std::endl;
        for (int i = 0; i < topo.size(); i+=3)
        {
             fichier << "f " << topo.at(i)+1 << " " << topo.at(i+1)+1 << " " << topo.at(i+2)+1 << std::endl;
        }
        fichier.close();  // on referme le fichier
    }
    else
    {
        std::cerr << "Erreur à l'ouverture !" << std::endl;
    }
}

Maillage Maillage::lectureOff(std::string nom)
{
    std::vector<Vector3D> geom;
    std::vector<int> topo;

    std::ifstream fichier (nom);
    if(fichier)
    {
        int delimiterPos_1;
        int delimiterPos_2;
        int delimiterPos_3;
        int delimiterPos_4;
        std::string readLine;

        getline(fichier,readLine);
        if (readLine != "OFF")
        {
            std::cout << "The file to read is not in OFF format." << std::endl;
            return Maillage(geom, topo);
        }

        getline(fichier,readLine);
        delimiterPos_1 = readLine.find(" ", 0);
        int nbSommets = atoi(readLine.substr(0,delimiterPos_1+1).c_str());
        delimiterPos_2 = readLine.find(" ", delimiterPos_1);
        int nbTriangles = atoi(readLine.substr(delimiterPos_1,delimiterPos_2 +1).c_str());

        std::cout << "nb sommets : " << nbSommets << std::endl;
        std::cout << "nb triangles : " << nbTriangles << std::endl;

        for (int n=0; n<nbSommets; n++)
        {
            Vector3D temp;
            getline(fichier,readLine);
            delimiterPos_1 = readLine.find(" ", 0);
            temp.setX(atof(readLine.substr(0,delimiterPos_1).c_str()));
            delimiterPos_2 = readLine.find(" ", delimiterPos_1+1);
            temp.setY(atof(readLine.substr(delimiterPos_1,delimiterPos_2 ).c_str()));
            delimiterPos_3 = readLine.find(" ", delimiterPos_2+1);
            temp.setZ(atof(readLine.substr(delimiterPos_2,delimiterPos_3 ).c_str()));
			geom.push_back(temp);
            //std::cout << temp.x() << "\t" << temp.y() << "\t" << temp.z() << "\t" << std::endl;
        }

        for (int n=0; n<nbTriangles; n++)
        {
            getline(fichier,readLine);
            delimiterPos_1 = readLine.find(" ", 0);
            delimiterPos_2 = readLine.find(" ", delimiterPos_1+1);
            topo.push_back(atoi(readLine.substr(delimiterPos_1,delimiterPos_2 ).c_str()));
            delimiterPos_3 = readLine.find(" ", delimiterPos_2+1);
            topo.push_back(atoi(readLine.substr(delimiterPos_2,delimiterPos_3 ).c_str()));
            delimiterPos_4 = readLine.find(" ", delimiterPos_3+1);
            topo.push_back(atoi(readLine.substr(delimiterPos_3,delimiterPos_4 ).c_str()));

            /*cout << facades[n].v1 << "\t" << facades[n].v2 << "\t" <<
            facades[n].v3 << "\t" << endl;*/
        }
        fichier.close();
    }
    else
    {
        std::cout << "erreur à l'ouverture du fichier" << std::endl;
    }
    return Maillage(geom, topo);
}

std::vector<Vector3D> Maillage::getGeom() const
{
    return geom;
}

void Maillage::setGeom(const std::vector<Vector3D> &value)
{
    geom = value;
}

std::vector<int> Maillage::getTopo() const
{
    return topo;
}

void Maillage::setTopo(const std::vector<int> &value)
{
    topo = value;
}

std::vector<Vector3D> Maillage::getNormales() const
{
    return normales;
}

void Maillage::setNormales(const std::vector<Vector3D> &value)
{
    normales = value;
}


Maillage::~Maillage()
{

}
