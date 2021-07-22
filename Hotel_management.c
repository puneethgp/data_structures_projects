

#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Order
{
    int food_item_number;
    char *food_name;
    int price;
    struct Order* next;
};
struct Order* head ;
char items[8][3][25]= {{"1"," BURGER","45"},{"2", "SAMOSA","10"},{"3", "PIZZA","60"},{"4","VADA PAV","10"},{"5", "COLD COFFEE","45"},{"6", "MILKSHAKE","45"},{"7","TEA","10"}};


int ATOI(char* num)
{
    int result=0;
    for(int i=0; num[i]!='\0'; ++i)
        result = result*10 + num[i]-'0';
    return result;
}


struct Order* Get_Order(int item_number)
{
    struct Order* temp = (struct Order*)malloc(sizeof(struct Order));
    temp->food_name = malloc(strlen(items[item_number-1])+1);
    strcpy(temp->food_name,items[item_number-1][1]);
    temp->food_item_number = item_number;
    temp->price = ATOI(items[item_number-1][2]);
    temp->next = NULL;
    return temp;
};

void Push(int item_number)
{
    struct Order* temp = Get_Order(item_number);
    if (head == NULL)
        head = temp;
    else
    {
        struct Order* q=head;
        while (q->next!=NULL)
            q=q->next;
        q->next= temp;
    }
}

void Pop(int item)
{
    if (item>7) return;
    struct Order* temp1 = head;
    if(head == NULL)
    {
        printf("You have no orders to delete\n ");
        return ;
    }
    while(temp1->next->food_item_number!=item)
    {
        temp1= temp1->next;
    }
    struct Order* temp2 =temp1->next;
    printf("\nremoved %s from your order\n",temp1->next->food_name);
    temp1->next = temp1->next->next;
    free(temp2);
}

void Display_order()
{
    struct Order* temp = head ;
    if(head == NULL)
    {
        printf("You have no orders to show\n ");
        return ;
    }
    printf("\n--YOUR ORDER SO FAR--\n");
    printf("NUM  NAME			PRICE\n");
    while (temp!=NULL)
    {
        printf("%d   %s			%d\n",temp->food_item_number,temp->food_name,temp->price);
        temp= temp->next;
    }
}

int Bill()
{
    if(head == NULL)
    {
        printf("You have not ordered any items\n ");
        return 0;
    }
    struct Order* temp = head;
    int sum=0;
    while(temp!=NULL)
    {
        sum += temp->price;
        temp = temp->next;
    }
    return sum;
}

void Menu()
{
    printf("\n.......Select The Food From list.......\n\n");
    printf("1 BURGER			|Rs 45|\n");
    printf("2 SAMOSA			|Rs 10|\n");
    printf("3 PIZZA				|Rs 60|\n");
    printf("4 VADA PAV			|Rs 10|\n");
    printf("5 COLD COFFEE			|Rs 45|\n");
    printf("6 MILKSHAKE			|Rs 45|\n");
    printf("7 TEA				|Rs 10|\n");
}

void Main_menu( )
{
    printf("\n----Options avaliable----\n");
    printf("\nOrder food		   	press 1\n");
    printf("Delete orderd food	   	press 2\n");
    printf("Display order		   	press 3\n");
    printf("Count total bill	   	press 4\n");
    printf("Exit			   	press 5\n");
}


int main()
{
    head = NULL;
    int choice,item;
    bool add = true;
    printf("\n				...WELCOME TO FOOD ORDER SYSTEM ...\n\n");

    do
    {
        Main_menu();
        printf("\nEnter your choice:");

        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            while(1){
            Menu();
            printf("Order an item from the Menu : ");
            scanf("%d",&item);
            if (item==0) break;
            Push(item);
            printf("to exit press 0\n");
            }
            break;

        case 2:
            Menu();
            printf("Enter  item_number to remove from the order\n");
            scanf("%d",&item);
            Pop(item);
            break;

        case 3:
            Display_order();
            break;

        case 4:
            printf("%dRs is your total bill\n",Bill());
            break;

        case 5:
            printf("pay the bill of %d before leaving",Bill());
            printf("\nTHANK YOU FOR VISITING\n");
            getch();
            exit(0);
            break;
        }
    }
    while(1);
    printf("\nHappy eating\n");
}

