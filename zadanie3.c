#include <stdio.h>
#include <stdlib.h>

struct pracownik{
    char imie[15];
    char nazwisko[25];
    float liczba_godzin;
    float stawka;
    float procent_premii;
};

struct pracownik wprowadzPracownika();
void wyswietlDane(struct pracownik);
float obliczPlace(struct pracownik);
void listaPlac(struct pracownik [], int);
void Najwiecej(struct pracownik [], int);
int main(){
    int pracownicy_ilosc;
    printf("Ilosc pracownikow: \n");
    scanf("%d", &pracownicy_ilosc);
    struct pracownik pracownicy[pracownicy_ilosc];
    for(int x=0;x<pracownicy_ilosc;x++){
        pracownicy[x] = wprowadzPracownika();
    }
    listaPlac(pracownicy, pracownicy_ilosc);

}

void listaPlac(struct pracownik p[], int ilosc){
    float suma;
    printf("\n LISTA PLAC \n");
    printf("%d", sizeof(*p)/sizeof(p[0]));
    for(int x=0;x<ilosc;x++){
        float wyplata = obliczPlace(p[x]);
        printf("%s|%s|%.2f PLN \n", p[x].imie, p[x].nazwisko, wyplata);
        suma += wyplata;
    }
    printf("SUMA: %.2f PLN", suma);
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

void wyswietlDane(struct  pracownik p)
{
    printf("Imie: %s, Nazwisko: %s, liczba godzin: %.2f, stawka: %.2f, premia: %.2f%%, wynagrodzenie: %.2f PLN\n", p.imie, p.nazwisko, p.liczba_godzin, p.stawka, p.procent_premii, obliczPlace(p));
}

float obliczPlace( struct  pracownik p)
{
    float premia = (p.procent_premii/100)*p.liczba_godzin*p.stawka;
    return p.liczba_godzin*p.stawka+premia;
}