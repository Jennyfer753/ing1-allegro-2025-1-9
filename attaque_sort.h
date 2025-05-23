// attaque_sort.h
#ifndef ATTAQUE_SORT_H
#define ATTAQUE_SORT_H

#include <allegro.h>

// Définition de la structure Sort
typedef struct {
    int pv_retire_min; //nombre de pv minimum que retire le sort
    int pv_retire_max; //nombre de pv max que retire le sort
    int pa_requis; //nombre de pa que vaut le sort
    char nom[30]; // nom du sort
    int portee_min; //portée minimum du sort
    int portee_max; //portée max du sort
    int chance_echec; //pourcentage d'échec du sort
    int zone_effet; // 0 = cible unique, 1 = cases adjacentes, etc.
    BITMAP* animation[10]; // Tableau pour les frames d'animation
    int nb_frames;
    int frame_delay; // Délai entre chaque frame
} Sort;

//Définition structure pour la classe des personnages
typedef struct {
    Sort sorts[4]; // Chaque personnage a 4 sorts
    char nom_classe[50];
    BITMAP* sprite; // Sprite pour les animations de personnages
    int x; //Numéro de la ligne
    int y; // Numéro de la colonne
    int puissanceCAC; //Puissance pour les attaques au corps à corps
    int pv;
} ClassePersonnage;

// Prototypes des fonctions
void initialiser_sort(Sort* sort, const char* nom, int pv_min, int pv_max, int pa,
                     int portee_min, int portee_max, int echec, int zone);
void charger_animations_sort(Sort* sort, const char* prefixe_nom_fichier);
void liberer_sort(Sort* sort);

// Fonctions pour initialiser les sorts de chaque classe
void initialiser_sorts_mage(ClassePersonnage* classe);
void initialiser_sorts_maitresse_dragon(ClassePersonnage* classe);
void initialiser_sorts_savant_fou(ClassePersonnage* classe);
void initialiser_sorts_archere(ClassePersonnage* classe);

// Fonctions pour lancer les sorts
int lancer_sort(Sort* sort, int x_source, int y_source, int x_cible, int y_cible,
               BITMAP* buffer, int* frame_counter);
void afficher_portee_sort(Sort* sort, int x_source, int y_source,
                         int** grille, int largeur, int hauteur, BITMAP* buffer);

#endif // ATTAQUE_SORT_H
