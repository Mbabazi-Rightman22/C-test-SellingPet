#include<stdio.h>
#include<string.h>
#include<windows.h>

struct owner{
    char ownerName[20];
    int ownerID;
};

struct detail
{
    int number;
    char name[20];
    char species[20];
    struct owner own;
}pet,mypet[100];

void add()
{
    FILE *st;
    st=fopen("petData.txt","a");
    {
        printf("\nENTER THE PET NUMBER: ");
        scanf("%d",&pet.number);
        printf("\nENTER THE PET NAME: ");
        scanf("%s",pet.name);
        printf("ENTER THE PET SPECIES: ");
        scanf("%s",pet.species);
        printf("ENTER THE PET OWNER NAME: ");
        scanf("%s",pet.own.ownerName);
        printf("ENTER THE PET OWNER ID: ");
        scanf("%d",&pet.own.ownerID);
        fprintf(st,"\n%s \t%d \t%s \t%s \t%d",pet.name,pet.number,pet.species,pet.own.ownerName,pet.own.ownerID);
        }
    fclose(st);
}

void display()
{
    FILE *st;
    sort();
    st=fopen("petData.txt","r");
    printf("\nPetname\tPetNumber\tPetSpecies\tOwnerName\tOwner ID");
    while(fscanf(st,"\n%s \t%d \t%s \t%s \t%d",pet.name,&pet.number,pet.species,pet.own.ownerName,&pet.own.ownerID)!=EOF)
    {
        printf("\n%s \t%d \t%s \t%s \t%d",pet.name,pet.number,pet.species,pet.own.ownerName,pet.own.ownerID);
    }
    fclose(st);
}

void sort()
{
    FILE *st,*p;
    struct detail temp;
    int i=0,j,k,l;
    st=fopen("petData.txt","r");
    while(fscanf(st,"\n%s \t%d \t%s \t%s \t%d",mypet[i].name,&mypet[i].number,mypet[i].species,mypet[i].own.ownerName,&mypet[i].own.ownerID)!=EOF)
    {
        i++;
    }
    for(j=0;j<i;j++)
    {
        for(k=j+1; k<i; k++)
        {
            if(strcmp(mypet[k].name,mypet[j].name)<0)
            {
                temp=mypet[j];
                mypet[j]=mypet[k];
                mypet[k]=temp;
            }
        }
    }
    p=fopen("sort.txt","a");
    for(l=0; l<i; l++)
    {
        fprintf(p,"\n%s \t%d \t%s \t%s \t%d",mypet[l].name,mypet[l].number,mypet[l].species,mypet[l].own.ownerName,mypet[l].own.ownerID);
    }
    fclose(st);
    fclose(p);
    remove("petData.txt");
    rename("sort.txt","petData.txt");
}

void sold()
{
    FILE *st,*k,*p;
    char name[20];
    st=fopen("petData.txt","r");
    k=fopen("sold.txt","a");
    p=fopen("temp.txt","w");
    printf("\nEnter Pet name you want to buy: ");
    scanf("%s",name);
     while(fscanf(st,"\n%s \t%d \t%s \t%s \t%d",pet.name,&pet.number,pet.species,pet.own.ownerName,&pet.own.ownerID)!=EOF)
    {
        if(strcmp(pet.name,name)!=0)
        {
            fprintf(p,"\n%s \t%d \t%s \t%s \t%d",pet.name,pet.number,pet.species,pet.own.ownerName,pet.own.ownerID);
        }
        else
        {
            fprintf(k,"\n%s \t%d \t%s \t%s \t%d",pet.name,pet.number,pet.species,pet.own.ownerName,pet.own.ownerID);
            printf("\nPet sold");
        }
    }
    fclose(p);
    fclose(k);
    fclose(st);
    remove("petData.txt");
    rename("temp.txt","petData.txt");
}

void soldpet()
{
    FILE *k;
    sort();
    k=fopen("sold.txt","r");
    printf("\nPetname\tPetNumber\tPetSpecies\tOwnerName\tOwner ID");
    while(fscanf(k,"\n%s \t%d \t%s \t%s \t%d",pet.name,&pet.number,pet.species,pet.own.ownerName,&pet.own.ownerID)!=EOF)
    {
        printf("\n%s \t%d \t%s \t%s \t%d",pet.name,pet.number,pet.species,pet.own.ownerName,pet.own.ownerID);
    }
    fclose(k);
}

void main()
{

    int choice;
    do{

    printf("\n\tPLEASE CHOOSE THE SERVICE YOU NEED");
    printf("\n1.TO ADD A PET");
    printf("\n2.TO DISPLAY LIST OF PETS");
    printf("\n3.TO SELL A PET");
    printf("\n4. TO DISPLAY SOLD PET");
    printf("\n0.To EXIT\n");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add();
            break;
            case 2:
                display();
            break;
            case 3:
                sold();
                break;
            case 4:
                soldpet();
                break;
            default:
                if(choice==0)
                    exit (0);
                else
                    printf("\nWRONG CHOICE");
        }
    }
    while(choice);
}