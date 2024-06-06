#pragma once

#include "../GameObject.h"

class Enemy3 :public GameObject
{
private:
	int animation[2];     //�A�j���[�V�����摜
	int animation_count;  //�A�j���[�V��������
	int filp_flag;        //���]�t���O
	Vector2D direction;

public:
	Enemy3();
	~Enemy3();

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
};

