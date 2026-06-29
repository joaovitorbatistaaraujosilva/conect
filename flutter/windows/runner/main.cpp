#include <flutter/dart_project.h>
#include <flutter/flutter_view_controller.h>
#include <windows.h>

#include "flutter_window.h"
#include "utils.h"
#include <iostream>

int APIENTRY wWinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prev,
                      _In_ wchar_t *command_line, _In_ int show_command) {
  // Attach to console when present (e.g., 'flutter run') or create a
  // new console when running with a debugger.
  if (!::AttachConsole(ATTACH_PARENT_PROCESS) && ::IsDebuggerPresent()) {
    CreateAndAttachConsole();
  }

  // Initialize COM, so that it is available for use in the library and/or
  // plugins.
  ::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

  HINSTANCE hInstance = LoadLibraryA("librustdesk.dll");
  if (!hInstance)
  {
    std::cout << "Failed to load librustdesk.dll" << std::endl;
    return EXIT_FAILURE;
  }
  typedef char** (*FUNC_RUSTDESK_CORE_MAIN_ARGS)(int*);
  FUNC_RUSTDESK_CORE_MAIN_ARGS rustdesk_core_main_args =
      (FUNC_RUSTDESK_CORE_MAIN_ARGS)GetProcAddress(hInstance, "rustdesk_core_main_args");
  if (!rustdesk_core_main_args)
  {
    std::cout << "Failed to get rustdesk_core_main_args" << std::endl;
    return EXIT_FAILURE;
  }
  int args_len = 0;
  char** c_args = rustdesk_core_main_args(&args_len);
  if (!c_args)
  {
    std::cout << "Rustdesk core returns false, exiting without launching Flutter app" << std::endl;
    return EXIT_SUCCESS;
  }
  std::vector<std::string> rust_args(c_args, c_args + args_len);

  flutter::DartProject project(L"data");

  std::vector<std::string> command_line_arguments =
      GetCommandLineArguments();

  command_line_arguments.insert(command_line_arguments.end(), rust_args.begin(), rust_args.end());
  project.set_dart_entrypoint_arguments(std::move(command_line_arguments));

  FlutterWindow window(project);
  Win32Window::Point origin(10, 10);
  Win32Window::Size size(1280, 720);
  if (!window.Create(L"conect", origin, size)) {
    return EXIT_FAILURE;
  }
  window.SetQuitOnClose(true);

  ::MSG msg;
  while (::GetMessage(&msg, nullptr, 0, 0)) {
    ::TranslateMessage(&msg);
    ::DispatchMessage(&msg);
  }

  ::CoUninitialize();
  return EXIT_SUCCESS;
}
