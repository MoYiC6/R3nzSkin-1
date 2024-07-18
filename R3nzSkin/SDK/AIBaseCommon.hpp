// 声明为头文件
#pragma once

// 包含相关头文件
#include <cstdint>
#include "CharacterDataStack.hpp"
#include "GameObject.hpp"

// 定义AIBaseCommon类，继承自GameObject
class AIBaseCommon : public GameObject {
public:
	// 获取角色数据堆栈
	[[nodiscard]] CharacterDataStack* get_character_data_stack() const noexcept { return reinterpret_cast<CharacterDataStack*>(std::uintptr_t(this) + offsets::AIBaseCommon::CharacterDataStack); }

	// 改变模型皮肤
	void change_skin(const char* model, const std::int32_t skin) noexcept;
private:
	// 检查特殊皮肤
	bool checkSpecialSkins(const char* model, const std::int32_t skin) noexcept;
};