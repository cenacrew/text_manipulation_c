#ifndef ROPE_H
#define ROPE_H

typedef struct RopeNode
{
    char *text; // Texte stocké dans ce nœud
    size_t length; // Longueur du texte
    size_t threshold; // Seuil pour la division des feuilles en branches
    struct RopeNode *left; // Sous-arbre gauche
    struct RopeNode *right; // Sous-arbre droit
} RopeNode;

typedef struct Rope
{
    RopeNode *root; // Racine de l'arbre
} Rope;

Rope* rope_new(char *text);
void rope_insert_at(Rope *rope, char *text, size_t pos);
size_t rope_len(Rope *rope);
void rope_delete(Rope *rope);

#endif /* ROPE_H */
