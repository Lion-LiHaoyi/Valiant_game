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
SYSTEMTIME Time;
struct Player //��ҽṹ�壬����ʼ��player
{
char type[100];
char name[100]; 
int attack;
int defense; //������Ϸ2�汾����£����� 
int health;//������־�����׸ĵ���ԭ�汾�Ŀ�ܣ��޸Ĳ��ִ�80% 
long int max_health;//���ڸĶ����������һЩbug������OrdinaryAct()����������£���ӭ��Ұ�æ�޸� 
int level; //�������²ۣ����ذ�������Ϸ�����У԰��Ϸ�� 
int exp; //���ʳ�������ȥ�ˣ�������\����\ʧ���� 
int range_exp; //@����&��ǣ���һ���ҵ�qq1476563317һ������������Ϸ���� 
long int max_exp; 
int air;
int max_air; 
int player_number;
}hercules={"����ʿ","\0",60,40,120,120,1,0,0,100,10,10,1}, 
bombardier={"Ͷ����","\0",50,40,100,100,1,0,0,100,10,10,2}, 
beauty={"��Ů","\0",45,35,90,90,1,0,0,100,10,10,3}, 
sniper={"�ѻ���","\0",45,35,100,100,1,0,0,100,10,10,4},
key={"����","\0",45,35,100,100,1,0,0,100,10,10,5},
player={"\0","\0",0,0,0,0,0,0,0,0,0,0,0};
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
int nex; 
char a[5];
int guai_number;
}strongman={"ɭ�־���","�ƽ�ʥ��",50,60,350,200,100,1,2,5,2,1,"��",1},
witch={"ɭ����ʦ","����",40,30,100,50,50,2,2,0,1,1,"Ʈ",2},
xiyi={"ɭ������","����",30,25,50,30,35,3,3,0,0,1,"��",3},
big_strongman={"ɭ�־�����","����֮��",150,180,1200,800,400,4,4,10,3,1,"\0",4},
lions={"��ԭʨȺ","��ʨ֮צ",120,150,1800,800,400,13,4,10,3,1,"\0",5},
lion={"��ԭ��ʨ","�����ý�",70,40,280,200,100,5,2,5,2,1,"��",6},
horse={"��ԭҰ��","��Ѫ��",50,30,90,50,50,6,2,0,1,1,"��",7}, 
bee={"��ԭ�Ʒ�","����",30,20,60,30,35,7,3,0,0,1,"��",8},
stone={"ɽ����ʯ","����",10,40,100,50,20,0,4,0,0,0,"��",9},
asshole={"ɽ���ջ�","ذ��",30,10,60,50,20,8,4,0,0,0,"Ų",10},
shitu={"��ѧ��","\0",350,170,1600,1200,600,-1,0,15,3,1,"\0",11},
wugui={"�޹�","���֮��",100,500,500,1000,400,11,3,10,2,1,"\0",12},
shark={"������","��������",350,50,500,1000,400,10,3,10,3,1,"\0",13},
fish={"ʳ����","������һ�ص�Կ��",35,25,70,40,40,9,8,0,0,1,"��",14},
pangxie={"�з","������һ�ص�Կ��",30,35,70,40,40,9,8,0,0,1,"��",15},
smallshark={"С��","������һ�ص�Կ��",45,35,100,50,50,12,7,0,1,1,"��",16},
lanjing={"С����","������һ�ص�Կ��",30,50,200,50,50,12,7,0,1,1,"\0",17},
oldman={"У��","\0",570,270,2700,1800,1000,-1,0,20,4,1,"\0",18}, 
guai={"\0","\0",0,0,0,0,0,0,0,0,0,0,"\0",0},
guai1={"\0","\0",0,0,0,0,0,0,0,0,0,0,"\0",0},
guai2={"\0","\0",0,0,0,0,0,0,0,0,0,0,"\0",0};
struct Place
{
int sign;
char name[10];
}
school={0,"ѧУ"} ,
bar={1,"�ư�"},
hotel={2,"�õ�"},
forest={14,"ɭ�ֱ���"},
forest1={3,"ɭ��һ��"},
forest2={4,"ɭ�ֶ���"},
forest3={5,"ɭ������"},
grass={15,"��ԭ����"},
grass1={6,"��ԭһ��"},
grass2={7,"��ԭ����"},
grass3={8,"��ԭ����"},
mountain={9,"ɽ��"},
mountain1={17,"ɽ��"},
mlgb={10,"���ո��"},
sea={16,"����"},
sea1={11,"����һ��"},
sea2={12,"�������"},
sea3={13,"��������"},
place={0,"\0"};
int max_exp=0;
int choose_number=0,s=0,strongman_arm=0,lion_hand=0,battle=0,money=1000,bi=0,yun=0,yaoshi1=0,yaoshi2=0,s1=0,s2=0,res,number=0;
int cao=4,jijiubao=3,baiyao=3,superbaiyao=1,boom=4,dubiao=3,atom_boom=1,aircase=1,diangun=1,yulei=1,zidan=1;
int fang=0,fang1=10,fang1n=0,fang2=20,fang2n=0,fang3=40,fang3n=0,fang4=100,fang4n=0,fang5=150,fang5n=0;
int gong=0,gong1=10,gong1n=0,gong2=20,gong2n=0,gong3=40,gong3n=0,gong4=100,gong4n=0,gong5=150,gong5n=0;
char gongname[20]="��",fangname[20]="��";
char proof;
char *p;
char fujin1[10]="��",fujin2[10]="��",fujin3[10]="��",fujin4[10]="��",direction;
void AddWupin(int);
int AttackResult();
void BattleAct();
void ChooseWupin();
void DisplayState();
void OrdinaryAct(); 
int SuiJi();
int SuiJi100();
void WhetherLevelUp();
void Battle();
void Map();
void Menu();
void Setjindutiao(int); 
void SlowDisplay(char *); 
void gotoxy(int,int);
int main()
{
system("mode con cols=150 lines=150"); 
system("color 0F");
int i=0,j=0,k=0;
char player_name[21];
res=MessageBox(NULL,"׼���ÿ�ʼ��Ϸ����","��ʾ",MB_YESNO);
if(res==IDNO)
{
MessageBox(NULL,"̫���˰ɣ�","��ʾ",MB_OK);
return 0;
}
Setjindutiao(25);
SlowDisplay("����һ�����˵��۵���������! ʦ��Сʱ��ʦ����ʦ����У���˵���У���������ˣ��Ź֣������!\n\n ΰ������߰�~�������ǵĽڲ�,�������£�����������Ӫ��У��!\n\n\n");
SlowDisplay("ѡ�����뵱�Ľ�ɫ��1������ʿ  2��Ͷ����  3����Ů  4���ѻ���  5��������\n\n\n");
do
{
switch(scanf("%d",&number),number)
{
case 1:player=hercules;break;
case 2:player=bombardier;boom+=2;break;
case 3:player=beauty;break;
case 4:player=sniper;zidan+=5;break;
case 5:player=key;break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
}
while(number!=1&&number!=2&&number!=3&&number!=4&&number!=5);
SlowDisplay("�����������: ��50���ַ����ڣ�\n\n\n");// sndPlaySound("res\\F005.wav",SND_LOOP);
scanf("%s",player.name); 
if(strcmp(player.name,"hzwer")==0)
{
SlowDisplay("���Ӷ����hzwer��!�����ڿ����ؼ�������!\n\n\n     hzwer���³�ɽ... �漴... ����!!!\n\n\n");//���ҳ��� 
player.attack=999;
player.defense=999;
player.health=9999;
player.max_health=9999;
atom_boom++; 
}
if(strcmp(player.name,"��ͩѧ��")==0)
{
SlowDisplay("���Ӷ������ͩѧ����!�����ڿ����ؼ�������!\n\n\n    ��ͩѧ�����³�ɽ... �漴... ����!!!\n\n\n");//���ҳ��� 
player.attack=100;
player.defense=100;
player.health=1000;
player.max_health=1000;
atom_boom++; 
bi+=10;
}
strcat(player.type,player.name);
strcpy(player.name,player.type);
place=school;
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
gotoxy(22,2);
printf("��Ʒ:\n1,ֹѪ��%d��\n2,���Ȱ�%d��\n3,���ϰ�ҩ%d��\n4,�������ϰ�ҩ%d��\n5,����%d��\n6,����%d��\n7,����ʽԭ�ӵ�%d��\n8,���ܼ�����\n9,������%d��\n10,���%d��\n11,����%d��\n12,�ѻ�ǹ\n0,����\n\n\n",cao,jijiubao,baiyao,superbaiyao,boom,dubiao,atom_boom,aircase,diangun,yulei);
scanf("%d",&choose_number);
Setjindutiao(20);
switch(choose_number)
{
case 1:
if(cao>0)
{
SlowDisplay("ʹ��ֹѪ��,HP����80\n\n\n");
cao--;
if(player.health+80>player.max_health)player.health=player.max_health;
else player.health+=80;
}
else MessageBox(NULL,"û��ֹѪ����","ע��",MB_OK);
break;
case 2:
if(jijiubao>0)
{
SlowDisplay("ʹ�ü��Ȱ�,HP����100\n\n\n");
jijiubao--;
if(player.health+100>player.max_health)player.health=player.max_health;
else player.health+=100;
}
else MessageBox(NULL,"û�м��Ȱ���","ע��",MB_OK);
break;
case 3:
if(baiyao>0)
{
SlowDisplay("ʹ�����ϰ�ҩ,HP����150\n\n\n");
baiyao--;
if(player.health+150>player.max_health)player.health=player.max_health;
else player.health+=150;
}
else MessageBox(NULL,"û�����ϰ�ҩ��","ע��",MB_OK);
break;
case 4:
if(superbaiyao>0)
{
SlowDisplay("ʹ�ó������ϰ�ҩ,HP����200\n\n\n");
superbaiyao--;
if(player.health+200>player.max_health)player.health=player.max_health;
else player.health+=200;
}
else MessageBox(NULL,"û�г������ϰ�ҩ��","ע��",MB_OK);
break;
case 5:
if(battle&&place.sign!=sea1.sign&&place.sign!=sea2.sign&&place.sign!=sea3.sign) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(boom>0)
{
SlowDisplay("ʹ������,����HP����150\n\n\n");
boom--;
guai.health-=150;
AttackResult();
}
}
else MessageBox(NULL,"��ս��״̬���ں���,����ʹ������!","����",MB_OK);
break;
case 6:
if(battle&&place.sign!=sea1.sign&&place.sign!=sea2.sign&&place.sign!=sea3.sign) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(dubiao>0)
{
SlowDisplay("ʹ�ö���,����HP����300\n\n\n");
dubiao--;
guai.health-=300;
AttackResult();
}
}
else MessageBox(NULL,"��ս��״̬���ں���,����ʹ�ö���!","����",MB_OK);
break;
case 7:
if(battle&&place.sign!=sea1.sign&&place.sign!=sea2.sign&&place.sign!=sea3.sign) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(atom_boom>0)
{
SlowDisplay("ʹ������ʽԭ�ӵ�,����HP����600\n\n\n");
atom_boom--;
guai.health-=600;
AttackResult();
}
}
else MessageBox(NULL,"��ս��״̬���ں���,����ʹ������ʽԭ�ӵ�!","����",MB_OK);
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
else MessageBox(NULL,"��ս��״̬,����ʹ�ñ��ܼ�����!","����",MB_OK);
break;
case 9:
if(aircase>0)
{
SlowDisplay("ʹ��������,��������5\n\n\n");
player.air--;
if(player.air+5>player.max_air)player.air=player.max_air;
else player.air+=5;
}
else MessageBox(NULL,"û����������","ע��",MB_OK);
break;
case 10:
if(battle) //��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(diangun>0)
{
SlowDisplay("ʹ�õ��,����HP����200������ͣ3�غϷ���\n\n\n");
diangun--;
guai.health-=200;
yun=3;
AttackResult();
}
}
else MessageBox(NULL,"��ս��״̬,����ʹ�õ��!","����",MB_OK);
break;
case 11:
if(battle&&place.sign==sea1.sign||place.sign==sea2.sign||place.sign==sea3.sign)//��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(yulei>0)
{
SlowDisplay("ʹ������,����HP����500\n\n\n");
yulei--;
guai.health-=500;
AttackResult();
}
}
else MessageBox(NULL,"��ս��״̬���ں���,����ʹ������!","����",MB_OK);
break;
case 12:
if(battle)//��ս����(battle=1),����(battle=0)����ʹ�ù�������Ʒ
{
if(zidan>0)
{
SlowDisplay("ʹ�þѻ�ǹ,����HP����300\n\n\n");
zidan--;
guai.health-=300;
AttackResult();
}
}
else MessageBox(NULL,"��ս��״̬,����ʹ�þѻ�ǹ!","����",MB_OK);
break;
case 0:break;
default:MessageBox(NULL,"����!","����",MB_OK);
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
yun=0;
s1++;
if(s1=2)
{
zidan++;s1=0;
}
player.range_exp+=guai.exp;
money+=guai.money; s=SuiJi();
system("pause");
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
printf("%s���˹�������������һ���ƣ����һ�����㲻�ú�����ҵ�������ʲô���飡���������HP������%d��\n\n",guai.name,guai.attack+s-player.defense/3);
player.health-=guai.attack+s-player.defense/3;
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
if(yun==0)
{
gotoxy(3,5);
printf("\t\t\t");
gotoxy(3,5);
if(SuiJi100()>=guai.double_attack)
{
if((guai.attack+s-(player.defense+fang)/3)<0)
{
player.health-=1;
printf("-1\n");
}
else
{
player.health-=guai.attack+s-(player.defense+fang)/3;
printf("-%d\n",guai.attack+s-(player.defense+fang)/3);
}
}
else
{
if((2*guai.attack+s-(player.defense+fang)/3)<0)
{
player.health-=2;
printf("-2!!!\n");
}
else
{
player.health-=2*guai.attack+s-(player.defense+fang)/3;
printf("-%d!!!\n",2*guai.attack+s-(player.defense+fang)/3);
}
}
}
else
{
gotoxy(3,25);
printf("%s���ˣ��޷�������\n\n",guai.name);
yun--;
}
if(player.health<0)
{
battle=0;
if(player.air!=0)
printf("%sս��!��ҵ���%d\n\n\n",player.name,player.level*100);
else printf("%s��Ϣ!��ҵ���%d\n\n\n",player.name,player.level*100);
money-=player.level*100;
player.health=player.max_health/5;
system("pause");
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
default:MessageBox(NULL,"����!","����",MB_OK);
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
Setjindutiao(25); 
if(place.sign==0||place.sign==1||place.sign==2){strcpy(fujin1,bar.name);strcpy(fujin2,hotel.name);strcpy(fujin3,"û����");strcpy(fujin4,"û����");}
else if(place.sign==3||place.sign==4||place.sign==5||place.sign==14){strcpy(fujin1,forest.name);strcpy(fujin2,forest1.name);strcpy(fujin3,forest2.name);strcpy(fujin4,forest3.name);}
else if(place.sign==6||place.sign==7||place.sign==8||place.sign==15){strcpy(fujin1,grass.name);strcpy(fujin2,grass1.name);strcpy(fujin3,grass2.name);strcpy(fujin4,grass3.name);}
else if(place.sign==11||place.sign==12||place.sign==13||place.sign==16){strcpy(fujin1,sea.name);strcpy(fujin2,sea1.name);strcpy(fujin3,sea2.name);strcpy(fujin4,sea3.name);}
else if(place.sign==9||place.sign==10||place.sign==17){strcpy(fujin1,mountain.name);strcpy(fujin2,mountain1.name);strcpy(fujin3,mlgb.name);strcpy(fujin4,"û����");}
if(player.player_number==key.player_number){yaoshi1=1;yaoshi2=1;}
printf("\n\n\t������%s",place.name);
if(place.sign==0)Map();
else
{
gotoxy(12,40);
printf("5����ѧУ");
}
gotoxy(21,4);
printf("\t�����ĵص㣺1��%s\t2��%s\t3��%s\t4��%s\n\t�˵�(m)\n",fujin1,fujin2,fujin3,fujin4);
puts("=============================================================================");
puts("Ҫȥ����?");
scanf("%c",&direction);
Setjindutiao(20);
switch(place.sign)
{
case 0:
switch(direction)
{
case 'w':place=grass;system("color A0");break;
case 's':place=forest;system("color 2F");break;
case 'a':place=mountain;system("color 70");break;
case 'd':place=sea;system("color 9F");break;
case '1':place=bar;system("color 6F");break;
case '2':place=hotel;system("color 1F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 1:
switch(direction)
{
case '1':place=bar;break;
case '2':place=hotel;break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 2:
switch(direction)
{
case '1':place=bar;break;
case '2':place=hotel;break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 3:
switch(direction)
{
case '1':place=forest;break;
case '2':place=forest1;Battle();break;
case '3':place=forest2;Battle();break;
case '4':place=forest3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 4:
switch(direction)
{
case '1':place=forest;break;
case '2':place=forest1;Battle();break;
case '3':place=forest2;Battle();break;
case '4':place=forest3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 5:
switch(direction)
{
case '1':place=forest;break;
case '2':place=forest1;Battle();break;
case '3':place=forest2;Battle();break;
case '4':place=forest3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 14:
switch(direction)
{
case '1':place=forest;break;
case '2':place=forest1;Battle();break;
case '3':place=forest2;Battle();break;
case '4':place=forest3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 6:
switch(direction)
{
case '1':place=grass;break;
case '2':place=grass1;Battle();break;
case '3':place=grass2;Battle();break;
case '4':place=grass3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 7:
switch(direction)
{
case '1':place=grass;break;
case '2':place=grass1;Battle();break;
case '3':place=grass2;Battle();break;
case '4':place=grass3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 8:
switch(direction)
{
case '1':place=grass;break;
case '2':place=grass1;Battle();break;
case '3':place=grass2;Battle();break;
case '4':place=grass3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 15:
switch(direction)
{
case '1':place=grass;break;
case '2':place=grass1;Battle();break;
case '3':place=grass2;Battle();break;
case '4':place=grass3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 11:
switch(direction)
{
case '1':place=sea;break;
case '2':place=sea1;Battle();break;
case '3':place=sea2;Battle();break;
case '4':place=sea3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 12:
switch(direction)
{
case '1':place=sea;break;
case '2':place=sea1;Battle();break;
case '3':place=sea2;Battle();break;
case '4':place=sea3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 13:
switch(direction)
{
case '1':place=sea;break;
case '2':place=sea1;Battle();break;
case '3':place=sea2;Battle();break;
case '4':place=sea3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 16:
switch(direction)
{
case '1':place=sea;break;
case '2':place=sea1;Battle();break;
case '3':place=sea2;Battle();break;
case '4':place=sea3;Battle();break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 9:
switch(direction)
{
case '1':place=mountain;break;
case '2':place=mountain1;Battle();break;
case '3':place=mlgb;
system("color 8F");
s=SuiJi(); 
if(s<5)
{
printf("��ɳ���죬%sʲôҲ������\n\n\n",player.name);
}
else if(s<9)
{
Setjindutiao(25);
battle=1; 
if(strongman_arm>=1&&gong5n>=1&&fang5n>=1&&lion_hand>=1)
{
SlowDisplay("����У��:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!����֮��,��ʨ֮צ,�������ݺ����֮���Ҷ�Ҫ��,У����Ҳ�������!\n\n\n");
strongman_arm--;gong5n--;fang5n--;
guai=shitu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
}
break;
case 10:
switch(direction)
{
case '1':place=mountain;break;
case '2':place=mountain1;Battle();break;
case '3':place=mlgb;place=mlgb;
system("color 8F");
s=SuiJi(); 
if(s<5)
{
printf("��ɳ���죬%sʲôҲ������\n\n\n",player.name);
}
else if(s<9)
{
Setjindutiao(25);
battle=1; 
if(strongman_arm>=1&&gong5n>=1&&fang5n>=1&&lion_hand>=1)
{
SlowDisplay("����У��:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!����֮��,��ʨ֮צ,�������ݺ����֮���Ҷ�Ҫ��,У����Ҳ�������!\n\n\n");
strongman_arm--;gong5n--;fang5n--;
guai=shitu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
}
break;
case 17:
switch(direction)
{
case '1':place=mountain;break;
case '2':place=mountain1;Battle();break;
case '3':place=mlgb;place=mlgb;
system("color 8F");
s=SuiJi(); 
if(s<5)
{
printf("��ɳ���죬%sʲôҲ������\n\n\n",player.name);
}
else if(s<9)
{
Setjindutiao(25);
battle=1; 
if(strongman_arm>=1&&gong5n>=1&&fang5n>=1&&lion_hand>=1)
{
SlowDisplay("����У��:\n\n\n ����,������,���Ĳ���,����...�ٺ�,���ϵ���!����֮��,��ʨ֮צ,�������ݺ����֮���Ҷ�Ҫ��,У����Ҳ�������!\n\n\n");
strongman_arm--;gong5n--;fang5n--;
guai=shitu;
printf("%s���˹���!\n\n\n",guai.name);
BattleAct();
}
break;
case '5':place=school;system("color 0F");break;
case 'm':Menu();break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
}
break;
}
}
}
void Battle()
{
int s=SuiJi();
s2=1;
switch(place.sign)
{
case 3:guai1=xiyi;guai2=witch;break;
case 4:guai1=witch;guai2=strongman;break;
case 5:guai1=strongman;guai2=big_strongman;break;
case 6:guai1=bee;guai2=horse;break;
case 7:guai1=horse;guai2=lion;break;
case 8:guai1=lion;guai2=lions;break;
case 9:guai1=asshole;guai2=stone;break;
case 11:guai1=fish;guai2=pangxie;break;
case 12:guai1=lanjing;guai2=smallshark;break;
case 13:guai1=wugui;guai2=shark;break;
}
if(place.sign<10)
{
if(s<6)guai=guai1;
else if(s<9)guai=guai2;
else
{
SlowDisplay("\n\n\t\t���ﰲȫ\n\n\n");
OrdinaryAct();
}
}
else
{
if(s<4)guai=guai1;
else if(s<7)guai=guai2;
else if(s<9) 
{
printf("\n\n\t\tһȺС��ײ�˹���������%s����С�ˡ�\n\n\n",player.name);
if(place.sign==12)yaoshi1++;
else if(place.sign==13)yaoshi2++;
player.health=player.health-5;
OrdinaryAct();
}
else
{
if(place.sign==12)yaoshi1++;
else if(place.sign==13)yaoshi2++;
SlowDisplay("\n\n\t\t���ﰲȫ\n\n\n");
OrdinaryAct();
}
}
switch(guai.guai_number)
{
case 4:
SlowDisplay("\n\n\t\tһ�������ɭ���л��죺�ˣ������ˣ������ˣ������漴ɭ�־��������˹���������\n\n\n");
BattleAct();break;
case 5:
SlowDisplay("\n\n\t\tһ��ʨ�ӷɿ�ĳ��˹���������\n\n\n");
BattleAct();break;
case 12:
SlowDisplay("\n\n\t\t��......��......��......һ......��......��......��......��......��......��......��......��......��......��......��......��......��......��......\n\n\n");
BattleAct();break;
case 13:
printf("\n\n\t\t%s�ɿ�����˹���!\n\n\n",guai.name);
BattleAct();break;
case 17 :
SlowDisplay("\n\n\t\tС...��...��...��...��...��...��...��...��...��...\n\n\n");
BattleAct();break;
default:
printf("\n\n\t\t%s%s�˹���!\n\n\n",guai.name,guai.a);
BattleAct();
}
}
void DisplayState()
{
gotoxy(16,2);
printf("%s ������:%d+%d=%d ������:%d+%d=%d HP:%d/%d \n\n\n",player.name,player.attack,gong,player.attack+gong,player.defense,fang,player.defense+fang,player.health,player.max_health);
printf("����: %s ����: %s  ���ܣ� %d  ʣ�������� %d/%d �ӵ���%d \n\n\n",gongname,fangname,bi,player.air,player.max_air,zidan);
printf("�ȼ�:%d ����:%d/%d ����Ҫ%d�������� ���:%d \n\n\n",player.level,player.exp,player.max_exp,player.max_exp-player.exp,money); 
system("pause");
}
void BattleAct()
{
if(s2=1)Setjindutiao(20);
if(player.player_number==beauty.player_number&&guai.nex==1)yun++;
while(1)
{
gotoxy(2,5);
printf("%sHP:%d  ",player.name,player.health);
gotoxy(3,5);
printf("������%d ������%d",player.attack+gong,player.defense+fang);
gotoxy(2,40);
printf("%sHP:%d  ",guai.name,guai.health);
gotoxy(3,40);
printf("������%d ������%d",guai.attack,guai.defense);
gotoxy(21,0);
puts("=============================================================================");
printf("Ҫ��ô��?\n\n\n 1,���� 2,��Ʒ 3,�鿴״̬ 4,����\n\n\n");
switch(scanf("%d",&choose_number),choose_number)
{
case 1:
s=SuiJi();
if(s>=guai.miss||yun!=0) 
{
gotoxy(4,40);
printf("\t\t\t\t");
gotoxy(4,40);
printf("-%d\n",player.attack+s+gong-guai.defense/3);
guai.health-=player.attack+s+gong-guai.defense/3;
if(place.sign==sea1.sign||place.sign==sea2.sign||place.sign==sea3.sign)player.air--;
else player.air=player.max_air;
if(player.air<=0)player.health=-1;
}
else
{
gotoxy(4,25);
printf("%s�㿪�˹�����\n",guai.name);
}
if(AttackResult())return; //��������н��(���˻����ս��)�˳�����
else continue; 
case 2:ChooseWupin();break; //ѡ����Ʒ,����ʹ��,ս��������ʹ�ù�������Ʒ
case 3:DisplayState();break; //��ʾ״̬
case 4:Setjindutiao(20);
s=SuiJi();
if(s<4) //40%�ĸ��ʿ�������
{
gotoxy(3,5);
printf("%s������~\n\n\n",player.name);
battle=0;
return;
}
else if(s<7)
{
gotoxy(3,5);
printf("%s����ʧ��!���⵽��%s�ķ���!!!\n\n\n",player.name,guai.name);
if(AttackResult())return; //��������н��(���˻����ս��)�˳�����
else continue; 
}
else 
{
gotoxy(3,5);
printf("%s����ʧ��!\n\n\n",player.name);
}
break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
s2=0;
}
}
void Menu()
{
gotoxy(4,30);puts("1����Ʒ");
gotoxy(6,30);puts("2���Ի�");
gotoxy(8,30);puts("3��״̬");
gotoxy(10,30);puts("4��װ��");
gotoxy(12,30);puts("0���˳�");
switch(scanf("%d",&choose_number),choose_number)
{
case 1: ChooseWupin();break; //��ʾ����,������ʹ��.
case 2: Setjindutiao(25); //�Ի�ѡ��
if(place.sign==bar.sign) 
{
SlowDisplay("Ҫ��˭˵��?\n\n\n1,�췢Ů�� 2,�ͽ����� 3,�ư��ϰ�  4,���ߵ��ϰ�\n\n\n"); //��ʾ�Ի�����
scanf("%d",&choose_number);
Setjindutiao(25);
switch(choose_number)
{
case 1:
SlowDisplay("�췢Ů��:\n\n\n ��̨���Ǹ�Hunter��˧��!(~����~)\n\n\n��˵�������������,�����·��Ӧ�ú���Ϥ��!\n\n\n");
break;
case 2:
SlowDisplay("�ͽ�����:\n\n\n ������!\n\n\n ����Ҫ��ɽ����Ĺ��޿�ʼ��\n\n\n ���ɭ������ľ���������ԭ�����ʨȺ����������ľ޹�;�����!\n\n\n ���ɱ��У���ſ��ԾȻ�У��!\n\n\n");
break;
case 3:
choose_number=1;
while(choose_number)
{
SlowDisplay("Ҫ�ȵ�ʲô?\n\n\n 1,����ͷ20��� HP+30 2,XO��50��� HP+100 3,��ͷ��100��� HP+150  4,��Ҫ������ 0,����\n\n\n");
scanf("%d",&choose_number);
Setjindutiao(25);
switch(choose_number)
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
}
else
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
case 4:
while(choose_number)
{
SlowDisplay("Ҫ��ɶ�� 1,ذ��50���  2,����100���  3,����50���  4,����100���   0,����\n\n\n");
scanf("%d",&choose_number);
Setjindutiao(25);
switch(choose_number)
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
}
break;
case 0:SlowDisplay("�´�����!\n");break;
}
} 
break;
case 4:
choose_number=1;
while(choose_number)
{
SlowDisplay("Ҫ���ʲô?\n\n\n 1��ֹѪ��100��� 2�����Ȱ�180��� 3�����ϰ�ҩ200��� 4������150���  5��������100���  6�����1500���  7������500���  0,����\n\n\n");
scanf("%d",&choose_number);
Setjindutiao(25);
switch(choose_number)
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
case 6:if(money<1500)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("���+1\n");
money=money-1500;
diangun++;
}
break;
case 7:if(money<500)
{
SlowDisplay("Ǯ����!\n"); 
}
else
{
SlowDisplay("����+1\n");
money=money-500;
yulei++;
}
break;
case 0:SlowDisplay("�´�����!\n");break;
default:MessageBox(NULL,"����!","����",MB_OK);
}
}
}
}
else SlowDisplay("�������û�˿�������\n\n\n");
break;
case 3: DisplayState(); break; //��ʾ״̬
case 4: Setjindutiao(25);//װ��
printf("��װ: 1,ذ��:%d�� 2,����:%d�� 3,��Ѫ��:%d�� 4,�����ý�:%d�� 9,��������:%d��\n\n\n",gong1n,gong2n,gong3n,gong4n,gong5n);
printf("��װ: 5,����:%d�� 6,����:%d�� 7,����:%d�� 8,�ƽ�ʥ��:%d�� 10,���֮��:%d��\t\t0,����\n\n\n",fang1n,fang2n,fang3n,fang4n,fang5n);
SlowDisplay("ѡ��Ҫװ�������������:\n\n\n");
scanf("%d",&choose_number);
Setjindutiao(25);
switch(choose_number)
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
default:MessageBox(NULL,"����!","����",MB_OK);
}
break;
case 0:Setjindutiao(25);
res=MessageBox(NULL,"ȷ���˳���Ϸ��","��ʾ",MB_YESNO);
if(res==IDYES)
{
MessageBox(NULL,"���ݴ洢��","��ʾ",MB_OK);
//���ļ��и�������;
getchar();
MessageBox(NULL,"�˳�","ע��",MB_OK);
return;
}
else MessageBox(NULL,"������Ϸ!","��ʾ",MB_OK);
break;
default:MessageBox(NULL,"����!","����",MB_OK);
} 
}
void Setjindutiao(int p)
{
system("cls");
Sleep(100);
HWND hConsole = FindWindow("ConsoleWindowClass", NULL);
POINT pt;
GetCursorPos(&pt);
GetLocalTime(&Time);
int s=Time.wHour;
int f=Time.wMinute;
gotoxy(0,0);
SetConsoleTitle("������Ϸ2"); //����
COORD pos; //����һ��λ�ñ���
puts("���������") ; 
puts("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
puts("�U                                                            �U");
puts("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
printf("\t�������ӷ�������%d:%d",s,f);
printf("\t������Ϸ\t");
if(battle==1)printf("ս��������");
gotoxy(2,2);
for(int i=0;i<20;i++)
{
Sleep(p);
printf("��");
}
for(int i=20;i<30;i++)
{
Sleep(p+15);
printf("��");
}
system("cls");
}
void Map()
{
gotoxy(8,48);printf("%c��(w): %s",24,grass.name);gotoxy(12,48);printf("%c��(s): %s",25,forest.name);
gotoxy(10,32);printf("��(a): %s%c",mountain.name,27);;gotoxy(10,52);printf("%c��(d): %s",26,sea.name);
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
