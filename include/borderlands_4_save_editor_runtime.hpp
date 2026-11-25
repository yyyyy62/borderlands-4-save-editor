#pragma once
#include <cstdint>

namespace borderlands_4_save_editor {
inline constexpr const char* kModuleName = "borderlands-4-save-editor";
inline constexpr const char* kBuildSalt = "6efb56b7e13f3ba0";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace borderlands_4_save_editor
