#include <string>
#include "DxLib.h"

using namespace std;

// ここで学ぶこと。
// 　＊【プログラム基礎】変数とは？宣言してまずは使ってみよう。
// 　＊【プログラム基礎】変数同士や数値（定数）との計算をしてみよう。算術演算子もね。
// 　＊【プログラム基礎】余りについて、のお話し
// 　＊【プログラム基礎】繰り返すごとに変数の値が変化することを確認しよう。
//　
// 
// いろいろ弄ってみる
// 　＊今表示されている文字列を変数を使って表示してみよう。
// 　＊さらに変数の値を変化させて表示してみよう。どうなるか？
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

    int x = 600;
    int y = 300;
	int counter = 0; // カウンター変数を初期化

    //double da = 0.0;

    // メインループ（ウィンドウが閉じられるか、Escキーが押されるまで継続）
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        // 画面を消去
        ClearDrawScreen();

        // --------------------------------------------------
        // 文字を表示する処理
        // DrawString( X座標, Y座標, 表示する文字列, 文字の色 );
        // --------------------------------------------------
		x = x - 5; 
        y = y + 1;
        DrawString(x, y, "Hello, DX Library!", GetColor(255, 255, 255));
        DrawString(100, 140, "DXライブラリへようこそ！", GetColor(255, 200, 100));

        DrawString(100, 400, to_string(x % y).c_str(),
            GetColor(255, 255, 255));

		// カウンターを増加させる
		counter = counter + 1;
        DrawString(100, 440, to_string(counter).c_str(), 
            GetColor(255, 255, 255));

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // DXライブラリの終了処理
    DxLib_End();

    return 0;
}