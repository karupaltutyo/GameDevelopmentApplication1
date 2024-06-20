#include "Enemy4.h"
#include "../GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
Enemy4::Enemy4() :animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;

}

//�f�X�g���N�^
Enemy4::~Enemy4()
{

}
//����������
void Enemy4::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/1.png");
	animation[1] = LoadGraph("Resource/Images/2.png");


	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("�n�l�e�L�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0;

	//��`�̑傫���̐ݒ�
	box_size = 64.0;

	//�����������̐ݒ�
	image = animation[0];
}

//�X�V����
void Enemy4::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void Enemy4::Draw() const
{
	//�摜���]�t���O
	int flip_flag = FALSE;
	//�n�l�e�L�摜�̕`��
	DrawRotaGraphF(location.x, 200.0, 1.0, radian, image, TRUE, filp_flag);


}

//�I��������
void Enemy4::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Enemy4::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
	direction = 0.0f;
}

//�ړ�����
void Enemy4::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//�������ɐi�ݑ�����
	location.x += -1.5f;

	//���̒[�ɍs���ƁA�E�̒[�ֈړ�����
	if (location.x <= 0.0f)
	{
		location.x = 640.0f;
	}

	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Enemy4::AnimeControl()
{
	//�t���[���J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐؂�ւ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}