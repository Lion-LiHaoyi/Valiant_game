#include<stdlib.h>//初次做游戏可能做的不好 
#include<stdio.h>
#include<time.h> //suiji 
#include<string.h>
#include<conio.h>
#include<algorithm>
#include<windows.h> //SLEEP函数
struct Player //玩家结构体，并初始化player
{
char name[21]; 
int attack;
int defense; //勇者游戏1.8.3版本更新 
int health;//更新日志：修复了已知的所有bug（包括道具店老板哦！） 
long int max_health;//修改了关于双倍攻击的参数 
int level; //（个人吐槽：陈曦把勇者游戏搞成了校园游戏） 
int exp; //请问陈曦死哪去了？（阴险\滑稽\失望） 
int range_exp; //@陈曦&吴非：加一下我的qq1476563317一起商讨勇者游戏更新 
long int max_exp; 
int air;
int max_air; 
}player={"勇者",50,40,100,100,1,0,0,100,10,10};
struct Enemy //怪的结构体,并初始化各种怪
{
char name[200];
char wupin[100];
int attack;
int defense;
int health;
int money;
long int exp;
int wupin_sign;
int wupinpro;
int double_attack;
int miss;
}strongman={"森林巨人","黄金圣衣",50,60,350,200,100,1,2,5,2},
witch={"森林女巫","银甲",40,30,100,50,50,2,2,0,1},
xiyi={"森林蜥蜴","铁甲",30,25,50,30,35,3,3,0,0},
big_strongman={"森林巨人王","巨人之臂",150,180,1200,800,400,4,4,10,3},
lions={"草原狮群","雄狮之爪",120,150,1800,800,400,13,4,10,3},
lion={"草原雄狮","绝世好剑",70,40,280,200,100,5,2,5,2},
horse={"草原野马","碧血剑",50,30,90,50,50,6,2,0,1}, 
bee={"草原黄蜂","长剑",30,20,60,30,35,7,3,0,0},
stone={"山脉岩石","布衣",10,40,100,50,20,0,4,0,0},
asshole={"山脉菊花","匕首",30,10,60,50,20,8,4,0,0},
shitu={"大学渣","\0",350,170,1600,1200,600,-1,0,15,3},
wugui={"巨龟","神龟之盾",100,500,500,1000,400,11,3,10,2},
shark={"巨兽鲨","狂鲨利齿",350,50,500,1000,400,10,3,10,3},
fish={"食人鱼","进入下一关的钥匙",35,25,70,40,40,9,8,0,0},
pangxie={"螃蟹","进入下一关的钥匙",30,35,70,40,40,9,8,0,0},
smallshark={"小鲨","进入下一关的钥匙",45,35,100,50,50,12,7,0,1},
lanjing={"小蓝鲸","进入下一关的钥匙",30,50,200,50,50,12,7,0,1},
oldman={"校长","\0",570,270,2700,1800,1000,-1,0,20,4}, 
guai={"\0","\0",0,0,0,0,0,0,0,0,0};
struct Place
{
int bar,hotel,forest1,forest2,forest3,grass1,grass2,grass3,mountain,mlgb,sea1,sea2,sea3;
}place={1,2,3,4,5,6,7,8,9,10,11,12,13};

int max_exp=0;
int choose_number=0,s=0,strongman_arm=0,lion_hand,battle=0,money=1000,place_sign=11,bi=0,buy_number=0,yun=0,yaoshi1=0,yaoshi2=0;
int cao=4,jijiubao=3,baiyao=3,superbaiyao=1,boom=4,dubiao=3,atom_boom=1,aircase=1,diangun=1,yulei=1,zidan=1,s1=0,res;
int fang=0,fang1=10,fang1n=0,fang2=20,fang2n=0,fang3=40,fang3n=0,fang4=100,fang4n=0,fang5=150,fang5n=0;
int gong=0,gong1=10,gong1n=0,gong2=20,gong2n=0,gong3=40,gong3n=0,gong4=100,gong4n=0,gong5=150,gong5n=0;
char gongname[20]="无",fangname[20]="无";
char proof;
char *p;

void AddWupin(int);
int AttackResult();
void BattleAct();
void ChooseWupin();
void DisplayState();
void OrdinaryAct(); 
int SuiJi();
int SuiJi100();
void WhetherLevelUp();
void SlowDisplay(char *); 

int main()
{
system("mode con cols=150 lines=150"); 
system("color 0F");
int i=0,j=0,k=0;
char player_name[21];
res=MessageBox(NULL,"准备好开始游戏了吗？","提示",MB_YESNO);
if(res==IDNO)
{
MessageBox(NULL,"太慢了吧！","提示",MB_OK);
return 0;
}
SlowDisplay("这是一个令人蛋疼的勇者世界! 师大附小时代师大附中师大四校联盟的总校花，被好人（才怪）绑架了!\n\n 伟大的勇者啊~拿起你们的节操,不，铁锹，不，武器，营救校花!\n\n\n输入你的名字: （20个字符以内）\n\n\n");

// sndPlaySound("res\\F005.wav",SND_LOOP);
scanf("%s",player_name); 
strncpy(player.name,player_name,20);
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("隐居多年的hzwer啊!你终于可以重见天日了!\n\n\n     hzwer重新出山... 随即... 暴走!!!\n\n\n");//开挂程序 
player.attack=999;
player.defense=999;
player.health=9999;
player.max_health=9999;
atom_boom++; 
}
if(strcmp(player.name,"吴桐学长")==0)
{
SlowDisplay("隐居多年的吴桐学长啊!你终于可以重见天日了!\n\n\n    吴桐学长重新出山... 随即... 暴走!!!\n\n\n");//开挂程序 
player.attack=100;
player.defense=100;
player.health=1000;
player.max_health=1000;
atom_boom++; 
bi+=10;
}
getchar();
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
return rand()%100;
}
void ChooseWupin() //选择物品 并使用
{
printf("物品: 1,止血草%d个 2,急救包%d个 3,云南白药%d个 4,超级云南白药%d个 5,手雷%d个 6,毒标%d个 7,手抛式原子弹%d个 8,逼能激光炮 9,氧气袋%d个 10,电棍%d个 11,鱼雷%d个 12,步枪 0,返回\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,aircase,diangun,yulei);
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(cao>0)
{
SlowDisplay("使用止血草,HP增加80\n\n\n");
cao--;
if(player.health+80>player.max_health)player.health=player.max_health;
else player.health+=80;
}
else MessageBox(NULL,"没有止血草了","注意",MB_OK);
break;
case 2:
if(jijiubao>0)
{
SlowDisplay("使用急救包,HP增加100\n\n\n");
jijiubao--;
if(player.health+100>player.max_health)player.health=player.max_health;
else player.health+=100;
}
else MessageBox(NULL,"没有急救包了","注意",MB_OK);
break;
case 3:
if(baiyao>0)
{
SlowDisplay("使用云南白药,HP增加150\n\n\n");
baiyao--;
if(player.health+150>player.max_health)player.health=player.max_health;
else player.health+=150;
}
else MessageBox(NULL,"没有云南白药了","注意",MB_OK);
break;
case 4:
if(superbaiyao>0)
{
SlowDisplay("使用超级云南白药,HP增加200\n\n\n");
superbaiyao--;
if(player.health+200>player.max_health)player.health=player.max_health;
else player.health+=200;
}
else MessageBox(NULL,"没有超级云南白药了","注意",MB_OK);
break;
case 5:
if(battle&&place_sign!=place.sea1&&place_sign!=place.sea2&&place_sign!=place.sea3) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(boom>0)
{
SlowDisplay("使用手雷,敌人HP减少150\n\n\n");
boom--;
guai.health-=150;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态或在海中,不能使用手雷!","警告",MB_OK);
break;
case 6:
if(battle&&place_sign!=place.sea1&&place_sign!=place.sea2&&place_sign!=place.sea3) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(dubiao>0)
{
SlowDisplay("使用毒标,敌人HP减少300\n\n\n");
dubiao--;
guai.health-=300;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态或在海中,不能使用毒标!","警告",MB_OK);
break;
case 7:
if(battle&&place_sign!=place.sea1&&place_sign!=place.sea2&&place_sign!=place.sea3) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(atom_boom>0)
{
SlowDisplay("使用手抛式原子弹,敌人HP减少600\n\n\n");
atom_boom--;
guai.health-=600;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态或在海中,不能使用手抛式原子弹!","警告",MB_OK);
break;
case 8:
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(bi>20)
{
SlowDisplay("使用逼能激光炮,敌人HP减少1500\n\n\n");
bi-=20;
guai.health-=1500;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态,不能使用逼能激光炮!","警告",MB_OK);
break;
case 9:
if(aircase>0)
{
SlowDisplay("使用氧气袋,氧气增加5\n\n\n");
player.air--;
if(player.air+5>player.max_air)player.air=player.max_air;
else player.air+=5;
}
else MessageBox(NULL,"没有氧气袋了","注意",MB_OK);
break;
case 10:
if(battle) //在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(diangun>0)
{
SlowDisplay("使用电棍,敌人HP减少200，并暂停3回合反击\n\n\n");
diangun--;
guai.health-=200;
yun=3;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态,不能使用电棍!","警告",MB_OK);
break;
case 11:
if(battle&&place_sign==place.sea1||place_sign==place.sea2||place_sign==place.sea3)//在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(yulei>0)
{
SlowDisplay("使用鱼雷,敌人HP减少500\n\n\n");
yulei--;
guai.health-=500;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态或不在海中,不能使用鱼雷!","警告",MB_OK);
break;
case 12:
if(battle)//在战斗中(battle=1),否则(battle=0)不能使用攻击性物品
{
if(zidan>0)
{
SlowDisplay("使用步枪,敌人HP减少300\n\n\n");
zidan--;
guai.health-=300;
AttackResult();
}
}
else MessageBox(NULL,"非战斗状态,不能使用步枪!","警告",MB_OK);
break;
case 0:break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
}
}
int AttackResult() //攻击结果:判断是否获胜 是否获得物品 和 是否升级
{
if(guai.health<=0)
{
battle=0;
printf("战斗胜利!获得金币%d,经验%d\n\n\n",guai.money,guai.exp);
player.exp+=guai.exp;
bi++;
yun=0;
s1++;
if(s1=2)
{
zidan++;s1=0;
}
player.range_exp+=guai.exp;
money+=guai.money; s=SuiJi();
if(s<guai.wupinpro)
{
SlowDisplay("从敌人尸骸中发现");
printf("%s\n\n\n",guai.wupin);
AddWupin(guai.wupin_sign);
}
WhetherLevelUp();
if(strcmp(guai.name,"大学渣")==0)  
{
puts("神秘校长：看来你还挺强啊，来，我们亲自较量一下\n") ;
battle=1;
guai=oldman;
printf("%s冲了过来，并扇了你一巴掌，大吼一声：你不好好做作业，来这搞什么事情！！！（你的HP减少了%d）\n\n",guai.name,guai.attack+s-player.defense/3);
player.health-=guai.attack+s-player.defense/3;
BattleAct();
}
if(strcmp(guai.name,"校长")==0)
{
puts("战斗胜利，救出了校花！！！");
getchar();
getchar();
exit(0);
}
return 1; //攻击有结果了返回1,否则返回0,用于判断是否继续做战斗行为
}
else 
{
int s=SuiJi();
if(yun==0)
{
if(SuiJi100()>=guai.double_attack)
{
if((guai.attack+s-player.defense/3)<0)
{
player.health-=1;
printf("%s反击,你的HP减少了 1\n\n",guai.name);

}
else
{
player.health-=guai.attack+s-player.defense/3;
printf("%s反击,你的HP减少了%d\n\n",guai.name,guai.attack+s-player.defense/3);
}
}
else
{
if((2*guai.attack+s-player.defense/3)<0)
{
player.health-=2;
printf("%s爆发！！！你的HP减少了 2\n\n",guai.name);
}
else
{
player.health-=2*guai.attack+s-player.defense/3;
printf("%s爆发！！！你的HP减少了%d\n\n",guai.name,2*guai.attack+s-player.defense/3);
}
}
}
else
{
printf("%s晕了，无法反击！\n\n",guai.name);
yun--;
}
if(player.health<0)
{
battle=0;
if(player.air!=0)
printf("%s战死!金币掉落%d\n\n\n",player.name,player.level*100);
else printf("%s窒息!金币掉落%d\n\n\n",player.name,player.level*100);
money-=player.level*100;
player.health=player.max_health/5;
OrdinaryAct();
return 1;
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
case 4:strongman_arm++;break;
case 5:gong4n++; break;
case 6:gong3n++; break;
case 7:gong2n++; break;
case 8:gong1n++; break;
case 9:yaoshi1++;break;
case 10:gong5n++; break;
case 11:fang5n++; break;
case 12:yaoshi2++;break;
case 13:lion_hand++;break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
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
SlowDisplay(" 升级!\n\n\n攻击力+5, 防御力+5, HP上限+20,氧气上限+1\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=5;
player.defense+=5;
player.max_health+=20;
player.health=player.max_health;
player.max_air+=1; 
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=100;
}
else
{
printf("好厉害!连升%d级!",l1);
printf("攻击力+%d, 防御力+%d, HP上限+%d,氧气上限+%d \n\n\n",5*l1,5*l1,20*l1,1*l1);
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=5*l1;
player.defense+=5*l1;
player.max_health+=20*l1;
player.health=player.max_health;
player.max_air+=1*l1; 
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
SlowDisplay(" 升级!\n\n\n攻击力+5, 防御力+5, HP上限+20,氧气上限+1\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=5;
player.defense+=5;
player.max_health+=20;
player.health=player.max_health;
player.max_air++;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=300;
}
else
{
printf("好厉害!连升%d级!",l1);
printf("攻击力+%d, 防御力+%d, HP上限+%d,氧气上限+%d\n\n\n",5*l2,5*l2,20*l2,1*l2);
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=5*l2;
player.defense+=5*l2;
player.max_health+=20*l2;
player.health=player.max_health;
player.max_air+=1*l2;
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
SlowDisplay(" 升级!\n\n\n攻击力+5, 防御力+5, HP上限+20,氧气上限+1\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=5;
player.defense+=5;
player.max_health+=20;
player.health=player.max_health;
player.max_air++;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=600;
}
else
{
printf("好厉害!连升%d级!",l1);
printf("攻击力+%d, 防御力+%d, HP上限+%d,氧气上限+%d\n\n\n",5*l3,5*l3,20*l3,1*l3);
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=5*l3;
player.defense+=5*l3;
player.max_health+=20*l3;
player.health=player.max_health;
player.max_air+=l3;
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
puts("=============================================================================");
printf("要做什么?\n\n\n 1,移动 2,道具 3,对话 4,查看状态 5,装备 0,退出游戏\n\n\n");
puts("=============================================================================");
switch(scanf("%d",&choose_number),choose_number)
{ 
case 1: //显示移动菜单
SlowDisplay("要去哪里?\n\n\n");
printf("1,酒吧 2,旅馆 3,山脉 4,森林一层 5,森林二层 6,森林三层 7,草原一层 8,草原二层 9,草原三层 10,海洋一层 11,海洋二层 12,海洋三层 13,马勒戈壁\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:place_sign=place.bar; //记录目前位置-酒吧
// OrdinaryAct();
system("color 6F");
break;
case 2:place_sign=place.hotel; //进入旅店
system("color 1F");
SlowDisplay("要住店吗? 400个金币 1,是 0,否\n\n\n");
choose_number=1;
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money-400<0) //判断钱是否够
{
SlowDisplay("Sorry,你的钱不够~\n\n\n"); 
}
else 
{
SlowDisplay("好好休息\n\tHP满\n\t\t第二天了\n\n");
money-=400; //花费400住店费
player.health=player.max_health; //体力满
}
break;
case 0:SlowDisplay("下次再来!\n\n\n");break;
default:printf("hotel talk error!\n\n\n");
}
place_sign=0; break;
case 3:
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
}
break;
case 4:
place_sign=place.forest1;
system("color 2F");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=xiyi;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=witch;
printf("%s飘了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
//不用调用OAct函数,会自动执行OAct函数;
}
break;
case 5:
place_sign=place.forest2;
system("color 2F");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=witch;
printf("%s飘了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=strongman;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
}
break;
case 6:
place_sign=place.forest3;
system("color 2F");
s=SuiJi(); 
if(s<6)
{
battle=1;
guai=strongman;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=big_strongman;
SlowDisplay("一阵巨响在森林中回响：咚！！！咚！！！咚！！！随即森林巨人王扑了过来！！！\n\n\n");
BattleAct();0;
}
else
{
SlowDisplay("这里安全\n\n\n");
}
break;
case 7:
place_sign=place.grass1;
system("color A0");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=bee;
printf("%s飞了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=horse;
printf("%s冲了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
}
break;
case 8:
place_sign=place.grass2;
system("color A0");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=horse;
printf("%s冲了过来!\n\n\n",guai.name);
BattleAct(); }
else if(s<9)
{
battle=1;
guai=lion;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("这里安全\n\n\n");
}
break;
case 9:
place_sign=place.grass3;
system("color A0");
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=lion;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=lions;
SlowDisplay("一大波狮子飞快的冲了过来！！！\n\n\n");
BattleAct();0;
}
else
{
SlowDisplay("这里安全\n\n\n");
}
break;
case 10:
place_sign=place.sea1;
system("color 9F");
s=SuiJi(); 
if(s<4)
{
battle=1;
guai=fish;
printf("%s游了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<7)
{
battle=1;
guai=pangxie;
printf("%s爬了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("一群小鱼撞了过来！！！%s受了小伤。\n\n\n",player.name);
player.health=player.health-5;
}
else
{
SlowDisplay("这里安全\n\n\n");
}
break;
case 11:
place_sign=place.sea2;
system("color 9F");
s=SuiJi(); 
if(yaoshi1>0)
{
yaoshi1--; 
if(s<4)
{
battle=1;
guai=smallshark;
printf("%s游了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<7)
{
battle=1;
guai=lanjing;
SlowDisplay("小...蓝...鲸...缓...慢...的...游...了...过...来...\n\n\n");
BattleAct();
}
else if(s<9)
{
battle=0;
printf("一群小鱼撞了过来！！！%s受了小伤。\n\n\n",player.name);
player.health=player.health-5;
yaoshi1++;
}
else
{
SlowDisplay("这里安全\n\n\n");
yaoshi1++;
}
}
else
{
SlowDisplay("先去海洋一层拿把钥匙吧\n\n\n");
}
break;
case 12:
place_sign=place.sea3;
system("color 9F");
s=SuiJi(); 
if(yaoshi2>0)
{
yaoshi2--;
if(s<4)
{
battle=1;
guai=wugui;
SlowDisplay("巨......龟......以......一......种......慢......到......令......人......绝......望......的......速......度......游......了......过......来......\n\n\n");
BattleAct();
}
else if(s<7)
{
battle=1;
guai=shark;
printf("%s飞快的游了过来!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("一群小鱼撞了过来！！！%s受了小伤。\n\n\n",player.name);
yaoshi2++;
player.health=player.health-5;
}
else
{
SlowDisplay("这里安全\n\n\n");
yaoshi2++;
}
}
else
{
SlowDisplay("先去海洋二层拿把钥匙吧\n\n\n");
}
break;
case 13:
place_sign=place.mlgb;
system("color 8F");
s=SuiJi(); 
if(s<5)
{
printf("黄沙漫天，%s什么也看不见\n\n\n",player.name);
}
else if(s<9)
{
battle=1; 
if(strongman_arm>=1&&gong5n>=1&&fang5n>=1&&lion_hand>=1)
{
SlowDisplay("神秘校长:\n\n\n 哈哈,年轻人,做的不错,不过...嘿嘿,你上当啦!巨人之臂,雄狮之爪,狂鲨利齿和神龟之盾我都要了,校花你也别想带走!\n\n\n");
strongman_arm--;gong5n--;fang5n--;
guai=shitu;
printf("%s扑了过来!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("神秘校长:\n\n\n 年轻人,你好啊.如果你有巨人之臂,雄狮之爪,狂鲨利齿和神龟之盾我可以告诉你校花的下落哦~\n\n\n");
}
break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
}
break;
case 2: ChooseWupin();break; //显示道具,并可以使用.
case 3: //对话选项
if(place_sign==place.bar) 
{
SlowDisplay("要和谁说话?\n\n\n1,红发女郎 2,赏金猎人 3,酒吧老板  4,道具店老板\n\n\n"); //显示对话人物
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
SlowDisplay("红发女郎:\n\n\n 吧台边那个Hunter好帅啊!(~脸红~)\n\n\n听说他经常外出打猎,外面的路他应该很熟悉的!\n\n\n");
break;
case 2:
SlowDisplay("赏金猎人:\n\n\n 年轻人!\n\n\n 你需要从山脉里的怪兽开始，\n\n\n 打败森林最深处的巨人王、草原最深处的狮群、海洋最深处的巨龟和巨兽鲨!\n\n\n 最后杀死校长才可以救回校花!\n\n\n");
break;
case 3:
printf("要喝点什么?\n\n\n 1,二锅头20金币 HP+30 2,XO酒50金币 HP+100 3,人头马100金币 HP+150  4,我要卖东西 0,返回\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<20)
{
SlowDisplay("钱不够!"); 
}
else
{
if(player.health+30<=player.max_health)
{
SlowDisplay("HP+30.");
money-=20;
player.health+=30;
}
else
{
SlowDisplay("HP满了"); 
player.health=player.max_health;
}
}
break;
case 2:if(money<50)
{
SlowDisplay("钱不够!"); 
}
else
{
if(player.health+80<=player.max_health)  
{
SlowDisplay("HP+80.");
money-=50;
player.health+=80;
} else
{
SlowDisplay("HP满了"); 
player.health=player.max_health;
}
}
break;
case 3:if(money<100)
{
SlowDisplay("钱不够!"); 
}
else
{
if(player.health+150<=player.max_health)
{
SlowDisplay("HP+150.");
money-=100;
player.health+=150;
}
else
{
SlowDisplay("HP满了"); 
player.health=player.max_health;
}
}
break;
case 4:SlowDisplay("要卖啥？ 1,匕首50金币  2,长剑100金币  3,布衣50金币  4,铁甲100金币   0,返回\n\n\n");
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(gong1n>1)
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
case 2:if(gong2n>1)
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
case 3:if(fang1n>1)
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
case 4:if(fang2n>1)
{
SlowDisplay("金币加100.\n");
fang2n--;
money+=10;
}
else 
{
SlowDisplay("铁甲不够\n");
}
break; 
}
}
break;
printf("要喝点什么?\n\n\n 1,二锅头20金币 HP+30 2,XO酒50金币 HP+100 3,人头马100金币 HP+150  4,我要卖东西 0,返回\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
case 0:SlowDisplay("下次再来!\n");break;
}
} 
break;
case 4:printf("要买点什么?\n\n\n 1：止血草100金币 2：急救包180金币 3：云南白药200金币 4：手雷150金币  5：氧气袋100金币  6：电棍1500金币  7：鱼雷500金币  0,返回\n\n\n");
buy_number=1;
while(buy_number)
{
switch(scanf("%d",&buy_number),buy_number)
{
case 1:if(money<100)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("止血草+1\n");
money=money-100;
cao++;
}
break;
case 2:if(money<180)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("急救包+1\n");
money=money-180;
jijiubao++;
}
break;
case 3:if(money<200)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("云南白药+1\n");
money=money-200;
baiyao++;
} 
break;
case 4:if(money<150)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("手雷+1\n");
money=money-150;
boom++;
} 
break;
case 5:if(money<100)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("氧气袋+1\n");
money=money-100;
aircase++;
}
break;
case 6:if(money<1500)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("电棍+1\n");
money=money-1500;
diangun++;
}
break;
case 7:if(money<500)
{
SlowDisplay("钱不够!\n"); 
}
else
{
SlowDisplay("鱼雷+1\n");
money=money-500;
yulei++;
}
break;
case 0:SlowDisplay("下次在来!\n");break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
}
}
}
}
else SlowDisplay("这里好像没人可以聊天\n\n\n");
break;
case 4: DisplayState(); break; //显示状态
case 5: //装备
printf("攻装: 1,匕首:%d个 2,长剑:%d个 3,碧血剑:%d个 4,绝世好剑:%d个 9,狂鲨利齿:%d个\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
printf("防装: 5,布衣:%d个 6,铁甲:%d个 7,银甲:%d个 8,黄金圣衣:%d个 10,神龟之盾:%d个\t\t0,返回\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
SlowDisplay("选择要装备的武器或防具:\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(gong1n>=1)
{
SlowDisplay("拿起了匕首\n\n\n");
gong=gong1;
strcpy(gongname,"匕首");
}
else SlowDisplay("你没有匕首可以装备\n\n\n");
break;
case 2:if(gong2n>=1)
{
SlowDisplay("拿起了长剑\n\n\n");
gong=gong2;
strcpy(gongname,"长剑");
}
else SlowDisplay("你没有长剑可以装备\n\n\n");
break;
case 3:if(gong3n>=1)
{
SlowDisplay("拿起了碧血剑\n\n\n");
gong=gong3;
strcpy(gongname,"碧血剑");
}
else SlowDisplay("你没有碧血剑可以装备\n\n\n");
break;
case 4:if(gong4n>=1)
{
SlowDisplay("拿起了绝世好剑\n\n\n");
gong=gong4;
strcpy(gongname,"绝世好剑");
}
else SlowDisplay("你没有绝世好剑可以装备\n\n\n");
break;
case 5:if(fang1n>=1)
{
SlowDisplay("穿上了布衣\n\n\n");
fang=fang1;
strcpy(fangname,"布衣");
}
else SlowDisplay("你没有布衣可以装备\n\n\n");
break;
case 6:if(fang2>=1) 
{
SlowDisplay("穿上了铁甲\n\n\n");
fang=fang2;
strcpy(fangname,"铁甲");
}
else SlowDisplay("你没有铁甲可以装备\n\n\n");
break;
case 7:if(fang3n>=1)
{
SlowDisplay("穿上了银甲\n\n\n");
fang=fang3;
strcpy(fangname,"银甲");
}
else SlowDisplay("你没有银甲可以装备\n\n\n");
break;
case 8:if(fang4n>=1)
{
SlowDisplay("穿上了黄金圣衣\n\n\n");
fang=fang4;
strcpy(fangname,"黄金圣衣");
}
else SlowDisplay("你没有黄金圣衣可以装备\n\n\n");
break;
case 9:if(gong5n>=1)
{
SlowDisplay("拿起了狂鲨利齿\n\n\n");
gong=gong5;
strcpy(gongname,"狂鲨利齿");
}
else SlowDisplay("你没有狂鲨利齿可以装备\n\n\n");
break;
case 10:if(fang5n>=1)
{
SlowDisplay("拿起了神龟之盾\n\n\n");
fang=fang5;
strcpy(fangname,"神龟之盾");
}
else SlowDisplay("你没有神龟之盾可以装备\n\n\n");
break;
case 0:SlowDisplay("未更换装备\n\n\n");break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
}
break;
case 0: 
res=MessageBox(NULL,"确定退出游戏？","提示",MB_YESNO);
if(res==IDYES)
{
MessageBox(NULL,"数据存储中","提示",MB_OK);
//向文件中更新数据;
getchar();
MessageBox(NULL,"退出","注意",MB_OK);
return;
}
else MessageBox(NULL,"继续游戏!","提示",MB_OK);
break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
}
}
}
void DisplayState()
{
printf("%s 攻击力:%d+%d=%d 防御力:%d+%d=%d HP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health);
printf("武器: %s 防具: %s  逼能： %d  剩余氧气： %d/%d 子弹：%d \n\n\n",gongname,fangname,bi,player.air,player.max_air,zidan);
printf("等级:%d 经验:%d/%d 还需要%d经验升级 金币:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money); 
}
void BattleAct()
{
while(1)
{

puts("=============================================================================");
printf("要怎么办?\n\n\n 1,攻击 2,物品 3,查看状态 4,逃跑\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
s=SuiJi();
if(s>=guai.miss||yun!=0) 
{
printf("%s攻击! %sHP减少%d\n\n\n",player.name,guai.name,player.attack+s+gong-guai.defense/3);
guai.health-=player.attack+s+gong-guai.defense/3;
if(place_sign==place.sea1||place_sign==place.sea2||place_sign==place.sea3)player.air--;
else player.air=player.max_air;
if(player.air<=0)player.health=-1;
}
else printf("%s躲开了攻击！\n\n\n",guai.name);
if(AttackResult())return; //如果攻击有结果(敌人或玩家战死)退出函数
else continue; 
case 2: ChooseWupin();break; //选择物品,可以使用,战斗中允许使用攻击性物品
case 3:DisplayState();break; //显示状态
case 4:
s=SuiJi();
if(s<4) //40%的概率可以逃跑
{
printf("%s逃跑了~\n\n\n",player.name);
battle=0;
return;
}
else printf("%s逃跑失败!\n\n\n",player.name);
break;
default:MessageBox(NULL,"错误!","警告",MB_OK);
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
