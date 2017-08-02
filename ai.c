#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sentence[40],result[20][40],tmp[20],go[20][40];
int l=0,now[20],R=1,total=0;

int checksameshort(int countforjump, char exchange[], char temp[100][100], int *changecount, int shortfact[]) //finding same short command
{
	int u, t, sflag = 0;
	for (u = 0; u < countforjump; u++)
	{
		if ( strcmp(exchange, temp[shortfact[u]]) == 0 )
			{
				sflag = 1;
				for(t = 0; t < *changecount; t++)
					exchange[*changecount] = '\0';
				*changecount = 0;
			}
	}
	return sflag;
}
unsigned long whereitis(char a[], char b[]) //find the index of input in array
{
	char *loc;
	loc = strstr(a,b);
	if (loc == NULL)
		return 10000;
	else
	return loc-a;
}
void Save(char exchange[], int *countforjump, int *facts, char temp[100][100], int shortfact[], int *changecount, int r) // Saving new facts we've got  
{
	int u, t;
	if(strlen(exchange) < 😎
		{
			*countforjump = *countforjump + 1;
			*facts = *facts + 1;
			shortfact[*countforjump - 1] = *facts - 1;
			for(u = 0; u < *changecount; u++)
				temp[*facts - 1][u] = exchange[u];
		}
	else
		{
			*countforjump = *countforjump + 1;
			*facts = *facts + 1;
			shortfact[*countforjump - 1] = r;
			for(u = 0; u < *changecount; u++)
				temp[*facts - 1][u] = exchange[u];
		}
	for(t = 0; t < *changecount; t++)
		exchange[*changecount] = '\0';
	*changecount = 0;
}


void ptf(){
	int A=1,I,and=0;

	for(I=0;I<20;++I){
		if(now[I]!=0){
			printf("R%d%d: ",R,A);
			++A;
			strcpy(go[total],result[I]);
			//puts(go[total]);
			++total;
			printf("%s\n",result[I]);
		}
	}
}

int detectblank(int which,int head,int tail){
	int blank=0,E;
	for(E=head;E<=tail;++E){
		if(result[which][E]==' '){++blank;}
	}
	return blank;}

void ortoand(){
	int I,J;
	for(I=0;I<strlen(tmp);++I){
	if((tmp[I]=='o')&&(tmp[I+1]=='r')){
		tmp[I]='a';
		tmp[I+1]='n';
		tmp[I+2]='d';
		for(J=strlen(tmp)-1;J>=I+3;--J){
			tmp[J+1]=tmp[J];
		}
		tmp[I+3]=' ';
	}
	}
}

void strcopy(int which,int head,int tail){
	int I,nownow=0;
	for(I=0;I<20;++I){
		tmp[I]=' ';
	}
	tmp[0]='\0';
	strcpy(tmp,"");
	for(I=head;I<=tail;++I){
		tmp[nownow]=result[which][I];
		++nownow;
	}
	if((tail-head+1)<0){tmp[0]='\0';}
	tmp[tail-head+1]='\0';
}

int detector(int which,int head,int tail){
	int or=0,E;
	for(E=head;E<=tail;++E){
		if((result[which][E]=='o')&&(result[which][E+1]=='r')){or=1;}
	}
	return or;}

	void dealwithimp(int which){
	int length,I,imp=0,headto,tailfrom;
	length=strlen(result[which]);
	for(I=0;I<length;++I){
		if(result[which][I]=='i'){
		if((result[which][I+1]=='m')&&(result[which][I+2]=='p')){
			tailfrom=I+4;
			headto=I-2;
			imp=1;
		}}
	}
	if(imp==1){
		int nownow=4;
		++l;
		now[l]=now[which];
		now[which]=0;
		strcpy(result[l],"not ");
		strcopy(which,0,headto);
		strcat(result[l],tmp);
		strcat(result[l]," or ");
		if((detector(which,tailfrom,length-1))==1){
			++tailfrom;
			--length;
		}
		strcopy(which,tailfrom,length-1);
		strcat(result[l],tmp);
	}
}

int detectnot(int which,int where){
	int havenot=0,A=where;
	if(result[which][A]=='('){++A;}
	if((result[which][A]=='n')&&(result[which][A+1]=='o')&&(result[which][A+2]=='t')){havenot=1;}
	return havenot;}
		
void deletnot(int which){
	int bad=0,I=0,head=0,tail=0,andor=0,X=0,J;
	char *tmptmp;
	char *blank=" ";
	for(I=0;I<strlen(result[which]);++I){
		if((detectnot(which,I)==1)&&(result[which][I+4])=='('){
			head=I+5;
			I+=5;
			bad=1;
			++l;
			now[l]=now[which];
			now[which]=0;
		}
	if(result[which][I]==')'){tail=I-1;
		}
	if(tail!=0){break;}
	}
	if(detector(which,head,tail)==1){andor=1;}
		else {andor=-1;}

	if(bad==1){
		strcopy(which,0,head-7);
		strcpy(result[l],tmp);
		strcopy(which,head,tail);
		tmptmp=strtok(tmp,blank);
		if(strlen(result[l])!=0){strcat(result[l]," ");}
			strcat(result[l],"(");
			while(tmptmp!=NULL){
				if((andor==1)&&(X!=0)){strcat(result[l]," and ");
					tmptmp=strtok(NULL,blank);
				}
				else if((andor==-1)&&(X!=0)){strcat(result[l]," or ");
					tmptmp=strtok(NULL,blank);
				}
				if(strcmp(tmptmp,"not")!=0){
					strcat(result[l],"not ");
					strcat(result[l],tmptmp);
					X=1;
				}
				else{
					tmptmp=strtok(NULL, blank);
					X=1;
					strcat(result[l],tmptmp);
				}
				tmptmp=strtok(NULL, blank);
			}
		strcat(result[l], ") ");
		strcopy(which,tail+3,strlen(result[which])-1);
		strcat(result[l],tmp);
	}
}

void lastone(int which){
	int I,tail=0,head,bad=0;
	for(I=0;I<strlen(result[which]);++I){
		if(result[which][I]=='('){head=I+1;}
		if(result[which][I]==')'){tail=I-1;
			bad=1;
			break;
			}
		}

	if(bad==1){
		int in=0,out=0;
		for(I=0;I<=strlen(result[which])-1;++I){
		if((result[which][I]=='a')&&(result[which][I+1]=='n')&&(result[which][I+2]=='d')){
		if((I>=head)&&(I<=tail)){in=-1;}
		else{out=-1;}
		}
		if((result[which][I]=='o')&&(result[which][I+1]=='r')){
			if((I>=head)&&(I<=tail)){in=1;}
			else{out=1;}
		}
		if((in!=0)&&(out!=0)){break;}
		}

		int J,X=0,Y;
		if((out==-1)&&(in==-1)){
			for(I=0;I<strlen(result[which]);++I){
				if(result[which][I]=='('){
					for(J=I;J<strlen(result[which])-1;++J)
						result[which][J]=result[which][J+1];
					}
					result[which][strlen(result[which])-1]='\0';
					break;
				}
			}
		else if((out==1)&&(in==1)){
			for(I=0;I<strlen(result[which]);++I){
				if((result[which][I]=='a')&&(result[which][I+1]=='n')&&(result[which][I+2]=='d')){
				if(result[which][X]=='('){++X;}
				if(result[which][I-2]==')'){Y=I-3;}
				else{Y=I-2;}
				strcopy(which,X,Y);
				++l;
				now[l]=now[which];
				strcpy(result[l],tmp);
				}
				X=I+4;
			}
			if(result[which][strlen(result[which])-1]==')'){Y=strlen(result[which])-2;}
			else{strlen(result[which])-1;}
				strcopy(which,X,Y);
				++l;
				now[l]=now[which];
				now[which]=0;
				strcpy(result[l],tmp);
			}


			else if((out==1)&&(in==-1)){
				char tmpout[20],*tmpin;
				char *blank=" ";
				int outfirst;
				if(tail>=strlen(result[which])-2){
					if(result[which][0]=='('){X=1;}
						else{X=0;}
					if((result[which][head-1])=='('){Y=head-6;}
						else{Y=head-5;}
					outfirst=1;
				}
				else{
					if((result[which][tail+1])==')'){X=tail+6;}
						else{X=tail+5;}
					Y=strlen(result[which])-1;
					outfirst=0;
				}
				strcopy(which,X,Y);
				strcpy(tmpout,tmp);

				strcopy(which,head,tail);
				tmpin=strtok(tmp,blank);

				while(tmpin!=NULL){
					++l;
					now[l]=now[which];
					if(outfirst==1){strcpy(result[l],tmpout);}
					else {strcpy(result[l],tmpin);
					if(strcmp(tmpin,"not")==0){
						tmpin=strtok(NULL,blank);
						strcat(result[l]," ");
						strcat(result[l],tmpin);
						}
					}
				strcat(result[l]," or ");
				if(outfirst==1){strcat(result[l],tmpin);
					if(strcmp(tmpin,"not")==0){
					tmpin=strtok(NULL,blank);
					strcat(result[l]," ");
					strcat(result[l],tmpin);
					}
				}
				else {strcat(result[l],tmpout);}
					tmpin=strtok(NULL,blank);

				if(tmpin!=NULL){
					tmpin=strtok(NULL,blank);}
						else{break;}
				}

				now[which]=0;
			}

				else if((out==-1)&&(in==1)){
				}
		}
}
int main(){
	char *Tmp;
	char *blank = " ";
	char tt[] = "iff";
	int i,j=0,p=0,k,iff=0,first_bad=0,trouble=0,pre=0,post=0,a;
	while(gets(sentence)){
		//      startdeal();

		Tmp=strtok(sentence, blank);
			l=0;
			now[l]=-1;
			while(Tmp!=NULL){

				if(strcmp(Tmp,tt)==0){
					++l;
					iff=1;
					j=0;
					first_bad=1;
					now[l]=1;
				}

				if(iff==0){
					if(j==0){strcpy(result[l],Tmp);
						j=1;
					}
					else{
						strcat(result[l]," ");
						strcat(result[l],Tmp);}
				}
				else{
				iff=0;
				}
				Tmp=strtok(NULL, blank);
		}
		if(first_bad==1){
			++l;
			strcpy(result[l],result[0]);
			strcat(result[l]," imp ");
			strcat(result[l],result[1]);
			now[l]=-1;
			++l;
			now[l]=1;
			strcpy(result[l],result[1]);
			strcat(result[l]," imp ");
			strcat(result[l],result[0]);
			now[1]=now[0]=0;
		}

		for(i=0;i<4;++i){
			if(now[i]!=0){
				dealwithimp(i);
			}
		}

		for(i=0;i<20;++i){
			if(now[i]!=0){
				deletnot(i);
			}
		}
		for(i=0;i<20;++i){
			if(now[i]!=0){
				lastone(i);
			}
		}
		ptf();
		++R;
		for(i=0;i<20;++i){
			now[i]=0;
			for(j=0;j<88;++j){
				result[i][j]='\0';}
			}
		j=0;
	}

		//printf("\n");
	int q,r,s;
	for(r=0;r<20;++r){
		strcpy(result[r],go[r]);
	}

	char target[10];
	char temp[100][100];
	int NotFlag = 0;
	char NotFactCon[10] = " ";
	strcpy(target, "not P31");
	for(q = 4; q < 7; q++)
		NotFactCon[q-4] = target[q];
	if(strlen(target) > 4)
		NotFlag = 1;
	for(q = 0; q < 13; q++)
		printf("R%d: %s\n", q+1, result[q]);
	printf("XX: %s\n", target);
	printf("================================\n");
	for(q = 0; q < 100; q++)
	{
		for(r = 0; r < 100; r++)
			temp[q][r] = '\0';
	}
		for(q = 0; q < 100; q++)
		{
			if(strcmp(result[q], "") == 0)
				continue;
			for(r = 0; r < 100; r++)
				temp[q][r] = result[q][r];
		}
	int shortfact[100];
	int countforjump = 0, flag = 0, facts = 0;
	unsigned long position = 0;
	for (q = 0; q < 100; q++)
	{
		if(strcmp(temp[q], "") == 0)
			continue;
		if(strlen(temp[q]) < 😎
			{
				shortfact[countforjump] = q;
				countforjump++;
			}
		facts++;
	}
	char exchange[100] = " ";
	int t, u, changecount = 0;
	char fornotfact[10] = " ";
	char cancelpart[10] = " ";
	for(q = 0; q < countforjump; q++)
		{
			if(strlen(temp[shortfact[q]]) < 4)
			{
				for(r = 0; r < facts; r++)
				{
					flag = 0;
					for(s = 0; s < countforjump; s++)
					{
						if(r == shortfact[s])
						{
							flag = 1;
							break;
						}
					}

					if (flag == 1)
					continue;
			else
			{
				position = 0;
				position = whereitis(temp[r] ,temp[shortfact[q]]);
				if (position == 10000){
					continue;}
				else if (position == 0){
					continue;}
				else
					{
					if (temp[r][position-2] == 't')                        
					{
						for(u = 0; u < 10; u++)
						cancelpart[u] = '\0';
						for(u = 0; u < 7; u++)
						cancelpart[u] = temp[r][position-4+u];
						for(t = 0; t < 100; t++)
							{
								if(position == 4)
									{
										if ((t >= position - 4)&&(t <= position+6))												continue;
										else
											{
												exchange[changecount] = temp[r][t];
																				changecount++;
											}
									}
								else
									{
										if ((t >= position - 8)&&(t <= position + 2))										continue;
										else
											{
												exchange[changecount] = temp[r][t];
																				changecount++;
											}
									}
							}
							if (checksameshort(countforjump, exchange, temp, &changecount, shortfact) == 1)
								continue;
								printf("R%d + R%d (cancel %s)\n", shortfact[q]+1, r+1, cancelpart);
								printf("得到\n");
								Save(exchange, &countforjump, &facts, temp, shortfact, &changecount, r);
								printf("R%d: %s\n\n", facts+1, exchange);
								}
							else
									continue;
								}
					}
				}
			}
			else if(strlen(temp[shortfact[q]]) < 😎
				{
					for(r = 4; r < 7; r++)
					fornotfact[r-4] = temp[shortfact[q]][r];
					for(r = 0; r < facts; r++)
					{
						flag = 0;
						for(s = 0; s < countforjump; s++)
							{
								if(r == shortfact[s])
									{
										flag = 1;
										break;
									}
							}
						if (flag == 1)
							continue;
						else
							{
								position = 0;
								position = whereitis(temp[r] , fornotfact);
								if (position == 10000)
									continue;
								else if (position == 0)
									{
									for(u = 0; u < 10; u++)
										cancelpart[u] = '\0';
									for(u = 0; u < 3; u++)
										cancelpart[u] = temp[r][position+u];
									for(t = 0; t < 100; t++)
										{
											if(t < 7)
											continue;
										else
										{	
											exchange[changecount] = temp[r][t];
											changecount++;
										}
									}
									if (checksameshort(countforjump, exchange, temp, &changecount, shortfact) == 1)
										continue;
									printf("R%d + R%d (cancel %s)\n", shortfact[q]+1, r+1, cancelpart);
									printf("得到\n");
									Save(exchange, &countforjump, &facts, temp, shortfact, &changecount, r);
									printf("R%d: %s\n\n", facts+1, exchange);
								}
									else
									{
										for(u = 0; u < 10; u++)
											cancelpart[u] = '\0';
										for(u = 0; u < 3; u++)
											cancelpart[u] = temp[r][position+u];
								if (temp[r][position-2] == 'r')                           {
								for(t = 0; t < 100; t++)
									{
										if( (t >= position-4)&&(t <= position+2) )										continue;
										else
										{
										exchange[changecount] = temp[r][t];
										changecount++;
										}
									}
								if (checksameshort(countforjump, exchange, temp, &changecount, shortfact) == 1)
									continue;
								printf("R%d + R%d (cancel %s)\n", shortfact[q]+1, r+1, cancelpart);
								printf("得到\n");
								Save(exchange, &countforjump, &facts, temp, shortfact, &changecount, r);
								printf("R%d: %s\n\n", facts+1, exchange);
									}
								else
									continue;
								}
							}
						}
							for(r = 0; r < 10; r++)
								fornotfact[r] = '\0';
							}
					}
		unsigned long point = 0;
			if(NotFlag == 0)
			{
				for (q = 0; q < countforjump; q++)
					{
						point = 0;
						point = whereitis(target, temp[shortfact[q]]);
						if(point == 10000)
							continue;
							else if(point == 0)
						{
							printf("%s  %s 一樣\n", target, temp[shortfact[q]]);
							printf("得證\n");
						}
						else
							{
							printf("%s + %s (cancel %s)\n", target, temp[shortfact[q]], target);
							printf("得到空集合\n");
							printf("X得證\n");
							}
						}
				}
			else
			{
				for (q = 0; q < countforjump; q++)
					{
						point = 0;
						point = whereitis(NotFactCon, temp[shortfact[q]]);
						if(point == 10000)
							continue;
							else if(point == 0)
							{
								printf("%s + %s (cancel %s)\n", target, temp[shortfact[q]], target);
								printf("得到空集合\n");
								printf("X得證\n");
							}
						else
							{
								printf("%s  %s 一樣\n", target, temp[shortfact[q]]);
								printf("得證\n");
							}
					}
			}
		return 0;
}
