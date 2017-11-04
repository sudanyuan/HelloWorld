/****************************************************************/
/* Copyright  (C)  SSE_USTC,  2017-2018                         */
/*                                                              */
/*  FILE NAME              :   menu.h                           */
/*  PRINCIPAL AUTHOR       :   sudanyuan                        */
/*  SUBSYSTEN NAME         :   menu                             */
/*  MODULE NAME            :   menu                             */
/*  LANGUAGE               :   C                                */ 
/*  TARGET ENVIRONMENT     :   ANY                              */
/*  DATE OF FIRST RELEASE  :   2017/11/3                        */
/****************************************************************/

/* 
 * Revision log:
 * Created by sudanyuan,2017/11/3
 * Verified callback and head/next for search by sudanyuan,2017/11/3
 */

/* add cmd to menu */
int MenuConfig(char * cmd, char * desc, void (*handler)(int argc, char *argv[]));

/* Menu Engine Execute */
int ExecuteMenu();


