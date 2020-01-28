#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define STR_LIMIT 512
#define DEBUG

char* cwd;
char* user;


//Initialise shell
void initShell(){
    //Set working directory to users home directory
    cwd = getenv("HOME");
    //Change current directory to home path
    chdir(cwd);
    #ifdef
    char* buff;
    char* test = getcwd(buff,0); 
    printf("%s",test);
    #endif
    //Set user to the username of the user
    user = getenv("USER");

}

void getCommand()
{
    //Variable to store users input. Set to hold a max of 512 characters
    char str[STR_LIMIT];
    //Delimeter variable to tokenise string
    char *delimiter = " \t|><&;\n";
    //Print out "> " and wait for user input
    printf("> ");
    char *input = fgets(str, STR_LIMIT, stdin);
    //Check for ctrl + D input
    if (input == NULL)
    {
        printf("\n");
        exit(0);
    }
    //Tokenise user input using Delimeters
    char *token = strtok(str, delimiter);
    while (token != NULL)
    {
        //Check if user inputs exit command
        if (strcmp("exit", token) == 0)
        {
            exit(0);
        }
        //Check that tokens are correct
        #ifdef DEBUG
        printf("\"");
        printf("%s", token);
        printf("\"\n");
        #endif
        token = strtok(NULL, delimiter);
    }
}

int main()
{
    //Initialise shell
    initShell();
    //Loop until the shell is terminated
    do
    {
        //Print user, current directory and prompt
        printf("%s: %s", user, cwd);
        //Get user input
        getCommand();
    } while (1);
}
