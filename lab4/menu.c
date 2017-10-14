/****************************************************************/
/* Copyright  (C)  SSE_USTC,  2017-2018                         */
/*                                                              */
/*  FILE NAME              :   menu.c                           */
/*  PRINCIPAL AUTHOR       :   sudanyuan                        */
/*  SUBSYSTEN NAME         :   menu                             */
/*  MODULE NAME            :   menu                             */
/*  LANGUAGE               :   C                                */ 
/*  TARGET ENVIRONMENT     :   ANY                              */
/*  DATE OF FIRST RELEASE  :   2017/10/13                       */
/****************************************************************/

/*
 * Created by sudanyuan,2017/10/13
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "linktable.h"

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char* cmd;
    char* desc;
    int   (*handler)();
}tDataNode;

/* find a cmd in the linktable and return the datanode pointer */
tDataNode* FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
	if(strcmp(pNode->cmd, cmd) == 0)
	{
            return pNode;
	}
	pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}

/* show all cmd in linktable */
int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
	printf("%s\t - %s\n",pNode->cmd, pNode->desc);
	pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode* ) pNode);
    }
    return 0;
}

static tDataNode menu[] =
{
    {(tLinkTableNode*)&menu[1],"Help","Menu List:",Help},
    {(tLinkTableNode*)&menu[2],"version","Menu Program V1.0",NULL},
    {(tLinkTableNode*)NULL,"quit","Quit from Menu Program v1.0",Quit}
};

int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    (*ppLinktable)->pHead = (tLinkTableNode*)&menu[0];
    (*ppLinktable)->pTail = (tLinkTableNode*)&menu[2];
    (*ppLinktable)->SumOfNode = 3;
    
}

/* menu program */

tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head);
    printf("Welcome this program!\n");
    printf("Please use 'Help' to show the menu!");
    /* cmd line begins */
    while(1)
    {
	char cmd[CMD_MAX_LEN];
	printf("\n\n");
	printf("Input a cmd number -> ");
	scanf("%s", cmd);
	tDataNode *p = FindCmd(head, cmd);
	if( p == NULL)
	{
	    printf("This is a wrong cmd!\n");
	    continue;
	}
	printf("%s\t - %s\n",p->cmd, p->desc);
	if(p->handler != NULL)
	{
	    p->handler();
	}
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}

int Quit()
{
    exit(0);
}




