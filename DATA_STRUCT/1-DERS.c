#include <stdint.h>
#include <stdlib.h>  // malloc fonksiyonu için gerekli
#include <stdio.h>   // printf fonksiyonu için gerekli

// Yapı tanımlaması
struct node {
    int data;            // data: Bu bir int tipi, yani bir tamsayı saklayacak.
    struct node *next;   // next: Bu, aynı türde bir struct node işaretçisi. Bu işaretçi, bir sonraki düğümü işaret eder.
};

// Yeni düğüm oluşturma fonksiyonu
struct node *newNode(int x) {
    // Bellek ayırma
    struct node *yeni = (struct node *)malloc(sizeof(struct node));
    // [malloc] fonksiyonu ile bellekte bir yer ayırıyoruz ve bu yeri struct node olarak kullanıyoruz.
    if (yeni == NULL) {
        return NULL;  // Bellek ayıramadıysa NULL döndür
    }

    // Verileri atama
    yeni->data = x;
    yeni->next = NULL;

    return yeni;  // Yeni düğümü döndür
}

// Başa düğüm ekleme fonksiyonu
void basaEkle(struct node **head, int x) {
    struct node *yeni = newNode(x);
    yeni->next = *head;   // Yeni düğümün next işaretçisi, eski başı işaret edecek
    *head = yeni;         // Yeni düğümü baş yap
}

// Listeyi ekrana yazdırma fonksiyonu
void printList(struct node *head) {
    struct node *tmp = head;
    while (tmp != NULL) {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

// Listeyi temizleme (free) fonksiyonu
void freeList(struct node *head) {
    struct node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    // Boş bir liste oluştur
    struct node *head = NULL;

    // Başa yeni düğümler ekle
    basaEkle(&head, 5);  // Listenin başına 5 ekle
    basaEkle(&head, 10); // Listenin başına 10 ekle
    basaEkle(&head, 15); // Listenin başına 15 ekle

    // Listeyi yazdır
    printf("Liste: ");
    printList(head);

    // Listeyi temizle (free)
    freeList(head);

    return 0;
}