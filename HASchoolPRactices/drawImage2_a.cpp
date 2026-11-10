#include "DxLib.h"

// ここで学ぶこと。
// 　＊【ゲームプログラミング】アニメーションとは？
// 　＊【プログラミング基礎】条件分岐を学ぶ（0:ならAの画像、1:ならBの画像）
// 
// いろいろ弄ってみる
// 　＊if文を増やしてアニメーションを増やしてみよう。
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

    int GHandle1 = LoadGraph("images/hero_down_1.png"); // 画像を読み込む（相対パス）
    int GHandle2 = LoadGraph("images/hero_down_2.png"); // 画像を読み込む（相対パス）

	int drawImageNo = 0; // 画像の切り替え番号
	int switchTime = 0; // 画像の切り替え時間

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
        
        // 経過フレームに応じて表示するアニメ番号を切り替える
        switchTime++;
		if (switchTime > 60)
		{
            drawImageNo = 0;
            switchTime = 0;
		}
		else if (switchTime > 30)
		{
			drawImageNo = 1;
		}

		// 画像の切り替え番号に応じて表示する画像を切り替える
        if (drawImageNo == 0)
        {
            DrawGraph(350, 100, GHandle1, TRUE);
        }
        else 
        {
            DrawGraph(350, 100, GHandle2, TRUE);
        }

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