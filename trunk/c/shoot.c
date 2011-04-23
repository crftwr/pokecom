#include "util.c"
#include "actor.c"

char * jiki_img="4041633E34141810";
char * teki_img="3C6699818199663C";
char * tama_img="1000100010001010";

#define teki_num 4
struct actor jiki;
struct actor tama;
struct actor teki[teki_num];

extern void fire();
void jiki_update(struct actor * self){
 if(key(0x8010)){self->yy-=16;}
 if(key(0x2010)){self->yy+=16;}
 if(key(0x4008)){self->xx-=16;}
 if(key(0x4020)){self->xx+=16;}
 if(key(0x0820)){fire();}
 self->xx=self->xx*8/10;
 self->yy=self->yy*8/10;
 if(self->x<0){self->x=0;self->xx=0;}
 if(self->x>136<<4){self->x=136<<4;self->xx=0;}
 if(self->y<8<<4){self->y=8<<4;self->yy=0;}
 if(self->y>48<<4){self->y=48<<4;self->yy=0;}
 if(actor_hittest(self,teki,teki_num,8<<4)){/* printf("hit\n"); */}
}

void bound(struct actor * self){
 if(self->x<0){self->xx=abs(self->xx);}
 if(self->y<8<<4){self->yy=abs(self->yy);}
 if(self->x>136<<4){self->xx=-abs(self->xx);}
 if(self->y>48<<4){self->yy=-abs(self->yy);}
}

void fire(){
 actor_create(&tama);
 tama.x = jiki.x;
 tama.y = jiki.y;
 tama.xx= 8<<4;
 tama.img = tama_img;
}

void teki_update(struct actor * self){
 bound(self);
}

main(){
 int i;
 actor_create(&jiki);
 jiki.x=50<<4;
 jiki.y=10<<4;
 jiki.img=jiki_img;
 jiki.update=jiki_update;
 for(i=0;i<teki_num;i++){
  actor_create(&teki[i]);
  teki[i].x=rnd(144<<4);
  teki[i].y=rnd(48<<4);
  teki[i].xx=rnd(5<<4)-(2<<4);
  teki[i].yy=rnd(5<<4)-(2<<4);
  teki[i].img=teki_img;
  teki[i].update=teki_update;
 }
 for(;;){
  actor_update(&jiki,1);
  actor_update(teki,teki_num);
  actor_update(&tama,1);
  actor_draw(teki,teki_num);
  actor_draw(&jiki,1);
  actor_draw(&tama,1);
 }
}

