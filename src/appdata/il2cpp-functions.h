// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.3.0 - 2023.1.99

// ******************************************************************************
//* IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************

using namespace app;

// God Mode & Hit effect
DO_APP_FUNC(0x01212ED0, bool, AdventureActor_OnHitActor, (AdventureActor* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* actor, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x015B0630, List_1_LogicEntity_*, AdventureModuleController_get_playerActors, (AdventureModuleController* __this, MethodInfo* method));
DO_APP_FUNC(0x0166E850, bool, AreaEffectEntity_OnHitActor, (AreaEffectEntity* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* entity, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x01674AD0, bool, AreaEffect_AttackComponent_OnHitActor, (AreaEffect_AttackComponent* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* entity, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x016D6730, bool, AdventureWeapon_OnHitActor, (AdventureWeapon* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* actor, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x016BD1E0, bool, AdventureBulletBase_OnHitActor, (AdventureBulletBase* __this, HitBox* hitBox, int32_t uniqueAttackId, int32_t onceAttackTargetCount, LogicEntity* actor, DeterministicRaycastHit* raycastHit, bool* damaged, GameObject* hurtEffectPrefab, bool isHittedEffectScale, bool effectIgnoreTimeScale, MethodInfo* method));
DO_APP_FUNC(0x016D78F0, int32_t, AdventureWeapon_get_uniqueAttackId, (AdventureWeapon* __this, MethodInfo* method));

// No Cooldown
DO_APP_FUNC(0x014886A0, void, PlayerSkillCd_ReduceSkillSection, (PlayerSkillCd* __this, int32_t skillId, bool beginResume, MethodInfo* method));
DO_APP_FUNC(0x01488E00, void, PlayerSkillCd_ResetUseInterval, (PlayerSkillCd* __this, int32_t skillId, MethodInfo* method));

// Unlimited Energy
DO_APP_FUNC(0x01486440, void, PlayerSkillCd_ClearEnergy, (PlayerSkillCd* __this, MethodInfo* method));
DO_APP_FUNC(0x0148FE50, void, SkillInfo_set_currentEnergy, (SkillInfo* __this, FP value, MethodInfo* method));
DO_APP_FUNC(0x0148FE10, int32_t, SkillInfo_get_totalEnergy, (SkillInfo* __this, MethodInfo* method));
DO_APP_FUNC(0x011CC5B0, void, AdventureSkill_InitSkill, (AdventureSkill* __this, int32_t skillId, GameObject* owner, List_1_UnityEngine_GameObject_* targets, SkillLauncherType__Enum skillLauncherType, bool isInterruptAttack, bool isBreakable, SkillPhaseFeatureFlag__Enum skillCastBehaviourType, SkillCountdownTiming__Enum countdownTiming, Action_1_Boolean_* finishCallback, Action_1_TrueSync_FP_* beginCDForMonsterCallback, bool ingoreCDAndEnergy, MethodInfo* method));
DO_APP_FUNC(0x01337040, iFP, AttributeList_GetAttributeValue, (AttributeList* __this, GameEnum_effectAttributeType__Enum type, MethodInfo* method));

// Mob Vacuum
DO_APP_FUNC(0x01221010, void, AdventureActor_SyncMovementLocation_1, (AdventureActor* __this, bool clearPath, MethodInfo* method));
DO_APP_FUNC(0x015A3510, List_1_LogicEntity_*, AdventureModuleController_get_monsterActors, (AdventureModuleController* __this, MethodInfo* method));
DO_APP_FUNC(0x015AF200, void, AdventureModuleController_Update, (AdventureModuleController* __this, MethodInfo* method));
DO_APP_FUNC(0x00962B00, TSVector2, TrueSyncTransform_get_Position, (TrueSyncTransform* __this, MethodInfo* method));
DO_APP_FUNC(0x0110A750, void, TrueSyncTransform_set_Position, (TrueSyncTransform* __this, TSVector2 value, MethodInfo* method));
DO_APP_FUNC(0x0110A690, void, TrueSyncTransform_set_PositionY, (TrueSyncTransform* __this, FP value, MethodInfo* method));
DO_APP_FUNC(0x0110A0B0, TSVector2, TrueSyncTransform_get_Forward, (TrueSyncTransform* __this, MethodInfo* method));
DO_APP_FUNC(0x05247AF0, TSVector2, TSVector2_op_Addition, (TSVector2 value1, TSVector2 value2, MethodInfo* method));
DO_APP_FUNC(0x05247DE0, TSVector2, TSVector2_op_Multiply_1, (TSVector2 value, FP scaleFactor, MethodInfo* method));
DO_APP_FUNC(0x010FFBC0, FP, CommonHelper_GetTerrainHeight_1, (TSVector2 targetPosition, FP defaultPostionY, MethodInfo* method));

// Instant Break
DO_APP_FUNC(0x015B19C0, iFP, SpecialAttributeList_GetAttributeValue, (SpecialAttributeList* __this, GameEnum_specialAttributeType__Enum type, MethodInfo* method));
DO_APP_FUNC(0x0147C290, bool, MonsterToughnessInfo_DamageToToughness, (MonsterToughnessInfo* __this, AdventureActor* from, int32_t damage, IList_1_System_Int32_* hitDamageTag, MethodInfo* method));

// Always Crit
DO_APP_FUNC(0x010140E0, iFP, ActorAdditionalAttrInfo_get_critRate, (ActorAdditionalAttrInfo* __this, MethodInfo* method));

DO_APP_FUNC(0x0521FE00, FP, FP_op_Implicit_3, (int32_t value, MethodInfo* method));
DO_APP_FUNC(0x05233D10, FP, iFP_get_Value, (iFP* __this, MethodInfo* method));
DO_APP_FUNC(0x052349C0, iFP, iFP_op_Implicit, (FP val, MethodInfo* method));

// Singleton
DO_APP_FUNC(0x00014830, void*, Singleton_GetInstance, (MethodInfo* method));
DO_APP_FUNC_METHODINFO(0x06F95020, Singleton_1_AdventureModuleController__get_Instance__MethodInfo);
DO_APP_FUNC_METHODINFO(0x06F89A30, Singleton_1_AdventurePlayerController__get_Instance__MethodInfo);