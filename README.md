- Bellekten SILME Islemi -

--Silme islemi sırasında eğer su yoluizlersek:

Iter->next = iter->next->next;
free(iter->next):

artık iter'in next'i iter'in 2 next sonrasını gostereceginden silmek istediğimiz elemandan sonra gelen elemanı silmiş olacağız...

--Eger su sekil olursa da:

free(iter->next):
Iter->next = iter->next->next;

bu sefer de silme islemi oncesinden dolayı aradaki bağı kopardigimizdan sonraki tum elemanlari yaybetmis olacagiz...

-- Olmasi gerek ise:

node *temp = iter->next;
iter->next = iter->next->next;
free(temp);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////