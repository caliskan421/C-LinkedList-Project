# C-LinkedList-Project

Bu proje, C dilinde yazılmış bir bağlantılı liste (linked list) yapısını içerir. İçerisinde temel bağlantılı liste işlemleri ve bellek yönetimi örnekleri bulunmaktadır.


## Bellekten Silme İşlemi

Bağlantılı listeden bir eleman silerken, önce bağlantıyı güncelleyip sonra belleği serbest bırakmak önemlidir. Yanlış bir sıralama, listede veri kaybına veya bellek hatalarına yol açabilir. İşte doğru ve yanlış sıralamalar:
- **Yanlış Sıra 1: Bağlantıyı güncellemeden ÖNCE silme**:
```c
iter->next = iter->next->next; // Bağlantıyı günceller
free(iter->next);               // Belleği serbest bırakır (yanlış)
```
- **Yanlış Sıra 2: Silme işleminden SONRA bağlantıyı güncelleme**:
```c
free(iter->next);               // Önce belleği serbest bırakır (yanlış)
iter->next = iter->next->next;  // Ardından bağlantıyı günceller
```
- **Doğru Sıralama:**:
```c
node *temp = iter->next;       // Silinecek düğümü geçici olarak sakla
iter->next = iter->next->next; // Bağlantıyı güncelle
free(temp);                    // Belleği güvenle serbest bırak
```

## Çift Bağlı Listede Önemli Bir Nokta:

```c
if (temp->next != NULL) {
        temp->next->prew = temp;
    }
```

- Yukarıdaki sıralı eleman ekleme veya silme fonksiyonunda yer alan bu (SON ELEMAN MI) satırı önemlidir.
- Çünkü Eğer << temp -> next NULL >> ise, << temp -> next -> prew >> işaretçisine erişmeye çalışmak bir erişim hatasına yol açar. Bu hatanın sebebi, temp->next NULL olduğunda temp->next herhangi bir bellek adresini göstermiyor demektir, dolayısıyla temp->next->prew gibi bir alan da bulunmaz. 