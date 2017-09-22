#include<stdio.h>
#include<stdlib.h>

int aboutInfor()
{
    printf("***************************Information***************************\n"
           "*\t\t\t\t\t\t\t\t*\n"
           "*\tinfor\t\tShow this infor list\t\t\t*\n"
           "*\thelp\t\tShow help information\t\t\t*\n"
           "*\thello\t\tSay hello\t\t\t\t*\n"
           "*\tdate\t\tShow date and time\t\t\t*\n"
           "*\tcode\t\tPrint the code of menu.c\t\t*\n"
           "*\tls\t\tList files\t\t\t\t*\n"
           "*\tpwd\t\tPrint working directory\t\t\t*\n"
           "*\tquit\t\tQuit this program\t\t\t*\n"
           "*\t\t\t\t\t\t\t\t*\n" 
           "*****************************************************************\n\n"
    );
    return 0;
}

int cmdHelp()
{
    printf("This is a small menu program,users can get the corresponding  results through different operations!\n");
    return 0;
}


int cmdHello()
{
    printf("Hello users!\n");
    printf("Welcome to this menu!\n");
    return 0;
}

int printCode()
{
    char c;
    FILE *fp = NULL;
    fp = fopen("menu.c", "r");
    if (NULL == fp)
    {
        printf("Error: menu.c does not exist!\n");
        return -1;
    }
    while (fscanf(fp, "%c", &c) !=EOF)
        printf("%c", c);
    fclose(fp);
    fp = NULL;
    return 0;
}

int main()
{
    char cmd[128];
    while(1)
    {
        printf("Menu->");
        scanf("%s", cmd);
        if (strcmp(cmd, "infor") == 0)
        {
            aboutInfor();
        }
        else if (strcmp(cmd, "help") == 0)
        {
            cmdHelp();
        }
        else if (strcmp(cmd, "hello") == 0)
        {
            cmdHello();
        }
        else if (strcmp(cmd, "date") == 0)
        {
            system(cmd);
        }
        else if (strcmp(cmd, "code") == 0)
        {
            printCode(cmd);
        }
        else if (strcmp(cmd, "ls") == 0)
        {
            system(cmd);
        }
        else if (strcmp(cmd, "pwd") == 0)
        {
            system(cmd);
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Error!\n");
        }
    }
}





