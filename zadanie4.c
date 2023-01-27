#include <stdio.h>
#include <stdlib.h>
//AZ
struct student{
    char imie[15];
    char nazwisko[25];
    float oceny[5];
};

struct student wprowadzStudenta();
void wyswietlDane(struct student);
float sredniaStudenta(float []);
float sredniaGrupy(struct student[], int);

int main(){
    int ilosc_studentow;
    printf("Ilosc studentow: \n");
    scanf("%d", &ilosc_studentow);
    struct student studenci[ilosc_studentow];
    for(int x=0;x<ilosc_studentow;x++){
        printf("Student %d\n", x+1);
        studenci[x] = wprowadzStudenta();
        printf("%s %s srednia %.2f\n", studenci[x].nazwisko, studenci[x].imie, sredniaStudenta(studenci[x].oceny));
    }

    printf("\nSrednia grupy: %.2f", sredniaGrupy(studenci, ilosc_studentow));


}

float sredniaGrupy(struct student grupa[], int ilosc){
    float sredniaCalosc=0, srednia=0;
    for(int x=0; x<ilosc;x++){
            srednia+=sredniaStudenta(grupa[x].oceny);
    }
    sredniaCalosc = srednia/ilosc;
    return sredniaCalosc;
}

struct student wprowadzStudenta(){
    struct student osoba;
    printf("Imie: \n");
    scanf("%s", &osoba.imie);
    printf("Nazwisko \n");
    scanf("%s", &osoba.nazwisko);
    printf("Oceny: \n");
    for(int x=0;x<sizeof(osoba.oceny)/sizeof(osoba.oceny[0]);x++){
        printf("Ocena %d\n", x+1);
        scanf("%f", &osoba.oceny[x]);
    }
    return osoba;
}

float sredniaStudenta(float oceny[]){
    float srednia=0;
    for(int x=0;x<5;x++){
        srednia+=oceny[x];
    }
    return srednia/5;
}
