#include "Scene.h"
#include"../Objects/Enemy/Enemy.h"
#include"../Objects/Enemy/Enemy2.h"
#include"../Objects/Enemy/Enemy3.h"
#include"../Objects/Player/Player.h"
#include"../Objects/tool/bom.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

//コンストラクタ
Scene::Scene() : objects(), back_grond(NULL)
{

}

//デストラクタ
Scene::~Scene()
{
	//忘れ防止
	Finalize();
}
//初期化処理
void Scene::Initialize()
{
	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 60.0f));
	CreateObject<Enemy>(Vector2D(320.0f, 240.0f));
	CreateObject<Enemy2>(Vector2D(320.0f, 60.0f));
	CreateObject<Enemy3>(Vector2D(320.0f, 240.0f));

	//背景画像を生成する
	back_grond = LoadGraph("Resource/Images/background.png");
}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
	//弾の出現場所
	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Bom>(objects[0]->GetLocation());
	}
}

//描画処理
void Scene::Draw() const
{
	DrawRotaGraphF(320.0, 250.0, 1.2, 0.0, back_grond, TRUE);

	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//終了時処理
void Scene::Finalize()
{
	//動的配列が空なら処理を終了する
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}
	//動的配列の解放
	objects.clear();
}

#ifdef D_PIVEOT_CENTER

//当たり判定チェック処理（矩形の中心で当たり判定を取る）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//２つのオブジェクトの距離を取得
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//当立ったことをオブジェクトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}


#else

//当たり判定チェック処理（左上頂点の座標から当たり判定計算を行う）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//右下頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//矩形Aと矩形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) && (a->GetLocation().y < b_lower_right.y) && (a_lower_right.x > b->GetLocation().x) && (a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#endif // D_PIVEOT_CENTER
