#include<stdio.h>
#include<string.h>
int t,n,m,k1,k2;
typedef struct node
{
    char s[5];
    int id,camper,score,alive;
} node;
node player[105];
int killplayer[105][105];
int killcounter[105];

int ZGwin()
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(player[i].s,"ZG")==0&&player[i].alive==0)// ZG alive
            return 0;
        if(strcmp(player[i].s,"FZ")==0||strcmp(player[i].s,"NJ")==0) // FZ and NJ dead
        {
            if(player[i].alive)
                return 0;
        }
    }
    return 1;
}
int FZwin()
{
    int i;
    for(i=0; i<n; i++)
        if(strcmp(player[i].s,"ZG")==0&&player[i].alive==0)// ZG dead
            return 1;
    return 0;
}
//NJ kill ZG
//others all dead
int NJwin(int a,int b)
{
    int i;
    if(strcmp(player[a].s,"NJ")!=0||strcmp(player[b].s,"ZG")!=0)// NJ KILL ZG
        return 0;
    for(i=0; i<n; i++)
    {
        if(i==a||i==b)
            continue;
        if(player[i].alive==1)//other dead
            return 0;
    }
    return 1;
}


void calZGwin(int a,int b)
{
    int cntaliveZC=0,i,j;
    for(i=0; i<n; i++) //cal the number of alive ZC
    {
        if(strcmp(player[i].s,"ZC")==0&&player[i].alive)
            cntaliveZC++;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(player[i].s,"ZG")==0)//ZG points
            player[i].score=4+cntaliveZC*2;
        if(strcmp(player[i].s,"ZC")==0)
            player[i].score=5+cntaliveZC;

        //this op result to the end
        //so the last NJ or FZ must be b
        //so if b is NJ ,just judge the number of ZC
        //we can know solo or not
        if(strcmp(player[i].s,"NJ")==0&&i==b)
        {
            if(cntaliveZC!=0)
                player[i].score=0;
            else player[i].score=n;
        }
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(player[i].s,"ZG")==0||strcmp(player[i].s,"ZC")==0)
        {
            for(j=0; j<killcounter[i]; j++)
            {
                if(strcmp(player[killplayer[i][j]].s,"FZ")==0||strcmp(player[killplayer[i][j]].s,"NJ")==0)
                    player[i].score++;
            }
        }
    }
}
void calFZwin()
{
    int cntaliveFZ=0,i,j;
    for(i=0; i<n; i++) //cal the number of alive ZC
        if(strcmp(player[i].s,"FZ")==0&&player[i].alive)
            cntaliveFZ++;
    for(i=0; i<n; i++)
    {
        if(strcmp(player[i].s,"FZ")==0)
            player[i].score=cntaliveFZ*3;
        if(strcmp(player[i].s,"NJ")==0&&player[i].alive)
            player[i].score=1;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(player[i].s,"FZ")==0)
        {
            for(j=0; j<killcounter[i]; j++)
            {
                if(strcmp(player[killplayer[i][j]].s,"ZC")==0||strcmp(player[killplayer[i][j]].s,"NJ")==0)
                    player[i].score++;
                if(strcmp(player[killplayer[i][j]].s,"ZG")==0)
                    player[i].score+=2;
            }
        }
    }
}
void calNJwin()
{
    int i;
    for(i=0; i<n; i++)
    {
        if(strcmp(player[i].s,"ZG")==0)
            player[i].score=1;
        if(strcmp(player[i].s,"NJ")==0&&player[i].alive)
            player[i].score=4+n*2;
    }
}



int judge(int a,int b) // judge win
{
    if(ZGwin())
    {
        //cout<<"ZG win!!"<<endl;
        calZGwin(a,b);
        return 1;
    }
    if(NJwin(a,b))
    {
        //cout<<"NJ win!!"<<endl;
        calNJwin();
        return 1;
    }
    if(FZwin())
    {
        //cout<<"FZ win!!"<<endl;
        calFZwin();
        return 1;
    }
    return 0;
}
int cmp( const void *a , const void *b )
{
    struct node *c = (node *)a;
    struct node *d = (node *)b;
    if(c->score == d->score) return c->id - d->id;
    else return d->score - c->score;
}

int main()
{
    int cse,i,flag;
    scanf("%d",&t);
    for(cse = 1 ; cse <= t ; cse ++)
    {
        memset(killplayer,0,sizeof(killplayer));
        memset(killcounter,0,sizeof(killcounter));
        scanf("%d%d",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%s",player[i].s);
            player[i].id=i;
            player[i].alive=1;
            player[i].score=0;
        }
        flag=0;
        for(i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(flag)continue;
            player[b].alive=0;
            killplayer[a][killcounter[a]++]=b;
            if(judge(a,b))flag=1;
        }
        scanf("%d",&k1);
        for(i=0; i<k1; i++)
        {
            int id;
            scanf("%d",&id);
            player[id].camper=0;
        }
        scanf("%d",&k2);
        for(i=0; i<k2; i++)
        {
            int id;
            scanf("%d",&id);
            player[id].camper=1;
        }

        printf("Game %d:\n",cse);
        for(i=0; i<n; i++)
        {
            if(i!=0)printf(" ");
            printf("%d",player[i].score);
        }
        printf("\n");

        qsort(player,n,sizeof(player[0]),cmp);

        int sum[2],haveNJ[2];
        memset(sum,0,sizeof(sum));
        memset(haveNJ,0,sizeof(haveNJ));
        for(i=0;i<n;i++){
            if(i==0)sum[player[i].camper]+=3;
            if(i==1)sum[player[i].camper]+=2;
            if(i==2)sum[player[i].camper]+=1;
            sum[player[i].camper]+=player[i].score;
            if(strcmp(player[i].s,"NJ")==0)haveNJ[player[i].camper]=1;
        }
        for(i=0;i<2;i++)sum[i]+=haveNJ[i];
        printf("%d %d\n",sum[0],sum[1]);
        if(sum[0]>sum[1])
            printf("YZ WIN!\n");
        else if(sum[0]<sum[1])
            printf("NH WIN!\n");
        else printf("TIE!\n");
        printf("\n");
    }
    return 0;
}
