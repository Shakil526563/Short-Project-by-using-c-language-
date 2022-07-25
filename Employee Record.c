
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct node
{
    char Employee_Name[40];
    char Employee_Age[50];
    char Employee_Id[30];
    char Employee_Salary[50];
    char Employee_Performance[50];
    char Employee_contract_number[50];

    struct node *next;
};
struct node *head;
void Add_Record()
{
    getchar();
    printf("-------- Add Record --------\n");
    printf("\n--------------------------------------------------\n\n");
    struct node *temp=(struct node*) malloc (sizeof(struct node));
    printf("Employee_Name :- ");
    gets(temp->Employee_Name);
    printf("Employee_Age :- ");
    gets(temp->Employee_Age);
    printf("Employee_Id :- ");
    gets(temp->Employee_Id);
    printf("Employee_Performance out of 10 :- ");
    gets(temp->Employee_Performance);
    printf("Employee_Salary :- ");
    gets(temp->Employee_Salary);
    printf("Employee_contract_number :- ");
    gets(temp->Employee_contract_number);


    temp->next=head;
    head=temp;

    return 0;



}
void List_Records()
{
    struct node *temp=head;
    printf("\n-------- List Records --------\n");

    while(temp!=NULL)
    {
        printf("Employee_Name :- %s\n",temp->Employee_Name);
        printf("Employee_Age :- %s\n",temp->Employee_Age);
        printf("Employee_Id :- %s\n",temp->Employee_Id);
        printf("Employee_Performance out of 10 :- %s\n",temp->Employee_Performance);
        printf("Employee_Salary :- %s\n",temp->Employee_Salary);
        printf("Employee_contract_number :- %s\n",temp->Employee_contract_number);
        printf("\n\n");

        temp = temp->next;


    }
    return;
}
void Employee_search()
{
    char Search_Id[77];
    int found=0;
    struct node *temp=head;
    getchar();
    printf("\n-------- Employee_search --------\n");

    printf("Search_Id ");
    gets(Search_Id);
    while(temp!=NULL)
    {
        if(strcmp(temp->Employee_Id,Search_Id)==0)
        {
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==1)
    {
        printf(" Employee Information \n\n\n");
        printf("Employee_Name :- %s\n",temp->Employee_Name);
        printf("Employee_Age :- %s\n",temp->Employee_Age);
        printf("Employee_Id :- %s\n",temp->Employee_Id);
        printf("Employee_Performance out of 10 :- %s\n",temp->Employee_Performance);
        printf("Employee_Salary :- %s\n",temp->Employee_Salary);
        printf("Employee_contract_number :- %s\n",temp->Employee_contract_number);

    }
    else
        printf("No data  with id %s! \n",Search_Id);
    return ;
}
void Modify_Records()
{
    char Search_Id[77];
    int found=0;
    struct node *temp=head;
    getchar();
    printf("\n-------- Modify_Records --------\n");

    printf("Search_Id ");
    gets(Search_Id);
    while(temp!=NULL)
    {
        if(strcmp(temp->Employee_Id,Search_Id)==0)
        {
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==1)
    {
        printf("Old Information \n");
        printf("Employee_Name :- %s\n",temp->Employee_Name);
        printf("Employee_Age :- %s\n",temp->Employee_Age);
        printf("Employee_Performance out of 10 :- %s\n",temp->Employee_Performance);
        printf("Employee_Salary :- %s\n",temp->Employee_Salary);
        printf("Employee_contract_number :- %s\n",temp->Employee_contract_number);

        printf("_________________\n");
        printf("New Information\n");

        printf("Employee_Name :- ");
        gets(temp->Employee_Name);
        printf("Employee_Age :- ");
        gets(temp->Employee_Age);
        printf("Employee_Performance out of 10 :- ");
        gets(temp->Employee_Performance);
        printf("Employee_Salary :- ");
        gets(temp->Employee_Salary);
        printf(" Employe_contract_number :- ");
        gets(temp->Employee_contract_number);

        printf("Data Update \n");
    }
    else
        printf("No data found with id %s! \n",Search_Id);
    return ;
}

void Delate_Records()
{

    char Search_Id [77];
    int found=0;
    struct node *temp=head,*pretemp;
    getchar();
    printf("\n-------- Delete_Records  --------\n");


    printf("Search_Id ");
    gets(Search_Id);
    if(strcmp(temp->Employee_Id,Search_Id)==0)
    {

        head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->Employee_Id,Search_Id)==0)
        {
            found=1;
            break;
        }
        pretemp=temp;
        temp=temp->next;
    }
    if(found==1)
    {
        pretemp->next = temp->next;
        free(temp);

        printf("Information Update \n");
    }


}
int main()
{
    int n;
    head=NULL;
    while(1)
    {

        printf("\n------------------- Main Menu --------------------\n");
        printf("\n--------------------------------------------------\n");
        printf("\n--------  1. Add to Employee Record        -------\n");
        printf("\n--------  2. List of Employee Records      -------\n");
        printf("\n--------  3. Modify  of Employee Records   -------\n");
        printf("\n--------  4. Delate to Records             -------\n");
        printf("\n--------  5. Employee_search               -------\n");
        printf("\n--------  6. Exit                          -------\n");
        printf("\n--------------------------------------------------\n");


        printf("Reply: ");
        scanf("%d",&n);
        printf("\n--------------------------------------------------\n");
        switch(n)
        {
        case 1:
            Add_Record();
            break;
        case 2:
            List_Records();

            break;

        case 3:
            Modify_Records();

            break;

        case 4:
            Delate_Records();


            break ;

        case 5:
            Employee_search();

            break ;

        case 6:

            return 0;
            break ;

        default:
            printf("Invalid input");
            break;
        }
    }

    return 0;
}
