// Count small Character from file
// Maximum throughput in minimum hardware movement
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int CountSmall(char Fname[])
{
     int iRet = 0;
     int fd = 0;   //File Discriptor
     char Data[10];  
     int iCnt = 0;
     int i = 0;

     fd = open(Fname,O_RDWR);
     if(fd == -1)
     {
          printf("Unable to open the file\n");
          return -1;
      
     }

     while((iRet = read(fd,Data,sizeof(Data))) !=0)
     {
        for(i = 0;i < iRet ; i++)
        {
          if(Data[i] >= 'a'&& Data[i] <= 'z')
          {
               iCnt++;
          }
        }
     }

     close(fd);
     return iCnt;

}

int main()
{
     char Fname[20];
     char Data[10];         //Mug
     int iRet = 0;

     int fd = 0;   //File Discriptor
     
     printf("Enter File name to open\n");
     scanf("%s",Fname);

     iRet =  CountSmall(Fname);
     printf("Number of small characters are:  %d\n",iRet);


     return 0;
}
