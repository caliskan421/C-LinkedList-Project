# C-LinkedList-Project

Bu proje, C dilinde yazılmış bir bağlantılı liste (linked list) yapısını içerir. İçerisinde temel bağlantılı liste işlemleri ve bellek yönetimi örnekleri bulunmaktadır.

## Özellikler
- **Sıralı Ekleme**: Elemanları artan sırada listeye ekler.
- **Eleman Silme**: Listeden belirli bir değere sahip düğümü güvenli bir şekilde siler.
- **Listeyi Yazdırma**: Listedeki tüm elemanları yazdırır.

## Bellekten Silme İşlemi

Silme işlemi sırasında aşağıdaki doğru yöntemi kullanmak önemlidir:

```c
node *temp = iter->next;
iter->next = iter->next->next;
free(temp);