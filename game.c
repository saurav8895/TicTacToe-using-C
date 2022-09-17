#include<stdio.h>
#include<string.h>
void printBoard(char arr[9]){
    printf("\n");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2TIC TAC TOE\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\n");
    printf("FIRST PLAYER : X\t\tSECOND PLAYER : O\n");
    printf("   \t|\t| \n");
    for (int i = 0; i < 9; i++)
    {
        if(i==8){
            printf("   %c\n",arr[i]);
            printf("\t|\t| \n");
            break;
        }
        if((i+1)%3==0){
            printf("   %c\n",arr[i]);
            printf("________|_______|________\n");
            printf("\t|\t| \n");
            continue;
        }
        printf("   %c\t|",arr[i]);
        
    }
    
}
int main()
{
    char arr[9];
    
    memset(arr,'E',9*sizeof(char));
    printBoard(arr);
    return 0;
}