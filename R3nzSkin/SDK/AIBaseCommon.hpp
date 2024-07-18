// ����Ϊͷ�ļ�
#pragma once

// �������ͷ�ļ�
#include <cstdint>
#include "CharacterDataStack.hpp"
#include "GameObject.hpp"

// ����AIBaseCommon�࣬�̳���GameObject
class AIBaseCommon : public GameObject {
public:
	// ��ȡ��ɫ���ݶ�ջ
	[[nodiscard]] CharacterDataStack* get_character_data_stack() const noexcept { return reinterpret_cast<CharacterDataStack*>(std::uintptr_t(this) + offsets::AIBaseCommon::CharacterDataStack); }

	// �ı�ģ��Ƥ��
	void change_skin(const char* model, const std::int32_t skin) noexcept;
private:
	// �������Ƥ��
	bool checkSpecialSkins(const char* model, const std::int32_t skin) noexcept;
};