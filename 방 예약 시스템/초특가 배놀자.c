#include<stdio.h>
#include<string.h>

int main()
{
	int a,x,y; //a=1 üũ��, a=0 üũ�ƿ�, a=2 ��û�� a=1 checkin, a=0 checkout, a=2 clean the room
	int i,j,k,cnt=0; //cnt=���� ���� ���  cnt=size of available rooms
	int room[31];//30��¥�� �� the size of the rooms is 30
	int data[31];//��� ���� �� �ִ��� �����Ϸ��� what rooms are fulled
	for(k=0;k<30;k++)
	{
		room[k]=0;
		data[k]=0;
	} //�� �� ��� all rooms are leaved
	room[30]=1;
	data[30]=1;
	while(1)
	{
		printf("check in(1), check out(0), clean the rooms(2): ");
		scanf("%d",&a);
	
		if(a==1)
		{
			printf("how many people?: ");
			scanf("%d",&x);
			if(x==0)
				printf("no way..");
			else
			{
				printf("how much size of the room do you want?: ");
				scanf("%d",&y);
				for(k=0;k<30;k++)
				{
					if(room[k]==0)
					cnt++;
				} //�� �� ��ü ��� ���� how many rooms are not fulled
			}
			if(y>cnt)
			printf("sorry no rooms now.\n");
			else
			{
				for(i=0;i<30;i++)
				{
					if(room[i]==0)
					{
						for(k=0;k<30;k++)
						{
							if(room[i+k]==1)
							break;
						} // ����ִ� ���� ���� ��� = k , size of a room that is not fulled
						if(i+k>30)
						break;
						if(k<y) // ���� ����� ���� ���ϴ� ������� ������ if the size of the room is not enough for this customer
						{
							while(room[i+k]==1)
							k++;
							i=k+i-1; //�������� ����ִ� �� ã��, for�� i++������ -1 ���� next room that is not fulled
						}
						else
						{
							k=0;
							break;
						}
					}
				}
				if(i+k>30)
				printf("sorry no rooms here");
				for(j=0;j<y;j++)
				{
					room[i+j]=1; //���� ä��� the room is fulled
				}
				printf("room no.:%d\n",i); //�� ��ȣ�� ���� ùĭ ��ȣ the room number is first number of the room[]
				data[i]=1, data[i+j]=1;
				cnt=0;
				for(k=0;k<30;k++)
				{
					if(room[k]==0)
					cnt++;
				}
				printf("left room: %d\n",cnt);
			}
		}
		if(a==0)
		{
			printf("room no.: ");
			scanf("%d",&i);
			for(j=1;j<30;j++)
			{
				if(data[i+j]==1)
				{
					break;
				}
			}
			for(k=0;k<=j;k++)
			{
				room[i+k]=2;
			}
			printf("please clean the room%d-%d \n",i,i+j);

		}
		if(a==2)
		{
			printf("room no.:");
			scanf("%d",&i);
			data[i]=0;
			while(room[i]==2)
			{
				room[i]=0;
				i++;
			}
			data[i-1]=0;
		}
	}
	return 0;
}
