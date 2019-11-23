    #include <stdio.h>
    #include <conio.h>
    #include <string.h>
    void table()
    {
    printf("\n|-------------------------------------|");
    printf("\n|variables|Minterms|Term|Maxterms|Term|");
    printf("\n|---------|--------|----|--------|----|");
    printf("\n| 0| 0 | 0|x'.y'.z'| m0 |x+y+z   | M0 |");
    printf("\n| 0| 0 | 1|x'.y'.z | m1 |x+y+z'  | M1 |");
    printf("\n| 0| 1 | 0|x'.y.z' | m2 |x+y'+z  | M2 |");
    printf("\n| 0| 1 | 1|x'.y.z  | m3 |x+y'+z' | M3 |");
    printf("\n| 1| 0 | 0|x.y'.z' | m4 |x'+y+z  | M4 |");
    printf("\n| 1| 0 | 1|x.y'.z  | m5 |x'+y+z' | M5 |");
    printf("\n| 1| 1 | 0|x.y.z'  | m6 |x'+y'+z | M6 |");
    printf("\n| 1| 1 | 1|x.y.z   | m7 |x'+y'+z'| M7 |");
    printf("\n|-------------------------------------|");
    }
    void solutionpos(int,int[],int,char[],int);
    void solutionsop(int,int[],int,char[],int);
    void main()
    {
    int i,j,k,n,t,nm,ng,nmgi,ochoice,minterms[16],minterms2[4],kmap[4][4]={0,1,3,2,4,5,7,6,12,13,15,14,8,9,11,10};
    char k2map[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char k3map[4][4]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    char v[6];
    printf("\t\t\tK-MAP");
    printf("\n\t\t\t-----");
    printf("\nEnter no of variables(3or4):");
    scanf("%d",&n);
    printf("\nEnter the variables: ");
    for(i=0;i<n;i++)
    {
        printf("\nEnter variable %d:",i+1);
        scanf("%s",&v[i]);
    }
    v[i]='\0';
    printf("\n1.SOP");
    printf("\n2.POS");
    printf("\nEnter the required output form(1or2):-");
    scanf("%d",&ochoice);
    switch(ochoice){
    case 2:{system("cls");
            table();
            printf("\nEnter the number of minterms : ");
            scanf("%d",&nm);
            printf("\nEnter the corresponding minterms number from the table above : ");
            for(i=0;i<nm;i++)
            {
                printf("\nEnter Minterm %d:",i+1);
                scanf("%d",&minterms[i]);

            }
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                 {
                    for(k=0;k<nm;k++){
                        if(kmap[i][j]==minterms[k]){
                            k2map[i][j]=1;
                         }
                         }
                  }
            }
            system("cls");
            printf("\n\t-----------------        -----------------");
            for(i=0;i<4;i++)
            {
                printf("\n\t");
                    for(j=0;j<4;j++){
                        printf("| %d ",k2map[i][j]);

                        }
                        printf("|");
                        printf("        ");
                        for(t=0;t<4;t++){
                        printf("|m%2d",kmap[i][t]);
                        }
                            printf("|");
                                printf("\n\t-----------------        -----------------");
             }

             printf("\nEnter the no of groups:");
             scanf("%d",&ng);
             for(i=0;i<ng;i++){
                printf("\nEnter group %d:",i+1);
                printf("\nEnter no of minterms in group %d:",i+1);
                scanf("%d",&nmgi);
                for(j=0;j<nmgi;j++){
                    printf("\nEnter minterm %d:",j+1);
                    scanf("%d",&minterms2[j]);
                }
                solutionpos(ochoice,minterms2,nmgi,v,ng);
             }
             break;
             }
    case 1 :{system("cls");
              table();
              printf("\nEnter the number of maxterms : ");
              scanf("%d",&nm);
              printf("\nEnter the corresponding maxterms number from the table above : ");
              for(i=0;i<nm;i++)
              {
                  printf("\nEnter Maxterm %d:",i+1);
                  scanf("%d",&minterms[i]);
              }
              for(i=0;i<4;i++)
              {
                  for(j=0;j<4;j++)
                  {
                      for(k=0;k<nm;k++){
                        if(kmap[i][j]==minterms[k]){
                            k3map[i][j]=0;
                        }
                      }
                  }
              }
              system("cls");
       printf("\n\t-----------------        -----------------");
            for(i=0;i<4;i++)
            {
                printf("\n\t");
                    for(j=0;j<4;j++){
                        printf("| %d ",k3map[i][j]);

                        }
                        printf("|");
                        printf("        ");
                        for(t=0;t<4;t++){
                        printf("|M%2d",kmap[i][t]);
                        }
                            printf("|");
                                printf("\n\t-----------------        -----------------");
             }
              printf("\nEnter the no of groups:");
              scanf("%d",&ng);
              for(i=0;i<ng;i++){
                 printf("\nEnter group %d:",i+1);
                 printf("\nEnter no of maxterms in group %d:",i+1);
                 scanf("%d",&nmgi);
                 for(j=0;j<nmgi;j++){
                    printf("\nEnter maxterms %d:",j+1);
                    scanf("%d",&minterms2[j]);
                 }
                 solutionsop(ochoice,minterms2,nmgi,v,ng);
              }
              break;
              }
     default:{printf("\nInvalid choice..");
              break;
              }
              }
             _getch();
              }
     void solutionpos(int ochoice,int minterms2[],int nm,char v[],int ng)
     {
     int i,r,f,l,e,q,p,temp,len,o=0,z=0,j,c=0,k,checkarray[8][4],binterms[16][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     static char answers[16][16]={0};
     static int t=0;
     for(i=0;i<nm;i++){
        for(j=0;j<4;j++){
            binterms[i][j]=minterms2[c]%2;
            minterms2[c]=minterms2[c]/2;
        }
        c++;
     }
     for(i=0;i<nm;i++){
     k=3;
        for(j=0;j<=1;j++){
            temp=binterms[i][j];
            binterms[i][j]=binterms[i][j+k];
            binterms[i][j+k]=temp;
            k=k-2;
        }
     }
     for(i=0,r=0;i<nm;i++,r++){
        for(j=0;j<4;j++){
            checkarray[r][j]=binterms[i][j];
        }
     }
     for(j=0,p=0;j<4;j++){
        for(i=0;i<nm;i++){
            if(checkarray[i][j]==1){
                o++;
            }
            if(checkarray[i][j]==0){
                 z++;
            }
     }
        if(o==nm){
            answers[t][p]=v[j];
            answers[t][p+1]='\'';
            p=p+2;
        }
        else if(z==nm){
            answers[t][p]=v[j];
            p++;
        }
        else{
            answers[t][p]='o';
            p++;
        }
        o=0;
        z=0;
     }
     t++;
     if(t==ng){
      printf("\nThe solution to the boolean function is :");
        for(i=0;i<ng;i++){
          if(i>0){
            printf(".");
          }
          f=0;
          e=0;
            len=strlen(answers[i]);
        for(j=0;j<len;j++){
            if(j>0){
                for(k=j-1;k>=0;k--){
                    if(answers[i][k]!='o'){
                        f=1;
                        break;
                    }
                    }
                }
             l=j+1;
                if(l!=len){
                    for(q=j+1;q<len;q++){
                        if(answers[i][q]!='o'){
                            e=1;
                            break;
                        }
                    }
                }
            if(answers[i][j]=='o'){
                continue;
            }
           else if(answers[i][j+1]=='\''){
               if(j==0||f==0){
                printf("(%c",answers[i][j]);
               }
              else if(j+1==len||e==0){
                printf("%c)",answers[i][j]);
              }
              else{
                printf("%c",answers[i][j]);
              }
            }
            else{
               if(j==0||f==0){
                printf("(%c+",answers[i][j]);
               }
              else if(j+1==len||e==0){
                printf("%c)",answers[i][j]);
              }
              else{
                printf("%c+",answers[i][j]);
              }
            }
            e=0;
            f=0;
            }
            }
        }
     }
     void solutionsop(int ochoice,int minterms2[],int nm,char v[],int ng)
    {
     int i,r,f,l,e,q,p,temp,len,o=0,z=0,j,c=0,k,checkarray[8][4],binterms[16][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     static char answers[16][16]={0};
     static int t=0;
     for(i=0;i<nm;i++){
        for(j=0;j<4;j++){
            binterms[i][j]=minterms2[c]%2;
            minterms2[c]=minterms2[c]/2;
        }
        c++;
     }
     for(i=0;i<nm;i++){
     k=3;
        for(j=0;j<=1;j++){
            temp=binterms[i][j];
            binterms[i][j]=binterms[i][j+k];
            binterms[i][j+k]=temp;
            k=k-2;
        }
     }
     for(i=0,r=0;i<nm;i++,r++){
        for(j=0;j<4;j++){
            checkarray[r][j]=binterms[i][j];
        }
     }
     for(j=0,p=0;j<4;j++){
        for(i=0;i<nm;i++){
            if(checkarray[i][j]==1){
                o++;
            }
            if(checkarray[i][j]==0){
                 z++;
            }
        }
        if(z==nm){
            answers[t][p]=v[j];
            answers[t][p+1]='\'';
            p=p+2;
        }
        else if(o==nm){
            answers[t][p]=v[j];
            p++;
        }
        else{
            answers[t][p]='o';
            p++;
        }
        o=0;
        z=0;
     }
     t++;
     if(t==ng){
      printf("\nThe solution to the boolean function is :");
        for(i=0;i<ng;i++){
          if(i>0){
            printf("+");
          }
          f=0;
          e=0;
            len=strlen(answers[i]);
        for(j=0;j<len;j++){
            if(j>0){
                for(k=j-1;k>=0;k--){
                    if(answers[i][k]!='o'){
                        f=1;
                        break;
                    }
                    }
                }
             l=j+1;
                if(l!=len){
                    for(q=j+1;q<len;q++){
                        if(answers[i][q]!='o'){
                            e=1;
                            break;
                        }
                    }
                }
            if(answers[i][j]=='o'){
                continue;
            }
           else if(answers[i][j+1]=='\''){

               if(j==0||f==0){
                printf("(%c",answers[i][j]);
               }
              else if(j+1==len||e==0){
                printf("%c)",answers[i][j]);
              }
              else{
                printf("%c",answers[i][j]);
              }
            }
            else{
               if(j==0||f==0){
                printf("(%c.",answers[i][j]);
               }
              else if(j+1==len||e==0){
                printf("%c)",answers[i][j]);
              }
              else{
                printf("%c.",answers[i][j]);
              }
            }
            e=0;
            f=0;
            }
            }
        }
        }












