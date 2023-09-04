#pragma once

#include "externals/il2cpp-api.h"
#include "externals/Dpr/SequenceEditor/SequenceCameraSystem.h"
#include "externals/UnityEngine/Vector3.h"
#include "externals/UnityEngine/Coroutine.h"

namespace Dpr::Battle::View::Systems {
    struct BattleCameraSystem : ILClass<BattleCameraSystem> {
        struct Fields : Dpr::SequenceEditor::SequenceCameraSystem::Fields {
            int32_t _WaitCameraState_k__BackingField;
            int32_t _lotteryCnt;
            UnityEngine::Coroutine::Object* _waitCameraLoadCoroutine;
            bool _isSplitScreen;
            bool _isSplitScreenDelResource;
            bool _isEnableWaitamera;
            bool _isFirstWaitCamera;
            bool _isStatedWaitCamera;
            int32_t _waitCameraCnt;
            int32_t _playWaitCameraIndex;
            void* _useWaitCameraDatas; //XLSXContent_BattleWaitCameraData_SheetWaitCameraData_array*
            void* _lotteryPlayWaitCameraDatas; //System_Collections_Generic_HashSet_BattleWaitCameraData_SheetWaitCameraData__o*
            UnityEngine::Vector3::Object _position;
            UnityEngine::Vector3::Object _target;
            UnityEngine::Vector3::Object _animPosition;
            UnityEngine::Vector3::Object _animTarget;
            float _animNear;
            float _animFar;
            float _animFov;
            float _animTwist;
            int32_t _waitCameraTargetPoke;
            int32_t _waitCameraTargetTrainer;
            UnityEngine::Coroutine::Object* _waitCameraDispose;
        };
    };
}