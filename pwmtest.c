#include "pwmconfig.h"

int main(int argc, char **argv)
{
    int PwmChannel;
    int MyPeriod = 1000000000; //period 设置为1s
	float rate = 0.5;
    int MyDuty = MyPeriod * rate;
	char *array[3] = {"B", "C", "D"};

	/* handle (optional) flags first */
	if(argc != 2) {
		fprintf(stderr, "Usage:  %s <PWM Channel Name(B or C or D)>\n", argv[0]);
		exit(1);
	}

	if(!strcmp(argv[1],array[0])){
		/*export corresponding PWM Channel*/
		PwmChannel = 1;
        if(pwm_export(PwmChannel) < 0){
        	printf("PWM export error!\n");
        	return(-1);
        }
        if(pwm_disable(PwmChannel) < 0){
        	printf("PWM disable error!\n");
        	return(-1);
        }
        /* set period and duty cycle time in ns */
        if(pwm_config(PwmChannel, MyPeriod, MyDuty) < 0){
        	printf("PWM configure error!\n");
        	return(-1);
        }
        /* enable corresponding PWM Channel */
        if(pwm_enable(PwmChannel) < 0){
        	printf("PWM enable error!\n");
        	return(-1);
        }
        printf("PWM_B successfully enabled with period - %dms, duty cycle - %2.1f%%\n", MyPeriod/1000000, rate*100);
    }
	else if(!strcmp(argv[1],array[1])){
		PwmChannel = 4;
		if(pwm_export(PwmChannel) < 0){
			printf("PWM export error!\n");
			return(-1);
		}
		if(pwm_disable(PwmChannel) < 0){
			printf("PWM disable error!\n");
			return(-1);
		}
		/* set period and duty cycle time in ns */
		if(pwm_config(PwmChannel, MyPeriod, MyDuty) < 0){
		printf("PWM configure error!\n");
		return(-1);
		}
		/* enable corresponding PWM Channel */
		if(pwm_enable(PwmChannel) < 0){
		printf("PWM enable error!\n");
		return(-1);
		}
		printf("PWM_C successfully enabled with period - %dms, duty cycle - %2.1f%%\n", MyPeriod/1000000, rate*100);
	}
	else if(!strcmp(argv[1],array[2])){
		PwmChannel = 2;
		if(pwm_export(PwmChannel) < 0){
		    printf("PWM export error!\n");
		    return(-1);
		}
		if(pwm_disable(PwmChannel) < 0){
			printf("PWM disable error!\n");
			return(-1);
		}
		/* set period and duty cycle time in ns */
		if(pwm_config(PwmChannel, MyPeriod, MyDuty) < 0){
		    printf("PWM configure error!\n");
			return(-1);
		}
		/* enable corresponding PWM Channel */
		if(pwm_enable(PwmChannel) < 0){
		printf("PWM enable error!\n");
		return(-1);
		}
		printf("PWM_D successfully enabled with period - %dms, duty cycle - %2.1f%%\n", MyPeriod/1000000, rate*100);
	}
	else{
		printf("wrong PWM Channel input\n");
		return(-1);
    }
	return 0;
}
