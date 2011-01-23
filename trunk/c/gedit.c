#include "util.c"

struct{
 int x;
 int y;
}csr;

struct{
 char color;
 char dirty;
}img[8][8];
char dirty=0;
const int dsiz=5;
const int offset_x=100;
const int offset_y=3;

void control(){
 int old_x=csr.x;
 int old_y=csr.y;
 if(key(0x1001)){
  csr.x-=1;
 }else if(key(0x1002)){
  csr.x+=1;
 }else if(key(0x0880)){
  csr.y-=1;
 }else if(key(0x0840)){
  csr.y+=1;
 }
 csr.x=min(csr.x,7);
 csr.x=max(csr.x,0);
 csr.y=min(csr.y,7);
 csr.y=max(csr.y,0);
 if(old_x!=csr.x || old_y!=csr.y){
  dirty=1;
  img[old_y][old_x].dirty=1;
  img[csr.y][csr.x].dirty=1;
 }
 if(key(0x0820)){
  img[csr.y][csr.x].color=!img[csr.y][csr.x].color;
  img[csr.y][csr.x].dirty=1;
  dirty=1;
 }
}

void getgstr(char buf[]){
 int x,y;
 int dot8;
 /* breakpt(); */
 for(x=0;x<8;x++){
  dot8=0;
  for(y=7;y>=0;y--){
   dot8<<=1;
   if(img[y][x].color){dot8|=1;}
  }
  sprintf(buf,"%02X",dot8);
  buf+=2;
 }
}
void drawinit(){
dirty=1;
 line(offset_x-2,offset_y-2,offset_x+8*dsiz+2,offset_y+8*dsiz+2,0,0xffff,1);
}
void draw(){
 int x,y;
 char gstr[20];
 if(!dirty)return;
 dirty=0;
 for(y=0;y<8;y++){
  for(x=0;x<8;x++){
   if(img[y][x].dirty){
    img[y][x].dirty=0;
    line(x*dsiz+offset_x,y*dsiz+offset_y,x*dsiz+offset_x+dsiz-1,y*dsiz+offset_y+dsiz-1,img[y][x].color?0:1,0xffff,2);
   }
  }
 }
 line(csr.x*dsiz+offset_x,csr.y*dsiz+offset_y,csr.x*dsiz+offset_x+dsiz-1,csr.y*dsiz+offset_y+dsiz-1,2,0x5555,1);
 getgstr(gstr);
 gotoxy(0,2);
 printf("%s",gstr);
 gcursor(offset_x-16,offset_y+8*dsiz);
 gprint(gstr);
}

main(){
 drawinit();
 while(1){
  control();
  draw();
 }
}
