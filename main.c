#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void title()
{
    printf(" _______________________________________________________________________________________________________________________________\n");
    printf("|      _____                 _____                    _______    __________  ___________      _                    _______      |\n");
    printf("|     |     \\       |      /          |          |   |                |           |          / \\          |       /       \\     |\n");
    printf("|     |      \\      |     |           |          |   |                |           |         /   \\         |       |       |     |\n");
    printf("|     |______/      |     |     ____  |          |   |_____           |           |        /_____\\        |       |       |     |\n");
    printf("|     |      \\      |     |      |    |          |   |                |           |       /       \\       |       |       |     |\n");
    printf("|     |       \\     |     |      |    |          |   |                |           |      /         \\      |       |       |     |\n");
    printf("|     |_______/     |      \\____/     |______    |   |_______         |           |     /           \\     |       \\_______/     |\n");
    printf("|_______________________________________________________________________________________________________________________________|\n");
}
// struttura data
struct Date
{
    int day;
    int month;
    int year;
};
// selezione del tipo do utenza
void selezione_utente(int *tipo_utente)
{
    printf(" ________________________________________________________\n");
    printf("|                                                        |\n");
    printf("|      selezionare il tipo di utenza del programma       |\n");
    printf("|________________________________________________________|\n");
    printf("|                                                        |\n");
    printf("|    ________________              __________________    |\n");
    printf("|   |       1)       |            |        2)        |   |\n");
    printf("|   | amministratore |            |      utente      |   |\n");
    printf("|   |________________|            |__________________|   |\n");
    printf("|                                                        |\n");
    printf("|________________________________________________________|\n");

    scanf("%d", tipo_utente);

    // se l'utente inserito è sbagliato
    while (!(*tipo_utente == 1 || *tipo_utente == 2))
    {
        printf(" ________________________________________________________\n");
        printf("|                                                        |\n");
        printf("|          utente non disponibile, riprovare             |\n");
        printf("|________________________________________________________|\n");
        printf("|                                                        |\n");
        printf("|    ________________              __________________    |\n");
        printf("|   |       1)       |            |        2)        |   |\n");
        printf("|   | amministratore |            |      utente      |   |\n");
        printf("|   |________________|            |__________________|   |\n");
        printf("|                                                        |\n");
        printf("|________________________________________________________|\n");

        scanf("%d", tipo_utente);
    }
}

// selezione tipo di biglietto

void ticket_type(int *ticket, float price1, float price2, float price3)
{
    printf(" ____________________________________________________________________________________\n");
    printf("|                                                                                    |\n");
    printf("|                        selezionare  il tipo di biglietto                           |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("|                                                                                    |\n");
    printf("|    ________________              ________________              ________________    |\n");
    printf("|   |                |            |                |            |                |   |\n");
    printf("|   |  1) under 12   |            |   2) over 65   |            |   3) normale   |   |\n");
    printf("|   |________________|            |________________|            |________________|   |\n");
    printf("|                                                                                    |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("1) euro %f\n", price1);
    printf("2) euro %f\n", price2);
    printf("3) euro %f\n", price3);

    scanf("%d", ticket);

    // se il biglietto selezionato non esiste lo richiede fino a quando non è uno dei tre selezionabili
    while (!(*ticket == 1 || *ticket == 2 || *ticket == 3))
    {
        printf(" ____________________________________________________________________________________\n");
        printf("|                                                                                    |\n");
        printf("|                   tipo di biglietto non disponibile, riprovare                     |\n");
        printf("|____________________________________________________________________________________|\n");
        printf("|                                                                                    |\n");
        printf("|    ________________              ________________              ________________    |\n");
        printf("|   |                |            |                |            |                |   |\n");
        printf("|   |  1) under 12   |            |   2) over 65   |            |   3) normale   |   |\n");
        printf("|   |________________|            |________________|            |________________|   |\n");
        printf("|                                                                                    |\n");
        printf("|____________________________________________________________________________________|\n");
        printf("1) euro %f\n", price1);
        printf("2) euro %f\n", price2);
        printf("3) euro %f\n", price3);

        scanf("%d", ticket);
    }
}
// funzione per il pagamento
void payment(int *typePayment, float *money, float price1, float price2, float price3, int ticket_number, int ticket, int pinCard, float *amount, float provvigione1, float provvigione2, float provvigione3, float *rexultProvvigione, int *countTicket)
{
    int nextPayment = 0;
    while (nextPayment == 0)
    {
        float carry = 0;
        float moneyPlus = 0;
        int pinCardInsert = 0;
        int try = 3;

        printf(" ___________________________________________________________________\n");
        printf("|                                                                   |\n");
        printf("|                  inserire il tipo di pagamento                    |\n");
        printf("|                                                                   |\n");
        printf("|      1) pagamento con contanti                                    |\n");
        printf("|      2) pagamento con carta                                       |\n");
        printf("|___________________________________________________________________|\n");
        scanf("%d", typePayment);

        switch (ticket)
        {
        case 1:
        {
            *amount = price1 * ticket_number;
            break;
        }
        case 2:
        {
            *amount = price2 * ticket_number;
            break;
        }
        case 3:
        {
            *amount = price3 * ticket_number;
            break;
        }
        }
        printf("l'importo e' di euro %f\n", *amount);

        while (!(*typePayment == 1 || *typePayment == 2))
        {
            printf(" ___________________________________________________________________\n");
            printf("|                                                                   |\n");
            printf("|          tipo di pagamento non riconosciuto, riprovare            |\n");
            printf("|                                                                   |\n");
            printf("|      1) pagamento con contanti                                    |\n");
            printf("|      2) pagamento con carta                                       |\n");
            printf("|___________________________________________________________________|\n");
            scanf("%d", typePayment);
        }

        if (*typePayment == 1)
        {
            printf(" ___________________________________________________________________\n");
            printf("|                                                                   |\n");
            printf("|                         inserire il denaro                        |\n");
            printf("|___________________________________________________________________|\n");
            scanf("%f", money);

            while(*money < 0)
            {
                printf(" ___________________________________________________________________\n");
                printf("|                                                                   |\n");
                printf("|      impossibile inserire una quantita' di denaro negativo        |\n");
                printf("|___________________________________________________________________|\n");
                scanf("%f", money);
            }

            switch (ticket) // switch case capire su quale ticket si deve calcolare il prezzo
            {
            case 1:
            {
                while (*money < (price1 * ticket_number))
                {
                    carry = (price1 * ticket_number) - *money;
                    printf(" ___________________________________________________________________\n");
                    printf("|                                                                   |\n");
                    printf("|         denaro insufficiente, il quantitativo mancante            |\n");
                    printf("|___________________________________________________________________|\n");
                    printf("denaro mancante: euro %f\n", carry);
                    scanf("%f", &moneyPlus);
                    *money = *money + moneyPlus;
                }
                carry = *money - (price1 * ticket_number);
                printf("il resto e' di euro %f\n", carry);
                break;
            }
            case 2:
            {
                while (*money < (price2 * ticket_number))
                {
                    carry = (price2 * ticket_number) - *money;
                    printf(" ___________________________________________________________________\n");
                    printf("|                                                                   |\n");
                    printf("|         denaro insufficiente, il quantitativo mancante            |\n");
                    printf("|___________________________________________________________________|\n");
                    printf("denaro mancante: euro %f\n", carry);
                    scanf("%f", &moneyPlus);
                    *money = *money + moneyPlus;
                }
                carry = *money - (price2 * ticket_number);
                printf("il resto e' di euro %f\n", carry);
                break;
            }
            case 3:
            {
                while (*money < (price3 * ticket_number))
                {
                    carry = (price3 * ticket_number) - *money;
                    printf(" ___________________________________________________________________\n");
                    printf("|                                                                   |\n");
                    printf("|         denaro insufficiente, il quantitativo mancante            |\n");
                    printf("|___________________________________________________________________|\n");
                    printf("denaro mancante: euro %f\n", carry);
                    scanf("%f", &moneyPlus);
                    *money = *money + moneyPlus;
                }
                carry = *money - (price3 * ticket_number);
                printf("il resto e' di euro %f\n", carry);
                break;
            }
            }
            nextPayment = 1;
        }
        else
        {
            printf(" _____________________________________\n");
            printf("|                                     |\n");
            printf("|         inserire la carta           |\n");
            printf("|_____________________________________|\n");
            printf("|                                     |\n");
            printf("|         attendere, prego            |\n");
            printf("|_____________________________________|\n");
            sleep(2);
            printf(" _____________________________________\n");
            printf("|                                     |\n");
            printf("|   carta inserita, digitare il pin   |\n");
            printf("|   hai 3 tentativi                   |\n");
            printf("|_____________________________________|\n");
            scanf("%d", &pinCardInsert);
            while (pinCardInsert != pinCard && try > 1)
            {
                try--;
                printf(" _____________________________________\n");
                printf("|                                     |\n");
                printf("|      pin non valido, riprovare      |\n");
                printf("|                                     |\n");
                printf("|      tentativi rimasti %d            |\n", try);
                printf("|_____________________________________|\n");
                scanf("%d", &pinCardInsert);
            }

            if (try <= 1)
            {
                printf(" _____________________________________\n");
                printf("|                                     |\n");
                printf("|           carta bloccata            |\n");
                printf("|_____________________________________|\n");
                break;
            }

            printf(" ___________________________________________\n");
            printf("|                                           |\n");
            printf("| se vuoi confermare la transazione premi 1 |\n");
            printf("|                                           |\n");
            printf("| se vuoi cambiare metodo premi 0           |\n");
            printf("|___________________________________________|\n");
            scanf("%d", &nextPayment);
            while (!(nextPayment == 0 || nextPayment == 1))
            {
                printf(" __________________________________________\n");
                printf("|                                          |\n");
                printf("|    numero errato, riprovare:             |\n");
                printf("|                                          |\n");
                printf("|    se vuoi proseguire premi 1            |\n");
                printf("|                                          |\n");
                printf("|    se vuoi ritornare all'inizio premi 0  |\n");
                printf("|__________________________________________|\n");
                scanf("%d", &nextPayment);
            }
            if (nextPayment == 0)
            {
                continue;
            }
        }
    }
    // premio di 50€ ogni volta che vengono venduti 100 biglietti
    while (*countTicket - 100 >= 0)
    {
        *rexultProvvigione += 50;
        *countTicket -= 100;
    }

    switch (ticket)
    {
    case 1:
    {
        *rexultProvvigione += (price1 * ticket_number) * provvigione1;
        break;
    }
    case 2:
    {
        *rexultProvvigione += (price2 * ticket_number) * provvigione2;
        break;
    }
    case 3:
    {
        *rexultProvvigione += (price3 * ticket_number) * provvigione3;
        break;
    }
    }
}

// selezione della quantità del biglietto
void ticket_amount(int *ticket_number, int *max_ticket1, int *max_ticket2, int *max_ticket3, int *ticket, int *countTicket)
{
chiediBiglietti: // etichetta per tornare indietro alla selezione della quatità del biglietto
    printf(" ____________________________________________________________________________________\n");
    printf("|                                                                                    |\n");
    printf("|                  inserire la quantita' del biglietto selezionato                   |\n");
    printf("|____________________________________________________________________________________|\n");

    scanf("%d", ticket_number);

    while (*ticket_number <= 0)
    {
        printf(" ____________________________________________________________________________________\n");
        printf("|                                                                                    |\n");
        printf("|               quantitativo di biglietti negativo, riselezionare:                   |\n");
        printf("|____________________________________________________________________________________|\n");
        scanf("%d", ticket_number);
    }

    switch (*ticket)
    {
    case 1:
    {
        if (*ticket_number <= *max_ticket1)
        {
        }
        else
        {
            printf(" ____________________________________________________________________________________\n");
            printf("|                                                                                    |\n");
            printf("|               quantitativo biglietti insufficiente, rilesezionare:                 |\n");
            printf("|____________________________________________________________________________________|\n");
            goto chiediBiglietti;
        }
        break;
    }
    case 2:
    {
        if (*ticket_number <= *max_ticket2)
        {
        }
        else
        {
            printf(" ____________________________________________________________________________________\n");
            printf("|                                                                                    |\n");
            printf("|               quantitativo biglietti insufficiente, rilesezionare:                 |\n");
            printf("|____________________________________________________________________________________|\n");
            goto chiediBiglietti;
        }
        break;
    }
    case 3:
    {
        if (*ticket_number <= *max_ticket3)
        {
        }
        else
        {
            printf(" ____________________________________________________________________________________\n");
            printf("|                                                                                    |\n");
            printf("|               quantitativo biglietti insufficiente, rilesezionare:                 |\n");
            printf("|____________________________________________________________________________________|\n");
            goto chiediBiglietti;
        }
        break;
    }
    }
    *countTicket += *ticket_number;
}

// autenticazione dell'admin
void adminAutentication(char adminPasswordString[])
{
    char autenticationString[] = "aaaaa0000";
    printf(" ____________________________________________________________________\n");
    printf("|                                                                    |\n");
    printf("|                  inserire la pasword dell'admin                    |\n");
    printf("|____________________________________________________________________|\n");
    scanf("%s", autenticationString);
    while (strcmp(autenticationString, adminPasswordString) != 0)
    {
        printf(" ____________________________________________________________________\n");
        printf("|                                                                    |\n");
        printf("|                  password errata, riprovare                        |\n");
        printf("|____________________________________________________________________|\n");
        scanf("%s", autenticationString);
    }
}

// Funzione per confrontare due date
int compare_dates(struct Date d1, struct Date d2)
{
    if (d1.year < d2.year)
    {
        return -1; // d1 è precedente a d2
    }
    else if (d1.year > d2.year)
    {
        return 1; // d1 è successiva a d2
    }
    else
    {
        if (d1.month < d2.month)
        {
            return -1; // d1 è precedente a d2
        }
        else if (d1.month > d2.month)
        {
            return 1; // d1 è successiva a d2
        }
        else
        {
            if (d1.day < d2.day)
            {
                return -1; // d1 è precedente a d2
            }
            else if (d1.day > d2.day)
            {
                return 1; // d1 è successiva a d2
            }
            else
            {
                return 0; // le date sono uguali
            }
        }
    }
}

void adminEvents(char event1[], char event2[], char event3[], float *price1, float *price2, float *price3, int *maxTicket1, int *maxTicket2, int *maxTicket3, struct Date *data1, struct Date *data2)
{
    int input = 2;
    printf("evento 1: %s\n", event1);
    printf("evento 2: %s\n", event2);
    printf("evento 3: %s\n", event3);

    printf(" _________________________________________________\n");
    printf("|                                                 |\n");
    printf("|         inserire il nome dell' evento1          |\n");
    printf("|                                                 |\n");
    printf("|         separare le parole con il ""_""             |\n");
    printf("|_________________________________________________|\n");
    scanf("%s", event1);
    printf(" ____________________________________________________________________________________\n");
    printf("|                                                                                    |\n");
    printf("|               inserire i prezzi delle tre tipologie di biglietto                   |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("|                                                                                    |\n");
    printf("|    ________________              ________________              ________________    |\n");
    printf("|   |                |            |                |            |                |   |\n");
    printf("|   |  1) under 12   |            |   2) over 65   |            |   3) normale   |   |\n");
    printf("|   |________________|            |________________|            |________________|   |\n");
    printf("|                                                                                    |\n");
    printf("|____________________________________________________________________________________|\n");
    printf(" _______________\n");
    printf("|               |\n");
    printf("|  biglietto 1  |\n");
    printf("|_______________|\n");
    scanf("%f", price1);
    while (*price1 < 0)
    {
        printf(" ______________________________________\n");
        printf("|                                      |\n");
        printf("|  il prezzo non puo' essere negativo  |\n");
        printf("|______________________________________|\n");
        scanf("%f", price1);
    }
    printf(" _______________\n");
    printf("|               |\n");
    printf("|  biglietto 2  |\n");
    printf("|_______________|\n");
    scanf("%f", price2);
    while (*price2 < 0)
    {
        printf(" ______________________________________\n");
        printf("|                                      |\n");
        printf("|  il prezzo non puo' essere negativo  |\n");
        printf("|______________________________________|\n");
        scanf("%f", price2);
    }
    printf(" _______________\n");
    printf("|               |\n");
    printf("|  biglietto 3  |\n");
    printf("|_______________|\n");
    scanf("%f", price3);
    while (*price3 < 0)
    {
        printf(" ______________________________________\n");
        printf("|                                      |\n");
        printf("|  il prezzo non puo' essere negativo  |\n");
        printf("|______________________________________|\n");
        scanf("%f", price3);
    }
    printf(" ____________________________________________________________________________________\n");
    printf("|                                                                                    |\n");
    printf("|         inserire il quantitativo disponibile per ciascun tipo di biglietto         |\n");
    printf("|____________________________________________________________________________________|\n");
    printf("|                                                                                    |\n");
    printf("|    ________________              ________________              ________________    |\n");
    printf("|   |                |            |                |            |                |   |\n");
    printf("|   |  1) under 12   |            |   2) over 65   |            |   3) normale   |   |\n");
    printf("|   |________________|            |________________|            |________________|   |\n");
    printf("|                                                                                    |\n");
    printf("|____________________________________________________________________________________|\n");
    printf(" _______________\n");
    printf("|               |\n");
    printf("|  biglietto 1  |\n");
    printf("|_______________|\n");
    scanf("%d", maxTicket1);
    while(*maxTicket1 <=0)
    {
        printf(" ___________________________________________________\n");
        printf("|                                                   |\n");
        printf("|  il numero di biglietti non puo' essere negativo  |\n");
        printf("|___________________________________________________|\n");
        scanf("%d", maxTicket1);
    }
    printf(" _______________\n");
    printf("|               |\n");
    printf("|  biglietto 2  |\n");
    printf("|_______________|\n");
    scanf("%d", maxTicket2);
    while(*maxTicket2 <=0)
    {
        printf(" ___________________________________________________\n");
        printf("|                                                   |\n");
        printf("|  il numero di biglietti non puo' essere negativo  |\n");
        printf("|___________________________________________________|\n");
        scanf("%d", maxTicket2);
    }
    printf(" _______________\n");
    printf("|               |\n");
    printf("|  biglietto 3  |\n");
    printf("|_______________|\n");
    scanf("%d", maxTicket3);
    while(*maxTicket3 <=0)
    {
        printf(" ___________________________________________________\n");
        printf("|                                                   |\n");
        printf("|  il numero di biglietti non puo' essere negativo  |\n");
        printf("|___________________________________________________|\n");
        scanf("%d", maxTicket3);
    }
// lettura della data di inizio e fine della prevendita
inizioPrevendita:
    printf(" ____________________________________________________________________________________\n");
    printf("|                                                                                    |\n");
    printf("|        Inserisci la data di inizio della prevendita (giorno mese anno):            |\n");
    printf("|____________________________________________________________________________________|\n");
    scanf("%d %d %d", &data1->day, &data1->month, &data1->year);

    while (data1->day < 1 || data1->day > 31)
    {
        printf(" _____________________________________________\n");
        printf("|                                             |\n");
        printf("|    giorno non disponibile, reinserirlo:     |\n");
        printf("|_____________________________________________|\n");
        scanf("%d", &data1->day);
    }

    // nel caso il mese non esista
    while (data1->month < 1 || data1->month > 12)
    {
        printf(" _____________________________________________\n");
        printf("|                                             |\n");
        printf("|     mese non disponibile, reinserirlo:      |\n");
        printf("|_____________________________________________|\n");
        scanf("%d", &data1->month);
    }

    int i = 0;
    int anno_bisestile = 0;
    for (i = 1904; i < 2000; i = i + 4)
    {
        if (data1->year == i)
        {
            anno_bisestile++;
        }
    }
    for (i = 2004; i < 2100; i = i + 4)
    {
        if (data1->year == i)
        {
            anno_bisestile++;
        }
    }

    switch (data1->month)
    {
    case 2:
    {
        if (anno_bisestile == 0 && data1->day > 28)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto inizioPrevendita;
        }
        else if (anno_bisestile == 1 && data1->day > 29)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto inizioPrevendita;
        }
        break;
    }
    case 4:
    {
        if (data1->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto inizioPrevendita;
        }
        break;
    }
    case 6:
    {
        if (data1->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto inizioPrevendita;
        }
        break;
    }
    case 9:
    {
        if (data1->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto inizioPrevendita;
        }
        break;
    }
    case 11:
    {
        if (data1->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto inizioPrevendita;
        }
        break;
    }
    }
finePrevendita:
    printf(" ____________________________________________________________________________________\n");
    printf("|                                                                                    |\n");
    printf("|         Inserisci la data di fine della prevendita (giorno mese anno):             |\n");
    printf("|____________________________________________________________________________________|\n");
    scanf("%d %d %d", &data2->day, &data2->month, &data2->year);

    while (data2->day < 1 || data2->day > 31)
    {
        printf(" _____________________________________________\n");
        printf("|                                             |\n");
        printf("|    giorno non disponibile, reinserirlo:     |\n");
        printf("|_____________________________________________|\n");
        scanf("%d", &data2->day);
    }

    // nel caso il mese non esista
    while (data2->month < 1 || data2->month > 12)
    {
        printf(" _____________________________________________\n");
        printf("|                                             |\n");
        printf("|     mese non disponibile, reinserirlo:      |\n");
        printf("|_____________________________________________|\n");
        scanf("%d", &data2->month);
    }

    anno_bisestile = 0;
    for (i = 1904; i < 2000; i = i + 4)
    {
        if (data2->year == i)
        {
            anno_bisestile++;
        }
    }
    for (i = 2004; i < 2100; i = i + 4)
    {
        if (data2->year == i)
        {
            anno_bisestile++;
        }
    }

    switch (data2->month)
    {
    case 2:
    {
        if (anno_bisestile == 0 && data2->day > 28)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto finePrevendita;
        }
        else if (anno_bisestile == 1 && data2->day > 29)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto finePrevendita;
        }
        break;
    }
    case 4:
    {
        if (data2->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto finePrevendita;
        }
        break;
    }
    case 6:
    {
        if (data2->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto finePrevendita;
        }
        break;
    }
    case 9:
    {
        if (data2->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto finePrevendita;
        }
        break;
    }
    case 11:
    {
        if (data2->day > 30)
        {
            printf(" _____________________________________________\n");
            printf("|                                             |\n");
            printf("|      data non esistente, reinserire:        |\n");
            printf("|_____________________________________________|\n");
            goto finePrevendita;
        }
        break;
    }
    }

    if (compare_dates(*data2, *data1) < 0)
    {
        printf(" ____________________________________________________\n");
        printf("|                                                    |\n");
        printf("|  la data di inizio e' successiva a quella di fine  |\n");
        printf("|                                                    |\n");
        printf("|  reinserire le date:                               |\n");
        printf("|____________________________________________________|\n");
        goto finePrevendita;
    }
}

void stampaBiglietto(int ticket, int countTicket)
{
    int i = 1;
    for (i = 1; i <= countTicket; i++)
    {
        switch (ticket)
        {
        case 1:
        {
            printf(" ________________________________________________________________________________________________________\n");
            printf("|      _____                 _____                    _______    __________  ___________    _______      |\n");
            printf("|     |     \\       |      /          |          |   |                |           |        /       \\     |\n");
            printf("|     |      \\      |     |           |          |   |                |           |        |       |     |\n");
            printf("|     |______/      |     |     ____  |          |   |_____           |           |        |       |     |\n");
            printf("|     |      \\      |     |      |    |          |   |                |           |        |       |     |\n");
            printf("|     |       \\     |     |      |    |          |   |                |           |        |       |     |\n");
            printf("|     |_______/     |      \\____/     |______    |   |_______         |           |        \\_______/     |\n");
            printf("|________________________________________________________________________________________________________|\n");
            printf("                                                                                                        \n");
            printf("                              numero: %d                 tipo: %d                                         \n", i, ticket);
            printf(" ________________________________________________________________________________________________________\n");
            break;
        }
        case 2:
        {
            printf(" ________________________________________________________________________________________________________\n");
            printf("|      _____                 _____                    _______    __________  ___________    _______      |\n");
            printf("|     |     \\       |      /          |          |   |                |           |        /       \\     |\n");
            printf("|     |      \\      |     |           |          |   |                |           |        |       |     |\n");
            printf("|     |______/      |     |     ____  |          |   |_____           |           |        |       |     |\n");
            printf("|     |      \\      |     |      |    |          |   |                |           |        |       |     |\n");
            printf("|     |       \\     |     |      |    |          |   |                |           |        |       |     |\n");
            printf("|     |_______/     |      \\____/     |______    |   |_______         |           |        \\_______/     |\n");
            printf("|________________________________________________________________________________________________________|\n");
            printf("                                                                                                        \n");
            printf("                              numero: %d                 tipo: %d                                         \n", i, ticket);
            printf("________________________________________________________________________________________________________\n");
            break;
        }
        case 3:
        {
            printf(" ________________________________________________________________________________________________________\n");
            printf("|      _____                 _____                    _______    __________  ___________    _______      |\n");
            printf("|     |     \\       |      /          |          |   |                |           |        /       \\     |\n");
            printf("|     |      \\      |     |           |          |   |                |           |        |       |     |\n");
            printf("|     |______/      |     |     ____  |          |   |_____           |           |        |       |     |\n");
            printf("|     |      \\      |     |      |    |          |   |                |           |        |       |     |\n");
            printf("|     |       \\     |     |      |    |          |   |                |           |        |       |     |\n");
            printf("|     |_______/     |      \\____/     |______    |   |_______         |           |        \\_______/     |\n");
            printf("|________________________________________________________________________________________________________|\n");
            printf("                                                                                                        \n");
            printf("                              numero: %d                 tipo: %d                                         \n", i, ticket);
            printf("________________________________________________________________________________________________________\n");
            break;
        }
        }
    }
}
// main
int main()
{
    // per continuare o uscire
    int next = 0;
    // tipo utente
    int tipo_utente = 0;
    // tipologia ticket
    int ticket = 0;
    // quantità ticket
    int ticket_number = 0;
    int max_ticket1 = 0;
    int max_ticket2 = 0;
    int max_ticket3 = 0;
    int countTicket = 0;
    // prezzi dei 3 tipi di biglietti
    float price1 = 0;
    float price2 = 0;
    float price3 = 0;

    // provvigioni
    float provvigione1 = (float)6 / 100;
    float provvigione2 = (float)12 / 100;
    float provvigione3 = (float)15 / 100;
    float rexultProvvigione = 0;
    // tipo di pagamento
    int typePayment = 0;
    // denaro
    float money = 0;
    float amount = 0;
    // pin carta
    int pinCard = 12345;

    // password admin
    char adminPasswordString[] = "admin1234";

    // eventi
    char event1[100] = "evento non assegnato";
    char event2[] = "Concerto di fine anno";
    char event3[] = "Concerto di primavera";
    int chooseEvent = 0;

    // selezione azione amministratore
    int adminChoice = 0;

    struct Date start_date, end_date, purchase_date;

    title();
    adminAutentication(adminPasswordString);
    adminEvents(event1, event2, event3, &price1, &price2, &price3, &max_ticket1, &max_ticket2, &max_ticket3, &start_date, &end_date);

    while (next == 0)
    {
    startCode:
        selezione_utente(&tipo_utente);
        printf(" __________________________________________\n");
        printf("|                                          |\n");
        printf("|    se vuoi proseguire premi 1            |\n");
        printf("|                                          |\n");
        printf("|    se vuoi ritornare all'inizio premi 0  |\n");
        printf("|__________________________________________|\n");
        scanf("%d", &next);
        while (!(next == 0 || next == 1))
        {
            printf(" __________________________________________\n");
            printf("|                                          |\n");
            printf("|    numero errato, riprovare:             |\n");
            printf("|                                          |\n");
            printf("|    se vuoi proseguire premi 1            |\n");
            printf("|                                          |\n");
            printf("|    se vuoi ritornare all'inizio premi 0  |\n");
            printf("|__________________________________________|\n");
            scanf("%d", &next);
        }
        if (next == 0)
        {
            continue;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (tipo_utente == 1)
        {
            adminAutentication(adminPasswordString);
            printf(" __________________________________________\n");
            printf("|                                          |\n");
            printf("|    se vuoi proseguire premi 1            |\n");
            printf("|                                          |\n");
            printf("|    se vuoi ritornare all'inizio premi 0  |\n");
            printf("|__________________________________________|\n");
            scanf("%d", &next);
            while (!(next == 0 || next == 1))
            {
                printf(" __________________________________________\n");
                printf("|                                          |\n");
                printf("|    numero errato, riprovare:             |\n");
                printf("|                                          |\n");
                printf("|    se vuoi proseguire premi 1            |\n");
                printf("|                                          |\n");
                printf("|    se vuoi ritornare all'inizio premi 0  |\n");
                printf("|__________________________________________|\n");
                scanf("%d", &next);
            }
            if (next == 0)
            {
                continue;
            }
            printf("evento 1: %s\n", event1);
            printf("evento 2: %s\n", event2);
            printf("evento 3: %s\n", event3);

            printf(" __________________________________________\n");
            printf("|                                          |\n");
            printf("|  selezionare 1 per settare i parametri   |\n");
            printf("|                                          |\n");
            printf("|  selezionare 2 per resoconto provvigione |\n");
            printf("|                                          |\n");
            printf("|  selezionare 3 per uscire                |\n");
            printf("|__________________________________________|\n");
            scanf("%d", &adminChoice);
            while (adminChoice != 1 && adminChoice != 2 && adminChoice != 3)
            {
                printf(" __________________________________________\n");
                printf("|                                          |\n");
                printf("|  selezione errata, riprovare             |\n");
                printf("|                                          |\n");
                printf("|  selezionare 1 per settare i parametri   |\n");
                printf("|                                          |\n");
                printf("|  selezionare 2 per resoconto provvigione |\n");
                printf("|                                          |\n");
                printf("|  selezionare 3 per uscire                |\n");
                printf("|__________________________________________|\n");
                scanf("%d", &adminChoice);
            }

            if (adminChoice == 1)
            {
                adminEvents(event1, event2, event3, &price1, &price2, &price3, &max_ticket1, &max_ticket2, &max_ticket3, &start_date, &end_date);
            }
            else if (adminChoice == 2)
            {
                printf("La provvigione totale e' di euro %f\n", rexultProvvigione);
            }
            else if (adminChoice == 3)
            {
                goto startCode;
            }
            goto startCode;
        }
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        else
        {
            // lettura della data corrente (data di acquisto)
            printf(" ______________________________________________________\n");
            printf("|                                                      |\n");
            printf("|                 Selezionare l'evento:                |\n");
            printf("|______________________________________________________|\n");
            printf("evento 1: %s --> disponibile\n", event1);
            printf("evento 2: %s --> ingressi esauriti\n", event2);
            printf("evento 3: %s --> ingressi esauriti\n", event3);
            scanf("%d", &chooseEvent);
            while (chooseEvent != 1)
            {
                printf(" ______________________________________________________\n");
                printf("|                                                      |\n");
                printf("|    Evento selezionato non disponibile, riprovare:    |\n");
                printf("|______________________________________________________|\n");
                printf("evento 1: %s --> disponibile\n", event1);
                printf("evento 2: %s --> ingressi esauriti\n", event2);
                printf("evento 3: %s --> ingressi esauriti\n", event3);
                scanf("%d", &chooseEvent);
            }
            purchaseDate:
            printf(" ____________________________________________________________________________________\n");
            printf("|                                                                                    |\n");
            printf("|                 Inserisci la data di acquisto (giorno mese anno):                  |\n");
            printf("|____________________________________________________________________________________|\n");
            scanf("%d %d %d", &purchase_date.day, &purchase_date.month, &purchase_date.year);
            while (purchase_date.day < 1 || purchase_date.day > 31)
            {
                printf(" _____________________________________________\n");
                printf("|                                             |\n");
                printf("|    giorno non disponibile, reinserirlo:     |\n");
                printf("|_____________________________________________|\n");
                scanf("%d", &purchase_date.day);
            }

            // nel caso il mese non esista
            while (purchase_date.month < 1 || purchase_date.month > 12)
            {
                printf(" _____________________________________________\n");
                printf("|                                             |\n");
                printf("|     mese non disponibile, reinserirlo:      |\n");
                printf("|_____________________________________________|\n");
                scanf("%d", &purchase_date.month);
            }
            int i = 0;
            int anno_bisestile = 0;
            for (i = 1904; i < 2000; i = i + 4)
            {
                if (purchase_date.year == i)
                {
                    anno_bisestile++;
                }
            }
            for (i = 2004; i < 2100; i = i + 4)
            {
                if (purchase_date.year == i)
                {
                    anno_bisestile++;
                }
            }

            switch (purchase_date.month)
            {
            case 2:
            {
                if (anno_bisestile == 0 && purchase_date.day > 28)
                {
                    printf(" _____________________________________________\n");
                    printf("|                                             |\n");
                    printf("|      data non esistente, reinserire:        |\n");
                    printf("|_____________________________________________|\n");
                    goto purchaseDate;
                }
                else if (anno_bisestile == 1 && purchase_date.day > 29)
                {
                    printf(" _____________________________________________\n");
                    printf("|                                             |\n");
                    printf("|      data non esistente, reinserire:        |\n");
                    printf("|_____________________________________________|\n");
                    goto purchaseDate;
                }
                break;
            }
            case 4:
            {
                if (purchase_date.day > 30)
                {       
                    printf(" _____________________________________________\n");
                    printf("|                                             |\n");
                    printf("|      data non esistente, reinserire:        |\n");
                    printf("|_____________________________________________|\n");
                    goto purchaseDate;
                }
                break;
            }
            case 6:
            {
                if (purchase_date.day > 30)
                {
                    printf(" _____________________________________________\n");
                    printf("|                                             |\n");
                    printf("|      data non esistente, reinserire:        |\n");
                    printf("|_____________________________________________|\n");
                    goto purchaseDate;
                }
                break;
            }
            case 9:
            {
                if (purchase_date.day > 30)
                {
                    printf(" _____________________________________________\n");
                    printf("|                                             |\n");
                    printf("|      data non esistente, reinserire:        |\n");
                    printf("|_____________________________________________|\n");
                    goto purchaseDate;
                }
                break;
            }
            case 11:
            {
                if (purchase_date.day > 30)
                {
                printf(" _____________________________________________\n");
                printf("|                                             |\n");
                printf("|      data non esistente, reinserire:        |\n");
                printf("|_____________________________________________|\n");
                goto purchaseDate;
                }
                break;
            }
            }

            // confronto della data di acquisto con la data di inizio e fine della prevendita
            if (compare_dates(purchase_date, start_date) >= 0 && compare_dates(purchase_date, end_date) <= 0)
            {
            }
            else
            {
                printf(" ____________________________________________________________________________________\n");
                printf("|                                                                                    |\n");
                printf("|       La data di acquisto non e' valida. Il biglietto non e' nella prevendita.     |\n");
                printf("|____________________________________________________________________________________|\n");
                goto startCode;
            }

            ticket_type(&ticket, price1, price2, price3);
            printf(" __________________________________________\n");
            printf("|                                          |\n");
            printf("|    se vuoi proseguire premi 1            |\n");
            printf("|                                          |\n");
            printf("|    se vuoi ritornare all'inizio premi 0  |\n");
            printf("|__________________________________________|\n");
            scanf("%d", &next);
            while (!(next == 0 || next == 1))
            {
                printf(" __________________________________________\n");
                printf("|                                          |\n");
                printf("|    numero errato, riprovare:             |\n");
                printf("|                                          |\n");
                printf("|    se vuoi proseguire premi 1            |\n");
                printf("|                                          |\n");
                printf("|    se vuoi ritornare all'inizio premi 0  |\n");
                printf("|__________________________________________|\n");
                scanf("%d", &next);
            }
            if (next == 0)
            {
                continue;
            }

            ticket_amount(&ticket_number, &max_ticket1, &max_ticket2, &max_ticket3, &next, &countTicket);

            printf(" __________________________________________\n");
            printf("|                                          |\n");
            printf("|    se vuoi proseguire premi 1            |\n");
            printf("|                                          |\n");
            printf("|    se vuoi ritornare all'inizio premi 0  |\n");
            printf("|__________________________________________|\n");
            scanf("%d", &next);
            while (!(next == 0 || next == 1))
            {
                printf(" __________________________________________\n");
                printf("|                                          |\n");
                printf("|    numero errato, riprovare:             |\n");
                printf("|                                          |\n");
                printf("|    se vuoi proseguire premi 1            |\n");
                printf("|                                          |\n");
                printf("|    se vuoi ritornare all'inizio premi 0  |\n");
                printf("|__________________________________________|\n");
                scanf("%d", &next);
            }
            if (next == 0)
            {
                continue;
            }
        }
        payment(&typePayment, &money, price1, price2, price3, ticket_number, ticket, pinCard, &amount, provvigione1, provvigione2, provvigione3, &rexultProvvigione, &countTicket);
        stampaBiglietto(ticket, countTicket);
        goto startCode;
    }
    return 0;
}