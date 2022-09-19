#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
static int cnt=0;
    char names[3][20];
void printBoard(char arr[9]){
    
    system("cls");
    printf("\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2{ TIC\tTAC\tTOE }\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    
    // printf("%20cFIRST PLAYER : X\tSECOND PLAYER : O\n\n",' ');
    printf("\t\tFIRST PLAYER :%s : X\tSECOND PLAYER :%s : O\n\n",names[1],names[2]);
    printf("  \t\t\t\t|\t| \n"," ");
    printf("\t\t\t");
    for (int i = 0; i < 9; i++)
    {
        if(i==8){
            printf("  %c\n",arr[i]);
            printf("\t\t\t\t|\t| \n");
            break;
        }
        if((i+1)%3==0){
            printf("  %c\n",arr[i]);
            printf("\t\t\t________|_______|________\n");
            printf("  \t\t\t\t|\t| \n"," ");
            printf("\t\t\t");
            continue;
        }
        printf("   %c\t|",arr[i]);
        
    }
    
}

void user_input(char arr[],int player){
    int pos;
   do
   {
    printf("Enter the Position :");
    scanf("%d",&pos);
    pos--;
   } while (arr[pos]!=' ');
        cnt++;
        if(player==1)
        arr[pos]='X';
        else
        arr[pos]='O';
    printBoard(arr);
    // return;
}
char winning(char arr[]){
    if(arr[0]==arr[1] && arr[0]==arr[2] )
     return arr[0];
    if(arr[3]==arr[4] && arr[3]==arr[5])
     return arr[3];
    if(arr[6]==arr[7] && arr[6]==arr[8])
     return arr[6];

    if(arr[0]==arr[3] && arr[0]==arr[6])
     return arr[0];
    if(arr[1]==arr[4] && arr[1]==arr[7])
     return arr[1];
    if(arr[2]==arr[5] && arr[2]==arr[8])
     return arr[2];


    if(arr[0]==arr[4] && arr[0]==arr[8])
     return arr[0];
    if(arr[2]==arr[4] && arr[2]==arr[6])
     return arr[2];

      return ' ';
}
int main()
{
    char arr[9];
    
    for (int i = 1; i < 3; i++)
    {
        printf("enter %dth player's name\n",i);
        scanf("%s",&names[i]);
    }
    memset(arr,' ',9*sizeof(char));
    printBoard(arr);
    char w ;
    // user_input(arr,1);
    int current_player=1;
    do
    {
        printf("%s's turn\n",names[current_player]);
        if(current_player==1)
        {
            user_input(arr,1);
            current_player=2;
        }
        else
        {
             user_input(arr,2);
            current_player=1;
        }
        fflush(stdin);
        w=winning(arr);
     
    } while (cnt<=8 && w==' ');
    if(cnt==9 && w==' ')
    printf("Match Draw\n");
    else
    printf("\nCongratulations %s You Won.",names[3-current_player]);
    
    return 0;
}