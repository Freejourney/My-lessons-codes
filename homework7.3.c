#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *data;
	int size;
	int max;
}seqlist;

void IniList(seqlist *l, int n);
void InsertRear(seqlist *l, int n);
void showList(seqlist *l, int n);
void Insert(seqlist *l, int n);
void Erase(seqlist *l, int n);
void clear(seqlist *l);
void FreeList(seqlist *l);
void Selection(seqlist *l);

int main()
{
	int i,j;
	seqlist l;
	IniList(&l, 10);
	InsertRear(&l, 10);
	showList(&l, 10);
	Selection(&l);
	showList(&l, 10); 
	Insert(&l,10); 
	showList(&l, 10); 
	Erase(&l, 10);
	showList(&l, 10);
	clear(&l);
	FreeList(&l);
}

void Selection(seqlist *l)
{
	int min;
	int i,j,k;
	for(j=0;j<l->size;j++)//size=10
	{
		min=l->data[j];
		k=j;
		for(i=j;i<l->size;i++)
		{
			if(min>l->data[i])
			{
				k=i;
				min=l->data[i]; 
			}
		}
		int temp;
		temp=l->data[j];
		l->data[j]=min;
		l->data[k]=temp;
	}
}
void FreeList(seqlist *l)
{
	free(l->data);
}
void clear(seqlist *l)
{
	l->size=0;
}
void Erase(seqlist *l, int n)
{
	int m;
	printf("Now enter the index where you want to erase the number.\n");
	scanf("%d", &m);
	while(getchar()!='\n')
		continue;
	printf("You'll erase the %d , are you sure? please enter [Y] to erase it or enter [Q] to quit.\n", l->data[m]);
	if(getchar()=='y')
	{
		for(;m<=n-1;m++)
			l->data[m]=l->data[m+1]; 
		l->size--;
	}
}

void Insert(seqlist *l, int n)
{
	int m;
	printf("Now enter the index where you want to insert a number(0-9).\n");
	scanf("%d", &m);
	int i;
	for(i=l->size-1;i>=m;i--)
	{
		l->data[i+1]=l->data[i];
	}
	printf("Ok, you will insert a number at the index of %d, please enter the number you want to enter.\n", m);
	scanf("%d", &(l->data[m]));
	l->size++;
	printf("Number insert succeed! Here is the list after insert %d\n", l->data[m]);
}
void showList(seqlist *l, int n)
{
	int i;
	for(i=0;i<l->size;i++)
		printf("%3d", l->data[i]);
	putchar('\n');
}

void IniList(seqlist *l, int n)
{
	l->data=(int *)malloc((n+1)*sizeof(int));
	if(l->data==NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	l->size=0;
	l->max=n;
}

void InsertRear(seqlist *l, int n)
{
	printf("Please enter 10 numbers and I'll save them in the Seqlist for you.\n");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d", &(l->data[l->size++]));
		printf("%d number is entered\n",i+1);
	}
	printf("Number enter succeed!\n"
		   "Here is the list I have just created!"); 
}
