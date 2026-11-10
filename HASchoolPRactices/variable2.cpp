#include <string>

#include "DxLib.h"

using namespace std;

// ここで学ぶこと。
// 　＊【プログラム基礎】変数には専用の型があることを確認しよう。
// 　＊【プログラム基礎】変数の中身を表示する方法を確認しよう。
// 　＊【プログラム基礎】変数の中身同士を計算する方法を確認しよう。算術演算子
// 　＊【ゲームプログラミング】ある点の周囲をくるくる回る点の座標を計算して表示してみよう。sin, cos関数を使うよ。
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

    int teihen = 11;
    int takasa = 3;
    double answer = 0;
    answer = teihen * takasa / 2.0;

    double hankei = 2.4;
    double answer2 = 0;
	answer2 = hankei * hankei * 3.14;

    double fuyo = 0.0f;

    //double b = 3.14;



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

        DrawString(100, 400, to_string(answer).c_str(),
            GetColor(255, 255, 255));

        DrawString(100, 300, to_string(answer2).c_str(),
            GetColor(255, 255, 255));


        fuyo = fuyo + 0.05;
        if (fuyo > 6.28) {
            fuyo = 0.0;
        }
        double x1 = cos(fuyo);
        double y1 = sin(fuyo);
        DrawString(400 + (x1 * 30), 400 + (y1 * 30), 
            "●", GetColor(255, 255, 255));



        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // DXライブラリの終了処理
    DxLib_End();

    return 0;
}