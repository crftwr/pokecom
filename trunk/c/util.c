int min(int a,int b)
{return a<b?a:b;}

int max(int a,int b)
{return a>b?a:b;}

static unsigned int _rndseed=9452147;
unsigned int rnd(unsigned int a){
 _rndseed=_rndseed*4876147+123456;
 return _rndseed%a;
}
void rndseed(unsigned int seed){
 _rndseed = seed;
}

int key(int k){
 int o=(k>>8)&0xff;
 int i=k&0xff;
 outport(0x11,o);
 return (inport(0x10)&i)!=0;
}

