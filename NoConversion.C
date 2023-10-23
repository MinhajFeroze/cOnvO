#include<stdlib.h>
#include<math.h>
#include<conio.h>

typedef struct node
{
	int info;
	struct node *next;
}node;

node *first=NULL;

void stack(int n)
{
	node *ptr, *temp;
	
	ptr=(node *)malloc(sizeof (node));
	
	ptr->info=n;
	ptr->next=NULL;
	
	if (first==NULL)
	{
		first=ptr;
		return;
	}
	
	temp=first;
	
	while (temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=ptr;
}

void rev()
{
	node *ptr, *prev=NULL, *temp;
	
	ptr=first;
	temp=first->next;
	
	while (temp!=NULL)
	{
		ptr->next=prev;
		
		prev=ptr;
		ptr=temp;
		temp=temp->next;
	}
	ptr->next=prev;
	first=ptr;
}

void display()
{
	node *ptr;
	ptr=first;
	
	while (ptr!=NULL)
	{
		if (ptr->info==10)
		printf("A");
		else if (ptr->info==11)
		printf("B");
		else if (ptr->info==12)
		printf("C");
		else if (ptr->info==13)
		printf("D");
		else if (ptr->info==14)
		printf("E");
		else if (ptr->info==15)
		printf("F");
		else
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
}

int accept()
{
	int n;
	printf("Enter No: ");
	scanf("%d",&n);
	
	return n;
}

void Dec_Bin()
{
	int dig, n=accept();
	while (n>0)
	{
		dig=n%2;
		stack(dig);
		n/=2;
	}
	
	rev();
	printf("Binary = ");
	display();
	printf("\n\n");
}

void Dec_Oct(int n)
{
	int dig; //n=accept();
	while (n>0)
	{
		dig=n%8;
		stack(dig);
		n/=8;
	}
	
	rev();
	printf("Octal = ");
	display();
	printf("\n\n");
}

void Dec_Hex(int n)
{
	int dig; //n=accept();
	while (n>0)
	{
		dig=n%16;
		stack(dig);
		n/=16;
	}
	
	rev();
	printf("Hexadecimal = ");
	display();
	printf("\n\n");
}

int Bin_Dec(int n, int c)
{
	int dig, p=0, sum=0;//n=accept();
	while (n>0)
	{
		dig=n%10;
		sum+=(dig*pow(2,p));
		p++;
		n/=10;
	}
	if (c==1)
	return sum;
	printf("Decimal = %d",sum);
	printf("\n\n");
	//return sum;
}

void Bin_Oct()
{
	int n=accept(), dig, d=0;
	while (n>0)
	{
		dig=n%1000;
		d=Bin_Dec(dig,1);
		stack(d);
		n/=1000;
	}
	rev();
	printf("Octal = ");
	display();
	printf("\n\n");
}

void Bin_Hex()
{
	int dec, n=accept();
	dec=Bin_Dec(n,1);
	Dec_Hex(dec);
}

void Oct_Dec(int ch)
{
	int dig, p=0, sum=0,n=accept();
	while (n>0)
	{
		dig=n%10;
		sum+=(dig*pow(8,p));
		p++;
		n/=10;
	}
	if (ch==1)
	return sum;
	printf("Decimal = %d",sum);
	printf("\n\n");
}

void Oct_Bin()
{
	int dig, n=accept(), copy=n;
	node *ptr;
	
	while (copy>0)
	{
		dig=copy%10;
		stack(dig);
		copy/=10;
	}
	
	rev();
	ptr=first;
	
	printf("Binary: ");
	while (ptr!=NULL)
	{
		if (ptr->info==0)
		printf("000");
		else if (ptr->info==1)
		printf("001");
		else if (ptr->info==2)
		printf("010");
		else if (ptr->info==3)
		printf("011");
		else if (ptr->info==4)
		printf("100");
		else if (ptr->info==5)
		printf("101");
		else if (ptr->info==6)
		printf("110");
		else if (ptr->info==7)
		printf("111");
		
		ptr=ptr->next;
	}
	printf("\n\n");
}

void Oct_Hex()
{
	int dec=Oct_Dec(1);
	Dec_Hex(dec);
}

void Hex_Dec(int ch)//Char Issue
{
	/*int dig, p=0, sum=0,n=accept();
	while (n>0)
	{
		dig=n%10;
		sum+=(dig*pow(16,p));
		p++;
		n/=10;
	}
	printf("Decimal = %d",sum);
	printf("\n\n");*/
	char a[15];
	int l, i, p=0, sum=0;
	printf("Enter No: ");
	scanf("%s",&a);
	l=strlen(a);
	
	for (i=l-1; i>=0; i--)
	{
		if (a[i]=='A')
		sum+=(10*pow(16,p));
		else if (a[i]=='B')
		sum+=(11*pow(16,p));
		else if (a[i]=='C')
		sum+=(12*pow(16,p));
		else if (a[i]=='D')
		sum+=(13*pow(16,p));
		else if (a[i]=='E')
		sum+=(14*pow(16,p));
		else if (a[i]=='F')
		sum+=(15*pow(16,p));
		else// Ascii Error !! (Solved !!)
		{
			//printf("%d  ",(int)a[i]);
		    sum+=((a[i]-48)*pow(16,p));
		}
		
		p++;
	}
	if (ch==1)
	return sum;
	printf("Decimal: %d\n\n",sum);
}

void Hex_Bin()
{
	char s[15];
	int l, i;
	printf("Enter No: ");
	scanf("%s",&s);
	//gets(s);
	l=strlen(s);
	
	printf("Binary: ");
	for (i=0; i<l; i++)
	{
		if (s[i]=='0')
		printf("0000");
		else if (s[i]=='1')
		printf("0001");
		else if (s[i]=='2')
		printf("0010");
		else if (s[i]=='3')
		printf("0011");
		else if (s[i]=='4')
		printf("0100");
		else if (s[i]=='5')
		printf("0101");
		else if (s[i]=='6')
		printf("0110");
		else if (s[i]=='7')
		printf("0111");
		else if (s[i]=='8')
		printf("1000");
		else if (s[i]=='9')
		printf("1001");
		else if (s[i]=='A')
		printf("1010");
		else if (s[i]=='B')
		printf("1011");
		else if (s[i]=='C')
		printf("1100");
		else if (s[i]=='D')
		printf("1101");
		else if (s[i]=='E')
		printf("1110");
		else if (s[i]=='F')
		printf("0001");
	}
	printf("\n\n");
}

void Hex_Oct()
{
	int hex=Hex_Dec(1);
	Dec_Oct(hex);
}
		
main()
{
	int ch;
	do
	{
		first=NULL;
		
		printf("1. Dec->Bin\n2. Dec->Oct\n3. Dec->Hex\n4. Bin->Dec\n5. Bin->Oct\n6. Bin->Hex\n7. Oct->Dec\n8. Oct->Bin\n9. Oct->Hex\n10. Hex->Dec\n11. Hex->Bin\n12. Hex->Oct\n0. EXIT\n\n");
		scanf("%d",&ch);
		if (ch==1)
		Dec_Bin();
		else if (ch==2)
		{
			int n=accept();
			Dec_Oct(n);
		}
		else if (ch==3)
		{
			int n=accept();
		Dec_Hex(n);
		}
		else if (ch==4)
		{
			int n=accept();
		    Bin_Dec(n,0);
		}
		else if (ch==5)
		Bin_Oct();
		else if (ch==6)
		Bin_Hex();
		else if (ch==7)
		Oct_Dec(0);
		else if (ch==8)
		Oct_Bin();
		else if (ch==9)
		Oct_Hex();
		else if (ch==10)
		Hex_Dec(0);
		else if (ch==11)
		Hex_Bin();
		else if (ch==12)
		Hex_Oct();
		else if (ch==0)
		{
			clrscr();
			printf("sEE U sOOn !!");
			exit(0);
		}
		else
		printf("Invalid Choice\n\n");
	}while (1);
}