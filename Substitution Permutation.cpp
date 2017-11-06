#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map< string, string > substitutionBox;
map< int, int > permutationBox;
map < string, string > inverseSubstitutionBox;
map< int, int > inversePermutationBox;
void print(string text[],int m)
{
    for(int i =0;i<m;i++)
        cout<<text[i]<<' ';
    cout<<endl;
}
void print(string text[],int i,int j)
{
    for(int k=i;k<=j;k++)
       cout<<text[k]<<' ';
       cout<<endl;
}
int main()
{
   int m,l,r;
   cout<<"Enter m, l and r in order: ";
   scanf("%d %d %d",&m,&l,&r);
   string text[m+1];
   int choice;
   do{
   cout<<"Enter choice (1:Encrypt/2:Decrypt):";
   cin>>choice;
   }
   while(choice!=1&&choice!=2);
   if(choice==1)
   {

   cout<<"Enter the plaintext ( separate groupings of "<<l<<" bits each separated by spaces) :";
   int i;
   for(i=0;i<m;i++)
    cin>>text[i];
   cout<<"Enter the complete key ( separate groupings of "<<l<<" bits each separated by spaces) :";
   string key[m+r+5];
   for(i=0;i<m+r;i++)
    cin>>key[i];
   cout<<"Enter the substitution box ( each l bit group along with its corresponding substitution ):";
   for(i=1;i<=pow(2,l);i++)
   {
       string temp1,temp2;
       cin>>temp1>>temp2;
       substitutionBox[temp1] = temp2;
       inverseSubstitutionBox[temp2] = temp1;
   }
   cout<<"Enter the permutation box used ( each position along with its corresponding position in permuted arrangement ):";
   for(i=1;i<=l*m;i++)
   {
       int x,y;
       cin>>x>>y;
       permutationBox[x]=y;
       inversePermutationBox[y]=x;
   }
   int j,k,jj,kk;
   cout<<"Plaintext:";
   print(text,m);

   for(i=1;i<=r-1;i++)//initial r-1 rounds
   {
        cout<<"Key:";
        print(key,i-1,i-2+m);
       //Xoring part
       for(j=0,k=j+i-1;j<m;j++,k++)
        {
           for(jj=0;jj<l;jj++)
           {

               text[j][jj]= ((text[j][jj]-'0')^(key[k][jj]-'0'))?'1':'0';
           }

       }
       cout<<"u:";
       print(text,m);
       //Substitution part
       for(j=0;j<m;j++)
       {
           text[j] = substitutionBox[text[j]];


       }
       //Permutation part
       cout<<"v:";
       print(text,m);
       char temp[l*m+5];
       for(j=1;j<=l*m;j++)
       {
           temp[j] = text[(j-1)/l][(j-1)%l];
       }
       for(j=1;j<=l*m;j++)
       {
           int row = (permutationBox[j]-1)/l;
           int col = (permutationBox[j]-1)%l;
           text[row][col] = temp[j];
       }
       cout<<"w:";
       print(text,m);
   }
    cout<<"Key:";
        print(key,r-1,r-2+m);
       //Xoring part
       for(j=0,k=j+r-1;j<m;j++,k++)
        {
           for(jj=0;jj<l;jj++)
           {

               text[j][jj]= ((text[j][jj]-'0')^(key[k][jj]-'0'))?'1':'0';
           }

       }
       cout<<"u:";
       print(text,m);
       //Substitution part
       for(j=0;j<m;j++)
       {
           text[j] = substitutionBox[text[j]];


       }
       //Permutation part
       cout<<"v:";
       print(text,m);
       cout<<"k:";
       print(key,r,r+m-1);
       //Xoring part
       for(j=0,k=j+r;j<m;j++,k++)
        {
           for(jj=0;jj<l;jj++)
           {

               text[j][jj]= ((text[j][jj]-'0')^(key[k][jj]-'0'))?'1':'0';
           }

       }
       cout<<"Ciphertext:";
       print(text,m);
   }
   else
   {
    cout<<"Enter the ciphertext ( separate groupings of "<<l<<" bits each separated by spaces) :";
   int i;
   for(i=0;i<m;i++)
    cin>>text[i];
   cout<<"Enter the complete key ( separate groupings of "<<l<<" bits each separated by spaces) :";
   string key[m+r+5];
   for(i=0;i<m+r;i++)
    cin>>key[i];
   cout<<"Enter the substitution box used for encryption ( each l bit group along with its corresponding substitution ):";
   for(i=1;i<=pow(2,l);i++)
   {
       string temp1,temp2;
       cin>>temp1>>temp2;
       substitutionBox[temp2] = temp1;
   }
   cout<<"Enter the permutation box used for decryption ( each position along with its corresponding position in permuted arrangement ):";
   for(i=1;i<=l*m;i++)
   {
       int x,y;
       cin>>x>>y;
       permutationBox[y]=x;
   }
   int j,k,jj,kk;
   cout<<"Ciphertext:";
       print(text,m);

   cout<<"k:";
       print(key,r,r+m-1);
       //Xoring part
       for(j=0,k=j+r;j<m;j++,k++)
        {
           for(jj=0;jj<l;jj++)
           {

               text[j][jj]= ((text[j][jj]-'0')^(key[k][jj]-'0'))?'1':'0';
           }

       }

    cout<<"v:";
       print(text,m);
    for(j=0;j<m;j++)
       {
           text[j] = substitutionBox[text[j]];


       }

   cout<<"u:";
       print(text,m);

     cout<<"Key:";
        print(key,r-1,r-2+m);
       //Xoring part
       for(j=0,k=j+r-1;j<m;j++,k++)
        {
           for(jj=0;jj<l;jj++)
           {

               text[j][jj]= ((text[j][jj]-'0')^(key[k][jj]-'0'))?'1':'0';
           }

       }
     for(i=r-1;i>=1;i--)//initial r-1 rounds
   {
         cout<<"w:";
       print(text,m);

       char temp[l*m+5];
       for(j=1;j<=l*m;j++)
       {
           temp[j] = text[(j-1)/l][(j-1)%l];
       }
       for(j=1;j<=l*m;j++)
       {
           int row = (permutationBox[j]-1)/l;
           int col = (permutationBox[j]-1)%l;
           text[row][col] = temp[j];
       }

         cout<<"v:";
       print(text,m);

        for(j=0;j<m;j++)
       {
           text[j] = substitutionBox[text[j]];


       }

        cout<<"u:";
       print(text,m);


        cout<<"Key:";
        print(key,i-1,i-2+m);
       //Xoring part
       for(j=0,k=j+i-1;j<m;j++,k++)
        {
           for(jj=0;jj<l;jj++)
           {

               text[j][jj]= ((text[j][jj]-'0')^(key[k][jj]-'0'))?'1':'0';
           }

       }

       //Substitution part

       //Permutation part



   }


   cout<<"Plaintext:";
   print(text,m);




       //Substitution part

       //Permutation part








   }
}
