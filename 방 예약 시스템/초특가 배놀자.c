#include<stdio.h>
#include<string.h>

int main()
{
	int a,x,y; //a=1 체크인, a=0 체크아웃, a=2 방청소 a=1 checkin, a=0 checkout, a=2 clean the room
	int i,j,k,cnt=0; //cnt=남은 방의 평수  cnt=size of available rooms
	int room[31];//30평짜리 방 the size of the rooms is 30
	int data[31];//어느 방이 차 있는지 구분하려고 what rooms are fulled
	for(k=0;k<30;k++)
	{
		room[k]=0;
		data[k]=0;
	} //방 다 비움 all rooms are leaved
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
				} //빈 방 전체 평수 세기 how many rooms are not fulled
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
						} // 비어있는 방의 개별 평수 = k , size of a room that is not fulled
						if(i+k>30)
						break;
						if(k<y) // 방의 평수가 고객이 원하는 평수보다 작으면 if the size of the room is not enough for this customer
						{
							while(room[i+k]==1)
							k++;
							i=k+i-1; //다음으로 비어있는 방 찾음, for에 i++때문에 -1 넣음 next room that is not fulled
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
					room[i+j]=1; //방을 채운다 the room is fulled
				}
				printf("room no.:%d\n",i); //방 번호는 방의 첫칸 번호 the room number is first number of the room[]
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
