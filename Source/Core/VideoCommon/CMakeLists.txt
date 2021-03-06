set(SRCS	AsyncRequests.cpp
			BoundingBox.cpp
			BPFunctions.cpp
			BPMemory.cpp
			BPStructs.cpp
			CPMemory.cpp
			CommandProcessor.cpp
			Debugger.cpp
			DriverDetails.cpp
			Fifo.cpp
			FPSCounter.cpp
			FramebufferManagerBase.cpp
			GeometryShaderGen.cpp
			GeometryShaderManager.cpp
			HiresTextures.cpp
			ImageWrite.cpp
			IndexGenerator.cpp
			MainBase.cpp
			OnScreenDisplay.cpp
			OpcodeDecoding.cpp
			PerfQueryBase.cpp
			PixelEngine.cpp
			PixelShaderGen.cpp
			PixelShaderManager.cpp
			PostProcessing.cpp
			RenderBase.cpp
			Statistics.cpp
			TextureCacheBase.cpp
			TextureConversionShader.cpp
			TextureDecoder_Common.cpp
			VertexLoader.cpp
			VertexLoaderBase.cpp
			VertexLoaderManager.cpp
			VertexLoader_Color.cpp
			VertexLoader_Normal.cpp
			VertexLoader_Position.cpp
			VertexLoader_TextCoord.cpp
			VertexManagerBase.cpp
			VertexShaderGen.cpp
			VertexShaderManager.cpp
			VideoBackendBase.cpp
			VideoConfig.cpp
			VideoState.cpp
			XFMemory.cpp
			XFStructs.cpp
			VR.cpp
			MetroidVR.cpp)

set(LIBS core png OVR.a)

if(_M_X86)
	set(SRCS ${SRCS} TextureDecoder_x64.cpp VertexLoaderX64.cpp)
elseif(_M_ARM_64)
	set(SRCS ${SRCS} VertexLoaderARM64.cpp TextureDecoder_Generic.cpp)
else()
	set(SRCS ${SRCS} TextureDecoder_Generic.cpp)
endif()

if(LIBAV_FOUND OR WIN32)
	set(SRCS ${SRCS} AVIDump.cpp)
endif()

add_dolphin_library(videocommon "${SRCS}" "${LIBS}")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	if(LIBAV_FOUND)
		target_link_libraries(videocommon ${LIBS} ${LIBAV_LIBRARIES})
	endif()
endif()
