10 int min(int a,int b)
20 {return a<b?a:b;}
30
40 int max(int a,int b)
50 {return a>b?a:b;}
60
70 unsigned int rnd(unsigned int a){
80  static unsigned int r=9452147;
90  r=r*4876147+123456;
100  return r%a;
110 }
120
130 int key(int k){
140  int o=(k>>8)&0xff;
150  int i=k&0xff;
160  outport(0x11,o);
170  return (inport(0x10)&i)!=0;
180 }
190
200 #if 0
210 main(){
220  int k;
230  while(1){
240   k=key(0x0840);
250   printf("key=%d\n",k);
260  }
270 }
280 #endif
290
300 #if 0
310 main(){
320  int i;
325  for(i=0;i<100;i++){
330   printf("%d\n",rnd(100));
335  }
340 }
350 #endif
