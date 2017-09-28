#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

int ShowAllCmd(tDataNode *head)
{
    printf("\n");
    printf("***************Menu List***************\n");
    tDataNode *p = head;
    while(p != NULL)
    {
	printf("%s\t- %s\n", p->cmd, p->desc);
	p = p->next;
    }
    printf("***************************************\n");
    return 0;
}

tDataNode * FindCommand(tDataNode *head, char *cmd)
{
    if(head == NULL || cmd == NULL)
    {
	return NULL;
    }
    tDataNode *p = head;
    while(p != NULL)
    {
 	if(!strcmp(cmd, p->cmd))
        {
	    return p;
	}
        p = p->next;
    }
    return NULL;
}


