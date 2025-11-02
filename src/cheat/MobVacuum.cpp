#include <pch.h>
#include <appdata/helpers.h>
#include "MobVacuum.h"
#include "main.h"

namespace cheat::feature
{
	static void OnUpdate();

	MobVacuum& MobVacuum::GetInstance()
	{
		static MobVacuum instance;
		return instance;
	}

	MobVacuum::MobVacuum() : Feature(),
		f_MobVacuum(false)
	{
		global::AdventureModuleController_Update.push_back(OnUpdate);
	}

	const FeatureGUIInfo& MobVacuum::GetGUIInfo() const
	{
		static FeatureGUIInfo info = { "", "World", false };
		return info;
	}

	void MobVacuum::DrawMain()
	{
		ImGui::Checkbox("Mob Vacuum", &f_MobVacuum);
	}

	app::TSVector2 GetForwardPos(app::LogicEntity* actor, int32_t scalar)
	{
		auto playerPos = app::TrueSyncTransform_get_Position(actor->fields._tsTransform_k__BackingField, nullptr);
		auto playerForward = app::TrueSyncTransform_get_Forward(actor->fields._tsTransform_k__BackingField, nullptr);

		auto convertedScale = app::FP_op_Implicit(scalar, nullptr);
		auto forwardScale = app::TSVector2_op_Multiply(playerForward, convertedScale, nullptr);
		auto forwardPos = app::TSVector2_op_Addition(playerPos, forwardScale, nullptr);
		return forwardPos;
	}

	static void OnUpdate()
	{
		MobVacuum& instance = MobVacuum::GetInstance();
		if (!instance.f_MobVacuum) return;

		auto adventureModuleController = GET_SINGLETON(AdventureModuleController);
		if (adventureModuleController == nullptr) return;

		auto adventurePlayerController = GET_SINGLETON(AdventurePlayerController);
		if (adventurePlayerController == nullptr) return;

		auto monsterActors = TO_UNI_LIST(app::AdventureModuleController_get_monsterActors(adventureModuleController, nullptr), app::LogicEntity*);
		if (monsterActors == nullptr) return;

		auto playerActor = adventurePlayerController->fields._activedPlayerActor;
		if (playerActor == nullptr) return;

		auto player = reinterpret_cast<app::LogicEntity*>(playerActor);
		if (player == nullptr) return;

		auto targetPos = GetForwardPos(player, 3);

		for (auto monster : *monsterActors)
		{
			auto actor = reinterpret_cast<app::AdventureActor*>(monster);
			app::AdventureActor_Teleport(actor, targetPos, nullptr);
		}
	}
}