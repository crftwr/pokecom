#include "util.c"
#include "actor.c"

char * jiki_img="4429BA7C38181010";
char * tama_img="1010101010000000";
char * baku_img="4415C83A5C13A822";
char * teki_img="0034343C34141018";

struct actor jiki;
struct actor tama;
#define teki_num 3
struct actor teki[teki_num];
char key_enter_prev;

void tama_update(struct actor * self){
 struct actor * teki_hit;
 if(self->x>136<<4){self->alive=0;}
 teki_hit = actor_hittest(self,teki,teki_num,5<<4);
 if(teki_hit){ teki_hit->img=baku_img; actor_draw(teki_hit,1); teki_hit->alive=0; self->alive=0; }
}

void jiki_update(struct actor * self){
 char key_enter = key(0x1080);
 if(key(0x0820)){self->yy-=4;}
 if(key_enter_prev==0 && key_enter && tama.alive==0){
  actor_create(&tama);
  tama.x=jiki.x; tama.xx=4<<4;
  tama.y=jiki.y;
  tama.img=tama_img;
  tama.update=tama_update;
 }
 key_enter_prev=key_enter;
 self->yy+=2;
 self->xx+=2;
 self->xx=self->xx*90/100;
 self->yy=self->yy*90/100;
 if(self->x<0){self->x=0;self->xx=0;}
 if(self->x>136<<4){self->x=136<<4;self->xx=0;}
 if(self->y<8<<4){self->y=8<<4;self->yy=0;}
 if(actor_hittest(self,teki,teki_num,5<<4)){self->img=baku_img; actor_draw(self,1); self->alive=0; }
 if(self->y>48<<4){self->y=48<<4;self->yy=0;}
 if(self->y>45<<4){self->img=baku_img; actor_draw(self,1); self->alive=0; }
 if(self->x>97<<4 && self->x<115<<4 && self->y>44<<4){self->alive=0; }
}

void title_screen(){
 int i;
 gotoxy(5,1);
 printf("Landing Game");
 for(i=0;;++i){
  if(key(0x0820)){break;}
 }
 clrscr();
 rndseed(i);
}

main(){
 int i;
 begin:
 title_screen();
 actor_create(&jiki);
 jiki.x=20<<4;
 jiki.y=10<<4;
 jiki.img=jiki_img;
 jiki.update=jiki_update;
 for(i=0;i<teki_num;++i){
  actor_create(&teki[i]);
  teki[i].x=(rnd(50)+50)<<4;
  teki[i].y=(rnd(40)+5)<<4;
  teki[i].img=teki_img;
 }
 actor_draw(teki,teki_num);
 line(0,46,127,46,0,0x3333,0);
 line(0,47,127,47,0,0xCCCC,0);
 for(;;){
  actor_update(&tama,1);
  actor_update(&jiki,1);
  actor_draw(&tama,1);
  actor_draw(&jiki,1);
  line(100,43,120,43,0,0xffff,0);
  if(jiki.alive==0){
   for(i=0;i<5000;++i){}
   goto begin;
  }
 }
}

