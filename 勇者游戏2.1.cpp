#include <stdlib.h>//��������Ϸ�������Ĳ��� 
#include <stdio.h>
#include <time.h> //suiji 
#include <string.h>
#include <conio.h>
#include <string>
#include <algorithm>
#include "stdlib.h"
#include <iomanip>
#include <ctime>
#include <cmath>
#include <windows.h> //SLEEP����
#include<iostream>
using namespace std; 
SYSTEMTIME Time;
struct Player 
{ 
char name[101]; 
int attack; 
int defense; 
int health; 
int mp; 
long int max_health; 
long int max_mp; 
int level; 
int exp; 
int range_exp; 
long int max_exp; 
float miss;
int max_miss;
}
tank={"̹��",25,75,250,75,250,75,1,0,0,100,0,0},
army={"սʿ",60,50,150,100,150,100,1,0,0,100,1,1},
ack={"�̿�",100,30,100,100,100,100,1,0,0,100,1,1},
mag={"��ʦ",75,40,120,250,120,250,1,0,0,100,1,1},
gun={"����",80,30,110,150,110,150,1,0,0,100,1,3},
player={"\0",0,0,0,0,0,0,0,0,0,0};
struct Enemy //�ֵĽṹ��,����ʼ�����ֹ�
{
char name[200];
char wupin[100];
long long attack;
int defense;
int health;
int max_health;
int money;
long int exp;
int wupin_sign;
int wupinpro;
int double_attack;
int miss;
}strongman={"ɭ�־���","�ƽ�ʥ��",50,60,600,500,200,100,1,2,1,1},
witch={"ɭ��Ů��","����",30,45,100,100,50,50,2,3,1,1},
xiyi={"ɭ������","����",12,30,80,80,30,35,3,4,2,1},
big_strongman={"ɭ�־�����","����Գ����",35*5,55*5,355*5,355*5,200*5,100*5,4,10,2,2},
lion={"��ԭ��ʨ","�����ý�",100,100,400,400,200,100,5,2,1,2},
horse={"��ԭҰ��","��Ѫ��",70,20,200,120,50,50,6,3,1,1}, 
bee={"��ԭ�Ʒ�","����",23,10,75,75,30,35,7,4,2,2},
stone={"ɽ����ʯ","����",15,50,100,100,50,20,0,5,2,2},
asshole={"ɽ���ջ�","ذ��",20,10,60,60,50,20,8,5,2,2},
cxy={"����Գ","����Գ��׹",100,200,2000,2000,500,300,17,5,1,0},
shitu={"������","����������",65*7,35*7,285*7,285*7,205*7,105*7,9,10,1,0},
wugui={"�޹�","���֮��",40,375,166*10,166*10,150,100,11,1,1,0},
shark={"������","��������",90,50,500,500,300,150,10,1,1,0},
Bman={"B_boomͶ��","B_boom",999999999,60,300,300,300,200,12,1,1,1},
fashu={"����","ħ������",150,20,250,250,300,200,13,8,1,1},
hongshi={"�ɺ�֮ʯ","�ɺ쾫��",100,100,500,500,100,100,20,8,1,1},
gushi={"Զ��֮ʯ","Զ�ž���",100,100,500,500,100,100,21,8,1,1},
ccm={"������","�������׹",200,30,300,300,300,200,18,5,1,0},
cnx={"������","����������",100*7,30*5,200*7,200*7,205*7,105*7,14,10,1,0},
ffk={"������","�����ϵ�׹",70,300,500,500,300,300,19,5,1,0},
fky={"������","�ܿ�ѧ������",25*7,500,300*7,300*7,205*7,105*7,15,10,1,0},
zk={"hzwer","\0",100*7,500,300*7,300*7,205*7,105*7,16,0,1,0},
guai={"\0","\0",0,0,0,0,0,0,0,0,0};
struct Place
{
int bar,hotel,forest1,forest2,forest3,grass1,grass2,grass3,mountain,mlgb,sea,mesh,fsyg,cnm,fky,jd,zysd;
}place={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
struct xiaohua
{
char name[21];
}xiaohua={"xiaohua"};
int max_exp=0;
int choose_number=0,s=0,strongman_arm=0,battle=0,money=1000,place_sign=11,jishu=0,jishu2=20,jishu3=1,huolianjishu=4;
int bbcy=0,bbcyn=100,pkzr=0,pkzrn=125,zhhc=0,zhhcn=175,dltxz=0,dltxzn=135,cqmsb=0,cqmsbn=150;
int wgbxs=0,wgbxsn=175,slgmt=0,slgmtn=120,slzsk=0,slzskn=75,hgysy=0,hgysyn=200,qlpfj=0,qlpfjn=75;
int cao=4,jijiubao=3,baiyao=3,superbaiyao=1,boom=4,dubiao=3,atom_boom=1,B=0,juan1=0,my=3;
int dbjs=0,yinxie=0,tjsww=0,lingpai0=0,lingpai1=0,lingpai2=0,lingpai3=0;
int honghua=0,guhua=0,juan2=0,juan3=0,fenshu=0,n=0,nn=0,nnn=0,nnnn=0,nnnnn=0,wrbsp=0,dhwj=0,dysls=0,fnhl=0,kfzx=0;
int fang=0,fang1=10,fang1n=0,fang2=20,fang2n=0,fang3=40,fang3n=0,fang4=80,fang4n=0,fang5=100,fang5n=0;
int gong=0,gong1=8,gong1n=0,gong2=15,gong2n=0,gong3=25,gong3n=0,gong4=60,gong4n=0,gong5=80,gong5n=0;
int diaozhui1nn=0,diaozhui2nn=0,diaozhui3nn=0,diaozhui1n=0,diaozhui1=200,diaozhui2n=0,diaozhui2=50,diaozhui3n=0,diaozhui3=70;
char gongname[20]="��",fangname[20]="��",diaozhui1name[20]="��",diaozhui2name[20]="��",diaozhui3name[20]="��",zyname[20]="��";
char proof;

void AddWupin(int);
int AttackResult();
void BattleAct();
void ChooseWupin();
void DisplayState();
void OrdinaryAct(); 
int SuiJi();
void MapForforest();
int SuiJi100();
void WhetherLevelUp();
void jingdutiao();
void SlowDisplay(char *); 
void MapForgrass();
void zhuangbei();
void Map();
void gotoxy(int,int);
void menu();
void MapFordangerous();
void MapForpeople();
void Boom();
int main()
{
jingdutiao();
system("color F0");
int i=0,j=0,k=0;
char player_name[101];
char xiaohua_name[101];
SlowDisplay("����һ�����˵��۵�ѧ������!\n\n ʦ��Сʱ��ʦ����ʦ�����˵�У������һȺ���ˣ��Ź֣������!\n\n ΰ���ѧ������~�������ǵĽڲ�,�������£�����������Ӫ��У��!\n\n\n");
printf("ѡ�����ְҵ��\n\n 1 ̹�� �⵽����\n\n 2 սʿ ��������\n\n 3 �̿� �������\n\n 4 ��ʦ ���޻ָ�\n\n 5 ���� ��������\n\n");
do
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:player=tank;n++;break;
case 2:player=army;nn++;break;
case 3:player=ack;nnn++;break;
case 4:player=mag;nnnn++;break;
case 5:player=gun;nnnnn++;break;
}
}
while(choose_number!=1&&choose_number!=2&&choose_number!=3&&choose_number!=4&&choose_number!=5);
printf("�������������У�������֣���һ����һ�»س���\n\n\n");
// sndPlaySound("res\\F005.wav",SND_LOOP);
scanf("%s",player_name); 
strncpy(player.name,player_name,20);
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("���Ӷ����hzwer��!�����ڻ�����!��ȥɱ���Ǹ�ð�ƻ��ɣ�\n\n\n     hzwer���³�ɽ... �漴... ����!!!\n\n\n");//���ҳ��� 
player.attack=999;
player.defense=999;
player.health=9999;
player.max_health=9999;
atom_boom++; 
lingpai3=10;
}
getchar();
scanf("%s",xiaohua_name); 
strncpy(xiaohua.name,xiaohua_name,20);
getchar();
jingdutiao();
OrdinaryAct();
return 0;
}

int SuiJi()
{
srand((unsigned)time(NULL));
return rand()%10;
}


int SuiJi100()
{
srand((unsigned)time(NULL));
return rand()%100; }

void zy()
{
printf("������:%d ְҵ��:%s\n\n\n ̹�˰��� 1\n\n\n ��ʦ���� 2\n\n\n ���ְ��� 3\n\n\n 0,����\n\n\n",fenshu,zyname);
switch(scanf("%d",&choose_number),choose_number)
{
case 3:
if(kfzx>=1&&huolianjishu>=1)
{
printf("BIU!!!!!!\n\n\n");
guai.health-=300;
huolianjishu--;
if(player.miss<player.max_miss)
{
player.miss+=0.1;	
}
else
{
player.miss=player.max_miss;
}
AttackResult();
}
else
SlowDisplay("���˰���\n\n\n");
break; 
case 1:
if(wrbsp>=1&&huolianjishu>=1)
{
if(jishu2>0)
{
SlowDisplay("�����֮��,������ǿһ��!!!��������������!!!\n\n\n");
jishu2--;
huolianjishu--;
guai.health-=250;
player.max_health+=20;
player.defense+=2;
AttackResult();
}
if(jishu2<=0)
{
huolianjishu--;
SlowDisplay("�����֮��,������ǿһ��!!!\n\n\n");
guai.health-=250;
AttackResult();
}
}
else
printf("���˰���\n\n\n");
break;
case 2:
if(fnhl>=1&&huolianjishu>=1)
{
printf("���%d�˺�,��ȡѪ,ħ%d\n\n\n",player.level/5+player.max_mp/2+player.attack/3,(player.level/5+player.max_mp/2+player.attack/3)/10,(player.level/5+player.max_mp/2+player.attack/3)/10);
guai.health-=player.level/5+player.max_mp/2+player.attack/3;
huolianjishu--;
if(player.health+(player.level/5+player.max_mp/2+player.attack/3)/10<player.max_health)
{
player.health+=(player.level/5+player.max_mp/2+player.attack/3)/10;
}
else
{
player.health=player.max_health;
}
if(player.mp+(player.level/5+player.max_mp/2+player.attack/3)/10<player.max_mp)
{
player.mp+=(player.level/5+player.max_mp/2+player.attack/3)/10;
}
else
{
player.mp=player.max_mp;
}
AttackResult();
}
else
SlowDisplay("���˰���\n\n\n");
break;
case 0:break;
}
}

void jineng()
{
printf("���ܣ�1���󱬾��� 2,��Ѫ 3,̫�������� 0,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:	
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(dbjs>0&&player.mp+diaozhui1nn/4>=30)
{
SlowDisplay("���ۼ�������\n\n\n");
guai.health-=150;
player.mp-=30;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
break;
case 2:	
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(yinxie>0&&player.mp+diaozhui1nn/4>=25)
{
printf("͵��%d����������\n\n\n",(player.health+diaozhui1nn+guai.health)/20);
guai.health-=100;
player.mp-=25;
if(player.health+(player.health+guai.health)/20>=player.max_health)
player.health=player.max_health;
else player.health+=(player.health+guai.health)/20;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
break;
case 3:	
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(tjsww>0&&player.mp+diaozhui1nn>=150)
{
SlowDisplay("���︴�գ�����������״̬�����������50���˺�������\n\n\n");
player.health=player.max_health;
player.mp-=150;
player.mp=player.max_mp;
guai.health-=50;
tjsww--;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
break;
case 0:break;
default:printf("����ѡ���ܣ�\n\n\n");
}
}
void ChooseWupin() //ѡ����Ʒ ��ʹ��
{
printf("��Ʒ: 1,ֹѪ��%d�� 2,���Ȱ�%d�� 3,���ϰ�ҩ%d�� 4,�������ϰ�ҩ%d�� 5,����%d�� 6,����%d�� 7,����ʽԭ�ӵ�%d�� 8,B_boom%d��\n\n\n 9,ħ������%d�� 10,�ɺ쾫��%d�� 11,�ɺ����%d�� 12,Զ�ž���%d�� 13,Զ�ž���%d�� 14,��ҩ%d�� \n\n\n15,����Գ����%d 16,����������%d 17,����������%d 18,�ܿ�ѧ������%d 0,����\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,B,juan1,honghua,juan2,guhua,juan3,my,lingpai0,lingpai1,lingpai2,lingpai3);
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(cao>0)
{
SlowDisplay("ʹ��ֹѪ��,HP����60\n\n\n");
cao--;
if(player.health+60>player.max_health)player.health=player.max_health;
else player.health+=60;
}
jingdutiao();
break;
case 2:
if(jijiubao>0)
{
SlowDisplay("ʹ�ü��Ȱ�,HP����80\n\n\n");
jijiubao--;
if(player.health+80>player.max_health)player.health=player.max_health;
else player.health+=80;
}
else SlowDisplay("û�м��Ȱ���\n\n\n");
jingdutiao();
break;
case 3:
if(baiyao>0)
{
SlowDisplay("ʹ�����ϰ�ҩ,HP����120\n\n\n");
baiyao--;
if(player.health+120>player.max_health)player.health=player.max_health;
else player.health+=120;
}
else SlowDisplay("û�����ϰ�ҩ��\n\n\n");
jingdutiao();
break;
case 4:
if(superbaiyao>0)
{
SlowDisplay("ʹ�ó������ϰ�ҩ,HP����200\n\n\n");
superbaiyao--;
if(player.health+200>player.max_health)player.health=player.max_health;
else player.health+=200;
}
else SlowDisplay("û�г������ϰ�ҩ��\n\n\n");
jingdutiao();
break;
case 5:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(boom>0)
{
SlowDisplay("ʹ������,����HP����100\n\n\n");
boom--;
guai.health-=100;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
else SlowDisplay("��ս��״̬,����ʹ������!\n\n\n");
jingdutiao();
break;
case 6:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(dubiao>0)
{
SlowDisplay("ʹ�ö���,����HP����200\n\n\n");
dubiao--;
guai.health-=200;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
else SlowDisplay("��ս��״̬,����ʹ�ö���!\n\n\n");
jingdutiao();
break;
case 7:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(atom_boom>0)
{
SlowDisplay("ʹ������ʽԭ�ӵ�,����HP����500\n\n\n");
atom_boom--;
guai.health-=500;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
else SlowDisplay("��ս��״̬,����ʹ������ʽԭ�ӵ�!\n\n\n");
jingdutiao();
break;
case 8:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(B>0)
{
Boom();
B--;
guai.health-=1666;
AttackResult();
}
else
{
printf("���˰���\n\n\n");
}
}
else SlowDisplay("��ս��״̬,����ʹ��Bboom!\n\n\n");
jingdutiao();
break;
case 9:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 10:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 11:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 12:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 13:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 14:
if(my>0)
{
SlowDisplay("ʹ����ҩ,MP����30\n\n\n");
my--;
if(player.mp+30>player.max_mp)player.mp=player.max_mp;
else player.mp+=30;
jingdutiao();
}
else SlowDisplay("û����ҩ��\n\n\n");
jingdutiao();
break;
case 15:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 16:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 17:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 18:
SlowDisplay("����ܻ����õ�\n\n\n");
jingdutiao();
break;
case 0:
jingdutiao();
break;
default:printf("ChooseWupin error!\n\n\n");
}
}
int AttackResult() //�������:�ж��Ƿ��ʤ �Ƿ�����Ʒ �� �Ƿ�����
{
if(guai.health<=0)
{
battle=0;
printf("ս��ʤ��!��ý��%d,����%d\n\n\n",guai.money,guai.exp);
SlowDisplay(" ");
jishu3=1;
huolianjishu=4;
player.exp+=guai.exp;
player.range_exp+=guai.exp;
fenshu++;
money+=guai.money; s=SuiJi();
if(s<guai.wupinpro)
{
printf("%s������",guai.name);
printf("%s\n\n\n",guai.wupin);
SlowDisplay(" ");
AddWupin(guai.wupin_sign);
}
WhetherLevelUp();
jingdutiao();
if(strcmp(guai.name,"hzwer")==0)
{
SlowDisplay("ɱ������:");
printf("%d\t\t",fenshu);
SlowDisplay("���յȼ�:");
printf("%d\t\t",player.level);
SlowDisplay("�������:");
printf("%d\n\n\n",money);
printf("ս��ʤ�����ȳ����У��Ů��%s!!!\n\n\n",xiaohua.name);
getchar();
getchar();
exit(0);
}
return 1; //�����н���˷���1,���򷵻�0,�����ж��Ƿ������ս����Ϊ
}
else 
{
int s=SuiJi();
if(s>=player.miss)
{
if((guai.attack+s-(player.defense+fang+diaozhui3)/3)<0)
{
player.health-=1;
printf("%s����,���HP������ 1\n\n",guai.name);
}
else
{
player.health-=guai.attack+s-(player.defense+fang+diaozhui3nn)/3;
printf("%s����,���HP������%d\n\n",guai.name,guai.attack+s-(player.defense+fang+diaozhui3nn)/3);
}
}
else
{
printf("%s",player.name);
SlowDisplay("����!!!\n\n\n");
}
if(player.health+diaozhui1nn<=0)
{
if(dhwj>=1&&jishu3>=1)
{
SlowDisplay("Զ��ս���Ӣ��ʹ�㲻������,���");
printf("%d",(player.max_health+diaozhui1nn)/4);
SlowDisplay("����ֵ������\n\n\n");
player.health=0;
player.health+=(player.max_health+diaozhui1nn)/4;
jishu3--;
}
else
{
battle=0;
printf("%sս��!��ҵ���%d\n\n\n",player.name,player.level*500);
jingdutiao();
jishu3=1;
huolianjishu=4;
if(money<player.level*500)
{
money=0;
}
else
{
money-=player.level*500;
}
player.health=player.max_health/5;
OrdinaryAct();//////////
return 1;
}
}
}
return 0;
}
void AddWupin(int wupin_sign)
{

switch(wupin_sign)
{
case 0:fang1n++; break;
case 1:fang4n++; break;
case 2:fang3n++; break;
case 3:fang2n++; break;
case 4:lingpai0=1;break;
case 5:gong4n++; break;
case 6:gong3n++; break;
case 7:gong2n++; break;
case 8:gong1n++; break;
case 9:lingpai1=1; break;
case 10:gong5n++; break;
case 11:fang5n++; break;
case 12:B++; break;
case 13:juan1++; break;
case 14:lingpai2=1;break;
case 15:lingpai3=1;break;
case 17:diaozhui1n++;break;
case 18:diaozhui2n++;break;
case 19:diaozhui3n++;break;
case 20:honghua++;break;
case 21:guhua++;break;
default:printf("AddWupin error\n\n\n");
}

}
void WhetherLevelUp()
{
int i=0,j=0;
int l1=player.range_exp/100;
int l2=player.range_exp/300;
int l3=player.range_exp/600;
if(player.level<=15&&l1>0) //15������,�����㹻 ������������
{
if(l1==1)
{
printf("%s",player.name);
SlowDisplay(" ����!\n\n\n������+3, ������+2, HP����+20, MP����+10\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3;
player.defense+=2;
player.max_health+=20;
player.max_mp+=10;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=100;
}
else
{
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d, MP����+%d\n\n\n",3*l1,2*l1,20*l1,10*l1);
SlowDisplay(" ");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3*l1;
player.defense+=2*l1;
player.max_health+=20*l1;
player.max_mp+=10*l1;
player.level+=l1;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=100*l1;
}
}
else if(player.level<=40&&l2>0)
{
if(l2==1) {
printf("%s",player.name);
SlowDisplay(" ����!\n\n\n������+3, ������+2, HP����+20, MP����+10\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3;
player.defense+=2;
player.max_health+=20;
player.max_mp+=10;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=300;
}
else
{
printf("������!����%d��!",l2);
printf("������+%d, ������+%d, HP����+%d, MP����+%d\n\n\n",3*l2,2*l2,20*l2,10*l2);
SlowDisplay(" ");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3*l2;
player.defense+=2*l2;
player.max_health+=20*l2;
player.max_mp+=10*l2;
player.level+=l2;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=300*l2;
}
}
else if(l3>0)
{
if(l3==1)
{
printf("%s",player.name);
SlowDisplay(" ����!\n\n\n������+3, ������+2, HP����+20, MP����+10\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3;
player.defense+=2;
player.max_health+=20;
player.max_mp+=10;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=600;
}
else
{
printf("������!����%d��!",l3);
printf("������+%d, ������+%d, HP����+%d, MP����+10\n\n\n",3*l3,2*l3,20*l3,10*l3);
SlowDisplay(" ");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3*l3;
player.defense+=2*l3;
player.max_health+=20*l3;
player.max_mp+=10;
player.level+=l3;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=600*l3;
}
}
}
void OrdinaryAct() //������Ϊ�˵�(�ƶ�,��Ʒ,�Ի�,�鿴״̬,װ��,�˳���Ϸ)
{

while(1)
{
// \(1000);
// system("cls");
Map();
printf("\n�˵�(m)\t�˳�(o)\t��������(u)\t�������ֽ̳�(j)\nĿǰ�еĵط����ذ�0(�����),�еİ�o(���ͼ),���ǻᾡ���޸�\n");
switch(scanf("%s",&choose_number),choose_number)
{ 
case 'j':
SlowDisplay("��һ����Ҫ��Ϊ�������ֵ����ִ���D����\n��һ���ļ�����Ϊ�ҵ�����,��������\n������Ϊ01.mp3,02.mp3�ȵ�,ֻ���ڴ����и�д������\n");
SlowDisplay("��ʽ:\n������(��д):\\(��������Զ���һ��,�����ֻдһ���ͻᱻ��)�����ļ���\\�ļ���.mp3\n");
SlowDisplay("�Ƽ���������:\n��she is my sin��(ʵ����)\n��we are electric��(ʵ����)\n��victory��(����ʹ��)\n��he s a pirate��(����ʹ��)\n��barbarbar��(����)\n��pacific rim��\n��smooth criminal��(����)\n��the dawn��(����ʹ��)\n��moves like jagger��(����,����ʹ��,����Ϸ��˵Ҳ��)\n��the mass��(�����󻬻�,�¾�װ�ױ�������)\n��highscore��\n��invincible-xray dog��(����,³�����ͬ��)\n��girlfriend��(�󻬻�,ż���Ľ�˵��)\n�������Ⱥ�\n");
SlowDisplay("�ǵð����õ����ֲ�������Ϊ����ѭ��Ŷ!!!!\n");
SlowDisplay("Do you get it??????????????????\n");
SlowDisplay("���ڼ�������,������ʱ���������߼���������Ч��,�������!!!O(��_��)O�Ϲ���л!!!! ");
jingdutiao();
break;
case 'u':
system("D:\\�ҵ�����\\03.mp3.mp3");//��������������������������� 
cin.get();
jingdutiao();
break;
case 'o': 
SlowDisplay("ȷ���Ƴ���Ϸ?(Y/N)\n\n\n");
getchar();
proof=getchar();
if(proof=='y'||proof=='Y')
{
SlowDisplay("���ݴ洢��...");
//���ļ��и�������;
getchar();
SlowDisplay("���س��˳�");
getchar();
return;
}
else if(proof=='n'||proof=='N')printf("������Ϸ!\n\n\n");
else SlowDisplay("����!\n\n\n");
jingdutiao();
break;
case 'm':
menu();
break;
case 'f':
jingdutiao();
system("color 2F");
MapForforest(); 
switch(scanf("%s",&choose_number),choose_number)
{
case 'o':
jingdutiao();
break;
case 'm':
menu();
break;
case 'f':
place_sign=place.forest1;
s=SuiJi(); 
if(s<7)
{
jingdutiao();
battle=1;
guai=xiyi;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=witch;
printf("%sƮ�˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
//���õ���OAct����,���Զ�ִ��OAct����;
}
break;
case 's':
place_sign=place.forest2;
s=SuiJi(); 
if(s<7)
{
jingdutiao();
battle=1;
guai=witch;
printf("%sƮ�˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=strongman;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 't':
place_sign=place.forest3;
s=SuiJi(); 
if(s<7)
{
jingdutiao();
battle=1;
guai=strongman;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=big_strongman;
SlowDisplay("һ�������ɭ���л��죺�ˣ������ˣ������ˣ������漴ɭ�־��������˹���������\n\n\n");
BattleAct();0;
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
default:
SlowDisplay("������(����)");
jingdutiao(); 
}
break;
case 'd':
jingdutiao();
if(lingpai0!=1)
{
jingdutiao();
SlowDisplay("�㻹̫��\n\n\n");
jingdutiao();
break; 
}
else 
jingdutiao();
MapFordangerous();
switch(scanf("%s",&choose_number),choose_number)
{
case 's':
jingdutiao();
place_sign=place.jd;
system("color 0F");
s=SuiJi(); 
if(s<7)
{
printf("%sʲôҲ������\n\n\n",player.name);
SlowDisplay(" ");
jingdutiao();
}
else if(s<9)
{
battle=1; 
if(lingpai3)
{
SlowDisplay("hzwer:\n\n\n ����ҾͿ��Ծȳ�У��������\n\n\n");
guai=zk;
printf("%s���˹���!\n\n\n",guai.name);
SlowDisplay("һ����������������B����boom��ʹ��\n\n\n"); 
B=0;
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("hzwer���Ŷ����Ǹ����Լ�һ�����ˣ�������һ�δ��룬�Է���ʱ�ҷ�����");
Boom();
}
BattleAct();
}
else SlowDisplay("hzwer:\n\n\n ������,��ð�.��������ҵ�����,�ҿ��Ը�����У��������Ŷ~\n\n\n");
jingdutiao();
}
break;
case 'f':
jingdutiao();
place_sign=place.fky;
system("color 90");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=ffk;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1; 
if(lingpai2)
{
SlowDisplay("������:\n\n\n ���У���������ѽ����\n\n\n");
guai=fky;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("������:\n\n\n ������,��ð�.������з���������,�ҿ��Ը�����У��������Ŷ~\n\n\n");
jingdutiao();
}
break;
case 'j':
jingdutiao();
place_sign=place.mesh;
system("color 0C");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=Bman;
printf("%s��������!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("����������%s������\n\n\n",player.name);
player.health=player.health-15;
SlowDisplay(" ");
jingdutiao();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 'l':
jingdutiao();
place_sign=place.mlgb;
system("color E0");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=cxy;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1; 
if(lingpai0)
{
SlowDisplay("������:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!����Գ������Ҫ��,У����Ҳ�������!\n\n\n");
guai=shitu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("������:\n\n\n ������,��ð�.������г���Գ����,�ҿ��Ը�����У��������Ŷ~\n\n\n");
jingdutiao();
}
break;
case 'o':
jingdutiao();
break;
case 'm':
menu();
break;
default:
SlowDisplay("������(����)");
jingdutiao(); 
}
break;
case 'g':
jingdutiao();
system("color B0");
MapForgrass();
switch(scanf("%s",&choose_number),choose_number)
{
case 'o':
jingdutiao();
break;
case 'm':
menu();
break;
case 't':
jingdutiao();
place_sign=place.grass3;
s=SuiJi(); 
if(s<7)
{
jingdutiao();
battle=1;
guai=lion;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 's':
place_sign=place.grass2;
s=SuiJi(); 
if(s<7)
{
jingdutiao();
battle=1;
guai=horse;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct(); }
else if(s<9)
{
jingdutiao();
battle=1;
guai=lion;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 'f':
place_sign=place.grass1;
s=SuiJi(); 
if(s<7)
{
jingdutiao();
battle=1;
guai=bee;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=horse;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
default:
SlowDisplay("������(����)");
jingdutiao(); 
}
break;
case 'k':
jingdutiao();
place_sign=place.fsyg;
system("color D0");
s=SuiJi(); 
if(s<3)
{
battle=1;
guai=fashu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<6)
{
battle=1;
guai=hongshi;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=gushi;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 'h':
jingdutiao();	
place_sign=place.mountain;
system("color 70");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=asshole;
printf("%sŲ�˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=stone;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 's':
jingdutiao();
system("color 3F");
place_sign=place.sea;
s=SuiJi(); 
if(s<4)
{
battle=1;
guai=wugui;
SlowDisplay("��.....��.....��.....һ.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....\n\n\n");
BattleAct();
}
else if(s<8)
{
battle=1;
guai=shark;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("һ�����˴��˹���������%s����С��\n\n\n",player.name);
SlowDisplay(" ");
player.health=player.health-5;
jingdutiao();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
jingdutiao();
}
break;
case 'p':
jingdutiao();
system("color 6F");
MapForpeople();
switch(scanf("%s",&choose_number),choose_number)
{
case 'o':
jingdutiao();
break;
case 's':
jingdutiao();
printf("��ʿ,��ʲô��:1,����ְҵ���� 2,����ְҵ����װ�� 0,����\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 2:
printf("̹��ר�� 1 �Աڴ���\t\t2 ��Ų�����\n\n\nսʿר�� 3 �ƿ�֮��\t\t4 ʥ�������\n\n\n�̿�ר�� 5 ׷��ô�\t\t6 �������ֿ�\n\n\n��ʦר�� 7 ����������\t\t8 �ù�ҫ����\n\n\n����ר�� 9 ���������\t\t10 ǧ���Ʒ羵\n\n\n0,����\t����������Դ����Ϸ��С˵\n\n\n");
printf("PS:ͳһ��:300000\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 0:
SlowDisplay("����!!!\n\n\n");
jingdutiao();
break;
}
}
break;
case 1:
printf("1 ̹��ר�� �����ɽ��(��������) \n\n\n2 սʿר�� Զ����־(��������) \n\n\n3 �̿�ר�� ����֮��(������Ѫ)\n\n\n4 ��ʦר�� ��ŭ����(��ħ��Ѫ) \n\n\n5 ����ר�� ���֮Ϣ(���ܼӳ�) \n\n\n0 ���� ���ϼ�����Դ����Ϸ��С˵\n\n\n"); 
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(n==1&&jishu!=1)
{
SlowDisplay("����ɹ�\n\n\n");
wrbsp++;
n++;
jishu==1;
strcpy(zyname,"�����ɽ��");
}
else
SlowDisplay("����\n\n\n");
break;
case 2:
if(nn==1)
{
SlowDisplay("����ɹ�\n\n\n");
dhwj++;
nn++;
strcpy(zyname,"Զ����־");
}
else
SlowDisplay("����\n\n\n");
break;
case 3:
if(nnn==1)
{
SlowDisplay("����ɹ�\n\n\n");
dysls++;
nnn++;
strcpy(zyname,"����֮��");
}
else
SlowDisplay("����\n\n\n");
break;
case 4:
if(nnnn==1)
{
SlowDisplay("����ɹ�\n\n\n");
fnhl++;
nnnn++;
strcpy(zyname,"��ŭ����");
}
else
SlowDisplay("����\n\n\n");
break;
case 5:
if(nnnnn==1)
{
SlowDisplay("����ɹ�\n\n\n");
kfzx++;
nnnnn++;
strcpy(zyname,"���֮Ϣ");
}
else
SlowDisplay("����\n\n\n");
break;
case 0:
SlowDisplay("����!!!\n\n\n");
jingdutiao();
break;
}
}
break;
case 0:
SlowDisplay("����!!!\n\n\n");
jingdutiao();
break;
}
}
break;
case 'm':
menu();
break;
case 'h':
jingdutiao();
SlowDisplay("Ҫס����? 500����� 1,�� 0,��\n\n\n");
choose_number=1;
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money-500<0) //�ж�Ǯ�Ƿ�
{
SlowDisplay("Sorry,���Ǯ����~\n\n\n"); 
jingdutiao();
}
else 
{
SlowDisplay("�ú���Ϣ\n\tHP��,MP��\n\t\t�ڶ�����\n\n");
money-=500; //����200ס���
player.health=player.max_health;
player.mp=player.max_mp;//������
jingdutiao();
}
break;
case 0:SlowDisplay("�´�����!\n\n\n");
jingdutiao();break;
default:printf("hotel talk error!\n\n\n");system("cls");
}
break;
case 'j':
printf("1,������Ա 2,������־ 0,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{ 
case 1:
{
jingdutiao();
SlowDisplay("\n\n\n ����������\n\n");
SlowDisplay(" ���ܿ�ѧ��\n\n");
SlowDisplay(" �ı���\n\n");
SlowDisplay(" ����� ����\n\n");
SlowDisplay(" ����\n\n");
SlowDisplay(" �����\n\n");
SlowDisplay(" �����ƶ�\n\n");
SlowDisplay(" ����\n\n");
SlowDisplay(" ��л\n\n");
SlowDisplay(" ֣������ʦ ���ܿ�ѧ�� ������\n\n");
SlowDisplay(" ������Ϸ,��л��ҵ�֧��!!!O(��_��)O�Ϲ���л!!!! "); 
jingdutiao();
}
break;
case 2:
{
jingdutiao();
SlowDisplay("\n\n\n������־:\n\n");
SlowDisplay(" �����˳������ӻ�\n\n");
SlowDisplay(" ��Ϸ������Ż�\n\n");
SlowDisplay(" ְҵ������\n\n");
SlowDisplay(" ְҵװ����ΪԤ��ų�\n\n");
SlowDisplay(" ��ʱȡ��ˮս����\n\n");
SlowDisplay(" սʿ���ֶ�λ�޸�\n\n");
SlowDisplay(" ���󾯸�Ż���Ϸ������\n\n");
SlowDisplay(" ��������ϵͳ����\n\n");
SlowDisplay(" �����ʲô���������9018ƽ̨�Ͽ����۰�Ŷ\n\n");
SlowDisplay(" һ���ڴ���һ���汾�ĵ���!!!(��һ����汾���ƻ���2.6/7����)\n\n");
SlowDisplay(" ������Ϸ,��л��ҵ�֧��!!!O(��_��)O�Ϲ���л!!!! "); 
jingdutiao();
}
break;
case 0:
jingdutiao();
break;
}
break;
case 'b':
jingdutiao();
place_sign=place.bar;
printf("Ҫ��˭˵��?\n\n\n1,�췢Ů�� 2,�ͽ����� 3,�ư��ϰ� 4,��ʦ 5,���յ��ϰ� 0,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 5:
printf("�����������������һ���\n1 ذ�� 2 ���� 50��� \n3 ���� 4 ���� 100��� \n5 ��Ѫ�� 6 ���� 300��� \n7 �����ý� 8 �ƽ�ʥ�� 750���\n0 ����\n\n\n"); 
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(gong1n>=2)
{
SlowDisplay("��Ҽ�50.\n");
gong1n--;
money+=50;
}
else 
{
SlowDisplay("ذ�ײ���\n");
}
break;
case 2:
if(fang1n>=2)
{
SlowDisplay("��Ҽ�50.\n");
fang1n--;
money+=50;
}
else 
{
SlowDisplay("���²���\n");
}
break; 
case 3:if(gong2n>=2)
{
SlowDisplay("��Ҽ�100.\n");
gong2n--;
money+=100;
}
else 
{
SlowDisplay("��������\n");
}
break; 
case 4:if(fang2n>=2)
{
SlowDisplay("��Ҽ�100.\n");
fang2n--;
money+=100;
}
else 
{
SlowDisplay("���ײ���\n");
}
break; 
case 5:if(gong3n>=2)
{
SlowDisplay("��Ҽ�300.\n");
gong3n--;
money+=300;
}
else 
{
SlowDisplay("��Ѫ������\n");
}
break; 
case 6:if(fang3n>=2)
{
SlowDisplay("��Ҽ�300.\n");
fang3n--;
money+=300;
}
else 
{
SlowDisplay("���ײ���\n");
}
break; 
case 7:if(gong4n>=2)
{
SlowDisplay("��Ҽ�750.\n");
gong4n--;
money+=750;
}
else 
{
SlowDisplay("�����ý�����\n");
}
break; 
case 8:if(fang4n>=2)
{
SlowDisplay("��Ҽ�750.\n");
fang4n--;
money+=750;
}
else 
{
SlowDisplay("�ƽ�ʥ�²���\n");
}
break; 
case 0:
SlowDisplay("�´�����������");
jingdutiao();
break; 
}
case 0:
jingdutiao();
break;
case 1:
SlowDisplay("�췢Ů��:\n\n\n ��̨���Ǹ�Hunter��˧��!(~����~)\n\n\n��˵�������������,�����·��Ӧ�ú���Ϥ��!\n\n\n");
jingdutiao();
break;
case 2:
if(player.level<=30)
SlowDisplay("�ͽ�����:\n\n\n ������!\n\n\n ����Ҫ��ɽ����Ĺ��޿�ʼ��\n\n\n ���ɭ������ľ�����!\n\n\n �����4λ���˲ſ��ԾȻ�У��!\n\n\n");
jingdutiao();
if(player.level>30)
SlowDisplay("�ͽ�����:\n\n\n FUCK ����������������������������������������ôǿ�ˣ������Ҹ���\n\n\n");
jingdutiao();
break;
case 3:
printf("Ҫ�ȵ�ʲô?\n\n\n 1,����ͷ20��� HP+20 2,XO��80��� HP+50 3,��ͷ����150��� HP+100 0,�뿪\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<20)
{
SlowDisplay("Ǯ����!\n\n\n"); 
}
else
{
if(player.health+20<=player.max_health)
{
SlowDisplay("HP+20.\n\n\n");
money-=20;
player.health+=20;
}
else
{
SlowDisplay("HP����\n\n\n"); 
player.health=player.max_health;
}
}
break;
case 2:if(money<100)
{
SlowDisplay("Ǯ����!\n\n\n"); 
}
else
{
if(player.health+80<=player.max_health)
{
SlowDisplay("HP+80.\n\n\n");
money-=100;
player.health+=80;
} else
{
SlowDisplay("HP����\n\n\n"); 
player.health=player.max_health;
}
}
break;
case 3:if(money<200)
{
SlowDisplay("Ǯ����!\n\n\n"); 
}
else
{
if(player.health+150<=player.max_health)
{
SlowDisplay("HP+150.\n\n\n");
money-=200;
player.health+=150;
}
else
{
SlowDisplay("HP����\n\n\n"); 
player.health=player.max_health;
}
}
break;
case 0:SlowDisplay("�´�����!\n");
jingdutiao();
break;
}
}
break;
case 4:
printf("��Щ�����������Ƶ��ķ���\n\n 1����ҩ 10��ң���ħ30\n\n 2,ħ������ 500���\n\n 3,�ɺ���� ħ������+�ɺ쾫��\n\n 4,Զ�ž��� ħ������+Զ�ž���\n\n 5�󱬾��� �˺�150 ��ħ30 �ȼ�Ҫ��15 ħ����������10\n\n 6,��Ѫ �˺�100 ��ħ25 �ȼ�Ҫ��25 �ɺ��������14 ͵��һ������\n\n 7,̫�������� �˺�50 ��ħ150 �ȼ�Ҫ��50 Զ�ž�������20 ״̬ȫ�� �����Է���\n\n 0���뿪\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<10)
{
SlowDisplay("Ǯ����!\n\n\n"); 
}
else
{
if(player.mp+diaozhui1nn/4+30<=diaozhui1nn/4+player.max_mp)
{
SlowDisplay("MP+20.\n\n\n");
money-=10;
player.mp+=30;
}
else
{
SlowDisplay("MP����\n\n\n"); 
player.mp=player.max_mp;
}
}
break;
case 2:
{
if(money<500)
{
SlowDisplay("Ǯ������\n\n\n");
}
else
{
printf("���������\n\n\n");
money-=500;
juan1++;
}
}
break;
case 3:
if(juan1<1||honghua<1)
{
SlowDisplay("���ϲ�����\n\n\n");
}
else if(juan1>=1&&honghua>=1)
{
printf("�ϳ����ɺ���ᣡ\n\n\n");
juan1--;
honghua--;
juan2++;
}
break;
case 4:
if(juan1<1||guhua<1)
{
SlowDisplay("���ϲ�����\n\n\n");
}
else if(juan1>=1&&guhua>=1)
{
printf("�ϳ���Զ�ž��ᣡ\n\n\n");
juan1--;
guhua--;
juan3++;
}
break;
{
case 5:if(player.level<15||juan1<10)
{
SlowDisplay("�������������!\n\n\n"); 
}
else
{
if(player.level>=15&&juan1>=10)
{
SlowDisplay("�����ķ������Ժ�\n\n\n");
juan1-=10;
dbjs++;
}
}
break;
case 6:if(player.level<25||juan2<14)
{
SlowDisplay("��������������������!\n\n\n"); 
}
else
{
if(player.level>=25&&juan2>=14)
{
SlowDisplay("�ֲ������������л���\n\n\n");
juan2-=14;
yinxie++;
}
}
break;
case 7:if(player.level<50||juan3<20)
{
SlowDisplay("�������������!\n\n\n"); 
}
else
{
if(player.level>=50&&juan3>=20)
{
SlowDisplay("���˵Ļ�Ӱ���ĸ���\n\n\n");
juan3-=20;
tjsww++;
}
}
break;
case 0:SlowDisplay("ȥ�ɣ����ͣ�����\n\n\n");
jingdutiao();
break;
}
}
}
}
break;
}
break;
default:
SlowDisplay("������(����)");
jingdutiao(); 
}
} 
}
void DisplayState()
{
printf("%s ������:%d+%d+%d=%d ������:%d+%d+%d=%d HP:%d/%d MP:%d/%d ����:%f\n\n\n",player.name,player.attack,gong,diaozhui2nn,player.attack+gong+diaozhui2nn,player.defense,fang,diaozhui3nn,player.defense+fang+diaozhui3nn,player.health+diaozhui1nn,player.max_health+diaozhui1nn,player.mp+diaozhui1nn/4,player.max_mp+diaozhui1nn/4,player.miss);
printf("����: %s ����: %s ��Ʒ:%s %s %s\n\n\n",gongname,fangname,diaozhui1name,diaozhui2name,diaozhui3name);
printf("�ȼ�:%d ����:%d/%d ����Ҫ%d�������� ���:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money); 
printf("0 ���� \n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 0:
jingdutiao();
break;
}
}
void BattleAct()
{
while(1)
{
puts("=============================================================================");
printf("Ҫ��ô��?\n\n\n 1,���� 2,��Ʒ 3,�鿴״̬ 4,���� 5,ְҵר�� 6,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
s=SuiJi();
if(s>=guai.miss)
{
if(dysls>=1&&player.health<=player.max_health/3)
{
SlowDisplay("Դ��Ѫ�����������׾���!!!!����������1/4!!!\n\n\n");
guai.health-=player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3;
player.health+=(player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3)/3;
printf ("��%s���%d�˺�!!!��ȡ%d����!!!\n\n\n",guai.name,player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3,(player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3)/3);
}
else
{
printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,player.attack+s+gong+diaozhui2nn-guai.defense/3);
guai.health-=player.attack+s+gong+diaozhui2nn-guai.defense/3;
}
}
else SlowDisplay("û���У�����\n\n\n");
if(AttackResult())return; //��������н��(���˻����ս��)�˳�����
else continue; 
case 2: ChooseWupin();break; //ѡ����Ʒ,����ʹ��,ս��������ʹ�ù�������Ʒ
case 3:DisplayState();break; //��ʾ״̬
case 4:jineng();break;
case 5:zy();break;
case 6:
s=SuiJi();
if(s<4) //40%�ĸ��ʿ�������
{
printf("%s������~\n\n\n",player.name);
battle=0;
jishu3=1;
huolianjishu=4;
jingdutiao();
return;
}
else printf("%s����ʧ��!��ˤ����!��ʧ5����!!\n\n\n",player.name);
SlowDisplay(" \n");
if(player.health>5)
{ 
player.health-=5;
break;
} 
else
{
battle=0;
printf("%sˤ����,��ҵ���%d.....\n\n\n",player.name,player.level*5);
puts("o(�s���t)o ");
jingdutiao();
jishu3=1;
if(money<player.level*5)
{
money=0;
}
else
{
money-=player.level*5;
}
player.health=player.max_health/5;
OrdinaryAct();//////////
} 
break;
default:SlowDisplay("�������,��������!\n\n\n");
}
}
}
void SlowDisplay(char *p)
{
while(1)
{
if(*p!=0)
printf("%c",*p++);
else 
break;
Sleep(75);
}
}
void gotoxy(int x, int y)
{
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c = { y, x };
SetConsoleCursorPosition(hOut, c);
} 
void menu()
{
jingdutiao();
printf("\n\n\n\t\t\t\t1,��Ʒ\n\n\t\t\t\t2,װ��\n\n\t\t\t\t3,״̬\n\n\t\t\t\t0,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
ChooseWupin();
break;
case 3:
DisplayState();
break;
case 2:
zhuangbei();
break;
case 0: 
jingdutiao();
break;
}
}
void Map()
{
system("color F0");
gotoxy(2,30);printf("��(g):��ԭ����");gotoxy(10,20);printf("��(h):ɽ������");
gotoxy(1,1);printf("�������ı�����(p)");gotoxy(5,52);printf("��(f):ɭ������");
gotoxy(4,4);printf("�����Ĺ�(k)");gotoxy(15,50);printf("Σ������(d)");gotoxy(15,10);printf("�߽纣(s)");
printf("\n\n\n\n");
}
void MapForforest()
{
	gotoxy(7,15);printf("ɭ��һ��(f)");gotoxy(14,9);printf("ɭ�ֶ���(s)");gotoxy(12,50);printf("ɭ������(t)");
printf("\n\n\n\n\n\n\n\n\n");
printf("����(o)\n\n\n");
}
void MapForgrass()
{
gotoxy(7,25);printf("��ԭһ��(f)");gotoxy(17,9);printf("��ԭ����(s)");gotoxy(12,50);printf("��ԭ����(t)");
printf("\n\n\n\n\n\n\n\n\n");
printf("����(o)\n\n\n");
}
void MapForpeople()
{
gotoxy(7,25);printf("�ư�(b)");gotoxy(10,7);printf("�õ�(h)");gotoxy(15,50);printf("������Ϸ������(j)");gotoxy(3,3);printf("ְҵ���(s)");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("����(o)\n\n\n");
}
void zhuangbei()
{
jingdutiao();
printf("��װ: 1,ذ��:%d�� 2,����:%d�� 3,��Ѫ��:%d�� 4,�����ý�:%d�� 9,��������:%d��\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
printf("��װ: 5,����:%d�� 6,����:%d�� 7,����:%d�� 8,�ƽ�ʥ��:%d�� 10,���֮��:%d��\t\t0,����\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
printf("��Ʒ��11,����Գ��׹%d(����,����) 12���������׹%d�������� 13�������ϵ�׹%d��������\n\n\n",diaozhui1n,diaozhui2n,diaozhui3n);
SlowDisplay("ѡ��Ҫװ�������������:\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(gong1n>=1)
{
SlowDisplay("������ذ��\n\n\n");
gong=gong1;
strcpy(gongname,"ذ��");
jingdutiao();
}
else SlowDisplay("��û��ذ�׿���װ��\n\n\n");
jingdutiao();
break;
case 2:if(gong2n>=1)
{
SlowDisplay("�����˳���\n\n\n");
gong=gong2;
strcpy(gongname,"����");
jingdutiao();
}
else SlowDisplay("��û�г�������װ��\n\n\n");
jingdutiao();
break;
case 3:if(gong3n>=1)
{
SlowDisplay("�����˱�Ѫ��\n\n\n");
gong=gong3;
strcpy(gongname,"��Ѫ��");
jingdutiao();
}
else SlowDisplay("��û�б�Ѫ������װ��\n\n\n");
jingdutiao();
break;
case 4:if(gong4n>=1)
{
SlowDisplay("�����˾����ý�\n\n\n");
gong=gong4;
strcpy(gongname,"�����ý�");
jingdutiao();
}
else SlowDisplay("��û�о����ý�����װ��\n\n\n");
jingdutiao();
break;
case 5:if(fang1n>=1)
{
SlowDisplay("�����˲���\n\n\n");
fang=fang1;
strcpy(fangname,"����");
jingdutiao();
}
else SlowDisplay("��û�в��¿���װ��\n\n\n");
jingdutiao();
break;
case 6:if(fang2>=1) 
{
SlowDisplay("����������\n\n\n");
fang=fang2;
strcpy(fangname,"����");
}
else SlowDisplay("��û�����׿���װ��\n\n\n");
jingdutiao();
break;
case 7:if(fang3n>=1)
{
SlowDisplay("����������\n\n\n");
fang=fang3;
strcpy(fangname,"����");
jingdutiao();
}
else SlowDisplay("��û�����׿���װ��\n\n\n");
jingdutiao();
break;
case 8:if(fang4n>=1)
{
SlowDisplay("�����˻ƽ�ʥ��\n\n\n");
fang=fang4;
strcpy(fangname,"�ƽ�ʥ��");
jingdutiao();
}
else SlowDisplay("��û�лƽ�ʥ�¿���װ��\n\n\n");
jingdutiao();
break;
case 9:if(gong5n>=1)
{
SlowDisplay("�����˿�������\n\n\n");
gong=gong5;
strcpy(gongname,"��������");
jingdutiao();
}
else SlowDisplay("��û�п������ݿ���װ��\n\n\n");
jingdutiao();
break;
case 10:if(fang5n>=1)
{
SlowDisplay("���������֮��\n\n\n");
fang=fang5;
strcpy(fangname,"���֮��");
jingdutiao();
}
else SlowDisplay("��û�����֮�ܿ���װ��\n\n\n");
jingdutiao();
break;
case 11:if(diaozhui1n>=1)
{
SlowDisplay("�����˳���Գ��׹\n\n\n");
diaozhui1nn=diaozhui1;
strcpy(diaozhui1name,"����Գ��׹");
jingdutiao();
}
else SlowDisplay("��û�г���Գ��׹����װ��\n\n\n");
jingdutiao();
break;
case 12:if(diaozhui2n>=1)
{
SlowDisplay("�����˲������׹\n\n\n");
diaozhui2nn=diaozhui2;
strcpy(diaozhui2name,"�������׹");
jingdutiao();
}
else SlowDisplay("��û�в������׹����װ��\n\n\n");
jingdutiao();
break;
case 13:if(diaozhui3n>=1)
{
SlowDisplay("�����˷����ϵ�׹\n\n\n");
diaozhui3nn=diaozhui3;
strcpy(diaozhui3name,"�����ϵ�׹");
jingdutiao();
}
else SlowDisplay("��û�з����ϵ�׹����װ��\n\n\n");
jingdutiao();
break;
case 0:SlowDisplay("δ����װ��\n\n\n");
jingdutiao();
break;
default:printf("change error!");
jingdutiao();
}
}
void MapFordangerous()
{
system("color FC");
gotoxy(13,4);printf("�����ϴ�(f)");gotoxy(9,25);printf("������ƽԭ(c)");gotoxy(1,1);printf("���ո��(l)");
gotoxy(6,42);printf("��е֮��(j)");gotoxy(15,50);printf("����ʵ����(s)");
printf("\n\n\n\n����(o)\n\n\n");
}
void Boom()
{
gotoxy(17,74);puts("o");system("cls");
gotoxy(15,74);puts("+");gotoxy(17,70);puts("+       +");gotoxy(19,74);puts("+");system("cls");
gotoxy(13,74);puts("+");gotoxy(15,68);puts("+           +");gotoxy(17,66);puts("+               +");gotoxy(19,68);puts("+           +");gotoxy(21,74);puts("+");system("cls");
gotoxy(11,74);puts("+");gotoxy(13,66);puts("+               +");gotoxy(17,62);puts("+                       +");gotoxy(21,66);puts("+               +");gotoxy(23,74);puts("+");system("cls");
gotoxy(2,74);puts("+");gotoxy(3,64);puts("+                    +");gotoxy(5,56);puts("+                                   +");gotoxy(8,50);puts("+                                               +");gotoxy(12,46);puts("+                                                       +");
gotoxy(17,44);puts("+                                                           +");gotoxy(22,46);puts("+                                                       +");gotoxy(25,50);puts("+                                               +");gotoxy(28,56);puts("+                                   +");
gotoxy(30,64);puts("+                    +");gotoxy(31,74);puts("+");system("cls");
gotoxy(13,0);
puts("\t\t\t\t\t����������    ����������    ����������    ����      ����  ��");
puts("\t\t\t\t\t��      ��    ��      ��    ��      ��    �� ��    �� ��  ��");
puts("\t\t\t\t\t��      ��    ��      ��    ��      ��    ��  ��  ��  ��  ��");
puts("\t\t\t\t\t��������      ��      ��    ��      ��    ��   ����   ��  ��");
puts("\t\t\t\t\t��      ��    ��      ��    ��      ��    ��    ��    ��  ��");
puts("\t\t\t\t\t��      ��    ��      ��    ��      ��    ��    ��    ��    ");
puts("\t\t\t\t\t����������    ����������    ����������    ��    ��    ��  ��");
guai.health-=6666;
jingdutiao();
}
void jingdutiao()
{
system("cls");
Sleep(100);
POINT pt;
GetCursorPos(&pt);
GetLocalTime(&Time);
int s=Time.wHour;
int f=Time.wMinute;
gotoxy(0,0);
SetConsoleTitle("������Ϸ2.1"); //����
COORD pos; //����һ��λ�ñ���
puts("����:�����\tС��:����\t������Ϸ������") ; 
puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
puts("�U                                                            �U");
puts("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
printf("\t���ڼ���.........%d:%d\t\t",s,f);
printf("\t������Ϸ\t");
if(battle)SlowDisplay("ս��������");
gotoxy(2,2);
for(int i=0;i<30;i++)
{
Sleep(20);
printf("��");
}
system("cls");
}
