/*
#############################PROGRAMMA FRED##################################
#                                                                           #
#Copyright © 2015 Corrado Mulas.                                            #
#                                                                           #
#Rilasciato dietro licenza GNU GENERAL PUBLIC LICENSE VERSION 3             #
#                                                                           #
#    This program is free software: you can redistribute it and/or modify   #
#    it under the terms of the GNU General Public License as published by   #
#    the Free Software Foundation, either version 3 of the License, or      #
#    (at your option) any later version.                                    #
#                                                                           #
#    This program is distributed in the hope that it will be useful,        #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of         #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          #
#    GNU General Public License for more details.                           #
#                                                                           #
#    You should have received a copy of the GNU General Public License      #
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.  #
#                                                                           #
#############################################################################
*/


#include <stdio.h>
//#include <santodio.h> (St. Dio)

int main()
{
    //DICHIARAZIONI
    unsigned int nmazzi;
    unsigned int incasso;
    unsigned int minprezzo;
    unsigned int maxprezzo;
    unsigned int prezzo;
    unsigned int richiesta;
    unsigned int buffer;
    unsigned int media;
    unsigned int _PREZZO_MAX;
    unsigned int i;

    //VARIABILI
    _PREZZO_MAX = 101;          //Il massimo prezzo praticabile
    minprezzo = _PREZZO_MAX;    //Il prezzo più basso registrato;
    maxprezzo = 0;              //Il prezzo del mazzo più costoso venduto;
    nmazzi = 0;                 //Numero di mazzi di fiori venduto
    incasso = 0;
    i = 0;

//Testo di benvenuto
 printf("Fred v1.1. Sei un dannato Stakhanovista, ricordatelo sempre. E non chiamarmi Rosario.\n");

//Loop infinito
        while(i < 1)
        {
                //Chiedo cosa devo fare: devo informare il capo su come vanno gli affari, vendo dei fiori o devo andare a casa?
                printf("\nSpecificare una richiesta: [1] per il capo, [2] per il cliente, [3] per mandarmi (finalmente) a casa: ");
                scanf("%i", &buffer);
                richiesta = buffer;

//switch-case è meglio di una marea di else if
            switch(richiesta) {
                case 1 :
                    //è venuto quel bastardone del capo...
                    //Azioni da fare nel caso abbia venduto degli articoli:
                    if(nmazzi != 0)
                    {
                        printf("\nMAX prezzo: €%d", maxprezzo);         //Scrivo il prezzo del mazzo più costoso
                        printf("\nMIN prezzo: €%i", minprezzo);         //Scrivo il prezzo del mazzo meno costoso
                        printf("\nNumero mazzi venduti: %i", nmazzi);   //Scrivo il numero di mazzi venduto
                        media = (incasso/nmazzi);                       //Calcolo il prezzo medio dei mazzi venduti
                        printf("\nPrezzo medio per mazzo: €%i", media); //Scrivo il dato precedentemente calcolato
                        printf("\nSei un dannato Stakhanovista");       //Insulto il capo perché mi fa lavorare troppo.
                    }
                    //Se non ho venduto niente... Informo il capo e lo insulto nuovamente
                    else
                    {
                        printf("\nPer ora non ho venduto niente, e tu sei un dannato Stakhanovista.");
                    }
                break;

                case 2 :
                    //C'è un cliente
                    //Gli chiedo che mazzo vuole, di conseguenza inserisco il prezzo per registrarlo:
                    printf("\nInserire il prezzo: ");
                    scanf("%i", &buffer);
                    prezzo = buffer;

                    //Rosario, non cercar di imbrogliare il cliente!
                    if(prezzo > _PREZZO_MAX)
                    {
                        printf("\nQui non si vendono mazzi a più di 100€. Vendita non registrata.");
                    }
                    else
                    {   //Segno i prezzi massimi e minimi
                        if(prezzo < minprezzo && prezzo < _PREZZO_MAX)
                        {
                            minprezzo = prezzo;
                        }
                        if(prezzo > maxprezzo && prezzo < _PREZZO_MAX)
                        {
                            maxprezzo = prezzo;
                        }
                        //Incremento di una unità il numero di mazzi venduto, e aggiorno l'incasso con un operatore di assegnazione
                        nmazzi++;
                        incasso += prezzo;
                    }
                break;

                case 3 :
                    //È ora di rientrare a casa, scordati fortemente che Rosario (Fred) porterà con sé i dati delle variabili, credo che li userà per accendere il camino.
                    printf("Arrivederci! Ora ho perso tutte le variabili memorizzate perché sono MALVAGIO! Muahahahahah! Hai bessu, sporco capitalista. \n");
                    return 0;
                break;

                default :
                    //Ovviamente ora qualcuno sta approfittando della pazienza di Fred, ma lui sa già come rispondere:
                    printf("\nRichiesta non valida, ora ti denuncio per mobbing.");
                break;

            }



        }

}
