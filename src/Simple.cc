#include "Core/Main.h"
#include "Gfx/Gfx.h"

using namespace Oryol;

class SimpleApp : public App {
public:
    AppState::Code OnInit();
    AppState::Code OnRunning();
    AppState::Code OnCleanup();
};
OryolMain(SimpleApp);

AppState::Code SimpleApp::OnInit() {
    Gfx::Setup(GfxSetup::Window(640, 480, "Window Title"));
    return App::OnInit();
}

AppState::Code SimpleApp::OnRunning() {
    Gfx::BeginPass();
    Gfx::EndPass();
    Gfx::CommitFrame();
    return Gfx::QuitRequested() ? AppState::Cleanup : AppState::Running;
}

AppState::Code SimpleApp::OnCleanup() {
    Gfx::Discard();
    return App::OnCleanup();
}

