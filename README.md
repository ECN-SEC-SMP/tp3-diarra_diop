# TP – Programmation Orientée Objet : Les templates en C++

## 🎯 Objectifs du TP

Ce TP a pour but de manipuler plusieurs aspects importants du C++ :

- la programmation générique avec **templates**  
- la **surcharge d’opérateurs**
- l’héritage et le **polymorphisme**
- les **classes abstraites**
- la manipulation de **structures de données** (`vector`)

---

## 📌 Contenu du travail

### 1️⃣ Classe `Point<T>`

Créer une classe template représentant un point du plan.

La classe doit inclure :

- deux attributs `x` et `y`,
- un constructeur avec deux paramètres pour l'abscisse et l'ordonnée
- un constructeur de recopie,
- des accesseurs/mutateurs,
- une méthode  
  ```cpp
  void translate(const T& dx, const T& dy);

---

### 2️⃣ Classe abstraite Forme<T,M>

Créer une classe représentant une forme géométrique centrée sur un point.

Elle doit contenir :

- un attribut centre de type Point<T>,
- un constructeur prenant un centre,
- deux méthodes abstraites :
    ```cpp
  void translate(const T& dx, const T& dy);
une surcharge de operator<< en fonction amie.

---

### 3️⃣ Formes géométriques "concrètes"
Créer une classe dérivant de Forme<T,M> contenant largeur et longueur, et fixer automatiquement le centre en (largeur / 2, longueur / 2)
redéfinir :
- perimetre()
- surface()
- surcharger operator<<
Le programme principal (main.cpp) doit tester :
- l’affichage,
- les méthodes de calcul,

---

### 4️⃣ Jeux d'essai
Pour tester le bon fonctionnement de l'implémentation des différentes classes, des jeux d'essai ont été fait dans le programme principal.
Ci-dessous le retour.

<img width="1422" height="458" alt="image" src="https://github.com/user-attachments/assets/145867f0-e077-4523-a5f8-04081712c4d7" />
 Remarque :
Le problème de la division entière se pose. En effet, pour l'exemple du rectangle de longueur 10 et de largeur 5, le centre devrait être: (5, 2.5). Comme pour le carre ou on a (2,2) au lieu de (2.5, 2.5).
Le type float dans le deuxieme parametre du template ne change rien :
<img width="1209" height="686" alt="image" src="https://github.com/user-attachments/assets/96ac21d9-7421-4d10-89ec-707760701008" />



---
### 5️⃣ Spécilisation
Spécialiser la méthode translate() pour les points de type string.
Il s'agit de declarer la fonction translater() en tant que fonction template. La declaration est faite en dehors de la classe comme suit: 
```cpp
   //Specialisation de la fonction translater pour le type string
  template<> void Point<string>::translater(const string &a_x, const string &a_y)
    {
        x += a_x;
        y += a_y;
    }

```
<img width="1257" height="450" alt="image" src="https://github.com/user-attachments/assets/dc156484-100f-4342-9477-97dd5f84bd9e" />


---
### 6️⃣ Liste des formes
A l’aide de la structure de données vector<>, on définit la classe listeFormes qui, outre les opérations classiques de consultation ou d’ajout de formes dans la liste permet de :
 — calcule la surface totale de la liste
 — calcule la boite englobante de la liste de formes (le plus petit rectangle aligné sur les axes qui contient l’ensemble des formes de la liste)
 La chose la plus importante dans cette section est de gerer la liste de forme du fait que Forme est une classe virtuelle donc on ne peut pas instancier ses objets abstraits.
 #### A retenir:
 Il faut utiliser des pointeurs et gerer l'allocation de la mémoire en supprimant la mémoire occupée une fois la ressource utilisée. Ce qui est réalisé en créant un destructeur virtuel dans la classe Forme de sorte à appeler le bon destructeur Rectangle ou Carre. 
<img width="1049" height="307" alt="image" src="https://github.com/user-attachments/assets/364c1842-99ea-4878-88a0-12decc18a836" />

#### La boite englobante
A compléter

--- 

## 7️⃣ Compilation et exécution

### 🧰 A la main
Utiliser **g++** (ou tout compilateur compatible C++17 ou supérieur) :

```bash
g++ main.cpp -o prog
```
```bash
./prog
```
### Makefile
```bash
make
```


##  8️⃣Auteur
Mame Diarra DIOP_SEC 2027

📅 TP réalisé le 17 Novembre 2025
