#include"header.h"
#include<stdio.h>
#include<stdint.h>
int main()
{
	unsigned int i;
	printf("Enter the program no. you want to run: ");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			printf("Problem no. %d is running\n",i);
			q1();
			break;
		case 2:
                        printf("Problem no. %d is running\n",i);
                        q2();
                        break;
		case 3:
                        printf("Problem no. %d is running\n",i);
                        q3();
                        break;
		case 4:
                        printf("Problem no. %d is running\n",i);
                        q4();
                        break;
		case 5:
                        printf("Problem no. %d is running\n",i);
                        q5();
                        break;
		case 6:
                        printf("Problem no. %d is running\n",i);
                        q6();
			break;
		case 7:
                        printf("Problem no. %d is running\n",i);
                        q7();
                        break;
		case 8:
                        printf("Problem no. %d is running\n",i);
                        q8();
                        break;
		case 9:
                        printf("Problem no. %d is running\n",i);
                        q9();
                        break;
		case 10: 
			printf("Problem no. %d is running\n",i);
			q10();
    			break;
		case 11:
            		printf("Problem no. %d is running\n", i);
            		q11();
            		break;
		case 12:
                        printf("Problem no. %d is running\n", i);
                        q12();
                        break;
		case 13:
                        printf("Problem no. %d is running\n", i);
                        q13();
                        break;
	        case 14:
                        printf("Problem no. %d is running\n", i);
                        q14();
                        break;
		case 15:
                        printf("Problem no. %d is running\n", i);
                        q15();
                        break;
		case 16:
                        printf("Problem no. %d is running\n", i);
                        q16();
                        break;
		case 17:
                        printf("Problem no. %d is running\n", i);
                        q17();
                        break;
	}
	return 0;
}
