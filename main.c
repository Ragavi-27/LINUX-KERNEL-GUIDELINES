#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>

#include<ctype.h>

int isKeyword(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;

	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}

	return flag;
}


FILE *fp;

char str[1000], ch;

int i ;line = 0;flag;count;j=0;

int main(){

	main :

		system("cls");

		printf("\n\t\t------------------------------------------"
    	   	"\n\t\t|     LINUX KERNEL CODING GUIDELINES     |"
		   	"\n\t\t------------------------------------------");

		printf("\n\n\t\t\tChoose a parameter to check\n\n\t\t-------------"
			"-----------------------------\n\t\t\t|1| COMMENTS \n\t\t\t"
			"|2| BREAKING LONG LINES  \n\t\t\t|3| FUNCTIONS \n\t\t\t"
			"|4| MODELINES\n\t\t\t|5| BRACKET PLACEMENT\n\t\t\t|6| NAMING\n\t\t\t|0| EXIT\n\t\t------------------------------------------\n\t\t");

   	    	printf("Enter the choice:");

      		scanf("%d",&ch);

	switch(ch)

    {

	case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

		break;

	case 1:	{

    		char a[3] = "/*";char b[3] = "*/";char c[3] = "//";
    		int temp=0;
    		fp = fopen("program.c", "r");

   			if (fp == NULL){
    	    	printf("\n Could not open file ");
        		return 1;
   			}

			while (fgets(str, 1000 , fp) != NULL){

				for (i = 0; i < strlen(str); i++){

        				if ( strstr(str,a) || strstr(str,b) || strstr(str,c)) {

            				flag=1;
    					}
				}


				if(strlen(str) == 3)
   					temp ++;

   			 }

		if(temp >= 2)
   				printf("\n\t\t----- COMMENTS ARE AS PER GUIDELINES -----"
    				   "\n\t\t----- GUIDELINE CHECKED SUCCESSFULLY ! -----");
		else if(flag == 1)
	    		printf("\n\n\t\t----- COMMENTS EXIST BUT NOT AS PER GUIDELINES -----"
				  	   "\n\t\t--------- GUIDELINE CHECKED SUCCESSFULLY ! ---------",temp);
    		else
    			printf("\n\t\t\t---------- NO COMMENTS EXIST ----------"
					   "\n\t\t\t--- GUIDELINE CHECKED SUCCESSFULLY ! ---");


		fclose(fp);
		break;


	}

	case 2:	{



		fp = fopen("program.c", "r");

				if (fp == NULL){
        			printf("\n Could not open file ");
        			return 1;
   	 			}

		while (fgets(str, 1000 , fp) != NULL){


            		if( strlen(str) > 80 )
	        	 {

    	     			printf("\n\t\t LINE NO %d HAS MORE CHARACTERS : %s",line,str);

			 }
		 	else
			 {
		 		printf("\n\t\t LINE NO %d HAS PROPER NO OF CHARACTERS ",line);


		 	 }

			 line++;

			}

    	fclose(fp);


		break;
	}

	case 3:{

	    FILE *fp;
	    int i=0,j=0,count=0 ,fcount = 0,vcount =0,l1,l2,l3,l4,l5;
	    char str[100], a[] = "()",b[]="main",g[]=";",h[]="}",k[]="printf";

	    char c[10] ="int";char d[10] ="char";
	    char e[10]="float";char f[10]="double";



	    fp = fopen("program.c", "r");

	   		if (fp == NULL){
	        	printf("\n Could not open file ");
	        	return 1;
	   		}

		while (fgets(str, 100 , fp) != NULL){

			if(strstr(str,a) && !strstr(str,b) && !strstr(str,g) ){
				fcount++;
					while (fgets(str, 100, fp) != NULL && !strstr(str,h) && !strstr(str,k)){


					   l1 = strlen(str);l2 = strlen(c);l3 = strlen(d);l4 = strlen(e);l5 = strlen(f);

						for (i = 0; i < l1;){

        						j = 0;
        						count = 0;
       						while ((str[i] == c[j])||(str[i] == d[j])||(str[i] == e[j])||(str[i] == f[j])){

							count++;
            						i++;
						        j++;
						}
						        if((count == l2)||(count == l3)||(count == l4)||(count == l5)){

						            vcount++;
						            count = 0;
						        }
						        else
						            i++;
						    	}

        			}
			}
		}



		if(vcount >=10){
			printf("\n\t\tTOO MANY LOCAL VARIABLES "
			       "\n\t\tLOCAL VARIABLE COUNT = %d"
				 "\n\t\tFUNCTIONS CHECKED = %d",vcount,fcount);
	   	}
		else{
				printf("\n\t\t----- NO COMPLEX FUNTIONS EXIST -----"
					"\n\t\t----- GUIDELINE CHECKED SUCCESSFULLY ! -----"
			        	"\n\t\tLOCAL VARIABLE COUNT = %d"
			                "\n\t\tFUNCTIONS CHECKED = %d",vcount,fcount);
		}

		fclose(fp);
    		break;

	}

	case 4:{


    	char a[] = "set shiftwidth", b[] = "c-basic-offset", c[] = "compile-command",d[]="set shift";
    	char e[] ="-*- mode:",f[]=" noai:ts=",g[]="~/.",h[]="ex:set ts",j[]="HSync Vsync";


    	fp = fopen("program.c", "r");

   		if (fp == NULL){
        	printf("\n Could not open file ");
        	return 1;
   		}

		while (fgets(str, 1000 , fp) != NULL){

    			if ( strstr(str,a) || strstr(str,b) || strstr(str,c)||
			     strstr(str,d) || strstr(str,e) || strstr(str,f)||
	   		     strstr(str,g) || strstr(str,h) || strstr(str,j)){

					flag=1;

				}
		}

		if(flag)
   			printf("\n\n\t\t VISIBLE EDITOR CONFIGURATIONS OR CUSTOM MODELINES "
			   	   "\n\t\t       ARE NOT ADVISABLE AS PER GUIDELINES ! ");
		else
	    		printf("\n\n\t\t NO VISIBLE EDITOR CONFIGURATIONS OR MODELINES !"
		    		   "\n\t\t   	GUIDELINE CHECKED SUCCESSFULLY ! ");


		fclose(fp);

		break;

	}

	case 5:{

		FILE *fp;
		char str[1000],a[]="{",b[]="main",c[]="if",d[]="switch",e[]="while",f[]="for",g[]="do",h[]="()";

		int line = 1;

		fp = fopen("program.c", "r");

				if (fp == NULL){
        			printf("\n Could not open file ");
        			return 1;
   	 			}


		while (fgets(str, 1000 , fp) != NULL){
			line++;

			if( (strstr(str,a) && strstr(str,b)) || (strstr(str,a) && strstr(str,c)) ||
			    (strstr(str,a) && strstr(str,d)) || (strstr(str,a) && strstr(str,e)) ||
			    (strstr(str,a) && strstr(str,f)) || (strstr(str,a) && strstr(str,g)) ){


				printf("\n NO MISPLACED BRACES FOUND IN LINE NO: %d",line);
				printf(" %s",str);

			}
			if( (!strstr(str,a) && strstr(str,b)) || (!strstr(str,a) && strstr(str,c)) ||
			    (!strstr(str,a) && strstr(str,d)) || (!strstr(str,a) && strstr(str,e)) ||
			    (!strstr(str,a) && strstr(str,f)) || (!strstr(str,a) && strstr(str,g)) ){

				printf("\n MISPLACEMENT OF BRACES FOUND IN LINE NO: %d",line);
				printf(" %s",str);

			}
		    	if(strstr(str,h) && strstr(str,a)){
		    		printf("\n FUNCTION WITH WRONG BRACE PLACEMENT IN LINE NO: %d",line);
		    		printf(" %s",str);

			}



		}


	    fclose(fp);

		break;
	}

	case 6:{

		char ch, buffer[15],*ptr;
		FILE *fp;
		int i,j=0,temp=0;


		fp = fopen("program.c","r");

		if(fp == NULL){
			printf("error while opening the file\n");
			exit(0);
		}

		while((ch = fgetc(fp)) != EOF){


	   		if(isalnum(ch)){
	   			buffer[j++] = ch;
	   		}
	   		else if((ch == ' ' || ch == '\n') && (j != 0)){
	   				buffer[j] = '\0';
	   				j = 0;

	   				if(isKeyword(buffer) == 0){

					   ptr = buffer;

						while(*ptr!='\0'){

	        					if(isupper(*ptr) || isspace(*ptr)){

	        						temp++;

	        					}
	        					*ptr++;
						}



					}

	   		}

		}
		if(temp!=0)
			printf("\n\t\tIDENTIFIER WITH SPACE OR UPPERCASE IS FOUND!");
		else
			printf("\n\t\tGUIDELINE CHECKED SUCCESSFULLY");


		fclose(fp);

		return 0;


		break;

	}

	default:

	    printf("INVALID CHOICE");

        break;

	}


 	printf("\n\n\n\tENTER THE CHOICE :\n\n\t[1] MAIN MENU\n\t[0] EXIT\n");

    scanf("%d",&ch);


    switch (ch){

    		case 0:

        		break;

        	case 1:

        		goto main;

    		default:

        		printf("Invalid choice");

        		break;
	}

}
