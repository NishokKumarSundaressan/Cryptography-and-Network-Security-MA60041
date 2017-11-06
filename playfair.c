#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int input(char key[],char msg[])
{
  int flag = 0;
    int i,j,k=0;
  do{
   printf("Enter the key:");
   char key1[100005];
   scanf("%[^\n]%*c",key1);
   for(i=0;key1[i];i++)
   {
      if(isalpha(key1[i]))
      {
        key[k++]=key1[i]!='j'?key1[i]:'i';
      }
   }
   key[k]='\0';
   int check[26]={0};
   for(i=0;i<strlen(key);i++)
   check[tolower(key[i])-97]++;
   flag++;
 }while(!flag);
 int choice;
  do{
  printf("Enter choice: Encrypt(1)/Decrypt(2):");

  scanf("%d",&choice);
  }while(choice!=1&&choice!=2);
  if(choice==1)
  printf("Enter the message to be encrypted:");
  else
   printf("Enter the ciphertext to be decrypted:");
  fflush(stdin);
  scanf("%[^\n]%*c",msg);
  return choice;

}
void encrypt(char key[],char msg[],char message[])
{
   char msg1[100005];
   int i,j,k;
   for(i=0;msg[i];i++)
   {
     msg1[i]=tolower(msg[i])!='i'&&tolower(msg[i])!='j'?tolower(msg[i]):'i';
   }
   msg1[i]='\0';
   for(i=0,k=0;msg1[i];i++)
   {
       if(isalpha(msg1[i]))
       {

         if(k%2&&(msg1[i]==message[k-1]))
         {
            message[k++]='x';
            message[k++]=msg1[i];

         }else
         message[k++]=msg1[i];
       }
   }
   message[k]='\0';
   char matrix[6][6];
   int row[26],col[26];

   char arr[100];
   int l=0;
   char arr1[25] = "abcdefghiklmnopqrstuvwxyz";
   int cha[26]={0};
   int qq=0;
   for(k=0;k<strlen(key);k++)
   {
     if((tolower(key[k])=='i'||tolower(key[k])=='j')&&!cha[tolower(key[k])-97])
     {
       arr[qq]='i';arr1[8]='.';qq++;
        cha[tolower(key[k])-97]=1;
     }
     else if(!cha[tolower(key[k])-97])
     {
       arr[qq]=tolower(key[k]);qq++;
       cha[tolower(key[k])-97]=1;
       if(tolower(key[k])>'i')
       arr1[tolower(key[k])-98]='.';
       else arr1[tolower(key[k])-97]='.';
     }
   }
   arr[qq]='\0';
   strcat(arr,arr1);
   for(i=0;i<5;i++)
   for(j=0;j<5;j++)
   {
     while(arr[l]=='.')l++;
     matrix[i][j] = arr[l];
     row[arr[l]-97]=i;
     col[arr[l]-97]=j;
     l++;


   }
   for(i=0;i<5;i++)
   {
     for(j=0;j<5;j++)
     printf("%c ",matrix[i][j]);
     printf("\n");

   }
   if(strlen(message)%2)
   {
     strcat(message,"x");
   }
   for(i=0;i<strlen(message);i+=2)
   {
      if(row[message[i]-97]==row[message[i+1]-97])
      {
        message[i]=matrix[row[message[i]-97]][(col[message[i]-97]+1)%5];
        message[i+1]=matrix[row[message[i+1]-97]][(col[message[i+1]-97]+1)%5];
      }
      else if(col[message[i]-97]==col[message[i+1]-97])
      {
        message[i]=matrix[(row[message[i]-97]+1)%5][col[message[i]-97]];
        message[i+1]=matrix[(row[message[i+1]-97]+1)%5][col[message[i+1]-97]];
      }
      else
      {
         char temp = message[i];
         message[i]=matrix[row[message[i]-97]][col[message[i+1]-97]];
         message[i+1]=matrix[row[message[i+1]-97]][col[temp-97]];


      }


   }
}
void decrypt(char key[],char msg[],char message[])
{
   char msg1[100005];
   int i,j,k;
   for(i=0;msg[i];i++)
   {
     msg1[i]=tolower(msg[i])!='i'&&tolower(msg[i])!='j'?tolower(msg[i]):'i';
   }
   msg1[i]='\0';
   for(i=0,k=0;msg1[i];i++)
   {
       if(isalpha(msg1[i]))
       {
         message[k++]=msg1[i];
       }
   }
   message[k]='\0';
   char matrix[6][6];
   int row[26],col[26];

   char arr[100];
   int l=0;
   char arr1[25] = "abcdefghiklmnopqrstuvwxyz";
   int cha[26]={0};
   int qq=0;
   for(k=0;k<strlen(key);k++)
   {
     if((tolower(key[k])=='i'||tolower(key[k])=='j')&&!cha[tolower(key[k])-97])
     {
       arr[qq]='i';arr1[8]='.';qq++;
        cha[tolower(key[k])-97]=1;
     }
     else if(!cha[tolower(key[k])-97])
     {
       arr[qq]=tolower(key[k]);qq++;
       cha[tolower(key[k])-97]=1;
       if(tolower(key[k])>'i')
       arr1[tolower(key[k])-98]='.';
       else arr1[tolower(key[k])-97]='.';
     }
   }
   arr[qq]='\0';
   strcat(arr,arr1);
   for(i=0;i<5;i++)
   for(j=0;j<5;j++)
   {
     while(arr[l]=='.')l++;
     matrix[i][j] = arr[l];
     row[arr[l]-97]=i;
     col[arr[l]-97]=j;
     l++;


   }
   for(i=0;i<5;i++)
   {
     for(j=0;j<5;j++)
     printf("%c ",matrix[i][j]);
     printf("\n");

   }
   if(strlen(message)%2)
   {
     strcat(message,"x");
   }
   for(i=0;i<strlen(message);i+=2)
   {
      if(row[message[i]-97]==row[message[i+1]-97])
      {
        message[i]=matrix[row[message[i]-97]][(col[message[i]-97]-1)%5];
        message[i+1]=matrix[row[message[i+1]-97]][(col[message[i+1]-97]-1)%5];
      }
      else if(col[message[i]-97]==col[message[i+1]-97])
      {
        message[i]=matrix[(row[message[i]-97]-1)%5][col[message[i]-97]];
        message[i+1]=matrix[(row[message[i+1]-97]-1)%5][col[message[i+1]-97]];
      }
      else
      {
         char temp = message[i];
         message[i]=matrix[row[message[i]-97]][col[message[i+1]-97]];
         message[i+1]=matrix[row[message[i+1]-97]][col[temp-97]];


      }


   }
}
int main()
{
  char key[27],msg[100005],message[100005];
  int flag = 0;
  int choice = input(key,msg);
  if(choice==1)
  {
  encrypt(key,msg,message);
  printf("Ciphertext: \n");
  int i;
  for(i=0;i<strlen(message);i+=2)
  {
      printf("%c%c ",message[i],message[i+1]);

  }
  }
  else
  {
      decrypt(key,msg,message);
  printf("Plaintext ( spaces will have to be interpreted by user and i and j are interchangeable ): \n");
  int i;
  for(i=0;i<strlen(message);i+=2)
  {
      printf("%c%c ",message[i],message[i+1]);

  }




  }
  return 0;
}
