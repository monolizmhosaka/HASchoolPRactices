#include "DxLib.h"

// ここで学ぶこと。
// 　＊【ゲームプログラミング】画像の準備
// 　＊【コンピューターの基礎】パスとは？絶対パスと相対パスの違いを確認しよう。
// 　＊【ゲームプログラミング】画像の読み込み・表示・破棄（）
// 
// いろいろ弄ってみる
// 　＊読み込む画像を変えてみよう。
// 　＊２枚目を読み込むプログラムを書いて２つ表示してみよう。
// 　＊以前行った変数を使って、移動するプログラムを作ってみよう。
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

    int x = 0;
    int y = 0;
    int GHandle1 = LoadGraph("images/hero_down_1.png"); // 画像を読み込む（相対パス）
    int GHandle2 = LoadGraph("images/hero_down_2.png"); // 画像を読み込む（相対パス）

    // 描画先を裏画面に設定（チラつき防止）
    SetDrawScreen(DX_SCREEN_BACK);

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

        // 画面左上に描画します(『DrawGraph』を使用)
        x = x + 1;
        y = y + 1;
        DrawGraph(x, 400, GHandle1, TRUE);
        DrawGraph(400, y, GHandle2, TRUE);

        // 裏画面の内容を表画面に反映
        ScreenFlip();
    }

    // 読み込んだ画像のグラフィックハンドルを削除
    DeleteGraph(GHandle1);
    DeleteGraph(GHandle2);

    // DXライブラリの終了処理
    DxLib_End();

    return 0;
}