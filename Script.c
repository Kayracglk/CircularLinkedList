#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Person
{
    char name[10];
    char surname[10];
    long phoneNumber;
    struct Person *next;
};

struct Person *root = NULL;
struct Person *temp = NULL;

struct Person *createPerson(long phoneNumber, char *name1, char *surname1);
void Add(long phoneNumber, char *name1, char *surname1);
void Delete(long phoneNumber);
void SearchByName(char *name);
void ToList();
void SearchByNumber(long phoneNumber);

int main()
{
    short choosenNumber;
    char name[10], surname[10];
    long phoneNumber;
    while(1==1)
    {
        printf("1-> Ekle\n2-> Sil\n3 -> Listeleme\n4 -> Arama\n5 -> Cikis\n");
        scanf("%d",&choosenNumber);
        switch(choosenNumber)
        {
        case 1:
            printf("Ad(En fazla 10 haneli): ");
            scanf("%s",name);
            printf("SoyAd(En fazla 10 haneli): ");
            scanf("%s",surname);
            printf("Telefon Numarasi(En fazla 10 haneli): ");
            scanf("%ld",&phoneNumber);
            Add(phoneNumber,name, surname);
            break;
        case 2:
            printf("Silinecek telefon numarasini giriniz: ");
            scanf("%ld",&phoneNumber);
            Delete(phoneNumber);
            break;
        case 3:
            ToList();
            break;
        case 4:
            printf("1 -> Telefon numarasina gore arama\n2 -> Isime gore arama\n");
            scanf("%d",&choosenNumber);
            switch(choosenNumber)
            {
            case 1:
                printf("Aranack telefon numarasini giriniz: ");
                scanf("%ld",&phoneNumber);
                SearchByNumber(phoneNumber);
                break;
            case 2:
                printf("Aranacak ismi giriniz: ");
                scanf("%s",name);
                SearchByName(name);
                break;
            default:
                break;
            }
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}

struct Person *createPerson(long phoneNumber, char *name1, char *surname1)
{
    struct Person * person = (struct Person *) malloc (sizeof(struct Person));
    strcpy(person->name,name1);
    strcpy(person->surname,surname1);
    person -> phoneNumber = phoneNumber;
    person -> next = NULL;
    return person;
}

void Add(long phoneNumber, char *name1, char *surname1)
{
    struct Person *person = createPerson(phoneNumber, name1, surname1);
    temp = root;
    if(root == NULL)
    {
        root = (struct Person *) malloc (sizeof(struct Person));
        root = person;
        root ->next = root;
    }
    else
    {
        if(temp->phoneNumber == person->phoneNumber)
            {
                printf("Bu telefon numarasi kayitli.\n");
                return;
            }
        while(temp->next != root)
        {
            if(temp->phoneNumber == person->phoneNumber)
            {
                printf("Bu telefon numarasi kayitli.\n");
                return;
            }
            temp = temp->next;
        }
        temp ->next = person;
        person-> next = root;
        root = person;
    }
}

void Delete(long phoneNumber)
{
    struct Person *prevPerson;
    prevPerson = (struct Person*) malloc (sizeof(struct Person));
    prevPerson = root;
    temp = root;
    if(temp->phoneNumber == phoneNumber && temp ->next == root)
    {
        root = NULL;
        free(temp);
        printf("Kayit Silindi\n");
        return;
    }
    if(temp->phoneNumber == phoneNumber)
    {
        while(temp->next != root)
        {
            temp = temp->next;
        }
        temp->next = root ->next;
        root = temp->next;
        free(prevPerson);
        printf("Kayit Silindi\n");
        return;
    }

    while(temp->next != root)
    {
        if(temp->phoneNumber == phoneNumber)
        {
            prevPerson->next = temp ->next;
            free(temp);
            printf("Kayit Silindi\n");
            return;
        }
        prevPerson = temp;
        temp = temp->next;
    }
    printf("Kayit Bulunamadi\n");


}

void SearchByName(char *name)
{
    bool isFind = false;
    temp = root;
    if(strcmp(name,temp->name) == 0 && temp ->next == root)
    {
        printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
        return;
    }
    if(strcmp(name,temp->name) == 0)
    {
        printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
        isFind = true;
    }
    while(temp->next != root)
    {
        temp = temp->next;
        if(strcmp(name,temp->name) == 0)
        {
            printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
            isFind = true;
        }
    }
    if(!isFind)
    {
        printf("Kayit Bulunamadi");
    }
}

void ToList()
{
    if(root == NULL)
    {
        printf("Liste Bostur.\n");
        return;
    }
    temp = (struct Person*)malloc(sizeof(struct Person));
    temp = root;
    if(temp->next == root)
    {
        printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
        return;
    }
    while(temp->next!= root)
    {
        printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
        temp = temp->next;
    }
    printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
}

void SearchByNumber(long phoneNumber)
{
    temp = root;
    if(temp->phoneNumber == phoneNumber && temp ->next == root)
    {
        printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
        return;
    }
    if(temp->phoneNumber == phoneNumber)
    {
        printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
        return;
    }
    while(temp->next != root)
    {
        temp = temp->next;
        if(temp->phoneNumber == phoneNumber)
        {
            printf("Ad: %s , Soyad:  %s, TelNo: %ld\n",temp->name,temp->surname,temp->phoneNumber);
            return;
        }
    }
    printf("Kayit Bulunamadi");
}




