#include<stdlib.h>//��������Ϸ�������Ĳ��� 
#include<stdio.h>
#include<time.h> //suiji 
#include<string.h>
#include<windows.h> //SLEEP����
struct Player //��ҽṹ�壬����ʼ��player
{
char name[21]; 
int attack;
int defense; //������Ϸ1.6.2�汾���� 
int health;//������־����������������ÿ�ι�����Ҫʹ�ã����������������±��ܼ�����������ʽ���޸�bug�� 
long int max_health;//�Ż�����ʾ��������У������������ʾ�����޸ġ� 
int level; //�������²ۣ����ذ�������Ϸ�����У԰��Ϸ�� 
int exp; 
int range_exp; 
long int max_exp; 
int air;
int max_air; 
}player={"����",50,40,100,100,1,0,0,100,10,10};
struct Enemy //�ֵĽṹ��,����ʼ�����ֹ�
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
}strongman={"ɭ�־���","�ƽ�ʥ��",50,60,350,200,100,1,2,1,0},
witch={"ɭ��Ů��","����",40,30,100,50,50,2,2,1,1},
xiyi={"ɭ������","����",30,25,50,30,35,3,3,2,2},
big_strongman={"ɭ�־�����","����֮��",150,180,1200,800,400,4,4,2,0},
lion={"��ԭ��ʨ","�����ý�",70,40,280,200,100,5,2,1,0},
horse={"��ԭҰ��","��Ѫ��",50,30,90,50,50,6,2,1,1}, 
bee={"��ԭ�Ʒ�","����",30,20,60,30,35,7,3,2,2},
stone={"ɽ����ʯ","����",10,40,100,50,20,0,3,2,2},
asshole={"ɽ���ջ�","ذ��",30,10,60,50,20,8,3,2,2},
shitu={"��ѧ��","\0",350,170,1600,1200,600,9,1,1,0},
wugui={"�޹�","���֮��",100,500,500,1000,400,11,1,1,0},
shark={"������","��������",350,50,500,1000,400,10,1,1,0},
oldman={"У��","\0",570,270,2700,1800,1000,12,1,1,0}, 
guai={"\0","\0",0,0,0,0,0,0,0,0,0};
struct Place
{
int bar,hotel,forest1,forest2,forest3,grass1,grass2,grass3,mountain,mlgb,sea;
}place={1,2,3,4,5,6,7,8,9,10,11};

int max_exp=0;
int choose_number=0,s=0,strongman_arm=0,battle=0,money=1000,place_sign=11,bi=0,buy_number=0;
int cao=4,jijiubao=3,baiyao=3,superbaiyao=1,boom=4,dubiao=3,atom_boom=1,aircase=0;
int fang=0,fang1=10,fang1n=0,fang2=20,fang2n=0,fang3=40,fang3n=0,fang4=100,fang4n=0,fang5=150,fang5n=0;
int gong=0,gong1=10,gong1n=0,gong2=20,gong2n=0,gong3=40,gong3n=0,gong4=100,gong4n=0,gong5=150,gong5n=0;
char gongname[20]="��",fangname[20]="��";
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
int i=0,j=0,k=0;
char player_name[21];

SlowDisplay("����һ�����˵��۵���������! ʦ��Сʱ��ʦ����ʦ����У���˵���У�� �������ˣ��Ź֣������!\n\n ΰ������߰�~�������ǵĽڲ�,�������£�����������Ӫ��У��!\n\n\n�����������: ��20���ַ����ڣ�\n\n\n");

// sndPlaySound("res\\F005.wav",SND_LOOP);
scanf("%s",player_name); 
strncpy(player.name,player_name,20);
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("���Ӷ���� hzwer ��!�����ڿ����ؼ�������!\n\n\n     hzwer���³�ɽ... �漴... ����!!!\n\n\n");//���ҳ��� 
player.attack=999;
player.defense=999;
player.health=9999;
player.max_health=9999;
atom_boom++; 
}
if(strcmp(player.name,"��ͩѧ��")==0)
{
SlowDisplay("���Ӷ���� ��ͩѧ�� ��!�����ڿ����ؼ�������!\n\n\n    ��ͩѧ�� ���³�ɽ... �漴... ����!!!\n\n\n");//���ҳ��� 
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
return rand()%100; }


void ChooseWupin() //ѡ����Ʒ ��ʹ��
{
printf("��Ʒ: 1,ֹѪ��%d�� 2,���Ȱ�%d�� 3,���ϰ�ҩ%d�� 4,�������ϰ�ҩ%d�� 5,����%d�� 6,����%d�� 7,����ʽԭ�ӵ�%d��  8,���ܼ�����   9,������%d�� 0,����\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,aircase);
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
if(cao>0)
{
SlowDisplay("ʹ��ֹѪ��,HP����80\n\n\n");
cao--;
if(player.health+80>player.max_health)player.health=player.max_health;
else player.health+=80;
}
else SlowDisplay("û��ֹѪ����\n\n\n");
break;
case 2:
if(jijiubao>0)
{
SlowDisplay("ʹ�ü��Ȱ�,HP����100\n\n\n");
jijiubao--;
if(player.health+100>player.max_health)player.health=player.max_health;
else player.health+=100;
}
else SlowDisplay("û�м��Ȱ���\n\n\n");
break;
case 3:
if(baiyao>0)
{
SlowDisplay("ʹ�����ϰ�ҩ,HP����150\n\n\n");
baiyao--;
if(player.health+150>player.max_health)player.health=player.max_health;
else player.health+=150;
}
else SlowDisplay("û�����ϰ�ҩ��\n\n\n");
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
break;
case 5:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(boom>0)
{
SlowDisplay("ʹ������,����HP����150\n\n\n");
boom--;
guai.health-=150;
AttackResult();
}
}
else SlowDisplay("��ս��״̬,����ʹ������!\n\n\n");
break;
case 6:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(dubiao>0)
{
SlowDisplay("ʹ�ö���,����HP����300\n\n\n");
dubiao--;
guai.health-=300;
AttackResult();
}
}
else SlowDisplay("��ս��״̬,����ʹ�ö���!\n\n\n");
break;
case 7:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(atom_boom>0)
{
SlowDisplay("ʹ������ʽԭ�ӵ�,����HP����600\n\n\n");
atom_boom--;
guai.health-=600;
AttackResult();
}
}
else SlowDisplay("��ս��״̬,����ʹ������ʽԭ�ӵ�!\n\n\n");
break;
case 8:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(bi>20)
{
SlowDisplay("ʹ�ñ��ܼ�����,����HP����1500\n\n\n");
bi-=20;
guai.health-=1500;
AttackResult();
}
}
else SlowDisplay("��ս��״̬,����ʹ�ñ��ܼ�����!\n\n\n");
break;
case 9:
if(aircase>0)
{
SlowDisplay("ʹ��������,��������5\n\n\n");
player.air--;
if(player.air+5>player.max_air)player.air=player.max_air;
else player.air+=5;
}
else SlowDisplay("û����������\n\n\n");
break;
case 0:break;
default:printf("ChooseWupin error!\n\n\n");
}
}
int AttackResult() //�������:�ж��Ƿ��ʤ �Ƿ�����Ʒ �� �Ƿ�����
{
if(guai.health<=0)
{
battle=0;
printf("ս��ʤ��!��ý��%d,����%d\n\n\n",guai.money,guai.exp);
player.exp+=guai.exp;
bi++;
player.range_exp+=guai.exp;
money+=guai.money; s=SuiJi();
if(s<guai.wupinpro)
{
SlowDisplay("�ӵ���ʬ���з���");
printf("%s\n\n\n",guai.wupin);
AddWupin(guai.wupin_sign);
}
WhetherLevelUp();
if(strcmp(guai.name,"��ѧ��")==0)  
{
puts("����У���������㻹ͦǿ���������������Խ���һ��\n") ;
battle=1;
guai=oldman;
printf("%s���˹�������������һ���ƣ����һ�����㲻�ú�����ҵ�������ʲô���飡���������HP������%d��\n\n",guai.name,guai.attack+s-player.defense/3,guai.name);
BattleAct();
}
if(strcmp(guai.name,"У��")==0)
{
puts("ս��ʤ�����ȳ���У��������");
getchar();
getchar();
exit(0);
}
return 1; //�����н���˷���1,���򷵻�0,�����ж��Ƿ������ս����Ϊ
}
else 
{
int s=SuiJi();


if((guai.attack+s-player.defense/3)<0)
{
player.health-=1;
printf("%s����,���HP������ 1\n\n",guai.name);
}
else
{
player.health-=guai.attack+s-player.defense/3;
printf("%s����,���HP������%d\n\n",guai.name,guai.attack+s-player.defense/3);
}
if(player.health<0)
{
battle=0;
if(player.air!=0)
printf("%sս��!��ҵ���%d\n\n\n",player.name,player.level*100);
else printf("%s��Ϣ!��ҵ���%d\n\n\n",player.name,player.level*100);
money-=player.level*100;
player.health=player.max_health/5;
OrdinaryAct();//////////
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
case 4:strongman_arm=1;break;
case 5:gong4n++; break;
case 6:gong3n++; break;
case 7:gong2n++; break;
case 8:gong1n++; break;
case 10:gong5n++; break;
case 11:fang5n++; break;
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
SlowDisplay(" ����!\n\n\n������+5, ������+5, HP����+20,��������+1\n\n\n");
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
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d,��������+%d \n\n\n",5*l1,5*l1,20*l1,1*l1);
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
SlowDisplay(" ����!\n\n\n������+5, ������+5, HP����+20,��������+1\n\n\n");
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
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d,��������+%d\n\n\n",5*l2,5*l2,20*l2,1*l2);
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
SlowDisplay(" ����!\n\n\n������+5, ������+5, HP����+20,��������+1\n\n\n");
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
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d,��������+%d\n\n\n",5*l3,5*l3,20*l3,1*l3);
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
void OrdinaryAct() //������Ϊ�˵�(�ƶ�,��Ʒ,�Ի�,�鿴״̬,װ��,�˳���Ϸ)
{

while(1)
{
// \(1000);
// system("cls");
puts("=============================================================================");
printf("Ҫ��ʲô?\n\n\n 1,�ƶ� 2,���� 3,�Ի� 4,�鿴״̬ 5,װ�� 0,�˳���Ϸ\n\n\n");
puts("=============================================================================");
switch(scanf("%d",&choose_number),choose_number)
{ 
case 1: //��ʾ�ƶ��˵�
SlowDisplay("Ҫȥ����?\n\n\n");
printf("1,�ư� 2,�ù� 3,ɽ�� 4,ɭ��һ�� 5,ɭ�ֶ��� 6,ɭ������ 7,��ԭһ�� 8,��ԭ���� 9,��ԭ���� 10,���� 11,���ո��\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:place_sign=place.bar; //��¼Ŀǰλ��-�ư�
// OrdinaryAct();
break;
case 2:place_sign=place.hotel; //�����õ�
SlowDisplay("Ҫס����? 500����� 1,�� 0,��\n\n\n");
choose_number=1;
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money-500<0) //�ж�Ǯ�Ƿ�
{
SlowDisplay("Sorry,���Ǯ����~\n\n\n"); 
}
else 
{
SlowDisplay("�ú���Ϣ\n\tHP��\n\t\t�ڶ�����\n\n");
money-=500; //����200ס���
player.health=player.max_health; //������
}
break;
case 0:SlowDisplay("�´�����!\n\n\n");break;
default:printf("hotel talk error!\n\n\n");
}
place_sign=0; break;
case 3:
place_sign=place.mountain;
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
}
break;
case 4:
place_sign=place.forest1;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=xiyi;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=witch;
printf("%sƮ�˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
//���õ���OAct����,���Զ�ִ��OAct����;
}
break;
case 5:
place_sign=place.forest2;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=witch;
printf("%sƮ�˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=strongman;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 6:
place_sign=place.forest3;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=strongman;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=big_strongman;
SlowDisplay("һ�������ɭ���л��죺�ˣ������ˣ������ˣ������漴ɭ�־��������˹���������\n\n\n");
BattleAct();0;
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 7:
place_sign=place.grass1;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=bee;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=1;
guai=horse;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 8:
place_sign=place.grass2;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=horse;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct(); }
else if(s<9)
{
battle=1;
guai=lion;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 9:
place_sign=place.grass3;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=lion;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 10:
place_sign=place.sea;
s=SuiJi(); 
if(s<5)
{
battle=1;
guai=wugui;
SlowDisplay("��.....��.....��.....һ.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....��.....\n\n\n");
BattleAct();
}
else if(s<7)
{
battle=1;
guai=shark;
printf("%s�ɿ�����˹���!\n\n\n",guai.name);
BattleAct();
}
else if(s<9)
{
battle=0;
printf("һȺС��ײ�˹���������%s����С�ˡ�\n\n\n",player.name);
player.health=player.health-5;
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 11:
place_sign=place.mlgb;
s=SuiJi(); 
if(s<7)
{
printf("��ɳ���죬%sʲôҲ������\n\n\n",player.name);
}
else if(s<9)
{
battle=1; 
if(strongman_arm>=1&&gong5n>=1&&fang5n>=1)
{
SlowDisplay("����У��:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!����֮��,�������ݺ����֮���Ҷ�Ҫ��,У����Ҳ�������!\n\n\n");
strongman_arm--;gong5n--;fang5n--;
guai=shitu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("����У��:\n\n\n ������,��ð�.������о���֮��,�������ݺ����֮���ҿ��Ը�����У��������Ŷ~\n\n\n");
}
break;
default:printf("choose map error!\n\n\n");
}
break;
case 2: ChooseWupin();break; //��ʾ����,������ʹ��.
case 3: //�Ի�ѡ��
if(place_sign==place.bar) 
{
SlowDisplay("Ҫ��˭˵��?\n\n\n1,�췢Ů�� 2,�ͽ����� 3,�ư��ϰ�  4,���ߵ��ϰ�\n\n\n"); //��ʾ�Ի�����
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
SlowDisplay("�췢Ů��:\n\n\n ��̨���Ǹ�Hunter��˧��!(~����~)\n\n\n��˵�������������,�����·��Ӧ�ú���Ϥ��!\n\n\n");
break;
case 2:
SlowDisplay("�ͽ�����:\n\n\n ������!\n\n\n ����Ҫ��ɽ����Ĺ��޿�ʼ��\n\n\n ���ɭ������ľ���������������ľ޹�;�����!\n\n\n ���ɱ��У���ſ��ԾȻ�У��!\n\n\n");
break;
case 3:
printf("Ҫ�ȵ�ʲô?\n\n\n 1,����ͷ20��� HP+30 2,XO��50��� HP+100 3,��ͷ����100��� HP+150  4,��Ҫ������ 0,����\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<20)
{
SlowDisplay("Ǯ����!"); 
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
SlowDisplay("HP����"); 
player.health=player.max_health;
}
}
break;
case 2:if(money<50)
{
SlowDisplay("Ǯ����!"); 
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
SlowDisplay("HP����"); 
player.health=player.max_health;
}
}
break;
case 3:if(money<100)
{
SlowDisplay("Ǯ����!"); 
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
SlowDisplay("HP����"); 
player.health=player.max_health;
}
}
break;
case 4:SlowDisplay("Ҫ��ɶ�� 1,ذ��50���  2,����100���  3,����50���  4,����100���   0,����\n\n\n");
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(gong1n>1)
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
case 2:if(gong2n>1)
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
case 3:if(fang1n>1)
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
case 4:if(fang2n>1)
{
SlowDisplay("��Ҽ�100.\n");
fang2n--;
money+=10;
}
else 
{
SlowDisplay("���ײ���\n");
}
break; 
}
case 0:SlowDisplay("�´�����!\n");break;
}
break;
switch(scanf("%d",&choose_number),choose_number)

case 0:SlowDisplay("�´�����!\n");break;
}
} 
case 4:printf("Ҫ���ʲô?\n\n\n 1��ֹѪ��100��� 2�����Ȱ�180��� 3�����ϰ�ҩ200��� 4������150���  5��������100���   0,����\n\n\n");
buy_number=1;
while(buy_number)
{
switch(scanf("%d",&buy_number),buy_number)
{
case 1:if(money<100)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("ֹѪ��+1\n");
money=money-100;
cao++;
}
break;
case 2:if(money<180)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("���Ȱ�+1\n");
money=money-180;
jijiubao++;
}
break;
case 3:if(money<200)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("���ϰ�ҩ+1\n");
money=money-200;
baiyao++;
} 
break;
case 4:if(money<150)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("����+1\n");
money=money-150;
boom++;
} 
break;
case 5:if(money<100)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("������+1\n");
money=money-100;
aircase++;
}
break;
case 0:SlowDisplay("�´�����!\n");break;
default:SlowDisplay("�������\n\n\n");
}
}
}
}
else if(place_sign==place.hotel)
SlowDisplay("���ϰ���!��...��\n\n\n����æ���أ�û������~��\n\n\n");
else SlowDisplay("�������û�˿�������\n\n\n");
break;
case 4: DisplayState(); break; //��ʾ״̬
case 5: //װ��
printf("��װ: 1,ذ��:%d�� 2,����:%d�� 3,��Ѫ��:%d�� 4,�����ý�:%d�� 9,��������:%d��\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
printf("��װ: 5,����:%d�� 6,����:%d�� 7,����:%d�� 8,�ƽ�ʥ��:%d�� 10,���֮��:%d��\t\t0,����\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
SlowDisplay("ѡ��Ҫװ�������������:\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(gong1n>=1)
{
SlowDisplay("������ذ��\n\n\n");
gong=gong1;
strcpy(gongname,"ذ��");
}
else SlowDisplay("��û��ذ�׿���װ��\n\n\n");
break;
case 2:if(gong2n>=1)
{
SlowDisplay("�����˳���\n\n\n");
gong=gong2;
strcpy(gongname,"����");
}
else SlowDisplay("��û�г�������װ��\n\n\n");
break;
case 3:if(gong3n>=1)
{
SlowDisplay("�����˱�Ѫ��\n\n\n");
gong=gong3;
strcpy(gongname,"��Ѫ��");
}
else SlowDisplay("��û�б�Ѫ������װ��\n\n\n");
break;
case 4:if(gong4n>=1)
{
SlowDisplay("�����˾����ý�\n\n\n");
gong=gong4;
strcpy(gongname,"�����ý�");
}
else SlowDisplay("��û�о����ý�����װ��\n\n\n");
break;
case 5:if(fang1n>=1)
{
SlowDisplay("�����˲���\n\n\n");
fang=fang1;
strcpy(fangname,"����");
}
else SlowDisplay("��û�в��¿���װ��\n\n\n");
break;
case 6:if(fang2>=1) 
{
SlowDisplay("����������\n\n\n");
fang=fang2;
strcpy(fangname,"����");
}
else SlowDisplay("��û�����׿���װ��\n\n\n");
break;
case 7:if(fang3n>=1)
{
SlowDisplay("����������\n\n\n");
fang=fang3;
strcpy(fangname,"����");
}
else SlowDisplay("��û�����׿���װ��\n\n\n");
break;
case 8:if(fang4n>=1)
{
SlowDisplay("�����˻ƽ�ʥ��\n\n\n");
fang=fang4;
strcpy(fangname,"�ƽ�ʥ��");
}
else SlowDisplay("��û�лƽ�ʥ�¿���װ��\n\n\n");
break;
case 9:if(gong5n>=1)
{
SlowDisplay("�����˿�������\n\n\n");
gong=gong5;
strcpy(gongname,"��������");
}
else SlowDisplay("��û�п������ݿ���װ��\n\n\n");
break;
case 10:if(fang5n>=1)
{
SlowDisplay("���������֮��\n\n\n");
fang=fang5;
strcpy(fangname,"���֮��");
}
else SlowDisplay("��û�����֮�ܿ���װ��\n\n\n");
break;
case 0:SlowDisplay("δ����װ��\n\n\n");break;
default:printf("change error!");
}
break;
case 0: 
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
break;
default:SlowDisplay("�������!\n\n\n");
}
}
}
void DisplayState()
{
printf("%s ������:%d+%d=%d ������:%d+%d=%d HP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health);
printf("����: %s ����: %s  ���ܣ� %d  ʣ�������� %d/%d\n\n\n",gongname,fangname,bi,player.air,player.max_air);
printf("�ȼ�:%d ����:%d/%d ����Ҫ%d�������� ���:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money); 
}
void BattleAct()
{
while(1)
{

puts("=============================================================================");
printf("Ҫ��ô��?\n\n\n 1,���� 2,��Ʒ 3,�鿴״̬ 4,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
s=SuiJi();
printf("%s����! %sHP����%d\n\n\n",player.name,guai.name,player.attack+s+gong-guai.defense/3);
guai.health-=player.attack+s+gong-guai.defense/3;
if(place_sign==place.sea)player.air--;
else player.air=player.max_air;
if(player.air<=0)player.health=0;
if(AttackResult())return; //��������н��(���˻����ս��)�˳�����
else continue; 
case 2: ChooseWupin();break; //ѡ����Ʒ,����ʹ��,ս��������ʹ�ù�������Ʒ
case 3:DisplayState();break; //��ʾ״̬
case 4:
s=SuiJi();
if(s<4) //40%�ĸ��ʿ�������
{
printf("%s������~\n\n\n",player.name);
battle=0;
return;
}
else printf("%s����ʧ��!\n\n\n",player.name);
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
