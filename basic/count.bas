10DIM XX(9)
20DIM YY(9)
30WAIT 0
40RANDOMIZE
50CLS
60IF INKEY$ <>"" THEN 60
70LOCATE 7,2
80PRINT "COUNT GAME"
90LOCATE 6,4
100PRINT "PUSH ANY KEY"
110IF INKEY$ ="" GOTO 110
120CLS
130WAIT 0
140IF INKEY$ <>"" THEN 140
150N= RND 9
160USING "###"
170CLS
180WAIT 0
190LOCATE 4,1
200FOR I=1 TO N
210X= ( RND 80)+8
220Y= ( RND 30)+8
230HIT=0
240FOR II=1 TO I-1
250IF ABS (X-XX(II))<10 AND ABS (Y-YY(II))<10 THEN HIT=1
260NEXT II
270IF HIT=1 GOTO 210
280CIRCLE (X,Y),4
290XX(I)=X
300YY(I)=Y
310NEXT I
320WAIT 0
330R=0
340K$= INKEY$
350IF K$="" THEN 340
360KA= ASC K$
370IF KA>=48 AND KA<=57 THEN R=KA-48
380IF KA=13 THEN 440
390USING "##"
400LOCATE 18,2
410PRINT R
420IF INKEY$ <>"" THEN 420
430GOTO 340
440IF INKEY$ <>"" THEN 440
450IF R=N THEN 550
460WAIT 100
470LOCATE 17,4
480PRINT "(-_-)"
490WAIT 0
500LOCATE 17,4
510PRINT "     "
520LOCATE 18,2
530PRINT "     "
540GOTO 320
550WAIT 100
560LOCATE 17,4
570PRINT "(^o^)"
580GOTO 120
