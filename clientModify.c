/********************************************************************/
/* Copyright (C) SSE-USTC 2013                                      */
/*                                                                  */
/*  FILE NAME             :  clientModify.h                             */
/*  PRINCIPAL AUTHOR      :  SongGuantao                            */
/*  SUBSYSTEM NAME        :  client                                 */
/*  MODULE NAME           :  client                                 */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  Any                                    */
/*  DATE OF FIRST RELEASE :  2013/03/09                             */
/*  DESCRIPTION           :  Reply Service User(Client)             */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by SongGuantao,2013/03/09  
 *
 */
 
#include"mysyswrapper.h"

#define MAX_CONNECT_QUEUE   1024

int main()
{
    char sgtBuf[MAX_BUF_LEN] = "\0";
    char sgtMsg[MAX_BUF_LEN] = "hello\0";
    OpenRemoteService();
	SendMsg(sgtMsg);
	RecvMsg(sgtBuf);
	CloseRemoteService();
	return 0;
}

