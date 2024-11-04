#include <stdio.h>
#include <stdlib.h>

struct n {
    int value;
    struct n *next;
    struct n *prew;
};

typedef struct n node;

//Bu fonksiyon cift yonlu bagli listede de ayni sekilde calisacaginan degisime ihtiyaci yoktur
void bastir(node *r) {
    while (r != NULL) {
        printf("%d\n", r->value);
        r = r->next;
    }
}

node *siraliEkle(node *r, int newValue) {
    if (r == NULL) {
        r = (node *) malloc(sizeof(node));
        r->next = NULL;
        r->prew = NULL;
        r->value = newValue;
        return r;
    }
    if (r->value > newValue) {
        node *temp = (node *) malloc(sizeof(node));
        temp->value = newValue;
        temp->next = r;
        r->prew = temp;
        return temp;
    }
    node *iter = r;
    while (iter->next != NULL && iter->next->value < newValue) {
        iter = iter->next;
    }
    node *temp = (node *) malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->prew = iter;
    // Sondeki degeri silip silmedigimizin kontrolunu yapmak onemlidir.
    // Cunku sondeki degerin NEXT'inin NULL'u gostermesi bir problem degil iken
    // NULL'dan tekrar prew ile son degere donme senaryosu problem olusturur
    if (temp->next != NULL) {
        temp->next->prew = temp;
    }
    temp->value = newValue;
    return r;
}

node *sil(node *r, int selectedValue) {
    node *temp;
    node *iter = r;

    if (r->value == selectedValue) {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter->next != NULL && iter->next->value != selectedValue) {
        iter = iter->next;
    }
    if (iter->next == NULL) {
        printf("SAYI BULUNAMADI\n");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    // Sondeki degeri silip silmedigimizin kontrolunu yapmak onemlidir.
    // Cunku sondeki degerin NEXT'inin NULL'u gostermesi bir problem degil iken
    // NULL'dan tekrar prew ile son degere donme senaryosu problem olusturur
    if (iter->next != NULL){
        iter->next->prew = iter;
    }
    return r;
}

int main() {
    node *root;
    root = NULL;

    root = siraliEkle(root, 1);
    root = siraliEkle(root, 3);
    root = siraliEkle(root, 2);
    root = siraliEkle(root, 4);

    root = sil(root, 1);
    root = sil(root, 4);
    bastir(root);

}