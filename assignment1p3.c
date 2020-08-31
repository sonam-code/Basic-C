/*Add Static variables in program created till now.
Modifications in program must demonstrate usage of static variable, scope and life of static variable. And add more members in structure like employee_id, employee_salary, employee_name.*/
#include<stdio.h>
#include<stdlib.h>
static int num=50;
// num and i,j,ptr are temporary variable.....
#pragma pack(1)
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
int check_name(char *name);
int main()
{
    E_t * *temp;
    int i,j,count=0;
    char *ptr;//which is not recommended it take further space in memory
    static int num;
    printf("enter the number of employee-\n");
    scanf("%d",&count);
    temp=malloc(sizeof(E_t *)*count);///allocating memory to array of structure....
    fflush(stdin);
    for(i=0;i<count;i++)///allocating memory to each structure means employee...
    {
        temp[i]=malloc(sizeof(E_t));
    }
    for(i=0;i<count;i++)///scanning data
    {
        static int num=100;// no reinitialization
        int r;
        do
        {
            j=0;
            ptr=NULL;
            temp[i]->emp_name=NULL;
            printf("num=%d\n",num);
            printf("enter the detail of employee:\nNAME of employee\n");
            do
            {
                ptr=realloc(ptr,j+1);
                ptr[j]=getchar();
            }while(ptr[j++]!='\n');
            ptr[j]='\0';
            temp[i]->emp_name=ptr;
            fflush(stdin);
            r=check_name(temp[i]->emp_name);
                if(r==0)
                {
                free(temp[i]->emp_name);
                }
        }while(r==0);
        temp[i]->emp_ID=num++;
        do
        {
            printf("GRADE of employee\n");
            scanf(" %c",&temp[i]->emp_grade);
            fflush(stdin);
            if(!(temp[i]->emp_grade=='A'||temp[i]->emp_grade=='B'||temp[i]->emp_grade=='C'))
            {
                printf("grade should be A B C\n");
            }
        }while(!(temp[i]->emp_grade=='A'||temp[i]->emp_grade=='B'||temp[i]->emp_grade=='C'));
        printf("BASIC salary of employee\n");
        scanf("%f",&temp[i]->emp_Basic);
        fflush(stdin);
        printf("HRA of employee\n");
        scanf("%f",&temp[i]->emp_HRA);
        fflush(stdin);
        printf("BONUS of employee\n");
        scanf("%f",&temp[i]->emp_bonus);
        fflush(stdin);
        printf("PF of employee\n");
        scanf("%f",&temp[i]->emp_PF);
        fflush(stdin);
    }
    printf("NAME ID GRADE BASIC HRA BONUS PF:\n ");
    for(i=0;i<count;i++)
    {
       //static int num=100;
        printf("%s %d %c %f %f %f %f \n",temp[i]->emp_name,temp[i]->emp_ID,temp[i]->emp_grade,temp[i]->emp_Basic,temp[i]->emp_HRA,temp[i]->emp_bonus,temp[i]->emp_PF);
    }
    free(temp);
    printf("the value of num =%d\n",num);//num=0;because the scope of num used in loop is within that loop only
}
///checking name is valid or not......
int check_name(char *name)
{
int i=0;
while(name[i])
{
    if(!(name[i]>='a'&&name[i]<='z'||name[i]>='A'&&name[i]<='Z'||name[i]==32))
        break;
    i++;
}
if((name[i]=='\n'))
{
 return 1;
}
else
{
    printf("only character are allowed in name...\n");
    return 0;
}
}


