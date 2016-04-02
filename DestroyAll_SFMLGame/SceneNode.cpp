#include "SceneNode.h"
#include <algorithm>    // std::find_if
#include <cassert>


SceneNode::SceneNode() :mChildren(), mParent(nullptr)
{
}


SceneNode::~SceneNode()
{
}

void SceneNode::attachChild(SceneNodePtr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::SceneNodePtr SceneNode::detachChild(const SceneNode & node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](SceneNodePtr &ptr) {return ptr.get() == &node; });
	assert(found != mChildren.end());
	SceneNodePtr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt)
{
	//virtual -  empty here
}

void SceneNode::updateChildren(sf::Time dt)
{
	for (const SceneNodePtr&child : mChildren)
	{
		child->update(dt);
	}
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	return sf::Transform();
}



void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);
	drawChildren(target, states);

}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	//virtual -  empty here
}

void SceneNode::drawChildren(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (const SceneNodePtr&child : mChildren)
	{
		child->draw(target, states);
	}
}
