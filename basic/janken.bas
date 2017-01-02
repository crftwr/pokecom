10PRINT "ﾖｸｷﾀﾈ!"
20INPUT "ﾅﾝﾃｲｳﾅﾏｴ?";NA$
30INPUT "ﾊﾟｽﾜ-ﾄﾞｦｲﾚﾃﾈ";PW$
40IF PW$ <>"ﾑｼｷﾝｸﾞ" THEN 30
50PRINT "ｼﾞｬﾝｹﾝｼﾖｳ"
60PRINT "1ｶﾞｸﾞ-､"
70PRINT "2ｶﾞﾁｮｷ､"
80PRINT "3ｶﾞﾊﾟ-ﾀﾞﾖ"
90PRINT "ｻｲｼﾊ ｸﾞ- ｼﾞｬﾝｹﾝ"
95INPUT J
100A= RND 3
110IF J=A THEN PRINT "ｱｲｺﾃﾞｼｮ":GOTO 95
120IF 3=A AND 2=J THEN 200
130IF 2=A AND 1=J THEN 200
140IF 1=A AND 3=J THEN 200
150PRINT "ﾎﾞｸﾉｶﾁﾀﾞﾖ!"
160GOTO 300
200PRINT "ｷﾐﾉｶﾁﾀﾞﾖ
300PRINT "ﾀﾉｼｶｯﾀﾖ";NA$
310PRINT "ﾊﾞｲﾊﾞ-ｲ"
