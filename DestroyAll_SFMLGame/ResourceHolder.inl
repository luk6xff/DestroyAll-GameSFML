#include "ResourceHolder.h"


template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed while loading " + filename);
	}
	insertResource(id, std::move(resource));
}



template<typename Resource, typename Identifier>
template<typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename, const Parameter & secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename,secondParam))
	{
		throw std::runtime_error("ResourceHolder::load - Failed while loading " + filename);
	}
	insertResource(id, std::move(resource));
}

template<typename Resource, typename Identifier>
Resource & ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourcesMap.find(id);
	assert(found != mResourcesMap.end());
	return *(found->second);
}


template<typename Resource, typename Identifier>
const Resource & ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourcesMap.find(id);
	assert(found != mResourcesMap.end());
	return *(found->second);
}

template<typename Resource, typename Identifier>
void  ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	auto inserted = mResourcesMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second); //check if inserted correctly
}