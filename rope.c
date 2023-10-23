#include "rope.h"
#include <stdlib.h>
#include <string.h>

RopeNode* create_rope_node(char *text)
{
    RopeNode* node = (RopeNode*)malloc(sizeof(RopeNode));
    if (node)
    {
        node->text = strdup(text);
        node->length = strlen(text);
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

Rope* rope_new(char *text)
{
    Rope* rope = (Rope*)malloc(sizeof(Rope));
    if (rope)
    {
        rope->root = create_rope_node(text);
    }
    return rope;
}

void rope_insert_at(Rope *rope, char *text, size_t pos)
{
    RopeNode *node = rope->root;
    if (node)
    {
        size_t len = rope_len(rope);
        if (pos <= len)
        {
            rope_insert_at_node(node, text, pos);
        }
    }
    
    if (node->length >= node->threshold)
    {
        // Diviser le nœud en deux nouvelles branches
        RopeNode *newLeft = create_rope_node(strndup(node->text, pos));
        RopeNode *newRight = create_rope_node(strndup(node->text + pos, node->length - pos));

        // Mettre à jour les nœuds gauche et droit
        node->left = newLeft;
        node->right = newRight;

        // Mettre à jour le texte et la longueur du nœud actuel
        free(node->text);
        node->text = strdup("");
        node->length = 0;
    }
}

size_t rope_len(Rope *rope)
{
    // Calcul de la longueur totale de la corde ici
    // ...
    return 0;
}

void delete_rope_node(RopeNode *node)
{
    if (node)
    {
        free(node->text);
        free(node);
    }
}

void delete_rope_recursive(RopeNode *node)
{
    if (node)
    {
        delete_rope_recursive(node->left);
        delete_rope_recursive(node->right);
        delete_rope_node(node);
    }
}

void rope_delete(Rope *rope)
{
    if (rope)
    {
        delete_rope_recursive(rope->root);
        free(rope);
    }
}
