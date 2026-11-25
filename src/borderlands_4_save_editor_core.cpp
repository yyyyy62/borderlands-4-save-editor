#include "../include/borderlands_4_save_editor_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace borderlands_4_save_editor {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace borderlands_4_save_editor

int main() {
    bool menu_open = true;
    while (borderlands_4_save_editor::g_running.load(std::memory_order_relaxed)) {
        borderlands_4_save_editor::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
