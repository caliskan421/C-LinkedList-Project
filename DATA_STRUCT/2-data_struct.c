#include <stdio.h>
#include <stdlib.h>

// Bir yapı tanımı ile düğüm yapısını oluşturuyoruz
struct n {
    int value;               // Düğümde saklanacak veriyi temsil eden tam sayı
    struct n *next;      // Sonraki düğümü işaret eden işaretçi
};

// Yapı tanımı ile `node` isimli bir tip oluşturuyoruz
// (`node` artık `struct n` ile aynı anlama geliyor)
typedef struct n node;

void bastir(node *r) {   // Listenin başlangıç düğümünü alır
    while (r != NULL) {   // Düğüm NULL olana kadar devam eder
        printf("%d\n", r->value); // Düğümdeki veriyi ekrana yazdırır
        r = r->next;          // Sonraki düğüme geçer
    }
}

void ekle(node *r, int value) {

    while (r->next != NULL) {
        r = r->next; // Listenin son düğümüne gelene kadar devam eden döngü
    }

    r->next = (node *) malloc(sizeof(node)); // Yeni bir düğüm için bellek ayırıyoruz
    r->next->value = value;        // Yeni düğüme verilen değeri atıyoruz
    r->next->next = NULL;      // Yeni düğümün `next` işaretçisini NULL yapıyoruz
}

int main() {
    node *root;                 // Listenin başlangıç düğümü için bir pointer oluşturuyoruz
    int firstNodelValue = 500;
    root = (node *) malloc(sizeof(node)); // İlk düğüm için bellek ayırıyoruz
    root->value = firstNodelValue;              // İlk düğümün değeri olarak [firstNodelValue] atıyoruz
    root->next = NULL;          // Ilk düğümün `next` işaretçisini NULL yapıyoruz

    node *iter;                 // Liste üzerinde gezinmek için bir iter pointer'ı oluşturuyoruz
    iter = root;                // `iter` işaretçisini başlangıç düğümüne ayarlıyoruz

    for (int i = 1; i < 5; i++) {
        ekle(root, i);  // Listeye 1'den 4'e kadar olan sayıları ekliyoruz
    }

    bastir(root); // Tüm listeyi yazdırıyoruz

    free(root);     // Listenin başlangıç düğümünü serbest bırakıyoruz
}