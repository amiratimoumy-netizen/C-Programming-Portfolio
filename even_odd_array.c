
#include <stdio.h>

int saisirNb() {
    int n;
    do {
        printf("Entrez un nombre entier positif : ");
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

int parite(int a) {
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}

float moyenne(int T[], int n) {
    int somme = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (parite(T[i]) == 1) {
            somme += T[i];
            count++;
        }
    }

    if (count == 0)
        return 0;

    return (float)somme / count;
}

int produit(int T[], int n) {
    int product = 1;

    for (int i = 0; i < n; i++) {
        if (parite(T[i]) == 0) {
            product *= T[i];
        }
    }

    return product;
}

void afficheTab(int T[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int main() {
    int m = saisirNb();
    int V[100];

    if (m > 100) {
        printf("Taille maximale depassee.\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        printf("V[%d] = ", i);
        scanf("%d", &V[i]);
    }

    afficheTab(V, m);

    float moy = moyenne(V, m);
    int prod = produit(V, m);

    printf("Moyenne des nombres pairs : %f\n", moy);
    printf("Produit des nombres impairs : %d\n", prod);

    return 0;
}
