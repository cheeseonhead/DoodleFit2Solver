#include <cstdio>

/*
Presets"
1





*/
int bh,bw,board[100][100];
int pid,piece[100][5][5],ph[100],pw[100],pqua[100];
int ans[100][100][100];
int aid;
bool esc;

bool isfit(int id,int cx,int cy,int h,int w)
{
	for(int i=cx;i-cx<h;i++)
		for(int j=cy;j-cy<w;j++)
		{
			if(i>=bh || j>=bw)return 0;
			if(!piece[id][i-cx][j-cy] && board[i][j]>0)
				return 0;
		}
	
	for(int i=cx;i-cx<h;i++)
		for(int j=cy;j-cy<w;j++)
		{
			if((!board[i][j]) && (!piece[id][i-cx][j-cy]))
			{
				board[i][j]=id+2;
			}
		}
		
		
	
	return 1;
}

void unvis(int id)
{
	for(int i=0;i<bh;i++)
		for(int j=0;j<bw;j++)
			if(board[i][j]==id+2)
				board[i][j]=0;
}

void printboard(int id)
{
	for(int i=0;i<bh;i++)
	{
		for(int j=0;j<bw;j++)
			if(ans[id][i][j]==1)
				printf(" ");
			else
				printf("%c",ans[id][i][j]+'A'-1);
		puts("");
	}
	puts("");			
}

int chnprint(int id)
{
	int check[1000],dif;
	for(int k=0;k<id;k++)
	{
		memset(check,0,sizeof(check));
		dif=0;
		
		for(int i=0;i<bh;i++)
		{
			for(int j=0;j<bw;j++)
			{
				if(check[ans[k][i][j]]==0 && ans[id][i][j]!=0)
					check[ans[k][i][j]]=ans[id][i][j];
				if(check[ans[k][i][j]]!=0 && check[ans[k][i][j]]!=ans[id][i][j])
				{
					dif=1;
					break;
				}
			}
			if(dif)break;
		}
		if(dif)continue;
		return 0;
	}
	printboard(id);
	return 1;
}

bool dfs(int id,int h,int w)
{
	if(id==pid)return 1;
	for(int cx=0;cx<bh;cx++)
		for(int cy=0;cy<bw;cy++)
		{
			if(isfit(id,cx,cy,h,w))
			{
				if(dfs(id+1, ph[id+1], pw[id+1]))
				{
					for(int i=0;i<bh;i++)
					{
						for(int j=0;j<bw;j++)
						{
							ans[aid][i][j]=board[i][j];
						}
					}
					if(chnprint(aid))
						aid++;
				}
				unvis(id);
			}
			
		}
		return 0;
}

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%d%d\n",&bh,&bw);
	
	aid=0;
	
	for(int i=0;i<bh;i++)
	{
		for(int j=0;j<bw;j++)
		{
			board[i][j]=int(getchar())-'0';
		}
		getchar();
	}
	getchar();
	pid=0;
	
	char c;
	
	c=getchar();
	if(c=='P')
	{
		int pre,ind;
		getchar();
		while(~scanf("%d",&pre))
		{
//			printf("pre %d\n",pre);
			switch(pre)
			{
				case 1  :
					ind=11;break;
				case 21 :
					ind=12;break;
				case 22 :
					ind=21;break;
				case 311:
					ind=13;break;
				case 312:
					ind=31;break;
				case 321:
					ind=100022;break;
				case 322:
					ind=10022;break;
				case 323:
					ind=122;break;
				case 324:
					ind=1022;break;
				case 411:
					ind=14;break;
				case 412:
					ind=41;break;
				case 471:
					ind=11000032;break;
				case 472:
					ind=1010023;break;
				case 473:
					ind=1132;break;
				case 474:
					ind=101023;break;
				case 491:
					ind=10100023;break;
				case 492:
					ind=1100032;break;
				case 493:
					ind=10123;break;
				case 494:
					ind=11032;break;
				case 431:
					ind=10132;break;
				case 432:
					ind=10001023;break;
				case 433:
					ind=10100032;break;
				case 434:
					ind=1000123;break;
				case 421:
					ind=10000123;break;
				case 422:
					ind=110032;break;
				case 451:
					ind=1001023;break;
				case 452:
					ind=10000132;break;
				case 400:
					ind=22;break;
			}
//			printf("ind %d\n",ind);
			ph[pid]=ind%10;
			ind/=10;
			pw[pid]=ind%10;
			ind/=10;
			
//			printf("ph %d pw %d\n",ph[pid],pw[pid]);
			for(int i=0;i<ph[pid];i++)
			{
				for(int j=0;j<pw[pid];j++)
				{
					piece[pid][i][j]=ind%10;
					ind/=10;
				}
			}
			pid++;
		}
	}
	else
	{
		ungetc(c,stdin);
		while(~scanf("%d%d",&ph[pid],&pw[pid]))
		{
			getchar();
			for(int i=0;i<ph[pid];i++)
			{
				for(int j=0;j<pw[pid];j++)
				{
					piece[pid][i][j]=int(getchar())-'0';
				}
				getchar();
			}
			pid++;
		}
	}
	
	//id ph pw
	dfs(0,ph[0],pw[0]);
}