#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <mmsystem.h>

char* pitches_text[][19] = {
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛      @@@@@@@@@@@@@@@@@@@@@@@      弛", " 弛      @@                           弛", " 弛      @@                           弛", " 弛      @@                           弛", " 弛      @@                           弛", " 弛      @@@@@@@@@@@@@@@@@@@@@@@      弛", " 弛                @@                 弛", " 弛                @@                 弛", " 弛                @@                 弛", " 弛                @@                 弛", " 弛      @@@@@@@@@@@@@@@@@@@@@@@      弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" },
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛     @@@@@@@@@@@@@@@    @@   @@    弛", " 弛                  @@    @@   @@    弛", " 弛                  @@    @@   @@    弛", " 弛                  @@    @@   @@    弛", " 弛     @@@@@@@@@@@@@@@ @@@@@   @@    弛", " 弛     @@                 @@   @@    弛", " 弛     @@                 @@   @@    弛", " 弛     @@                 @@   @@    弛", " 弛     @@@@@@@@@@@@@@@    @@   @@    弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" },
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛     @@@@@@@@@@@@@@@@@@@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@               @@   @@      弛", " 弛     @@@@@@@@@@@@@@@@@@@   @@      弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" },
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛  @@@@@@@@@@@@@@@@@@@@@@   @@      弛", " 弛      @@           @@      @@      弛", " 弛      @@           @@      @@      弛", " 弛      @@           @@      @@      弛", " 弛      @@           @@      @@@@@@  弛", " 弛      @@           @@      @@      弛", " 弛      @@           @@      @@      弛", " 弛      @@           @@      @@      弛", " 弛  @@@@@@@@@@@@@@@@@@@@@@@  @@      弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" },
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                @@                 弛", " 弛              @@  @@               弛", " 弛             @@    @@              弛", " 弛            @@      @@             弛", " 弛           @@   @@   @@            弛", " 弛                @@                 弛", " 弛        @@@@@@@@@@@@@@@@@@         弛", " 弛                                   弛", " 弛          @@@@@@@@@@@@@@           弛", " 弛                      @@           弛", " 弛          @@@@@@@@@@@@@@           弛", " 弛          @@                       弛", " 弛          @@@@@@@@@@@@@@           弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" },
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛     @@@@@@@@@@@@@@@      @@       弛", " 弛                  @@      @@       弛", " 弛                  @@      @@       弛", " 弛                  @@      @@       弛", " 弛     @@@@@@@@@@@@@@@      @@@@@@   弛", " 弛     @@                   @@       弛", " 弛     @@                   @@       弛", " 弛     @@                   @@       弛", " 弛     @@@@@@@@@@@@@@@      @@       弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" },
	{ " 忙 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 忖", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛            @@             @@      弛", " 弛          @@  @@           @@      弛", " 弛         @@    @@          @@      弛", " 弛        @@      @@         @@      弛", " 弛       @@        @@        @@      弛", " 弛      @@          @@       @@      弛", " 弛      @@          @@       @@      弛", " 弛     @@            @@      @@      弛", " 弛     @@            @@      @@      弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 弛                                   弛", " 戌 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 式 戎" }
};

int random_num = 0;

void sound_tik()
{
	PlaySound(TEXT("./G.wav"), NULL, SND_SYNC);
}

void *sound_Ding(void* data)
{
	static int retval = 999;
	char* pitch[7] = { "./C.wav", "./D.wav", "./E.wav", "./F.wav", "./G.wav", "./A.wav", "./B.wav" };
	PlaySound(pitch[random_num], NULL, SND_SYNC);
	pthread_exit((void*)&retval);
}

int main(void) { // left: 52, right: 54.
		
	char response;
	
	pthread_t timer;
	pthread_t sound_thread;
	int thr_id;
	char p1[] = "thread_1";
	char p2[] = "thread_2";
	
	while(1) {
		system("cls");
		printf("------------------------------------\n");
		printf("瞰渠擠馬 啪歜\n");
		printf("[S: 衛濛]    [ESC: 謙猿]\n");
		printf("------------------------------------\n");
		response = _getch();
		
		if(response == 115) {
			system("cls");
			printf("START");
			sound_tik();
			Sleep(1);
			
			system("cls");
			srand(time(0));
			srand(time(0));
			
			int count = 0;
			int wrong = 0;
				
			while(count < 15) { // 檣啪歜
				random_num = rand() % 7;
				int tmp = rand() % 7;
				int answer = 0;
				
				if(tmp == random_num) { continue; }
				
				printf("蜃擎 偃熱: %d\n", count);
				printf("ぎ萼 偃熱: %d\n", wrong);
				for(int j = 0; j < 19; j++) {
					if(random_num % 2 == 0) {
						answer = 77;
						printf("%s\t%s\n", pitches_text[tmp][j], pitches_text[random_num][j]);
					}
					else {
						answer = 75;
						printf("%s\t%s\n", pitches_text[random_num][j], pitches_text[tmp][j]);
					}
				}
				thr_id = pthread_create(&sound_thread, NULL, sound_Ding, (void *)&p2);
				
				while(1) {
					int arrow = _getch();
					arrow = _getch();
					
					if(arrow == answer) {
						count++;
						break;
					}
					else if(arrow == 77 || arrow == 75) {
						wrong++;
						break;
					}
				}
				
				system("cls");
			}
			printf("------------------------\n");
			printf("蜃擎 偃熱: %d\n", count);
			printf("ぎ萼 偃熱: %d\n", wrong);
			printf("------------------------\n");
			_getch();
		}
		else if(response == 27) return 0;
	}
//
////	printf("%s", C);
////	printf("%s", D);
////	printf("%s", E);
////	printf("%s", F);
////	printf("%s", G);
////	printf("%s", A);
////	printf("%s", B);
	
	return 0;
}
