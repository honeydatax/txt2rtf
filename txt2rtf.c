#include <stdio.h>
#include <stdlib.h>
#include <string.h>

printrtf(char *text){
	char *a="\\par \\pard\\plain \\s0\\nowidctlpar{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\cf0\\kerning1\\dbch\\af5\\langfe2052\\dbch\\af6\\afs24\\alang1081\\loch\\f0\\fs24\\lang2070{\\rtlch \\ltrch\\loch";
	printf ("%s\n%s }\n",a,text); 
}


void endrtf (){
	char *a="\\par }";
	printf ("%s\n",a);
}

void par(){
	char *a="{\\*\\ftnsep\\chftnsep}\\pgndec\\pard\\plain \\s20\\sb0\\sa0\\dbch\\af8\\dbch\\af5\\afs20\\loch\\f0\\fs20";
	printf ("%s\n",a);
}
void info(){
	char *a="}{\\info{\\creatim\\yr0\\mo0\\dy0\\hr0\\min0}{\\revtim\\yr2021\\mo1\\dy17\\hr1\\min47}{\\printim\\yr0\\mo0\\dy0\\hr0\\min0}{\\comment txt2rtf}{\\vern67306242}}\\deftab709";
	char *b="\\viewscale100";
	printf ("%s\n",a);
	printf ("%s\n",b);
}


void txt(){
	char *a="{\\s20\\sbasedon0\\snext20\\sb0\\sa0\\dbch\\af8\\dbch\\af5\\afs20\\loch\\f5\\fs20 Preformatted Text;}";
	printf ("%s\n",a);
}
void body(){
	char *a="{\\s16\\sbasedon0\\snext16\\sl288\\slmult1\\sb0\\sa140 Text Body;}";
	printf ("%s\n",a);
}

void head(){
	char *a="{\\s15\\sbasedon0\\snext16\\sb240\\sa120\\keepn\\dbch\\af7\\dbch\\af9\\afs28\\loch\\f4\\fs28 Heading;}";
	printf ("%s\n",a);
}
void style(){
	char *a="{\\stylesheet{\\s0\\snext0\\nowidctlpar{\\*\\hyphen2\\hyphlead2\\hyphtrail2\\hyphmax0}\\cf0\\dbch\\af7\\langfe2052\\dbch\\af9\\afs24\\alang1081\\loch\\f3\\fs24\\lang2070 Normal;}";
	printf ("%s\n",a);
}
void color(){
	char *a="{\\colortbl;\\red0\\green0\\blue128;\\red0\\green128\\blue128;}";
	printf ("%s\n",a);
}
void font(){
	char *a="{\\fonttbl{\\f0\\froman\\fprq2\\fcharset0 Free Mono;}}";
	printf ("%s\n",a);

}
void rtf(){
	char *a="{\\rtf1\\ansi\\deff3\\adeflang1025";
	printf ("%s\n",a);

}


int main(int argc,char *argv[]){
	char *til="hello world.";
	char c[2080];
	int n;
	FILE *f;
	if(argc>1){	
		rtf();
		font();
		color();
		style();
		head();
		body();
		txt();
		info();
		par();
		
		f=fopen(argv[1],"r");
			if (f!=NULL){
				while(feof(f)!=1){	
					fgets(c,2070,f);
					printrtf(c);
				}
			}
		fclose (f);
		endrtf ();
	}else{
		return 1;	
	}	
	return 0;
}