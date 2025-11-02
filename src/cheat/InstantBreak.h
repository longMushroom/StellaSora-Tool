#pragma once
#include "Feature.h"

namespace cheat::feature
{
	class InstantBreak : public Feature
	{
	public:
		bool f_InstantBreak;

		static InstantBreak& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const override;
		void DrawMain() override;

	private:
		InstantBreak();
	};
}