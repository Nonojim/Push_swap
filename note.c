/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:50:00 by npederen          #+#    #+#             */
/*   Updated: 2025/03/16 20:29:21 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BASE 256 // Utilisation de 8 bits pour chaque passe

// Fonction d'échange pour l'Insertion Sort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insertion Sort pour terminer rapidement quand la liste est presque triée
void insertion_sort(int *arr, int n) {
    int i = 1;
    while (i < n) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
        i++;
    }
}

// Radix Sort Optimisé
void radix_sort(int *arr, int n) {
    int *output = malloc(n * sizeof(int));  // Tableau temporaire
    int count[BASE] = {0};                 // Table de comptage
    bool sorted = false;                    // Early stopping

    // Trouver le max et min pour gérer les négatifs
    int min = arr[0], max = arr[0];
    int i = 1;
    while (i < n) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        i++;
    }

    // Décalage pour rendre tous les nombres positifs
    int shift = -min;
    i = 0;
    while (i < n) {
        arr[i] += shift;
        i++;
    }
    
    // Détermination du nombre de passes (octets nécessaires)
    int max_shifted = max + shift;
    int passes = 0;
    while (max_shifted > 0) {
        passes++;
        max_shifted /= BASE;
    }

    // Radix Sort en base 256 (8 bits à la fois)
    int pass = 0;
    while (pass < passes && !sorted) {
        sorted = true;  // On suppose que c'est trié

        // Réinitialiser le comptage
        for (i = 0; i < BASE; i++) count[i] = 0;

        // Comptage des fréquences
        for (i = 0; i < n; i++) {
            int digit = (arr[i] >> (8 * pass)) & 0xFF;
            count[digit]++;
            if (i > 0 && arr[i] < arr[i - 1]) sorted = false;
        }

        // Early Stopping si déjà trié
        if (sorted) break;

        // Cumuler les fréquences
        for (i = 1; i < BASE; i++) {
            count[i] += count[i - 1];
        }

        // Réorganisation des éléments
        for (i = n - 1; i >= 0; i--) {
            int digit = (arr[i] >> (8 * pass)) & 0xFF;
            output[--count[digit]] = arr[i];
        }

        // Copie dans le tableau original
        for (i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        pass++;
    }

    // Annuler le décalage
    i = 0;
    while (i < n) {
        arr[i] -= shift;
        i++;
    }

    // Optimisation finale : Insertion Sort si nécessaire
    insertion_sort(arr, n);

    free(output);
}

// Fonction d'affichage
void print_array(int *arr, int n) {
    int i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

// Test
int main() {
    int arr[] = {170, -45, 75, -90, 802, 24, 2, 66, -255, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Avant tri:\n");
    print_array(arr, n);

    radix_sort(arr, n);

    printf("Après tri:\n");
    print_array(arr, n);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "stack_utils.h"

// Vérifie si la pile est déjà triée
bool is_sorted(t_stack *a) {
    t_node *current = a->top;
    while (current && current->next) {
        if (current->value > current->next->value)
            return false;
        current = current->next;
    }
    return true;
}

// Tri par insertion pour 3 à 5 nombres
void small_sort(t_stack *a, t_stack *b) {
    int size = stack_size(a);
    if (size == 2 && a->top->value > a->top->next->value)
        sa(a);
    else if (size == 3) {
        if (a->top->value > a->top->next->value)
            sa(a);
        if (a->top->value > a->bottom->value)
            rra(a);
        if (a->top->next->value > a->bottom->value) {
            sa(a);
            ra(a);
        }
    } else {
        while (stack_size(a) > 3)
            pb(a, b);
        small_sort(a, b);
        while (!is_empty(b))
            pa(a, b);
    }
}

// Radix Sort optimisé pour 500 nombres
void radix_sort(t_stack *a, t_stack *b) {
    int size = stack_size(a);
    int max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;

    for (int bit = 0; bit < max_bits; bit++) {
        int count = size;
        while (count--) {
            if ((a->top->value >> bit) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (!is_empty(b))
            pa(a, b);
        if (is_sorted(a))
            return;
    }
}

// Fonction principale
void push_swap(t_stack *a, t_stack *b) {
    if (is_sorted(a))
        return;
    int size = stack_size(a);
    if (size <= 5)
        small_sort(a, b);
    else
        radix_sort(a, b);
}

// Parsing et remplissage de la pile
void parse_args(t_stack *a, char **argv) {
    for (int i = 1; argv[i]; i++) {
        long num = atol(argv[i]);
        if (num > INT_MAX || num < INT_MIN) {
            fprintf(stderr, "Erreur: Nombre invalide\n");
            exit(EXIT_FAILURE);
        }
        push(a, (int)num);
    }
}

// Main
int main(int argc, char **argv) {
    if (argc < 2) return 1;

    t_stack a, b;
    init_stack(&a);
    init_stack(&b);

    parse_args(&a, argv);
    push_swap(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "stack_utils.h"

// Initialisation de la pile
void init_stack(t_stack *stack) {
    stack->top = NULL;
    stack->bottom = NULL;
}

// Vérifie si la pile est vide
bool is_empty(t_stack *stack) {
    return stack->top == NULL;
}

// Retourne la taille de la pile
int stack_size(t_stack *stack) {
    int count = 0;
    t_node *current = stack->top;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Ajoute un élément en haut de la pile
void push(t_stack *stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node) exit(EXIT_FAILURE);
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    if (!stack->bottom)
        stack->bottom = new_node;
}

// Retire et retourne l'élément du haut de la pile
int pop(t_stack *stack) {
    if (is_empty(stack)) exit(EXIT_FAILURE);
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Libère la mémoire de la pile
void free_stack(t_stack *stack) {
    while (!is_empty(stack))
        pop(stack);
}

#ifndef STACK_UTILS_H
#define STACK_UTILS_H

#include <stdbool.h>

typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    t_node *bottom;
} t_stack;

// Gestion des piles
void init_stack(t_stack *stack);
bool is_empty(t_stack *stack);
int stack_size(t_stack *stack);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void free_stack(t_stack *stack);


#endif

ARG=$(seq -100 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l
