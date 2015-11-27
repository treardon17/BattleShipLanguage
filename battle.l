%{
#include <string.h>
#include "battle.tab.h"
%}

DIGIT 		[0-9]
ID				[a-zA-Z][a-z0-9]*

%%

int				{ return INTTYPE; }
char			{ return CHARTYPE; }
string		{ return STRINGTYPE; }
player		{ return PLAYERTYPE; }
computer 	{ return COMPUTERTYPE; }

"->" { yylval.action = (char*) strdup(yytext); return ACTIONSYMBOL;}
"."	 { yylval.action = (char*) strdup(yytext); return STATEMENTNUMSYMBOL;}
":"	 { yylval.action = (char*) strdup(yytext); return STATEMENTNUMSYMBOLSTART;}

loop { yylval.loop = (char*) strdup(yytext); return BEGINLOOP;}
endloop. { yylval.loop = (char*) strdup(yytext); return ENDLOOP;}
if	{ yylval.ifval = (char*) strdup(yytext); return BEGINIFCOND;}
endif. { yylval.ifval = (char*) strdup(yytext); return ENDIFCOND;}
else { yylval.ifval = (char*) strdup(yytext); return BEGINELSE;}
endelse. { yylval.ifval = (char*) strdup(yytext); return ENDELSE;}
when { yylval.whenval = (char*) strdup(yytext); return WHENSTATEMENT;}
try { yylval.tryval = (char*) strdup(yytext); return TRYSTATEMENT;}

"="			{ return ASSIGNOP; }
"'"."'"			{ yylval.sval = (char*) strdup(yytext+1); yylval.sval[1] = '\0'; return CHARLITERAL; }
"\""[^\"]*"\""	{ yylval.sval = (char*) strdup(yytext+1); yylval.sval[strlen(yylval.sval)-1] = '\0'; return STRINGLITERAL; }
{DIGIT}+		{ yylval.sval = (char*) strdup(yytext); return INTLITERAL; }
{ID}			{ yylval.id = (char*) strdup(yytext); return (IDENTIFIER); }

newPlayer\(\"[a-zA-Z][a-zA-Z0-9]+\"\) { yylval.sval = (char*) strdup(yytext+11); yylval.sval[strlen(yylval.sval)-2] = '\0'; return PLAYERLITERAL; }
newComputer\(\"[a-zA-Z][a-zA-Z0-9]+\"\) { yylval.sval = (char*) strdup(yytext+13); yylval.sval[strlen(yylval.sval)-2] = '\0'; return COMPUTERLITERAL;}
addBoat\([ ]*\"[a-zA-Z]+\"[ ]*,[ ]*\'[a-zA-Z]\'[ ]*,[ ]*[0-9]+[ ]*,[ ]*\'[vh]{1}\'[ ]*\) { yylval.sval = (char*) strdup(yytext+8); yylval.sval[strlen(yylval.sval)-1] = '\0'; return ADDBOATACTION;}
randomlyAddBoats\([ ]*[0-9]+[ ]*\) { yylval.sval = (char*) strdup(yytext+17); yylval.sval[strlen(yylval.sval)-1] = '\0'; return RANDOMADDBOATACTION; }
attack\(\"[ ]*[a-zA-Z]?[0-9]*[ ]*\"\) { yylval.sval = (char*) strdup(yytext+7); yylval.sval[strlen(yylval.sval)-1] = '\0'; return ATTACKBOATACTION;}
show\([ ]*\) {yylval.sval = (char*) strdup(yytext); return SHOWVARACTION;}
seek\([0-9]+\) {yylval.sval = (char*) strdup(yytext+5); yylval.sval[strlen(yylval.sval)-1] = '\0'; return SEEKACTION;}
trySink\([ ]*\"(up|down|left|right)\"[ ]*,[ ]*[0-9]+[ ]*\) { yylval.sval = (char*) strdup(yytext+8); yylval.sval[strlen(yylval.sval)-1] = '\0'; return TRYSINKACTION;}

findsBoat\(\) {yylval.sval = (char*) strdup(yytext); return FINDSBOAT;}


[\+\-*/]		{ return yytext[0]; }

"\/*".*"*\/" /* allow for comments */
\/\/.* /* allow for comments */

[ \t\n\r]+		/* eat up whitespace */
.				printf( "Unrecognized character: '%s'\n", yytext );

%%

int yywrap() {
	//If there are more files, return 0 and point yyin to
	//another file. If not, return 1
	return 1;
}
