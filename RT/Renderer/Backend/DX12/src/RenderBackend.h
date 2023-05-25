#pragma once

#include "ApiTypes.h"
#include "Renderer.h" 

extern RT_MaterialEdge g_rt_material_edges  [RT_MAX_MATERIAL_EDGES];
extern uint16_t        g_rt_material_indices[RT_MAX_MATERIALS];

namespace RenderBackend
{

	void Init(const RT_RendererInitParams* params);
	void Exit();
	void Flush();

	void BeginFrame();
	void BeginScene(const RT_SceneSettings* scene_settings);
	void EndScene();
	void EndFrame();
	void SwapBuffers();
	void OnWindowResize(uint32_t width, uint32_t height);

	RT_RendererIO *GetIO();
	int CheckWindowMinimized();

	void DoDebugMenus(const RT_DoRendererDebugMenuParams *params);

	RT_ResourceHandle UploadTexture(const RT_UploadTextureParams& texture_params);
	RT_ResourceHandle UploadMesh(const RT_UploadMeshParams& mesh_params);
	void ReleaseMesh(const RT_ResourceHandle mesh_handle);
	uint16_t UpdateMaterial(uint16_t material_index, const RT_Material *material);

	RT_ResourceHandle GetDefaultWhiteTexture();
	RT_ResourceHandle GetDefaultBlackTexture();

	// -----------------------------------------------------------------------------------------------
	// Raytracing

	void RaytraceSubmitLights(size_t size, const RT_Light* lights);
	void RaytraceSetVerticalOffset(float new_offset);
	float RaytraceGetVerticalOffset();
	void RaytraceMesh(const RT_RenderMeshParams& render_mesh_params);
	void RaytraceBillboardColored(uint16_t material_index, RT_Vec3 color, RT_Vec2 dim, RT_Vec3 pos, RT_Vec3 prev_pos);
	void RaytraceRod(uint16_t material_index, RT_Vec3 bot_p, RT_Vec3 top_p, float width);
	void RaytraceRender();
    void RaytraceSetSkyColors(RT_Vec3 top, RT_Vec3 bottom);

	// -----------------------------------------------------------------------------------------------
	// Rasterization (UI, debug rendering)

	void RasterSetViewport(float x, float y, float width, float height);
	void RasterTriangles(RT_RasterTrianglesParams* params, uint32_t num_params);
	void RasterLines(RT_RasterLineVertex* vertices, uint32_t num_vertices);
	void RasterLinesWorld(RT_RasterLineVertex* vertices, uint32_t num_vertices);
	void RasterRender();
	void RasterRenderDebugLines();

	// -----------------------------------------------------------------------------------------------
	// Dear ImGui

	void RenderImGuiTexture(RT_ResourceHandle texture_handle, float width, float height);
	void RenderImGui();

	void QueueScreenshot(const char *file_name);

}

