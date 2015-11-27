battle.exe : battle.tab.c lex.yy.c symtbl.h types.h
	g++ -O0 -g -o battle.exe battle.tab.c lex.yy.c

battle.tab.c : battle.y symtbl.h lex.yy.c
	bison -vd battle.y

lex.yy.c : battle.l
	flex battle.l

clean:
	rm -f *.exe
	rm -f *.tab.c
	rm -f *.tab.h
	rm -f *.yy.c
	rm -f *.output
