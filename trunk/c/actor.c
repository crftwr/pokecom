
struct actor{
 char alive;
 int x;
 int y;
 int _x;
 int _y;
 int xx;
 int yy;
 char * img;
 void (*update)(struct actor * self);
};

void actor_create(struct actor * self){
 self->alive=1;
 self->x=0;
 self->y=0;
 self->_x=0;
 self->_y=0;
 self->xx=0;
 self->yy=0;
 self->img=0;
 self->update=0;
}
void actor_update(struct actor * a, int num){
 int i;
 for(i=0;i<num;i++){
  if(a[i].alive==0) continue;
  a[i]._x=a[i].x;
  a[i]._y=a[i].y;
  a[i].x+=a[i].xx;
  a[i].y+=a[i].yy;
  if(a[i].update){a[i].update(&a[i]);}
 }
}

void actor_draw(struct actor * a, int num){
 int i;
 for(i=0;i<num;i++){
  if(a[i].alive==0) continue;
  gcursor(a[i]._x>>4,a[i]._y>>4);
  gprint("0000000000000000");
  gcursor(a[i].x>>4,a[i].y>>4);
  gprint(a[i].img);
 }
}

struct actor * actor_hittest(struct actor * a,struct actor * b,int num, int r){
 int i;
 if(a->alive==0) return 0;
 for(i=0;i<num;i++){
  if(b[i].alive && abs(a->x-b[i].x)<r && abs(a->y-b[i].y)<r ) return &b[i];
 }
 return 0;
}

