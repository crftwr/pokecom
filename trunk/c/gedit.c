10 #include "util.c"
20
30 struct{
40  int x;
50  int y;
60 }csr;
70
80 struct{
90  char color;
100  char dirty;
110 }img[8][8];
120 char dirty=0;
130 const int dsiz=5;
140 const int offset_x=100;
150 const int offset_y=3;
160
170 void control(){
180  int old_x=csr.x;
190  int old_y=csr.y;
200  if(key(0x1001)){
210   csr.x-=1;
220  }else if(key(0x1002)){
230   csr.x+=1;
240  }else if(key(0x0880)){
250   csr.y-=1;
260  }else if(key(0x0840)){
270   csr.y+=1;
280  }
290  csr.x=min(csr.x,7);
300  csr.x=max(csr.x,0);
310  csr.y=min(csr.y,7);
320  csr.y=max(csr.y,0);
330  if(old_x!=csr.x || old_y!=csr.y){
340   dirty=1;
350   img[old_y][old_x].dirty=1;
360   img[csr.y][csr.x].dirty=1;
370  }
380  if(key(0x0820)){
390   img[csr.y][csr.x].color=!img[csr.y][csr.x].color;
400   img[csr.y][csr.x].dirty=1;
410   dirty=1;
420  }
430 }
440
450 void getgstr(char buf[]){
460  int x,y;
470  int dot8;
480  /* breakpt(); */
490  for(x=0;x<8;x++){
500   dot8=0;
510   for(y=7;y>=0;y--){
520    dot8<<=1;
530    if(img[y][x].color){dot8|=1;}
540   }
550   sprintf(buf,"%02X",dot8);
560   buf+=2;
570  }
580 }
590 void drawinit(){
600 dirty=1;
610  line(offset_x-2,offset_y-2,offset_x+8*dsiz+2,offset_y+8*dsiz+2,0,0xffff,1);
620 }
630 void draw(){
640  int x,y;
650  char gstr[20];
660  if(!dirty)return;
670  dirty=0;
680  for(y=0;y<8;y++){
690   for(x=0;x<8;x++){
700    if(img[y][x].dirty){
710     img[y][x].dirty=0;
720     line(x*dsiz+offset_x,y*dsiz+offset_y,x*dsiz+offset_x+dsiz-1,y*dsiz+offset_y+dsiz-1,img[y][x].color?0:1,0xffff,2);
730    }
740   }
750  }
760  line(csr.x*dsiz+offset_x,csr.y*dsiz+offset_y,csr.x*dsiz+offset_x+dsiz-1,csr.y*dsiz+offset_y+dsiz-1,2,0x5555,1);
770  getgstr(gstr);
780  gotoxy(0,2);
790  printf("%s",gstr);
800  gcursor(offset_x-16,offset_y+8*dsiz);
810  gprint(gstr);
820 }
830
840 main(){
850  drawinit();
860  while(1){
870   control();
880   draw();
890  }
900 }
