#include <stdio.h>    // printf fonksiyonunu kullanmak için gerekli
#include <stdlib.h>  // malloc ve free fonksiyonları için gerekli

// Düğüm yapısını tanımlıyoruz; her düğüm bir değer ve bir sonraki düğüme işaretçi içerir
struct n {
    int value;           // Düğümde saklanan değer
    struct n *next;     // Sonraki düğümü işaret eden pointer
};

typedef struct n node;  // Yapıyı 'node' olarak adlandırarak kullanımını kolaylaştırıyoruz

// Listenin tüm elemanlarını ekrana bastıran fonksiyon
void bastir(node *r) {
    node *iter = r;                      // iter değişkenini listenin başına ayarlıyoruz
    printf("%d\n", iter->value);        // İlk düğümün değerini yazdırıyoruz
    iter = iter->next;                 // Bir sonraki düğüme geçiyoruz
    while (iter != r) {               // iter tekrar baş düğümü gösterene kadar döngüye devam ediyoruz
        printf("%d\n", iter->value); // Geçerli düğümün değerini yazdırıyoruz
        iter = iter->next;          // Sonraki düğüme geçiyoruz
    }
}

// Listenin sonuna yeni bir düğüm ekleyen fonksiyon
void ekle(node *r, int newValue) {
    node *iter = r;                 // Listenin baş düğümünü iter'e atıyoruz
    while (iter->next != r) {      // iter'i listenin sonuna kadar ilerletiyoruz
        iter = iter->next;        // Sonraki düğüme geçiyoruz
    }
    iter->next = (node *) malloc(sizeof(node)); // Yeni düğüm için bellek ayırıyoruz
    iter->next->value = newValue;                   // Yeni düğüme verilen değeri atıyoruz
    iter->next->next = r;                          // Yeni düğümün son düğüm olduğunu belirliyoruz
}

// Listeye sıralı olarak yeni düğüm ekleyen fonksiyon
node *siraliEkle(node *r, int newValue) {
    if (r == NULL) {                              // Liste boşsa
        r = (node *) malloc(sizeof(node));  // Yeni düğüm için bellek ayır
        r->next = r;                            // Dairesel bir yapı kurarak kendisine işaret etmesini sağla
        r->value = newValue;                   // Değeri ata
        return r;                             // Yeni baş düğümü döndür
    }
    if (r->value > newValue) {                            // Yeni değer listenin başında olmalıysa
        node *temp = (node *) malloc(sizeof(node)); // Yeni düğüm için bellek ayır
        temp->value = newValue;                         // Yeni değeri ata
        temp->next = r;                                // Yeni düğüm başa ekleniyor
        node *iter = r;                               // Son düğüme ulaşmak için iter oluşturuluyor
        while (iter->next != r) {                    // Son düğümü bulmak için iter'i ilerletiyoruz
            iter = iter->next;                      // Son düğüme kadar ilerle
        }
        iter->next = temp;                         // Son düğümün next'ini yeni baş düğüme bağla
        return temp;                              // Yeni baş düğüm olarak temp döndürülüyor
    }
    node *iter = r;                               // Araya eklemek için iter başlangıca ayarlanıyor
    while (iter->next != r && iter->next->value < newValue) {
        iter = iter->next;                        // Sırayla ilerliyor, doğru yeri bulana kadar
    }
    node *temp = (node *) malloc(sizeof(node));   // Yeni düğüm için bellek ayırıyoruz
    temp->next = iter->next;                          // Yeni düğümün next'i, iter'in next'i yapılıyor
    iter->next = temp;                               // Yeni düğüm iter'in next'ine ekleniyor
    temp->value = newValue;                         // Değer atanıyor
    return r;                                      // Baş düğüm değişmeden geri döndürülüyor
}

// Belirli bir değere sahip düğümü silen fonksiyon
node *sil(node *r, int selectedValue) {
    node *temp;                                    // Geçici bir pointer tanımlıyoruz
    node *iter = r;                               // iter'i listenin başına ayarlıyoruz

    if (iter->value == selectedValue) {            // İlk düğüm silinmek istenirse
        while (iter->next != r) {                 // Son düğüme kadar ilerliyoruz
            iter = iter->next;                   // Son düğüme kadar ilerle
        }
        iter->next = r->next;                      // Son düğümün next'ini güncelleyerek baş düğümü geçiyoruz
        temp = r;                                 // Silinecek düğümü temp'e atıyoruz
        r = r->next;                             // Yeni baş düğüm olarak bir sonraki düğümü ayarlıyoruz
        free(temp);                             // Belleği serbest bırakıyoruz
        return r;                              // Yeni baş düğümü döndürüyoruz
    }

    while (iter->next != r && iter->next->value != selectedValue) {
        iter = iter->next;                         // Silinecek değeri bulana kadar ilerliyoruz
    }

    if (iter->next == r) {                         // Değer bulunamazsa
        printf("SAYI BULUNAMADI\n");              // Hata mesajı yazdırıyoruz
        return r;                                // Baş düğüm değişmeden döndür
    }

    temp = iter->next;                             // Silinecek düğüm temp'e atanıyor
    iter->next = iter->next->next;                // iter'in next'ini, silinecek düğümden sonrakine bağlıyoruz
    free(temp);                                  // Belleği serbest bırakıyoruz
    return r;                                   // Güncellenmiş baş düğüm döndürülüyor
}

int main() {
    node *root;
    root = NULL;

    root = siraliEkle(root, 1);                    // Baş düğüm olarak 1 ekleniyor
    root = siraliEkle(root, 3);                   // 3 sıralı şekilde ekleniyor
    root = siraliEkle(root, 2);                  // 2 sıralı şekilde ekleniyor
    root = siraliEkle(root, 4);                 // 4 sıralı şekilde ekleniyor

    bastir(root);
    printf("/////////////////////\n");
    root = sil(root, 1);        // Baş düğüm olan 1 siliniyor
    bastir(root);
    printf("/////////////////////\n");
    root = sil(root, 6);        // Listede olmayan 6'yı silmeye çalışıyoruz
    bastir(root);
}