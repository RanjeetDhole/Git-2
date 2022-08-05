//Accept File name from user count length of that File

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int FileLength(char Fname[])
{
     int iRet = 0;
     int fd = 0;   //File Discriptor
     char Data[10];  
     int iSum = 0;

     fd = open(Fname,O_RDWR);
     if(fd == -1)
     {
          printf("Unable to open the file\n");
          return -1;
      
     }

     while((iRet = read(fd,Data,sizeof(Data))) !=0)
     {
          iSum = iSum + iRet;
     }

     close(fd);
     return iSum;

}

int main()
{
     char Fname[20];
     char Data[10];         //Mug
     int iRet = 0;

     int fd = 0;   //File Discriptor
     
     printf("Enter File name to open\n");
     scanf("%s",Fname);

     iRet = FileLength(Fname);
     printf("File Length is: %d\n",iRet);


     return 0;
}
