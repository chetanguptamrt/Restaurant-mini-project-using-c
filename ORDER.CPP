#include<iostream.h>
#include<conio.h>
#include<string.h>
int fd_edt=0;
int cst_edt=0;
int cst_ord=0;
void take_order();
void make_order();
void order_history();
void food_detail();
void food_entry();
void food_show();
void food_delete();
struct food
{
	char name[20];
	int price,use,number;
};
struct customer
{
	int arr[15],number,sum,size;
};
struct food fd[20];
struct customer cst[20];
void main()
{
	int ch;
	main_top:
	clrscr();
	cout<<"press 1 for take order\npress 2 for open order history";
	if(cst_edt==0)
		cout<<" (disable)";
	cout<<"\npress 3 of food detail\npress 4 for exit\n";
	main_choice:
	cout<<"enter your choice - ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			take_order();
			break;
		case 2:
			order_history();
			break;
		case 3:
			food_detail();
			break;
		case 4:
			goto main_end;
		default:
			cout<<"\n wrong choice! re-";
			goto main_choice;
	}
	goto main_top;
	main_end:
	clrscr();
	cout<<"thanks for using this software";
	getch();
}
void take_order()
{
	int ch;
	take_order_top:
	clrscr();
	food_show();
	cout<<"\npress 1 for new order";
	if(fd_edt==0)
	{
		cout<<" (Disable)";
	}
	cout<<"\npress 2 for back\n";
	take_order_ch:
	cout<<"enter your choice - ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			make_order();
			break;
		case 2:
			goto take_order_end;
		default:
			cout<<"invalid choice! re-";
			goto  take_order_ch;
	}
	goto take_order_top;
	take_order_end:
}
void make_order()
{
	if(fd_edt>0)
	{
		int ch,i;
		make_order_top:
		clrscr();
		food_show();
		cst[cst_edt].number=cst_edt+1;
		cout<<"\nuser= "<<cst[cst_edt].number<<"\t sum="<<cst[cst_edt].sum;
		cout<<"\nyour order - ";
		for(i=0;i<cst_ord;i++)
			cout<<cst[cst_edt].arr[i]<<",";
		cout<<"\n\npress those numbert to select food\npress "<<fd_edt+1<<" for next user\n";
		cout<<"press "<<fd_edt+2<<" for back\n";
		cout<<"enter your choice - ";
		cin>>ch;
		if(ch<=fd_edt)
		{
			cst[cst_edt].arr[cst_ord]=ch;
			cst[cst_edt].sum+=fd[ch-1].price;
			++cst[cst_edt].size;
			++fd[ch-1].use;
			++cst_ord;
		}
		//for new user
		if(ch==fd_edt+1)
		{
			cst_ord=0;
			++cst_edt;
		}
		//for  back
		if(ch==fd_edt+2)
		{
			goto  make_order_end;
		}
		goto make_order_top;
		make_order_end:
	}
}
void order_history()
{
	if(0<cst_edt)
	{
		int ch,i;
		order_history_top:
		clrscr();
		cout<<"order_history:-\n";
		cout<<"number\tsum\n";
		for(i=0;i<cst_edt;i++)
		{
			cout<<cst[i].number<<"\t"<<cst[i].sum<<endl;
		}
		cout<<"press any for back - ";
		cin>>ch;
	}
}
void food_detail()
{
	int ch,num;
	food_detail_top:
	clrscr();
	food_show();
	cout<<"\n\npress 1 for edit price";
	if(fd_edt==0)
		cout<<" (disable)";
	cout<<"\npress 2 for enter new food\n";
	cout<<"press 3 for delete some food";
	if(fd_edt==0)
		cout<<" (dtsable)";
	cout<<"\npress 4 for back\n";
	food_detail_choice:
	cout<<"enter your choice - ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			if(0<fd_edt)
			{
				cout<<"enter food number - ";
				cin>>num;
				cout<<"enter new price - ";
				cin>>fd[num-1].price;
			}
			break;
		case 2:
			food_entry();
			break;
		case 3:
			if(0<fd_edt)
			food_delete();
			break;
		case 4:
			goto food_detail_end;
		default:
			cout<<"wrong choice! re-";
			goto food_detail_choice;
	}
	goto food_detail_top;
	food_detail_end:
}
void food_entry()
{
	int cycle;
	food_entry_top:
	clrscr();
	food_show();
	if(fd_edt<20)
	{
		++fd_edt;
		cout<<"\nenter new food detail:-";
		cout<<"\nname - ";
		cin>>fd[fd_edt-1].name;
		cout<<"price - ";
		cin>>fd[fd_edt-1].price;
		fd[fd_edt-1].use=0;
		fd[fd_edt-1].number=fd_edt;
		cout<<"\ndo you want to enter new food press 1\notherwise press any key\n=";
		cin>>cycle;
		if(cycle==1)
		{
			goto food_entry_top;
		}
	}
	else
	{
		cout<<"\nyou are not enter more than 20 food....";
	}
}
void food_show()
{
	int i;
	if(fd_edt>0)
	{
		cout<<"food detail\n";
		cout<<"no.\tname\tprice\tuse";
		if(fd_edt>1)
			cout<<"\tno.\tname\tprice\tuse";
		cout<<endl;
		for(i=0;i<fd_edt;i++)
		{
			cout<<fd[i].number<<"\t"<<fd[i].name<<"\t"<<fd[i].price<<"\t"<<fd[i].use;
			if(i%2==1)
				cout<<"\n";
			else
				cout<<"\t";
		}
	}
	else
	{
		cout<<"food are not exist...";
	}
}
void food_delete()
{
	if(0<fd_edt)
	{
		int i,num;
		cout<<"\nenter food number";
		cin>>num;
		if(num<=fd_edt)
		{
			--fd_edt;
			for(i=num-1;i<fd_edt;i++)
			{
				strcpy(fd[i].name,fd[i+1].name);
				fd[i].use=fd[i+1].use;
				fd[i].price=fd[i+1].price;
			}
		}
	}
}