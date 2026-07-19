#include<stdio.h>
//manager fisso settimanale
//lavoratore ad ore: le prime 40 ore sono pagate normali, oltre le 40 1,5 volte l'ora
//lavoratore a provvigione: 250$ + 5,7% delle lore venidete settimanale lorde
//lavororatori a cottimo: ricevono una quantità fissa di denaro per ogni prodotto compleato

int main(){
    int idLavoratore = 0;


    while(idLavoratore >= 0){
        printf("\n\nInserisi -1 per uscire dall'inserimento");
        printf("\nInserisci il codice del lavoratore: ");
        scanf("%d", &idLavoratore);

        switch(idLavoratore){
            case 1 :
                float stipendioSettimanle = 0;
                printf("Quanto prende il manager settimanalmente? ");
                scanf("%f",&stipendioSettimanle);
                printf("Stipendio: %f\n", stipendioSettimanle*4);
                break;
            case 2 :
                float pagaOraria,oreFatte,stipendio = 0;
                printf("Inserisci la paga oraria: ");
                scanf("%f", &pagaOraria);
                printf("Quante ore ha fatto: ");
                scanf("%f", &oreFatte);
                if(oreFatte > 40){
                    stipendio = oreFatte * pagaOraria;
                    oreFatte = oreFatte - 40;
                    if(oreFatte > 0){
                        stipendio = stipendio + oreFatte * (pagaOraria*1,5);
                    }
                }else{
                    stipendio = oreFatte * pagaOraria;
                }
                printf("Stipendio: %f\n", stipendio);
                break;
                break;
            case 3:
                float totaleVendite = 0;
                printf("Quanto è il totale delle vendite che ha fatto? ");
                scanf("%f", &totaleVendite);
                printf("Stipendio: %f\n", 250 + totaleVendite * 0.057);
                break;
            case 4:
                float numeroProdotti, denaroAProdotto = 0;
                printf("Quanto prende per ogni prodotto? ");
                scanf("%f", &denaroAProdotto);
                printf("Quanti prodotti ha fatto? ");
                scanf("%f", &numeroProdotti);
                printf("Stipendio: %f\n", denaroAProdotto*numeroProdotti);
                break;
            case -1:
                break;
            default:
                printf("Codice inserito non valido");
                break;
        }
    }


    return 0;
}