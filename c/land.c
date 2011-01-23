10 #include "util.c"
20 #include "actor.c"
30
40 char * jiki_img="4429BA7C38181010";
45 char * tama_img="1010101010000000";
50 char * baku_img="4415C83A5C13A822";
60 char * teki_img="0034343C34141018";
70
80  struct actor jiki;
85  struct actor tama;
90  #define teki_num 3
100  struct actor teki[teki_num];
110
111 void tama_update(struct actor * self){
112  struct actor * teki_hit;
113  if(self->x>136<<4){self->alive=0;}
114  teki_hit = actor_hittest(self,teki,teki_num,5<<4);
115  if(teki_hit){ teki_hit->img=baku_img; actor_draw(teki_hit,1); teki_hit->alive=0; self->alive=0; }
119 }
120 void jiki_update(struct actor * self){
130  if(key(0x0820)){self->yy-=4;}
131  if(key(0x1080)){
132   actor_create(&tama);
133   tama.x=jiki.x; tama.xx=4<<4;
134   tama.y=jiki.y;
135   tama.img=tama_img;
136   tama.update=tama_update;
137  }
140  self->yy+=2;
150  self->xx+=2;
160  self->xx=self->xx*90/100;
170  self->yy=self->yy*90/100;
180  if(self->x<0){self->x=0;self->xx=0;}
190  if(self->x>136<<4){self->x=136<<4;self->xx=0;}
200  if(self->y<8<<4){self->y=8<<4;self->yy=0;}
210  if(actor_hittest(self,teki,teki_num,5<<4)){self->img=baku_img; actor_draw(self,1); self->alive=0; }
220  if(self->y>48<<4){self->y=48<<4;self->yy=0;}
230  if(self->y>45<<4){self->img=baku_img; actor_draw(self,1); self->alive=0; }
240  if(self->x>97<<4 && self->x<115<<4 && self->y>44<<4){self->alive=0; }
250 }
260 void title_screen(){
270  int i;
280  gotoxy(5,1);
290  printf("Landing Game");
300  for(i=0;;++i){
310   if(key(0x0820)){break;}
320  }
330  clrscr();
340  rndseed(i);
350 }
360 main(){
370  int i;
380  begin:
390  title_screen();
400  actor_create(&jiki);
410  jiki.x=20<<4;
420  jiki.y=10<<4;
430  jiki.img=jiki_img;
440  jiki.update=jiki_update;
450  for(i=0;i<teki_num;++i){
460   actor_create(&teki[i]);
470   teki[i].x=(rnd(50)+50)<<4;
480   teki[i].y=(rnd(40)+5)<<4;
490   teki[i].img=teki_img;
500  }
510   actor_draw(teki,teki_num);
520  line(0,46,127,46,0,0x3333,0);
530  line(0,47,127,47,0,0xCCCC,0);
540  for(;;){
550   actor_update(&tama,1);
550   actor_update(&jiki,1);
560   actor_draw(&tama,1);
560   actor_draw(&jiki,1);
570   line(100,43,120,43,0,0xffff,0);
580   if(jiki.alive==0){
590    for(i=0;i<5000;++i){}
600    goto begin;
610   }
620  }
630 }

