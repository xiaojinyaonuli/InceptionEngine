#include "IE_PCH.h"

#include "AnimationSystem.h"
#include "ECS/Entity/EntityComponentPool.hpp"
#include "ECS/Components/AnimationComponent/AnimationComponent.h"
#include "RunTime/Animation/AnimationController.h"


namespace inceptionengine
{
	AnimationSystem::AnimationSystem(ComponentsPool& componentsPool)
		:SystemBase(componentsPool)
	{

	}

	void AnimationSystem::Start()
	{
		auto& view = mComponentsPool.get().GetComponentPool<AnimationComponent>()->GetComponentView();

		for (auto& component : view)
		{
			component.mAnimationController->StartAnimStateMachine();
		}
	}

	void AnimationSystem::Update(float deltaTime)
	{
		auto& view = mComponentsPool.get().GetComponentPool<AnimationComponent>()->GetComponentView();

		for (auto& component : view)
		{
			component.mAnimationController->Update(deltaTime);
		}
	}


}
