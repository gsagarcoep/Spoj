#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void getInt(int &x)
{
	register int c = getchar_unlocked();
	x=0;
	int neg=0;
	for( ;((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	
	if(c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}

	for(;c>47 && c<58; c = getchar_unlocked())
	{
		x= (x << 1) + (x << 3) + c - 48;
	}

	if(neg) 
		x=-x;

}
struct node
{
	char A;
	char name[20];	
	long long int seniority;
	long long int productivity;
	struct node* next;
	struct node* prev;
};

int main()
{
	int M=0;
	getInt(M);
	struct node* list;
	struct node* head;
	int listCount=0;
	while(M--)
	{
		long long int totalProd=0;
		
		char tempA,tempName[20];
		long long int tempSen,tempProd;
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		
		if(listCount==0)
			scanf("%c%s%lld%lld",&tempA,&tempName,&tempSen,&tempProd);
		else
			scanf("%*c%c%s%lld%lld",&tempA,&tempName,&tempSen,&tempProd);
		
		printf("---%c %s %lld %lld\n--+\n",tempA,tempName,tempSen,tempProd);
		temp->A=tempA;
		strcpy(temp->name,tempName);
		temp->seniority=tempSen;
		temp->productivity=tempProd;
		temp->next=NULL;
		temp->prev=NULL;
		
		if(tempA=='R')
		{}
		else{
			if(listCount==0)
			{
				list=temp;
				head=temp;
				listCount++;
			}
			else{
				bool flag=false;
				struct node* iter=head;
				while(iter!=NULL){
					printf("***%s+*",iter->name);
			
				if(!flag && (temp->seniority > iter->seniority || (temp->seniority == iter->seniority && temp->productivity > iter->productivity)))
						{
						temp->prev=iter->prev;
						temp->next=iter;
						iter->prev=temp;
						iter=temp;
						flag=true;
						listCount++;
					}
					else{
						totalProd+=(iter->prev->productivity*iter->productivity);
						iter=iter->next;
						if(iter->next==NULL){
							if(!flag){
								temp->prev=iter;
								iter->next=temp;
								listCount++;
							}
							else	
								totalProd+=(iter->prev->productivity*iter->productivity);
						}
					}
					
				}
		
			}		
		}		
		printf("%lld\n",totalProd);
	}
	return 0;
	
}
