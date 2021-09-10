#include <stdio.h>
#include <term.h>

char box[10] = {'0','1','2','3','4','5','6','7','8','9'};
void creating_board();
void marking_board(int,char); //pour marquer une croix ou un rond sur le board
int check_for_win(); //pour le vainqueur

int main()
{
    int choix,joueur=1,i;
    char marque;

    do{
        creating_board();
        joueur = (joueur % 2) ? 1: 2; // permet d'obtenir joueur 1/2
        
        printf("Joueur %d, entrez un nombre pour poser votre pion : ", joueur);
        scanf("%d", &choix);

        marque = (joueur==1) ? 'X' : 'O'; //permet d'alterner la marque(X ou O) en fonction du joueur 1 ou joueur 2
        marking_board(choix,marque);

        i=check_for_win();
        joueur++; // permet de changer de joueur
    }while (i == -1);

    creating_board();

    if(i==1)
        printf("Joueur %d, tu as remporté la partie !", --joueur);
    else
        printf("<-------Égalité------->");

    return 0;
}

void creating_board() 
{
    printf("\n\n\t Tic Tac Toe\n\n");
    printf("Joueur 1 (X) vs Joueur 2 (O)\n\n");
    printf("     |    |    \n");
    printf(" %c   | %c  | %c   \n", box[1], box[2],box[3]);
    printf("_____|____|_____\n");
    printf("     |    |    \n");
    printf(" %c   | %c  | %c   \n", box[4], box[5],box[6]);
    printf("_____|____|_____\n");
    printf("     |    |    \n");
    printf(" %c   | %c  | %c   \n", box[7], box[8],box[9]);
    printf("_____|____|_____\n");
    printf("     |    |    \n");

}

void marking_board(int choix, char marque)
{

    if(choix == 1 && box[1] == '1')
        box[1] = marque;
    else if (choix == 2 && box[2] == '2')
        box[2] = marque;
    else if (choix == 3 && box[3] == '3')
        box[3] = marque;
    else if (choix == 4 && box[4] == '4')
        box[4] = marque;
    else if (choix == 5 && box[5] == '5')
        box[5] = marque;
    else if (choix == 6 && box[6] == '6')
        box[6] = marque;
    else if (choix == 7 && box[7] == '7')
        box[7] = marque;
    else if (choix == 8 && box[8] == '8')
        box[8] = marque;
    else if (choix == 9 && box[9] == '9')
        box[9] = marque;
    else{
        printf("Choix invalide");
    }
}

int check_for_win() // Possibilité de victoire
{
    if (box[1]==box[2] && box[2]==box[3])       // Alignement horizontal
        return 1;
    else if (box[4]==box[5] && box[5]==box[6])
        return 1;
    else if (box[7]==box[8] && box[8]==box[9]) 
        return 1;

    else if (box[1]==box[4] && box[4]==box[7])  // Aligement vertical
        return 1;
    else if (box[2]==box[5] && box[5]==box[8])
        return 1;
    else if (box[3]==box[6] && box[6]==box[9])
        return 1;

    else if (box[1]==box[5] && box[5]==box[9])  // Alignement diagonal
        return 1;
    else if (box[3]==box[5] && box[5]==box[7])
        return 1;
    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9') // pas d'alignement
        return 0;
    else
        return -1;

}