#include <stdio.h>
#include <stdlib.h>

const int linesize = 1024;

void cleanup(FILE* f, char** ls, int nL){
    ftruncate(fileno(f), 0);
    fseek(f, 0, SEEK_SET);
    for(int i = 0; i < nL; i++){
        fputs(ls[i], f);
        free(ls[i]);
    }
    free(ls);
    fclose(f);
}

void printFile(char** ls, int nL){
    printf("the state of the file is: \n");
    for(int i = 0; i < nL; i++){
        printf("%d: %s", i, ls[i]);
    }
}

void editLine(int line, char** ls, int nL){
    printf("Type the text you want to replace line %d with: \n", line);
    
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    char* newLine = malloc(linesize * sizeof(char));
    fgets(newLine, linesize, stdin);

    free(ls[line]);
    ls[line] = newLine;
}

void insertLine(int line, char** ls, int* nL){
    
    char* newLine = malloc(linesize * sizeof(char));
    printf("New text to insert at line %d: \n", line);
    
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    fgets(newLine, linesize, stdin);

    for(int i = *nL; i < line; i--){
        ls[i] = ls[i-1];
    }
    ls[line] = newLine;
    (*nL)++;

    // free(ls[line]);
}

void deleteLine(int line, char** ls, int* nL){
    char* oldPointer = ls[line];
    free(ls[line]);

    for(int i = line; i < (*nL) - 1; i--){
        ls[i] = ls[i+1];
    }
    free(oldPointer);
    free(ls[(*nL)-1]);
    (*nL)--;
    
}

int main(int argc, char* argv[]){

    FILE *ourFile = fopen(argv[1], "r+");

    if(ourFile < 0){
        return 1;
    }
    char** lines = malloc(10000 * sizeof(char*));
    int numLines = 0;
    lines[0] = malloc(linesize);
    
    while(fgets(lines[numLines], linesize, ourFile)){
        numLines++;
        lines[numLines] = malloc(linesize);
    }
    free(lines[numLines]);
    printf("the file you're going to edit is: \n");
    for (int i = 0; i < numLines; i++){
        printf("line %d is: %s", i, lines[i]);
    }
    printf("\n");


    int option = 0;
    while(option != 4){
        printf("Welcome to our goofy little file editor: \n");
        // printFile(lines, numLines);
        printf("1: edit a line\n");
        printf("2: delete a line\n");
        printf("3: insert a line\n");
        printf("4: quit\n");

        scanf("%d", &option);
        switch(option){
            int line;
            case 1:{
                printf("Which line do you want to edit?");
                scanf("%d", &line);
                editLine(line, lines, numLines);
                break;
            }
            case 2:{
                scanf("Which line would you like to delete?: ");
                scanf("%d", &line);
                deleteLine(line, lines, &numLines);
                break;
            }
            case 3:{
                printf("Which line would you like to insert?");
                scanf("%d", &line);
                insertLine(line, lines, &numLines);
                break;
            }
            case 4:{
                printf("GOODBYE.\n");
                cleanup(ourFile, lines, numLines);
                continue;
                break;
            }
        }


    }
    return 0;
}