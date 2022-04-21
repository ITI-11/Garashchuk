//Lab_9
#include<stdio.h> 
#include<conio.h> 
#include<windows.h> 
#include<math.h> 
#include<iostream>
#include <string>

char bufRus[256]; 
char* Rus(const char*text) 
{ 
CharToOem(text, bufRus); 
return bufRus; 
} 

struct index
	{
		int start;
		int end;
	};


struct dop_memory
	{
		int size;
		struct index indx;
		int Name;
	};
	
int menu();
void inf(int *memory);
void add_storage(int *memory);
void delete_proc(int *memory);
void clear(int *memory);
void size_block(int *memory);
	
int main()
{
	int i,j,t,k,n=0,minBirth,runProc;
	int memory[100];
	for(i=0;i<100;i++)
		memory[i]=0;
//	for(i=0;i<20;i++)
//		memory[i]=1;
	k=0;
	while(k!=6){
		k=menu();
		switch(k)
		{
			case 1:
				inf(memory);
				break;
			case 2:
				size_block(memory);
				break;
			case 3:
				add_storage(memory);
				break;
			case 4:
				delete_proc(memory);
				break;
			case 5:
				clear(memory);
				break;
			case 6:
				break;
			default:
				puts(Rus("������ ������ ���!"));
		}
	}
	return 0;
}

void size_block(int *memory){
	int i,max,k=0;
	max=0;
	for(i=0;i<100;i++){
		k=0;
		while(memory[i]==0){
			k++;
			i++;
		}
		if(k>max)
			max=k;
	}
	printf(Rus("������ ����������� ���������� ����� ����� %d\n"),max-2);
		
}

void clear(int *memory){
	int i;
	for(i=0;i<100;i++)
		memory[i]=0;
	puts(Rus("������ �������!"));
}

void delete_proc(int *memory){
	int i,n;
	printf(Rus("������� ����� ��������, ������� �� ������ �������:\n->����:"));
	scanf("%d",&n);
	for(i=0;i<100;i++)
		if(memory[i]==n)
			memory[i]=0;
}

void add_storage(int *memory){
	int max,i,j,k,sizeProc,freeSize=0,n;
	max=0;
	for(i=0;i<100;i++){
		if(memory[i]>max)
			max=memory[i];
	}
	k=max+1;
	//struct dop_memory p[k];
	puts(Rus("������� ����� ������ ��������"));
	printf(Rus("->����: "));scanf("%d",&n);
	puts(Rus("������� ������ ������ ��������"));
	printf(Rus("->����: "));scanf("%d",&sizeProc);
	if(sizeProc<101){
		for(i=0;i<100;i++){
			if(memory[i]==0){
				freeSize++;
			}
		}
		if(freeSize<sizeProc){
			while(freeSize<sizeProc){
				max=0;
				for(i=0;i<100;i++){
					if(max<memory[i]){
						max=memory[i];
					}
				}
				for(i=0;i<100;i++){
					if(memory[i]==max){
						memory[i]=0;
						freeSize++;
					}
				}
			}
		}
		if(freeSize>=sizeProc){
			for(i=0;i<100 && sizeProc!=0;i++){
				if(memory[i]==0){
					memory[i]=n;
					sizeProc--;
				}
			}
		}
	}else
		puts(Rus("������� ������� ����� �����"));
	
}

void inf(int *memory){
	int i,j,k,max,n;
	max=0;
	for(i=0;i<100;i++)
		if(memory[i]>max)
			max=memory[i];
	n=max+1;
	int *space=new int[n];

	for(j=0;j<n;j++){
		space[j]=0;
		for(i=0;i<100;i++)
			if(memory[i]==j)
				space[j]++;
	}
	printf(Rus("��������� ������������ - %d\n������� ������������ - %d\n"),space[0],100-space[0]);
	printf(Rus("������������ �� ����� (p0-���������� ��������� ������):\n"));
	for(i=0;i<n;i++)
		if(space[i]!=0)
			printf(" p%d=%d\n",i,space[i]);
	printf(Rus("���������� ������:\n"));
	printf("\xDA");
	for(i=0;i<100;i++)
		printf("\xC4");
	printf("\xBF\n\xB3");
	for(i=0;i<100;i++)
		printf("%d",memory[i]);
	printf("\xB3\n\xC0");
	for(i=0;i<100;i++)
		printf("\xC4");
	printf("\xD9\n");	
	delete []space;	
}

int menu(){
	int k;
	printf("\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
	printf("\xB3");printf(Rus("     �������� ����� ����     "));printf("\xB3\n");
	puts("\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4");
	printf("\xB3");printf(Rus(" 1) ������� ���������� �     "));printf("\xB3\n");
	printf("\xB3");printf(Rus(" ��������� � ������� ������. "));printf("\xB3\n");
	printf("\xB3");printf(Rus(" 2) ������ �����������       "));printf("\xB3\n");
	printf("\xB3");printf(Rus("���������� �����.            "));printf("\xB3\n");
	printf("\xB3");printf(Rus(" 3) �������� ������.         "));printf("\xB3\n");
	printf("\xB3");printf(Rus(" 4) ������� �������.         "));printf("\xB3\n");
	printf("\xB3");printf(Rus(" 5) ��������� �������� ������"));printf("\xB3\n");
	printf("\xB3");printf(Rus(" 6) �����.                   "));printf("\xB3\n");
	puts("\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");
	printf(Rus("->����: "));
	//"	������� ��� �������� �� ����������  ����������� � �������� �����
	scanf("%d",&k);
	return(k);
}


