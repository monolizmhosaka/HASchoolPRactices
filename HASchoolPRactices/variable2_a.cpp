#include <string>

#include "DxLib.h"

using namespace std;

// ここで学ぶこと。
// 　＊【プログラム基礎】変数には専用の型があることを確認しよう。
// 　＊【プログラム基礎】変数の中身を表示する方法を確認しよう。
// 　＊【プログラム基礎】変数の中身同士を計算する方法を確認しよう。算術演算子
// 　＊【プログラム基礎】余りについて、のお話し。余りを表示してみよう。
// 
// いろいろ弄ってみる
// 　＊いろいろな変数や定数を宣言して計算・表示してみよう。
//
// 

// WinMain関数から処理が始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ウィンドウモードに設定（フルスクリーンにしたい場合は false にする）
    ChangeWindowMode(TRUE);

    // DXライブラリの初期化処理
    if (DxLib_Init() == -1)
    {
        return -1; // 初期化に失敗したら終了
    }

    // 描画先を裏画面に設定（チラつき防止）
    SetDrawScreen(DX_SCREEN_BACK);

    int x = 0;
    int y = 300;

	double da = 0.0;    // 小数点を入れるための変数。
    bool flag = false;  // 表面上はfalseだが、実際には0が入っている。0はfalseと同じ意味。
    char c = 'A';      // 文字型の変数。

	int loopCounter = 0; // ループ回数を数える変数

    // メインループ（ウィンドウが閉じられるか、Escキーが押されるまで継続）
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面を消去
        ClearDrawScreen();

        // --------------------------------------------------
        // 文字を表示する処理
        // DrawString( X座標, Y座標, 表示する文字列, 文字の色 );
        // --------------------------------------------------
        DrawString(100, 100, "Hello, DX Library!", GetColor(255, 255, 255));
        DrawString(100, 140, "DXライブラリへようこそ！", GetColor(255, 200, 100));

        DrawString(x, y, "うひょひょ", GetColor(155, 200, 100));
        x = x + 5;
        y = y - 5;

        // --------------------------------------------------
        // 変数の中身を表示する処理
        // DrawString( X座標, Y座標, 表示する文字列, 文字の色 );
        // --------------------------------------------------
        DrawString(100, 200, to_string(x).c_str(), GetColor(255, 255, 255));
        DrawString(100, 240, to_string(y).c_str(), GetColor(255, 255, 255));

        //試しにdaの値を変化させながら表示
		da = da + 0.1;
        DrawString(100, 280, to_string(da).c_str(), GetColor(255, 255, 255));
        //試しにflagの値を変化させながら表示
		if (loopCounter %30 == 0 ) {
			flag = !flag;
		}
        DrawString(100, 320, to_string(flag).c_str(), GetColor(255, 255, 255));
		//試しにcの値を変化させながら表示
        if (loopCounter % 30 == 0) {
            c = c + 1;
        }
        DrawString(100, 360, string(1, c).c_str(), GetColor(255, 255, 255));

        // いろんな計算をしてみる。
        int ans = 3 * 5;
        DrawString(100, 400, to_string(ans).c_str(), GetColor(255, 255, 255));


		// ループカウンターを増やす
        loopCounter = loopCounter + 1;
        DrawString(100, 440, to_string(loopCounter).c_str(), GetColor(255, 255, 255));

        // 
        // 
        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // DXライブラリの終了処理
    DxLib_End();

    return 0;
}