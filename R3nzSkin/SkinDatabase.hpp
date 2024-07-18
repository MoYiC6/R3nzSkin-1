#pragma once

#include <cstdint>
#include <map>
#include <utility>
#include <vector>

#include "fnv_hash.hpp"
 
class SkinDatabase {
public:
	class skin_info {
	public:
		const char* model_name;
		std::string skin_name;
		std::int32_t skin_id;
	};

	class jungle_mob_skin_info {
	public:
		const char* name;
		std::vector<std::uint64_t> name_hashes;
		std::vector<const char*> skins;
	};

	class specialSkin {
	public:
		std::uint64_t champHash;
		std::int32_t skinIdStart;
		std::int32_t skinIdEnd;
		std::vector<const char*> gears;
	};

	void load() noexcept;

	std::map<std::uint64_t, std::vector<skin_info>> champions_skins;
	std::vector<std::pair<std::uint32_t, const char*>> wards_skins;
	
	std::vector<const char*> minions_skins{
		"小兵", "夏季小兵",
		"攻城小兵", "冰雪节小兵",
		"德莱文小兵", "星际卫士小兵",
		"街机小兵", "冰雪节2小兵",
		"奥德赛小兵", "鼠标小兵", "奥术小兵"
	};

	std::vector<const char*> turret_skins{
		"默认我方防御塔", "默认敌方防御塔",
		"雪地 我方防御塔", "雪地 敌方防御塔",
		"扭曲的丛林 我方防御塔", "扭曲的丛林 敌方防御塔",
		"URF 我方防御塔", "URF 敌方防御塔",
		"街机防御塔",
		"灵魂莲华防御塔",
		"奥术我方防御塔", "奥术敌方防御塔",
		"屠宰码头我方防御塔", "屠宰码头敌方防御塔",
		"嚎哭深渊我方防御塔", "嚎哭深渊敌方防御塔"
	};

	std::vector<jungle_mob_skin_info> jungle_mobs_skins{
		{
			"男爵",
			{ FNV("SRU_Baron") },
			{ "男爵", "冰雪节男爵", "冠军赛男爵", "月球狂欢男爵", "MSI男爵", "奥德赛男爵", "锦标赛生日男爵", "残败的国王男爵" }
		},
		{
			"蓝",
			{ FNV("SRU_Blue") },
			{ "蓝", "深蓝", "泳池派对蓝", "破败的国王蓝" }
		},
		{
			"红",
			{ FNV("SRU_Red") },
			{ "红", "泳池派对红", "破败的国王红" }
		},
		{
			"河蟹",
			{ FNV("Sru_Crab") },
			{ "河蟹", "万圣节河蟹", "万圣节黑暗 河蟹", "破败的国王 河蟹" }
		},
		{
			"石甲虫",
			{ FNV("SRU_Krug"), FNV("SRU_KrugMini"), FNV("SRU_KrugMiniMini") },
			{ "石甲虫", "黑暗石甲虫" }
		},
		{
			"剃刀鸟",
			{ FNV("SRU_Razorbeak"), FNV("SRU_RazorbeakMini") },
			{ "剃刀鸟", "小鸡剃刀鸟" }
		}
	};

	std::vector<specialSkin> specialSkins{
		{ FNV("Katarina"), 29, 36, { "Dagger 1", "Dagger 2", "Dagger 3", "Dagger 4", "Dagger 5", "Dagger 6" }},
		{ FNV("Renekton"), 26, 32, { "Head off", "Head on", "Fins", "Ultimate" } },
		{ FNV("MissFortune"), 16, 16, { "Scarlet fair", "Zero hour", "Royal arms", "Starswarm" } },
		{ FNV("Ezreal"), 5, 5, { "Level 1", "Level 2", "Level 3" } }
	};
};
