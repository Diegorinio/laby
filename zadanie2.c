#include <stdio.h>
#include <stdlib.h>
//AZ
struct pracownik{
    char imie[15];
    char nazwisko[25];
    float liczba_godzin;
    float stawka;
    float procent_premii;
};

struct pracownik wprowadzPracownika();
void wprowadzDaneViaPointer(struct 
pracownik *);
void wyswietlDane(struct pracownik);
void wyswietlDaneViaPointer(struct pracownik *);
float obliczPlace(struct pracownik);
float obliczPlaceViaPointer( struct pracownik *);

int main(){
    struct pracownik pr1, *pr2;
    pr1=wprowadzPracownika();
    wyswietlDane(pr1);
    printf("\n--Pointer--\n");
    wprowadzDaneViaPointer(&pr2);
    wyswietlDaneViaPointer(&pr2);
}

struct pracownik wprowadzPracownika(){
    struct pracownik osoba;
    printf("Imie: \n");
    scanf("%s", &osoba.imie);
    printf("Nazwisko \n");
    scanf("%s", &osoba.nazwisko);
    printf("Liczba godzin\n");
    scanf("%f", &osoba.liczba_godzin);
    printf("Stawka: \n");
    scanf("%f", &osoba.stawka);
    printf("premia: \n");
    scanf("%f", &osoba.procent_premii);
    return osoba;
}

void wprowadzDaneViaPointer(struct pracownik *osoba){
    printf("Imie: \n");
    scanf("%s", &osoba->imie);
    printf("Nazwisko \n");
    scanf("%s", &osoba->nazwisko);
    printf("Liczba godzin\n");
    scanf("%f", &osoba->liczba_godzin);
    printf("Stawka: \n");
    scanf("%f", &osoba->stawka);
    printf("premia: \n");
    scanf("%f", &osoba->procent_premii);
}

void wyswietlDane(struct  pracownik p)
{
    printf("Imie: %s, Nazwisko: %s, liczba godzin: %.2f, stawka: %.2f, premia: %.2f%%, wynagrodzenie: %.2f PLN\n", p.imie, p.nazwisko, p.liczba_godzin, p.stawka, p.procent_premii, obliczPlace(p));
}

void wyswietlDaneViaPointer(struct pracownik *p){
        printf("Imie: %s, Nazwisko: %s, liczba godzin: %.2f, stawka: %.2f, premia: %.2f%%, wynagrodzenie: %.2f PLN\n", p->imie, p->nazwisko, p->liczba_godzin, p->stawka, p->procent_premii, obliczPlaceViaPointer(p));
}

float obliczPlace( struct  pracownik p)
{
    float premia = (p.procent_premii/100)*p.liczba_godzin*p.stawka;
    return p.liczba_godzin*p.stawka+premia;
}

float obliczPlaceViaPointer( struct pracownik *p){
    float premia = (p->procent_premii/100)*p->liczba_godzin*p->stawka;
    return p->liczba_godzin*p->stawka+premia;
}