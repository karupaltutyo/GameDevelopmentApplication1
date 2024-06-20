#pragma once

#include "../GameObject.h"

class bullet :public GameObject
{
private:
	int animation[4];     //�A�j���[�V�����摜
	int animation_count;  //�A�j���[�V��������
	Vector2D direction;	 //�i�s����

public:
	bullet();
	~bullet();

	virtual void Initialize() override;      //����������
	virtual void Update() override;          //�X�V����
	virtual void Draw() const override;      //�`�揈��
	virtual void Finalize() override;        //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_obJect) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();

public:
	void SetDirection(Vector2D dir);
};
