#include<stdlib.h>//��������Ϸ�������Ĳ��� 
#include<stdio.h>
#include<time.h> //suiji 
#include<string.h>
#include<windows.h> //SLEEP����
struct Player //��ҽṹ�壬����ʼ��player
{
char name[21]; 
int attack;
int defense;
int health;
long int max_health;
int level;
int exp;
int range_exp;
long int max_exp;
}player={"����",50,40,100,100,1,0,0,100};
struct Enemy //�ֵĽṹ��,����ʼ�����ֹ�
{
char name[20];
char wupin[12];
int attack;
int defense;
int health;
int money;
long int exp;
int wupin_sign;
int wupinpro;
int double_attack;
int miss;
}strongman={"ɭ�־���","�ƽ�ʥ��",40,50,350,200,100,1,2,1,0},
witch={"ɭ��Ů��","����",25,15,100,50,50,2,2,1,1},
xiyi={"ɭ������","����",18,10,50,30,35,3,3,2,2},
big_strongman={"ɭ�־�����","����֮��",40*5,50*5,350*5,200*5,100*5,4,4,2,0},
lion={"��ԭ��ʨ","�����ý�",60,30,280,200,100,5,2,1,0},
horse={"��ԭҰ��","��Ѫ��",28,12,90,50,50,6,2,1,1}, 
bee={"��ԭ�Ʒ�","����",17,11,60,30,35,7,3,2,2},
shitu={"ʹͽ","\0",60*8,30*8,280*8,200*8,100*8,9,1,1,0},
guai={"\0","\0",0,0,0,0,0,0,0,0,0};
struct Place
{
int bar,hotel,forest1,forest2,forest3,grass1,grass2,grass3;
}place={1,2,3,4,5,6,7,8};

int max_exp=0;
int choose_number=0,s=0,strongman_arm=0,battle=0,money=500,place_sign=9;
int cao=5,jijiubao=4,baiyao=3,superbaiyao=1,boom=5,dubiao=4,atom_boom=3;
int fang=0,fang1=10,fang1n=0,fang2=20,fang2n=0,fang3=40,fang3n=0,fang4=100,fang4n=0;
int gong=0,gong1=8,gong1n=0,gong2=15,gong2n=0,gong3=25,gong3n=0,gong4=60,gong4n=0;
char gongname[20]="��",fangname[20]="��";
char proof;

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

//����Ϸ�� ����˧�� 16B35ChenZhouKai ԭ������ֹ���� ������
int i=0,j=0,k=0;
char player_name[21];

SlowDisplay("����һ�����˵��۵���������! �л������������Ϸ�С�ձ����͹��Ĺ��� ����������ˣ��������ˣ���������һ�����ҡ������Ư���Ĺ����������ߣ����������ˣ�����İ���˰����!\n\n ΰ������߰�~�������ǵĽڲ�,�������£�����������Ӫ�ȹ���!\n\n\n�����������: (20���ַ�)\n\n\n");

// sndPlaySound("res\\F005.wav",SND_LOOP);
scanf("%s",player_name); 
strncpy(player.name,player_name,20);
if(strcmp(player.name,"EVA���Ż�")==0)
{
SlowDisplay("��ӡ����� EVA���Ż� ��!�����ڿ����ؼ�������!\n\n\n EVA���Ż� ��������... �漴... ����!!!\n\n\n");//���ҳ��� 
player.attack=999;
player.defense=999;
player.health=9999;
player.max_health=9999;
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
void ChooseWupin() //ѡ����Ʒ ��ʹ��
{
printf("��Ʒ: 1,ֹѪ��%d�� 2,���Ȱ�%d�� 3,���ϰ�ҩ%d�� 4,�������ϰ�ҩ%d�� 5,����%d�� 6,����%d�� 7,����ʽԭ�ӵ�%d�� 0,����\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom);
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
player.range_exp+=guai.exp;
money+=guai.money;
s=SuiJi();
if(s<guai.wupinpro)
{
SlowDisplay("�ӵ���ʬ���з���");
printf("%s\n\n\n",guai.wupin);
AddWupin(guai.wupin_sign);
}
WhetherLevelUp();
if(strcmp(guai.name,"ʹͽ")==0)
{
puts("ս��ʤ�����ȳ������ţ��ޣ���Ĺ���������");
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
printf("%sս��!��ҵ���%d\n\n\n",player.name,player.level*100);
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
case 1:fang4n++; break;
case 2:fang3n++; break;
case 3:fang2n++; break;
case 4:strongman_arm=1;break;
case 5:gong4n++; break;
case 6:gong3n++; break;
case 7:gong2n++; break;
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
SlowDisplay(" ����!\n\n\n������+3, ������+2, HP����+20\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3;
player.defense+=2;
player.max_health+=20;
player.health=player.max_health;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=100;
}
else
{
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d\n\n\n",3*l1,2*l1,20*l1);
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3*l1;
player.defense+=2*l1;
player.max_health+=20*l1;
player.health=player.max_health;
player.level+=l1;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=100*l1;
}
}
else if(player.level<=40&&l2>0)
{
if(l2==1)
{
printf("%s",player.name);
SlowDisplay(" ����!\n\n\n������+3, ������+2, HP����+20\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3;
player.defense+=2;
player.max_health+=20;
player.health=player.max_health;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=300;
}
else
{
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d\n\n\n",3*l2,2*l2,20*l2);
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3*l2;
player.defense+=2*l2;
player.max_health+=20*l2;
player.health=player.max_health;
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
SlowDisplay(" ����!\n\n\n������+3, ������+2, HP����+20\n\n\n");
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3;
player.defense+=2;
player.max_health+=20;
player.health=player.max_health;
player.level++;
player.range_exp=0;
player.exp=player.max_exp;
player.max_exp+=600;
}
else
{
printf("������!����%d��!",l1);
printf("������+%d, ������+%d, HP����+%d\n\n\n",3*l3,2*l3,20*l3);
player.exp=player.exp+guai.exp-(player.exp+guai.exp)%100;
player.attack+=3*l3;
player.defense+=2*l3;
player.max_health+=20*l3;
player.health=player.max_health;
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
printf("1,�ư� 2,�ù� 3,ɭ��һ�� 4,ɭ�ֶ��� 5,ɭ������ 6,��ԭһ�� 7,��ԭ���� 8,��ԭ����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:place_sign=place.bar; //��¼Ŀǰλ��-�ư�
// OrdinaryAct();
break;
case 2:place_sign=place.hotel; //�����õ�
SlowDisplay("Ҫס����? 200����� 1,�� 0,��\n\n\n");
choose_number=1;
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money-200<0) //�ж�Ǯ�Ƿ�
{
SlowDisplay("Sorry,���Ǯ����~\n\n\n"); 
}
else 
{
SlowDisplay("�ú���Ϣ\n\tHP��\n\t\t�ڶ�����\n\n");
money-=200; //����200ס���
player.health=player.max_health; //������
}
break;
case 0:SlowDisplay("�´�����!\n\n\n");break;
default:printf("hotel talk error!\n\n\n");
}
place_sign=0;
break;
case 3:
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
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
//���õ���OAct����,���Զ�ִ��OAct����;
}
break;
case 4:
place_sign=place.forest2;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=witch;
printf("%s���˹���!\n\n\n",guai.name);
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
case 5:
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
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
case 6:
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
case 7:
place_sign=place.grass2;
s=SuiJi(); 
if(s<7)
{
battle=1;
guai=horse;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
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
case 8:
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
battle=1; 
if(strongman_arm)
{
SlowDisplay("��������:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!����֮����Ҫ��,������Ҳ�������!\n\n\n");
guai=shitu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
else SlowDisplay("��������:\n\n\n ������,��ð�.������о���֮��,�ҿ��Ը����㹫��������Ŷ~\n\n\n");
}
else
{
SlowDisplay("���ﰲȫ\n\n\n");
}
break;
default:printf("choose map error!\n\n\n");
}
break;
case 2: ChooseWupin();break; //��ʾ����,������ʹ��.
case 3: //�Ի�ѡ��
if(place_sign==place.bar) 
{
SlowDisplay("Ҫ��˭˵��?\n\n\n1,�췢Ů�� 2,�ͽ����� 3,�ư��ϰ�\n\n\n"); //��ʾ�Ի�����
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
SlowDisplay("�췢Ů��:\n\n\n ��̨���Ǹ�Hunter��˧��!(~����~)\n\n\n��˵�������������,�����·��Ӧ�ú���Ϥ��!\n\n\n");
break;
case 2:
if(fang1n<1&&gong1n<1)
{
SlowDisplay("�ͽ�����:\n\n\n ��Ҫ�ȹ�����!�õ���!\n\n\n ��������Ĵ��ֺͲ�ԭ���ն�,����Խ��ԽΣ��,����ذ�׺Ͳ���,�������Щ������,��ȥ��!\n\n\n");
printf("%s����:(��,��λ��������ð�!\n\n\n)",player.name);
gong1n++;
fang1n++;
}
else SlowDisplay("�ͽ�����:\n\n\n ���Ͱ�,������!\n\n\n ��Ҫ��������ֺͲ�ԭ���ŵ�!\n\n\n");
break;
case 3:
printf("Ҫ�ȵ�ʲô?\n\n\n 1,����ͷ25��� HP+20 2,XO��80��� HP+50 3,��ͷ����150��� HP+100 0,����\n\n\n");
choose_number=1;
while(choose_number)
{
switch(scanf("%d",&choose_number),choose_number)
{
case 1:if(money<25)
{
SlowDisplay("Ǯ����!"); 
}
else
{
if(player.health+20<=player.max_health)
{
SlowDisplay("HP+20.");
money-=25;
player.health+=20;
}
else
{
SlowDisplay("HP����"); 
player.health=player.max_health;
}
}
break;
case 2:if(money<80)
{
SlowDisplay("Ǯ����!"); 
}
else
{
if(player.health+50<=player.max_health)
{
SlowDisplay("HP+50.");
money-=80;
player.health+=50;
}
else
{
SlowDisplay("HP����"); 
player.health=player.max_health;
}
}
break;
case 3:if(money<150)
{
SlowDisplay("Ǯ����!"); 
}
else
{
if(player.health+100<=player.max_health)
{
SlowDisplay("HP+100.");
money-=150;
player.health+=100;
}
else
{
SlowDisplay("HP����"); 
player.health=player.max_health;
}
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
printf("��װ: 1,ذ��:%d�� 2,����:%d�� 3,��Ѫ��:%d�� 4,�����ý�:%d��\n\n\n",gong1n,gong2n,gong3n,gong4n);
printf("��װ: 5,����:%d�� 6,����:%d�� 7,����:%d�� 8,�ƽ�ʥ��:%d��\t\t0,����\n\n\n",fang1n,fang2n,fang3n,fang4n);
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
case 0:SlowDisplay("δ����װ��\n\n\n");break;
default:printf("change error!");
}
break;
case 0: 
SlowDisplay("ȷ���˳���Ϸ?(Y/N)\n\n\n");
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
printf("����: %s ����: %s \n\n\n",gongname,fangname);
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
Sleep(100);
}
} //����Ϸ�� ����˧�� 16B35ChenZhouKai ԭ������ֹ���� ������
