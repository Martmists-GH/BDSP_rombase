#include "exlaunch.hpp"

#include "externals/FieldPlayerEntity.h"
#include "externals/GameController.h"
#include "externals/UnityEngine/Vector2.h"
#include "externals/UnityEngine/Vector3.h"

HOOK_DEFINE_TRAMPOLINE(FieldPlayerEntity_CheckMapCollision_AfterCharacterHit) {
    static bool Callback(FieldPlayerEntity::Object* __this, UnityEngine::Vector3::Fields moveVelocity, UnityEngine::Vector3::Object* afterMoveVector, UnityEngine::Vector3::Object* hitNormal) {
        bool collision = Orig(__this, moveVelocity, afterMoveVector, hitNormal);

        system_load_typeinfo(0x35f1);
        GameController::getClass()->initIfNeeded();
        bool movingStick = UnityEngine::Vector2::op_Inequality(GameController::getClass()->static_fields->analogStickL, UnityEngine::Vector2::get_zero());
        bool movingDpad = UnityEngine::Vector2::op_Inequality(GameController::getClass()->static_fields->digitalPad, UnityEngine::Vector2::get_zero());

        if (movingStick || movingDpad)
        {
            __this->fields._hit_se_request = true;
        }

        return collision;
    }
};

void exl_npc_collision_audio_main() {
    FieldPlayerEntity_CheckMapCollision_AfterCharacterHit::InstallAtOffset(0x01da4b00);
}
