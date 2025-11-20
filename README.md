# TP – Programmation Orientée Objet : Manipulation de fichier en C++

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

###2️⃣ Classe abstraite Forme<T,M>

Créer une classe représentant une forme géométrique centrée sur un point.

Elle doit contenir :

- un attribut centre de type Point<T>,
- un constructeur prenant un centre,
- deux méthodes abstraites :
    ```cpp
  void translate(const T& dx, const T& dy);

---

une surcharge de operator<< en fonction amie.

---

## 3️⃣ Formes géométriques "concrètes"
Créer une classe dérivant de Forme<T,M> contenant largeur et longueur, et fixer automatiquement le centre en (largeur / 2, longueur / 2)
redéfinir :
- perimetre()
- surface()
- surcharger operator<<
Le programme principal (main.cpp) doit tester :
- l’affichage,
- les méthodes de calcul,

---

## 4️⃣ Spécilisation
Spécialiser la méthode translate() pour les points de type string en utilisant std::swap pour échanger les coordonnées.

---
## 5️⃣ Liste des formes

--- 

## 6️⃣ Compilation et exécution

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


## 7️⃣ Auteur

### Noms : Mame Diarra DIOP
### Filière : SEC_2027
### Université : Ecole Centrale de Nantes

📅 TP réalisé le 17 Novembre 2025
