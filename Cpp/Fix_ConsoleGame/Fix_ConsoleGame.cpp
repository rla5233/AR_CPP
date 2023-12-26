#include <iostream>
#include <conio.h>

// 전역변수는 영역과 관계없이 사용가능

// 콘솔 화면 상수 세팅
const char ScreenBackGround = 'x';

const int ScreenX = 40;
const int ScreenY = 28;

const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

// 갤러그 세팅
const char GalagWall = 'o';
const char GalagBackGround = '.';
const char Default_Bullet = '^';
const char Default_Player = 'A';

const int GameScreenStartX = 2;
const int GameScreenStartY = 1;

const int GameScreenX = ScreenX - GameScreenStartX - 1;
const int GameScreenY = ScreenY - GameScreenStartY;


class int2
{
    // 보통 이런 수학적 클래스는
    // public 으로 멤버변수를 둔다.
public:
    int X = 0;
    int Y = 0;

    // 연산자 오버로딩
    // 기본 대입연산자
    void operator=(const int2& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
    }

    int2 operator+(const int2& _Other)
    {
        return { X + _Other.X, Y + _Other.Y };
    }

    void operator+=(const int2& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
    }
};

// 상하좌우 이동 다음과 같이 나타내는 방법이 있다.
const int2 Left = { -1, 0 };
const int2 Right = { 1, 0 };
const int2 Up = { 0, -1 };
const int2 Down = { 0, 1 };

class ConsoleScreen
{
public:
    // 생성자를 만든다는것 -> 내가 만든 생성자 형식으로만 생성해라
    // 따라서 컴파일러는 기본생성자를 만들지 않는다.
    ConsoleScreen(char _BaseChar)
    {
        Base_C = _BaseChar;
    }

    void PrintScreen()
    {
        for (int y = 0; y < ScreenY; y++)
        {
            char* Ptr = Arr[y];
            printf_s(Ptr);
            printf_s("\n");
        }
    }

    // 모니터가 게임을 알고있지않다.
    // 게임에서 화면(벽)을 출력해줘야 한다.
    void ClearScreen()
    {
        system("cls");

        for (int y = 0; y < ScreenY; y++)
        {
            for (int x = 0; x < ScreenX - 1; x++)
            {
                //if (y == 0 || y == ScreenY - 1 ||
                //    x == 0 || x == ScreenX - 2)
                //{
                //    Arr[y][x] = Wall_C;
                //}
                //else
                //{
                //    Arr[y][x] = Base_C;
                //}

                Arr[y][x] = Base_C;
            }
        }
    }

    void SetPixel(const int2& _Position, char _Char)
    {
        SetPixel(_Position.X, _Position.Y, _Char);
    }

    void SetPixel(int _X, int _Y, char _Char)
    {
        Arr[_Y][_X] = _Char;
    }

protected:

private:
    char Arr[ScreenY][ScreenX] = { 0, };
    char Base_C = ' ';
};

class Galaga
{
public:
    Galaga() {};

    // 갤러그 맵 그리기 (콘솔화면 객체를 참조한다.)
    void GalagaMapDraw(ConsoleScreen& _Screen)
    {
        for (int y = GameScreenStartY; y < GameScreenY; y++)
        {
            for (int x = GameScreenStartX; x < GameScreenX; x++)
            {
                if (y == GameScreenStartY || y == GameScreenY - 1 ||
                    x == GameScreenStartX || x == GameScreenX - 1)
                {
                    _Screen.SetPixel({ x,  y }, GalagWall);
                }
                else
                {
                    _Screen.SetPixel({ x,  y }, GalagBackGround);
                }
            }
        }
    }

protected:

private:

};

class Player
{
public:
    Player() {}

    Player(const int2& _StartPos, char _RenderChar)
        : Pos(_StartPos), RenderChar(_RenderChar)
    {

    }

    void Update()
    {
        char input = _getch();

        switch (input)
        {
            case 'w':
            case 'W':
            {
                if ((Pos + Up).Y != GameScreenStartY)
                {
                    Pos += Up;;
                }

                break;
            }
            case 'a':
            case 'A':
            {
                if ((Pos + Left).X != GameScreenStartX)
                {
                    Pos += Left;
                }

                break;
            }
            case 's':
            case 'S':
            {
                if ((Pos + Down).Y != GameScreenY - 1)
                {
                    Pos += Down;
                }

                break;
            }
            case 'd':
            case 'D':
            {
                if ((Pos + Right).X < GameScreenX - 1)
                {
                    Pos += Right;
                }

                break;
            }
            case ' ':
            {
                if (IsFire != nullptr)
                {
                    *IsFire = true;
                }

                break;
            }
        }

       
    }

    void SetBulletFire(bool* _IsFire)
    {
        if (_IsFire == nullptr)
        {
            return;
        }

        IsFire = _IsFire;
    }

    inline int2 GetPos() { return Pos; }
    inline char GetRenderChar() { return RenderChar; }

private:
    int2 Pos = { 0, 0 };
    char RenderChar = ' ';

    // 이런거 좋지 않다. (총알과 플레이어가 뗄 수 없는 관계가 됨)
    // Bullet Bullet = Bullet(Bullet_C);

    bool* IsFire = nullptr;
};

class Bullet
{
public:
    Bullet() {}
    Bullet(const int2& _StartPos, char _RenderChar)
        : Pos(_StartPos), RenderChar(_RenderChar)
    {}

    inline void SetPos(int _PosX, int _PosY)
    {
        Pos.X = _PosX;
        Pos.Y = _PosY;
    }

    inline int2 GetPos() { return Pos; }
    inline char GetRenderChar() { return RenderChar; }
    bool& GetIsFireRef() { return IsFire; }

protected:

private:
    int2 Pos = { 0, 0 };
    char RenderChar = ' ';
    bool IsFire = false;
};


// 함수의 실행 메모리는 고정되어 있어야 한다. -> exe 파일에 적혀있다.
// 한번 컴파일 되고나면 절대 바뀔 수 없다.
// main 함수는 100바이트를 사용한다.
int main()
{
    // 1. 키 입력받아 플레이어 상하좌우 움직이기
    // 2. 벽 채우기 및 벽 바깥으로 못나가게 하기
    // 3. 플레이어가 키 입력받아 총알 발사 (방향은 아무데나)

    ConsoleScreen NewScreen = ConsoleScreen(ScreenBackGround);
    Galaga NewGalaga = Galaga();

    Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, Default_Player);
    Bullet NewBullet = Bullet(NewPlayer.GetPos(), Default_Bullet);

    bool& Ref = NewBullet.GetIsFireRef();
    NewPlayer.SetBulletFire(&Ref);

    while (1)
    {
        NewScreen.ClearScreen();
        NewGalaga.GalagaMapDraw(NewScreen);

        NewScreen.SetPixel(NewPlayer.GetPos(), NewPlayer.GetRenderChar());

        if (NewBullet.GetIsFireRef() == true)
        {
            NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
        }

        NewScreen.PrintScreen();
        NewPlayer.Update();
    }
}