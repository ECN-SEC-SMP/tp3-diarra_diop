#include <iostream>
using namespace std;

// #################Création d'une classe point template#####################
template <typename T>
class Point
{protected  :
    T x;
    T y;

public:
    // Constructor avec deux paramètres
    Point(const T &xCoord, const T &yCoord)
    {
        x = xCoord;
        y = yCoord;
    };
    // translater prend en argument respectivement une paire d'éléments du même type que les coordonnées
    void translater(const T &a_x, const T &a_y)
    {
        x += a_x;
        y += a_y;
    };
    // Un constructeur de recopie prenant en paramètre une référence constante à un point
    Point(const Point<T> &other)
    {
        x = other.x;
        y = other.y;
    };

    // Accessors
    T getX() const
    {
        return x;
    };
    T getY() const
    {
        return y;
    };

    // setters
    void setX(const T &newX)
    {
        x = newX;
    };
    void setY(const T &newY)
    {
        y = newY;
    };

    // surcharge de l'opérateur d'affichage sous forme de fonction amie
    friend ostream &operator<<(ostream &os, const Point<T> &p)
    {
        os << "(" << p.getX() << ", " << p.getY() << ")";
        return os;
    }
};

// ####################Classe Forme abstraite##########################
template <typename T, typename mesure>
class Forme
{
protected:
    Point<T> centre; // utilisation de la classe Point comme attribut
public:
    // Constructeur avec un point centre
    Forme(const Point<T> &centre):centre(centre)
    {}
    // NB: type de retour générique T pour les méthodes abstraites
    // méthodes abstraites perimetre
    virtual mesure perimetre() const = 0;
    // méthodes abstraites surface
    virtual mesure surface() const = 0;

    // surcharge de l'opérateur d'affichage sous forme de fonction amie
    friend ostream &operator<<(ostream &os, const Forme &forme)
    {
        os << "(" << forme.centre.getX() << ", " << forme.centre.getY() << ")";
        return os;
    }
};

// ################Classe Rectangle dérivée de Forme##################
template <typename T, typename mesure>
class Rectangle : public Forme<T, mesure>
{

protected:
    // attributs en plus de l'attribut centre hérité de Forme
    T largeur;
    T longueur;

public:
    // Constructeur
     Rectangle(const T &largeur, const T &longueur)
        : Forme<T, mesure>(Point<T>(largeur / 2, longueur / 2)),
          largeur(largeur),
          longueur(longueur)
    {}

    // Implémentation des méthodes abstraites
    // override pour indiquer que ces méthodes remplacent les versions de la classe de base
    mesure perimetre() const override
    {
        return 2 * (largeur + longueur);
    }

    mesure surface() const override
    {
        return largeur * longueur;
    }
    // surcharge de l'opérateur d'affichage sous forme de fonction amie
    friend ostream &operator<<(ostream &os, const Rectangle &rectangle)
    {
        os << "Rectangle(largeur: " << rectangle.largeur << ", longueur: " << rectangle.longueur << ", centre: " << rectangle.centre << ")";
        return os;
    }
};
//###########################"##classe carree###################################
template <typename T, typename mesure>
class Carree : public Forme<T, mesure>
{
protected:
    T cote;
public:
    // Constructeur
    Carree(const T &cote)
        : Forme<T, mesure>(Point<T>(cote / 2, cote / 2)),
          cote(cote)
    {}
     // Implémentation des méthodes abstraites
    // override pour indiquer que ces méthodes remplacent les versions de la classe de base
    mesure perimetre() const override
    {
        return 4 * cote;
    }

    mesure surface() const override
    {
        return cote*cote;
    }
    // surcharge de l'opérateur d'affichage sous forme de fonction amie
    friend ostream &operator<<(ostream &os, const Carree &carree)
    {
        os << "carree de cote: " << carree.cote << " " << carree.centre << ")";
        return os;
    }
};

// ####################Fonction main pour tester la classe Point###############
int main()
{
    // Création d'un point de type int
    Point<int> p1(3, 4);
    cout << "Point p1: " << p1 << endl;
    // Translation
    p1.translater(2, 3);
    cout << "Point p1 apres translation: " << p1 << endl;
    // Test du constructeur de la classe rectangle
    Rectangle<int, double> rect(10, 5);
    cout << "Rectangle: " << rect << endl;
    cout << "Perimetre du rectangle: " << rect.perimetre() << endl;
    cout << "Surface du rectangle: " << rect.surface() << endl;
    Carree<int, double> carre(5);
    cout << "Carree: " << carre << endl;
    cout << "Perimetre du carree: " << carre.perimetre() << endl;
    cout << "Surface du carree: " << carre.surface() << endl;

    return 0;
}