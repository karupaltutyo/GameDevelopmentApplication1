#include "bullet.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//�R���X�g���N�^
bullet::bullet() :animation_count(0)
{
	animation[0] = NULL;
	/*animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;*/
}

//�f�X�g���N�^
bullet::~bullet()
{

}
//����������
void bullet::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/Images/1 (5).png");
	/*animation[1] = LoadGraph("Resource/images/eff1.png");
	animation[2] = LoadGraph("Resource/images/eff2.png");
	animation[3] = LoadGraph("Resource/images/eff3.png");*/

	//�G���[�`�F�b�N
	if (animation[0] == -1/*||animation[1]==-1||animation[2]==-1||animation[3]==-1*/)
	{
		throw("���e�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 360.0;

	//�����蔻��̑傫����ݒ�
	box_size = 64.0;

	//�����������̐ݒ�
	image = animation[0];
}

//�X�V����
void bullet::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimeControl();
}

//�`�揈��
void bullet::Draw() const
{
	//���e�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 1.0, radian, image, TRUE);

	//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D box_collision_upper_left = location - (box_size / 2.0f);
	Vector2D box_collision_lower_right = location + (box_size / 2.0f);

	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);

#endif
}

//�I��������
void bullet::Finalize()
{
	//�g�p�����摜���������
	DeleteGraph(animation[0]);
	/*DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);*/
}

//�����蔻��ʒm����
void bullet::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}

//�ړ�����
void bullet::Movement()
{
	//�ړ��̑���
	Vector2D velocity = 0.0f;

	//��ɓ���
	velocity.y += -1.0f;

	location += velocity;
}

//�A�j���[�V��������
void bullet::AnimeControl()
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
			image = animation[0];
		}
		else
		{
			image = animation[0];
		}
	}
}

void bullet::SetDirection(Vector2D dir)
{
	// �����Ƒ���̕����x�N�g�����Z�o����

	// �Z�o���������x�N�g���𐳋K������

	// ���K�������l���ړ��ʂƂ���

}
