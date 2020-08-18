/*Develop a program demonstrating various concepts of structure in C. Program must demonstrate:
Structure Padding and structure alignment
Array of Structure
Structure variables with and without typedef*/
#include<stdio.h>
int check_name(char *name);
typedef struct employee
{
    char emp_name[13];
    int emp_ID;
    char emp_grade;
}E_t;
struct employee1
{
    char emp_name[13];
    char emp_grade;
    int emp_ID;
};
#pragma pack(1)//structure alignment using pack of 1
struct employee2
{
    char emp_name[13];
    int emp_ID;
    char emp_grade;
}E2_t;
int main()
{
    E_t array[3];// array of structure (structure variable using typedef)
    struct employee1 reeta;//structure variable without typedef
    unsigned char count,n;
    int i,a;
    printf("size of employee by structure padding:%d\n",sizeof(E_t));//structure padding
    printf("size of employee1 keeping same data type together:%d\n",sizeof(reeta));//avoid of structure padding by keeping similar data type together
    printf("size of employee2 using pragma directive=%d\n",sizeof(E2_t));//using #pragma directive
    for(count=0,n=0;count<3;count++)
    {
        int name_check,id_check;
        do
        {
            printf("enter %d No.employee detail:\nNAME\n",count+1);
            fflush(stdout);
            scanf("%s",array[count].emp_name);
            fflush(stdin);
            name_check=check_name(array[count].emp_name);
        }while(name_check==0);
        do
        {
            printf("employee ID\n");
            id_check=scanf("%d",&array[count].emp_ID);
             n=count;
            fflush(stdin);
            if((array[count].emp_ID>>31&1)==1)//checking id is not be negative......
            {
                printf("id should not be negative\n");
            }
            else if(id_check!=1)//checking id to be integer value
            {
              printf("ID should be integer value try again..\n");
            }
            else
            {
                for(i=n;i>0;i--)  ///checking id not to be same.....
                {
                    a=0;
                    if(array[n].emp_ID==array[i-1].emp_ID)
                    {
                        printf("ID should not be same...\n");
                        a=1;
                        break;
                    }
                }
            }
        }while(id_check!=1||a==1||(array[count].emp_ID>>31&1)==1);
        do
        {
            printf("employee grade..\n");
            fflush(stdout);
            scanf(" %c",&array[count].emp_grade);
            fflush(stdin);
            if(!(array[count].emp_grade=='A'||array[count].emp_grade=='B'||array[count].emp_grade=='C'))///checking grade valid or not......
            {
                printf("grade only A Or B or C\n");
            }
        }while(!(array[count].emp_grade=='A'||array[count].emp_grade=='B'||array[count].emp_grade=='C'));
    }
    for(count=0;count<3;count++)
    {
      printf("%s: %d %c\n",array[count].emp_name,array[count].emp_ID,array[count].emp_grade);///printing array data
    }

}
///checking name is valid or not.....
int check_name(char *name)
{
int i=0;
while(name[i])
{
    if(!((name[i]>='a'&&name[i]<='z')||(name[i]>='A'&&name[i]<='Z')||name[i]==32))
    break;
    i++;
}
if(name[i]=='\0')
    return 1;
else
{
    printf("only character are allowed in name...\n");
    return 0;
}
}
