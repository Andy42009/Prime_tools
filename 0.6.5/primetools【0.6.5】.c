//�������:gcc primetools��0.6.5��.c -o primetools��0.6.5��.exe -lwinmm

#include <io.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <mmsystem.h>
#include <conio.h>


int Music_File_check()
{
	FILE *fp;
	
	char musicfile[20] = ".\\Music\\1.mp3";
	
	fp = fopen(musicfile, "r");
	
	if(fp == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
		fclose(fp);
	}
} 

void full_screen()
{   
	FILE *check_Options;
	
	check_Options = fopen(".\\Options\\o.ini","r");
	
	if(check_Options == NULL)
	{
    	HWND hwnd = GetForegroundWindow();
    	int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    	int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

    	LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* ��ȡ������Ϣ */
    	/* ���ô�����Ϣ ��� ȡ�����������߿� */
    	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	
    	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
    	
    	fclose(check_Options);
    }
    else
    {
		HWND hwnd = GetForegroundWindow();
		int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
		int cy = GetSystemMetrics(SM_CYSCREEN);			   /* ��Ļ�߶� ���� */
		            
		LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* ��ȡ������Ϣ */
		/* ���ô�����Ϣ ��� ȡ�����������߿� */
		SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
			
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, cx, cy, 0);
		
		fclose(check_Options);
	}
}

int title_print_1()
{
	printf("**********************************************************************************************************PRIME TOOLS V 0.6.5��Page1��*****************************************************************************************************\n");
	printf("**********************************************************************************1.primetools 2.Changelog 3.producers 4.primes_list 5.option 6.exit 7.next page***************************************************************************\n");
	printf("*******************************************************************************************************************************************************************************************************************************************\n");
	printf("Copyright Prime Tools Andy.AB   !!!\n");
}

int title_print_2()
{
	printf("********************************************************************************************PRIME TOOLS V 0.6.5��Page2��**************************************************************************\n");
	printf("**************************************************************************************1.check_primes 2.��ŵ�� 3.�������� 4.last page**************************************************************\n");
	printf("**************************************************************************************************************************************************************************************************\n");
	printf("Copyright Prime Tools Andy.AB   !!!\n");
}





void Move(int n, char x, char y, char z)

{
	
	if(n==1)
	printf("%d������ from %c�� to %c��\n", n, x, z);
	
	else
	{
		Move(n - 1, x, z, y);
		
		printf("%d������ from %c�� to %c��\n", n, x, z);
		
		Move(n - 1, y, x, z);
		
	}
	
	
	
}

int Check_Optionfile() 
{
	FILE *option;
	
	option = fopen(".\\Options\\o.ini","r");
	
	if(option == NULL)
	{
		fclose(option);
		return 0;
	}
	else
	fclose(option);
	return 1;
	
}


int Creat_Optionfile()
{
	FILE *top;
	
	top = fopen(".\\Options\\o.ini","w+");
	
	fclose(top);
}


int set_color(int choices)
{
	
	printf("1 = ��ɫ\n");
	printf("\n");
	printf("2 = ��ɫ\n");
	printf("\n");
	printf("3 = ǳ��ɫ\n");
	printf("\n");
	printf("4 = ��ɫ\n");
	printf("\n");
	printf("5 = ��ɫ\n");
	printf("\n");
	printf("6 = ��ɫ\n");
	printf("\n");
	printf("7 = ����ɫ\n");
	printf("\n");
	printf("8 = �ָ�Ĭ��ֵ\n");
	printf("\n");
	printf("9 = �Զ��屳����\n");
	printf("\n");
	printf("10 = �Զ��屳����ʧ��\n");
	printf("\n");
	
	Check_Optionfile();
	if(Check_Optionfile() == 1)
	{
		printf("11 = ȡ�����ڶ���\n");
		printf("\n");
	}
	
	else
	
	{
		printf("11 = ���ڶ���\n");
		printf("\n");
	}
	printf("Input your choices\n");
	scanf("%d" ,&choices);
	
	
	
	switch (choices)
	{
		case 1:
			system("color 1");
			break;
		case 2:
			system("color 2");
			break;
		case 3:
			system("color 3");
			break;
		case 4:
			system("color 4");
			break;
		case 5:
			system("color 5");
			break;
		case 6:
			system("color 6");
			break;
		case 7:
			system("color 9");
			break;
		case 8:
			system("color f");
			break;
		case 9:
			system("cls");
			
			mciSendString("stop andymusic",NULL,0,NULL);
			
			MessageBox(0,"�����Ҫ�ı����������Ŀ¼��Music�ļ��к󸲸�ԭ�����ļ�[����еĻ�]������ȷ����ť---������ļ�������Ϊ1.mp3,�������Ч��������","Andy---�Զ�����������",64);
			
			
			MessageBox(0,"�������������Խ�������д����򻺴�","Andy---�Զ�������",64);
			
			exit(1);
			
			break;
		case 10:
			system("cls");
			printf("�ļ���������1.mp3��������1.MP3\n");
			printf("\n");
			printf("�ļ������Ǳ��ؼ�����ļ�����β鿴���Ҽ��ļ�ѡ�����ԣ����Ϊ�����ļ�������������ʾ:���ļ�������������������ܻᱻ��ֹ�������ü����\n");
			printf("\n");
			Sleep(5000);
			break;
		case 11:
			
			Check_Optionfile();
			
			if(Check_Optionfile() == 1)
			{
				printf("1");
				Sleep(220);
				system("del .\\options\\o.ini");
				SetWindowPos(GetConsoleWindow(),HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_DRAWFRAME);
				break;
			}
			
			if(Check_Optionfile() == 0)
			{
				printf("0");
				Sleep(220);
				Creat_Optionfile();
				break;
			}
	}
	

}

int think()
{
	system("cls");
	printf("1-10������:��4��\n");
	printf("\n");
	printf("1-100������:��25��\n");
	printf("\n");
	printf("1-1000������:��168��\n");
	printf("\n");
	printf("1-10000������:��1229��\n");
	printf("\n");
	printf("1-100000������:��9592��\n");
	printf("\n");
	printf("1-1000000������:��78498��\n");
	printf("\n");
	printf("1-10000000������:��664579��\n");
	printf("\n");
	printf("1-100000000������:��5761455��\n");
	printf("\n");
	printf("1-1000000000������:��50847534��\n");
	printf("\n");
	printf("���⣺����Ҫ��Զ���ϼ����𣿿ɲ�����ֹͣ��\n");
	
	int result7=MessageBox(MB_APPLMODAL,"������?","Andy",MB_ICONASTERISK|MB_YESNO);
	
	
	if(result7 == IDYES || IDNO)
	{
		system("cls");
		Sleep(200);
	}
	
}

int Changelog()
{
	system("cls"); 
	printf("�汾0.0.1:\n"); 
	printf("ʱ��:2021������\n");
	printf("����:primetools��ճ���:)\n");
	printf("\n");
	printf("�汾0.0.2:���ش���¡�:\n");
	printf("ʱ��:2022.7.1\n");
	printf("����:primetools����ƽ�������ӿ����ʱ�䣬�Ż��㷨:)\n");
	printf("\n");
	printf("�汾0.0.3:\n");
	printf("ʱ��:2022.7.27\n");
	printf("����:primetools�����û����棬���������־���������������Ż�һ��һ������ļ�������:)\n");
	printf("\n");
	printf("�汾0.0.3.5:\n");
	printf("ʱ��:2022.9.7\n");
	printf("����:primetools���붯��������,�޸���֪����:)\n");
	printf("\n");
	printf("�汾0.0.3.8:\n");
	printf("ʱ��:2022.10.3\n");
	printf("����:primetools�޸�������ʾ,���µ�������,�޸�1-1000��������ֵ�����:)\n");
	printf("\n");
	printf("�汾0.0.4:���ش���¡�:\n\n");
	printf("ʱ��:2022.11.15{�������ա���ͷ��}\n\n");
	printf("����:primetools�������·�����޸���ͬ�����޷�����������־�����⡣����\n\n��ʾ:�˰汾��˰汾�����б����¼���ڸ�Ŀ¼�µ�Primes�ļ�����....\n\n������Ҫ(��α����ļ�)�����и����ļ���(����primes.txt����)�������Ŀ¼�������´μ���Ḳ��ԭ����primes.txt!\n\n[���ǵȸ���,haha~=_=]:)\n");
	printf("\n");
	printf("�汾0.0.4.5:\n");
	printf("ʱ��:2022.12.23\n");
	printf("����:primetools������ɫ���ã��ü������Ȥ���Ƽ�������ɫ/��ɫ��:)\n");
	printf("\n");
	printf("�汾0.0.4.8:\n");
	printf("ʱ��:2022.12.25\n");
	printf("����:primetools����ָ�Ĭ������:)\n");
	printf("\n");
	printf("�汾0.0.5:\n");
	printf("ʱ��:2022.12.27\n");
	printf("����:primetools��������λ,����ȫ��,��������ʽ����:)\n");
	printf("\n");
	printf("�汾0.0.6:\n");
	printf("ʱ��:2023.1.12\n");
	printf("����:primetools����˼�����֣���������ʽ����:)\n");
	printf("\n");
	printf("�汾0.0.7:\n");
	printf("ʱ��:2023.2.24\n");
	printf("����:primetools�����Զ�������:)\n");
	printf("\n");
	printf("�汾0.0.8���Զ������ָ��°���ɣ�33.3��:\n");
	printf("ʱ��:2023.6.24\n");
	printf("����:primetools�����Զ������ֵ���������nice��ǧ��ǧ��ǧ��ǧ��Ҫ�Ų��Ǳ��ؼ��������!---[������β鿴���ڳ���option��ѡ���10��ѡ�]---:)\n");
	printf("\n");
	printf("�汾0.0.9���Զ������ָ��°���ɣ�100��:\n");
	printf("ʱ��:2023.6.30\n");
	printf("����:primetools����ʶ�������ļ������û�У�����ǿ�ƣ������ԣ���ѡ��ǿ�ҽ���ʹ�ô˹��ܡ��Զ������֡�:)\n");
	printf("\n");
	printf("�汾0.1.0�����������������졿�������������ش���¡�:\n");
	printf("ʱ��:2023.6.30\n");
	printf("����:primetools��ȫ���汾���벢������һ����װ����Ϊ������ף�����졣�������������������鵽���а汾��primetools�����в��㣬��������ж��ָ�̡�,�޸�������С����:)\n");
	printf("\n");
	printf("�汾0.2.0:���ش���¡����Բ�����һЩ�汾����\n");
	printf("ʱ��:2023.9.7\n");
	printf("����:primetools���������¹��ܣ�1.�ж���������ǲ�������2.�鿴�����ļ����ֲе�ר�á�����Щ���ܾ��ڵڶ�ҳ��ѡ���һҳ�ĵ��߸�ѡ�������ת���������������ʹ���ϵĲ��ʣ����԰�issue�ᵽ�ҵ�˽������:zzh_Andy@outlook.com:)\n");
	printf("\n");
	printf("�汾0.2.5���޸����°���:\n");
	printf("ʱ��:2023.12.1\n");	
	printf("����:primetools�޸��ж��������⣬Ϊ�ж����������������������������Сֵ��⣬��̫���̫С���ᱨ�����ⷢ��һ����������:)\n");
	printf("\n");
	printf("�汾0.3.0�����ݸ��°���:\n");
	printf("ʱ��:2024.1.1\n");	
	printf("����:primetools����Ϊ��������ʱ���ʱ�Ĺ��ܣ�����λΪ��(�������˲���seconds��(s))���������޷��ڱ����ļ�ʱʹ�ã�ԭ���Լ���:)\n");
	printf("\n");
	printf("�汾0.3.5�����ݸ��°������ش���¡�:\n");
	printf("ʱ��:2024.7.6\n");	
	printf("����:primetools���뺺ŵ�����ݹ�˼�룬��ѧ�ߵ�ج�Ρ������鲻Ҫ�������10�����֣���Ϊ�ƶ�����=2���������η�-1:)\n");
	printf("\n");
	printf("�汾0.4.0�����ݸ��°������ش���¡�:\n");
	printf("ʱ��:2024.2.7\n");	
	printf("����:primetools�����ö��������ã���θ��¿��ƺ�С����ȴ������һ����:)\n");
	printf("\n");
	printf("�汾0.5.0���������¡�:\n");
	printf("ʱ��:2024.3.23\n");	
	printf("����:primetools�޸���ԭ����Ȥ������������������������������Ĭ�����޴Σ���������ȴ�3����Զ�ֹͣ����:)\n");
	printf("\n");
	printf("�汾0.5.77����Ȩ���¡�:\n");
	printf("ʱ��:2024.3.23\n");	
	printf("����:primetools������CopyRight!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!:)\n");
	printf("\n");
	printf("�汾0.6.5����Ȩ���¡�:\n");
	printf("ʱ��:2024.4.3\n");	
	printf("����:primetools�����������������ϲ�������򣬻�ӭ�������������⣬����Ҫ��!!!:)\n");	
	
	
	//�����������޸Ĳ����������־�����ģ����Ǻ�������������������á� 
	Sleep(5000);
}


int half_chn(char *info, int len)
{
    int i;
    for(i=0; i<len; )
    {
        if(info[i] >= 0x80)
            i += 2;
        else
            i++;
    }
    if(i == len)
        return 0;
    else
        return 1;
}



void ShowCharaScrol(void)
{
	printf("\n");
	
	//	char str[] = "����Ľɽ��ˮ��Ҳ�������Ұ����޻�";
	//	char str[] = "���˺ܾ�������Ը̧ͷ��������ڶ԰������¸ҡ������ٿ���һ�飬���ϵ���";
	
	char str[] = " �� �� �� �� : A n d y �� �� �� �� : A n d y �� �� �� �� : E m m a  ��������ȴ�3���˳�!!! ";
	//	char ptr[30] = {0};
	char dest[100] = {0};
	char *space = "  ";
    unsigned int i,j;
    
    while(1)
    {
        for(i = 0 ; i < strlen(str) && !_kbhit() ; i++)
        {
        //    system("cls");
            for(j = 0 ; j <= strlen(str) / 2 && !_kbhit() ; j++)
            {
                if(half_chn(str, strlen(str)) != 1)
				{
				  strcpy(dest,str+j*2);
				//	sprintf(dest,"%s  ",str+j*2);
					strcat(dest,space);
					strncat(dest,str,j*2);
					printf("%s",dest);
					
					memset(dest,0,strlen(dest));
					Sleep(500);
					system("cls");

				}
			//	 system("cls");
            }
        //    Sleep(500);
        //   printf("\n");
        }
        
        break;
        
   }
}




int isprime(int number1,int box)
{
	
	//�����жϺ���2.0.2�����뿪���� 
	
	if(number1 < 2)
	return 0;
	if(number1 == 2)
	return 1;
	if(number1 % 2 == 0)
	return 0;
	
	if(number1 <= box)
	{
		for(int i = 3 ;i < number1 ; i = i + 2)
			{
				if(number1 % i == 0)
				return 0;
			}
			return 1;
	}
	
	else
	
	
	{
		for(int i = 3 ; i <= box ; i = i + 2)
		{
			if(number1 % i == 0)
			return 0;
		}
		return 1;
	}
	
}

void CreateFolder_Prime()
{
    //�ļ�������
    char folderName[] = "Primes";

    // �ļ��в������򴴽��ļ���
    if (_access(folderName, 0) == -1)
    {
        _mkdir(folderName);
    }
}

void CreateFolder_music()
{
    //�ļ�������
    char folderName[] = "Music";

    // �ļ��в������򴴽��ļ���
    if (_access(folderName, 0) == -1)
    {
        _mkdir(folderName);
    }
}

void CreateFolder_option()
{
	//�ļ�������
	    char folderName[] = "Options";
	
	    // �ļ��в������򴴽��ļ���
	    if (_access(folderName, 0) == -1)
	    {
	        _mkdir(folderName);
	    }
}







int main()
{
	long long int number1,number2,times = 0;
	int choices=0;
	
	CreateFolder_option();
	
	CreateFolder_music();
	
	
	SetConsoleTitle("primes number tools ��Version��0.6.5��-----��ʽ�汾��ӭ����!");
	
	Music_File_check();
	
	if(Music_File_check() == 1)
	{
		system("cls");
		
		int result17 = MessageBox(MB_APPLMODAL,"��⵽û�������ļ��������������Գ����������Ӱ�죬�Ƿ��Զ�������","Andy---[CAN NOT FIND MUSIC FILE]",MB_ICONASTERISK|MB_YESNO);
		
		if(result17 == IDNO)
		{
			goto L2;
		}
		else
		
		MessageBox(0,"�����Ҫ�ı����������Ŀ¼��Music�ļ��к󸲸�ԭ�����ļ�[����еĻ�]������ȷ����ť---������ļ�������Ϊ1.mp3,�������Ч��������","Andy---�Զ�����������",64);
		
		MessageBox(0,"�������������Խ�������д����򻺴�","Andy---�Զ�������",64);
		
		exit(1); 
		
	}
	
	mciSendString("open .\\Music\\1.mp3 alias andymusic",NULL,0,NULL);
	
	mciSendString("play andymusic repeat",NULL,0,NULL);
	
	system("cls");
	
	
	
	L2:
																
															
	full_screen();
	system("cls");
	title_print_1();
	scanf("%d",&choices);
	
	if(choices == 2)
	{
		Changelog();
		goto L2;
	}
	
	if(choices == 3)
	{
		system("cls"); 
		
		ShowCharaScrol(); 
		
		Sleep(1000);
		goto L2;
	}
	
	if(choices == 4)
	{
		think();
		goto L2;
	}
	
	if(choices == 5)
	{
		system("cls");
		set_color(choices);
		
		goto L2; 
		
	}
	
	if(choices == 6) 
	{
		system("cls");
		exit(1);	
	}
	
	if(choices == 7)
	{
		L9:
		system("cls");
		
		
		title_print_2();
		scanf("%d" ,&choices);
		
		if(choices == 1)
		{
			
			L10: 
			for(;;)
			{
				system("cls");
				printf("Input the number which you want to check:\n");
				long long int prime_unknown,box_prime_unkown;
				
				scanf("%lld" ,&prime_unknown);
				
				if(prime_unknown >= 9223372036854775806)
				{
					system("cls");
					MessageBox(0,"Error:Too large numbers input","Andy",16);
					goto L10;
				}
				
				
				if(prime_unknown <= -9223372036854775806)
				{
						system("cls");
						MessageBox(0,"Error:Too small numbers input","Andy",16);
						goto L10;
				}
				
				
					box_prime_unkown = sqrt(prime_unknown);
					box_prime_unkown = ceil(prime_unknown);
				
				
				
					if(prime_unknown < 2)
					{
						system("cls");
						printf("No\n");
						int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
						if(result999 == IDNO)
						{
							goto L9;
						}
						else
						{
							system("cls");
							goto L10;
						}
						
					}
					
					
					if(prime_unknown == 2)
					{
						system("cls");
						printf("Yes\n");
						int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
						if(result999 == IDNO)
						{
							goto L9;
						}
						else
						{
							system("cls");
							goto L10;
						}
						
					}
									
									
					if(prime_unknown % 2 == 0)
					{
						system("cls");
						printf("No\n");
						int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
						if(result999 == IDNO)
						{
							goto L9;
						}
						else
						{
							system("cls");
							goto L10;
						}
										
					}
					
					if(prime_unknown <= box_prime_unkown)
					{
						for(int i = 3 ;i < prime_unknown ; i = i + 2)
							{
								if(prime_unknown % i == 0)
								{
									system("cls");
									printf("No\n");
									int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
									if(result999 == IDNO)
									{
										goto L9;
									}
									else
									{
										system("cls");
										goto L10;
									}
																	
								}
							}
							
							system("cls");
							printf("Yes\n");
							int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
							if(result999 == IDNO)
							{
								goto L9;
							}
							else
							{
								system("cls");
								goto L10;
							}
												
											
					}
					
					else
					
					
					{
						for(int i = 3 ; i <= box_prime_unkown ; i = i + 2)
						{
							if(prime_unknown % i == 0)
							system("cls");
							printf("No\n");
							int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
							if(result999 == IDNO)
							{
								goto L9;
							}
							else
							{
								system("cls");
								goto L10;
							}
							
							
						}
						
						
						system("cls");
						printf("Yes\n");
						int result999 = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
						if(result999 == IDNO)
						{
							goto L9;
						}
						else
						{
							system("cls");
							goto L10;
						}
						
						
						
					}
			}
		}
		
		
		if(choices == 2)
		{
			system("cls");
			
			int n;
			L_plate:printf("������������:");
			scanf("%d", &n);
				
			printf("�ƶ���������:\n");
			Move(n, 'A', 'B', 'C');
				
				
			int result_Move = MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
				
			if(result_Move == IDYES)
			{
				system("cls");
				goto L_plate;
			}
			else
			{
				system("cls");
				goto L9;
			}
			
		}
		
		
		if(choices == 3)
		{
			system("cls");
			
			MessageBox(0,"�������⣬����Ҫ��!!!","Andy",64);
			
			system("start https://afdian.net/a/Prime_Tools");
			
			goto L9;
			
		}
		
		
		if(choices == 4)
		{
			system("cls");
			
			
			goto L2;		
			
		}
		
		
	}
	
	L3:
	
	system("cls");
	times = 0;
	printf("Input the first number:\n");
	scanf("%lld",&number1);
	printf("Input the second number:\n");
	scanf("%lld",&number2);
	
	
	
	if(number1 >= 9223372036854775806 || number2 >= 9223372036854775806)
	{
		system("cls");
		MessageBox(0,"Error:Too large numbers input","Andy",16);
		goto L3;
	}
					
					
	if(number1 <= -9223372036854775806 || number2 <= -9223372036854775806)
	{
			system("cls");
			MessageBox(0,"Error:Too small numbers input","Andy",16);
			goto L3;
	}
	
	
	
	if(number1>number2)
	{
		number1 = number1 + number2;
		number2 = number1 - number2;
		number1 = number1 - number2;
	}
	
	
	int box;
	box = sqrt(number2);
	box = ceil(box);
	
	int result1 = MessageBox(MB_APPLMODAL,"How about saving the files into into disk","Andy",MB_ICONASTERISK|MB_YESNO);
	if (result1 == IDYES)
	{
		CreateFolder_Prime();
		FILE*fp;
		fp = fopen(".\\Primes\\primes.txt","w+");
		
		clock_t start_time=clock();
		
		isprime(number1,box);
		
		system("cls");
		fprintf(fp,"------------------------------------------------prime numbers between %15lld to %15lld are:------------------------------------------------\n",number1,number2);
		printf("------------------------------------------------prime numbers between %15lld to %15lld are:------------------------------------------------\n",number1,number2);
		number2=number2-1;
		
	for(;number1<=number2;number1++)
	{
			if(isprime(number1,box)==1)
	  			{
	  				fprintf(fp, "%15lld",number1);
		 			printf("%15lld",number1);
		 			times++;
		 			if(times%8==0)
		 			{
		 				printf("\n");
		 				fprintf(fp,"\n");
		 			}
		 			
				}
	
			}
			fprintf(fp,"\n");
			fprintf(fp,"There are %15lld primes in all.\n",times);
			fclose(fp);
			clock_t end_time=clock();
			
			printf("Total time:%ld S\n",((end_time-start_time)/CLOCKS_PER_SEC*1000)/1000);
			
			
			goto L1;
	}
	
	clock_t start_time=clock();
	
	system("cls");
	printf("------------------------------------------------prime numbers between %15lld to %15lld are:------------------------------------------------\n",number1,number2);
	number2=number2-1;
	
	for(;number1<=number2;number1++)
		{
			if(isprime(number1,box)==1)
			{
		 		printf("%15lld",number1);
		 		times++;
		 		if(times%8==0)
		 		printf("\n");
			}
			
		}

	printf("\n");
	printf("There are %15lld primes in all.\n",times);
	clock_t end_time=clock();
	
	printf("Total time:%ld S\n",((end_time-start_time)/CLOCKS_PER_SEC*1000)/1000);
	
	Sleep(500);
	int result2=MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
	if (result2 == IDYES)
	{
		system("cls");
		goto L3;
	}
	else
	goto L2;
	
	L1:
	printf("\n");
	printf("There are %15lld primes in all.\n",times);
	
	
	char* primes = ".\\Primes\\primes.txt";
	system(primes);
 	
 	
	Sleep(500);
	
	int result3=MessageBox(MB_APPLMODAL,"Go on?","Andy",MB_ICONASTERISK|MB_YESNO);
	if (result3 == IDYES)
	{
		system("cls");
		goto L3;
	}
	else
	goto L2;
	
}
