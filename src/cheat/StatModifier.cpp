#include <pch.h>
#include <intrin.h>
#include <appdata/helpers.h>
#include "StatModifier.h"
#include "main.h"

#pragma intrinsic(_ReturnAddress)

namespace cheat::feature
{
	static app::iFP ActorAdditionalAttrInfo_get_critRate_Hook(app::ActorAdditionalAttrInfo* __this, MethodInfo* method);

	StatModifier& StatModifier::GetInstance() {
		static StatModifier instance;
		return instance;
	}

	StatModifier::StatModifier() : Feature(),
		f_CritRate(false),
		f_CritRateValue(100.f)
	{
		HookManager::install(app::ActorAdditionalAttrInfo_get_critRate, ActorAdditionalAttrInfo_get_critRate_Hook);
	}

	const FeatureGUIInfo& StatModifier::GetGUIInfo() const {
		const static FeatureGUIInfo info{ "Status Modifier", "Player", true };
		return info;
	}

	void StatModifier::DrawMain()
	{
		ImGui::Checkbox("Crit Rate", &f_CritRate);
		ImGui::SameLine();
		ImGui::SliderFloat("##CritRate", &f_CritRateValue, 0.f, 100.f, "%.1f");
	}

	static app::iFP ActorAdditionalAttrInfo_get_critRate_Hook(app::ActorAdditionalAttrInfo* __this, MethodInfo* method)
	{
		StatModifier& statModifier = StatModifier::GetInstance();
		if (statModifier.f_CritRate)
		{
			static int64_t desiredRet = global::process::qwGameAssembly + 0x11FFC4B;
			auto retAddress = (int64_t)_ReturnAddress();

			auto adventurePlayerController = GET_SINGLETON(AdventurePlayerController);
			if (adventurePlayerController == nullptr)
				return CALL_ORIGIN(ActorAdditionalAttrInfo_get_critRate_Hook, __this, method);

			auto player = CastTo<app::AdventureActor>(adventurePlayerController->fields._activedPlayerActor, *app::AdventureActor__TypeInfo);
			if (player == nullptr)
				return CALL_ORIGIN(ActorAdditionalAttrInfo_get_critRate_Hook, __this, method);
			
			auto fromActor = (*app::AdventureActor__TypeInfo)->static_fields->fromActorTemp;
			if (retAddress == desiredRet && fromActor == player)
			{
				auto sanitizeCrit = statModifier.f_CritRateValue / 100.f;
				return app::iFP_op_Implicit((app::FP)(sanitizeCrit * (1LL << 32)), nullptr);
			}
		}

		return CALL_ORIGIN(ActorAdditionalAttrInfo_get_critRate_Hook, __this, method);
	}
}