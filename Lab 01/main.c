#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



#define MAX 50
#define ADDRESS "/bin"

int main()
{
    int match = 0;
    int terminator = 0;

    char user_input[MAX];
    fgets(user_input,MAX,stdin);
    for (int i = 0; i < MAX; i++)
    {
        if (user_input[i]=='\n')
        {
            user_input[i] = '\0';
            }
        }
    
    
    char* str_hello = "hello";
    char* typeone [] = {"hello","bye","author","section","assignment"}; 

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(user_input, typeone[i]) == 0){
            match = 1;
            break;
        }
        
    }

    if (match)
    {
        if (strcmp(user_input, typeone[0]) == 0){
            printf("hello, world");
        }
        if (strcmp(user_input, typeone[2]) == 0){
            printf("Sylvia Chen, N17312194, sc8043");
        }
        if (strcmp(user_input, typeone[3]) == 0){
                printf("002");
        }
        if (strcmp(user_input, typeone[4]) == 0){
            printf("%s", "202 lab #1 (Spring 2022)");
        }
        if (strcmp(user_input, typeone[1]) == 0){
            terminator = 1;
         }
        }

    else{
        int PorC = fork();
        if (PorC == 0)
        {
            // excuted by child
            char* command[] = {user_input,NULL};
            execve(ADDRESS,command,NULL);
            
        }
        else{
            // excuted by parent 
            char* command[] = {user_input,NULL};
            execve(ADDRESS,command,NULL);
            int status;
            wait(&status);
        }

        }
    
    return 0;
}


