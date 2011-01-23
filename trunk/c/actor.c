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

