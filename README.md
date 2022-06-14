# Absolute Game (절대음감 게임)
나오는 음이 무엇인지 방향키로 누르면 되는 간단한 게임입니다.

## How to Play

### Launch Game
1. Dev C++을 설치 합니다. [<a href="https://sourceforge.net/projects/orwelldevcpp/">Dev C++ Here</a>]
2. pthreads devpak을 설치합니다. > [<a href="https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/oopthread/pthreads_w32-2.8.0-1aj.DevPak">Direct Download Here</a>]
3. Dev C++ 에서 Game.c 소스파일을 엽니다.
4. 상단 바에 [Tools] > [Compiler Options]를 클릭 해줍니다.
5. General에 'Add the following commands when calling the compiler'를 체크 해주시고 `-std=c99 -lpthread -lwinmm`를 안에 적어줍니다.

### Play Game
1. F11을 눌러 코드를 컴파일 후 실행합니다.
2. S를 누르면 시작, ESC를 누르면 게임이 종료됩니다.
3. **15문제를 맞출 때까지 문제가 출제됩니다!**
4. 방향키로 정답을 맞춥니다.

< **게임 화면** >

<img width="589" alt="image" src="https://user-images.githubusercontent.com/80612949/173476540-5390d341-585d-4188-b384-776843a7f7cb.png">

< **결과 화면** >

<img width="325" alt="image" src="https://user-images.githubusercontent.com/80612949/173477014-25eb8f6a-3ebb-4b00-9d41-5bce42383d1b.png">
