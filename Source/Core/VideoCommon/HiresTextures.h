// Copyright 2013 Dolphin Emulator Project
// Licensed under GPLv2
// Refer to the license.txt file included.

#pragma once

#include <string>
#include <unordered_map>
#include "VideoCommon/TextureDecoder.h"
#include "VideoCommon/VideoCommon.h"

class HiresTexture
{
public:
	static void Init(const std::string& gameCode);

	static HiresTexture* Search(
		const u8* texture, size_t texture_size,
		const u8* tlut, size_t tlut_size,
		u32 width, u32 height,
		int format
	);

	static std::string GenBaseName(
		const u8* texture, size_t texture_size,
		const u8* tlut, size_t tlut_size,
		u32 width, u32 height,
		int format
	);

	~HiresTexture();

	struct Level
	{
		u8* data;
		size_t data_size;
		u32 width, height;
	};
	std::vector<Level> m_levels;

	static std::unordered_map<std::string, std::string> textureMap;

private:
	HiresTexture() {}

};
