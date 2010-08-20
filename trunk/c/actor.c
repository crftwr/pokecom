10 #include "util.c"
20
30 struct actor{
40  char alive;
50  int x;
60  int y;
70  int _x;
80  int _y;
90  int xx;
100  int yy;
110  char * img;
120  void (*update)(struct actor * self);
130 };
140
150 void actor_create(struct actor * self){
160  self->alive=1;
170  self->x=0;
180  self->y=0;
190  self->_x=0;
200  self->_y=0;
210  self->xx=0;
220  self->yy=0;
230  self->img=0;
240  self->update=0;
250 }
260 void actor_update(struct actor * a, int num){
270  int i;
280  for(i=0;i<num;i++){
290   a[i]._x=a[i].x;
300   a[i]._y=a[i].y;
310   a[i].x+=a[i].xx;
320   a[i].y+=a[i].yy;
330   if(a[i].update){a[i].update(&a[i]);}
340  }
350 }
360
370 void actor_draw(struct actor * a, int num){
380  int i;
390  for(i=0;i<num;i++){
400   gcursor(a[i]._x>>4,a[i]._y>>4);
410   gprint("0000000000000000");
420   gcursor(a[i].x>>4,a[i].y>>4);
430   gprint(a[i].img);
440  }
450 }
460
470 struct actor * actor_hittest(struct actor * a,struct actor * b,int num, int r){
480  int i;
490  for(i=0;i<num;i++){
500   if(abs(a->x-b[i].x)<r && abs(a->y-b[i].y)<r ) return &b[i];
510  }
520 return 0;
530 }
540
550 char * jiki_img="4041633E34141810";
560 char * teki_img="3C6699818199663C";
570 char * tama_img="1000100010001010";
580
590  #define teki_num 4
600  struct actor jiki;
610  struct actor tama;
620  struct actor teki[teki_num];
630
640 extern void fire();
650 void jiki_update(struct actor * self){
660  if(key(0x8010)){self->yy-=16;}
670  if(key(0x2010)){self->yy+=16;}
680  if(key(0x4008)){self->xx-=16;}
690  if(key(0x4020)){self->xx+=16;}
700  if(key(0x0820)){fire();}
710  self->xx=self->xx*8/10;
720  self->yy=self->yy*8/10;
730  if(self->x<0){self->x=0;self->xx=0;}
740  if(self->x>136<<4){self->x=136<<4;self->xx=0;}
750  if(self->y<8<<4){self->y=8<<4;self->yy=0;}
760  if(self->y>48<<4){self->y=48<<4;self->yy=0;}
770  if(actor_hittest(self,teki,teki_num,8<<4)){/* printf("hit\n"); */}
780 }
790
800 void bound(struct actor * self){
810  if(self->x<0){self->xx=abs(self->xx);}
820  if(self->y<8<<4){self->yy=abs(self->yy);}
830  if(self->x>136<<4){self->xx=-abs(self->xx);}
840  if(self->y>48<<4){self->yy=-abs(self->yy);}
850 }
860
870 void fire(){
880  actor_create(&tama);
890  tama.x = jiki.x;
900  tama.y = jiki.y;
902  tama.xx= 8<<4;
905  tama.img = tama_img;
910 }
920
930 void teki_update(struct actor * self){
940  bound(self);
950 }
960
970 main(){
980  int i;
990  actor_create(&jiki);
1000  jiki.x=50<<4;
1010  jiki.y=10<<4;
1020  jiki.img=jiki_img;
1030  jiki.update=jiki_update;
1040  for(i=0;i<teki_num;i++){
1050   actor_create(&teki[i]);
1060   teki[i].x=rnd(144<<4);
1070   teki[i].y=rnd(48<<4);
1080   teki[i].xx=rnd(5<<4)-(2<<4);
1090   teki[i].yy=rnd(5<<4)-(2<<4);
1100   teki[i].img=teki_img;
1110   teki[i].update=teki_update;
1120  }
1130  for(;;){
1140   actor_update(&jiki,1);
1150   actor_update(teki,teki_num);
1160   actor_update(&tama,1);
1170   actor_draw(teki,teki_num);
1180   actor_draw(&jiki,1);
1190   actor_draw(&tama,1);
1200  }
1210 }
