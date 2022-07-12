//a code for creating a phone book
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct phonebook
{
    char name[100];
    char phonenum[5][20];
    char address[100];
    char emailaddress[5][50];
    char group[5][100];
    struct phonebook *next;
};
void printphonebook(struct phonebook *head);
void namesearch(struct phonebook *head,char name[100]);
int addresssearch(struct phonebook *head,char address[100]);
int phonenumbersearch(struct phonebook *head,char phonenum[100]);
int emailaddresssearch(struct phonebook *head,char emailaddress[100]);
int groupsearch(struct phonebook *head,char group[100]);
void print(struct phonebook *current);
struct phonebook *deletename(struct phonebook *head,char name[100]);
struct phonebook *deletephonenum(struct phonebook *head,char phonenum[100]);
struct phonebook *deleteaddress(struct phonebook *head,char address[100]);
struct phonebook *deleteemailaddress(struct phonebook *head,char emailaddress[100]);
struct phonebook *deletegroup(struct phonebook *head,char group[100]);
int menu();
int menu1(int d);
void red();
void green();
void yesnochoice(int ch);
void savephonebook(struct phonebook *head);
struct phonebook *loader(struct phonebook *head);
struct phonebook *addelement(struct phonebook *head);
struct phonebook *reverse(struct phonebook *head);
int main()
{
    struct phonebook *head=NULL;
    int i,j;
    char ch,choice=1,query[100],choice1,a,choice2=0;
    head=loader(head);
    if(head)
    {
        head=reverse(head);
    }
    while(choice<7&&choice>0)
    {
        system("cls");
        system("COLOR 0A");
        choice=menu();
        switch(choice)
        {
        case 5:
            system("cls");
            savephonebook(head);
            getch();
            return 0;
            break;
        case 4://delete  function
            choice1=1;
            while(choice1<6)
            {
                system("cls");
                choice1=menu1(1);
                switch(choice1)
                {
                case 1:// via name
                    system("cls");
                    printf("\t\t\t\tEnter name:\n\t\t\t\t");
                    gets(query);
                    head=deletename(head,query);
                    getch();
                    break;
                case 2:// via phone number
                    system("cls");
                    printf("\t\t\t\tEnter phone number:\n\t\t\t\t");
                    gets(query);
                    head=deletephonenum(head,query);
                    getch();
                    break;
                case 3://via address
                    system("cls");
                    printf("\t\t\t\tEnter address:\n\t\t\t\t");
                    gets(query);
                    head=deleteaddress(head,query);
                    getch();
                    break;
                case 4://via email address
                    system("cls");
                    printf("\t\t\t\tEnter email address:\n\t\t\t\t");
                    gets(query);
                    head=deleteemailaddress(head,query);
                    getch();
                    break;
                case 5://via group
                    system("cls");
                    printf("\t\t\t\tEnter group:\n\t\t\t\t");
                    gets(query);
                    head=deletegroup(head,query);
                    getch();
                    break;
                }
            }
            break;
        case 3://search
            system("cls");
            choice1=1;
            while(choice1<6)
            {
                system("CLS");
                choice1=menu1(0);
                switch(choice1)
                {
                case 1://via name
                    system("cls");
                    printf("\t\t\t\tEnter name:\n\t\t\t\t");
                    gets(query);
                    namesearch(head,query);
                    getch();
                    system("cls");
                    choice2=menu2();
                    if(choice2==1)
                    {
                        choice1=1;
                        break;
                    }
                    else
                        exit (0);

                    break;
                case 2://via phone number
                    system("cls");
                    printf("\t\t\t\tEnter phone number:\n\t\t\t\t");
                    gets(query);
                    phonenumbersearch(head,query);
                    getch();
                    system("cls");
                    choice2=menu2();
                    if(choice2==1)
                    {
                        choice1=1;
                        break;
                    }
                    else
                        exit (0);
                    break;
                case 3://via address
                    system("cls");
                    printf("\t\t\t\tEnter address:\n\t\t\t\t");
                    gets(query);
                    addresssearch(head,query);
                    getch();
                    system("cls");
                    choice2=menu2();
                    if(choice2==1)
                    {
                        choice1=1;
                        break;
                    }
                    else
                        exit (0);
                    break;
                case 4://via email address
                    system("cls");
                    printf("\t\t\t\tEnter email address:\n\t\t\t\t");
                    gets(query);
                    emailaddresssearch(head,query);
                    getch();
                    system("cls");
                    choice2=menu2();
                    if(choice2==1)
                    {
                        choice1=1;
                        break;
                    }
                    else
                        exit (0);
                    break;
                case 5://via group
                    system("cls");
                    printf("\t\t\t\tEnter group:\n\t\t\t\t");
                    gets(query);
                    groupsearch(head,query);
                    getch();
                    system("cls");
                    choice2=menu2();
                    if(choice2==1)
                    {
                        choice1=1;
                        break;
                    }
                    else
                        exit (0);
                    break;
                }
            }
            break;
        case 2://print
            system("cls");
            printphonebook(head);
            getch();
            break;
        case 1://adding phone number
            system("cls");
            head=addelement(head);
            system("cls");
        }
    }
    return 0;
}
int menu()//menu design
{
    int n=0;
    char a;
    while(1)
    {
        printf("\t\t\t\t---------------MAIN MENU---------------\n");
        printf("\t\t\t\tPress up arrow and down arrow to change \n\t\t\t\tbetween options\n\t\t\t\tPress Enter to select");
        printf("\t\t\t\t\n\n\t\t\t\t_______________________________________\n\n");
        if(n==0)
        {
            red();
            printf("\t\t\t\t>>>ADD NEW CONTACT<<<");
            green();
            printf("\t\t\t\t\n\t\t\t\t_______________________________________\n\n\t\t\t\tShow all contact\n\t\t\t\t_______________________________________\n\n\t\t\t\tSearch\n\t\t\t\t_______________________________________\n\n\t\t\t\tDelete\n\t\t\t\t_______________________________________\n\n\t\t\t\tSave & Exit");
        }
        else if(n==1)
        {
            printf("\t\t\t\tAdd New contact\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>SHOW ALL CONTACT<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tSearch\n\t\t\t\t_______________________________________\n\n\t\t\t\tDelete\n\t\t\t\t_______________________________________\n\n\t\t\t\tSave & Exit");
        }
        else if(n==2)
        {
            printf("\t\t\t\tAdd New contact\n\t\t\t\t_______________________________________\n\n\t\t\t\tShow all contact\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>SEARCH<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tDelete\n\t\t\t\t_______________________________________\n\n\t\t\t\tSave & Exit");
        }
        else if(n==3)
        {
            printf("\t\t\t\tAdd New contact\n\t\t\t\t_______________________________________\n\n\t\t\t\tShow all contact\n\t\t\t\t_______________________________________\n\n\t\t\t\tSearch\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>DELETE<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tSave & Exit");
        }
        else if(n=4)
        {
            printf("\t\t\t\tAdd New contact\n\t\t\t\t_______________________________________\n\n\t\t\t\tShow all contact\n\t\t\t\t_______________________________________\n\n\t\t\t\tSearch\n\t\t\t\t_______________________________________\n\n\t\t\t\tDelete\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>SAVE & EXIT<<<");
            green();
        }
        printf("\n\t\t\t\t_______________________________________\n\n");
        a=getch();
        fflush(stdin);
        if(a=='\r')
        {
            if(n==0)
                return n+1;
            else if(n==1)
                return n+1;
            else if(n==2)
                return n+1;
            else if(n==3)
                return n+1;
            else if(n==4)
                return n+1;
        }
        if(a==80)
            n=n+1;
        else if(a==72)
            n=n-1;
        if(n<0)
            n=5+n;
        n=n%5;
        fflush(stdin);
        system("cls");
    }
}
struct phonebook *addelement(struct phonebook *head)//adding element of phone book
{
    struct phonebook *current = malloc (sizeof(struct phonebook)),*n;
    int i = 0, j = 0,f=1,k=0;
    char ch = 0,a,current_name[100],head_name[100],n_name[100],n_next_name[100];
    char str [51] = {};
    //current -> next = head;
    //head = current;
    printf("\n\t\t\t\tEnter Contact Name:\n\t\t\t\t");//taking name
    gets(str);
    fflush(stdin);
    strcpy(current -> name, str);
    for (i = 0; i < 5; )
    {
        while(1)
        {
            system("cls");
            if(f)
                printf("\t\t\t\tDo you want to enter phone number?\n");//taking phone number
            else
                printf("\t\t\t\tDo you want to enter more?\n");
            yesnochoice(ch);
            a=getch();
            if(a=='\r')
                break;
            if(a==80)
                ch=ch+1;
            else if(a==72)
                ch=ch-1;
            if(ch<0)
                ch=2+ch;
            ch=ch%2;
            fflush(stdin);
            system("cls");
            fflush(stdin);
        }
        if(ch)
        {
            while (i<5)
            {
                current -> phonenum[i][0] = '\0';
                i++;
            }
            break;
        }
        else
        {
            system("cls");
            printf("\t\t\t\tEnter phone number %d:\n\t\t\t\t",i+1);
            scanf("%s", str);
            fflush(stdin);
            strcpy(current -> phonenum[i], str);
            i++;
            f=0;
        }
    }
    ch=0;
    while(1)
    {
        system("cls");
        printf("\t\t\t\tDo you want to enter address\n");//taking address
        yesnochoice(ch);
        a=getch();
        if(a=='\r')
            break;
        if(a==80)
            ch=ch+1;
        else if(a==72)
            ch=ch-1;
        if(ch<0)
            ch=2+ch;
        ch=ch%2;
        fflush(stdin);
        system("cls");

    }
    if(!ch)
    {
        system("cls");
        fflush(stdin);
        printf("\t\t\t\tEnter Address:\n\t\t\t\t");
        scanf("%s", str);
        fflush(stdin);
        strcpy(current -> address, str);
    }
    ch=0;
    f=1;
    for (i = 0; i < 5; )
    {
        while(1)
        {
            system("cls");
            if(f)
                printf("\t\t\t\tDo you want to enter email address?\n");//taking email address
            else
                printf("\t\t\t\tDo you enter more?\n");
            yesnochoice(ch);
            a=getch();
            if(a=='\r')
                break;
            if(a==80)
                ch=ch+1;
            else if(a==72)
                ch=ch-1;
            if(ch<0)
                ch=2+ch;
            ch=ch%2;
            fflush(stdin);
            system("cls");
            fflush(stdin);
        }
        if (ch)
        {
            while (i < 5)
            {
                current -> emailaddress[i][0] = '\0';
                i++;
            }
            break;
        }
        else
        {
            system("cls");
            printf("\n\t\t\t\tEnter email address:\n\t\t\t\t");
            scanf("%s", str);
            fflush(stdin);
            strcpy(current -> emailaddress[i], str);
            i++;
            f=0;
        }
    }
    f=1;
    ch=0;
    for (i = 0; i < 5; )
    {
        while(1)
        {
            system("cls");
            if(f)
                printf("\t\t\t\tDo you want to enter group?\n");//taking group
            else
                printf("\t\t\t\tDo you want to enter more?\n");
            yesnochoice(ch);
            a=getch();
            if(a=='\r')
                break;
            if(a==80)
                ch=ch+1;
            else if(a==72)
                ch=ch-1;
            if(ch<0)
                ch=2+ch;
            ch=ch%2;
            fflush(stdin);
            system("cls");
            fflush(stdin);
        }
        if (ch)
        {
            while (i < 5)
            {
                current -> group[i][0] = '\0';
                i++;
            }
            break;
        }
        else
        {
            system("cls");
            printf("\t\t\t\tEnter group name:\n\t\t\t\t");
            scanf("%s", str);
            fflush(stdin);
            f=0;
            strcpy(current -> group[i], str);
            i++;
        }
    }
    current->next=NULL;
    while(current->name[k]!='\0')
    {
        current_name[k]=toupper(current->name[k]);
        k++;
    }

    current_name[k]='\0';
    k=0;
    if(head)
    {
        while(head->name[k]!='\0')
        {
            head_name[k]=toupper(head->name[k]);
            k++;
        }
    }
    head_name[k]='\0';
    if(head==NULL)
        head=current;
    else if(!head->next)
    {
        if(stricmp(current_name,head_name)>0)
        {
            head->next=current;
            //head=current;
        }
    }
    else if(stricmp(current_name,head_name)<0)
    {
        current->next=head;
        head=current;
    }
    else
    {
        n=head;
        k=0;
        while(n->name[k]!='\0')
        {
            n_name[k]=toupper(n->name[k]);
            k++;
        }
        n_name[k]='\0';
        if(!n->next)
        {
            if(stricmp(current_name,n_name)>0)
            {
                current->next=n->next;
                n->next=current;
                return head;
            }
        }
        while(n->next!=NULL)
        {
            k=0;
            while((n->next)->name[k]!='\0')
            {
                n_next_name[k]=toupper((n->next)->name[k]);
                k++;
            }
            n_next_name[k]='\0';
            if(stricmp(current_name,n_name)>0&&stricmp(current_name,n_next_name)<0)
            {
                current->next=n->next;
                n->next=current;
                return head;
            }
            n=n->next;
        }
        n=n->next;
    }
    system("cls");
    printf("\n\n\t\t\t\t_______________________________________\n\n");
    printf("\t\t\t\tAdding complete\n\t\t\t\tPress any key to go back to main menu");
    printf("\n\t\t\t\t_______________________________________\n\n");
    getch();
    return head;
}

void printphonebook(struct phonebook *head)//printing phone book
{
    if(!head)
    {
        printf("\n\n\t\t\t\t_______________________________________\n\n\t\t\t\tPhone book empty\n\n\t\t\t\t_______________________________________\n\n");
        return;
    }
    struct phonebook *current;
    int i;
    current=head;
    if(!current->next)
    {
        print(current);
    }
    while(current->next)
    {
        print(current);
        current=current->next;
        if(!current->next)
        {
            print(current);
        }
    }
}
void namesearch(struct phonebook *head,char name[100])//search for name
{
    struct phonebook *current,*n;
    int i;
    current=head;
    while(current)
    {
        if(!strcmp(name,current->name))
        {

            n=current;
            print(n);
            break;

        }
        else
            current=current->next;
    }
    if(!current)
        printf("\n\n\t\t\t\t_______________________________________\n\n\t\t\t\tNot found\n\n\t\t\t\t_______________________________________\n\n");

}
int phonenumbersearch(struct phonebook *head,char phonenum[100])//search for phone number
{
    struct phonebook *current=head;
    int i,j,flag=0;
    while (current!=NULL)
    {
        for (i=0; i< 5; i++)
        {
            if (!strcmp(phonenum, current->phonenum[i]) )
            {
                if (!flag)
                {
                    printf("\n\t\t\t\t_______________________________________\n\n");
                    printf("\t\t\t\tThe following contact(s) are in the %s group\n",current->group);
                    printf("\n\t\t\t\t_______________________________________\n\n");
                    flag = 1;
                }
                print(current);
            }
            else
                break;
        }
        current=current->next;
    }
    if(!flag)
    {
        printf("\n\n\t\t\t\t_______________________________________\n\n\t\t\t\tNot found\n\n\t\t\t\t_______________________________________\n\n");
        return 1;
    }
}
int addresssearch(struct phonebook *head,char address[100])//search for address
{
    struct phonebook *current,*n;
    int i;
    current=head;
    while(current)
    {
        if(!strcmp(address,current->address))
        {
            n=current;
            print(n);
            break;
        }
        else
            current=current->next;
    }
    if(!current)
    {
        printf("\n\n\t\t\t\t_______________________________________\n\n\t\t\t\tNot found\n\n\t\t\t\t_______________________________________\n\n");
        return 1;
    }
}
int emailaddresssearch(struct phonebook *head,char emailaddress[100])//search for email address
{
    struct phonebook *current=head,*n;
    int i,j,flag=0;
    while (current!=NULL)
    {
        for (i=0; i< 5; i++)
        {
            if (!strcmp(emailaddress, current->emailaddress[i]) )
            {
                if (!flag)
                {
                    printf("\n\t\t\t\t_______________________________________\n\n");
                    printf("\t\t\t\tThe following contact(s) are in the %s group\n",current->group);
                    printf("\n\t\t\t\t_______________________________________\n\n");
                    flag = 1;
                }
                print(current);
            }
            else
                break;
        }
        current=current->next;
    }
    if(!flag)
    {
        printf("\n\n\t\t\t\t_______________________________________\n\n\t\t\t\tNot found\n\n\t\t\t\t_______________________________________\n\n");
        return 1;
    }
}
int groupsearch(struct phonebook *head,char group[100])//search for group
{
    struct phonebook *current=head;
    int i,j,flag=0;
    while (current!=NULL)
    {
        for (i=0; i< 5; i++)
        {
            if (!strcmp(group, current->group[i]) )
            {
                if (!flag)
                {
                    printf("\n\t\t\t\t_______________________________________\n\n");
                    printf("\t\t\t\tThe following contact(s) are in the %s group\n\n\t\t\t\t",current->group);
                    printf("\n\t\t\t\t_______________________________________\n\n");
                    flag = 1;
                }
                print(current);
            }
            else
                break;
        }
        current=current->next;
    }
    if(!flag)
    {
        printf("\n\n\t\t\t\t_______________________________________\n\n\t\t\t\tNot found\n\n\t\t\t\t_______________________________________\n\n");
        return 1;
    }
}
void print(struct phonebook *current)// printing from search
{
    int i;
    printf("\n\t\t\t\t_______________________________________\n");
    printf("\n\n\t\t\t\tName:");
    puts(current->name);
    printf("\n\t\t\t\t_______________________________________\n");
    for(i=0; i<5; i++)
    {
        if(current->phonenum[i][0])
        {
            printf("\n\n\t\t\t\tPhone number %d:",i+1);
            puts(current->phonenum[i]);
            printf("\n\t\t\t\t_______________________________________\n");
        }
    }
    if(current->address[0])
    {
        printf("\n\n\t\t\t\tAddress:");
        puts(current->address);
        printf("\n\t\t\t\t_______________________________________\n");
    }
    for(i=0; i<5; i++)
    {
        if(current->emailaddress[i][0])
        {
            printf("\n\n\t\t\t\tEmail address %d:",i+1);
            puts(current->emailaddress[i]);
            printf("\n\t\t\t\t_______________________________________\n");
        }
    }
    for(i=0; i<5; i++)
    {
        if(current->group[i][0])
        {
            printf("\n\n\t\t\t\tGroup %d:",i+1);
            puts(current->group[i]);
            printf("\n\t\t\t\t_______________________________________\n");
        }
    }
}
struct phonebook *deletename(struct phonebook *head,char name[100])//delete via name search
{
    struct phonebook *current,*previous;
    current=head;
    previous=NULL;
    char ch=0,a;
    while(current)
    {
        if(!(strcmp(name,current->name)))
        {

            while(1)
            {
                system("cls");
                print(current);
                printf("\n\t\t\t\t_______________________________________\n\n");
                printf("\t\t\t\tDo you want to delete this data?");
                printf("\n\t\t\t\t_______________________________________\n\n");
                yesnochoice(ch);
                a=getch();
                if(a=='\r')
                    break;
                if(a==80)
                    ch=ch+1;
                else if(a==72)
                    ch=ch-1;
                if(ch<0)
                    ch=2+ch;
                ch=ch%2;
                fflush(stdin);
                system("cls");
                fflush(stdin);
            }
            if(ch)
                return head;
            else
                break;
        }
        else
        {
            previous=current;
            current=current->next;
        }
    }
    if(!current)
    {
        printf("\n\t\t\t\t_______________________________________\n\n");
        printf("\t\t\t\tNot found");
        printf("\n\t\t\t\t_______________________________________\n\n");
    }
    else if(!previous)
    {
        head=current->next;
        free(current);
        printf("\n\t\t\t\t_______________________________________\n\n");
        printf("\t\t\t\tDelete successful");
        printf("\n\t\t\t\t_______________________________________\n\n");
        return head;
    }
    else
    {
        previous->next=current->next;
        free(current);
        printf("Delete successful");
        return head;
    }

}
struct phonebook *deletephonenum(struct phonebook *head,char phonenum[100])//delete via phone number search
{
    struct phonebook *current,*previous;
    current=head;
    previous=NULL;
    int i=0;
    char ch=0,a,name[100];
    i=phonenumbersearch(head,phonenum);
    if(i)
        return head;
    printf("\n\t\t\t\tDo you want do delete the contact(s)?");
    printf("\n\t\t\t\tEnter the name of the contact you want\n\t\t\t\tto delete :");
    gets(name);
    head=deletename(head,name);
    return head;


}
struct phonebook *deleteaddress(struct phonebook *head,char address[100])//delete via address search
{
    struct phonebook *current,*previous;
    current=head;
    previous=NULL;
    int i=0;
    char ch=0,a,name[100];
    i=addresssearch(head,address);
    if(i)
        return head;
    printf("\n\t\t\t\tDo you want do delete the contact(s)?");
    printf("\n\t\t\t\tEnter the name of the contact you want\n\t\t\t\tto delete :");
    gets(name);
    head=deletename(head,name);
    return head;

}
struct phonebook *deleteemailaddress(struct phonebook *head,char emailaddress[100])//delete via email address search
{
    struct phonebook *current,*previous;
    current=head;
    previous=NULL;
    char ch=0,a,name[100];
    int i=0;
    i=emailaddresssearch(head,emailaddress);
    if(i)
        return head;
    printf("\n\t\t\t\tDo you want do delete the contact(s)?");
    printf("\n\t\t\t\tEnter the name of the contact you want\n\t\t\t\tto delete :");
    gets(name);
    head=deletename(head,name);
    return head;

}
struct phonebook *deletegroup(struct phonebook *head,char group[100])//delete via group search
{
    struct phonebook *current,*previous;
    current=head;
    previous=NULL;
    char ch=0,a,name[100];
    int i=0;
    if(i)
        return head;
    groupsearch(head,group);
    printf("\n\t\t\t\tDo you want do delete the contact(s)?");
    printf("\n\t\t\t\tEnter the name of the contact you want\n\t\t\t\tto delete :");
    gets(name);
    head=deletename(head,name);
    return head;

}
void yesnochoice(int ch)
{
    printf("\n\n\t\t\t\t_______________________________________\n\n");
    if(ch==0)
    {
        red();
        printf("\t\t\t\t>>>Yes<<<");
        green();
        printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tNo");
    }
    else if(ch==1)
    {
        printf("\t\t\t\tYes\n\t\t\t\t_______________________________________\n\n");
        red();
        printf("\t\t\t\t>>>No<<<");
        green();
    }
    printf("\n\t\t\t\t_______________________________________\n\n");
}
int menu1(int d)//sub menu design
{
    int n=0;
    char a;
    while(1)
    {
        if(d) printf("\t\t\t\t-------------DELETE MENU---------------\n");
        else printf("\t\t\t\t--------------SEARCH MENU--------------\n");
        printf("\t\t\t\tPress up arrow and down arrow to change \n\t\t\t\tbetween options\n\t\t\t\tPress Enter to select");
        printf("\n\n\t\t\t\t_______________________________________\n\n");
        if(n==0)
        {
            red();
            printf("\t\t\t\t>>>NAME<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tPhone number\n\t\t\t\t_______________________________________\n\n\t\t\t\tAddress\n\t\t\t\t_______________________________________\n\n\t\t\t\tEmail Address\n\t\t\t\t_______________________________________\n\n\t\t\t\tGroup\n\t\t\t\t_______________________________________\n\n\t\t\t\tMain menu");
        }
        else if(n==1)
        {
            printf("\t\t\t\tName\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>PHONE NUMBER<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tAddress\n\t\t\t\t_______________________________________\n\n\t\t\t\tEmail Address\n\t\t\t\t_______________________________________\n\n\t\t\t\tGroup\n\t\t\t\t_______________________________________\n\n\t\t\t\tMain menu");
        }
        else if(n==2)
        {
            printf("\t\t\t\tName\n\t\t\t\t_______________________________________\n\n\t\t\t\tPhone number\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>ADDRESS<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tEmail Address\n\t\t\t\t_______________________________________\n\n\t\t\t\tGroup\n\t\t\t\t_______________________________________\n\n\t\t\t\tMain menu");
        }
        else if(n==3)
        {
            printf("\t\t\t\tName\n\t\t\t\t_______________________________________\n\n\t\t\t\tPhone number\n\t\t\t\t_______________________________________\n\n\t\t\t\tAddress\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>EMAIL ADDRESS<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tGroup\n\t\t\t\t_______________________________________\n\n\t\t\t\tMain menu");
        }
        else if(n==4)
        {
            printf("\t\t\t\tName\n\t\t\t\t_______________________________________\n\n\t\t\t\tPhone number\n\t\t\t\t_______________________________________\n\n\t\t\t\tAddress\n\t\t\t\t_______________________________________\n\n\t\t\t\tEmail Address\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>GROUP<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tMain menu");
        }
        else if(n==5)
        {
            printf("\t\t\t\tName\n\t\t\t\t_______________________________________\n\n\t\t\t\tPhone number\n\t\t\t\t_______________________________________\n\n\t\t\t\tAddress\n\t\t\t\t_______________________________________\n\n\t\t\t\tEmail Address\n\t\t\t\t_______________________________________\n\n\t\t\t\tGroup\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>MAIN MENU<<<");
            green();
        }
        printf("\n\t\t\t\t_______________________________________\n\n");
        a=getch();
        fflush(stdin);
        if(a=='\r')
        {
            if(n==0)
                return n+1;
            else if(n==1)
                return n+1;
            else if(n==2)
                return n+1;
            else if(n==3)
                return n+1;
            else if(n==4)
                return n+1;
            else if(n==5)
                return n+1;
        }
        if(a==80)
            n=n+1;
        else if(a==72)
            n=n-1;
        if(n<0)
            n=6+n;
        n=n%6;
        fflush(stdin);
        system("cls");
    }
}
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[1;32m");
}
void savephonebook(struct phonebook *head)
{
    FILE *fp;
    if ( (fp=fopen("Phonebooksav.txt", "wb")) == NULL )
    {
        printf("Error in saving contact!\n");
        exit(1);
    }
    struct phonebook *current = head;
    while ( current != NULL )
    {
        if ( fwrite(current, sizeof(struct phonebook), 1, fp) != 1 )
        {
            printf("Error in writing contact info!\n");
            exit(1);
        }

        current = current -> next;
    }
    fclose(fp);
    printf("\n\n\t\t\t\t_______________________________________\n\n");
    printf("\n\n\t\t\t\tSave successful\n\n");
    printf("\n\n\t\t\t\t_______________________________________\n\n");
}
struct phonebook *loader(struct phonebook *head)
{
    FILE *fp;
    if ( (fp=fopen("Phonebooksav.txt", "rb")) == NULL )
    {
        return NULL;
    }
    struct phonebook *current = (struct phonebook*) malloc (sizeof(struct phonebook));

    while ( fread(current, sizeof(struct phonebook), 1, fp) == 1 )
    {

        current -> next = head;
        head = current;
        current = (struct phonebook*) malloc (sizeof(struct phonebook));
    }
    fclose(fp);
    return head;
}
struct phonebook *reverse(struct phonebook *head)
{
    struct phonebook *prev = NULL;
    struct phonebook *next;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
int menu2()
{
    int a,n=0;
    while(1)
    {
        printf("\n\n\t\t\t\t_______________________________________\n\n");
        if(n==0)
        {
            red();
            printf("\t\t\t\t>>>SEARCH MENU<<<");
            green();
            printf("\n\t\t\t\t_______________________________________\n\n\t\t\t\tExit");
        }
        else if(n==1)
        {
            printf("\t\t\t\tSEARCH MENU\n\t\t\t\t_______________________________________\n\n");
            red();
            printf("\t\t\t\t>>>EXIT<<<");
            green();
        }
        printf("\n\t\t\t\t_______________________________________\n\n");
        a=getch();
        fflush(stdin);
        if(a=='\r')
        {
            if(n==0)
                return n+1;
            else if(n==1)
                return n+1;
        }
        if(a==80)
            n=n+1;
        else if(a==72)
            n=n-1;
        if(n<0)
            n=2+n;
        n=n%2;
        fflush(stdin);
        system("cls");
    }

}



