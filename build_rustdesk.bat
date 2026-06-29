@echo off
echo Initializing MSVC Environment...
call "C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"

echo Setting Environment Variables...
set VCPKG_ROOT=C:\vcpkg
set LIBCLANG_PATH=C:\Program Files\LLVM\bin
set PATH=C:\Program Files\LLVM\bin;%PATH%

echo INCLUDE env var value:
echo %INCLUDE%

echo Running RustDesk in Release Mode...
cargo run --release