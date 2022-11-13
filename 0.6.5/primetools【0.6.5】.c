//编译程序:gcc primetools【0.6.5】.c -o primetools【0.6.5】.exe -lwinmm

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
    	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

    	LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* 获取窗口信息 */
    	/* 设置窗口信息 最大化 取消标题栏及边框 */
    	SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	
    	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
    	
    	fclose(check_Options);
    }
    else
    {
		HWND hwnd = GetForegroundWindow();
		int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
		int cy = GetSystemMetrics(SM_CYSCREEN);			   /* 屏幕高度 像素 */
		            
		LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* 获取窗口信息 */
		/* 设置窗口信息 最大化 取消标题栏及边框 */
		SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
			
		SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, cx, cy, 0);
		
		fclose(check_Options);
	}
}

int title_print_1()
{
	printf("**********************************************************************************************************PRIME TOOLS V 0.6.5【Page1】*****************************************************************************************************\n");
	printf("**********************************************************************************1.primetools 2.Changelog 3.producers 4.primes_list 5.option 6.exit 7.next page***************************************************************************\n");
	printf("*******************************************************************************************************************************************************************************************************************************************\n");
	printf("Copyright Prime Tools Andy.AB   !!!\n");
}

int title_print_2()
{
	printf("********************************************************************************************PRIME TOOLS V 0.6.5【Page2】**************************************************************************\n");
	printf("**************************************************************************************1.check_primes 2.汉诺塔 3.赞助作者 4.last page**************************************************************\n");
	printf("**************************************************************************************************************************************************************************************************\n");
	printf("Copyright Prime Tools Andy.AB   !!!\n");
}





void Move(int n, char x, char y, char z)

{
	
	if(n==1)
	printf("%d号盘子 from %c柱 to %c柱\n", n, x, z);
	
	else
	{
		Move(n - 1, x, z, y);
		
		printf("%d号盘子 from %c柱 to %c柱\n", n, x, z);
		
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
	
	printf("1 = 蓝色\n");
	printf("\n");
	printf("2 = 绿色\n");
	printf("\n");
	printf("3 = 浅绿色\n");
	printf("\n");
	printf("4 = 红色\n");
	printf("\n");
	printf("5 = 紫色\n");
	printf("\n");
	printf("6 = 黄色\n");
	printf("\n");
	printf("7 = 淡蓝色\n");
	printf("\n");
	printf("8 = 恢复默认值\n");
	printf("\n");
	printf("9 = 自定义背景音\n");
	printf("\n");
	printf("10 = 自定义背景音失败\n");
	printf("\n");
	
	Check_Optionfile();
	if(Check_Optionfile() == 1)
	{
		printf("11 = 取消置于顶层\n");
		printf("\n");
	}
	
	else
	
	{
		printf("11 = 至于顶层\n");
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
			
			MessageBox(0,"请把需要的背景音放入更目录的Music文件夹后覆盖原音乐文件[如果有的话]，单击确定按钮---【请把文件重命名为1.mp3,否则会无效！！！】","Andy---自定义音乐设置",64);
			
			
			MessageBox(0,"请重启本程序，以将新音乐写入程序缓存","Andy---自定义音乐",64);
			
			exit(1);
			
			break;
		case 10:
			system("cls");
			printf("文件名必须是1.mp3，不能是1.MP3\n");
			printf("\n");
			printf("文件必须是本地计算机文件。如何查看？右键文件选择属性，如果为外来文件，会在下面显示:此文件来自其他计算机，可能会被阻止并保护该计算机\n");
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
	printf("1-10的质数:共4个\n");
	printf("\n");
	printf("1-100的质数:共25个\n");
	printf("\n");
	printf("1-1000的质数:共168个\n");
	printf("\n");
	printf("1-10000的质数:共1229个\n");
	printf("\n");
	printf("1-100000的质数:共9592个\n");
	printf("\n");
	printf("1-1000000的质数:共78498个\n");
	printf("\n");
	printf("1-10000000的质数:共664579个\n");
	printf("\n");
	printf("1-100000000的质数:共5761455个\n");
	printf("\n");
	printf("1-1000000000的质数:共50847534个\n");
	printf("\n");
	printf("问题：你需要永远不断计算吗？可不可以停止？\n");
	
	int result7=MessageBox(MB_APPLMODAL,"可以吗?","Andy",MB_ICONASTERISK|MB_YESNO);
	
	
	if(result7 == IDYES || IDNO)
	{
		system("cls");
		Sleep(200);
	}
	
}

int Changelog()
{
	system("cls"); 
	printf("版本0.0.1:\n"); 
	printf("时间:2021年左右\n");
	printf("内容:primetools横空出世:)\n");
	printf("\n");
	printf("版本0.0.2:【重大更新】:\n");
	printf("时间:2022.7.1\n");
	printf("内容:primetools巧用平方根，加快计算时间，优化算法:)\n");
	printf("\n");
	printf("版本0.0.3:\n");
	printf("时间:2022.7.27\n");
	printf("内容:primetools加入用户界面，加入更新日志和制作者名单，优化一正一负报错的计算问题:)\n");
	printf("\n");
	printf("版本0.0.3.5:\n");
	printf("时间:2022.9.7\n");
	printf("内容:primetools加入动听的音乐,修复已知问题:)\n");
	printf("\n");
	printf("版本0.0.3.8:\n");
	printf("时间:2022.10.3\n");
	printf("内容:primetools修复报错提示,更新弹窗引导,修复1-1000开根后出现的问题:)\n");
	printf("\n");
	printf("版本0.0.4:【重大更新】:\n\n");
	printf("时间:2022.11.15{作者生日【狗头】}\n\n");
	printf("内容:primetools加入相对路径，修复不同电脑无法保存质数日志的问题。。。\n\n提示:此版本或此版本后所有保存记录均在更目录下的Primes文件夹中....\n\n如有需要(多次保存文件)请自行更改文件名(不是primes.txt即可)，或更改目录，否则下次计算会覆盖原来的primes.txt!\n\n[除非等更新,haha~=_=]:)\n");
	printf("\n");
	printf("版本0.0.4.5:\n");
	printf("时间:2022.12.23\n");
	printf("内容:primetools增加颜色设置，让计算更有趣【推荐：淡蓝色/绿色】:)\n");
	printf("\n");
	printf("版本0.0.4.8:\n");
	printf("时间:2022.12.25\n");
	printf("内容:primetools加入恢复默认设置:)\n");
	printf("\n");
	printf("版本0.0.5:\n");
	printf("时间:2022.12.27\n");
	printf("内容:primetools加入更多键位,超大全屏,给您沉浸式体验:)\n");
	printf("\n");
	printf("版本0.0.6:\n");
	printf("时间:2023.1.12\n");
	printf("内容:primetools加入思考部分，给您沉浸式体验:)\n");
	printf("\n");
	printf("版本0.0.7:\n");
	printf("时间:2023.2.24\n");
	printf("内容:primetools加入自定义音乐:)\n");
	printf("\n");
	printf("版本0.0.8【自定义音乐更新包完成％33.3】:\n");
	printf("时间:2023.6.24\n");
	printf("内容:primetools加入自定义音乐弹窗，更加nice，千万千万千万千万不要放不是本地计算机音乐!---[关于如何查看请在程序option中选择第10条选项卡]---:)\n");
	printf("\n");
	printf("版本0.0.9【自定义音乐更新包完成％100】:\n");
	printf("时间:2023.6.30\n");
	printf("内容:primetools加入识别音乐文件，如果没有，将会强制，啊不对，是选择，强烈建议使用此功能【自定义音乐】:)\n");
	printf("\n");
	printf("版本0.1.0【【【【【【周年庆】】】】】】【重大更新】:\n");
	printf("时间:2023.6.30\n");
	printf("内容:primetools将全部版本加入并制作了一个安装程序，为的是庆祝周年庆。。。。。【您可以体验到所有版本的primetools，如有不足，请各方大佬多多指教】,修复了两个小问题:)\n");
	printf("\n");
	printf("版本0.2.0:【重大更新【所以才跳了一些版本】】\n");
	printf("时间:2023.9.7\n");
	printf("内容:primetools加入两个新功能：1.判断您输的数是不是质数2.查看计算文件【手残党专用】，这些功能均在第二页【选择第一页的第七个选项卡即可跳转】，如遇问题或有使用上的不适，可以把issue提到我的私人邮箱:zzh_Andy@outlook.com:)\n");
	printf("\n");
	printf("版本0.2.5【修复更新包】:\n");
	printf("时间:2023.12.1\n");	
	printf("内容:primetools修复判断质数问题，为判断质数和任意区间质数增加最大最小值监测，若太大或太小，会报错，以免发生一连串的问题:)\n");
	printf("\n");
	printf("版本0.3.0【内容更新包】:\n");
	printf("时间:2024.1.1\n");	
	printf("内容:primetools加入为程序运算时间计时的功能，【单位为秒(不会有人不懂seconds吧(s))】，不过无法在保存文件时使用，原因自己想:)\n");
	printf("\n");
	printf("版本0.3.5【内容更新包】【重大更新】:\n");
	printf("时间:2024.7.6\n");	
	printf("内容:primetools加入汉诺塔【递归思想，初学者的噩梦】，建议不要输入大于10的数字，因为移动步数=2的盘子数次方-1:)\n");
	printf("\n");
	printf("版本0.4.0【内容更新包】【重大更新】:\n");
	printf("时间:2024.2.7\n");	
	printf("内容:primetools加入置顶窗口设置，这次更新看似很小，但却花了我一个月:)\n");
	printf("\n");
	printf("版本0.5.0【美化更新】:\n");
	printf("时间:2024.3.23\n");	
	printf("内容:primetools修改了原来无趣死板的制作者名单，加入滚动，滚动默认无限次，按任意键等待3秒会自动停止滚动:)\n");
	printf("\n");
	printf("版本0.5.77【版权更新】:\n");
	printf("时间:2024.3.23\n");	
	printf("内容:primetools加入了CopyRight!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!:)\n");
	printf("\n");
	printf("版本0.6.5【版权更新】:\n");
	printf("时间:2024.4.3\n");	
	printf("内容:primetools加入了赞助，如果你喜欢本程序，欢迎赞助，多少随意，心意要紧!!!:)\n");	
	
	
	//可以在这里修改并保存更新日志，随便改，这是函数，会在主程序里调用。 
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
	
	//	char str[] = "你倾慕山与水，也美不过我半生无悔";
	//	char str[] = "过了很久终于我愿抬头看，你就在对岸等我勇敢。让我再看你一遍，从南到北";
	
	char str[] = " 软 件 制 作 : A n d y 软 件 编 译 : A n d y 软 件 测 试 : E m m a  按任意键等待3秒退出!!! ";
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
	
	//质数判断函数2.0.2【加入开更】 
	
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
    //文件夹名称
    char folderName[] = "Primes";

    // 文件夹不存在则创建文件夹
    if (_access(folderName, 0) == -1)
    {
        _mkdir(folderName);
    }
}

void CreateFolder_music()
{
    //文件夹名称
    char folderName[] = "Music";

    // 文件夹不存在则创建文件夹
    if (_access(folderName, 0) == -1)
    {
        _mkdir(folderName);
    }
}

void CreateFolder_option()
{
	//文件夹名称
	    char folderName[] = "Options";
	
	    // 文件夹不存在则创建文件夹
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
	
	
	SetConsoleTitle("primes number tools 【Version：0.6.5】-----正式版本欢迎体验!");
	
	Music_File_check();
	
	if(Music_File_check() == 1)
	{
		system("cls");
		
		int result17 = MessageBox(MB_APPLMODAL,"检测到没有音乐文件，如继续，不会对程序运行造成影响，是否自定义音乐","Andy---[CAN NOT FIND MUSIC FILE]",MB_ICONASTERISK|MB_YESNO);
		
		if(result17 == IDNO)
		{
			goto L2;
		}
		else
		
		MessageBox(0,"请把需要的背景音放入更目录的Music文件夹后覆盖原音乐文件[如果有的话]，单击确定按钮---【请把文件重命名为1.mp3,否则会无效！！！】","Andy---自定义音乐设置",64);
		
		MessageBox(0,"请重启本程序，以将新音乐写入程序缓存","Andy---自定义音乐",64);
		
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
			L_plate:printf("请输入盘子数:");
			scanf("%d", &n);
				
			printf("移动步骤如下:\n");
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
			
			MessageBox(0,"多少随意，心意要紧!!!","Andy",64);
			
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
