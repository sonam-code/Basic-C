/*Make changes to program created for 1. And add functionality of dynamic memory allocation to create structure array.
 Implement separate function performing addition operation on member of Structure. Two functions must be implemented one must work on pass by value and another must on pass by reference.*/
#include<stdio.h>
#include<stdlib.h>

#pragma pack(2)
typedef struct employee
{
    char *emp_name;
    int emp_ID;
    char emp_grade;
    float emp_Basic;
    float emp_HRA;
    float emp_bonus;
    float emp_PF;
}E_t;
//declaration of function for adding the members of structure....
int check_name(char *name);
float call_value_salary(float,float,float,float);
float call_reference_salary(E_t *);
int main()
{
    E_t * *temp;
    int i,j,k,count,a,n;
    float emp_GS=0;
    printf("enter the number of employee-\n");
    scanf("%d",&count);
    temp=malloc(sizeof(E_t *)*count);//allocation memory to array of pointer for array of structure
    fflush(stdin);//used to empty STDIN file....
    for(i=0;i<count;i++)
    temp[i]=malloc(sizeof(E_t));// allocation of memory for each element of array means each structure...
    for(i=0;i<count;i++)
    {
        int r,id_check;
        do
        {
            j=0;
            temp[i]->emp_name=NULL;
            printf("enter the detail of employee no%d .\nNAME\n",i+1);//size of name is decided at run time by user.....
            fflush(stdout);
//allocation memory to name means string.....
            do
            {
                temp[i]->emp_name=realloc(temp[i]->emp_name,j+1);
                temp[i]->emp_name[j]=getchar();
            }while(temp[i]->emp_name[j++]!='\n');
            temp[i]->emp_name[j]='\0';
            fflush(stdin);
            r=check_name(temp[i]->emp_name);
            if(r==0)
            {
            free(temp[i]->emp_name);
            }
        }while(r==0);
        do{
            printf("employee ID\n");
            id_check=scanf("%d",&temp[i]->emp_ID);
            fflush(stdin);
            if((temp[i]->emp_ID>>31&1)==1)//checking id is not be negative......
            {
                printf("id should not be negative\n");
            }
            else if(id_check!=1)//checking id to be integer value
            {
              printf("ID should be integer value try again..\n");
            }
            else
            {
                for(k=i;k>0;k--)  ///checking id not to be same.....
                {
                    a=0;
                    if(temp[i]->emp_ID==temp[k-1]->emp_ID)
                    {
                        printf("ID should not be same...\n");
                        a=1;
                        break;
                    }
                }
            }
        }while(id_check!=1||a==1||(temp[i]->emp_ID>>31&1)==1);
        do
        {
            printf("GRADE:\n");
            scanf(" %c",&temp[i]->emp_grade);
            fflush(stdin);
            if(!(temp[i]->emp_grade=='A'||temp[i]->emp_grade=='B'||temp[i]->emp_grade=='C'))
            {
                printf("grade should be A B C\n");
            }
        }while(!(temp[i]->emp_grade=='A'||temp[i]->emp_grade=='B'||temp[i]->emp_grade=='C'));
        printf("BASIC\n");
        scanf("%f",&temp[i]->emp_Basic);
        fflush(stdin);
        printf("HRA\n");
        scanf("%f",&temp[i]->emp_HRA);
        fflush(stdin);
        printf("BONUS\n");
        scanf("%f",&temp[i]->emp_bonus);
        fflush(stdin);
        printf("PF\n");
        scanf("%f",&temp[i]->emp_PF);
        fflush(stdin);
  }
  ///printing array elements...
    for(i=0;i<count;i++)
    {
        printf("%s %d %c %f %f %f %f \n",temp[i]->emp_name,temp[i]->emp_ID,temp[i]->emp_grade,temp[i]->emp_Basic,temp[i]->emp_HRA,temp[i]->emp_bonus,temp[i]->emp_PF);
    }
///call by value part..
   printf("\nCALL BY VALUE..\n");
   for(i=0;i<count;i++)
   {
        emp_GS=0;
        emp_GS=call_value_salary(temp[i]->emp_Basic,temp[i]->emp_HRA,temp[i]->emp_bonus,temp[i]->emp_PF);//passing values
        printf("Gross Salary of %s=Rs.%f\n",temp[i]->emp_name,emp_GS);
   }
///call by reference part...
   printf("\nCALL BY REFERENCE\n");
   for(i=0;i<count;i++)
   {
        emp_GS=0;
        emp_GS=call_reference_salary(temp[i]);//passing address
        printf("Gross Salary of %s=Rs.%f\n",temp[i]->emp_name,emp_GS);
   }
    printf("%f\n",temp[0]->emp_bonus);
    free(temp);//freeing the allocating memory
}
float call_value_salary(float B,float HRA,float b,float PF)//function :call by value
{
    float sum=0;
    //b=100;//value of bonus will not change
    sum=B+HRA+b+PF;
    return sum;
}
float call_reference_salary(E_t *temp)//function:call by reference
{
     float sum=0;
    temp->emp_bonus=100;//value of bonus will be change
    sum=temp->emp_Basic+temp->emp_HRA+temp->emp_bonus+temp->emp_PF;
    return sum;
}
///checking name valid or not....
int check_name(char *name)
{
    int k=0;
    while(name[k])
    {
        if(!(name[k]>='a'&&name[k]<='z'||name[k]>='A'&&name[k]<='Z'||name[k]==32))
            break;
        k++;
    }
    if(name[k]=='\n')//
        return 1;
    else
    {
        printf("only character are allowed in name...\n");
        return 0;
    }
}



