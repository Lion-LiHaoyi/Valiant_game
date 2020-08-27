#include <stdlib.h>//初次做游戏可能做的不好 
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
#include <windows.h> //SLEEP函数
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
tank={"坦克",25,75,250,75,250,75,1,0,0,100,0,0},
army={"战士",60,50,150,100,150,100,1,0,0,100,1,1},
ack={"刺客",100,30,100,100,100,100,1,0,0,100,1,1},
mag={"法师",75,40,120,250,120,250,1,0,0,100,1,1},
gun={"射手",80,30,110,150,110,150,1,0,0,100,1,3},
player={"\0",0,0,0,0,0,0,0,0,0,0};
struct Enemy //怪的结构体,并初始化各种怪
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
}strongman={"森林巨人","黄金圣衣",50,60,600,500,200,100,1,2,1,1},
witch={"森林女巫","银甲",30,45,100,100,50,50,2,3,1,1},
xiyi={"森林蜥蜴","铁甲",12,30,80,80,30,35,3,4,2,1},
big_strongman={"森林巨人王","程序猿令牌",35*5,55*5,355*5,355*5,200*5,100*5,4,10,2,2},
lion={"草原雄狮","绝世好剑",100,100,400,400,200,100,5,2,1,2},
horse={"草原野马","碧血剑",70,20,200,120,50,50,6,3,1,1}, 
bee={"草原黄蜂","长剑",23,10,75,75,30,35,7,4,2,2},
stone={"山脉岩石","布衣",15,50,100,100,50,20,0,5,2,2},
asshole={"山脉菊花","匕首",20,10,60,60,50,20,8,5,2,2},
cxy={"程序猿","程序猿吊坠",100,200,2000,2000,500,300,17,5,1,0},
shitu={"程序廖","草泥马令牌",65*7,35*7,285*7,285*7,205*7,105*7,9,10,1,0},
wugui={"巨龟","神龟之盾",40,375,166*10,166*10,150,100,11,1,1,0},
shark={"巨兽鲨","狂鲨利齿",90,50,500,500,300,150,10,1,1,0},
Bman={"B_boom投手","B_boom",999999999,60,300,300,300,200,12,1,1,1},
fashu={"法妖","魔法卷轴",150,20,250,250,300,200,13,8,1,1},
hongshi={"猩红之石","猩红精华",100,100,500,500,100,100,20,8,1,1},
gushi={"远古之石","远古精华",100,100,500,500,100,100,21,8,1,1},
ccm={"草泥马","草泥马吊坠",200,30,300,300,300,200,18,5,1,0},
cnx={"草泥曦","法克鱿令牌",100*7,30*5,200*7,200*7,205*7,105*7,14,10,1,0},
ffk={"法克鱿","法克鱿吊坠",70,300,500,500,300,300,19,5,1,0},
fky={"法克逸","周凯学长令牌",25*7,500,300*7,300*7,205*7,105*7,15,10,1,0},
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
char gongname[20]="无",fangname[20]="无",diaozhui1name[20]="无",diaozhui2name[20]="无",diaozhui3name[20]="无",zyname[20]="无";
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
SlowDisplay("这是一个令人蛋疼的学生世界!\n\n 师大附小时代师大附中师大联盟的校花，被一群好人（才怪）绑架了!\n\n 伟大的学生党啊~拿起你们的节操,不，铁锹，不，武器，营救校花!\n\n\n");
printf("选择你的职业：\n\n 1 坦克 肉到绝望\n\n 2 战士 不屈特性\n\n 3 刺客 输出爆表\n\n 4 法师 无限恢复\n\n 5 射手 极高闪避\n\n");
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
printf("输入你的名字与校花的名字（输一个按一下回车）\n\n\n");
// sndPlaySound("res\\F005.wav",SND_LOOP);
scanf("%s",player_name); 
strncpy(player.name,player_name,20);
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("隐居多年的hzwer啊!你终于回来了!快去杀掉那个冒牌货吧！\n\n\n     hzwer重新出山... 随即... 暴走!!!\n\n\n");//开挂程序 
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
printf("熟练度:%d 职业技:%s\n\n\n 坦克按键 1\n\n\n 法师按键 2\n\n\n 射手按键 3\n\n\n 0,返回\n\n\n",fenshu,zyname);
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
SlowDisplay("算了吧你\n\n\n");
break; 
case 1:
if(wrbsp>=1&&huolianjishu>=1)
{
if(jishu2>0)
{
SlowDisplay("集天地之力,发动至强一击!!!并提升自身属性!!!\n\n\n");
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
SlowDisplay("集天地之力,发动至强一击!!!\n\n\n");
guai.health-=250;
AttackResult();
}
}
else
printf("算了吧你\n\n\n");
break;
case 2:
if(fnhl>=1&&huolianjishu>=1)
{
printf("造成%d伤害,汲取血,魔%d\n\n\n",player.level/5+player.max_mp/2+player.attack/3,(player.level/5+player.max_mp/2+player.attack/3)/10,(player.level/5+player.max_mp/2+player.attack/3)/10);
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
SlowDisplay("算了吧你\n\n\n");
break;
case 0:break;
}
}

void jineng()
{
printf("技能：1，大爆菊术 2,饮血 3,太极生万物 0,返回\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:	
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(dbjs>0&&player.mp+diaozhui1nn/4>=30)
{
SlowDisplay("赛扣及！！！\n\n\n");
guai.health-=150;
player.mp-=30;
AttackResult();
}
else
{
printf("算了吧你\n\n\n");
}
}
break;
case 2:	
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(yinxie>0&&player.mp+diaozhui1nn/4>=25)
{
printf("偷窃%d生命！！！\n\n\n",(player.health+diaozhui1nn+guai.health)/20);
guai.health-=100;
player.mp-=25;
if(player.health+(player.health+guai.health)/20>=player.max_health)
player.health=player.max_health;
else player.health+=(player.health+guai.health)/20;
AttackResult();
}
else
{
printf("算了吧你\n\n\n");
}
}
break;
case 3:	
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(tjsww>0&&player.mp+diaozhui1nn>=150)
{
SlowDisplay("万物复苏！！！！！满状态！！！并造成50点伤害！！！\n\n\n");
player.health=player.max_health;
player.mp-=150;
player.mp=player.max_mp;
guai.health-=50;
tjsww--;
AttackResult();
}
else
{
printf("算了吧你\n\n\n");
}
}
break;
case 0:break;
default:printf("认真选技能！\n\n\n");
}
}
void ChooseWupin() //选择物品 并使用
{
printf("物品: 1,止血草%d个 2,急救包%d个 3,云南白药%d个 4,超级云南白药%d个 5,手雷%d个 6,毒标%d个 7,手抛式原子弹%d个 8,B_boom%d个\n\n\n 9,魔法卷轴%d个 10,猩红精华%d个 11,猩红卷轴%d个 12,远古精华%d个 13,远古卷轴%d个 14,秘药%d个 \n\n\n15,程序猿令牌%d 16,草泥马令牌%d 17,法克鱿令牌%d 18,周凯学长令牌%d 0,返回\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,B,juan1,honghua,juan2,guhua,juan3,my,lingpai0,lingpai1,lingpai2,lingpai3);
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(cao>0)
{
SlowDisplay("使用止血草,HP增加60\n\n\n");
cao--;
if(player.health+60>player.max_health)player.health=player.max_health;
else player.health+=60;
}
jingdutiao();
break;
case 2:
if(jijiubao>0)
{
SlowDisplay("使用急救包,HP增加80\n\n\n");
jijiubao--;
if(player.health+80>player.max_health)player.health=player.max_health;
else player.health+=80;
}
else SlowDisplay("没有急救包了\n\n\n");
jingdutiao();
break;
case 3:
if(baiyao>0)
{
SlowDisplay("使用云南白药,HP增加120\n\n\n");
baiyao--;
if(player.health+120>player.max_health)player.health=player.max_health;
else player.health+=120;
}
else SlowDisplay("没有云南白药了\n\n\n");
jingdutiao();
break;
case 4:
if(superbaiyao>0)
{
SlowDisplay("使用超级云南白药,HP增加200\n\n\n");
superbaiyao--;
if(player.health+200>player.max_health)player.health=player.max_health;
else player.health+=200;
}
else SlowDisplay("没有超级云南白药了\n\n\n");
jingdutiao();
break;
case 5:
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(boom>0)
{
SlowDisplay("使用手雷,敌人HP减少100\n\n\n");
boom--;
guai.health-=100;
AttackResult();
}
else
{
printf("算了吧你\n\n\n");
}
}
else SlowDisplay("非战斗状态,不能使用手雷!\n\n\n");
jingdutiao();
break;
case 6:
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(dubiao>0)
{
SlowDisplay("使用毒标,敌人HP减少200\n\n\n");
dubiao--;
guai.health-=200;
AttackResult();
}
else
{
printf("算了吧你\n\n\n");
}
}
else SlowDisplay("非战斗状态,不能使用毒标!\n\n\n");
jingdutiao();
break;
case 7:
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(atom_boom>0)
{
SlowDisplay("使用手抛式原子弹,敌人HP减少500\n\n\n");
atom_boom--;
guai.health-=500;
AttackResult();
}
else
{
printf("算了吧你\n\n\n");
}
}
else SlowDisplay("非战斗状态,不能使用手抛式原子弹!\n\n\n");
jingdutiao();
break;
case 8:
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
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
printf("算了吧你\n\n\n");
}
}
else SlowDisplay("非战斗状态,不能使用Bboom!\n\n\n");
jingdutiao();
break;
case 9:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 10:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 11:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 12:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 13:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 14:
if(my>0)
{
SlowDisplay("使用秘药,MP增加30\n\n\n");
my--;
if(player.mp+30>player.max_mp)player.mp=player.max_mp;
else player.mp+=30;
jingdutiao();
}
else SlowDisplay("没有秘药了\n\n\n");
jingdutiao();
break;
case 15:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 16:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 17:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 18:
SlowDisplay("这货总会有用的\n\n\n");
jingdutiao();
break;
case 0:
jingdutiao();
break;
default:printf("ChooseWupin error!\n\n\n");
}
}
int AttackResult() //攻击结果:判断是否获胜 是否获得物品 和 是否升级
{
if(guai.health<=0)
{
battle=0;
printf("战斗胜利!获得金币%d,经验%d\n\n\n",guai.money,guai.exp);
SlowDisplay(" ");
jishu3=1;
huolianjishu=4;
player.exp+=guai.exp;
player.range_exp+=guai.exp;
fenshu++;
money+=guai.money; s=SuiJi();
if(s<guai.wupinpro)
{
printf("%s爆出了",guai.name);
printf("%s\n\n\n",guai.wupin);
SlowDisplay(" ");
AddWupin(guai.wupin_sign);
}
WhetherLevelUp();
jingdutiao();
if(strcmp(guai.name,"hzwer")==0)
{
SlowDisplay("杀怪数量:");
printf("%d\t\t",fenshu);
SlowDisplay("最终等级:");
printf("%d\t\t",player.level);
SlowDisplay("最终余额:");
printf("%d\n\n\n",money);
printf("战斗胜利，救出你的校花女友%s!!!\n\n\n",xiaohua.name);
getchar();
getchar();
exit(0);
}
return 1; //攻击有结果了返回1,否则返回0,用于判断是否继续做战斗行为
}
else 
{
int s=SuiJi();
if(s>=player.miss)
{
if((guai.attack+s-(player.defense+fang+diaozhui3)/3)<0)
{
player.health-=1;
printf("%s反击,你的HP减少了 1\n\n",guai.name);
}
else
{
player.health-=guai.attack+s-(player.defense+fang+diaozhui3nn)/3;
printf("%s反击,你的HP减少了%d\n\n",guai.name,guai.attack+s-(player.defense+fang+diaozhui3nn)/3);
}
}
else
{
printf("%s",player.name);
SlowDisplay("闪避!!!\n\n\n");
}
if(player.health+diaozhui1nn<=0)
{
if(dhwj>=1&&jishu3>=1)
{
SlowDisplay("远古战神的英灵使你不屈不灭,获得");
printf("%d",(player.max_health+diaozhui1nn)/4);
SlowDisplay("生命值！！！\n\n\n");
player.health=0;
player.health+=(player.max_health+diaozhui1nn)/4;
jishu3--;
}
else
{
battle=0;
printf("%s战死!金币掉落%d\n\n\n",player.name,player.level*500);
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
if(player.level<=15&&l1>0) //15级以下,经验足够 都满足则升级
{
if(l1==1)
{
printf("%s",player.name);
SlowDisplay(" 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20, MP上限+10\n\n\n");
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
printf("好厉害!连升%d级!",l1);
printf("攻击力+%d, 防御力+%d, HP上限+%d, MP上限+%d\n\n\n",3*l1,2*l1,20*l1,10*l1);
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
SlowDisplay(" 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20, MP上限+10\n\n\n");
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
printf("好厉害!连升%d级!",l2);
printf("攻击力+%d, 防御力+%d, HP上限+%d, MP上限+%d\n\n\n",3*l2,2*l2,20*l2,10*l2);
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
SlowDisplay(" 升级!\n\n\n攻击力+3, 防御力+2, HP上限+20, MP上限+10\n\n\n");
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
printf("好厉害!连升%d级!",l3);
printf("攻击力+%d, 防御力+%d, HP上限+%d, MP上限+10\n\n\n",3*l3,2*l3,20*l3,10*l3);
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
void OrdinaryAct() //正常行为菜单(移动,物品,对话,查看状态,装备,退出游戏)
{

while(1)
{
// \(1000);
// system("cls");
Map();
printf("\n菜单(m)\t退出(o)\t背景音乐(u)\t背景音乐教程(j)\n目前有的地方返回按0(如道具),有的按o(如地图),我们会尽力修复\n");
switch(scanf("%s",&choose_number),choose_number)
{ 
case 'j':
SlowDisplay("把一个想要作为背景音乐的音乐存在D盘里\n开一个文件夹名为我的音乐,放在里面\n并命名为01.mp3,02.mp3等等,只需在代码中改写就行啦\n");
SlowDisplay("格式:\n所在盘(大写):\\(计算机会自动吞一个,如果你只写一个就会被吞)所在文件夹\\文件名.mp3\n");
SlowDisplay("推荐背景音乐:\n《she is my sin》(实力赞)\n《we are electric》(实力赞)\n《victory》(作者使用)\n《he s a pirate》(作者使用)\n《barbarbar》(滑稽)\n《pacific rim》\n《smooth criminal》(滑稽)\n《the dawn》(作者使用)\n《moves like jagger》(滑稽,作者使用,拍游戏解说也用)\n《the mass》(超级大滑稽,德军装甲兵进行曲)\n《highscore》\n《invincible-xray dog》(滑稽,鲁班电玩同款)\n《girlfriend》(大滑稽,偶尔拍解说用)\n排名无先后\n");
SlowDisplay("记得把你用的音乐播放器调为单曲循环哦!!!!\n");
SlowDisplay("Do you get it??????????????????\n");
SlowDisplay("由于技术限制,我们暂时做不出来高级背景音乐效果,理解万岁!!!O(∩_∩)O鞠躬道谢!!!! ");
jingdutiao();
break;
case 'u':
system("D:\\我的音乐\\03.mp3.mp3");//背景音乐在这调！！！！！！！ 
cin.get();
jingdutiao();
break;
case 'o': 
SlowDisplay("确定推出游戏?(Y/N)\n\n\n");
getchar();
proof=getchar();
if(proof=='y'||proof=='Y')
{
SlowDisplay("数据存储中...");
//向文件中更新数据;
getchar();
SlowDisplay("按回车退出");
getchar();
return;
}
else if(proof=='n'||proof=='N')printf("继续游戏!\n\n\n");
else SlowDisplay("继续!\n\n\n");
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
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=witch;
printf("%s飘了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
jingdutiao();
//不用调用OAct函数,会自动执行OAct函数;
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
printf("%s飘了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=strongman;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
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
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=big_strongman;
SlowDisplay("一阵巨响在森林中回响：咚！！！咚！！！咚！！！随即森林巨人王扑了过来！！！\n\n\n");
BattleAct();0;
}
else
{
SlowDisplay("这里安全\n\n\n");
jingdutiao();
}
break;
default:
SlowDisplay("你搞错了(滑稽)");
jingdutiao(); 
}
break;
case 'd':
jingdutiao();
if(lingpai0!=1)
{
jingdutiao();
SlowDisplay("你还太弱\n\n\n");
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
printf("%s什么也看不见\n\n\n",player.name);
SlowDisplay(" ");
jingdutiao();
}
else if(s<9)
{
battle=1; 
if(lingpai3)
{
SlowDisplay("hzwer:\n\n\n 打败我就可以救出校花，来吧\n\n\n");
guai=zk;
printf("%s扑了过来!\n\n\n",guai.name);
SlowDisplay("一股神秘力量限制了B——boom的使用\n\n\n"); 
B=0;
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("hzwer看着对面那个和自己一样的人，输入了一段代码，对方顿时灰飞烟灭");
Boom();
}
BattleAct();
}
else SlowDisplay("hzwer:\n\n\n 年轻人,你好啊.如果你有我的令牌,我可以告诉你校花的下落哦~\n\n\n");
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
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1; 
if(lingpai2)
{
SlowDisplay("法克逸:\n\n\n 想救校花？来打架呀！！\n\n\n");
guai=fky;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("法克逸:\n\n\n 年轻人,你好啊.如果你有法克鱿令牌,我可以告诉你校花的下落哦~\n\n\n");
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
printf("%s发现你了!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("齿轮轧到了%s！！！\n\n\n",player.name);
player.health=player.health-15;
SlowDisplay(" ");
jingdutiao();
}
else
{
SlowDisplay("这里安全\n\n\n");
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
printf("%s跳了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1; 
if(lingpai0)
{
SlowDisplay("程序廖:\n\n\n 哈哈,年轻人,做的不错,不过...嘿嘿,你上当啦!程序猿令牌我要了,校花你也别想带走!\n\n\n");
guai=shitu;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("程序廖:\n\n\n 年轻人,你好啊.如果你有程序猿令牌,我可以告诉你校花的下落哦~\n\n\n");
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
SlowDisplay("你搞错了(滑稽)");
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
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
SlowDisplay("这里安全\n\n\n");
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
printf("%s冲了过来!\n\n\n",guai.name);
BattleAct(); }
else if(s<9)
{
jingdutiao();
battle=1;
guai=lion;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
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
printf("%s飞了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
jingdutiao();
battle=1;
guai=horse;
printf("%s冲了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
jingdutiao();
}
break;
default:
SlowDisplay("你搞错了(滑稽)");
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
printf("%s瞅了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<6)
{
battle=1;
guai=hongshi;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=gushi;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
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
printf("%s挪了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=stone;
printf("%s滚了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
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
SlowDisplay("巨.....龟.....以.....一.....种.....慢.....到.....令.....人.....绝.....望.....的.....速.....度.....爬.....了.....过.....来.....\n\n\n");
BattleAct();
}
else if(s<8)
{
battle=1;
guai=shark;
printf("%s冲了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("一个大浪打了过来！！！%s受了小伤\n\n\n",player.name);
SlowDisplay(" ");
player.health=player.health-5;
jingdutiao();
}
else
{
SlowDisplay("这里安全\n\n\n");
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
printf("勇士,有什么事:1,领悟职业技能 2,购买职业顶级装备 0,返回\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 2:
printf("坦克专属 1 霸壁锤岩\t\t2 万古不朽身\n\n\n战士专属 3 破空之刃\t\t4 圣灵光明体\n\n\n刺客专属 5 追魂幻刺\t\t6 狩猎者手凯\n\n\n法师专属 7 堕落天星杖\t\t8 幻光耀世衣\n\n\n射手专属 9 苍穹灭世波\t\t10 千里破风镜\n\n\n0,返回\t以上武器来源于游戏和小说\n\n\n");
printf("PS:统一价:300000\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 0:
SlowDisplay("走你!!!\n\n\n");
jingdutiao();
break;
}
}
break;
case 1:
printf("1 坦克专属 万仞崩山破(永久增肉) \n\n\n2 战士专属 远古意志(被动不屈) \n\n\n3 刺客专属 地狱之魂(被动饮血)\n\n\n4 法师专属 佛怒火莲(回魔回血) \n\n\n5 射手专属 狂风之息(闪避加成) \n\n\n0 返回 以上技能来源于游戏或小说\n\n\n"); 
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(n==1&&jishu!=1)
{
SlowDisplay("领悟成功\n\n\n");
wrbsp++;
n++;
jishu==1;
strcpy(zyname,"万仞崩山破");
}
else
SlowDisplay("滚！\n\n\n");
break;
case 2:
if(nn==1)
{
SlowDisplay("领悟成功\n\n\n");
dhwj++;
nn++;
strcpy(zyname,"远古意志");
}
else
SlowDisplay("滚！\n\n\n");
break;
case 3:
if(nnn==1)
{
SlowDisplay("领悟成功\n\n\n");
dysls++;
nnn++;
strcpy(zyname,"地狱之魂");
}
else
SlowDisplay("滚！\n\n\n");
break;
case 4:
if(nnnn==1)
{
SlowDisplay("领悟成功\n\n\n");
fnhl++;
nnnn++;
strcpy(zyname,"佛怒火莲");
}
else
SlowDisplay("滚！\n\n\n");
break;
case 5:
if(nnnnn==1)
{
SlowDisplay("领悟成功\n\n\n");
kfzx++;
nnnnn++;
strcpy(zyname,"狂风之息");
}
else
SlowDisplay("滚！\n\n\n");
break;
case 0:
SlowDisplay("走你!!!\n\n\n");
jingdutiao();
break;
}
}
break;
case 0:
SlowDisplay("走你!!!\n\n\n");
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
SlowDisplay("要住店吗? 500个金币 1,是 0,否\n\n\n");
choose_number=1;
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money-500<0) //判断钱是否够
{
SlowDisplay("Sorry,你的钱不够~\n\n\n"); 
jingdutiao();
}
else 
{
SlowDisplay("好好休息\n\tHP满,MP满\n\t\t第二天了\n\n");
money-=500; //花费200住店费
player.health=player.max_health;
player.mp=player.max_mp;//体力满
jingdutiao();
}
break;
case 0:SlowDisplay("下次再来!\n\n\n");
jingdutiao();break;
default:printf("hotel talk error!\n\n\n");system("cls");
}
break;
case 'j':
printf("1,制作人员 2,更新日志 0,返回\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{ 
case 1:
{
jingdutiao();
SlowDisplay("\n\n\n 制作发起者\n\n");
SlowDisplay(" 陈周凯学长\n\n");
SlowDisplay(" 改编者\n\n");
SlowDisplay(" 李昊逸 陈曦\n\n");
SlowDisplay(" 主编\n\n");
SlowDisplay(" 李昊逸\n\n");
SlowDisplay(" 方向制定\n\n");
SlowDisplay(" 陈曦\n\n");
SlowDisplay(" 鸣谢\n\n");
SlowDisplay(" 郑玲燕老师 陈周凯学长 云中月\n\n");
SlowDisplay(" 勇者游戏,感谢大家的支持!!!O(∩_∩)O鞠躬道谢!!!! "); 
jingdutiao();
}
break;
case 2:
{
jingdutiao();
SlowDisplay("\n\n\n更新日志:\n\n");
SlowDisplay(" 做到了初步可视化\n\n");
SlowDisplay(" 游戏体验感优化\n\n");
SlowDisplay(" 职业技开放\n\n");
SlowDisplay(" 职业装备作为预告放出\n\n");
SlowDisplay(" 暂时取消水战机制\n\n");
SlowDisplay(" 战士射手定位修改\n\n");
SlowDisplay(" 错误警告放回游戏界面中\n\n");
SlowDisplay(" 背景音乐系统开放\n\n");
SlowDisplay(" 如果有什么问题可以在9018平台上开讨论版哦\n\n");
SlowDisplay(" 一起期待下一个版本的到来!!!(下一个大版本估计会在2.6/7左右)\n\n");
SlowDisplay(" 勇者游戏,感谢大家的支持!!!O(∩_∩)O鞠躬道谢!!!! "); 
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
printf("要和谁说话?\n\n\n1,红发女郎 2,赏金猎人 3,酒吧老板 4,大法师 5,回收店老板 0,返回\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 5:
printf("至少有两个再来找我回收\n1 匕首 2 布衣 50金币 \n3 长剑 4 铁甲 100金币 \n5 碧血剑 6 银甲 300金币 \n7 绝世好剑 8 黄金圣衣 750金币\n0 返回\n\n\n"); 
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(gong1n>=2)
{
SlowDisplay("金币加50.\n");
gong1n--;
money+=50;
}
else 
{
SlowDisplay("匕首不够\n");
}
break;
case 2:
if(fang1n>=2)
{
SlowDisplay("金币加50.\n");
fang1n--;
money+=50;
}
else 
{
SlowDisplay("布衣不够\n");
}
break; 
case 3:if(gong2n>=2)
{
SlowDisplay("金币加100.\n");
gong2n--;
money+=100;
}
else 
{
SlowDisplay("长剑不够\n");
}
break; 
case 4:if(fang2n>=2)
{
SlowDisplay("金币加100.\n");
fang2n--;
money+=100;
}
else 
{
SlowDisplay("铁甲不够\n");
}
break; 
case 5:if(gong3n>=2)
{
SlowDisplay("金币加300.\n");
gong3n--;
money+=300;
}
else 
{
SlowDisplay("碧血剑不够\n");
}
break; 
case 6:if(fang3n>=2)
{
SlowDisplay("金币加300.\n");
fang3n--;
money+=300;
}
else 
{
SlowDisplay("银甲不够\n");
}
break; 
case 7:if(gong4n>=2)
{
SlowDisplay("金币加750.\n");
gong4n--;
money+=750;
}
else 
{
SlowDisplay("绝世好剑不够\n");
}
break; 
case 8:if(fang4n>=2)
{
SlowDisplay("金币加750.\n");
fang4n--;
money+=750;
}
else 
{
SlowDisplay("黄金圣衣不够\n");
}
break; 
case 0:
SlowDisplay("下次再来！！！");
jingdutiao();
break; 
}
case 0:
jingdutiao();
break;
case 1:
SlowDisplay("红发女郎:\n\n\n 吧台边那个Hunter好帅啊!(~脸红~)\n\n\n听说他经常外出打猎,外面的路他应该很熟悉的!\n\n\n");
jingdutiao();
break;
case 2:
if(player.level<=30)
SlowDisplay("赏金猎人:\n\n\n 年轻人!\n\n\n 你需要从山脉里的怪兽开始，\n\n\n 打败森林最深处的巨人王!\n\n\n 最后打败4位好人才可以救回校花!\n\n\n");
jingdutiao();
if(player.level>30)
SlowDisplay("赏金猎人:\n\n\n FUCK ！！！！！！！！！！！！！！！！！，你这么强了，还找我干铞\n\n\n");
jingdutiao();
break;
case 3:
printf("要喝点什么?\n\n\n 1,二锅头20金币 HP+20 2,XO酒80金币 HP+50 3,人头马面150金币 HP+100 0,离开\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<20)
{
SlowDisplay("钱不够!\n\n\n"); 
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
SlowDisplay("HP满了\n\n\n"); 
player.health=player.max_health;
}
}
break;
case 2:if(money<100)
{
SlowDisplay("钱不够!\n\n\n"); 
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
SlowDisplay("HP满了\n\n\n"); 
player.health=player.max_health;
}
}
break;
case 3:if(money<200)
{
SlowDisplay("钱不够!\n\n\n"); 
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
SlowDisplay("HP满了\n\n\n"); 
player.health=player.max_health;
}
}
break;
case 0:SlowDisplay("下次再来!\n");
jingdutiao();
break;
}
}
break;
case 4:
printf("这些是我最新研制的心法：\n\n 1，秘药 10金币，回魔30\n\n 2,魔法卷轴 500金币\n\n 3,猩红卷轴 魔法卷轴+猩红精华\n\n 4,远古卷轴 魔法卷轴+远古精华\n\n 5大爆菊术 伤害150 耗魔30 等级要求15 魔法卷轴消耗10\n\n 6,饮血 伤害100 耗魔25 等级要求25 猩红卷轴消耗14 偷窃一定生命\n\n 7,太极生万物 伤害50 耗魔150 等级要求50 远古卷轴消耗20 状态全满 消耗性法术\n\n 0，离开\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<10)
{
SlowDisplay("钱不够!\n\n\n"); 
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
SlowDisplay("MP满了\n\n\n"); 
player.mp=player.max_mp;
}
}
break;
case 2:
{
if(money<500)
{
SlowDisplay("钱不够！\n\n\n");
}
else
{
printf("这是你的了\n\n\n");
money-=500;
juan1++;
}
}
break;
case 3:
if(juan1<1||honghua<1)
{
SlowDisplay("材料不够！\n\n\n");
}
else if(juan1>=1&&honghua>=1)
{
printf("合成了猩红卷轴！\n\n\n");
juan1--;
honghua--;
juan2++;
}
break;
case 4:
if(juan1<1||guhua<1)
{
SlowDisplay("材料不够！\n\n\n");
}
else if(juan1>=1&&guhua>=1)
{
printf("合成了远古卷轴！\n\n\n");
juan1--;
guhua--;
juan3++;
}
break;
{
case 5:if(player.level<15||juan1<10)
{
SlowDisplay("你的力量还不够!\n\n\n"); 
}
else
{
if(player.level>=15&&juan1>=10)
{
SlowDisplay("爆菊心法尽收脑海\n\n\n");
juan1-=10;
dbjs++;
}
}
break;
case 6:if(player.level<25||juan2<14)
{
SlowDisplay("你的心理承受能力还不够!\n\n\n"); 
}
else
{
if(player.level>=25&&juan2>=14)
{
SlowDisplay("恐怖的声音在心中回响\n\n\n");
juan2-=14;
yinxie++;
}
}
break;
case 7:if(player.level<50||juan3<20)
{
SlowDisplay("你的力量还不够!\n\n\n"); 
}
else
{
if(player.level>=50&&juan3>=20)
{
SlowDisplay("伏羲的幻影悄悄浮现\n\n\n");
juan3-=20;
tjsww++;
}
}
break;
case 0:SlowDisplay("去吧，加油！！！\n\n\n");
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
SlowDisplay("你搞错了(滑稽)");
jingdutiao(); 
}
} 
}
void DisplayState()
{
printf("%s 攻击力:%d+%d+%d=%d 防御力:%d+%d+%d=%d HP:%d/%d MP:%d/%d 闪避:%f\n\n\n",player.name,player.attack,gong,diaozhui2nn,player.attack+gong+diaozhui2nn,player.defense,fang,diaozhui3nn,player.defense+fang+diaozhui3nn,player.health+diaozhui1nn,player.max_health+diaozhui1nn,player.mp+diaozhui1nn/4,player.max_mp+diaozhui1nn/4,player.miss);
printf("武器: %s 防具: %s 饰品:%s %s %s\n\n\n",gongname,fangname,diaozhui1name,diaozhui2name,diaozhui3name);
printf("等级:%d 经验:%d/%d 还需要%d经验升级 金币:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money); 
printf("0 返回 \n\n\n");
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
printf("要怎么办?\n\n\n 1,攻击 2,物品 3,查看状态 4,技能 5,职业专区 6,逃跑\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
s=SuiJi();
if(s>=guai.miss)
{
if(dysls>=1&&player.health<=player.max_health/3)
{
SlowDisplay("源于血脉的力量彻底觉醒!!!!攻击力增加1/4!!!\n\n\n");
guai.health-=player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3;
player.health+=(player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3)/3;
printf ("对%s造成%d伤害!!!汲取%d生命!!!\n\n\n",guai.name,player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3,(player.attack*5/4+s+gong+diaozhui2nn-guai.defense/3)/3);
}
else
{
printf("%s攻击! %sHP减少%d\n\n\n",player.name,guai.name,player.attack+s+gong+diaozhui2nn-guai.defense/3);
guai.health-=player.attack+s+gong+diaozhui2nn-guai.defense/3;
}
}
else SlowDisplay("没打中！！！\n\n\n");
if(AttackResult())return; //如果攻击有结果(敌人或玩家战死)退出函数
else continue; 
case 2: ChooseWupin();break; //选择物品,可以使用,战斗中允许使用攻击性物品
case 3:DisplayState();break; //显示状态
case 4:jineng();break;
case 5:zy();break;
case 6:
s=SuiJi();
if(s<4) //40%的概率可以逃跑
{
printf("%s逃跑了~\n\n\n",player.name);
battle=0;
jishu3=1;
huolianjishu=4;
jingdutiao();
return;
}
else printf("%s逃跑失败!还摔伤了!丢失5生命!!\n\n\n",player.name);
SlowDisplay(" \n");
if(player.health>5)
{ 
player.health-=5;
break;
} 
else
{
battle=0;
printf("%s摔死了,金币掉落%d.....\n\n\n",player.name,player.level*5);
puts("o(╯□╰)o ");
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
default:SlowDisplay("输入错误,重新输入!\n\n\n");
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
printf("\n\n\n\t\t\t\t1,物品\n\n\t\t\t\t2,装备\n\n\t\t\t\t3,状态\n\n\t\t\t\t0,返回\n\n\n");
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
gotoxy(2,30);printf("北(g):草原区域");gotoxy(10,20);printf("南(h):山脉区域");
gotoxy(1,1);printf("人类最后的保留地(p)");gotoxy(5,52);printf("东(f):森林区域");
gotoxy(4,4);printf("法术幽谷(k)");gotoxy(15,50);printf("危险区域(d)");gotoxy(15,10);printf("边界海(s)");
printf("\n\n\n\n");
}
void MapForforest()
{
	gotoxy(7,15);printf("森林一层(f)");gotoxy(14,9);printf("森林二层(s)");gotoxy(12,50);printf("森林三层(t)");
printf("\n\n\n\n\n\n\n\n\n");
printf("返回(o)\n\n\n");
}
void MapForgrass()
{
gotoxy(7,25);printf("草原一层(f)");gotoxy(17,9);printf("草原二层(s)");gotoxy(12,50);printf("草原三层(t)");
printf("\n\n\n\n\n\n\n\n\n");
printf("返回(o)\n\n\n");
}
void MapForpeople()
{
gotoxy(7,25);printf("酒吧(b)");gotoxy(10,7);printf("旅店(h)");gotoxy(15,50);printf("勇者游戏工作室(j)");gotoxy(3,3);printf("职业神殿(s)");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
printf("返回(o)\n\n\n");
}
void zhuangbei()
{
jingdutiao();
printf("攻装: 1,匕首:%d个 2,长剑:%d个 3,碧血剑:%d个 4,绝世好剑:%d个 9,狂鲨利齿:%d个\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
printf("防装: 5,布衣:%d个 6,铁甲:%d个 7,银甲:%d个 8,黄金圣衣:%d个 10,神龟之盾:%d个\t\t0,返回\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
printf("饰品：11,程序猿吊坠%d(生命,法术) 12，草泥马吊坠%d（攻击） 13，法克鱿吊坠%d（防御）\n\n\n",diaozhui1n,diaozhui2n,diaozhui3n);
SlowDisplay("选择要装备的武器或防具:\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(gong1n>=1)
{
SlowDisplay("拿起了匕首\n\n\n");
gong=gong1;
strcpy(gongname,"匕首");
jingdutiao();
}
else SlowDisplay("你没有匕首可以装备\n\n\n");
jingdutiao();
break;
case 2:if(gong2n>=1)
{
SlowDisplay("拿起了长剑\n\n\n");
gong=gong2;
strcpy(gongname,"长剑");
jingdutiao();
}
else SlowDisplay("你没有长剑可以装备\n\n\n");
jingdutiao();
break;
case 3:if(gong3n>=1)
{
SlowDisplay("拿起了碧血剑\n\n\n");
gong=gong3;
strcpy(gongname,"碧血剑");
jingdutiao();
}
else SlowDisplay("你没有碧血剑可以装备\n\n\n");
jingdutiao();
break;
case 4:if(gong4n>=1)
{
SlowDisplay("拿起了绝世好剑\n\n\n");
gong=gong4;
strcpy(gongname,"绝世好剑");
jingdutiao();
}
else SlowDisplay("你没有绝世好剑可以装备\n\n\n");
jingdutiao();
break;
case 5:if(fang1n>=1)
{
SlowDisplay("穿上了布衣\n\n\n");
fang=fang1;
strcpy(fangname,"布衣");
jingdutiao();
}
else SlowDisplay("你没有布衣可以装备\n\n\n");
jingdutiao();
break;
case 6:if(fang2>=1) 
{
SlowDisplay("穿上了铁甲\n\n\n");
fang=fang2;
strcpy(fangname,"铁甲");
}
else SlowDisplay("你没有铁甲可以装备\n\n\n");
jingdutiao();
break;
case 7:if(fang3n>=1)
{
SlowDisplay("穿上了银甲\n\n\n");
fang=fang3;
strcpy(fangname,"银甲");
jingdutiao();
}
else SlowDisplay("你没有银甲可以装备\n\n\n");
jingdutiao();
break;
case 8:if(fang4n>=1)
{
SlowDisplay("穿上了黄金圣衣\n\n\n");
fang=fang4;
strcpy(fangname,"黄金圣衣");
jingdutiao();
}
else SlowDisplay("你没有黄金圣衣可以装备\n\n\n");
jingdutiao();
break;
case 9:if(gong5n>=1)
{
SlowDisplay("拿起了狂鲨利齿\n\n\n");
gong=gong5;
strcpy(gongname,"狂鲨利齿");
jingdutiao();
}
else SlowDisplay("你没有狂鲨利齿可以装备\n\n\n");
jingdutiao();
break;
case 10:if(fang5n>=1)
{
SlowDisplay("拿起了神龟之盾\n\n\n");
fang=fang5;
strcpy(fangname,"神龟之盾");
jingdutiao();
}
else SlowDisplay("你没有神龟之盾可以装备\n\n\n");
jingdutiao();
break;
case 11:if(diaozhui1n>=1)
{
SlowDisplay("戴上了程序猿吊坠\n\n\n");
diaozhui1nn=diaozhui1;
strcpy(diaozhui1name,"程序猿吊坠");
jingdutiao();
}
else SlowDisplay("你没有程序猿吊坠可以装备\n\n\n");
jingdutiao();
break;
case 12:if(diaozhui2n>=1)
{
SlowDisplay("戴上了草泥马吊坠\n\n\n");
diaozhui2nn=diaozhui2;
strcpy(diaozhui2name,"草泥马吊坠");
jingdutiao();
}
else SlowDisplay("你没有草泥马吊坠可以装备\n\n\n");
jingdutiao();
break;
case 13:if(diaozhui3n>=1)
{
SlowDisplay("戴上了法克鱿吊坠\n\n\n");
diaozhui3nn=diaozhui3;
strcpy(diaozhui3name,"法克鱿吊坠");
jingdutiao();
}
else SlowDisplay("你没有法克鱿吊坠可以装备\n\n\n");
jingdutiao();
break;
case 0:SlowDisplay("未更换装备\n\n\n");
jingdutiao();
break;
default:printf("change error!");
jingdutiao();
}
}
void MapFordangerous()
{
system("color FC");
gotoxy(13,4);printf("法克鱿大海(f)");gotoxy(9,25);printf("草泥马平原(c)");gotoxy(1,1);printf("马勒戈壁(l)");
gotoxy(6,42);printf("机械之城(j)");gotoxy(15,50);printf("神秘实验室(s)");
printf("\n\n\n\n返回(o)\n\n\n");
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
puts("\t\t\t\t\t■■■■■    ■■■■■    ■■■■■    ■■      ■■  ■");
puts("\t\t\t\t\t■      ■    ■      ■    ■      ■    ■ ■    ■ ■  ■");
puts("\t\t\t\t\t■      ■    ■      ■    ■      ■    ■  ■  ■  ■  ■");
puts("\t\t\t\t\t■■■■      ■      ■    ■      ■    ■   ■■   ■  ■");
puts("\t\t\t\t\t■      ■    ■      ■    ■      ■    ■    ■    ■  ■");
puts("\t\t\t\t\t■      ■    ■      ■    ■      ■    ■    ■    ■    ");
puts("\t\t\t\t\t■■■■■    ■■■■■    ■■■■■    ■    ■    ■  ■");
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
SetConsoleTitle("勇者游戏2.1"); //标题
COORD pos; //定义一个位置变量
puts("主编:李昊逸\t小编:陈曦\t勇者游戏工作室") ; 
puts("╔══════════════════════════════╗");
puts("║                                                            ║");
puts("╚══════════════════════════════╝");
printf("\t正在加载.........%d:%d\t\t",s,f);
printf("\t勇者游戏\t");
if(battle)SlowDisplay("战斗！！！");
gotoxy(2,2);
for(int i=0;i<30;i++)
{
Sleep(20);
printf("■");
}
system("cls");
}
