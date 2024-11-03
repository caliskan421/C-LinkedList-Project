#include <stdio.h>    // printf fonksiyonunu kullanmak için gerekli
#include <stdlib.h>   // malloc ve free fonksiyonları için gerekli

// Düğüm yapısını tanımlıyoruz; her düğüm bir değer ve bir sonraki düğüme işaretçi içerir
struct n {
    int value;          // Düğümde saklanan değer
    struct n *next;     // Sonraki düğümü işaret eden pointer
};

typedef struct n node;  // Yapıyı 'node' olarak adlandırarak kullanımını kolaylaştırıyoruz

// Listenin tüm elemanlarını ekrana bastıran fonksiyon
void bastir(node *r) {
    while (r != NULL) {                  // Listenin sonuna kadar ilerleyene dek döngü devam eder
        printf("%d\n", r->value);        // Geçerli düğümdeki değeri yazdırıyoruz
        r = r->next;                     // Bir sonraki düğüme geçiyoruz
    }
}

// Listenin sonuna yeni bir düğüm ekleyen fonksiyon
void ekle(node *r, int value) {
    while (r->next != NULL) {            // r'nin next'i NULL olana kadar son düğüme kadar ilerliyoruz
        r = r->next;                     // Bir sonraki düğüme geçiyoruz
    }
    r->next = (node *) malloc(sizeof(node)); // Yeni düğüm için bellek ayırıyoruz
    r->next->value = value;              // Yeni düğüme verilen değeri atıyoruz
    r->next->next = NULL;                // Yeni düğüm listenin sonuna eklendiği için next'i NULL yapıyoruz
}

// Listeye sıralı olarak yeni düğüm ekleyen fonksiyon
node *siraliEkle(node *r, int newValue) {
    if (r == NULL) {                         // Liste boşsa
        r = (node *) malloc(sizeof(node));   // Yeni düğüm için bellek ayır
        r->next = NULL;                      // Tek düğümlük bir liste olduğu için next'i NULL yap
        r->value = newValue;                 // Yeni düğüme değeri ata
        return r;                            // Baş düğümü döndür
    }
    if (r->value > newValue) {               // Yeni değer başa eklenmeli mi kontrol ediyoruz
        node *temp = (node *) malloc(sizeof(node)); // Yeni düğüm için bellek ayırıyoruz
        temp->value = newValue;              // Değeri yeni düğüme atıyoruz
        temp->next = r;                      // Yeni düğüm listenin başına ekleniyor
        return temp;                         // Yeni baş düğümü döndür
    }
    node *iter = r;                          // Yeni düğüm eklenecek yeri bulmak için iter başlangıç düğümüne ayarlanıyor
    while (iter->next != NULL && iter->next->value < newValue) {
        iter = iter->next;                   // Sırayla ilerliyor, uygun konumu bulana kadar
    }
    node *temp = (node *) malloc(sizeof(node));  // Yeni düğüm için bellek ayırıyoruz
    temp->next = iter->next;                 // Yeni düğümün next'i iter'in next'i yapılıyor
    iter->next = temp;                       // Yeni düğüm iter'in next'ine ekleniyor
    temp->value = newValue;                  // Yeni düğüme değer atanıyor
    return r;                                // Baş düğüm değişmediği için aynı baş düğüm döndürülüyor
}

// Belirli bir değere sahip düğümü silen fonksiyon
node *sil(node *r, int selectedValue) {
    node *temp;                              // Geçici bir pointer tanımlıyoruz
    node *iter = r;                          // iter'i listenin başına ayarlıyoruz

    if (r->value == selectedValue) {         // İlk düğüm silinmek isteniyorsa
        temp = r;                            // Silinecek düğümü temp'e atıyoruz
        r = r->next;                         // Yeni baş düğüm olarak bir sonraki düğümü ayarlıyoruz
        free(temp);                          // Belleği serbest bırakıyoruz
        return r;                            // Yeni baş düğümü döndürüyoruz
    }
    while (iter->next != NULL && iter->next->value != selectedValue) {
        iter = iter->next;                   // Silinecek değeri bulana kadar ilerliyoruz
    }
    if (iter->next == NULL) {                // Değer bulunamazsa
        printf("SAYI BULUNAMADI\n");         // Hata mesajı yazdırıyoruz
        return r;                            // Baş düğüm değişmeden döndür
    }
    temp = iter->next;                       // Silinecek düğüm temp'e atanıyor
    iter->next = iter->next->next;           // iter'in next'ini, silinecek düğümden sonrakine bağlıyoruz
    free(temp);                              // Belleği serbest bırakıyoruz
    return r;                                // Güncellenmiş baş düğüm döndürülüyor
}

int main() {
    node *root;                              // Liste için root düğümünü tanımlıyoruz
    root = NULL;                             // Başlangıçta root boş (NULL)

    root = siraliEkle(root, 1);              // 1 elemanını sırayla ekliyoruz
    root = siraliEkle(root, 3);              // 3 elemanını sırayla ekliyoruz
    root = siraliEkle(root, 2);              // 2 elemanını sırayla ekliyoruz
    root = siraliEkle(root, 4);              // 4 elemanını sırayla ekliyoruz

    root = sil(root, 1);         // Baş düğüm olan 1 siliniyor
    bastir(root);                            // Güncel listeyi yazdırıyoruz
}