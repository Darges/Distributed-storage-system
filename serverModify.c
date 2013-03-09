/********************************************************************/
/* Copyright (C) SSE-USTC 2013                                      */
/*                                                                  */
/*  FILE NAME             :  serverModify.c                         */
/*  PRINCIPAL AUTHOR      :  SongGuantao                            */
/*  SUBSYSTEM NAME        :  server                                 */
/*  MODULE NAME           :  server                                 */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  Any                                    */
/*  DATE OF FIRST RELEASE :  2013/03/09                             */
/*  DESCRIPTION           :  Reply Client User(Server)              */
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
    char sgtReplyMsg[MAX_BUF_LEN] = "hi\0";
    InitializeService();
    while(1)
    {
        printf("Waiting for connecting......\n");
        ServiceStart();
        RecvMsg(sgtBuf); 
        SendMsg(sgtReplyMsg);
        ServiceStop();
    }
    ShutdownService();
    return 0;    
}
