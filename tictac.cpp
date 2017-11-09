# include <stdio.h>
# include <graphics.h>
# include <iostream>
# include <bits/stdc++.h>
using namespace std;

struct node
{
    string data;
     int v;
    struct node* next;
};

typedef struct node snode;

snode *newnode, *ptr, *temp, *temp1, *temp2;

snode *first=NULL, *last=NULL;

int win=0;
enum shape{O,X};

void player(int u, int v);

snode * create(int val);

void insert(int a);

void display();

void player1(int m);

void player2(int n);

void result(string d);

void check();

void call();

void restart(int s);

void check2();

void plotBoard();
void plotshape(shape s, int block);

void plotBoard()
{
  MAXX=getmaxx();
  MAXY=getmaxy();
  line((MAXX/2)-50,(MAXY/2)-150,(MAXX/2)-50,(MAXY/2)+150));
  line((MAXX/2)+50,(MAXY/2)-150,(MAXX/2)+50,(MAXY/2)+150));
    line((MAXX/2)-150,(MAXY/2)-50,(MAXX/2)+150,(MAXY/2)-50));
    line((MAXX/2)-150,(MAXY/2)+50,(MAXX/2)+150,(MAXY/2)+50));
    
}

void plotshape(shape s, int block)
{
  setcolor(s==X ? RED: BLUE);
  switch(block)
  {
    case 1 : if(s==X)
            {
              line((MAXX/2)-150,(MAXY/2)-150,(MAXX/2)-50,(MAXY/2)-50));
                    line((MAXX/2)-150,(MAXY/2)-50,(MAXX/2)-150,(MAXY/2)+150));

             }
             else
             {
              circle((MAXX/2)-100,(MAXY/2)-100,40);
             }
             break;
     case 2 : if(s==X)
            {
              line((MAXX/2)-50,(MAXY/2)-50,(MAXX/2)+50,(MAXY/2)-150));
                    line((MAXX/2)-50,(MAXY/2)-150,(MAXX/2)+50,(MAXY/2)-50));

             }
             else
             {
              circle((MAXX/2),(MAXY/2)-100,40);
             }
             break;
      case 3 : if(s==X)
            {
              line((MAXX/2)+50,(MAXY/2)-150,(MAXX/2)+150,(MAXY/2)-50));
                    line((MAXX/2)+50,(MAXY/2)-50,(MAXX/2)+150,(MAXY/2)-150));

             }
             else
             {
              circle((MAXX/2+100),(MAXY/2)-100,40);
             }
                 break;
      case 4: if(s==X)
            {
              line((MAXX/2)-150,(MAXY/2)-50,(MAXX/2)-50,(MAXY/2)+50));
                    line((MAXX/2)-150,(MAXY/2)+50,(MAXX/2)-50,(MAXY/2)-50));

             }
             else
             {
              circle((MAXX/2-100),(MAXY/2),40);
             }
             break;
       case 5: if(s==X)
            {
              line((MAXX/2)-50,(MAXY/2)-50,(MAXX/2)+50,(MAXY/2)+50));
                    line((MAXX/2)-50,(MAXY/2)+50,(MAXX/2)+50,(MAXY/2)-50));

             }
             else
             {
              circle((MAXX/2),(MAXY/2),40);
             }
             break;

        case 6: if(s==X)
            {
              line((MAXX/2)+50,(MAXY/2)-150,(MAXX/2)+150,(MAXY/2)+50));
                    line((MAXX/2)+50,(MAXY/2)+50,(MAXX/2)+150,(MAXY/2)-50));

             }
             else
             {
              circle((MAXX/2+100),(MAXY/2),40);
             }
             break;
          case 7: if(s==X)
            {
              line((MAXX/2)-150,(MAXY/2)+50,(MAXX/2)-50,(MAXY/2)+150));
                    line((MAXX/2)-150,(MAXY/2)+150,(MAXX/2)-50,(MAXY/2)+50));

             }
             else
             {
              circle((MAXX/2-100),(MAXY/2)+100,40);
             } 
             break;   
    case 8: if(s==X)
            {
              line((MAXX/2)-50,(MAXY/2)+50,(MAXX/2)+50,(MAXY/2)+150));
                    line((MAXX/2)-50,(MAXY/2)+150,(MAXX/2)+50,(MAXY/2)+50));

             }
             else
             {
              circle((MAXX/2),(MAXY/2)+100,40);
             }
             break;

      case 9: if(s==X)
            {
              line((MAXX/2)+50,(MAXY/2)+50,(MAXX/2)+150,(MAXY/2)+150));
                    line((MAXX/2)+50,(MAXY/2)+150,(MAXX/2)+150,(MAXY/2)+50));

             }
             else
             {
              circle((MAXX/2+100),(MAXY/2)+100,40);
             }  
             break;         
  }
}

/*
function to create a node
*/

snode * create(int val)
{
    newnode=new(snode);

    if(newnode==NULL)
    {
        cout<<"Memory not allocated "<<endl;
    }

    else
    {
        newnode->data= char(val+'0');
        newnode->v=0;
        newnode->next=NULL;
        return newnode;
    }

}

/*
function to insert a node at the end
*/

void insert(int a)
{
    newnode=create(a);

    if(first==last && first==NULL)
    {
        first=last=newnode;
        first->next=NULL;
        last->next=NULL;
    }

    else
    {
        last->next=newnode;
        last=newnode;
        newnode->next=NULL;
    }

}

/*
function to display the board
*/

void display()
{
    int c=0;
cout<<"\t\t";

    if(first==NULL)
    {
        cout<<"'List is empty ";
    }

    else
    {
        ptr=first;
        while(ptr!=NULL)
        {
          if(c==3 || c==6)
          {
              cout<<"\n\n\t\t";
          }
          cout<<ptr->data<<"    ";
          c++;
          ptr=ptr->next;
        }

    }

}

/*
function to add value of player1 to the board
*/

void player1(int m)
{
    int c=0;
    ptr=first;

    while(ptr!=NULL)
    {

       if((c+1)==m && (ptr->v==1))
        {
            win=3;
        }

        if((c+1)==m && (ptr->v==0))
        {
            ptr->data="X";
            ptr->v=1;
            plotBoard(X,m);
        }
        ptr=ptr->next;
        c++;
    }

}

/*
function to add value of player2 to the board
*/

void player2(int n)
{
    int c1=0;
    ptr=first;

    while(ptr!=NULL)
    {
        if((c1+1)==n && (ptr->v==1))
        {
            win=3; 
        }

        if((c1+1)==n && (ptr->v==0))
        {
            ptr->data="O";
            ptr->v=1;
            plotBoard(O,n);
        }

        ptr=ptr->next;
         c1++;
    }

}

/*
function to display the result
*/

void result(string d)
{
    if(d=="X")
    {
        cout<<"\n\n\n CONGRATULATIONS \nPlayer 1 won the match\n\n";
        exit;
    }

    else
    {
        cout<<"\n\n\n CONGRATULATIONS \n\nPlayer 2 won the match\n\n";
        exit;
    }

}

void check2()
{
    if(win==3)
    {
        cout<<"\n\nWrong move !!\nGame End\n\n";
        exit;
    }

}

/*
function to check whether any player has won the game
*/

void check()
{
    string t;

    temp=first;

    temp1=temp->next->next->next;

    temp2=temp1->next->next->next;

    if((temp->data)==(temp->next->data) && (temp->data)==(temp->next->next->data))
    {
        win=1;
        t=temp->data;
        result(t);
    }

    if((temp1->data)==(temp1->next->data) && (temp1->data)==(temp1->next->next->data))
    {
        win=1;
        t=temp1->data;
        result(t);
    }

    if((temp2->data)==(temp2->next->data) && (temp2->data)==(temp2->next->next->data))
    {
        win=1;
        t=temp2->data;
        result(t);
    }

    if((temp->data)==(temp1->data) && (temp->data)==(temp2->data))
    {
        win=1;
        t=temp->data;
        result(t);
    }

    if((temp->next->data)==(temp1->next->data) && (temp->next->data)==(temp2->next->data))
    {
        win=1;
        t=temp->next->data;
        result(t);
    }

    if((temp->next->next->data)==(temp1->next->next->data) && (temp->next->next->data)==(temp2->next->next->data))
    {
        win=1;
        t=temp->next->next->data;
        result(t);
    }

    if((temp->data)==(temp1->next->data) && (temp->data)==(temp2->next->next->data))
    {
        win=1;
        t=temp->data;
        result(t);
    }

    if((temp->next->next->data)==(temp1->next->data) && (temp1->next->data)==(temp2->data))
    {
        win=1;
        t=temp1->next->data;
        result(t);
    }

}

/*
function to give instructions to the player
*/

void call()
{
    int p;

    cout<<"\n\n\tThis is a two player game ";

    cout<<"\n\n\tSymbol for player 1 is (X) \n";

    cout<<"\n\tSymbol for player 2 is (O) \n";

  for(int i=0; i<9; i++)
  {
      if(win==1)
      {
          break;
      }

      if(win==3)
      {
          break;
      }

      else
      {
          int z=i%2;

          cout<<"\n\nTurn for player "<<z+1<<"\nEnter the number : ";
          cin>> p;

          if(p< 1 || p> 9)
          {
              cout<<"Wrong number !!";
              win=2;
              break;
          }

          if(z==0)
          {
              player1(p);
          }

          else
          {
              player2(p);
          }

          check2();

          //display();

          check();

      }

  }

}


void restart(int s)
{
     int c2=0;
    ptr=first;

    while(ptr!=NULL)
    {

        if((c2+1)==s)
        {
            ptr->data=char(s+'0');
        }

        ptr=ptr->next;

         c2++;

    }

}


int main()
{

    insert(1);

    insert(2);

    insert(3);

    insert(4);

    insert(5);

    insert(6);

    insert(7);

    insert(8);

    insert(9);

    char choice;
  int graphicDriver= DETECT, graphicMode;
  initgraph(&graphicDriver, &graphicMode,"");

    do
    {
    cout<<"\t\t WELCOME TO TIC-TAC-TOE GAME \n\n";
    int ch;
    cout<<"1. Start the game "<<endl;
    cout<<"2. Quit the game "<<endl;
    cin>>ch;
    

    switch(ch)
    {
        case 1 : cout<<"\t\tTic-tac-toe board\n\n";
                 display();
                 //clrscr();
                 cleardevice();
                 plotBoard();
                 call();
                 break;

        case 2 : break;

        case 3 : cout<<"Wrong choice !!";
                 break;
    }

    if(win==0)
    {
        cout<<"\n\n Match is draw !! \n\n";
    }

    cout<<"\n\n\nDo you want to play again (y/n) ? : ";
    cin>>choice;

    for(int i=1; i<=9; i++)
    {
        restart(i);
        win=0;
    }

    }while(choice=='y' || choice=='Y');

}
